#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct employee {

  char firstname[40];
  char lastname[40]; int id;
 }; typedef struct employee Employee;


/* Input the employee data interactively from the keyboard */
void InputEmployeeRecord(Employee *ptrEmp);

/* Display the contents of a given Employee record*/
void PrintEmployeeRecord(const Employee e);

/* Save the contents of the employee record list to the newly created text file specified by FileName */
void SaveEmployeeRecord(const Employee e[], const char *FileName);

void main() {

Employee e[3]; // TODO: modify to input and save an array of 3 employee records
for (int i =0;i<3;i++)
  {
    InputEmployeeRecord(&e[i]);
  }
  for (int i =0;i<3;i++)
    {
      PrintEmployeeRecord(e[i]);
    }
  SaveEmployeeRecord(e, "employee.dat");
}

void InputEmployeeRecord(Employee *ptrEmp)
/*Takes the name of an Employee
INPUT:Enter an employee info
OUTPUT:Info is saved to employee*/
{
  int idNum;
  char fName[40],lName[40];
  printf("Enter: FirstName LastName ID\n");
  scanf("%s %s %d",&fName,&lName,&idNum);//takes name and ID
  strcpy(ptrEmp->firstname,fName);//copies firstname
  strcpy(ptrEmp->lastname,lName);//copies lastname
  ptrEmp->id=idNum;
}

void PrintEmployeeRecord(const Employee e)
/*Prints an employees Info
INPUT:Employee
OUTPUT: Employee Info*/
{
  printf("%d %s %s\n",e.id,e.firstname,e.lastname);
}

void SaveEmployeeRecord(const Employee e[], const char *FileName)
{
	FILE *fp;
	fp = fopen(FileName, "w");
  for (int i =0;i<3;i++)
    {
      fprintf(fp, "%d %s %s\n",e[i].id,e[i].firstname,e[i].lastname);
    }
  fclose(fp);
}
