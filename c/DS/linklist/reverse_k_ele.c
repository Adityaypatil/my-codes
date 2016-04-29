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





struct node *reverseKele(struct node *head,int k)
{

  int cnt=0;
  struct node *curr=head;
  struct node *nextnode;
  struct node *prev=NULL;


  while(curr!=NULL && cnt<k)
    {
      nextnode=curr->next;
      curr->next=prev;
      prev=curr;
      curr=nextnode;
      cnt++;
    }
 

  if(nextnode!=NULL)
    {
      head->next=reverseKele(nextnode,k);
    }
  head=prev;
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

  printf("1. Before deletion:");
  display(head);

  head=reverseKele(head,3);

  //printf("2. After deletion:=");
  display(head);

  return 0;
}
