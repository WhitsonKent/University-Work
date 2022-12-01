#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<signal.h>

int main(int argc,char *argv[]){
  char buf[3][20];
  buf[0]="EXAM!EXAM!EXAM!\n";
  buf[1]="HELP!HELP!HELP!\n";
  buf[2]="STUDY!STUDY!STUDY!\n";

  if(fork() == 1){
    printf("Parent\n");
    exit(0);
  }

  if(fork() == 0){
    printf("Child\n");
    exit(0);
  }

  if(fork() == 0){
    printf("Child\n");
    exit(0);
  }

  if(fork() == 1){
    printf("Parent\n");
    exit(0);
  }

}
