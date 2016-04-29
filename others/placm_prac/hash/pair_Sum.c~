#include<stdio.h>
#include<stdbool.h>
#define max 1000

void printpair(int arr[],int size,int sum)
{
	int i,temp;
	bool boolmap[max]={0};

	for(i=0;i<size;i++)
	{
		temp=sum-arr[i];
		if(temp>= 0 && boolmap[temp]==1)
		{
			printf("Pair with given sum %d is (%d, %d) \n", sum, arr[i], temp);
		}
		boolmap[arr[i]]=1;
	}
}

int main()
{
	int A[]={1, 4, 45, 6, 10, 8};
	int n=6;
	int sum=16;
	printpair(A,n,sum);
	return 0;
}
