#include<stdio.h>
#include<stdlib.h>


struct node
{
  int data;
  struct node *next;
};



  struct node *insert(struct node *head,int data)
  {
    struct node *newnode,*curr;
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


struct node *reverse(struct node *head)
{
  struct node *temp,*prev,*nextnode;
  prev=NULL;
  temp=head;
  while(temp!=NULL)
    {
      nextnode=temp->next;
      temp->next=prev;
      prev=temp;
      temp=nextnode;
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
  printf("NULL\n");
}



int main()
{
  struct node *head=NULL;

  head=insert(head,10);
  head=insert(head,20);
  head=insert(head,35);
  head=insert(head,55);

  printf("1. The original linklist is:  ");
  display(head);

  head=reverse(head);
  printf("2. The reversed linklist is:  ");
  display(head);

  return 0;
}
