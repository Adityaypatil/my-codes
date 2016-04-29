#include<stdio.h>
#include<stdlib.h>
#define SIZE 10


struct node
{
  int data;
  struct node *next;
}*top=NULL;




int isEmpty()
{
  if(top==NULL)
    return 1;
  else 
    return 0;
}



void push(int no)
{

  struct node *temp,*curr;
  temp=(struct node *)malloc(sizeof(struct node));

  temp->data=no;
  temp->next=NULL;

  if(top==NULL)
    {
      top=temp;
      curr=top;
    }

  else
    {
      curr->next=temp;
      curr=curr->next;
    }
}
  



void display()
{
  struct node *temp;
 
  for(temp=0;temp<=top;temp++)
    {
      printf("%d ",temp->data);
    } 
}


int main()
{
  push(1);
  push(20);

  display();



  return 0;
}



