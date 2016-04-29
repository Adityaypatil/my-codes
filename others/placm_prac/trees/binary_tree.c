#include<malloc.h>
#include<stdbool.h>
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
int height(struct node *root)
{
	if(root ==NULL)
		return 0;
	else
	{
	int lht=height(root->left);
	int rht=height(root->right);
	
	if(lht >rht)
		return (lht+1);
	else
		return (rht+1);
	}

}
int count_nodes(struct node *node)
{
	if(node == NULL)
		return 0;
	else
		return count_nodes(node->left)+1+count_nodes(node->right);
}

int onechildnode(struct node *root)
{
	 if(root == NULL)
                return 0;
	else
		if(root->left==NULL && root->right!=NULL || root->right==NULL && root->left!=NULL  )
			{
				return 1;
			}
}

int noleafnode(struct node *root)
{
	if(root==NULL)
		return 0;
	else
		if(root->left==NULL && root->right==NULL)
			return 1;
	else
		return noleafnode(root->left)+noleafnode(root->right);

}
void findmax(struct node *root, int *min,int*max,int hd)
{
	if(root==NULL)
		return;
	if(hd < *min)
		*min=hd;
	else if (hd >*max)
		*max=hd;
		
	findmax(root->left,min,max,hd-1);
	findmax(root->right,min,max,hd+1);

}

void printVerticalLine(struct node *node, int line_no, int hd)
{
    // Base case
    if (node == NULL) return;
 
    // If this node is on the given line number
    if (hd == line_no)
       printf("%d\n",node->data);
 
    // Recur for left and right subtrees
    printVerticalLine(node->left, line_no, hd-1);
    printVerticalLine(node->right, line_no, hd+1);
}

int verticalprint(struct node *root)
{
	 int min = 0, max = 0;
	findmax(root, &min, &max, 0);
	int line_no; 
	for ( line_no = min; line_no <= max; line_no++)
    	{
        	printVerticalLine(root, line_no, 0);
       		 printf("\n");
    	}
}

void printlevel(struct node *root,int level, int ltr)
{
        if(root == NULL)
                return;
        else
        if(level == 0)
        printf("%d ",root->data);

        else if(level >1)
        {
                if(ltr)
                {
                        printlevel(root->left,level-1,ltr);
                        printlevel(root->right,level-1,ltr);
                }
                else
                {
                        printlevel(root->right,level-1,ltr);
                        printlevel(root->left,level-1,ltr);
                }

        }
}
void spiralprint(struct node *root)
{
	int h = height(root);

	int i;

	bool ltr =false;
	for(i=1;i<=h;i++)
	{
		printlevel(root,i,ltr);
		ltr= !ltr;
	}

}

int main()
{
	struct node *root=NULL;
	root=insert(1);
	root->left=insert(2);
	root->right=insert(3);
	root->left->left=insert(4);
	root->left->right=insert(5);
	root->right->left=insert(6);
	root->right->right=insert(7);
	root->left->right->left=insert(9);
	root->right->right->right=insert(10);
	display(root);
	
//	mirror(root);
	printf("\n");
	printf("%d",height(root));
	printf("\n%d\n",count_nodes(root));
	printf("%d\n",onechildnode(root));
	printf("%d\n",noleafnode(root));
	printf("Vertical order is :\n");
//	verticalprint(root);
	printf("Spiral Print:\n");
	spiralprint(root);
	return 0;
	
}
