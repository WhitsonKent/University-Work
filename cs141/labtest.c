/*Kent Whitson
104797895
March 6
Lab Exam 2
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 10
#define TRAPS 3
//PROTOTYPES
void InitializeMaze(char A[][COLS]);
int DoTrace(char A[ROWS][COLS],int x,int y);
void PrintResults(int num,char A[ROWS][COLS]);


void main()

{ char A[ROWS][COLS];
  int startX, startY;
  int num_moves=0;
  scanf("%d%d",&startX,&startY);
  InitializeMaze(A);//TODO: CODE THESE FUNCTIONS
  num_moves = DoTrace(A,startX,startY);
  PrintResults(num_moves,A);
}

void InitializeMaze(char A[ROWS][COLS])
//initializez arraywith random values
//INPUT: array
//OUTPUT:Populated array
{
	//r for row, c for column
  int letter;
  int flag=0;//indicates if G is placed or not
	for(int r=0; r<ROWS;r++)
	{
		for(int c=0; c<COLS;c++)
		{
      if (flag==0)
      {
        letter=1+rand()%6;//selects a value from 0 to 6
      }
      else
      {
        letter=1+rand()%5;//selects a value from 0 to 6
      }
      if(r==ROWS-1&&c==COLS-1&&flag==0)//Failsafe to ensure there is 1 G
      {
        letter=6;
      }
      //each number is for a different char
      switch(letter)
      {
        case 1:
        A[r][c]='D';
        break;
        case 2:
        A[r][c]='U';
        break;
        case 3:
        A[r][c]='R';
        break;
        case 4:
        A[r][c]='L';
        break;
        case 5:
        A[r][c]='T';
        break;
        case 6:
        A[r][c]='G';
        flag=1;
        break;
      }
		}
	}
}
int DoTrace(char A[ROWS][COLS],int x, int y)
//follows directions from array to find gold or trap
//INPUT: Array and starting points
//OUTPUT:Whether gold is gound or not
{
  int moves=1;//moves made
  char tile=A[y][x];//postition in the map
  for(;moves<=10;moves++)
  {
	tile=A[y][x];
    if(tile=='D'){
      y+=1;
    }
    if(tile=='U'){
      y-=1;
    }
    if(tile=='R'){
      x+=1;
    }
    if(tile=='L'){
      x-=1;
    }
    if(tile=='T'){
      return moves*-1;
    }
    if(tile=='G'){
      return moves;
    }
  }
  return 0;
}
void PrintResults(int num,char A[ROWS][COLS])
//prints The Array and results
//INPUT:results and arrays
//OUTPUT:Array and moves made
{
  {
  	for(int r=0; r<ROWS;r++)//r for row
  		//Begins by starting with a row
  	{
  		for(int c=0; c<COLS;c++)//c for col
  			// prints the values in each column of said row
  		{
  		printf("%c ",A[r][c]);
  		}
  	printf("\n");
  	}
  }
  if(num==0)
  {
    printf("Still stuck after 10 moves");
  }
  if(num>0)
  {
    printf("Gold found in %d moves",num);
  }
  if(num<0)
  {
    printf("Hit a trap in %d moves",-1*num);
  }
}
