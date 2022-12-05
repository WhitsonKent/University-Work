#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char*argv[])
{
  int fd;
  fd = open("list1.txt",O_WRONLY | O_CREAT | O_EXCL, 777);
  char line1[] = "101 GM\tBuick\t2010\n";
  char line2[] = "102 Ford\tLincoln\t2005\n";
  write(fd,line1,sizeof(line1));
  write(fd,line2,sizeof(line2));
  close(fd);
}
