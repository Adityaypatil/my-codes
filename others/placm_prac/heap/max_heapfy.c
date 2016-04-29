#include<malloc.h>

void mex_heapfy(int *a,int i,int n)
{
	int j,temp;
	temp=a[i];
	j=2*i;
	
	while(j<=n)
	{
		if(j<n && a[j+1]>a[j])	
			j=j+1;
		
		
		if(temp >a[j])
			break;
	
		else if(temp <= a[j])
		{
			a[j/2]=a[i];
			j=2*i;	
		}
	}
	a[j]=temp;	
//	return;
}

void build_maxheap(int *a,int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		mex_heapfy(a,i,n);
	}
	
}
int main()
{
	int a[]={9,6,5,0,8,2,7,1},i;
	int n=sizeof(a)/sizeof(a[0]);
	build_maxheap(a,n);
	printf("Ans :\n");
	for(i=0;i<n;i++)
	{
	printf("%d ",a[i]);
	}
	return 0;
}
