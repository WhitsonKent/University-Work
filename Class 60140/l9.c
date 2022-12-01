#include <stdio.h>
#include <math.h>

float calculateCharges(float n){
	float charge=2;
	if (n>3){
		charge=charge+0.5f*(floor(n-3));
	}
	if (charge>10){
		charge=10;
	}
	return charge;
}	
int main(void){
	float car1,car2,car3,charge1,charge2,charge3;
	printf("Enter the hours parked for 3 cars: ");
	scanf("%f %f %f",&car1,&car2,&car3);
	charge1=calculateCharges(car1);
	charge2=calculateCharges(car2);
	charge3=calculateCharges(car3);
	printf("\n%*s", 8,"Car");
	printf("%*s", 16,"Hours");
	printf("%*s", 16,"Charge");
	printf("\n%*s", 8,"1");
	printf("%*.1f", 16,car1);
	printf("%*.2f", 16,charge1);
	printf("\n%*s", 8,"2");
	printf("%*.1f", 16,car2);
	printf("%*.2f", 16,charge2);
	printf("\n%*s", 8,"3");
	printf("%*.1f", 16,car3);
	printf("%*.2f", 16,charge3);
	printf("\n%*s", 8,"TOTAL");
	printf("%*.1f", 16,car1+car2+car3);
	printf("%*.2f", 16,charge1+charge2+charge3);
}