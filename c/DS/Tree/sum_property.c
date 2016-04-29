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
  if(root==NULL)
    return 0;
 
  return(sum(root->left)+root->data+sum(root->right));  
}

int isSum(struct node *root)
{int ls,rs;
  if((root == NULL) ||(root->left==NULL && root->right==NULL))
    return 1;
  else
    {
      ls=sum(root->left);
      rs=sum(root->right);

      if((root->data == ls+rs)&&
	 isSum(root->left)&&
	  isSum(root->right))
	 {return 1;}
	 else
	   return 0;     
 

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



int main()
{
  int ans=-1;
  root=create(26);
  root->left=create(10);
  root->right=create(3);
  root->left->left=create(4);
  root->left->right=create(6);
  root->right->right=create(3);
  

  display(root);

  ans=isSum(root);
    if(ans==1)
      printf("Yes  sum tree\n");
    else
      printf("No\n");



  return 0;
}

