#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	FILE *f1=fopen(argv[1],"rw+");
  	FILE *f2=fopen(argv[2],"rw+");

  	fseek(f1,0,SEEK_END);
  	long fsize=ftell(f1);
 	fseek(f1,0,SEEK_SET);
	
  	char *buffer=malloc(fsize),*temp;
     fread(buffer,fsize,1,f1);
     fprintf(f2,"%s",buffer);

/*	fseek(f1,18,SEEK_SET); 
	fread(buffer,fsize,1,f1);
	
	char tag[]="<html>";
	char * table="<table>";
	char * end_table="</table>";
	char * row="<tr>";
     char *end_row ="</tr>";

 	fprintf(f2,"%s",tag);
	//temp=buffer;
	
	while(!feof(f1))
		{
		fprintf(f2,"%s",table);
		fprintf(f2,"%s",row);
		if (*buffer != '}')	
			buffer++;
		else
			fprintf(f2,"%s",end_table);
			
		if(*buffer != ';')
			buffer++;
		else
			fprintf(f2,"%s",end_row);			
		}
		
	fclose(f1);
	fclose(f2);
 */
 return 0;
}xxxxxxxxxxxxxx
