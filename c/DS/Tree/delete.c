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


int delete(struct node *root)
{
 if(root==NULL)
   return;

else
{
  delete(root->left);
delete(root->right);

printf("\ndeleting node =%d\n",root->data);
free(root);
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

 display(root);


delete(root);

display(root);

return 0;
}





