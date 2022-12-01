#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int intA;
int main(void) {
int intB;
pid_t cpid;
intA = 0; intB = 2;
 cpid = fork();
 wait(NULL);
intA++; intB++;
if (cpid == 0) {
 intA++; intB++;
 printf("cpid==0: intA <%d>, intB <%d>\n", intA, intB);
}
else {
 intA--; intB--;
 printf("cpid!=0: intA <%d>, intB <%d>\n", intA, intB);
 }
}
