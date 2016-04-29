#include<malloc.h>

struct node
{
	int data;
	struct side *next;

};

struct side
{
	int data;
	struct side *next;
	struct node *s;

};

void insert(struct side **head,int data)
{
	struct side *temp=NULL,*curr=NULL;
	curr=*head;
	temp=(struct side *)malloc(sizeof(struct side));
	temp->data=data;
	temp->next=NULL;
	
	if(*head==NULL)
		*head=temp;

	else
	{
		while(curr->next !=NULL)		
		{
			curr=curr->next;	
		}						
	curr->next=temp;	
	}
}

void display(struct side *head)
{
	while(head !=NULL)
		{
			printf("%d ->",head->data);
			head=head->next;
		}

}

int main()	{

	int i;
	struct side *s=NULL;
	int a[]={1,2,3};
	int b[]={10,20,30};
	
	for(i=0;i<3;i++)
		insert(&s,a[i]);
	
//	for(i=0;j<3;j++)
		
	display(s);	
	return 0;
}
