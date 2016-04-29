#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void insert(struct node **root,int data)
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
		newnode->next=*root;
		*root=newnode;
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
	display(root);
	return 0;
}
