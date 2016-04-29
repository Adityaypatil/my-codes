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



int main()
{


struct node *Queue[20];
struct node *temp;
int front=0,rear=0;

root=create(10);
root->left=create(20);
root->left->left=create(70);
root->left->left->left=create(40);
root->right=create(55);
root->right->right=create(77);

Queue[rear++]=root;
while(front<rear && rear<20)
{
  temp=Queue[front++];
  printf("%d\t",temp->data);

if(temp->left)
Queue[rear++]=temp->left;

if(temp->right)
Queue[rear++]=temp->right;

}

return 0;
}		
