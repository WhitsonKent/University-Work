#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int n;
	sscanf(argv[1],"%d",&n);
	char *c1[10],*c2[10];
	char arg1[]="ls -lt";
	char arg2[]="ps -ef";

	for(int i=0;i<n;i++){ // loop will run n times (n=5)
  	   if(fork() == 0) {
	       printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
				 if(i==0) {
		 			parse(arg1,c1);
		 			execute(c1);
		 		}
		 		if(i==1) {
		 			parse(arg2,c2);
		 			execute(c2);
		 		}
				exit(0);
			}
		sleep(1);
	}
	for(int i=0;i<5;i++) // loop will run n times (n=5)
	       wait(NULL);

}

void execute(char **args){
  execvp(*args,args);
}
void parse(char *buf, char **args) {
 while (*buf != '\0') {
 /* Strip whitespace, so that the previous argument is terminated with \0 */
 while ((*buf == ' ') || (*buf == '\t'))
 *buf++ = '\0';
 *args++ = buf; /* Save the argument into args*/
 /** Skip over the argument.*/
 while ((*buf != '\0') && (*buf != ' ') && (*buf != '\t'))
 buf++;
 }
 *args = NULL;
}
