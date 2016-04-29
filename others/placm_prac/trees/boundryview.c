#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

  struct node *creat(int data)
  {
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
  }

void inorder(struct node *node)
{
  if(node !=NULL)
    {
      inorder(node->left);
      printf("%d ",node->data);
      inorder(node->right);
    }
}

int topleft(struct node *node)
{
if(node && node->left==NULL && node->right==NULL)
	return NULL;

else
	{
	printf("%d ",node->data);
	topleft(node->left);
	}
}

int topright(struct node *node)
{
if(node && node->left==NULL&& node->right==NULL)
	return NULL ;
else
	{
	
	topright(node->right);
	printf("%d ", node->data);
	}	
}

int topview(struct node *node)
{
if(!node)
	return NULL;
	
	else
	{
		printf("%d ",node->data);

		topleft(node->left);
		topright(node->right);
	}
}

int leaf(struct node *node)
{
if(!node)
	return NULL;
	
	else if(node)
		{
			leaf(node->left);
			if(!node->left && !node->right)
				printf("%d ",node->data);
			leaf(node->right);
		
		}	


}
int boundry(struct node *node)
{
if(!node)
	return NULL;
	
	else
	{
		printf("%d ",node->data);

		topleft(node->left);
	
		leaf(node->left);
		leaf(node->right);	
	
		topright(node->right);
	}


}


  int main()
  {
    struct node *node=NULL;
    node=creat(10);
    node->left=creat(50);
    node->left->left=creat(30);
    node->right=creat(60);
    node->right->left=creat(80);
    node->right->right=creat(70);
    inorder(node);
    printf("\n");
    //topview(node);
   boundry(node);
   
   
    return 0;
  }
