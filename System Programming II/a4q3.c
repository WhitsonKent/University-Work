#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <string.h>

void sig_handler();

int main(int argc, char* argv[]) {
	signal(SIGCHLD, sig_handler);//enables catching of all child signals
	int pid = fork();
	if (pid == 0) {
		sleep(1);
		exit(0);//normal exit
	}
	pid = fork();
	if (pid == 0) {
		sleep(2);
		kill(getpid(), SIGABRT);//abnormal exit
	}
	while (1) {}
}

void sig_handler() {
	signal(SIGCHLD, sig_handler);
	int status;
	wait(&status);
	if (status != 0) {//Checks if exited normally or not
		printf("Child Terminated Abnormally Exit Code %d\n", status);
		exit(0);//parent terminates if child terminates abnormally
	} else printf("Child Terminated Normally Exit Code %d\n", status);
}
