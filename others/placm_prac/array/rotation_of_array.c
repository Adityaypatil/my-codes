#include<stdio.h>

void leftpos(int *a,int n);
void leftrotate(int *,int d,int n);
void printarr(int *,int n);

void leftpos(int *a,int n)
{
	int temp,i;
	temp=a[0];
	for(i=0;i<n-1;i++)
		{
		a[i]=a[i+1];	
		}	
	a[i]=temp;
		
}
void leftrotate(int *a,int d ,int n)
{
        int i;
        for(i=0;i<d;i++)
                leftpos(a,n);
}

void printarr(int *a,int n)
{
	int i;
	for(i=0;i< n;i++)
		printf("%d ",a[i]);
	
}

int main()
{
	int a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	int d=2;
	leftrotate(a,d,n);
	printarr(a,n);
	return 0;
}
