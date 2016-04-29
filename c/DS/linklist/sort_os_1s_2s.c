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





struct node *sort012(struct node *head)
{int i;
  struct node *temp=head;

  int cnt[3]={0,0,0};

  while(temp!=NULL)
    {
      cnt[temp->data] +=1;
      temp=temp->next;
    }

  i=0;
  temp=head;
  while(temp!=NULL)
    {

      if(cnt[i]==0)
	i++;
      else
	{
          temp->data=i;
	  cnt[i]--;

	  temp=temp->next;

	  }

    }
 


}





/*
int isPresent(struct node *head,int data)
{

  struct node *temp=head;

  while(temp!=NULL)
    {

      if(temp->data == data)
e	return 1;
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

*/




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
{struct node *head1=NULL;


  head1=insert(head1,2);
  insert(head1,0);
  insert(head1,1);
  insert(head1,0);
  insert(head1,2);
  insert(head1,1);
  insert(head1,0);
  insert(head1,1);

  display(head1);


  sort012(head1);
  display(head1);

}
