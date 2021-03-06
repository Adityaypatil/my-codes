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



void printarray(int path[],int len)
{int i;
  for(i=0;i<len;i++)
    printf(" %d ",path[i]);
  printf("\n");
}

struct node *root_to_leaf(struct node *root,int path[],int len)
{
  if(root==NULL)
    return;

      path[len]=root->data;
      len++;
      if(root->left==NULL && root->right==NULL)
	printarray(path,len);

      else
	{
        root_to_leaf(root->left,path,len);
        root_to_leaf(root->right,path,len);
	}
}
 

int max_sum_level(struct node *root)
{int front=0,rear=0,maxlevel=0,currsum=0,max_sum=0,level=0;

  struct node *Queue[20];
  struct node *temp=NULL;
 
  Queue[rear++]=root;
  Queue[rear++]=NULL;

  while(front<rear && rear<20)
    {
      temp=Queue[front++];
      
      if(temp==NULL)
	{
	  if(currsum>max_sum)
	    {
	      max_sum=currsum;
	      maxlevel=level;
	    }
	  currsum=0;
	  if(front<rear && rear<20)
	    Queue[rear++]=NULL;
	  level++;
         }

      else
	{
	  currsum=currsum+temp->data;
	  if(temp->left)
	    Queue[rear++]=temp->left;
	  if(temp->right)
	    Queue[rear++]=temp->right;      
	}
}
  return maxlevel;
}


int main()
{
  int path[20];
  int len=0;

  root=create(1);
  root->left=create(2);
  root->right=create(3);
  root->left->left=create(4);
  root->left->right=create(5);
  root->right->left=create(6);
  root->right->right=create(7);

  
  root_to_leaf(root,path,len);

  printf("The level with the maximum sum is = %d \n",max_sum_level(root));

  return 0;

}
