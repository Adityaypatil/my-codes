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




void printing(int arr[],int len)
{int i;
  for(i=0;i<len;i++)
    {
      printf(" %d ",arr[i]);
    }
}


void printpath(struct node *root,int arr[],int len,int number)
{

  if(root==NULL)
    return;

  arr[len]=root->data;
  len++;

  if(root->data == number)
    printing(arr,len);
  else
    {
      printpath(root->left,arr,len,number);
      printpath(root->right,arr,len,number);
    }
}



int main()
{

  int arr[100];

  struct node *root = create(1);
  root->left        = create(2);
  root->right       = create(3);
  root->left->left  = create(4);
  root->left->right = create(5);
  root->left->left->left  = create(7);


  printpath(root,arr,0,4);

  return 0;


}
