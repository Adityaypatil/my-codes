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

printf("Last five character are ===> ");
fseek(fp,-20,SEEK_END);

/*if(fseek(fp,-5,SEEK_END) == -1)
{
printf("No enough charcters");
exit(-1);
}*/


while((ch=fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	
	}
	printf("\n");
fclose(fp);		

}





