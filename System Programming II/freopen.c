#include<stdio.h>

int main(int argc, char*argv[]) {

		
	freopen("./mytemp.txt","w+", stdout);

	printf("hello there\n");

	fdopen( 1, "./mytemp.txt");

	printf("hello there again\n");
}
