#include <stdio.h>

int main(int argc, char *argv[]) {
	
	FILE *f=fopen("example.txt","w+");
	fprintf(f, "hello world.\n");
	fprintf(f, "hello windsor.\n");
	putc(-1, f);
	fprintf(f, "hello everyone.\n");

	fclose(f);

}
