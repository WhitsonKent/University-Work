//Written by KENT WHITSON 104797895
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
  int status;
  FILE* fread = fopen ("storage.txt", "r");
  if(!fread){//if file doesn't exist it creates on then restarts
    status = system("touch storage.txt");
    status = system("echo 5 > storage.txt");
    status = system("cc consumer.c -o consumer");
    status = system("./consumer");
    exit(0);
  }
  int num = 0;
  fscanf (fread, "%d", &num);
  num=num-3;
  FILE* fwrite = fopen ("storage.txt", "w");
  fprintf(fwrite, "%d\n",num);
  fclose(fread);
  fclose(fwrite);
  printf("from consumer: Number written to file: %d\n",num );
  status = system("./producer");
}
