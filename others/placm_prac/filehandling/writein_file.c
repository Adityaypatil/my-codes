#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fp;
char data[20]= "Aditya Patil";

int len=strlen(data);
int counter;


fp=fopen("sample2.txt","a");

if(fp == NULL)
{
	printf("Enable creat to file !");
}
else

	{
	
	for(counter=0;counter < len;counter++)
	{
		fputc(data[counter],fp);
	}


		printf("File open succesfully!");
		fclose(fp);
	}	



return 0;
}
