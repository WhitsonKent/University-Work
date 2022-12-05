/* The program asks for UNIX/Linux commands to be typed and inputted to a string*/
/* The string is then "parsed" by locating blanks, tabs. */
/* Each command and corresponding arguments are then put in an args array */
/* execvp is called to execute the command in child process */
/* This program does not handle executing the command as background process*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
 char buf[1024];
 char *args[64];
 for (;;) {
 printf("Command: "); /* * Prompt for and read a command. */
 if (gets(buf) == NULL) {
 printf("\n"); exit(0);
 }
 parse(buf, args); /*Split the string into arguments and */
 execute(args); /*execute the command. */
 }
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
/** execute--spawn a child process and execute the typed command.*/
void execute(char **args) {
  int pid;
  int status;
  pid = fork();
  if (pid == 0) {
    execvp(*args, args);
    exit(1);
    }
    else {
      while (wait(&status) != pid);
    }
}
