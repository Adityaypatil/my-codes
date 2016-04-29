#include<stdio.h>

int partition(int *arr,int low,int heigh)
{
  int i,left,right,pivot_index,pivot_item,temp;
  pivot_item=arr[heigh];
  pivot_index=low;
  left=low;right=heigh;

  for(i=low;i<heigh;i++)
    {
      if(arr[i]<=pivot_item)
	{
	  temp=arr[i];
	  arr[i]=arr[pivot_index];
	  arr[pivot_index]=temp;
	  pivot_index++;
	}

    }
  temp=arr[heigh];
  arr[heigh]=arr[pivot_index];
  arr[pivot_index]=temp;

  return pivot_index;
}

void quicksort(int *arr,int left ,int right)
{
  //  int pivot_item;
  if(left < right)
    {
     int  pivot_index=partition(arr,left,right);
      quicksort(arr,left,pivot_index-1);
      quicksort(arr,pivot_index+1,right);
      
    }
}

int main()
{
  int arr[]={5,2,1,6,4,3,9,11};
  int size,i;
  size=sizeof(arr)/sizeof(arr[0]);
  quicksort(arr,0,size-1);

  for(i=0;i<size;i++)
    printf("%d ",arr[i]);

  return 0;
}
