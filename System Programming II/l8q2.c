#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void handle_sigint(int sig) {}

int main(int argc, char* argv[]) {
	int fd;
	int pid1, pid2;
	signal(SIGUSR1, handle_sigint);
	fd = open("text.txt", O_CREAT | O_WRONLY, 0755);
	char buf[3][20];

	strcpy(buf[0], "EXAM!EXAM!EXAM!\n");
	strcpy(buf[1], "HELP!HELP!HELP!\n");
	strcpy(buf[2], "STUDY!STUDY!STUDY!\n");
	printf("parent %d opened file\n", getpid(), argv[1]);
	if ((pid1 = fork()) == 0) {
		printf("parent created child %d\n", getpid());
		kill(getppid(), SIGUSR1);//Create process then pause
		pause();
		printf("WRITING STRING 1 TO FILE\n");
		write(fd, &buf[0], 16);
		printf("%d has written to file: %s\n", getpid(), buf[0]);
		sleep(5);
		kill(getppid(), SIGUSR1);//EXIT
		exit(0);
	}
	else {
		pause();
	}

	if ((pid2 = fork()) == 0) {
		printf("parent created child %d\n", getpid());
		kill(getppid(), SIGUSR1);//create process then pause
		pause();
		printf("WRITING STRING 2 TO FILE\n");
		write(fd, &buf[1], 16);
		printf("%d has written to file: %s\n", getpid(), buf[1]);
		sleep(5);
		kill(getppid(), SIGUSR1);//EXIT
		exit(0);
	}
	else {
		pause();
	}
	printf("\nProcess 1 resumed\n");
	kill(pid1, SIGUSR1);
	pause();
	printf("Process 2 resumed\n");
	kill(pid2, SIGUSR1);
	pause();
	printf("PARENT resumed\n");
	printf("WRITING STRING 3 TO FILE\n");
	write(fd, &buf[2], 19);
	printf("%d has written to file: %s\n", getpid(), buf[2]);
	sleep(5);
	close(fd);
	exit(0);

}