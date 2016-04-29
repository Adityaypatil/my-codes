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


void differ(struct node *root,int diff)
{
  if(root->left!=NULL)
    {
     root->left->data=root->left->data+diff;
     differ(root->left,diff);
    }
  else if(root->right!=NULL)
    {
      root->right->data=root->right->data+diff;
      differ(root->right,diff);
    }
}




void change(struct node *root)
{int diff,left,right;
  if((root==NULL) ||(root->left==NULL && root->right==NULL))
     return;
     else
       {
	 change(root->left);
	 change(root->right);

	 if(root->left!=NULL)
	   left=root->left->data;
	 if(root->right!=NULL)
	   right=root->right->data;
	 diff=left+right-root->data;
	 if(diff>0)
	   root->data=root->data+diff;
	 if(diff<0)
	   differ(root,-diff);
       }
     } 


void display(struct node *root)
{
  if(root==NULL)
    return ;
  else
    {
      display(root->left);
      printf("%d\t",root->data);
      display(root->right);
    }
}


int main()
{
  root=create(19);
  root->left=create(4);
  root->right=create(10);
  root->left->left=create(3);
  root->left->right=create(1);
  display(root);

  change(root);

  display(root);

  return 0;
}
