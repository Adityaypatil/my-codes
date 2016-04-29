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


int sum(struct node *root)
{
  int rear=0,front=0,sum=0;
  struct node *Queue[20];
  struct node *temp=NULL;

  Queue[rear++]=root;
  while(front<rear && rear<20)
    {
      temp=Queue[front++];
      sum=sum+temp->data;
      if(temp->left)
	Queue[rear++]=temp->left;
      if(temp->right)
	Queue[rear++]=temp->right;
    }

  return sum;

}




void display(struct node *root)
{
  if(root==NULL)
    return;

  display(root->left);
  printf(" %d ",root->data);
  display(root->right);
}



int main()
{

  root=create(5);
  root->left=create(4);
  root->right=create(1);
  root->left->right=create(4);
  root->right->right=create(8);

  display(root);

  printf("\n %d is size of the tree\n",sum(root));



  return 0;
}

