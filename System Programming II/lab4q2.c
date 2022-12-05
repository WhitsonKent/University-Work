#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    FILE* fd = fopen("l4q2.txt", "w");
    char msg1[]="part 1\n";
    char msg2[]="part 2\n";
    fprintf(fd, "%s",msg1);
    int pid = fork();
    if(pid==0){
      printf("I Am Child\n");
      fclose(fd);
      exit(0);
    }
    else{
      printf("Waiting for Child\n");
      sleep(2);
      printf("Child Finished\n");
      fprintf(fd, "%s", msg2);
    }
    fclose(fd);
  }
