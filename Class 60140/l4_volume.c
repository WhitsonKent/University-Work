#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main(void)
{
	float volume,radius=5,height=1;
	
	while (height!=0){
		
		printf("\nEnter a height(0 to exit program)\n");
		
		scanf("%f",&height);
		
		volume = M_PI*(pow(radius,2))*height;
		
		if(height <= radius && height>0 ){
			printf("Height has to be bigger than radius (5.0)\n");
			}
			else if (height==0){
				printf ("Thank you for using my software\n");
			}
			else 
			{
				printf("The volume is %.2f\n",volume);
				}
	}
	return 0;
}
