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





struct node *reverse(struct node *head)
{
  struct node *prev=NULL;
  struct node *curr=head;
  struct node *nextnode;

  while(curr!=NULL)
    {
      nextnode=curr->next;
      curr->next=prev;
      prev=curr;
      curr=nextnode;
   }
  head=prev;
  return head;

}


struct node *detect(struct node *head)
{
  struct node *curr=head;
  struct node *temp;
  struct node *maxnode=head;

  while(curr!=NULL

struct node *isHigher(struct node *head)
{
  head=reverse(head);

  head=detect(head);

 head= reverse(head);

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
  insert(head,70);

 

  return 0;
}
