/* calculate sum of even and odd from 1 to n*/

#include<stdio.h>

void sum(int no);

int main()
{

  int num;

  printf("\nEnter n :");
  scanf("%d",&num);
  sum(num);
}

void sum(int num)
{
  int i,even=0,odd=0;
  for(i=0;i<=num;i++)
    {
      if(i%2==0)
	{
	  even=even+i;
	}
      else
	{
	  odd=odd+i;
	}
    }
  printf("\n Sum of even numbers is :%d",even);
  printf("\nSum of odd numbers is :%d",odd);
}



