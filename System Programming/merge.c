#include <stdio.h>

extern unsigned char *
read_P6(register char *filename,
int *xdim,//for first image x co-ordinate
int *ydim,//for first image y co-ordinate
int *xdim1,//for second image x co-ordinate
int *ydim1,//for second image y co-ordinate
int *maxval);//to get image max value

extern int
write_P6(register char *filename,
register char *comment,
register int xdim,
register int ydim,
register int maxval,
register unsigned char *data);


main(register int argc,
register char **argv)
{
   /* Process command line... */
   if (argc != 3) {
       fprintf(stderr,
           "Usage: %s input_ppm output_ppm\n",
           argv[0]);
       exit(1);
   }

   /* Do the I/O */
   {
       register unsigned char * p;
       register unsigned char * p1;
       int xdim, ydim, maxval;

       /* Read the input */
       p = read_P6(argv[1],
           &xdim,
           &ydim,
           &maxval);
       p1=   read_P6(argv[2],
           &xdim,
           &ydim,
           &maxval);
       if (p == 0) {
           fprintf(stderr,
               "%s: could not read %s\n",
               argv[0],
               argv[1]);
           exit(2);
       }

       if (p1 == 0) {
           fprintf(stderr,
               "%s: could not read %s\n",
               argv[0],
               argv[1]);
           exit(2);
       }

       if(xdim<xdim1 || ydim<ydim1 ){
           fprintf(stderr,
               "Height or width of first image is less than the second \n");
           exit(2);
       }

       xdim1=xdim + 2;//giving it a space of 2 so that i will not be in contact with the first image


       /* Write the output */
       if (write_P6(argv[3],
           "just a test",
           xdim,
           ydim,
           maxval,
           p)) {
           fprintf(stderr,
               "%s: could not write %s\n",
               argv[0],
               argv[2]);
           exit(2);
       }

       if (write_P6(argv[3],
           "just a test",
           xdim1,
           ydim1,
           maxval,
           p)) {
           fprintf(stderr,
               "%s: could not write %s\n",
               argv[0],
               argv[2]);
           exit(2);
       }
   }

   /* All's well, let's end well */
   exit(0);
}
