#include<stdio.h>

void main()
{
FILE *fs,*ft;
int count=0,i,cnt;
char chr,src[120];
fs=fopen("abc.txt","r");

ft=fopen("abc1.txt","w");
chr=fgetc(fs);
while(1)
{	
	if(chr == EOF)
	break;
	
	else
		fputc(chr,ft);

			
chr=fgetc(fs);
}
fclose(fs);
fclose(ft);
}
