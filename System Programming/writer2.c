#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open("list2.txt", O_WRONLY | O_CREAT,0755);
  char a[]="GM\t101\tBuick\t2010\nFord\t102\tLincoln\t2005\n";
  write(fd, a, 44);
  close(fd);
}
