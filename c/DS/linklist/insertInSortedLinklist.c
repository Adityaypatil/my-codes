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


struct node *insertAtPos(struct node *start,int data)
{struct node *newnode;
  struct node *curr=start,*temp;

  while(curr!=NULL && curr->data<data)
    {
      temp=curr;
      curr=curr->next;
    }

  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next=curr;
  temp->next=newnode;

  return start;
}


int main()
{
  start=insert(start,10);
  insert(start,20);
  insert(start,30);
  insert(start,70);
  start=insertAtPos(start,50);
  display(start);

  
}
