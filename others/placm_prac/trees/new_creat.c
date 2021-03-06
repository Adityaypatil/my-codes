#include<stdio.h>
#include<malloc.h>


struct node
{
  int data;
  struct node *left;
  struct node *right;

};

struct node *newnode(int data)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;

  return temp;
}

struct node *insert(struct node *node,int data)
{
  if(node==NULL)
    return newnode(data);

  if(data <= node->data )
    node->left=insert(node->left,data);

  else if(data >=node->data)
    node->right=insert(node->right,data);

  return node;
}

int size(struct node *node)
{
  if(node ==NULL)
    return NULL;

  return size(node->left)+1+size(node->right);
}

void inorder(struct node *node)
{
  if(node!=NULL)
    {
      inorder(node->left);
      printf("%d->",node->data);
      inorder(node->right);
    }

}




int main()
{
  struct node *root=NULL;
  root=insert(root,50);
  insert(root,30);
  insert(root,80);
  insert(root,60);
  insert(root,90);
  inorder(root);

  printf("\nSize of tree: %d\n", size(root));
  return 0;
}
