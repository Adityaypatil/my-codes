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





struct node *rotate(struct node *head,int k)
{
  int cnt=0;
  struct node *curr=head;
  struct node *last;
  struct node *kthnode;

  cnt=1;
  while(cnt<k && curr!=NULL)
    {
      curr=curr->next;
      cnt++;
    }
    
  kthnode=curr;

  while(curr->next!=NULL)
    {
      curr=curr->next;
    }


  curr->next=head;
  head=kthnode->next;

  kthnode->next=NULL;


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

  
  display(head);



  head=rotate(head,4);
    display(head);

  return 0;
}
