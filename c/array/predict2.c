#include<stdio.h>

void main()
{
int array[10],i;

for(i=0;i<=10;i++)
{
	array[i]='A'+i;
	printf("\n%d %c",array[i],array[i]);
}
}
