


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	int fd,fd2;
	char ch;
	int pid;

	while((fd=open("../myserver", O_WRONLY))==-1){
		fprintf(stderr, "trying to connect\n");
		sleep(1);
	}

	printf("Connected: type in data to be sent\n");
	pid =fork();
	if(pid == 0){
		fd2=open("../myclient", O_RDONLY);
		while(read(fd2, &ch, 1) == 1){
			fprintf(stderr, "%c", ch);
		}
		close(fd2);
		close(fd);
	}
	else{
	while((ch=getchar()) != -1) // -1 is CTRL-D
		write(fd, &ch, 1);
	close(fd);
	}
}
