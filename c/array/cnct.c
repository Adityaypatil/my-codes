#include<stdio.h>
#include<string.h>


void fun(char  src,char  dest)
{
int i=0,j=0;
//src = src + strlen(src);
for(i=0;i<strlen(dest);i++)
{
	src[j] = dest[i];
	//i++;
	j++;

}	
	src[j] !='\0';

printf("%s",src[j]);

}

void main()
{

char src[20],dest[20];

printf("Enter the two strings:");
scanf("%s%s",src,dest);
fun(src,dest);
return 0;
}
