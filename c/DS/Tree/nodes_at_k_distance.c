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


void nodes_at_k_distance(struct node * root,int k)
{
  int front=0,rear=0,cnt=0,level=0;
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
          if(level==k)
	    {
	      printf(" %d ",temp->data);
	    }

	  if(temp->left)
	    Queue[rear++]=temp->left;
	  if(temp->right)
	    Queue[rear++]=temp->right;
	}

    }
}

int main()
{
  root = create(1);
  root->left        = create(2);
  root->right       = create(3);
  root->left->left  = create(4);
  root->left->right = create(5);
  root->right->left = create(8);
  root->right->right=create(9);  
  root->right->right->right=create(55);


  nodes_at_k_distance(root,2);

  return 0;
}
