#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int a =101;
  int fd = open("list1.txt", O_RDWR,0755);
  lseek(fd,4,seek_set);
  write(fd,&a,4);
  close(fd);
}
