#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
  char FileName[]="data.txt"
  FILE *fp;
	fp = fopen(FileName, "w");
  int num;
  printf("Enter an integer between 1 and 15\n");
  scanf("%d\n",&num );
  if (num<1 || num>15){
    printf("ERROR INVALID NUMBER");
  }
}
