#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define FILENAME "employee.dat"

struct employee {

  char firstname[40];
  char lastname[40]; int id;
 }; typedef struct employee Employee;

 char WordCap(char *c);

 void main()
 {
   int c;
   Employee EmployeeList[3];
   FILE *fp;
   fp = fopen(FILENAME, "r");
   //capialises last name and first name in employee list
   for (int i=0;i<3;i++)
   {
     char *fPtr;
     fPtr=&EmployeeList[i].firstname[0];
     char *lPtr;
     lPtr=&EmployeeList[i].lastname[0];
     fscanf(fp,"%d\n",&EmployeeList[i].id);
     fscanf(fp,"%s\n",&EmployeeList[i].firstname);
     fscanf(fp,"%s\n",&EmployeeList[i].lastname);
     EmployeeList[i].firstname[0]=WordCap(fPtr);
     EmployeeList[i].lastname[0]=WordCap(lPtr);
   }
   fclose(fp);
   fp = fopen(FILENAME, "w");
   //puts new data into employee.dat
   for (int i=0;i<3;i++)
   {
      fprintf(fp,"%d ",EmployeeList[i].id);
      fprintf(fp, "%s ",EmployeeList[i].firstname);
      fprintf(fp, "%s\n",EmployeeList[i].lastname);
   }
   fclose(fp);
 }

 char WordCap(char *c)
 /*capitalises words
 INPUT:char
 OUTPUT:capitalised char*/
 {
   int cap=*c;
   cap=toupper(cap);
   return cap;
 }
