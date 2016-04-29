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
      printf("%d-",node->data);
      inorder(node->right);
    }
}

int identicalTrees(struct node *node,struct node *node2)
{
	if ((node ==NULL) && (node2==NULL))
		return 1;
	
	if(node !=NULL && node2 !=NULL)
		{
			return 
			(
			node->data=node2->data && identicalTrees(node->left,node2->left) && identicalTrees(node->right,node2->right)
			);
		}	

}

  int main()
  {
    struct node *node=NULL;
   struct node *node2=NULL;
    node=creat(10);
    node->left=creat(50);
    node->left->left=creat(30);
    node->right=creat(60);
    
    node2=creat(10);
    node2->left=creat(50);
    node2->left->left=creat(30);
    node2->right=creat(60);
    
    inorder(node);
   inorder(node2);
   
    if(identicalTrees(node, node2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");
 
    return 0;
  }
