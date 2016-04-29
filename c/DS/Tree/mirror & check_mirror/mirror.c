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


struct node *mirror(struct node *root)
{struct node *temp;
  if(root)
    {
      mirror(root->left);
      mirror(root->right);
	 temp=root->left;
	 root->left=root->right;
	 root->right=temp;
     }

       
 return root;
	 
}




void display(struct node *root)
{
  if(root==NULL)
    return;

  // display(root->left);
  printf("%d-->",root->data);
  display(root->left);
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

  printf("\n\n");
  mirror(root);
  display(root);
  printf("\n\n");

  return 0;
}

