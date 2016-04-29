#include<stdio.h>
#include<string.h>


void main()
{
int i, n;
char src[20];

printf("Enter list:");
scanf("%s",src);

for(i=0;i<strlen(src);i++)
	{
	if(src[i]>=97&&src[i]<=122)
	src[i]=src[i]-32;
	else
	src[i]=src[i]+32;	

	}
printf("String is : %s\n",src);

}
	
