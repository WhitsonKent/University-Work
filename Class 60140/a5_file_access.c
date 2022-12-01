#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <wchar.h>
#include <string.h>
#define FILE_NAME "a5_test.txt"

int monthDay(int mon){
	int day,days;
	if(mon==2){
		days=28;
	}else if(mon<8){
		if(mon%2!=0){
			days=31;
		}else days=30;
	}else if(mon%2!=0){
		days=30;
		}else days=31;
	day=(rand()%days)+1;
	return day;
}
void prepare_data(int m){
	int num = (rand()%(m-10))+10;
	FILE *fp;
	fp= fopen(FILE_NAME,"w");
	for(int i=0;i<num;i++){
		int itemNum = (rand()%15)+5;
		float price = ((float)rand()/(float)(RAND_MAX)) * 200;
		int year=(rand()%17)+2000;
		int mon=(rand()%12)+1;
		int d=monthDay(mon);
		fprintf(fp,"%d		",itemNum);
		if(price>100){
		fprintf(fp,"$%.2f		",price);
		}else if(price>10){
			fprintf(fp,"$ %.2f		",price);
		}else{
			fprintf(fp,"$  %.2f		",price);
		}
		fprintf(fp,"%d/%d/%d\n",mon,d,year);
	}
	fclose(fp);
}
void obtainData(){
	printf("Item		Unit		Purchase\n");
	printf("		Price		Date\n");
	int c;
	FILE *fp;
	fp = fopen(FILE_NAME, "r");
	if (fp) {
		while ((c = getc(fp)) != EOF){
		putchar(c);}
		fclose(fp);
	}
}
int main(void){
	int mx =15;
	time_t tm;
	srand((unsigned) time(&tm));
	prepare_data(mx);
	obtainData();
}