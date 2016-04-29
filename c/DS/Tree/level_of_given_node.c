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


void level_of_node(struct node *root,int data)
{int front=0,rear=0,level=0;

  struct node *Queue[20];
  struct node *temp=NULL;

  Queue[rear++]=root;
  Queue[rear++]=NULL;

   
while(front<rear && rear<20)
    {
      temp=Queue[front++];

      if(temp==NULL)
	{
	  level=level+1;

	  if(front<rear && rear<20)
	    Queue[rear++]=NULL;
	}

	
      else
	{
          if(temp->data == data)
	    printf(" %d ",level);
	  if(temp->left)
	    Queue[rear++]=temp->left;
	  if(temp->right)
	    Queue[rear++]=temp->right;
	}
    }

}

int main()
{
  
  root = create(3);
  root->left = create(2);
  root->right = create(5);
  root->left->left = create(1);
  root->left->right = create(4);

  level_of_node(root,1);
    return 0;
}
