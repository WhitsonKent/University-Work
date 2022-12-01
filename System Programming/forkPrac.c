#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int ppid;
  int pid;
  if (fork()==0){
    printf("Im Baby\n");
    pid=getpid();
    ppid=getppid();
    printf("This is babby: %d\n",pid);
    printf("This is daddy: %d\n",ppid);
  }
  else{
    printf("Im Daddy\n");
    pid=getpid();
    printf("This is papa: %d\n",pid);
  }
}
