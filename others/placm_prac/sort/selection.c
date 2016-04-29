#include<stdio.h>

void selection(int array[],int size)
{
  int i,j,min,temp;

  for(i=0;i<size;i++)
    {
      min=i;
      for(j=i+1;j<size;j++)
	{
	  if(array[j] < array[min])
	    min=j;
	}
      temp=array[min];
      array[min]=array[i];
      array[i]=temp;

     }
  for(i=0;i<size;i++)
    {
      printf("%d- ",array[i]);
    }
}

int insertion(int array[],int size)
{
  int i,j,v;

  for(i=0;i<size;i++)
    {
      v=array[i];
      j=i;
      while(array[j-1]>v && j>=1)
	{
	array[j]=array[j-1];
	j--;
	}
      array[j]=v;

    }

  for(i=0;i<size;i++)
    {
      printf("%d ",array[i]);
    }

}


int main()
{
  int array[]={5,2,1,7,8};
  int size;
  size=sizeof(array)/sizeof(array[0]);
  printf("%d\n",size);
  //  selection(array,size);
  insertion(array,size);
}
