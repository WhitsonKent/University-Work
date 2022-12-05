#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <string.h>

void sig_handler(int sig);

int main(int argc, char* argv[]) {
	char* args[]= { "./donothing",NULL };
	printf("Signal Catcher\n");//firsy we check to see if the signals get handled before exec
	signal(SIGINT, sig_handler);
	signal(SIGTSTP, sig_handler);
	kill(getpid(), SIGINT);
	kill(getpid(), SIGTSTP);
	sleep(1);
	int pid = fork();
	if (pid == 0) {
		execvp(args[0], args);
		exit(1);
	}
	else {
	}
	sleep(2);
	kill(getpid(), SIGINT);//check after execvp is complete if signals remain being properly handled
	kill(getpid(), SIGTSTP);
}

void sig_handler(int sig) {
	switch (sig) {
	case SIGINT://ctrl c handler
		signal(SIGINT, sig_handler);
		printf("Signal %d %s handled\n", sig, strsignal(sig));
		fflush(stdout);
		break;
	case SIGTSTP://ctrl z handler
		signal(SIGTSTP, sig_handler);
		printf("Signal %d %s ignored\n", sig, strsignal(sig));//technically it doesn't ignore the signal, more like it nullifies its effects
		fflush(stdout);
		break;
	}
}