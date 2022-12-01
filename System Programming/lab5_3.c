#include<stdio.h>
int duplicate(char *f1, char *f2) {
FILE *in, *out;
 unsigned char c;
if ( !(in = fopen(f1,"r")) || !(out = fopen(f2, "w"))){
return (-1);
}
while ((c=getc(in)) != EOF){
putc(c, out);
}
fclose(in);
fclose(out);
return (0);
}
int main(int argc, char * argv[]){
duplicate(argv[1], argv[2]);
}
