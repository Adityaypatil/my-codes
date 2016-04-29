#include<stdio.h>
#include<string.h>

void main()
{
int i,sum=0,len;
char str[20];

printf("Enter the string is :");
scanf("%s",str);
len=strlen(str);
for(i=0;i<len-1;i++)
	{
	if(str[i]>='0' && str[i]<='9')
	sum=sum+str[i]-'0';
	}
printf("addision is:%d\n",sum);
}
