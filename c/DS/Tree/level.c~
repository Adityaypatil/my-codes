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


  struct node *temp=NULL;
  struct node *Queue[20];
  int front = 0, rear = 0;

  Queue[rear++] = root;

  while ( front < rear && rear < 20 )
	{
	  temp = Queue[front++];
	   printf("%d\t",temp->data);

	  if ( temp )
		{
		  if ( temp -> left )
			Queue[rear++] = temp -> left;

		  if ( temp -> right )
			Queue[rear++] = temp -> right;
		}

         }        
  return 0;
}





