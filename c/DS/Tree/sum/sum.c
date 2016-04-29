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


int sum(struct node *root)
{
  if(root==NULL)
    return 0;
  else
    return(root->data + sum(root->left) +sum(root->right));

}



void display(struct node *root)
{
  if(root==NULL)
    return;

  display(root->left);
  printf(" %d ",root->data);
  display(root->right);
}



int main()
{

  root=create(1);
  root->left=create(4);
  root->right=create(6);
  root->left->right=create(5);
  root->right->right=create(2);

  display(root);

  printf("\nThe sum of the tree is =%d \n",sum(root));



  return 0;
}

