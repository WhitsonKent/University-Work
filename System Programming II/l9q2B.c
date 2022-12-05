#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h> 

#define MSGSIZE 63
char* fifo = "fifo";

void sigpipe() {
	signal(SIGPIPE, sigpipe);
	printf("Sigpipe handled\n");
	fflush(stdout);
}
void child(int p);
void parent(int p, pid_t);

int main(int argc, char* argv[]) {
	int fd;
	signal(SIGPIPE, sigpipe);
	mkfifo(fifo,0777);
	int pid = fork();
	char msg[] = "this is a msg\n";
	char buffer;
	if (pid == 0) {
		fd = open(fifo, O_WRONLY, 0777);
		write(fd, msg, 14);
		printf("msg written\n");
		sleep(3);
		write(fd, msg, 14);// now that read is closed this should generate a SIGPIPE
		close(fd);
		exit(0);
	}
	sleep(1);
	fd = open(fifo, O_RDONLY, 0777);
	for (int i = 0; i < 14; i++) {
		read(fd, &buffer, 1);
		printf("%c", buffer);
	}
	close(fd);
	printf("READ closed\n");
	sleep(3);
}