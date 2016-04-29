#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int convert_to_html(FILE *fp,FILE *fp1)
{
	char *start_string="<html>\n<body>\n<tr>\n<td>";
	fprintf(fp1,start_string);
	size_t size=50;
	char *buffer=malloc(size * 1);
	int mem;
	while(mem=getline(&buffer,&size,fp1))
	{	
		if(mem==-1)
			return 0;
		else
		{
			printf("Inside while\n");
			printf("%s\n",buffer);
			fprintf(fp1,buffer);
		}
	}	
}

int main(int argc, char *argv[])
{
	FILE *fp,*fp1;
	fp=fopen(argv[1],"r+");
	fp1=fopen(argv[2],"w+");	
	
	convert_to_html(fp,fp1);	
	return 0;
}	
