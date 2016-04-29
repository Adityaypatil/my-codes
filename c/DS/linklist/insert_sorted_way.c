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





struct node *insert_sorted_way(struct node *head,int data)
{struct node *curr=head;
  struct node *temp;


  while(curr!=NULL && curr->data<data)
    {
      temp=curr;
      curr=curr->next;

    }

  struct node *newnode=(struct node *)malloc(sizeof(struct node ));
  newnode->data=data;
  newnode->next=curr;
  temp->next=newnode;

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
  insert(head,70);

  display(head);


  insert_sorted_way(head,50);

  display(head);

  return 0;
}
