#include<stdio.h>
#include<conio.h>
#include<math.h>

int eval(int [],int,int);

void main()
{
int a[10],n,x,i,e;

printf(“\n\nENTER THE DEGREE OF POLYNOMIAL\n\n”);
scanf(“%d”,&n);

printf(“\n\nENTER THE CO-EFFICIENT OF POLYNOMIAL\n\n”);
	for(i=n;i>=0;i–)
	{
		printf(“\n\nCO-EFFICIENT OF A[%d]:-\t “,i);
		scanf(“%d”,&a[i]);
	}

printf(“\n\nENTERED POLYNOMAIL IS \n\n”);

	for(i=n;i>0;i–)
	{
		if(a[i]!=0)
		{
			printf(“%dX^%d+”,a[i],i);
		}
	}

printf(“%d”,a[i]);
printf(“\n\nENTER THE VALUE FOR X”);
scanf(“%d”,&x);

e=eval(a,n,x);

printf(“\nEvaluation of Poly is \t %d”,e);

}

int eval(int a[],int n,int x)
{
int sum=0,i;

for(i=n;i>=0;i–)
	{
	sum=sum+a[i]*pow(x,i);
	}
return sum;

}
