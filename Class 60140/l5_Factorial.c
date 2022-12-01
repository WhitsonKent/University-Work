#include <stdio.h>

int main(void)
{
	int n,factorial,original;
	for(;;){
		printf("Enter a positive integer(-ve to exit): ");
		scanf("%d",&n);
		original = n;
		factorial=n;
		if(n<0){ 
		break;
		}
		if (n==0){
			factorial=1;
		}
		else{
			for(;n>1;n--){
				factorial = factorial*(n-1);
				}
				}
		printf("Factorial of %d: %d\n",original,factorial);
	}
	printf("Thank you for using my software\n");
	return 0;
}