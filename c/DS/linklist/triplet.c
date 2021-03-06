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





struct node *delete_alternate(struct node *head)
{

  struct node *curr=head;
  struct node *temp;

  while(curr!=NULL && curr->next!=NULL)
    {
      temp=curr->next;
      curr->next=temp->next;
      free(temp);
      curr=curr->next; 
    }
        
}
 




struct node *triplet(struct node *head,struct node *b,struct node *c,int ans)
{
  struct node *temp=head;
  struct node *temp1=b;
  struct node *temp2=c;

  while(temp!=NULL)
    {
        
      while(temp1!=NULL && temp2!=NULL)
	{

	int sum=temp->data+temp1->data+temp2->data;
	  if(sum == ans)
	    {printf("The triplet formation is through %d %d %d\n",temp->data,temp1->data,temp2->data);
             
	      return;
	    }

	  else if (sum < ans)
            temp1=temp1->next; 

	  else
	    temp2=temp2->next;


	}
      temp=temp->next;

    }
  printf("The triplet is not found\n");
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
{struct node *b=NULL;
  struct node *c=NULL;


  head=insert(head,10);
  insert(head,20);
  insert(head,30);
  insert(head,40);
  insert(head,50);
  insert(head,60);
  display(head);


  b=insert(b,4);
  insert(b,7);
  insert(b,11);
  insert(b,15);
  insert(b,20);
  display(b);


  c=insert(c,45);
  insert(c,30);
  insert(c,25);
  insert(c,20);
  insert(c,15);
  display(c);


  triplet(head,b,c,47);

  return 0;
}
