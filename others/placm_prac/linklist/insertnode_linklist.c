#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct node
{
int data;
struct node *next;
};


void create(struct node **head_ref,int data)
{
struct node *newnode=NULL,*curr=NULL;

newnode = (struct node *)malloc (sizeof(struct node));
newnode->data=data;
newnode->next=NULL;

if(*head_ref == NULL)
	{ 
		*head_ref=newnode;
	}
else
	{
		curr=*head_ref;
		while(curr->next !=NULL)
		{
			curr=curr->next;
		}
		curr->next=newnode;
	}

}

void print(struct node *head)
{
while(head !=	NULL)
	{
		printf("%d-->",head->data);
		head=head->next;
	}
printf("\n");
}

bool search(struct node *head,int data)
{
if (head->next == NULL )
	return false;

if(head->data==data)
	return true;
	
 search(head->next,data);

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

//printf("%d\n",temp1->data);
	
while(temp2->data !=pos2)
	{
	temp2=temp2->next;
	}
//printf("%d",temp2->data);
	
		temp1->next=temp2->next;
		temp2->next=temp1->next;

}


int main()
{
	struct node *head=NULL;

	create(&head,1);
	create(&head,2);
	create(&head,3);
	create(&head,4);
	create(&head,5);
	create(&head,6);
	create(&head,7);

	print(head);	
//search(head, 9)? printf("Yes\n") : printf("No");
//swap(head,2,6);

	print(head);	
return 0;
}
