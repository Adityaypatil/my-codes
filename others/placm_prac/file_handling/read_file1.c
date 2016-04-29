#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>

int main()
{
	FILE *fp;int i=0;
	char ch;	
	char str[]="aditya patil";

	fp=open("abc1.txt",O_WRONLY);

	if(fp==NULL)
		printf("Error");
	else
		while((str[i]!='\0'))
		{
			write (fp,str[i++]);
		}
	fclose(fp);
	return 0;
	
}
