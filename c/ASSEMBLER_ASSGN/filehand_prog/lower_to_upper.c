#include<stdio.h>

void main()
{

FILE *fp;
char ch;
fp=fopen("xyx.txt","r");

while (ch=fgetc(fp)!=EOF)
	putchar(toupper(ch));
//return 0;
}


