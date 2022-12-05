#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void sigalrm();

int main(int argc, char* argv[]) {
	int seconds = atoi(argv[1]);
	int pid = fork();
	if (pid == 0) {
		sleep(seconds);
		kill(getppid(), SIGALRM);
		exit(1);
	}
	else { 
		printf("SLEEPING\n");
		signal(SIGALRM, sigalrm);
		pause();
	}
	printf(" slept for %d second(s).", seconds);
}

void sigalrm(){
	signal(SIGALRM, sigalrm); /* reset signal */
	printf("Ding!");
}