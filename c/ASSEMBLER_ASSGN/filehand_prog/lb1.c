#include<stdio.h>
#include<stdlib.h>

void main()
{
char filename[20];

printf("Enter file name to be read:");
scanf("%s",filename);

print_fivechar(filename);

}

void print_fivechar(char *f)
{
FILE *fp;
char ch;
int no=0;

fp=fopen(f,"r");

printf("First five character are ===> ");

while(no!=5)
	{
		ch=fgetc(fp);
		if(ch ==EOF)
		{
			break;
		}
		printf("%c",ch);
		no++;
	}
	printf("\n");
fclose(fp);		
}





