#include<stdio.h>
#include<stdlib.h>




struct node
{
  int data;
  struct node *left;
  struct node *right;
  struct node *nextright;
 
}*root=NULL;




struct node *create(int data)
{
  struct node *newnode=(struct node *)malloc(sizeof(struct node));

  newnode->data=data;
  newnode->left=NULL;
  newnode->right=NULL;

  return newnode;

}


struct node *connect_nodes(struct node *root)
{
  
  if(root==NULL)
    return ;

  if(root->left)
    root->left->nextright=root->right;

  if(root->right)
    root->right->nextright=(root->nextright)?(root->nextright->left):NULL;

  connect_nodes(root->left);
  connect_nodes(root->right);

}

void display(struct node *root)
{
  if(root==NULL)
    return;

  
  printf("%d\t",root->data);
  display(root->left);
  display(root->right);
}



int main()
{

  root=create(10);
  root->left=create(8);
  root->right=create(2);
  root->left->left=create(3);


  display(root);


  connect_nodes(root);
  
  printf("Following are populated nextRight pointers in the tree "
	 "(-1 is printed if there is no nextRight) \n");
  printf("nextRight of %d is %d \n", root->data,
         root->nextright? root->nextright->data: -1);
  printf("nextRight of %d is %d \n", root->left->data,
	 root->left->nextright? root->left->nextright->data: -1);
  printf("nextRight of %d is %d \n", root->right->data,
	 root->right->nextright? root->right->nextright->data: -1);
  printf("nextRight of %d is %d \n", root->left->left->data,
	 root->left->left->nextright? root->left->left->nextright->data: -1);
  



  return 0;
}

