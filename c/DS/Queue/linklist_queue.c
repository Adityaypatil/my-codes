#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int Queue[SIZE];


struct node
{
  int data;
  struct node *next;
}*front=NULL,*rear=NULL;



int isEmpty()
{
  if(rear==NULL && front==NULL)
    return 1;
  else
    return 0; 
}


void  push(int no)
{
  struct node *temp;

 temp=(struct node *)malloc(sizeof(struct node));
 
 temp->data=no;
 temp->next=NULL;

 if(rear==NULL)
   rear=front=temp;

else
  {                                                                   
     rear->next=temp;                                                      rear=rear->next;                                                 
  }         

}



int pop()
{int data1;
  struct node *temp;

  temp=front;
  
  front=front->next;
  data1=temp->data;
  free(temp);
  temp->next=NULL;

  return data1;
}



void display()
{
  struct node *temp;
  
  for(temp=front;temp!=NULL;temp=temp->next)
    {
      printf("%d ",temp->data);
    }
  printf("\n");
}
  










int main()
{
  push(20);
  push(30);
  push(40);

  display();


  printf("Deleted element is=%d\n",pop());
  

  display();

  return 0;
}
