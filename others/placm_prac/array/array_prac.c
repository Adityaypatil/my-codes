#include<stdio.h>

int reverse(int *arr,int size)
{
	int i=0;

	for(i=size-1;i>=0;i--)
		printf("%d ",arr[i]);
}


int main()
{
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	reverse(arr,n);	
	return 0;
}
