#include<stdio.h>
#include<stdlib.h>
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
		printf("| %d |-->",head->data);
		head=head->next;
	}
printf("\n");
}

// Count linklist iterative way =====================================================
void count (struct node *head)
{
int count=0;

while(head !=NULL)
	{
		count++;
		head=head->next;
	}
	printf("\nTotal count of linklist is ==>%d\n",count);
	
}
// reccursive way ====================================================================

int getcount(struct node *head)
{
if (head==NULL)
	return 0;

else return 1 + getcount(head->next);
}
int main()
{
	struct node *head=NULL;

	create(&head,1);
	create(&head,2);
	create(&head,3);
	create(&head,4);

print(head);	
//count(head);
printf("\nCount of linklist is ==>%d",getcount(head));
return 0;
}
