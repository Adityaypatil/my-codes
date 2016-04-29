#include<stdio.h>
#include<stdlib.h>
#define SIZE 10


int arr[SIZE],top=-1,ele;




int isFull()
{
  if(top==SIZE-1)
    return 1;
  else
    return 0;
}


int isEmpty()
{
  if(top==-1)
    return 1;
  else
    return 0;
}



void push(int data)
{
  if(!isFull())
    {
      top++;
      arr[top]=data;
      return;
    }
  else
    {
      printf("Stack is Full\n");   
    }
}



int pop()
{
  if(!isEmpty())
    {
      ele=arr[top];
      top--;
      return ele;
    }
  else
    {
      printf("Stack is empty\n");
    }
}


void display()
{
  int i;
  for(i=top;i>=0;i--)
    {
      printf("%d\t",arr[i]);
    }
  printf("\n");
}





int main()
{
  push(10);
  push(20);
  push(30);
  push(40);

  display();

  printf("%d is popped elemt\n",pop());
}
