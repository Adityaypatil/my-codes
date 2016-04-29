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



int identical(struct node *head,struct node *head1)
{
  struct node *a=head;
  struct node *b=head1;

  while(1)
    {
  if(a==NULL && b==NULL)
    return 1;
  if(a!=NULL  && b==NULL)
    return 0;
  if(a==NULL && b!=NULL)
    return 0;
  if(a->data!=b->data)
    return 0;

  a=a->next;
  b=b->next;
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
{ int ele=-1;


  head=insert(head,25);
  insert(head,20);
  insert(head,60);
  insert(head,70);



  head1=insert(head1,25);
  insert(head1,20);
  insert(head1,60);
  insert(head1,70);


  printf("1. List1:");
  display(head);

  printf("2. List2:");
  display(head1);
 


  ele=identical(head,head1);
  if(ele==1) {printf("list1 and list2 are identical\n");}
    else
      printf("Not identical\n");
  return 0;
}
