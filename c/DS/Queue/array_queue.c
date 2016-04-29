#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;
#define SIZE 10
int queue[SIZE];
int rear=-1;
int front =-1;

BOOL iSEmpty()
{
  if(rear==-1 && front==0)
    {return TRUE;
      // printf("Queue is Empty\n");
    }
  else
    {return FALSE;
      //printf("queue has elements to be deleted");
    }
}



BOOL isFull()
{
  if(rear == SIZE-1)
    {
      return TRUE;
    }
  else
    return FALSE;
}




int EnQueue(int data)
{
  if(isFull()==TRUE)
    {
      return -1;
    }
  else
    { if(front==-1)
	{front=0;
        }
      rear=rear+1;
      queue[rear]=data;
    }
}
 
/*int Dqueue()
{
  if(isEmpty()==TRUE)
    {
      return -1;
    }
  else
    {
      return queue[++front]; 
    }
}
*/



void display()
{int i;
  

  for(i=front;i<=rear;i++)
    {
      printf("%d ",queue[i]);
    
    }

}


int main()
{
  EnQueue(10);
  EnQueue(20);
  EnQueue(30);
  EnQueue(40);
  
  display();   
	 

  return 0;
}
