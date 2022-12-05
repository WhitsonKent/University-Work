#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
int main(){
	int i = 1;
	int pid = fork();//fork childprocess
	if (pid == 0) {
		while (1) {
			sleep(1);
			printf("COUNTING: %d\n", i);
			i++;
		}
	}
	else {
		sleep(3);//wait 3 seconds before stopping
		kill(pid, SIGSTOP);
		sleep(3);//wait 3 seconds then continue
		kill(pid, SIGCONT);
		sleep(3);//wait 3 seconds then terminate child
		kill(pid, SIGINT);
	}
}