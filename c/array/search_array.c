#include<stdio.h>

void main()
{
int i,n,a[20],num,count;

printf("Total count of list:");
scanf("%d",&n);

printf("Enter list:");

for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}

printf("Enter number to be search:");
scanf("%d",&num);

for(i=0;i<n;i++)
	{
		while(a[i]!= num)
		{

		count++;

		}
	}

printf("Index is:%d",count);

}

