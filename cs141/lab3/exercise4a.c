/*Kent Whitson
104797895
Feb 13
Lab 3
Purpose is to get familiar with pointers
*/

#include <stdio.h>

int main()
{
	int a = 7;//int a holds the value 7
	int *aPtr;//a pointer to a is made
	aPtr = &a;//tells us aPtr is a pointer to a
	printf("\n%p", &a);//returns the adress of a
	printf("\n%p", aPtr);//returns the value of aPtr, which is the adress of a
	printf("\n%p", &aPtr);//returns the adress of aPtr
	printf("\n%d", a);//returns the value of a
	printf("\n%d", *aPtr);//points to a and returns the value of a
	printf("\n%p", *&aPtr);//returns the value of aPtr, which is the adress of a
	printf("\n%p", &*aPtr);//does the same as *&aPtr
	printf("\n%d", *&a);//returns the value of a at the adress of a
	printf("%d", &*a);//doesn't work because a isn't a pointer
	return 0;
}