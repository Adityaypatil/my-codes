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


void print(int path[100],int pathlength)
{int i;
 for(i=0;i<pathlength;i++)
{
  printf("%d-->",path[i]);
}
printf("\n");
}

void printpaths(struct node *root,int path[100],int pathlength)
{
  if(root==NULL)
    return ;
else
  {
    path[pathlength]=root->data;
    pathlength++;
  }

  if(root->left==NULL && root->right==NULL)
   print(path,pathlength);

else
 {
  printpaths(root->left,path,pathlength);
  printpaths(root->right,path,pathlength);
 }
}








int main()
{
 int path[100];

root=create(10);
root->left=create(20);
root->right=create(40);
root->left->left=create(11);

printpaths(root,path,0);

return 0;
}


