#include<stdio.h>

int avg(int *a,int n)
{	
	int i, avg=0,sum=0; 
	for(i=0;i<n;i++)
		sum=sum+a[i];
	
return sum/n;
}
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9};
	int n=sizeof(a)/sizeof(a[0]);
	printf("%d is average of arraylist.\n",avg(a,n));
	return 0;
}
