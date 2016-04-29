#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE];
int top=-1;

int isEmpty()
{
  if(top==-1)
    return 1;
  else 
    return 0;
}



int isFull()
{
  if(top==SIZE-1)
    return 1;
  else
    return 0;
}



void push(int no)
{
  if(!isFull())
    {
      stack[++top]=no;       

     }
  else
    {
      printf("stack is full\n");
    }
}




int pop()
{
  if(!isEmpty())
    {
      return stack[top--];

	 }
  else
    { printf("No element to be deleted:\n");
      return;
     }

}

void display()
{
  int i;

  if(!isEmpty())
    {
        for(i =top ; i>=0; i--)
     {
       printf("%d ",stack[i]);
     }  
    printf("\n");
    }
  else
    printf("no elements in stack to be displayed");
}






int main()
{
  push(10);
  push(30);
  push(50);

  display();

  push(60);

  printf("deleted elemt is =%d \n",pop());

  display();

  return 0;
}
