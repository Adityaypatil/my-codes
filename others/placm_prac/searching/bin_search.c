#include<stdio.h>

int binary(int arr[],int size,int data)
{
  int i,j,mid=0;
  int low=0;
  int heigh=size-1;
  while(low<=heigh)
    {
  mid=low+(heigh-low)/2;
  if(arr[mid]==data)
    return mid;
  else if(arr[mid] < data)
    low=mid+1;
  else
    heigh=mid-1;

}
  return -1;
}



int main()
{
  int arr[]={1,2,3,4,5,6,7};
  int size = sizeof(arr)/sizeof(arr[0]);
  int data=6;
  printf("\nIndex :%d\n", binary(arr,size,data));

  return 0;
}
