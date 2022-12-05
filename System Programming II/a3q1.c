#include "smallsh.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *prompt = "Command> ";

int userin(char *p);
void procline(void);

int main()
{
	while (userin(prompt) != EOF)
		procline();
}

static char inpbuf[MAXBUF], tokbuf[2 * MAXBUF],
*ptr = inpbuf, *tok = tokbuf;

int inarg(char c);

int userin(char *p)
{
	int c, count;
	ptr = inpbuf;
	tok = tokbuf;
	
	printf("%s", p);
	count = 0;
	while (1)
	{
		if ((c = getchar()) == EOF)
			return(EOF);
		if (count < MAXBUF)
			inpbuf[count++] = c;
		if (c == '\n' && count < MAXBUF)
		{
			inpbuf[count] = '\0';
			return count;
		}
		
		if (c == '\n')
		{
			printf("smallsh: input line too long\n");
			count = 0;
			printf("%s ", p);
		}
	}
}

int gettok(char **outptr)
{
	int type;
	
	*outptr = tok;
	
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	
	*tok++ = *ptr;
	
	switch (*ptr++) {
	case '\n':
		type = EOL;
		break;
	case '&':
		type = AMPERSAND;
		break;
	case ';':
		type = SEMICOLON;
		break;
	default:
		type = ARG;
		
		while (inarg(*ptr))
			*tok++ = *ptr++;
	}
	*tok++ = '\0';
	return type;
}

//****************************************************************************************
static char special[] = { ' ', '\t', '&', ';', '\n', '\0' };
int inarg(char c)
{
	char *wrk;
	for (wrk = special; *wrk; wrk++)
	{
		if (c == *wrk)
			return (0);
	}
	return (1);
}

int gettok(char **outptr);
int runcommand(char **cline, int where);


void procline(void) 
{
	char *arg[MAXARG + 1]; 
	int toktype; 
	int narg; 
	int type; 

	narg = 0;

	for (;;) 
	{
	   switch (toktype = gettok(&arg[narg])) {
		case ARG:
			if (narg < MAXARG)
				narg++;
			break;
		case EOL:
		case SEMICOLON:
		case AMPERSAND:
			if (toktype == AMPERSAND)
				type = BACKGROUND;
			else
				type = FOREGROUND;
			if (narg != 0)
			{
				arg[narg] = NULL;
				runcommand(arg, type);
			}
			if (toktype == EOL)
				return;
			narg = 0;
			break;
		}
	}
}

int runcommand(char **cline, int where)
{
	pid_t pid;
	int status;
    if (strcmp(cline[0],"exit")==0)exit(1);//exits the program if user inputs exit
	switch (pid = fork()) {
		case 1:
			perror("smallsh");
			return (-1);
		case 0:
			execvp(cline[0], cline);
			perror(*cline);
			exit(1);
	}
	//code for parents
	if (where == BACKGROUND)
	{
		printf("[process id %d]\n", pid);
		return (0);
	}
	
	if (waitpid(pid, &status, 0) == -1)
		return (-1);
	else
		return (status);
}
