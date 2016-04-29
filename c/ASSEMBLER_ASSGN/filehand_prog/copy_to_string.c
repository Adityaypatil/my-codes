#include<stdio.h>

void main()
{
FILE *fp;
char  ch,src[300],s1,s2,s3,s4;
int i=0;
fp=fopen("add.asm","r");

while(1)
{
	ch=fgetc(fp);
	
	if(ch == EOF)
	{
		src[i]='\0';
			break;
	}
	if (ch == " ")
		src[i] = ch;
		i++;
		}		
	else
		break;
	//printf("%c",ch);
}
printf("%s\n",src);
fclose(fp);
}
	
