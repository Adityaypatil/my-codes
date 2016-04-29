#include<stdio.h>

int rec_bin(int arr[],int low,int heigh,int data)
{
  int mid=low+(heigh-low)/2;
  if(arr[mid]==data)
    return mid;
  else if(arr[mid] < data)
    return rec_bin(arr,low,mid+1,data);
  else return rec_bin(arr,mid-1,heigh,data);
  return -1;
}


int main()
{
  int arr[]={1,2,3,4,5,6};
  int size = sizeof(arr)/sizeof(arr[0]);
  int data=6;
  int low=0;
  int heigh=size-1;
  printf("==>%d",rec_bin(arr,low,heigh,data));
  return 0;
}
