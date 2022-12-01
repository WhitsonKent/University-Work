#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void){
	int n,k,r;
	char ch;
	time_t tm;
	srand((unsigned) time(&tm));
	printf("Enter a number between 2 and 35: ");
	scanf("%d",&n);
	for(n;n>0;n--){
		k=n;
		r= (rand()%8)+2;
		printf("%d: ",r);
		if (r<5 && k<=9){
			for(int i=r-1;i>0;i--){
				printf("%d",k);
			}
		}
		if (r<5 && k>9){
			ch = k + 87; 
			for(int i=r-1;i>0;i--){
				printf("%c",ch);
			}
		}
		if (r>=5 && k<=9){
			for(int i=r;i>0;i--){
				printf(" ");
			}
			for(int i=10-r;i>0;i--){
				printf("%d",k);
			}
		}
		if (r>=5 && k>9){
			ch = k + 87;
			for(int i=r;i>0;i--){
				printf(" ");
			}
			for(int i=10-r;i>0;i--){
				printf("%c",ch);
			}
		}
		printf("\n");
	}
}