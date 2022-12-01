#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
void stdinread(int fd);
int int main(int argc, char const *argv[]) {
  int fd1,fd2;
  pid_t pid;
  char ch;
  char blanks[55]=" | ";
  int writeblanks = 1;

  printf("\nClient has connected\n");
  fd1=open("./fifo1",O_WRONLY);
  fd1=open("./fifo2",O_RDONLY);
  printf("\n my messages (client) receieved messages (server )\n", );
  printf("-------------------------------------------------------------------------------\n");
  if((pid = fork())==-1){
    perror("fork");
    exit(1);
  }
  if (pid == 0)
  while(1){
    read(STDIN_FILENO,&ch,1);
    if (write(fd1,&ch,1)==-1)
    exit(0);
  }
  while (read(fd2,&ch,1)==1){
    if(writeblanks==1)
    write(1,blanks,sizeof(blanks));
    write(1,&ch,1);
    if (ch=='\n')
    writeblanks=1;
    else
    writeblanks=0;
  }
  close(fd1);
  close(fd2);
  printf("\nDisconnected.\n\n\n");
  kill(pid, SIGTERM);
}
