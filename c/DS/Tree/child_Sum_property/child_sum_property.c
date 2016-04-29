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
{if(root==NULL)
    return ;
  else
    {
  display(root->left);
  printf("%d-->",root->data);
  display(root->right);
}
}

int isChildSumProperty(struct node *root)
{int left,right;

  if(root==NULL || root->left==NULL && root->right==NULL)
    return 1;
  else
    {
      if(root->left!=NULL)
	left=root->left->data;
      if(root->right!=NULL)
	right=root->right->data;
      if((root->data==left+right)&&
	 isChildSumProperty(root->left)&&
	 isChildSumProperty(root->right))
	return 1;
      else
	return 0;
    }
}



int main()
{
  int ans=-1;

  root=create(10);
  root->left=create(6);
  root->right=create(4);
  root->left->left=create(4);
  root->left->right=create(2);
  

  display(root);
  printf("\n");


  ans=isChildSumProperty(root);
  if(ans==1)
  printf("yess!!! :) Holds isChildSumProperty\n");
  else
    printf("Nopes :( does not hold the property\n");

  return 0;


}
