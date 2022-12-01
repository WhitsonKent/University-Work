#include <stdio.h>
#include <math.h>

float polynomial(float n){
	float poly = 3*pow(n,5.0)+2*pow(n,4.0)-5*pow(n,3.0)-pow(n,2.0)+7*n-6;
	return poly;
}
int main(void){
	float num;
	printf("Enter a number\n");
	scanf("%f",&num);
	printf("%.0f",polynomial(num));
}