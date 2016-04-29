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



int main()
{


  struct node *Queue[20];
  struct node *temp;
  int front=0,rear=0;
  int cnt=0,newcnt=0,level=0,newlevel=0;
  root=create(10);
    root->left=create(20);
   root->right=create(30);
   root->left->left=create(40);
   root->left->right=create(50);
   root->right->right=create(60);
    root->right->right->left=create(70);
    root->right->right->right=create(80);

  Queue[rear++]=root;
  Queue[rear++]=NULL;
  while(front<rear && rear<20)
    {

    
      temp=Queue[front++];
    
      if(temp==NULL)
	{

	  if(cnt>newcnt)
	    {
	      newcnt=cnt;
	      newlevel=level;
	    }
	  cnt=0;

	  if(front<rear && rear<20)
	    Queue[rear++]=NULL;
          level++;
      }
      else
	{
	  cnt=cnt+1;
          
          if(temp->left)
	    Queue[rear++]=temp->left;

	  if(temp->right)
	    
	    Queue[rear++]=temp->right;
	}
    }

  printf("The level with the maximum width is = %d \n",newlevel);

}
