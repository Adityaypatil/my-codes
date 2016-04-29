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






struct node *alternateMerge(struct node *head,struct node *head1)
{

  struct node *p=head;
  struct node *q=head1;
  struct node *pnext=p->next;
  struct node *qnext=q->next;
  struct node *temp;

  while(q!=NULL && q->next!=NULL)
    {
      pnext=p->next;
      qnext=q->next;

     
      q->next=pnext;
      p->next=q;

      p=pnext;
      q=qnext;
    }
  head1=q;
  return head1;
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

  display(head);

  head1=insert(head1,45);
  insert(head1,20);
  insert(head1,30);
  insert(head1,50);
  insert(head1,60);

  display(head1);

  head1=alternateMerge(head,head1);

  display(head);
  display(head1);


   return 0;
}
