#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
FILE *fs,*fd;
char src[200],ch;
fs=fopen("abc.txt","r");

fd=fopen("xxxx.txt","w");
//fd=fopen("xyz.txt","w");
while(fgets(src,200,fs)!=NULL)
	
//	printf("%s",s);

putc(src,fd);


fclose(fs);
fclose(fd);
}
