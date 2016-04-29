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

bool search(struct node *head,int no)
{

if (head == NULL);
	return false;
	
if (head->data == no)
	return true;
	
	else search(head->next,no);

}

int main()
{
	struct node *head=NULL;

	create(&head,1);
	create(&head,2);
	create(&head,3);
	create(&head,4);

//print(head);	

search(head,3)? printf("\nNmber is present"):printf("\nNumber is not present\n");

return 0;

}
