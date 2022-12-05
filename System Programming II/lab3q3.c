#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    FILE* fd1 = fopen(argv[1], "r");
    char line[280];
    int numLines=0;
    while (fgets(line,sizeof(line),fd1)){
      numLines++;
    }
    fclose(fd1);
    char lines[numLines][280];
    FILE* fd2 = fopen(argv[1], "r");
    int i = 0;
    while (i<numLines) {
      fgets(line,sizeof(line),fd2);
      strcpy(lines[i],line);
      printf("%s",lines[i]);
      i++;
    }
    strcat(lines[i-1],"\n");
    fclose(fd2);
    printf("\n\n-------------------------\n\n");
    i=i-1;
    FILE* fd3 = fopen(argv[2], "w");
    while(i>=0){
      fprintf(fd3, "%s",lines[i]);
      printf("%s",lines[i]);
      i--;
    }
    fclose(fd3);
  }
