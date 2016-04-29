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

void inorder(struct node *root)
{
  int top=-1;
  /* set current to root of binary tree */
  struct node *current = root;
  struct node *stack[20];  /* Initialize stack s */
  int done=0;

  while (!done)
    {
    if(current !=  NULL)
	{

	   top=top+1;
	  stack[top]=current;                                            
	  current = current->left;  
	}
       
     else                                                              
	{
	  if (top!=-1)
	    {
	      current = stack[top];
	        top=top-1;
	      printf("%d ", current->data);


	      current = current->right;
	    }
	   else
	   done = 1; 
	}
    }  
}



void display(struct node *root)
{
  if(root==NULL)
    return;

  display(root->left);
  printf("%d\t",root->data);
  display(root->right);
}



int main()
{

  root=create(50);
  root->left=create(40);
  root->right=create(60);
  root->left->right=create(44);
  root->right->right=create(80);

  display(root);

  // printf("%d is size of the tree\n",size(root));

  inorder(root);

  return 0;
}

