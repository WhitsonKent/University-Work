

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

// This is the server
int main(int argc, char *argv[]){
	int fd,fd2;
	char ch;
	char msg[]="Message Received\n";

	unlink("../myserver"); // delete it if it exists

	if(mkfifo("../myserver", 0777)!=0)
		exit(1);

	unlink("../myclient"); // delete it if it exists

	if(mkfifo("../myclient", 0777)!=0)
		exit(1);

	while(1){
		fprintf(stderr, "Waiting for a client\n");

		fd = open("../myserver", O_RDONLY);
		fd2 = open("../myclient", O_WRONLY);

		fprintf(stderr, "Got a client: ");

		while(read(fd, &ch, 1) == 1){
			fprintf(stderr, "%c", ch);
			if(ch=='\n'){write(fd2,msg,sizeof(msg));}
	}
}
}
