/*Kent Whitson
104797895
Jan 29
Lab 2
Purpose is to practice coding
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//indicates max rows(10) and columns (5)
#define M 10
#define N 5
//prototype
void InitializeArray2D(int a[M][N]);
void PopulateRandomValues2D(int a[M][N]);
void PrintArray2D(int a[M][N]);
void Sort2D(int a[M][N]);
void LinearSearch2D(int a[M][N],int key);

int main(){
  int array[M][N];//The array
  int choice;//Choice from the menu
  int search;//Variable the user is searching for in LinearSearch2D
  do
  {
	  //MENU
	  //Asks the user which function to run till 0 is entered
	  //It is assumed that the array is first initalized by the user
	  //other wise the other functions won't work
	  printf("\nWhich function would you like to run?(0 to EXIT)\n");
	  printf("1-InitializeArray2D\n2-PopulateRandomValues2D\n");
	  printf("3-PrintArray2D\n4-Sort2D\n5-LinearSearch2D\n");
	  scanf("\n%d",&choice);
	  switch(choice)
	  {
		  case 1:
		  printf("\nInitalizing array...\n");
		  InitializeArray2D(array);
		  printf("Array initalized\n");
		  PrintArray2D(array);
		  break;
		  case 2:
		  printf("\nPopulating array...\n");
		  PopulateRandomValues2D(array);
		  printf("Array populated\n");
		  PrintArray2D(array);
		  break;
		  case 3:
		  PrintArray2D(array);
		  break;
		  case 4:
		  printf("\nSorting array...\n");
		  Sort2D(array);
		  printf("Finished sorting\n");
		  PrintArray2D(array);
		  break;
		  case 5:
		  printf("\nEnter the number you are searching for: ");
		  scanf("%d",&search);//Gets value for LinearSearch2D to find
		  LinearSearch2D(array,search);
		  break;
	  }	  
  }while(choice!=0);
}
//a stands for array in all cases below
void InitializeArray2D(int a[M][N])
/*This function initializes the array with zeroes*/
{
  //r for row, c for column
  for(int r=0; r<M;r++){
    for(int c=0; c<N;c++)
    {
    a[r][c]=0;
    }
  }
}

void PopulateRandomValues2D(int a[M][N])
/*This populates the array with random values
from 1 to 100*/
{
	//r for row, c for column
	srand(time(NULL));//this makes its populated with random numbers
	for(int r=0; r<M;r++)
	{
		for(int c=0; c<N;c++)
		{
			a[r][c]=1+rand()%100;//selects a value from 1 to 100
		}
	}
}
void PrintArray2D(int a[M][N])
/*Prints 2D arrays
Recieves a 2D array as an input
prints what it looks like*/
{
	for(int r=0; r<M;r++)
		//Begins by starting with a row
	{
		for(int c=0; c<N;c++)
			// prints the values in each column of said row
		{
		printf("%d ",a[r][c]);
		}
	printf("\n");
	}
}

void Sort2D(int a[M][N])
//Takes a 2D Array and sorts it in ascending order
//Input is an unsorted array, outputs the array in ascending order
{
	int hold = 0;
	int flag;
	int r2=0,c2=0;
	do{
		flag=0;
		//Runs while it hasn't been flagged i.e, no swap is made
		for(int r=0; r<M;r++)
		{
			for(int c=0; c<N;c++)
			{
				//Compares Column c with the column to the right
				if(a[r][c]>a[r][c+1] && c+1<N)
				{
					//Switches position of the variables
					hold = a[r][c];
					a[r][c]=a[r][c+1];
					a[r][c+1]=hold;
					flag =1;
					//Informs us a swap took place on this pass
				}
				//If c = N-1, Compares [r][c] with [r+1][0]
				else if(a[r][c]>a[r+1][0] && r+1<M)
				{
					hold = a[r][c];
					a[r][c]=a[r+1][0];
					a[r+1][0]=hold;
					flag=1;
					//Informs us a swap took place on this pass
				}
			}
		}
	}while(flag);
}
void LinearSearch2D(int a[M][N],int key)
/*Input is a 2D Array and the key
Key is the value we're searching for
Outputs whether or not the key has been found*/
{
	int found;
	int counter=0;
	for(int r=0; r<M;r++)
	{
		for(int c=0; c<N;c++)
		{
			//Checks a[r][c] for the key
			if (key==a[r][c]){ 
			found=1;
			counter+=1;
			}
		}
	}
	//output
	if(found) printf("FOUND %d INSTANCE(S) OF %d\n",counter,key);
	else printf("ERROR 404: VALUE NOT FOUND\n");
}