#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void handle_sigint(int sig){}

int main(int argc,char *argv[]){
  int fd;
  int pid1, pid2;
  char str[]="hello";
  signal(SIGUSR1, handle_sigint);
  printf("%s",str);
  if((pid1=fork()) == 0){
    kill(getppid(), SIGUSR1);//Create process then pause
    pause();
    printf("Executing Process 1\n" );
    kill(getppid(), SIGUSR1);//Create process then pause
    exit(0);
  }

  if((pid2=fork()) == 0){
    kill(getppid(), SIGUSR1);//Create process then pause
    pause();
    printf("Executing Process 2\n" );
    kill(getppid(), SIGUSR1);//Create process then pause
    exit(0);
  }

  kill(pid2, SIGUSR1);//Decides which process to execute
  pause();
  printf("Process 2 ended\n");
  kill(pid1, SIGUSR1);//Create process then pause
  pause();
  printf("Process 1 ended\n");
  printf("All Processes Executed\n");
}
