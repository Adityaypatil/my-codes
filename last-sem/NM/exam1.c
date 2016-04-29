

#include<math.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
int a[10][10],i,j,no;
float delta;
printf("Enter elements of matrix A:");

for(i=0;i<49;i++)
		{
			scanf("%d",&a[i]);
		}
	
delta = ((13143 % 7)+1);

printf ("\n%f",delta);

printf("\n Value of matrix A after modification=>\n ");

for (j=0;j<49;j++)
	{
	  a[j] = ((7 * a[j] + 13 ) % 31) + delta;
	}	

 for(i=0;i<49;i++)
   {
   printf(" \n%d",a[i]);
   }
}
