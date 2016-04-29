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



void preorder(struct node *root)
{

  if(root==NULL)
    return;

  int top=0;
  struct node *stack[20];
  struct node *curr=NULL;

  stack[top]=root;


  
  while(top!=-1) 
    {
       curr=stack[top];
       printf("%d-->",curr->data);
    
       top=top-1;
       

       if(curr->right)
	 {
	   top=top+1;
	 
	   stack[top]=curr->right;
	 } 

       if(curr->left)
	 {
	   top=top+1;
	   stack[top]=curr->left;
	 }
   }
	  
}
	   

	 













int main()
{
  root=create(10);
  root->left=create(22);
 root->right=create(44);
 root->left->left=create(4);
 root->left->right=create(7);
 root->right->left=create(9);
  preorder(root);

    return 0;
}
