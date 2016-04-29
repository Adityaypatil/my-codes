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


int check_mirror(struct node *root,struct node *root1)
{
  if(root==NULL && root1==NULL)
    return 1;
  if(root==NULL || root1==NULL)
    return 0;
  if(root->data!=root1->data)
    return 0;
  else
    return(check_mirror(root->left,root1->right) && check_mirror(root->right,root1->left)); 
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
{int ans;
  struct node *root1=NULL;
   root=create(50);
   root->left=create(40);
   root->right=create(60); 
   
   display(root);


   root1=create(50);
   root1->left=create(60);
   root1->right=create(40);
  
   printf("\n\n");
   display(root1);

  ans=check_mirror(root,root1);
  if(ans==1)
    printf("\n Yes :) :) the two trees are mirror of each other\n");
  else
    printf("\n Nopes :( :(  not mirror of each other\n");

  return 0;
}

