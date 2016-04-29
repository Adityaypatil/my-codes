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


int leafcount(struct node *root)
{int front=0,rear=0,cnt=0;
  struct node *Queue[20];
  struct node *temp=NULL;


  Queue[rear++]=root;
  while(front<rear && rear<20)
    {
      temp=Queue[front++];
      if(!temp->left && !temp->right)
	cnt++;
      else
	{
	  if(temp->left)
	    Queue[rear++]=temp->left;
	  if(temp->right)
	    Queue[rear++]=temp->right;
	}
    }
  return cnt;
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
   root->right=create(60);
   root->left->right=create(44);
  root->right->right=create(80);

  display(root);

  printf("\n %d is count of leaf nodes the tree :)\n",leafcount(root));



  return 0;
}

