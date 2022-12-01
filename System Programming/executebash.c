#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
  int status;
  if(fork()==0)
  {
    status=system("./mybash");
    exit(0);
  }
  else
  {
    wait(0);
    printf("STUDY!STUDY!STUDY!\n");
  }
}
