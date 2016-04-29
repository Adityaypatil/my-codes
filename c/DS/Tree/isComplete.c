#include<stdio.h>
#include<stdlib.h>


struct node
{
  int data;
  struct node *left;
  struct node *right;
}*root=NULL;



struct node *create(int data)
{
  struct node *newnode=(struct node *)malloc(sizeof(struct node));

  newnode->data=data;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}



void display(struct node *root)
{
  if(root==NULL)
    return;
  else
    {
      printf(" %d ",root->data);
      display(root->left);
      display(root->right);
    }
} 

int isComplete(struct node *root)
{ int rear=0,front=0,flag=0;

  struct node *Queue[20];
  struct node *temp=NULL;


  Queue[rear++]=root;
  while(front<rear && rear<20)
    {
      temp=Queue[front++];

      if(temp->left)
	{
          if(flag==1)
	    return 0;
	  Queue[rear++]=temp->left;
	}
      else
	flag=1;

      if(temp->right)
	{if(flag==1)
	    return 0;
	  Queue[rear++]=temp->right;
	}
      else
       flag=1;
    }
      return 1;
}



int main()
{
  root=create(30);
  root->left=create(35);
  root->right=create(40);
  root->left->left=create(55);
  root->left->right=create(66);
  root->right->right=create(77);
  display(root);

  if(isComplete(root)==1)
    printf("\n Yes is a complete tree \n");
  else
    printf("\n Nopes not a complete tree \n");

  return 0;
}
