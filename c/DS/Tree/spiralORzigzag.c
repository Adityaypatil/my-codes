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


struct node *spiral(struct node *root)
{
  int rear=0;
  int front=0;
  int top=0;
  int flag=0;

  struct node *Queue[20];
  struct node *stack[20];
  struct node *temp=NULL;

  Queue[rear++]=root;
  Queue[rear++]=NULL;

  while(front<rear && rear<20)
    {
      temp=Queue[front++];
      if(temp)
	{
          if(flag==0)
	    {
                printf(" %d ",temp->data);

	    }	
          else
	    {
	      top=top+1;
	      stack[top]=temp;
	    }
	  if(temp->left)
	    Queue[rear++]=temp->left;
	  if(temp->right)
	    Queue[rear++]=temp->right;
	}   

     else
 	{
          Queue[rear++]=NULL;
	  printf("\n");
	  if(flag==1)
	    {
	      while(top!=0)
		{
                 temp=stack[top];
		  top=top-1;
                  printf(" %d ",temp->data);
	        }
	      printf("\n");

	     }
 
	  if(flag==0) flag=1;
	  else
	    flag=0;
	}
}


}


void display(struct node *root)
{
  if(root==NULL)
    return;

  // display(root->left);
  printf("%d\t",root->data);
  display(root->left);
  display(root->right);
}



int main()
{

  root=create(1);
  root->left=create(2);
  root->right=create(3);
  root->left->left=create(4);
  root->left->right=create(5);
  root->right->left=create(6);
  root->right->right=create(7);
  root->left->left->left=create(8);
  root->left->left->right=create(9);
  root->right->left->left=create(10);
  root->right->right->right=create(11);
  display(root);
  printf("\n\n");


  spiral(root);


  return 0;
}

