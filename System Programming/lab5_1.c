#include <unistd.h> //needed for read(..)
#include <stdio.h> //needed for stdin

int main(int argc, char const *argv[]) {
  char buf[210];
  sleep(4);
  read(stdin, buf, 200);
  printf("%s\n",buf);
  return 0;
}
