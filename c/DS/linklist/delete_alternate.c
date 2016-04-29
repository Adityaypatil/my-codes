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





struct node *delete_alternate(struct node *head)
{

  struct node *curr=head;
  struct node *temp;

  while(curr!=NULL && curr->next!=NULL)
    {
      temp=curr->next;
      curr->next=temp->next;
      free(temp);
      curr=curr->next; 
   }
        
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
  insert(head,60);

  printf("1. Before deletion:");
  display(head);

  delete_alternate(head);

  printf("2. After deletion:=");
  display(head);

  return 0;
}
