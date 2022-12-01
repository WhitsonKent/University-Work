#include <stdio.h>
#include <string.h>
#define MAX 140;
void noVowel(char S[]);
void main()
{
  
}

void noVowel(char S[])
{
  int len=strlen(S);
  char hold[len];
  int i=0,j=0;
  char *pch;
  pch=strtok(S,"aeiouAEIOU");
  while(pch!=NULL){
    strcat(hold,pch);
    pch=strtok(NULL,"aeiouAEIOU");
  }
  strcpy(S,hold);
}
