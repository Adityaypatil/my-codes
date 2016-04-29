#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int insert(struct node **root,int data)
{
	struct node *newnode,*curr;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;

	if(*root==NULL)
	{
		*root=newnode;
	}
	else
	{
		curr=*root;
			while(curr->next!=NULL)
				{
					curr=curr->next;
				}
			curr->next=newnode;
	}
	return 1;
}

void position(struct node **root,int pos,int data)
{
	struct node *temp1=NULL;
	temp1=*root;
	
	if(pos== 1)
		insert(&root,data);
	
	 if( pos !=1)
		{
		while(pos!=0)
			{
				pos--;
				temp1=temp1->next;
			}
		struct node *newnode,*curr;
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=data;
		newnode->next=NULL;
		
		
		newnode->next=temp1->next;	
		temp1->next=newnode;	
						
		}
}
void display(struct node *root)
{
	while(root!=NULL)
		{
			printf("|%d|->",root->data);
			root=root->next;
		}

}

int main()
{
	struct node *root=NULL;
	insert(&root,1);
	insert(&root,2);
	insert(&root,3);
	insert(&root,4);
	insert(&root,5);
	display(root);
	position(&root,3,21);
	display(root);
	return 0;
}
