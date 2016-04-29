#include<malloc.h>

struct node
{
	int data;
	struct node *left,*right;
};

struct node *creat(int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;

return temp;
}

void inorder(struct node *root)
{
	if(root !=NULL)
	{
	inorder(root->left);
	printf("%d ->",root->data);
	inorder(root->right);
	}
}
int maxdepth(struct node *root)
{
	if (root==NULL)
		return 0;
	else
	{
	int l=maxdepth(root->left);
	int r=maxdepth(root->right);

	if(l >r)
		return (l+1);
	else
		return (r+1);
	}	
}


int main()
{
	struct node *root=NULL;
	root=creat(10);
	root->left=creat(4);
	root->right=creat(3);
	root->left->left=creat(1);
	inorder(root);
	printf("\nDepth is :%d",maxdepth(root));
	return 0;
}
