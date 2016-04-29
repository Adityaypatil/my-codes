#include<stdio.h>
#include<stdlib.h>

struct Queue
{
  struct node *data;
  struct Queue *next;
}*front=NULL,*rear=NULL;


int isEmpty(struct Queue *Queue)
{
  return(front==NULL);  
}



struct Queue *createQueue(struct Queue *Queue,struct node *data)
{
  struct Queue *newnode=(struct Queue *)malloc(sizeof(struct Queue));

  newnode->data=data;
  newnode->next=NULL;


  if(rear==NULL && front==NULL)
    {
      rear=newnode;
      front=newnode; 
   }
  else
    {
      rear->next=newnode;
      rear=newnode;
    }

  return Queue;

}
 


struct node *DeQueue(struct Queue *Queue)
{
  struct node *ele;
 
  if(!isEmpty(Queue))
    {
      ele=front->data;
      Queue=front->next;
      return ele;
    }
  return NULL;
      

}



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




/*
void printlevelorder(struct node *tree)
{
  struct queue *Q=createQueue();
  If (!tree) return NULL;
  Enqueue(Q,root)
    while(!IsEmptyQueue(Q))
      {
	struct node *temp=DeQueue(Q);
	printf("%d",Q->data);
	If temp->left EnQueue(Q, temp->left);
	If temp->right EnQueue(Q, temp->right);
      }
  
  DeleteQueue(Q);
}
*/

void  *levelorder(struct node *root)
{
  struct Queue *q=createQueue(q,root);
  struct node *temp=NULL;
  
  while(!isEmpty(q))
    {
          temp=DeQueue(q);
      printf("%d\t",temp->data);

      if(temp->left)
	createQueue(q,temp->left);
      if(temp->right)
	createQueue(q,temp->right);
    }
}


/*
struct node *display(struct node *root)
{
  if(root==NULL)
    return ;
  else
    {
      display(root->left);
      printf("%d\t",root->data);
      display(root->right);
    }
}
*/


int main()
{struct Queue *Queue=NULL;
  root=create(10);
  root->left=create(20);
  root->right=create(30);
  root->left->left=create(40);
  root->left->right=create(25);
  root->right->left=create(44);
  root->right->right=create(56);

  levelorder(root);
			  
  


  return 0;
}
