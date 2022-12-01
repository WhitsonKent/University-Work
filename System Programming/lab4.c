#include <unistd.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
  int num;
  int f = fork();
    if(f == 0){
        sleep(5);
        childFunction();
    }
    else{
        printf("Enter an intger between 1 and 15: ");
        scanf("%d", &num);
        if(num < 1 || num > 15){
            printf("ERROR");
            exit(1);
        }
        int fp = open("data.txt", O_RDWR | O_CREAT, 0755);
        write(fp, &num, 2);
    }
}

void childFunction(){
    int tmp;
    int fp = open("data.txt", O_RDONLY);
    read(fp, &tmp, sizeof(tmp));
    if(isPrime(tmp)){
        printf("Prime Number");
    }
    else{
        printf("Not Prime");
    }
}
int isPrime(int n) {
    int i;
    if (n <= 1){
        return 0;
    }
    for (i=2; i*i <= n; i++) {
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}
