#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int w,h,r,num;
	float freq=0,percent;
	char lc,uc;
	time_t tm;
	lc=97;
	uc=65;
	srand((unsigned) time(&tm));
	do{
		printf("Range: 9 < w < 21, 2 < h < 62\n");
		printf("Enter width and height: ");
		scanf("%d %d",&w,&h);
	}while(w<10 || w>20 || h<3 || h>61);
	for(int k=1;k<h+1;k++){
		num=k;
		for(;;){
		r= (rand()%(h));
		if (2<=r && r<=w-1){
			break;
			}
		}
		if(r==w/2){
			freq+=1;
		}
		if (r<10){
			printf("0%d: ",r);
		}
		else{
			printf("%d: ",r);
		}
		if(r>=w/2){
			for(int i=r;i>0;i--){
				printf(" ");
			}
			if(10<=k && k<=35){
				for(int i=w-r;i>0;i--){
					printf("%c",lc);
					}
					lc=lc+1;
			}
			if(k>35){
				for(int i=w-r;i>0;i--){
					printf("%c",uc);
					}
					uc=uc+1;
			}
			if(k<10){
				for(int i=w-r;i>0;i--){
					printf("%d",num);
					}
			}
		}
		else{
			if(10<=k && k<=35){
				for(int i=r-1;i>0;i--){
					printf("%c",lc);
					}
					lc=lc+1;
			}
			if(k>35){
				for(int i=r-1;i>0;i--){
					printf("%c",uc);
					}
					uc=uc+1;
			}
			if(k<10){
				for(int i=r-1;i>0;i--){
					printf("%d",num);
				}
			}
		}
		printf("\n");
	}
	percent=(freq/h)*100;
	printf("Among %d numbers, the percentage of %d is %.2f%%",h,w/2,percent);
	return 0;
}
