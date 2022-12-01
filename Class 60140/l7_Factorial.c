#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(void)
{
	int n,original;
	for(;;){
		printf("Enter a positive integer(-ve to exit): ");
		scanf("%d",&n);
		original = n;
		short s = n;
		unsigned short us = n;
		int i = n;
		unsigned int ui = n;
		long int l = n;
		unsigned long int ul = n;
		long long int ll = n;
		unsigned long long int ull = n;
		long double ld = n;
		if(n<0){ 
		break;
		}
		if (n==0){
			s = 1;
			us = 1;
			i = 1;
			ui = 1;
			l = 1;
			ul = 1;
			ll = 1;
			ull = 1;
			ld = 1;
		}
		else{
			for(;n>1;n--){
				s = s*(n-1);
				us = us*(n-1);
				i = i*(n-1);
				ui = ui*(n-1);
				l = l*(n-1);
				ul = ul*(n-1);
				ll = ll*(n-1);
				ull = ull*(n-1);
				ld = ld*(n-1);
				}
				}
		printf("Factorial of %d:\n",original);
		printf("%hd (short, size = 2)\n",s);
		printf("%hu (unsigned short, size = 2)\n",us);
		printf("%d (int, size = 4)\n",i);
		printf("%u (unsigned int, size = 4)\n",ui);
		printf("%ld (long, size = 4)\n",l);
		printf("%lu (unsigned long, size = 4)\n",ul);
		printf("%lld (long long, size = 8)\n",ll);
		printf("%llu (unsigned long long, size = 8)\n",ull);
		printf("%Lg(long double, size = 12)\n",ld);
	}
	printf("Thank you for using my software\n");
	return 0;
}