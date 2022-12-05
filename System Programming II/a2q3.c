#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char equation[20];
char buffer[20];
int exitstatus,status,pid;

int childFuntion(char *line){
  printf("Im A Child working for my parent\n");
  char statement[sizeof(line)];
  strcpy(statement,line);
  int ans;
  int status;
  int n1,n2;
  char op;
  status = sscanf(statement,"%d %c %d",&n1,&op,&n2);
  if(status==EOF){
    printf("ERROR: Wrong statement\n");
    exit(50);
  }
  if(op=='/'&& n2 == 0 ){
    printf("ERROR: Division by 0\n");
    exit(100);
  }
  switch(op)
  {
    case '+':
    ans = n1+n2;
    break;
    case '-':
    ans = n1-n2;
    break;
    case '*':
    ans = n1*n2;
    break;
    case '/':
    ans = n1/n2;
    break;
    default:
    printf("ERROR: Wrong operator\n");
    exit(200);
    break;
  }
  sprintf(buffer,"%d %c %d = %d",n1,op,n2,ans);
  printf("%s\n",buffer);
  printf("Sucessful case\n");
  exit(0);
}

int main(int argc, char const *argv[]) {
  int exit;
  for(;;){
  printf("Enter a simple arithmetic statement (n1 op n2)\nop can be +,-,* or /\n");
  gets(equation);
  pid=fork();
  if(pid==0){
    status=childFuntion(equation);
  }
  else{
    printf("Waiting for Child\n");
    wait(NULL);
  }
  if (WIFEXITED(status))
  {
	  exitstatus = WEXITSTATUS(status);
	  printf("Exit status from %d was %d\n", pid, exitstatus);
  }
  pid=1;
}
}
