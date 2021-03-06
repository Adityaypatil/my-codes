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


int size(struct node *root)
{
  if(root==NULL)
    return 0;
  else
    {
      return ((size(root->left)) + 1 +(size(root->right)));
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

  printf("%d is size of the tree\n",size(root));



  return 0;
}


