#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	time_t tm;
	srand((unsigned) time(&tm));
	int array[5][5];
	int rowTotal=0,colTotal=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			array[i][j]=rand()%24;
			}
	}
	for(int i=0;i<5;i++){
		printf("Row %d: ",i+1);
		for(int j=0;j<5;j++){
			printf("%d ",array[i][j]);
			}
			printf("\n");
	}
	printf("Row totals: ");
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			rowTotal+=array[i][j];
			}
			printf("%d ",rowTotal);
			rowTotal=0;
	}
	printf("\n");
	printf("Column totals: ");
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			colTotal+=array[j][i];
			}
			printf("%d ",colTotal);
			colTotal=0;
	}
}