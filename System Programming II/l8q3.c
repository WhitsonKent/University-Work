#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void action(int dummy){
	sleep(1);
}  

void child(int p);
void parent(int p, pid_t);

int main(int argc, char *argv[]){  
	int p[2];
	pid_t pid;  
	int childRes;

	pipe(p);

	if((pid=fork()) == 0)  
		child(p[1]);
	parent(p[0], pid);
}


void parent(int p, pid_t pid){  
	int childRes, n=0;

	while(1){
		signal(SIGUSR1, action);  

		pause();  

		read(p, &childRes, sizeof(int));
  
		printf("\nParent: child result: %d\n", childRes);  

		if(++n>5){
			printf("Parent: work done, bye bye\n");  
			kill(0, SIGTERM);
		}
		printf("Parent: waiting for child\n\n");  
		kill(pid, SIGUSR1);
	}
}

void child(int p){  
	int value;

	while(1){

		sleep(1);

		value = random()%100;  

		//write(&value, sizeof(int), 1, fp);  
		write(p, &value, sizeof(int));

		printf("Child: waiting for parent\n\n");  

		signal(SIGUSR1, action);

		kill(getppid(), SIGUSR1);  

		pause();
	}
}

