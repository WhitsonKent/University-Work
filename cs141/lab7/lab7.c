#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point
{
 int x;
 int y;
 char label[21];
 struct point *ptrNext;  // self referential pointer
};

int isEmptyList(struct point *ptrF);
void PrintList(struct point *ptrF);
void ResetList(struct point *ptrF, struct point *ptrL);
void AddToBeginning(struct point *ptrF, struct point *ptrL);
void AddToEnd(struct point *ptrF, struct point *ptrL);
void InputRecord(struct point *ptrNew); // used by Add to interactively get the values from the user

struct point *ptrFirst = NULL;
struct point *ptrLast = NULL;

void main()
{
  int first=1;//determines first node
  int menu=0;
  struct point *ptrNode;
  ptrNode=malloc(sizeof(struct point));
  ptrFirst=ptrNode;
  // do the menu
  for(;;)
  {
    printf("What would you like to do?\n");
    printf("1. Add a point at the END of the list\n");
    printf("2. Add a point at the BEGINNING of the list\n");
    printf("3. Is the list empty?\n");
    printf("4. Erase all points from the list (reset).\n");
    printf("5. Display the list.\n");
    printf("6. Save the list to a sequential file\n");
    printf("7. Read the list back from a sequential file\n");
    printf("0. Exit\n");
    printf(">> ");
    scanf("%d",&menu);
    switch (menu)
    {
      case 1:
      if(first){
        InputRecord(ptrFirst);
        first=0;
        ptrLast=ptrFirst;
      }
      else AddToEnd(ptrFirst,ptrLast);
      break;
      case 2:
      if(first){
        InputRecord(ptrFirst);
        first=0;
        ptrLast=ptrFirst;
      }
      else AddToBeginning(ptrFirst,ptrLast);
      break;
      case 3:
      if(isEmptyList(ptrFirst)) printf("Empty\n" );
      else printf("Not Empty\n");
      break;
      case 4:
      ResetList(ptrFirst,ptrLast);
      first=1;
      break;
      case 5:
      if(isEmptyList(ptrFirst)!=1)PrintList(ptrFirst);
      else printf("Its empty!\n");
      break;
      case 6:
      break;
      case 7:
      break;
    }
    if(menu==0) break;
  }
  free(ptrNode);
}

int isEmptyList(struct point *ptrF)
{
  if(ptrF==NULL){return 1;}
  else return 0;
}

void InputRecord(struct point *ptrNew)
/*prompts user to enter a record
INPUT:New point
OUTPUT:Filled point*/
{
  int xVal, yVal;
  char name[21];
  printf("Enter x value\n");
  scanf("%d",&xVal);
  ptrNew->x=xVal;
  printf("Enter y value\n");
  scanf("%d",&yVal);
  ptrNew->y=yVal;
  printf("Enter a label\n" );
  scanf("%s",&name);
  strcpy(ptrNew->label,name);
  ptrNew->ptrNext=NULL;
}

void PrintList(struct point *ptrF)
{
  struct point *temp=(struct point* )malloc(sizeof(struct point));
  temp=ptrF;
  for(;;)
  {
    printf("%s x:%d y:%d\n",temp->label,temp->x,temp->y);
    if (temp->ptrNext==NULL) break;
    temp=temp->ptrNext;
  }
  free(temp);
}

void AddToBeginning(struct point *ptrF, struct point *ptrL)
{
  struct point *temp=(struct point* )malloc(sizeof(struct point));
  InputRecord(temp);
  temp->ptrNext=ptrF;
  ptrF=temp;
  free(temp);
}
void AddToEnd(struct point *ptrF, struct point *ptrL)
{
  struct point *temp=(struct point* )malloc(sizeof(struct point));
  InputRecord(temp);
  ptrL->ptrNext=temp;
  ptrLast=temp;
  free(temp);
}
void ResetList(struct point *ptrF, struct point *ptrL)
{
  ptrFirst=NULL;
  ptrLast=NULL;
}
