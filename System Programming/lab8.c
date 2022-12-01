#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>


int main(int argc, char const *argv[]) {

    int fd[2];
    if (pipe(fd) == -1)
		exit(1);

    if ( fork()==0)
    {
            close(fd[0]);
            dup2(fd[1],STDOUT_FILENO);
            close(fd[1]);
            execlp(argv[1],argv[1],NULL);

    }
    else
    {
        char buffer[800];
        close(fd[1]);
        read(fd[0],&buffer,sizeof(buffer));
        int eof=0;

        while(1)
        {
            if(buffer[eof++]=='\0') break;
        }
        //Write to file
        int fp= open("results.txt",O_WRONLY|O_CREAT,0755);
        write (fp,buffer,eof);
    }


    return 0;
}
