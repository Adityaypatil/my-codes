#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *createnode(int data)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  temp->next=NULL;

  return temp;
}

void createlist(struct node **head,int data)
{
  struct node *temp,*temp1;
  
      temp=createnode(data);
     
      if(*head==NULL)
        {	  
	  	temp1=temp;
	  	*head=temp1;
	}
      else
	{
	  	temp1->next=temp;
	  	temp1=temp1->next;; 
	}

  
}
void disp(struct node *head)
{
  struct node *temp=head;
  while(temp)
    {
      printf("%d-->",temp->data);
      temp=temp->next;
    }

}
int len(struct node *head)
{
  if (head ==  NULL)
    return 0;

  else
   return  1 + len(head->next);
}
int position(struct node *head,int pos,int count)
{
  if(head==NULL)
    return;
 
  if(pos==count)
    return head->data ;

  position(head->next,pos,count+1);
}

void swap(struct node *head,int pos1,int pos2)
{
struct node *temp1=NULL,*temp2=NULL;
temp1=head;
temp2=head;

while(temp1->data !=pos1)
	{
	temp1=temp1->next;
	}

printf("%d\n",temp1->data);
	
while(temp2->data !=pos2)
	{
	temp2=temp2->next;
	}
printf("%d",temp2->data);

}


int main()
{
  int count=1,pos=2; 
  struct node *head=NULL;
  createlist(&head,1);
  createlist(&head,2);
  createlist(&head,3);
  createlist(&head,4);
  createlist(&head,5);
  createlist(&head,6);
  createlist(&head,7);
  disp(head);
  //printf("\n%d", len(head));
 // printf("\n%d",position(head,pos,count));
////////////////////////////////////////////////////////
//swap(head,2,6);

return 0;
}
