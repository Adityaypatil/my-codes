#include<malloc.h>

void selection(int *arr,int n)
{
	int i,j,min=0,temp;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[min] > arr[j])
				min=j;						
		}
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
	
	for(i=0;i<n;i++)
	{
	printf("%d-",arr[i]);
	}

}


int main()
{
	int arr[]={3,1,5,3,7,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	selection(arr,n);
	return 0;
}
