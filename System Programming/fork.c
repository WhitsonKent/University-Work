/*#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  int a =2;
  int b =4;
 fork();
 fork();
 fork();
 printf("%d\n", getpid());
}*/
/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
 if (fork() == 0)
 fork();
 else {
 fork();
 fork();
 printf("%d\n", getpid());
 }
}*/
/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
 if (fork() == 0)
 fork();
 else {
 fork();
 fork();
 }
 printf("%d\n", getpid());
}*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
 if (fork() == 0){
 printf("Process B\n");
 fork();}
 else {
   printf("Process A\n");
 fork();
 fork();
 exit(0);
 }
 printf("%d\n", getpid());
}
