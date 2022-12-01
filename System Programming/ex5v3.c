#include <stdio.h>

int main(int argc, char *argv[]){  
	FILE *f;
	char c;

	f=fopen(argv[1], "w");
	while((c=getchar()) != EOF){ 
		 fputc(c, f);
		 fflush(f);
	}
}

