#include<stdio.h>
#include<string.h>

void even1(char);

void main()
{
char src[20];

printf("Enter the string:");
scanf("%s",src);
even1(src);
	
}

void even1(char src)
{
int i;
len=strlen(src);
for(i=2;i<len-1;i=i+2)
	{
	printf("%s",src);
	}

}
