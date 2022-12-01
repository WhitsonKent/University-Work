#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open("list1.txt", O_WRONLY | O_CREAT,0755);
  char a[]="101   GM\tBuick\t2010\n102   Ford\tLincoln\t2005\n";
  write(fd, a, 44);
  close(fd);
}
