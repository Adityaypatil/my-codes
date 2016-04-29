#include<stdio.h>


void bubblesort(int array[],int size)
{
  int i,j,temp;

  for(i=0;i<size;i++)
    {
      for(j=i+1;j<size;j++)
	{
	  if(array[i]>array[j+1] )
	    {
	      temp=array[j+1];
	      array[j+1]=array[i];
	      array[i]=temp;
	    }
	}
    }
  for(i=0;i<size;i++)
    {
      printf("%d ",array[i]);
    }


  }

int main()
{

  int array[10]={5,3,10,4,9};
  //  size=(sizeof(array)/sizeof(array[0]);
  int size=5;

  bubblesort(array,size);

  return 0;
}
