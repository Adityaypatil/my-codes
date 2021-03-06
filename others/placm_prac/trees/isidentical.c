#include<malloc.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node * insert(int value)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->left=temp->right=NULL;
	return temp;
}	

void display(struct node *root)
{	
	while(root)
	{		
		display(root->left);
		printf("%d ",root->data);
		display(root->right);
		break;
	}
}

void mirror(struct node *node)
{
	  if (node==NULL) 
   		 return;  
  	else
  	{
    		struct node* temp;
     
  		  /* do the subtrees */
   		 mirror(node->left);
    		 mirror(node->right);
 
		    /* swap the pointers in this node */
  	   temp  = node->left;
   	   node->left  = node->right;
 	   node->right = temp;
	  }
		
//	display(node);
}

int isidentical(struct node *root, struct node *root1)
{
	if(root==NULL && root1==NULL)
		return 1;
	
	if (root!=NULL && root1!=NULL)
    	{
        return
        (
            root->data == root1->data &&
            isidentical(root->left, root1->left) &&
            isidentical(root->right, root1->right)
        );
    	}
	return 0;
}
	
int main()
{
	struct node *root=NULL,*root1=NULL;
	root=insert(1);
	root->left=insert(2);
	root->right=insert(3);
	root->left->left=insert(4);
	root->left->right=insert(5);
	root->right->left=insert(6);
	root->right->right=insert(7);
	display(root);
	
	printf("\n");
	
	root1=insert(1);
	root1->left=insert(2);
	root1->right=insert(3);
	root1->left->left=insert(4);
	root1->left->right=insert(5);
	root1->right->left=insert(9);
	root1->right->right=insert(7);
	display(root1);
	
	if(isidentical(root,root1))	
		printf("\nBoth are identical");
	else
		printf("\nNOt identical\n");
	//mirror(root);
	printf("\n");
	//display(root);
	return 0;
	
}
