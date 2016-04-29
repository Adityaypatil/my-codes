#include<stdio.h>
#include<stdlib.h>



struct node
{
  int data;
  struct node *next;
}*head=NULL,*head1=NULL;







struct node *insert(struct node *head,int data)
{
  struct node *curr;
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));

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





struct node *swaplinks(struct node *head)
{

  struct node *curr=head;
  struct node *temp=head->next;
  struct node *nextnode;

  head=temp;

  while(1)
    {
      nextnode=temp->next; 
      temp->next=curr;

      if(nextnode==NULL || nextnode->next==NULL)
	{
          curr->next=nextnode;
	  break;
         }
      curr->next=nextnode->next;
     
      curr=nextnode;
      temp=curr->next;
    }



 
     
  return head;
}




void display(struct node *head)
{
  struct node *temp=head;

  while(temp!=NULL)
    {
      printf("%d-->",temp->data);
      temp=temp->next;
    }
  printf("NUll\n");
}




int main()
{struct node *head3=NULL,*head4=NULL;

  head=insert(head,10);
  insert(head,20);
  insert(head,30);
  insert(head,40);
  insert(head,55);
  display(head);

  head=swaplinks(head);
  display(head);



  return 0;
}
