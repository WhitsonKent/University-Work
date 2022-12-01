#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]){  int fd1, fd2;
char buffer[1];  long int n1; int ch;

if(((fd1 = open(argv[1], O_RDONLY)) == -1)){
perror("file problem ");  exit(1);
}
while (n1=read(fd1, buffer, 1)){
write(STDOUT_FILENO ,buffer,1);
}
close(fd1);
}
