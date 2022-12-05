#include <stdio.h>
#include <string.h>
//standard io

void reverseString(char* str);

int main(int argc, char* argv[])
{
	//count number of lines in file
    FILE* fd1 = fopen(argv[1], "r");
    char line[280];
    int numLines=0;
    while (fgets(line,sizeof(line),fd1)){
      numLines++;
    }
    fclose(fd1);
	//copy lines to array
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
	//reverse
    FILE* fd3 = fopen(argv[2], "w");
    while(i>=0){
		reverseString(lines[i]);
		fprintf(fd3, "%s",lines[i]);
		printf("%s",lines[i]);
		i--;
    }
    fclose(fd3);
  }
void reverseString(char* str) {
	int size = strlen(str);
	char strRev[size];
	if (size > 1) {
		for (int i = 0; i < size; i++) {
			strRev[i] = str[size-i-1];
		}
		strcpy(str, strRev);
	}
}
