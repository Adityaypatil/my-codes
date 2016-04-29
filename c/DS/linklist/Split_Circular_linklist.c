#include<stdio.h>
#include<stdlib.h>

struct node
{int data;
  struct node *next;
}*head=NULL;


struct node *insert(struct node *head,int data)
{ struct node *curr;
  struct node *newnode=(struct node *)malloc(sizeof(struct node));

  newnode->data=data;
  newnode->next=NULL;

  if(head==NULL)
    {
      head=newnode;
      curr=newnode;
      newnode->next=head;
    }
  else
    {
      curr->next=newnode;
      newnode->next=head;
      curr=newnode;
    }
  return head;


}



struct node *Splitlinklist(struct node *head,struct node **head1,struct node **head2)
{

  struct node *slowptr=head;
  struct node *fastptr=head;

  if(head==NULL)
    return ;

  while(fastptr->next!=head && fastptr->next->next!=head)
    {
      fastptr=fastptr->next->next;
      slowptr=slowptr->next;
    }

  if(fastptr->next->next==head)
    {
      fastptr=fastptr->next;

    }
  *head1=head;

  if(head->next!=head)
    {
      *head2=slowptr->next;
    }

  fastptr->next=slowptr->next;
  slowptr->next=head;



}


void display(struct node *head)
{
  struct node *temp=head;
  
  do
    {
      printf("%d-->",temp->data);
      temp=temp->next;
    }while(temp!=head);
  printf("\n");

}



int main()
{struct node *head1=NULL;
  struct node *head2=NULL;

  head=insert(head,10);
  insert(head,20);
  insert(head,30);
  insert(head,55);

  display(head);


  Splitlinklist(head,&head1,&head2);

  printf("Circular list is:");
    display(head1);
  printf("Circular list is:");
  display(head2);

  return 0;
}
