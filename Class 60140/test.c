#include <stdio.h>

int main(void){
	int i=1;
	while(i<=128){
		printf("%d",i);
		i*=2;
	}
	printf("\n");
	for(int i =1;i<=128;i*=2){
		printf("%d",i);
	}
	printf("\n");
	printf("\n");
	i = 9384;
	do{
		printf("%d",i);
		i/=2;
	}while(i>0);
	printf("\n");
	for(int i =9384;i>0;i/=2){
		printf("%d",i);
	}
}