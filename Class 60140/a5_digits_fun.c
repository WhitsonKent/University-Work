#include <stdio.h>

int num_digits(int n){
	int digits=0;
	for(int i=1;n>0; i++){
	n/=10;
	digits = i;
	}
	return digits;
}
int main(void){
	int num;
	printf("Enter a number\n");
	scanf("%d",&num);
	num_digits(num);
	printf("%d has %d digit(s)",num,num_digits(num));
}