#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};	

void insert(struct node **head, int value)
{
	struct node *temp=NULL;
	struct node *tail;
	
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;

	if(*head==NULL)
	{
		*head=temp;
		tail=temp;
	}	
	else
	{
		tail->next=temp;
		tail=temp;
	}
}	

void display(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
}

int main()
{
	struct node *head=NULL;
	int a[]={1,2,3,4,5},i;
	int n=sizeof(a)/sizeof(a[0]);
	
	for(i=0;i<n;i++)
		insert(&head,a[i]);
	display(head);
	return 0;
}

