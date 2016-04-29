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




int isPresent(struct node *head,int data)
{

  struct node *temp=head;

  while(temp!=NULL)
    {

      if(temp->data == data)
	return 1;
      temp=temp->next;
    }
  return 0;
}








struct node *unionlist(struct node *head,struct node *head1)
{
  struct node *l1=head;
  struct node *l2=head1;
  struct node *result=NULL;

  while(l1!=NULL)
    {

      result=insert(result,l1->data);
      l1=l1->next;

    }

  while(l2!=NULL)
    {  
      if(!isPresent(result,l2->data))
	{
	  result=insert(result,l2->data);
     
        } 
      l2=l2->next; 
        
    }



  return result;


}





struct node *intersect(struct node *head,struct node *head1)
{
  struct node *result=NULL;
  struct node *t1=head;


  while(t1!=NULL)
    {
      if(isPresent(head1,t1->data))
        {
	  result=insert(result,t1->data);
	}

	t1=t1->next;
    }

  return result;
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


  head3=unionlist(head,head1);
  display(head3);


  head4=intersect(head,head1);
  display(head4);

  return 0;
}
