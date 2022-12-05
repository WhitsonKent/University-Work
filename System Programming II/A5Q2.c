#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc, char *argv[]){  
	int p[2];
	pid_t pid;  
	char ch;
	int size = 0;

	pipe(p);
	pid=fork();

	if (pid == 0) {//child
		int fd;
		close(p[0]);
		system("touch A5tmp.txt");
		strcat(argv[1], " > A5tmp.txt");
		system(argv[1]);
		fd = open("A5tmp.txt", O_RDONLY);
		while (read(fd, &ch, 1) == 1) {
			write(p[1], &ch, 1);
			size++;
		}
		close(fd);
		system("rm A5tmp.txt");
		close(p[1]);
		exit(0);
	}
	else {//parent
		FILE* fp;
		close(p[1]);
		fp = fopen("result.txt", "w+");
		while (read(p[0], &ch, 1) == 1) {
			fprintf(fp, "%c", ch);
			size++;
		}
		fclose(fp);
		close(p[0]);
		printf("the result of %s is written into result.txt size is %d bytes", argv[1],size);
		exit(0);
	}
}

