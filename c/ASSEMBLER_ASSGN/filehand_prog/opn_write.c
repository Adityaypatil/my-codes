#include<stdio.h>

void main()
{

FILE *fp;
char chr, name[10];
int age;
int count_lines=0;
fp=fopen("STUDENT_INFO.txt","w");

if(fp == NULL)
	{
	printf("File does not exist");
	return ;
	}
printf("Enter the name");
scanf("%s",name);

fprintf(fp,"Name :%s\n",name);

printf("Enter the age");
scanf("%d",&age);

fprintf(fp,"Age is: %d\n",age);
 
chr = getc(fp);
    while (chr != EOF)
    {
        if (chr == 'n')
        {
            count_lines = count_lines + 1;
        }
        
        chr = getc(fp);
    }

    printf("There are %d lines\n", count_lines);

fclose(fp);
}
