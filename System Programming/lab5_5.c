#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
 char buf[1024];
 char *args[64];
 printf("Command: "); /* * Prompt for and read a command. */
 if (gets(buf) == NULL) {
 printf("\n"); exit(0);
 }
 parse(buf, args); /*Split the string into arguments and */
 execute(args); /*execute the command. */
}
/* parse – This function splits the typed command in buf into individual tokens.*/
void parse(char *buf, char **args) {
 while (*buf != '\0') {
 /* Strip whitespace, so that the previous argument is terminated with \0 */
 while ((*buf == ' ') || (*buf == '\t'))
 *buf++ = '\0';
 *args++ = buf; /* Save the argument into args*/
 /** Skip over the argument.*/
 while ((*buf != '\0') && (*buf != ' ') && (*buf != '\t'))
 buf++;
 }
 *args = NULL;
}

void execute(char **args){
  int i =0;
    execvp(*args,args);
}
