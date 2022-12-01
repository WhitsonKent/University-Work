#include <stdio.h>
#include <stdlib.h>
#define FILE_NAME "example.txt"

int main (void)
{
	FILE *fp;
	fp = fopen(FILE_NAME,"r");
	fclose(fp);
}