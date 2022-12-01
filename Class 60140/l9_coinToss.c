#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip(){
	int result;
	result=(rand()%2);
	return result;
}
int main(void){
	time_t tm;
	srand((unsigned) time(&tm));
	int coin;
	int tails=0, heads=0;
	for (int i=0;i<100;i++){
		coin= flip();
		if(coin==0){
			tails+=1;
			printf("Tails ");
			}
		if(coin==1){
			heads+=1;
			printf("Heads ");
			}
	}
	printf("\n\nThe total number of Heads was %d\n",heads);
	printf("The total number of Tails was %d\n",tails);
}