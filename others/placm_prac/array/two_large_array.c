#include<malloc.h>

void two_large(int *a,int n)
{
	int i,temp;
	int l1=a[0];
	int l2=a[1];
	if (l1 < l2)	
		{
		temp=l1;
		l1=l2;
		l2=temp;
		}
	for(i=2;i<n;i++)
	{
		if(a[i]>=l1 )
		{
			l2=l1;
			l1=a[i];
		}
		else if(a[i] >l2 )
		{
			l2=a[i];
		}
	}
	printf("%d and %d is first and second largest number of list.\n",l1,l2);
}	

int main()
{
	int a[]={1,9,3,4,5,6,8};
	int n=sizeof(a)/sizeof(a[0]);
	two_large(a,n);
	return 0;
}
