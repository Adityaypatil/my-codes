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


int leafcount(struct node *root)
{
  if(root==NULL)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return 1;
  else
    {
      return (leafcount(root->left)+leafcount(root->right));
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
  root->left->left=create(67);
  root->left->right=create(44);
  root->right->left=create(90);
  root->right->right=create(80);

  display(root);

  printf("\n%d is leaf_count of the tree :)\n",leafcount(root));



  return 0;
}

