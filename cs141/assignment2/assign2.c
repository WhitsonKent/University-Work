/* WHITSON,  Kent 
ID:  104797895
Assignment 2
Date: February 28, 2018
Purpose: This is a sample C program used for practice 
I acknowledge that this is my own work and did not 
receive any unauthorized help with it.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 20
#define ROW 20

//PROTOTYPES
void PopulateArray2DUnique(int A [][COL],unsigned int rowsize, 
unsigned int colsize, int min, int max);
void DisplayArray2D(int A[][COL],unsigned int rowsize, unsigned int colsize);
int FindLargest(int A[][COL],unsigned int rowsize, unsigned int colsize);
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, 
unsigned int col_to_sum);
int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize);
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize,
unsigned int colsize);
int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize,
unsigned int colsize);


int main()
{
	//TestZone
	printf("\nTest using 3x3 array\n");
	int a1[ROW][COL], a2[ROW][COL];
	PopulateArray2DUnique(a1,3,3,1,9);
	printf("Populated Array\n");
	DisplayArray2D(a1,3,3);
	printf("FindLargest: %d",FindLargest(a1,3,3));
	printf("\nFindColsum of col 0: %d",FindColSum(a1,3,3,0));
	printf("\nSorted Array\n");
	Sort2DArray(a1,3,3);
	DisplayArray2D(a1,3,3);
	printf("Copy of Above\n");
	CopyArray2D(a1,a2,3,3);
	DisplayArray2D(a2,3,3);
	printf("SpiralCopy\n");
	CopyArray2DSpiral(a1,a2,3,3);
	DisplayArray2D(a2,3,3);
	
	printf("\nTest using 5x5 array\n");
	int b1[ROW][COL], b2[ROW][COL];
	PopulateArray2DUnique(b1,5,5,10,77);
	printf("Populated Array\n");
	DisplayArray2D(b1,5,5);
	printf("FindLargest: %d",FindLargest(b1,5,5));
	printf("\nFindColsum of col 0: %d",FindColSum(b1,5,5,0));
	printf("\nSorted Array\n");
	Sort2DArray(b1,5,5);
	DisplayArray2D(b1,5,5);
	printf("Copy of Above\n");
	CopyArray2D(b1,b2,5,5);
	DisplayArray2D(b2,5,5);
	printf("SpiralCopy\n");
	CopyArray2DSpiral(b1,b2,5,5);
	DisplayArray2D(b2,5,5);
	
	printf("\nTest using 3x4 array\n");
	int c1[ROW][COL], c2[ROW][COL];
	PopulateArray2DUnique(c1,3,4,0,100);
	printf("Populated Array\n");
	DisplayArray2D(c1,3,4);
	printf("FindLargest: %d",FindLargest(c1,3,4));
	printf("\nFindColsum of col 0: %d",FindColSum(c1,3,4,0));
	printf("\nSorted Array\n");
	Sort2DArray(c1,3,4);
	DisplayArray2D(c1,3,4);
	printf("Copy of Above\n");
	CopyArray2D(c1,c2,3,4);
	DisplayArray2D(c2,3,4);
	printf("SpiralCopy\n");
	CopyArray2DSpiral(c1,c2,3,4);
	DisplayArray2D(c2,3,4);
	
	return 0;
}

void PopulateArray2DUnique(int A [][COL],unsigned int rowsize,
 unsigned int colsize, int min, int max)
/*Populates the 2D Array of sizes rowsize x colsize with random integers
ranging between min and max inclusive.
INPUT: A(2D Array),row size, column size, minimum num generated, max num generated
OUTPUT:Fully populated array*/
/*THIS ONLY WORKS IF THE RANGE OF NUMBERS IS LARGER OR EQUAL TO THE AMOUNT
OF AVAILABLE SPOTS IN THE ARRAY (1+max-min)>=(rowsize*colsize)*/
{
	int range = 1+max - min;//range is the random numbers being generated
	int nums[range];//nums keeps track of unique numbers
	//Range will also be the size of the array nums
	//this is because it can only generate unique number within the range
	int k=0;//index of num
	int random=0,flag=0;//random for random variable, flag makes sure unique
	srand(time(NULL));//this generates truly random numbers with each run
	for(int r=0; r<rowsize;r++)
	{
		for(int c=0; c<colsize;c++)
		{
			//Checks to make sure random number is unique
			do
			{
				flag=0;
				random=min+rand()%range;
				for (int i=0;i<range;i++)//searches nums[] to make sure random is unique
				{
					if (random==nums[i]) flag=1;
					//if unique, flag=0 and will exit loop
				}
			}while(flag);
			
			A[r][c]=random;
			nums[k]=random;
			k++;
			/*populates the array at position r,c with numbers between min and max*/
		}
	}
}

void DisplayArray2D(int A[][COL],unsigned int rowsize, unsigned int colsize)
/*Prints 2D arrays
Recieves a 2D array as an input
prints what it looks like*/
{
	for(int r=0; r<rowsize;r++)
		//Begins by starting with a row
	{
		for(int c=0; c<colsize;c++)
			// prints the values in each column of said row
		{
		printf("%d ",A[r][c]);
		}
	printf("\n");
	}
}

int FindLargest(int A[][COL],unsigned int rowsize, unsigned int colsize)
/*Finds the largest integer in a 2Darray
INPUT:An array, row size, column size
OUTPUT: Largest value in the array*/
{
	int LRG=0;//LRG stands for largest
	for(int r=0; r<rowsize;r++)
	{
		for(int c=0; c<colsize;c++)
		{
			//Checks A[r][c] to check if larger than int LRG
			if (LRG<A[r][c])
			{
				LRG=A[r][c];
			}
		}
	}
	return LRG;	
}

int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, 
unsigned int col_to_sum)
//Finds the sum of all numbers in a given column
//INPUT: 2D Array, its dimension, and column you'd like to sum
//OUTPUT: Sum of all numbers in a given column
{
	int c = col_to_sum;//Column being summed
	int sum=0;
	for(int r=0; r<rowsize;r++)
	{
		sum+=A[r][c];//Sum increments as each column is checked
	}
	return sum;	
}

int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize)
/*Sorts a 2d array in ascending order
INPUT: 2d array and its dimensions
OUTPUT: Sorted 2d array*/
{
	if(rowsize>ROW || colsize>COL) return -1;
	
	int hold = 0;//Holds the value of the number to be swapped
	int flag;//indicates if sorted or not
	do{
		flag=0;
		//Runs while it hasn't been flagged i.e, no swap is made
		for(int r=0; r<rowsize;r++)
		{
			for(int c=0; c<colsize;c++)
			{
				//Compares Column c with the column to the right
				if(A[r][c]>A[r][c+1] && c+1<colsize)
				{
					//Switches position of the variables
					hold = A[r][c];
					A[r][c]=A[r][c+1];
					A[r][c+1]=hold;
					flag =1;
					//Informs us a swap took place on this pass
				}
				//If c = colsize-1, Compares [r][c] with [r+1][0]
				else if(A[r][c]>A[r+1][0] && r+1<rowsize)
				{
					hold = A[r][c];
					A[r][c]=A[r+1][0];
					A[r+1][0]=hold;
					flag=1;
					//Informs us a swap took place on this pass
				}
			}
		}
	}while(flag);
	return 0;
}

int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize,
unsigned int colsize)
/*Copy the contents of array A into array B of the same size such that
the contents of B would be exactly the contents of A
INPUT: Array and the array its being copied onto and their dimensions
OUTPUT: Copys A into B*/
{
	if(rowsize>ROW || colsize>COL) return -1;
	
	for(int r=0; r<rowsize;r++)
	{
		for(int c=0; c<colsize;c++)
		{
			B[r][c]=A[r][c];
			/*populates B at position r,c with values at A[r][c]*/
		}
	}
	return 0;
}

int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, 
unsigned int colsize)
/*Copies an array in a spiral pattern
INPUT: 2 arrays and their dimensions
OUTPUT: An array in a spiral pattern*/
{
	if(rowsize>ROW || colsize>COL) return -1;
	
	int nums[rowsize*colsize];//This will put A into a 2Darray
	int *ptrN;//Points to nums
	ptrN=&nums[0];
	for(int r=0; r<rowsize;r++)
	{
		for(int c=0; c<colsize;c++)
		{
			*ptrN=A[r][c];//Converts the info from A into a 2d array
			ptrN++;
		}
	}
	ptrN=&nums[0];
	
	int i,r=0, c=0,m=rowsize,n=colsize;
	//i keeps track of the direction the array is being filled in
	//r is for row
	//c is for column
	//m keeps track of empty rows
	//n keeps track of empty columns
    while (r<m && c<n)
    {
        //Puts info from nums into higherst remaing row of B from left to right
        for (i=c; i<n;++i)
        {
            B[r][i]=*ptrN;
			ptrN++;
        }
        r++;//indicates uppermost row is filled
 
         //furthest right remaing column is filled in
        for (i = r;i< m;++i)
        {
            B[i][n-1]=*ptrN;
			ptrN++;
        }
        n--;//indicates a column has been fully filled in
        //fills in lowest row from right to left
        if (r<m)
        {
            for (i=n-1;i>=c;--i)
            {
                B[m-1][i]=*ptrN;
				ptrN++;
            }
            m--;//indicates furthest right row is fully filled in
        }
        //leftermost remaining column gets filled in
        if (c<n)
        {
            for (i = m-1;i>=r;--i)
            {
                B[i][c]=*ptrN;
				ptrN++;
            }
            c++;//leftermost column is filled in, moves to next column over    
        }        
    }
	return 0;
}