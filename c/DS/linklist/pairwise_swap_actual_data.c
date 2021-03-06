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





void swap( int *a,int *b)
{
  struct node *temp;
  temp=*a;
  *a=*b;
  *b=temp;
}



struct node *pairwise(struct node **head)
{
  struct node *temp=*head;

  while(temp!=NULL && temp->next!=NULL)
    {
      swap(&temp->data,&temp->next->data);
      temp=temp->next->next;
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
  insert(head,40);
  insert(head,20);
  insert(head,60);
  insert(head,30);
  insert(head,70);

  display(head);


 pairwise(&head);

  display(head);

  return 0;
}
