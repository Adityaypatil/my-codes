#include<stdio.h>
#include<malloc.h>

void connectRecur(struct node* root);

struct node
{
  int data;
  struct node *left;
  struct node *right;
  struct node *rightpointer;	
};

  struct node *creat(int data)
  {
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->rightpointer=NULL;

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

void connect(struct node *root)
  {
    root->rightpointer=NULL;
    
    connectRecur(root);
  
  }
  
void connectRecur(struct node *root)
{
    if(!root)
         return;
         
    if(root->left)
        root->left->rightpointer=root->right;
        
       if (root->right)
    		root->right->nextpoiter = (root->nextpointer)? root->nextpointer->left: NULL;
 
    connectRecur(root->left);
    connectRecur(root->right);
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
    connect(node);
   
   printf("Following are populated nextRight pointers in the tree "
          "(-1 is printed if there is no nextRight) \n");
 
  printf("nextRight of %d is %d \n", node->data,
         node->rightpointer? node->rightpointer->data: -1);
 
  printf("nextRight of %d is %d \n", node->left->data,
        node->left->rightpointer? node->left->rightpointer->data: -1);
 
  printf("nextRight of %d is %d \n", node->right->data,
        node->right->rightpointer? node->right->rightpointer->data: -1);
 
  printf("nextRight of %d is %d \n", node->left->left->data,
        node->left->left->rightpointer? node->left->left->rightpointer->data: -1);
   
    return 0;
  }
