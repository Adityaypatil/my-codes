/* Check is it palindrome or not */\

#include<stdio.h>

void palindrome(int no);
int main()
{
  int num,temp;
  printf("\n Enter any number:");
  scanf("%d",&num);
  temp=num;
  palindrome(num);  
return 0;
}

void palindrome(int no)
{
  int temp=no,rev,rem;
  while(no!=0)
    {
      rem=no%10;
      rev=rev*10+rem;
      no=no/10;
    }

 if(temp == rev)
    {
   printf("\nGiven number is palindrome");
    }
  else
    {
    printf("\nNumber is not palindrome\n");
    }
}
