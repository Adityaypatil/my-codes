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








struct node *removeduplicates(struct node *head)

{
  struct node *ptr1=head;
  struct node *ptr2;
  struct node *temp;

  while(ptr1!=NULL && ptr1->next!=NULL)
    {
      ptr2=ptr1;

      while(ptr2!=NULL && ptr2->next!=NULL)
     {
      if(ptr1->data == ptr2->next->data)
	{
	  temp=ptr2->next;  
	  ptr2->next=temp->next;
	  free(temp);

	}
      else
	{
	  ptr2=ptr2->next;
	}
     }
      ptr1=ptr1->next;
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
  printf("\n");
}





int main()
{


  head=insert(head,10);
  insert(head,30);
  insert(head,20);
  insert(head,10);
  insert(head,40);
  insert(head,20);

  display(head);


  removeduplicates(head);

  display(head);

  return 0;
}
