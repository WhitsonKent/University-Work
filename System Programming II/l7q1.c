#include <unistd.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main(int argc, char* argv[]) {
	int sig = SIGALRM;
	printf("SIGNAL: %d %s\n", sig,strsignal(sig));
	sig = SIGUSR1;
	printf("SIGNAL: %d %s\n", sig, strsignal(sig));
	sig = SIGSTOP;
	printf("SIGNAL: %d %s\n", sig, strsignal(sig));
}