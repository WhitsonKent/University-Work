#include <stdio.h>

int main(void){
	int num,rev=0;
	printf("Enter a number: ");
	scanf("%d",&num);
	if (0<=num && num<10){
		printf("No need to reverse the number.\n");
	}
	else if(num<0){
		printf("Invalid input!\n");
	}
	else{
		do{
			rev = rev*10 +num%10;
			num=num/10;
		}while(num!=0);
	printf("The reversal is: %d\n",rev);
	}
	printf("Thank you for using the software.\n");
}