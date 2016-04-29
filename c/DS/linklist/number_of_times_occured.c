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



int occur(struct node *head,int number)
{int cnt=0;

  struct node *temp=head;

  while(temp!=NULL)
    {
      if(temp->data == number)
	{
          cnt++;
	}
      temp=temp->next;
    }
  return cnt;

} 



int main()
{
  int number=2;

  head=insert(head,10);
  insert(head,20);
  insert(head,30);
  insert(head,20);
  insert(head,50);
  insert(head,88);
  insert(head,20);

  display(head);


  printf("The element %d has occured %d times\n",number,occur(head,number));

}
