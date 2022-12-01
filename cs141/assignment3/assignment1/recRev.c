#include <stdio.h>
#include <math.h>

void reverse(unsigned int x);

int main(){
	reverse(344678);
}

void reverse(unsigned int x){
	if (x<10){
		printf("%u",x);
	}
	else{
	printf("%u",x%10);
	reverse(x/10);
	}
}