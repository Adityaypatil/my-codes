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


void mirror(struct node *root)
{struct node *temp;
  if(root)
  {
    mirror(root->left);
    mirror(root->right);

   temp=root->left;
   root->left=root->right;
   root->right=temp;

  }
}


int isIdentical(struct node *root,struct node *root1)
{
 if(root==NULL && root1==NULL)
  return 1;

 if((root->data == root1->data)&&
  isIdentical(root->left,root1->left)&&
  isIdentical(root->right,root1->right));
 {return 1;}
 
   return 0;


}


int foldable(struct node *root)
{int res=-1;
   if(root==NULL)
    return 1;
else
{
  mirror(root->left);

  res=isIdentical(root->left,root->right);

 return res;
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
{int res=-1;


  root=create(1);
  root->left=create(2);
  root->right=create(3);
  root->right->left=create(4);
  root->left->left=create(5);

  display(root);

res=foldable(root);
if(res==1)
  printf("\nYes the tree is foldable tree\n");
else
printf("\nNO the tree is not foldable\n");


  return 0;
}


