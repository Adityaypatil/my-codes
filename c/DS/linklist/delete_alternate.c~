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





struct node *delete(struct node **head)
{


  struct node *temp=*head;
  struct node *nextnode;

  while(temp!=NULL)
    {
      nextnode=temp->next;
      free(temp);
      temp=nextnode;
    }

  *head=NULL;
}











void display(struct node *head)
{
  struct node *temp=head;

  while(temp!=NULL)
    {
      printf("%d-->",temp->data);
      temp=temp->next;
    }
  printf("\n");
}



int main()
{

  head=insert(head,10);
  insert(head,20);
  insert(head,30);
  insert(head,40);
  insert(head,50);

  printf("1. Before deletion:");
  display(head);

  delete(&head);

  printf("2. After deletion:=");
  display(head);

  return 0;
}
