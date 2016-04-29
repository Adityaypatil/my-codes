#include<stdio.h>


int main()
{
	FILE *fp;int i=0;
	char ch;	
	char str[]="aditya patil";

	fp=fopen("abc.txt","w");

	if(fp==NULL)
		printf("Error");
	else
		while((str[i]!='\0'))
		{
			fputc(str[i++],fp);
		}
	fclose(fp);
	return 0;
	
}
