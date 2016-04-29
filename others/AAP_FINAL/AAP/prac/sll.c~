#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

int insert(struct node **head,int number)
{
	struct node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=number;
	temp->next=*head;
	*head=temp;
}

int display(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d ->",head->data);
		head=head->next;
	}
}

int main()
{
	struct node *first=NULL;
	
	insert(&first,10);
	insert(&first,20);
	insert(&first,30);
	insert(&first,40);
	insert(&first,50);
	
	display(first);
	return 0;
}

