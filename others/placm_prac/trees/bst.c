#include<malloc.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newnode(int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node *creat(struct node *root,int data)
{
	if(root==NULL)
		return newnode(data);

	if(data < root->data)
		root->left=creat(root->left,data);
	
	else if (data > root->data)
		root->right=creat(root->right,data);

	return root;
}

void inorder(struct node *root)
{
	if(root !=NULL)
	{
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	}
}

struct node *findmin(struct node *root)
{
    struct node *current = root;
 
    /* loop down to find the leftmost leaf */
    while (root->right != NULL)
	        root = root->right;
 
    return root;
}

struct node *deletenode(struct node *root,int data)
{
	if(root==NULL)
		return root;
	
	else if(data < root->data)
		root->left= deletenode(root->left,data);
	
	else if (data > root->data)
		root->right=deletenode(root->right,data);
	
	// for no child nodes
	else if(root->left ==NULL && root->right==NULL )
	{
			free (root);
			root=NULL;
		
	}
	// for one child
	else if(root->left==NULL)
	{
		struct node *temp=root;
		root=root->right;
		free(temp);
		
	}
	else if(root->right==NULL)
	{
		struct node *temp=root;
		root=root->left;
		free(temp);
		
	}
	// for more than one child
	else{
		struct node *temp= findmin(root->right);
		root->data=temp->data;
		root->right=deletenode(root->right,temp->data);
	}
return root;
}

int main()
{
	struct node *root=NULL;
	root=creat(root,5);
	creat(root,2);
	creat(root,3);
	creat(root,6);
	creat(root,1);
	creat(root,7);
	inorder(root);
	deletenode(root,2);
	printf("\n");
	inorder(root);
	return 0;
}
