#include<malloc.h>

int bubble(int *arr,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
				{
					if(arr[i] >arr[j])
					{
						temp=arr[j];
						arr[j]=arr[i];
						arr[i]=temp;
						
					}	
				}
		}
	for(i=0;i<n;i++)
		{
		printf("%d-",arr[i]);0
		}
}
int main()
{
	int arr[]={3,51,6,7,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubble(arr,n);
	return 0;
}
