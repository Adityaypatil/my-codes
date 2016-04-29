#include<stdio.h>
#include<stdlib.h>




struct node 
{
  int data;
  struct node *next;
}*head=NULL;




struct node *insert(struct node *head,int data)
{
  struct node *curr;
  struct node *newnode=(struct node *)malloc(sizeof(struct node));

  newnode->data=data;
  newnode->next=NULL;

  if(head==NULL)
    {
      head=newnode;
      curr=newnode;
    }
  else
    {
      curr->next=newnode;
      curr=newnode;
    }

  return head;
}







void display(struct node *head)
{
  struct node *temp=head;

  if(head==NULL)
    return;
  display(head->next);
  printf("%d\t",head->data);
}


int main()
{head=insert(head,10);
  insert(head,20);
  insert(head,30);


  display(head);
 
 return 0;
}

