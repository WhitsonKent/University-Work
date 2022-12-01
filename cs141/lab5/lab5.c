/*Kent Whitson
104797895
Mar 11
Lab 5
String Tokenization*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 140//max characters string can be

//PROTOTYPE
void ParseSentence(char S[MAX]);//takes a sentence, rearranges words in
//alphabetical order

int main()
{
	char S[]="mmmmm steamed hams. oh, not in utica.no; it's an albany expression.";
	ParseSentence(S);
}

void ParseSentence(char S[MAX])
/*This function takes words from a sentence and puts them in alphabetical order
INPUT:string
OUTPUT:string of words organized alphabetically*/
//only works if all letters are lowercase or all uppercase
//takes a maximum of 26 words and with less than 35 characters
{
	char *word;//individual word in the strings
	int i=0,size=0,flag=0;//i indexes wordlist, size is the amount of words in wordlist
	char wordlist[100][35];//allows for 100 words, with a max of 35 characters perword
	char hold[35];//holds strings to be swapped
	word = strtok (S," ,.;");
	int r=0;//keeps track of how many words there are
	while (word != NULL)//keeps gooing tilll no new word is found
  {
		strcpy(wordlist[r],word);
		r++;
    word = strtok (NULL, " ,.;");
  }

	//SORTING
	//this works only if the casing is the same for all leters in the string
	do {
		flag=0;
		for(int i=0;i<r-1;i++)
		{
			if(strcmp(wordlist[i],wordlist[i+1])>0)//checks for differences
			{
				strcpy(hold,wordlist[i]);
				strcpy(wordlist[i],wordlist[i+1]);
				strcpy(wordlist[i+1],hold);
				flag=1;//indicates a swap
			}

		}
	} while(flag);
	//printing
	for(int i=0;i<r;i++)
	{
		printf("%s\n",wordlist[i]);
	}
}
