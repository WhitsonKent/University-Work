#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	int fd, fd2,pid;
	char ch;

	unlink("../myserver"); // delete it if it exists

	if (mkfifo("../myserver", 0777) != 0)
		exit(1);

	unlink("../myclient"); // delete it if it exists

	if (mkfifo("../myclient", 0777) != 0)
		exit(1);
	pid = fork();
	if (pid == 0) {
		while (1) {
			fd = open("../myserver", O_RDONLY);
			fd2 = open("../myclient", O_WRONLY);


			while (read(fd, &ch, 1) == 1) {
				ch = toupper(ch);
				write(fd2, &ch, 1);
			}
		}
		close(fd2);
		close(fd);
		exit(1);
	}
	else {
		while ((fd = open("../myserver", O_WRONLY)) == -1) {
			fprintf(stderr, "trying to connect\n");
			sleep(1);
		}

		printf("Connected: type in data to be sent\n");
		pid = fork();
		if (pid == 0) {
			fd2 = open("../myclient", O_RDONLY);
			while (read(fd2, &ch, 1) == 1) {
				fprintf(stderr, "%c", ch);
			}
			close(fd2);
			close(fd);
		}
		else {
			while ((ch = getchar()) != -1) // -1 is CTRL-D
				write(fd, &ch, 1);
			close(fd);
		}
		exit(1);
	}
	exit(1);
}
