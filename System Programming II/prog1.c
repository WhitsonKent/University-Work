#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
int main(void){
int i=0;
char line[100]="Hello, my name No-Name\n";
 while(line[i] != '\0'){
 putchar(line[i++]);
 sleep(1);
 }
}
//prog1.c
