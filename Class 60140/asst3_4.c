#include <stdio.h>
#include <math.h>

int main(void){
	//Question 4a
	int n = 1;
	int a = 1;
	if(a>n && n>0){
		printf("Good!\n");
	}
	else printf("Hello!\n");
	//Question 4b
	for(int k=1;;){
		if(k>10){
			break;
		}
		printf("%d ",k);
		k=k+1;
	}
	printf("\n");	
	//Question 4c
	for(int k=1;;){
		printf("%d ",k);
		k=k+1;
		if(k>10){
			break;
		}
	}
	printf("\n");
	//Question 4d
	for(float x=10.0;;){
		if(x<1.001){
			break;
		}
		printf("%.3f ",x);
		x=sqrt(x);
	}
}