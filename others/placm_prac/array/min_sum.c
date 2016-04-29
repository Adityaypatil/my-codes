#include<stdio.h>

void minpair(int *a,int n)
{
	int sum,l,r,min_l=0,min_r=1,min_sum=a[0]+a[1];
	
	for(l=0;l<n-1;l++)
	{
		for(r=l+1;r<n;r++)
			{
				sum=a[l]+a[r];
				if(abs(min_sum)>abs(sum))
					{
						min_sum=sum;
						min_l=l;min_r=r;
			
					}
			}

	}
	printf("\n %d and %d are the two numbers\n",a[min_l],a[min_r]);

}
int main()
{
	int a[]={1, 60, -10, 70, -80, 85};
	minpair(a,6);
	return 0;
}
