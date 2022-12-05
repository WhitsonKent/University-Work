
/*
Kent Whitson 104797895

Study the SIGFPE signal.

Write a simple program to demonstrate generating the SIGFPE signal (divide by zero for example).
Your program should catch the signal and display a message.

If your signal handler simply displays a message but do not terminate the program, what would happen? 
Investigate your observation (google online) and provide a brief answer to what you observed.

answer: if you don't tell the program to exit upon catching the signal it ends up in
an infinite loop and keeps displaying messages that it caught the signal*/
#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <string.h>

void sig_handler();

int main(int argc, char* argv[]) {
	signal(SIGFPE, sig_handler);//enables catching of SIGFPE
	int n = 2 / 0;
}

void sig_handler() {
	signal(SIGFPE, sig_handler);
	printf("SIGFPE generated\n");
	exit(1);
}
