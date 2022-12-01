#include <stdio.h>

int main(void)
{
	char num []="CALLATT";
	printf("The translation of %s : ",num);
	for(int i=0;i<sizeof(num);i++){
		if ('A'<=num[i]&&num[i]<='C'){
			printf("2");
		}
		if ('D'<=num[i]&&num[i]<='F'){
			printf("3");
		}
		if ('G'<=num[i]&&num[i]<='I'){
			printf("4");
		}
		if ('J'<=num[i]&&num[i]<='L'){
			printf("5");
		}
		if ('M'<=num[i]&&num[i]<='O'){
			printf("6");
		}
		if ('P'<=num[i]&&num[i]<='S'){
			printf("7");
		}
		if ('T'<=num[i]&&num[i]<='V'){
			printf("8");
		}
		if ('W'<=num[i]&&num[i]<='Y'){
			printf("9");
		}
	}
}