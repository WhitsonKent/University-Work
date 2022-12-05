#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
  int pid = 1;
  if(fork()==0){
    sleep(1);
    printf("lmao\n");
    sleep(1);
  }else printf("ayy\n");
  }
