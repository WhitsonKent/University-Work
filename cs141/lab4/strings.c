/*Kent Whitson
104797895
Feb 26
Lab 4
Purpose is to get familiar with pointers and strings*/
#include <stdio.h>
#define M 80

void Reverse(char *str);
void RecursiveReverse(char str[],int index);
void Swap(char *a, char *b);

int main()
{
	char Buffer1[]={'t', 'h', 'i', 's', ' ', 'i','s',' ','t','h','e',' ',
	'f','i','r','s','t',' ','b','u','f','f','e','r','\0'};
	
	char Buffer2[]="this is the second buffer";
	
	char Buffer3[80];
	char *pBuffer;
	pBuffer=&Buffer3[0];
	printf("Enter a string without spaces\n");
	scanf("%[^\n]s",&Buffer3);
	RecursiveReverse(Buffer1,0);
	//initially spaces couldn't be read, but with [^\n] they can
	printf("\n%s\n%s\n",Buffer1,Buffer2);
	/*it prints out all the strings properly except for Buffer3 as
	Buffer3 only registers inputs without spaces*/
	Reverse(Buffer3);
	do{
		printf("%c",*pBuffer);
		pBuffer++;
	}while(*pBuffer!='\0');
	printf("\n");
}

void Reverse(char str[])
/*reverses the string
input:string
output:reverse of string*/
{
	int size=0;
	char *sPtr,*ptr1,*ptr2;
	//sPtr stands for string ptr
	//ptr1 points at the beginning of an array, ptr2 will point to the end
	sPtr=&str[0];
	//determines the size of the array
	do{
		size++;
		sPtr++;
	}while(*sPtr!='\0');
	size--;
	int mid=size/2;//mid is the midpoint of the array
	ptr1=&str[0];//beginning of the array
	ptr2=&str[size];//end of the array
	for(int i=0; i<=mid;i++)
		/*it reverses the string by swapping the values of ptr1 and ptr2
		till it reaches the midpoint of the array. This is because at the
		midpoint anything we could have reverse has been reversed*/
	{
		Swap(ptr1,ptr2);
		ptr1++;//starts at beginning, counts up to mid
		ptr2--;//starts at end, counts down to mid
	}
}

void Swap(char *a, char *b)
/*This function will swap the values of 'a' and 'b'
Input: Adress of 'a' and adress of 'b'
Output: the value of a is now b, and b is now a*/
{
	char holdA = *a, holdB = *b;//Holds the values of a and b
	//below the values are switched
	*a=holdB;
	*b=holdA;
}

void RecursiveReverse(char str[], int index)
/*This reverses a string recursively
input:string
output:reverse of string*/
{
	int size = 0;
	char *sPtr,*ptr1,*ptr2;
	sPtr=&str[0];//sPtr points to beginning of array
	//determines size of array
	do{
		size++;
		sPtr++;
	}while(*sPtr!='\0');
	size--;
	ptr1=&str[index];//beginning of the array
	ptr2=&str[size-index];//end of the array
	//by making ptr2 point to the size of the array minus the index
	//we ensure that the oppostie sides of the string are swapped
	if (index<size-index)//base case
	{
	Swap(ptr1,ptr2);
	RecursiveReverse(str,index+1);//recurses the function
	}
}