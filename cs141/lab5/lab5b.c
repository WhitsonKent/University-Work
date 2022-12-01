/*Kent Whitson
104797895
Mar 11
Lab 5
String Tokenization*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//PROTOTYPE
void ParseSentence(char S[]);

int main()
{
	char S[]="general kenobi, hello there; this is where the fun begins.";
	ParseSentence(S);
}

void ParseSentence(char S[])
/*This function takes words from a sentence and puts them in alphabetical order
INPUT:string
OUTPUT:string of words organized alphabetically*/
//only works if all letters are lowercase or all uppercase
//takes a maximum of 26 words and with less than 35 characters
{
	char *word;//individual word in the strings
	int i=0,size=0,flag=0;//i indexes wordlist, size is the amount of words in wordlist
	char wordlist[26][35];//array of pointers to srtings
	char str1[35],str2[35];//holds strings to be swapped
	word = strtok (S," ,.;");
	int r=0;//r is for row
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
			//str1 and str2 hold the values of the strings to be swapped
			strcpy(str1,wordlist[i]);
			strcpy(str2,wordlist[i+1]);
			if(strcmp(wordlist[i],wordlist[i+1])>0)//checks for differences
			{
				strcpy(wordlist[i],str2);
				strcpy(wordlist[i+1],str1);
				flag=1;
			}

		}
	} while(flag);
	//printing
	for(int i=0;i<r;i++)
	{
		printf("%s\n",wordlist[i]);
	}
}
