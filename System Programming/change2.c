#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int a =101;
  int fd = open("list2.txt", O_RDWR,0755);
  lseek(fd,3,SEEK_SET);
  write(fd,&a,4);
  close(fd);
}
