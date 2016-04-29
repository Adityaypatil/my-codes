#include<stdio.h>
#include<stdlib.h>
#define size 10


int queue[size],front,rear;


void init()
{
  front=0;
  rear=-1;
}



int isFull()
{
  if(rear==(size-1))
    return 1;
  else
    return 0;

}

int isEmpty()
{
  if(rear==-1)
    return 1;
  else
    return 0;
} 


void enqueue(int data)
{
  rear=rear+1;
  queue[rear]=data;

  return ;
} 



void display()
{
  int i;
  for(i=front;i<=rear;i++)
    {
      printf("%d\t",queue[i]);
    }
  printf("\n");
}






int main()
{
  init();

  enqueue(10);
  enqueue(20);
  enqueue(30);


  display(queue);

  return 0;
}
