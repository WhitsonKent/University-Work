#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include<stdio.h>
#include<signal.h>

// Handler for SIGINT, caused by
// Ctrl-C at keyboard
void handle_sigint(int sig)
{
    printf("Ctrl+C pressed\n");
    exit(0);
}
void handle_sigtstp(int sig)
{
    printf("Ctrl+Z pressed\n");
}


int main()
{
  char *args[]={"./dn",NULL};
    signal(SIGINT, handle_sigint);
    signal(SIGTSTP, handle_sigtstp);
    if (fork()==0){
      execvp(args[0],args);
    }else{
      for(int i=1; i<=15; i++){
        printf("I am in parent process.\n");
        sleep(1);}
    }
    while (1) ;
    return 0;
}
