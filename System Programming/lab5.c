#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>

static int process=0;
int main(int argc,char *argv[]){
int i, input, inputs[7];
        for(i=0;i<7;i++)
        {
                input=strtol(argv[i+1], NULL,10);
                inputs[i]=input;
        }
        for(int i=0;i<7;i++) // loop will run n times (n=5)
        {
          process++;
            if(fork() == 0)//creates I processes
            {
              sleep(inputs[i]);
                printf("process %d pid %d\n",process, getpid());
                exit(0);
            }
            else exit(0);
        } // loop will run n times (n=5)
}
