#include<stdio.h>
#include<stdlib.h>



struct node
{
  int data;
  struct node *next;
}*head=NULL;





struct node *insert(struct node * head,int data)
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




struct node * moveToLast2(struct node **head_ref)
{

  struct node *temp=*head_ref;
  struct node *secondlast=NULL;


  if(*head_ref==NULL || (*head_ref)==NULL)
    return;

  while(temp->next->next!=NULL)
    {                                                                           temp=temp->next;
    }

  secondlast=temp;
  temp=temp->next;

  secondlast->next=NULL;
  temp->next=*head_ref;

  *head_ref=temp;


}







struct node * moveToLast(struct node *head_ref)
{

  struct node *temp=head_ref;
  struct node *secondlast=NULL;


  if(head_ref==NULL || (head_ref)==NULL)
    return;

  while(temp->next->next!=NULL)
    {  
     
      //secondlast=temp; (if while conditn is (temp->next!=null)  
    temp=temp->next;
    }

  secondlast=temp;
  temp=temp->next;

  secondlast->next=NULL;
  temp->next=head_ref;

    head_ref=temp;

    return head_ref;

}








int main()
{
  head=insert(head,10);
  insert(head,20);
  insert(head,30);
  insert(head,40);

  display(head);

  moveToLast2(&head);
  display(head);

  head=moveToLast(head);
  display(head);


  return 0;
}
