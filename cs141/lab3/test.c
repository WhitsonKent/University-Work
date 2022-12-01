#include <stdio.h>
#define MAX 20
void Swap(int *a, int *b);
int Triple(int *num);
void bubbleSort(int arr[MAX],int size,int sort);
void PrintArray(int *arr,int size);
void populate(int *arr,int size);
void tripleArray(int *arr,int size);


int main()
{
	int order;
	int array[10];
	populate(&array[0],10);
	PrintArray(&array[0],10);
	printf("\n");
	tripleArray(&array[0],10);
	PrintArray(&array[0],10);
	printf("\nDescending Sort<0, Ascending Sort>=0: ");
	scanf("%d",&order);
	bubbleSort(array,10,order);
	PrintArray(&array[0],10);
}

void Swap(int *a, int *b)
/*This function will swap the values of 'a' and 'b'
Input: Adress of 'a' and adress of 'b'
Output: the value of a is now b, and b is now a*/
{
	int holdA = *a, holdB = *b;//Holds the values of a and b
	//below the values are switched
	*a=holdB;
	*b=holdA;
}

int Triple(int *num)
/*Holds the value num points to
Input: A Number
Output: that number times 3*/
{
	int trip = 3*(*num);
	return trip;
}

void bubbleSort(int arr[MAX],int size, int sort)
/*This function sorts arrays in ascending order or descending
INPUT:Array, array size, sorting order
OUTPUT: Returns a sorted array*/
{
	int flag=0;//Flag determines if sorted
	int *aPtr,*bPtr;
	aPtr=&arr[0];
	bPtr=&arr[0];
	do
	{
		flag=0;
		for(int i=0;i<size;i++ )
		{
			aPtr=&arr[i];
			bPtr=&arr[i+1];
			if (sort>=0)//ASCENDING ORDER SORT
			{
				if(*aPtr>*bPtr&&(i+1)<size)
				{
					Swap(aPtr,bPtr);
					flag = 1;
				}
				
			}
			else//DESCENDING ORDER SORT
			{
				if(*aPtr<*bPtr&&(i+1)<size)
				{
					Swap(aPtr,bPtr);
					flag = 1;
				}
			}
		}
	}while(flag);//Only exits when sorted
}

void PrintArray(int *arr,int size)
/*Prints an array
INPUT:An array
OUTPUT: That array but printed*/
{	
	for(int i=0;i<size;i++)
	{
		printf("%d ",*arr);
		arr++;
	}
}

void populate(int *arr,int size)
/*Populates an array by 2 starting at 4
INPUT: An array
OUTPUT:A newly populated array*/
{
	for(int i=1;i<=size;i++)
	{
		*arr=2+2*i;
		arr++;
	}
}

void tripleArray(int *arr,int size)
/*Triples each element in an array
INPUT: An array
OUTPUT:An array with every value tripled*/
{
	for(int i=1;i<=size;i++)
	{
		*arr=Triple(arr);
		arr++;
	}
}