#include<stdio.h>
#include<stdlib.h>


struct treenode
{ int data;
  struct treenode *left;
  struct treenode *right;
}*root=NULL;


struct treenode *create(int data)
{
  struct treenode *new=(struct treenode *)malloc(sizeof(struct treenode));

  new->data=data;
  new->left=NULL;
  new->right=NULL;


  return new;
}



void display(struct treenode *root)
{
  if(root==NULL)
    return;
  else
    {
      display(root->left);
      printf("%d->",root->data);
      display(root->right);
    }
}


int main()
{
  root=create(10);
  root->left=create(30);
  root->right=create(40);

  display(root);

    return 0;
}
