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


int max(struct node *root)
{
 int max_val=0;
int maxi=0,left,right;
if(root==NULL)
return;
else
{
   max_val=root->data;

left=max(root->left);
right=max(root->right);

if(left>right)
maxi=left;
if(right>left)
maxi=right;

if(maxi>max_val)
max_val=maxi;

//return max_val;
}

return max_val;
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
  root->right=create(90);
  root->left->right=create(44);
  root->right->right=create(80);

  display(root);

  printf("%d is max ele of the tree\n",max(root));
//max(root);


  return 0;
}


