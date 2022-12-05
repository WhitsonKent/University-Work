#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[]){
  int status;
  int size = 0;//number of tokens
  int numCommands;//how many unix commands to execute
  char command[50];
  char *commands;
  char str[50];
  char hold[50];
  gets(str);
  strcpy(hold,str);

  char* toks=strtok(str," ");
  //First we find number of tokens
  while (toks) {
    toks= strtok(NULL, " ");
    size++;
  }
//put tokens in args array
char args[size][50];
char* toks2=strtok(hold," ");
for (int i=0;i<size;i++) {
  strcpy(args[i],toks2);
  toks2= strtok(NULL, " ");
}
//determine how many commabds to execute
if(size==1){numCommands=1;}
else{
  if((size%2)==0){numCommands=size/2;}
  else numCommands=size/2+1;
}
//put args into command
printf("%d\n",numCommands);
for(int i=0;i<numCommands;i++){
  strcpy(command,args[i*2]);
  if(args[i*2+1]){
    strcat(command," ");
    strcat(command,args[i*2+1]);
  }
  //parse command again to execute
  parse(command,commands);
  execute(commands);
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
    printf("PID:%d\n",getpid());
    execvp(*args, args);
    exit(1);
    }
    else {
      while (wait(&status) != pid);
    }
}
