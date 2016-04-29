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





struct node *addElements(struct node *head,struct node *head1)
{
  struct node *first=head;
  struct node *second=head1;
  struct node *temp=NULL;
  int carry=0;
  int sum=0;

  while(first!=NULL || second!=NULL)
    {
      sum=carry + (first? first->data :0) + (second? second->data : 0);

          carry=(sum>=10)?1:0;
	  sum=sum % 10;
       
          temp=insert(temp,sum);


	  if(first) first=first->next;
	  if(second) second=second->next;

    }

  if(carry > 0)
    { 
    temp=insert(temp,carry);
    }
  return temp;
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
  struct node *head1=NULL,*addele=NULL;
  head=insert(head,5);
  insert(head,6);
  insert(head,3);

  display(head);


  head1=insert(head1,8);
   insert(head1,4);
  insert(head1,2);

  display(head1);


  addele=addElements(head,head1);
  display(addele);


  return 0;
}
