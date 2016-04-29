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




int isIdentical(struct node *root,struct node *root1)
{
  if(root==NULL && root1==NULL)
    return 1;

  if(root==NULL || root1==NULL)
    return 0;

  return ((root->data == root1->data)&&
     isIdentical(root->left,root1->left)&&
	  isIdentical(root->right,root1->right));
     
}




int ISsubtree(struct node *root,struct node *root1)
{
  if(root1 == NULL)
    return 1;

  if(root==NULL)
    return 0;

  if(isIdentical(root,root1))
     return 1;

   
	 return ISsubtree(root->left,root1) || ISsubtree(root->right,root1);
       


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
  int ans=-1;
  
struct node *root1=NULL;

  root=create(1);
  root->left=create(2);
  root->right=create(3);
  root->left->left=create(4);
  root->left->right=create(5);
  // root->left->left->left=create(6);
  root->right->right=create(8);

  display(root);


  root1=create(2);
  root1->left=create(4);
  root1->right=create(5);

  display(root1);
  //root->left->left=create(4);
  //root->left->right=create(5);
  //root->left->left->left=create(6);
  //root->right->right=create(8);




  ans=ISsubtree(root,root1);
  if(ans==1)
    printf("\nyes the tree is subtree of the given tree\n");
  else
    printf("\n Nopes\n");



  return 0;
}

