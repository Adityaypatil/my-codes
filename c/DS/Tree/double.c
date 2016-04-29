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




void doubletree(struct node *root)
{
  struct node *oldleft,*new;

  if(root == NULL)
    return ;

  doubletree(root->left);
  doubletree(root->right);

 
      oldleft=root->left;
      root->left=create(root->data);  
      root->left->left=oldleft;
 

}








void display(struct node *root)
{
  if(root==NULL)
    return;
  else
    {
      display(root->left);
      printf(" %d ",root->data);
      display(root->right);

    }

}



int main()
{
  struct node *root1=NULL;
  root = create(1);
  root->left = create(2);
  root->right = create(3);
  
  doubletree(root);

  display(root);


}
