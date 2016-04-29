#include<stdio.h>
int main()
{
	int i,j,n=9;
	
	for(i=1;i<=4;i++)
		{
			for(j=1;j<=i;j++)
				{
						printf("*");
				}
					printf("\n");
		}
		
	for(i=4;i>=0;i--)
		{
			for(j=1;j<=i;j++,n--)
				{
					if(n==3||n==2||n==0)
					{
					
						printf("*");
					}	
					else
					{
						printf("%d",n);
						
					}
				}
					printf("\n");
		}
		return 0;
}
