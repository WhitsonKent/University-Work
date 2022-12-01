/* WHITSON,  Kent 
ID:  104797895
Lab Exercise #1
Date: January 23, 2018
Purpose: This is a sample C program used for practice */ 

#include <stdio.h>
#include <math.h>

int f1a(int n);//f stands for function, the number is in
int f1b(int n);//reference to the question, and a is for
int f2a(int n);//non recursive functions and b is for a
int f2b(int n);//recursive function
int f3a(int n);//n is the number the user will enter
int f3b(int n);
int f4a(int a,int b);//a and b are also used for the numbers they oughtta enter
int f4b(int a, int b);
int f5a(int a, int b);
int f5b(int a, int b);
void f6a(int n);
void f6b(int n);
void f7a(int n);
void f7b(int n);
void f8a(int n);
void f8b(int n);

int main(){
	int f =0,a=0,b=0;//f represents which function you'd like to run
	/*a and b are the variable the program will ask you to assign
	a value to*/
	printf("Which function would you like to run?(1-8): ");
	//Its assumed  that the user enters a number between 1 and 8.
	scanf("%d",&f);
	printf("Only enter positive numbers\n");
	/*For ALL functions it is assumed that the user will enter
	only positive numbers*/
	switch(f){
		//in each case the program asks the user how many numbers they need to enter
		case 1:
		printf("Enter a Number: ");
		scanf("%d",&a);
		printf("Non Recursive\n %d\n",f1a(a));
		printf("Recursive\n %d\n",f1b(a));
		break;
		case 2:
		printf("Enter a Number: ");
		scanf("%d",&a);
		printf("Non Recursive\n %d\n",f2a(a));
		printf("Recursive\n %d\n",f2b(a));
		break;
		case 3:
		printf("Enter a Number: ");
		scanf("%d",&a);
		printf("Non Recursive\n %d\n",f3a(a));
		printf("Recursive\n %d\n",f3b(a));
		break;
		case 4:
		printf("Enter a Number: ");
		scanf("%d",&a);
		printf("Enter another Number: ");
		scanf("%d",&b);
		printf("\nNon Recursive\n %d",f4a(a,b));
		printf("\nRecursive\n %d",f4b(a,b));
		break;
		case 5:
		printf("Enter a Number: ");
		scanf("%d",&a);
		printf("Enter another Number: ");
		scanf("%d",&b);
		printf("\nNon Recursive\n %d",f5a(a,b));
		printf("\nRecursive\n %d",f5b(a,b));
		break;
		case 6:
		printf("Enter a Number: ");
		scanf("%d",&a);
		printf("\nNon Recursive\n");
		f6a(a);
		printf("\nRecursive\n");
		f6b(a);
		break;
		case 7:
		printf("Enter a Number: ");
		scanf("%d",&a);
		printf("\nNon Recursive\n");
		f7a(a);
		printf("Recursive\n");
		f7b(a);
		break;
		case 8:
		printf("Enter a Number: ");
		scanf("%d",&a);
		printf("\nNon Recursive");
		f8a(a);
		printf("\nRecursive\n");
		f8b(a);
		break;
	}
}

int f1a(int n)
/*This function finds the sum of all numbers from 1 to n
it is assumed n>0
n is the max number it will add to, i is where we start, x is the output
it will then output x as the summ of all numbers from 1 to n*/
{
	if (n<=0)//if a number equal or less to 0 is entered it returns 0
	{
		return 0;
	}
	int x=0;
	for(int i=1;i<=n;i++)
	{
		x+=i;
	}
	return x;
}

int f1b(int n)
/*Finds the sum of all numbers from 1 to n
it is assumed n>0
by putting what happens when x is less than 0 
the function knows when to stop recursing and
output the the sum of all numbers from 1 to n*/
{
	int x =n;//if a number equal or less to 0 is entered it returns 0
	if (x<=0){
		return 0;
	}
	x=f1b(n-1)+n;
	return x;
}

int f2a(int n){
	/*This function finds the sum of (i+1)^2 to n starting with i =1
	it is assumed the user will not enter a number less than 1
	The funtion then will output x which increases n times in the for loop*/
	int x = 0;
	for (int i=1;i<=n;i++)
	{
		x+=pow((i+1),2);
	}
	return x;
}
int f2b(int n){
	/*This function finds the sum of (i+1)^2 to n starting with i =1
	it is assumed the user will not enter a number less than 1
	This function finds the proper output by finding f2b(n-1)+(n+1)^2
	as you can find any step in the function if you know the previous step */
	int x = 0;
	if(n<=0)
	//this lets the function know to stop recursing when it reaches 0
	{
		return 0;	
	}
	x=f2b(n-1)+pow((n+1),2);
	return x;
}

int f3a(int n){
	/*You enter a number to create an array
	it is assumed n isn't negative
	using the loop below the program will perform
	the fibonacci sequence by assigning each spot in the array a
	value*/
	int fib[n];
	fib[0]=0;
	fib[1]=1;
	if(n>=2)
	{
		for(int i=2; i<=n;i++)
		{
			fib[i]=fib[i-1]+fib[i-2];
			/*here it looks into the array to determine what
			the next spot in the array will be*/
		}
	}
	return fib[n];/*it then returns the last spot in the array
	which is what the answer should be*/
}

int f3b(int n){
	/*This function does the fibonacci sequence
	it assumes that fibonacci(0)=0, and fibonacci(1)=1, and that n isn't negative
	it will the return the fibonacci(n) by adding the 2
	previous numbers in the sequence together as seen below*/
	int x = 0;
	if (n==1)
	{
		return 1;
	}
	if (n<=0)
	{
		return 0;
	}
	x = f3b(n-1)+f3b(n-2);
	return x;
}

int f4a(int a, int b){
	/*This function finds the greatest common denominator (gcd)
	between x and y under the assumption that if y=0, the gcd
	is x and that if y>0 the gcd between(x,y) is the same as the
	gcd of(y,x mod y). it will then return the gcd*/
	int x = a;
	int y = b;
	int gcd=1;
	/*the following if statements makes it so the 
	assumptions listted above are met*/
	if(y>0)
	{
		x=b;
		y=a%b;
	}
	if (y==0)
	{
		return x;
	}
	for(int i=2; i<=x&&i<=y; i++)
		/*this function finds the gcd by going through
		all the number between 2 and x or y till it finds
		the value for i which x and y mod i is equal to 0*/
	{
		if (x%i==0&&y%i==0)
		{
			gcd = i;
		}
	}
	return gcd;
}

int f4b(int a, int b){
	/*This function finds the greatest common denominator (gcd)
	between x and y under the assumption that if y=0, the gcd
	is x and that if y>0 the gcd between(x,y) is the same as the
	gcd of(y,x mod y). it will then return the gcd*/
	int x = a;
	int y = b;
	int gcd=1;
	/*the following if statements makes it so the 
	assumptions listted above are met*/
	if(y>0)
	{
		x=b;
		y=a%b;
	}
	if (y==0)
	{
		return x;
	}/*this function works by repeating till y eventually equals 0,
	at which point x will be the gcd*/
	gcd=f4b(x,y);
	return gcd;
}

int f5a(int a, int b){
	/*This function finds a to the power of b
	x represents a
	it will then output a to the power of b*/
	int x = a;
	for(int i=1;i<b;i++)
	{
		x=x*a;
		/*in this loop a will multiply itself b times.*/
	}
	return x;
}

int f5b(int a, int b){
	/*This function finds a to the power of b
	x represents a, y represents b, it is assumed a and b arent negative
	it will then output a to the power of b*/
	int x = a;
	int y = b;
	if(y==0)
	{
		return 1;
		/*this is here so the program knows anything 
		to the power of 0 is 1*/
	}
	x=f5b(x,y-1)*a;/*it recurses by finding the power of a*(b-1),
	then multiplying by a again so that it returns a^b*/
	return x;
}

void f6a(int n){
	/*This function counts down from n to 1
	it is assumed n>0
	n=i and i is the number being counted down from
	it then outputs each number from i to 1
	using the loop below*/
	for(int i=n;i>=1;i--)
	{
		printf("%d ",i);
	}
}

void f6b(int n){
	/*This function counts down from n to 1
	it is assumed n>0
	once it prints n, it then call on f6b(n-1) repeating till
	n=0*/
	if(n>0)
	{
		printf("%d ",n);
		f6b(n-1);
	}
}

void f7a(int n){
	/*This functon outputs a triange of stars
	its assumed n is not <=0
	it will print n stars, start a new line printin n-1 stars
	n times till only 1 star is output*/
	for (int i=n;i>=0;i--)
	{
		for(int j=0;j<i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void f7b(int n){
	/*This functon outputs a triange of stars
	its assumed n is not <=0
	it will print n stars, start a new line the recurse to 
	to print n-1 stars till n=1*/
	if (n>0)
	{
		for (int i=0;i<n;i++)
		{
			printf("*");
			}
			printf("\n");
			f7b(n-1);
	}
}

void f8a(int n){
	/*This functon outputs a triange of stars
	its assumed n is not <=0
	it will print 1 star, increasing by 1 each line till n lines
	have been printed.*/
	for (int i=0;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void f8b(int n){
	/*This functon outputs a triange of stars
	its assumed n is not <=0
	it finds what f8b(n-1 is till it reaches 1, then it knows
	how many stars to output for each line*/
	if(n>0)
	{
		f8b(n-1);
		for(;n>=1;n--)
		{
			printf("*");
		}
		printf("\n");
	}
}



