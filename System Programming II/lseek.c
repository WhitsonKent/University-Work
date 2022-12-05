#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char*argv[])
{
  char buffer[2];
  int fd;
  int n1;
  int begin;
  int size =0;
  fd = open(argv[1],O_RDONLY);
  size=lseek(fd,0,SEEK_END);
  printf("%d\n",size);
  begin = lseek(fd,-size,SEEK_CUR);
  while((n1 = read(fd,buffer,2))&& n1 != EOF){
    write(STDOUT_FILENO,buffer,2);
  }
  close(fd);
}
