//kent whitson 104797895
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int fd1, fd2, fd3,fd4, pid;
	char ch;

	unlink("..fifo1"); // delete it if it exists

	if (mkfifo("../fifo1", 0777) != 0)
		exit(1);

	unlink("../fifo2"); // delete it if it exists

	if (mkfifo("../fifo2", 0777) != 0)
		exit(1);

	pid = fork();
	if (pid == 0) {//child
		if (pid == 0) {//grandchild
			printf("process 3 go\n");
			system("touch FEtmp4.txt");

			system("touch results.txt");
			fd1 = open("../fifo2", O_RDONLY);
			fd2 = open("FEtmp4.txt", O_WRONLY);
			while (read(fd1, &ch, 1) == 1) {
				write(fd2, &ch, 1);
			}
			close(fd1);
			close(fd2);
			strcat(argv[3], " FEtmp4.txt");
			system(argv[3]);
			system("rm FEtmp4.txt");
			exit(1);
		}
		printf("process 2 go\n");
		system("touch FEtmp2.txt");
		system("touch FEtmp3.txt");
		fd1 = open("../fifo1", O_RDONLY);
		fd2 = open("FEtmp2.txt", O_WRONLY);
		while (read(fd1, &ch, 1) == 1) {
			write(fd2, &ch, 1);
		}
		close(fd2);
		close(fd1);
		//fd2 = open("../fifo2", O_WRONLY);S
		strcat(argv[2], " FEtmp2.txt > FEtmp3.txt");
		system(argv[2]);

		fd3 = open("FEtmp3.txt", O_RDONLY);
		fd4 = open("../fifo2", O_WRONLY);
		while (read(fd3, &ch, 1) == 1) {
			write(fd4, &ch, 1);
		}

		close(fd3);
		close(fd4);
		system("rm FEtmp2.txt");
		system("rm FEtmp3.txt");
		pid = fork();
		exit(1);
	}
	else {//parent
		printf("process 1 go\n");
		system("touch FEtmp.txt");
		fd2 = open("../fifo1", O_WRONLY);
		strcat(argv[1], " > FEtmp.txt");
		system(argv[1]);
		fd1 = open("FEtmp.txt", O_RDONLY);
		while (read(fd1, &ch, 1) == 1) {
			write(fd2, &ch, 1);
		}
		close(fd1);
		close(fd2);
		system("rm FEtmp.txt");
		exit(1);
	}
}