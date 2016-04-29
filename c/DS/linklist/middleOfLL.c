#include<stdio.h>
#include<stdlib.h>



struct node
{
  int data;
  struct node *next;
}*start=NULL;


struct node *insert(struct node *start,int data)
{

  struct node *newnode,*curr;
 

  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next=NULL;


  if(start==NULL)
    {
      start=newnode;
      curr=newnode;
    }

  else
    {
      curr->next=newnode;
      curr=newnode;
    }

  return start;
}



void display(struct node *start)
{
  struct node *temp=start;

  while(temp!=NULL)
    {
      printf("%d-->",temp->data);
      temp=temp->next;
    }
  printf("NULL\n");
}


struct node *middleElement(struct node *start)
{
  struct node *slow=start;
  struct node *fast=start;

  while(fast!=NULL && fast->next!=NULL)
    {
      fast=fast->next->next;
      slow=slow->next;
    }
  printf("2. Middle element of the list is =%d\n",slow->data);


}


int main()
{
  start=insert(start,10);
  insert(start,20);
  insert(start,90);
  insert(start,70);
 insert(start,50);
 insert(start,60);

 printf("1. Linklist is :");
  display(start);

  middleElement(start);
 
}
