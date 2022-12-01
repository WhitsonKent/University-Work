#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
  int status;
  char str[50];
  for(int i=0;i<argc;i++)
  {
    if(fork() == 0)
    {
      if(i <argc-2)
      {
        strcpy(str,argv[i+1]);
        strcat(str," ");
        strcat(str,argv[i+2]);
        status=system(str);
		exit(0);
      }
      else{
        if((argc%2)==0)
        {
          status=system(argv[i+1]);
        }
      }
      exit(0);
    }
  }
  printf("\n");
}
