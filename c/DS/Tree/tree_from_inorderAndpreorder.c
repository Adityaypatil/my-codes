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
  else
    {
      display(root->left);
      printf(" %d ",root->data);
	     display(root->right);
	     }
    }

int search(int data,int ino[],int strt,int end) 
{
  int i;
  for(i=strt;i<end;i++)
    {
      if(ino[i]==data)
	return i;
    }
}

struct node *build(int ino[],int pre[],int strt,int end)
{
  int inindex;
static  int  preindex=0;

  if(strt>end)
    return NULL;

  struct node *new=create(pre[preindex++]);

  if(strt==end)
    return new;
 
  inindex=search(new->data,ino,strt,end);
 

  new->left=build(ino,pre,strt,inindex-1);
  new->right=build(ino,pre,inindex+1,end);


  return new;
}




int main()
{
  int pre[]={1,2,4,5,3,6,7};
  int ino[]={4,2,5,1,6,3,7};

  int len=sizeof(ino)/sizeof(ino[0]);


  root=build(ino,pre,0,len-1);
  display(root);
  return 0;
}
