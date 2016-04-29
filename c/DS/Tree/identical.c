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



int identical(struct node *root,struct node *root1)
{

 if(root==NULL && root1==NULL)
return 1;

if(root!=NULL && root1!=NULL)
{
  return 
 ((root->data == root1->data) &&
 identical(root->left,root1->left) &&
 identical(root->right,root1->right));
}

return 0;

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

root=create(10);
root->left=create(20);
root->right=create(60);


root1=create(10);
root1->left=create(20);
root1->right=create(60);



display(root);
printf("\n");
display(root1);


ans=identical(root,root1);
if(ans==1)
printf("\nyes are identical\n");
else
printf("\n No are not identical\n");


return 0;
}




