#include<stdio.h>

int pow(int a,int b);

int pow(int a,int b)
{
int i,j;
int ans=a;
int inc=a;

for(i=1;i<b;i++)
	{
	for(j=1;j<a;j++)
		{
			ans=ans+inc;		
		}
		inc=ans;
	}

return ans;
}


int main()
{
int i,j;

printf("%d\n",pow(5,3));

return 0;
}
