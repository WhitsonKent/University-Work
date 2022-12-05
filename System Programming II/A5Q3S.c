#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>

// This is the server
int main(int argc, char *argv[]){
	int fd,fd2;
	char ch;

	unlink("../myserver"); // delete it if it exists

	if(mkfifo("../myserver", 0777)!=0)
		exit(1);

	unlink("../myclient"); // delete it if it exists

	if(mkfifo("../myclient", 0777)!=0)
		exit(1);

	while(1){
		fd = open("../myserver", O_RDONLY);
		fd2 = open("../myclient", O_WRONLY);


		while(read(fd, &ch, 1) == 1){
			fprintf(stderr, "%c", ch);
			ch = toupper(ch);
			write(fd2,&ch,1);
		}
	}
}
