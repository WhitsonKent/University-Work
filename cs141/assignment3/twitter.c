/*Kent Whitson
104797895
Mar 21
Assignment 3*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
//what makes a tweet
struct tweet {
  int id;//each tweet is assigned an id
  char created_at[51];//time of creation
  char text[141];//140 character max
  char user[21];//users name
};typedef struct tweet tweet;

//PROTOTYPES
void createTweet(tweet tweets[],int i,char username[]);
void displayTweets(tweet tweets[],int max);
int loadTweets(tweet tweets[],char FileName[]);
void saveTweets(tweet tweets[],int max,char FileName[]);
void searchTweets(tweet tweets[],int max,char key[]);



void main(){
  tweet tweets[1000];//can make a maximum of 1000 tweets
  char username[21];//users name
  char saveFile[100];//file to be loaded or saved
  char key[21];//word being serched for
  int choice=0;//choice for the menu
  //LOGIN
  printf("Enter your username\n");
  fgets(username, sizeof(username), stdin);
  int i=0;//number of tweets
  //Below all tweets from file are put into tweets array
  //MENU
  for(;;)//keeps going till 6 is entered
  {
    printf("1. Create a new tweet\n2. Search tweets\n3. Display tweets\n");
    printf("4. Save tweets to file\n5. Load tweets from file\n6. Exit\n");
    fflush(stdout);
    scanf("%d",&choice);
    //CREATE TWEETS
    if (choice==1)
    {
      createTweet(tweets,i,username);
      i++;
    }
    //SEARCH TWEETS
    if(choice==2)
    {
      printf("Enter the word you are looking for:\n");
      scanf("%s",&key);
      searchTweets(tweets,i,key);
    };
    //DISPLAY TWEETS
    if (choice==3)
    {
      displayTweets(tweets,i);
    }
    //SAVE TWEETS
    if (choice==4)
    {
      printf("Enter a Filename:\n");
      scanf("%s",&saveFile );
      saveTweets(tweets,i,saveFile);

    };
    //LOAD TWEETS
    if (choice==5)
    {
      printf("Enter a Filename:\n");
      scanf("%s",&saveFile);
      i=loadTweets(tweets,saveFile);
      printf("%d tweets loaded\n",i );
    }
    if (choice==6){break;}
  }
}

void createTweet(tweet tweets[],int i,char username[])
/*creates a tweet
INPUT:Array, position in array(i), and username
OUTPUT:Uses this information to add a tweet to the array*/
{
  char line[141];
  struct tm *local;
  time_t t;
  t = time(NULL);
  local = gmtime(&t);//generates time
  //Determines ID
  if(i-1>=0){
    tweets[i].id = tweets[i-1].id+1;//increments id no.
  }//new tweets default to 1000
  else tweets[i].id = 1000;
  //Info is added to array
  strcpy(tweets[i].created_at,asctime(local));
  strcpy(tweets[i].user,username);
  fgets(line, sizeof(line), stdin);//buffer
  printf("Enter your tweet:\n");
  fgets(line, sizeof(line), stdin);
  strcpy(tweets[i].text,line);
}

void searchTweets(tweet tweets[],int max,char key[])
/*Searches tweets for a keyword
INPUT:Keyword and tweet array
OUTPUT:Any tweet containing the key*/
{
  char user[21];
  char created[51];
  //searches array
  for(int i=0;i<max;i++)
  {
    //displays tweet
    if(strstr(tweets[i].text,key)!=NULL)
    {
      strcpy(user,tweets[i].user);
      strcpy(created,tweets[i].created_at);
      //gets rid of \n
      user[strlen(user)-1]=' ';
      created[strlen(created)-1]=' ';
      //prints matching tweets
      printf("%d\tCreated at: %s",tweets[i].id,created);
      printf("by %s\n%s\n",user,tweets[i].text);
    }
  }
}

void displayTweets(tweet tweets[],int max)
/*Displays all tweets made
INPUT:Array of tweets and number of tweets
OUTPUT:Content of tweets*/
{
  char user[21];
  char created[51];
  for(int i=0;i<max;i++)
  {
    strcpy(user,tweets[i].user);
    strcpy(created,tweets[i].created_at);
    //gets rid of \n
    user[strlen(user)-1]=' ';
    created[strlen(created)-1]=' ';
    //prints tweet
    printf("%d\tCreated at: %s",tweets[i].id,created);
    printf("by %s\n%s\n",user,tweets[i].text);

  }
}

void saveTweets(tweet tweets[],int max,char FileName[])
/*Saves tweets from array to a file
INPUT:tweet array,num of tweets(max), and FileName
OUTPUT:Tweets saved to file*/
{
  FILE *fp;
        fp = fopen(FileName, "w");
  for(int i=0;i<max;i++)
  {
    //saves tweets
    fprintf(fp, "%d\n",tweets[i].id);
    fprintf(fp, "%s",tweets[i].created_at);
    fprintf(fp, "%s",tweets[i].user);
    fprintf(fp, "%s",tweets[i].text );
  }
  fclose(fp);
  printf("%d tweets saved\n",max);
}

int loadTweets(tweet tweets[],char FileName[])
/*Takes a file and loads tweets into an array
INPUT:tweet array and filename
OUTPUT:tweets are put into an array, returns the amount of tweets*/
{
  char line[141];//stpres line input
  int i=0;//amount of tweets
  FILE *fp;
        fp = fopen(FileName, "r");
  if(fp==NULL){fclose(fp);}
  else
  {
    //for(;!feof(fp);i++)%s
    while(fscanf(fp, "%s\n", line) != EOF)
    {
      //takes inputs from file in order of id,creation,user and the tweet itself
      tweets[i].id = atoi(line);
      fgets(line, sizeof(line), fp);
      strcpy(tweets[i].created_at,line);
      fgets(line, sizeof(line), fp);
      strcpy(tweets[i].user,line);
      fgets(line, sizeof(line), fp);
      strcpy(tweets[i].text,line);
      i++;
    }
    fclose(fp);
  }
  return i;//returns number of tweets made
}
