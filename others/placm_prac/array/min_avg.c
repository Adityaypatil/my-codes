#include<stdio.h>

void avg(int *a,int k,int n)
{
	int curr_sum=0,min_sum=0,index=0;

	if (n < k)
		return;
	
	int i;
	for(i=0;i<k;i++)
		curr_sum+=a[i];

	min_sum= curr_sum;
	for(i=k; i<n; i++)
	{
		curr_sum+=a[i]-a[i-k];
		
		if(curr_sum < min_sum)
			{	
				curr_sum=min_sum;
				index=(i-k+1);
			}
	}

printf("Ans is : %d to %d\n",index,index +k-1);
	
}


int main()
{
	int a[]={3, 7, 90, 20, 10, 50, 40};
	int k=3;
	int n=(sizeof(a)/sizeof(a[0]));
	avg(a,k,n);
	return 0;
}
