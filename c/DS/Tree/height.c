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


int height(struct node *root)
{
  int lht=0,rht=0;

if(root==NULL)
return 0;

else
{
  lht=height(root->left);
  rht=height(root->right);

 if(lht>rht)
  return lht+1;

 else
 return rht+1;
}
}




void display(struct node *root)
{
  if(root==NULL)
   return;
else
{
  display(root->left);
printf("%d\t",root->data);
display(root->right);
}

}



int main()
{

root=create(10);
root->left=create(20);
root->right=create(30);
root->left->left=create(40);
root->left->left->right=create(55);
root->right->right=create(43);

display(root);

printf("\n %d is the height of this tree\n",height(root));

return 0;
}




