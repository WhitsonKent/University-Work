#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListItem
{
  int data;

  struct ListItem *next;
}node;

node *head=NULL;
node *last=NULL;

void addNode(int data);
void print_list();

int main() {
  int choice=1,data;
  for(;;)
  {
    printf("Enter Data to Store(0 to exit)\n");
    scanf("%d",&data);
    addNode(data);
    if (data==0)break;
  }
  print_list();
}

void addNode(int data)
{
  node *newNode=(node*)malloc(sizeof(node));
  if (data==0)
  {
    free(newNode);
  }
  else{
  newNode->data=data;
  newNode->next=NULL;

  if(head==NULL)
  {
    head=newNode;
    last=newNode;
  }
  else if(head!=NULL)
  {
    last->next=newNode;
    last=newNode;
  }
}
}

void print_list()
{
  node *temp=head;
  while(temp!=NULL)
  {
    printf("%d\n",temp->data);
    temp=temp->next;
  }
}
