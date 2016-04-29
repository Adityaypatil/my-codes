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



void printleaf(struct node *root)
{

  if(root)
    {
      printleaf(root->left);

      if(!root->left && !root->right)
	printf(" %d ",root->data);

      printleaf(root->right);
    }
}


void printlefttraversal(struct node *root)
{
  if(root)
    {
      if(root->left)
	{

          printf(" %d ",root->data);
	  printlefttraversal(root->left);
	}
      else
	if(root->right)
	  {
	    printf(" %d ",root->data);
	    printlefttraversal(root->right);
	  }
    }
}


void printrighttraversal(struct node *root) 
{
  if(root)
    {
      if(root->right)
	{
          printrighttraversal(root->right);
	  printf(" %d ",root->data);

	}

      else
	if(root->left)
	  {
	    printlefttraversal(root->left);
	    printf(" %d ",root->data);
	  }
    }

}

void BoundaryTraversal(struct node *root)
{
  if(root)
    {

      printf(" %d ",root->data);

      printlefttraversal(root->left);

      printleaf(root->left);
      printleaf(root->right);

      printrighttraversal(root->right);

   }

}



int main()
{
  root         = create(20);
  root->left                = create(8);
  root->left->left          = create(4);
  root->left->right         = create(12);
  root->left->right->left   = create(10);
  root->left->right->right  = create(14);
  root->right               = create(22);
  root->right->right        = create(55);
  
  display(root);

  printf("\n\n");

  BoundaryTraversal(root);
  printf("\n\n");

  return 0;
}
