#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h> 

void sigpipe() {
	signal(SIGPIPE, sigpipe);
	printf("Sigpipe handled\n");
	fflush(stdout);
}
void child(int p);
void parent(int p, pid_t);

int main(int argc, char* argv[]) {
	//A
	signal(SIGPIPE, sigpipe);
	int p[2];
	pipe(p);
	close(p[0]);
	write(p[1], "words\n", 5);//sigpipe generated because it tries to write when the read end of hte pipe has been closed
	//B
}