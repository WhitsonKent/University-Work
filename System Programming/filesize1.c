//filesize1.c
#include <stdio.h>

int main(int argc, char *argv[]){  
	FILE *fd;
	
	//unsigned char ch;  //what will happen if you uncomment this line and comment the 		//next line
        char ch;

	int fileSize=-1;

	fd = fopen(argv[1], "r");  

	do{
		ch=getc(fd);  
		fileSize++;
		printf("fileSize=%d\n", fileSize);
	} while( ch != EOF);
	
	//printf("ch=%d EOF=%#x\n", ch, EOF);
	//printf("size of char =%ld size of EOF=%ld\n", sizeof(char), sizeof(EOF));
	
	printf("Size of %s is %d\n", argv[1], fileSize);
}

