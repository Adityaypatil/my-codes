#include<stdio.h>

void quicksort(int *arr,int left,int right)
{
if(left < right)
	{
	int p_index=partition(arr,left,right);
	quicksort(arr,left,p_index-1);
	quicksort(arr,p_index+1,right);
		}

}

int partition(int *arr,int left,int right)
{
int i,temp;
int pivot_item=arr[right];
int p_index=left;

	for(i=left;i<right;i++)
		{
			if(arr[i]<=pivot_item)
				{
				temp=arr[i];
				arr[i]=arr[p_index];
				arr[p_index]=temp;
				p_index++;
					}
		}

temp=arr[p_index];
arr[p_index]=arr[right];
arr[right] =temp;

return p_index;
}



int main()
{
int arr[]={13,2,10,5,15,6,17,11};
int i,size;

size=sizeof(arr)/sizeof(arr[0]);

quicksort(arr,0,size-1);
for(i=0;i<size;i++)
	printf("%d ",arr[i]);
	
return 0;
}
