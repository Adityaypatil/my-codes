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





int loop(struct node *head)
{int flag=-1,cnt=0;
  struct node *slow=head;
  struct node *first=head;

  while(first && slow)
    {
      first=first->next;

      if(first==slow)
	{      
	flag= 1;
	break;
	}
      if(first==NULL)
	flag=0;
 

      first=first->next;

      if(first==slow)
	{
	  flag=1 ;
	  break;
	}

      slow=slow->next;
    }


  /*if(flag)
    {
      slow=head;

      while(slow!=first)
	{
	  first=first->next;
	  slow=slow->next;
	}
      return (slow->data);
      }*/
  cnt=1;
  if(flag)
    {
      first=first->next;

      while(slow!=first)
	{
         first=first->next;
	  cnt++;
	}
      return cnt;
    }
return 0;

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
{ int ans=-1;

  head=insert(head,10);
  insert(head,20);
  insert(head,30);
  insert(head,40);
  insert(head,50);

  display(head);
  head->next->next->next->next=head->next->next;

 ans= loop(head);
  /*if(ans==1) {printf("found");}
    else*/
 printf("%d",ans);
  

  return 0;
}
