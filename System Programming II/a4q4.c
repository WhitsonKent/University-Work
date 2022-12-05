#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <string.h>

void sig_handler(int sig);

int main(int argc, char* argv[]) {
	printf("Signal Catcher\n");
	sleep(1);
	int pid = fork();
	if (pid == 0) {
		kill(getppid(), SIGINT);
		sleep(1);
		kill(getppid(), SIGQUIT);
		exit(1);
	}
	else {
		signal(SIGINT, sig_handler);
		pause();
		signal(SIGQUIT, sig_handler);
		pause();
	}
}

void sig_handler(int sig) {
	switch (sig) {
	case SIGINT:
		signal(SIGINT, sig_handler);
		printf("SIGNAL %d: %s\n", sig, strsignal(sig));
		break;
	case SIGQUIT:
		printf("SIGNAL %d: %s\n", sig, strsignal(sig));
		exit(0);
	}
}