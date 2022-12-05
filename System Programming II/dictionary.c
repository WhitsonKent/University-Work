#include "dict.h"
#include <string.h>
#include <stdio.h>

int writedict(const char *dictname, struct dict_elem *elist){

	int j;
	FILE *outf;

	if ((outf = fopen(dictname, "w")) == NULL){
		return ERROR;
	}

	for (j = 0; elist[j].d_length != 0; j++);

	if (fwrite((void*)elist, sizeof(struct dict_elem), j, outf)){
		fclose(outf);
		return ERROR;
	}


	fclose(outf);
	return SUCCESS;
}

//**************************************************************************


struct dict_elem * readdict(const char *dictname,
  				     struct dict_elem *inlist, int maxlength)
{

	int i;
	FILE *inf;

	if ((inf = fopen(dictname, "r")) == NULL){
		return NULL;
	}

	for (i = 0; i < maxlength - 1; i++)
	{
		if (fread((void*)&inlist, sizeof(struct dict_elem), i, inf)<1)
		{
			break;
		}
	}


	fclose(inf);

	inlist[i].d_length = 0;

	return inlist;
}


// your main function goes here.
int main(void)
{
	struct dict_elem dict[2];
	dict[0].d_length=3
	strcpy(dict[0].d_name,"Dog");
	strcpy(dict[1].d_name,"Cat");
	writedict("dictionary.txt",dict);
}
