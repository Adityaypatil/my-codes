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


int size(struct node *root)
{
  if(root==NULL)
    return 0;
  else
    {
      return ((size(root->left)) + 1 +(size(root->right)));
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



int maximum(struct node *Queue[20])
{struct node *temp=NULL;
  int front=0,rear=0,max=-999;

 Queue[rear++]=root;

while(front<rear && rear<20)
{
  temp=Queue[front++];

  if(temp->data>max)
     max=temp->data; 
  
  if(temp)
  {
    if(temp->left)
    Queue[rear++]=temp->left;

    if(temp->right)
    Queue[rear++]=temp->right;
  }

}
printf("%d",max);
}






int main()
{
  struct node *Queue[20];

  root=create(50);
  root->left=create(40);
  root->right=create(90);
  root->left->right=create(44);
  root->right->right=create(80);


  maximum(Queue);

 return 0;
}


