#include <stdio.h>

int main(int argc, char *argv[]){
	int c;
	FILE *fp;
	fp = fopen(argv[1], "r");
	if (fp) {
		while ((c = getc(fp)) != EOF)
			putchar(c);
		fclose(fp);
	}
	if (fp== NULL){
		printf("WRONG");
	}
	
}