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
  struct node *newnode=(struct node *)malloc(sizeof (struct node));

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





struct node *segregate(struct node **head)
{
  struct node *end=*head;
  struct node *newend;
  struct node *curr=*head;
  struct node *prev=NULL;

  while(end->next!=NULL)
    {
      end=end->next;
    }

  newend=end;

  while((curr->data) % 2!=0 && curr!=end)
    {
      newend->next=curr;
      curr=curr->next;
      newend->next->next=NULL;
      newend=newend->next;
    }


  if((curr->data) % 2==0)
    {
      *head=curr;

      while(curr!=end)
	{
	  if((curr->data) % 2 ==0)
	    {

	      prev=curr;
              curr=curr->next; 

	    }
	  else
	    {
	      prev->next=curr->next;
	      curr->next=NULL;
	      newend->next=curr;
	      newend=curr;
	      curr=prev->next;
            }

	}

    }
  
      if((newend!=end) && ((end->data)%2!=0))
	{
	  prev->next=end->next;
	  end->next=NULL;
	  newend->next=end;
	}
      return;
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
  head=insert(head,11);
  insert(head,3);
  insert(head,4);
  insert(head,6);
  insert(head,8);
  insert(head,10);
  insert(head,12);
   insert(head,9);

  display(head);
 
  segregate(&head);

  display(head);

 return 0;
}
