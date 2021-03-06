#include<stdio.h>
#include<stdlib.h>


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


struct node *creat(struct node *head,int data)
{
  if(head==NULL)
    return newnode(data);

  if(data < head->data)
    newnode->left = creat(head->left,data);

  else if(data > head->data)
    newnode->right = creat(head->right,data);

  return head;

}


void inorder(struct node *head)
{
  if (head != NULL)
    {
      inorder(head->left);
      printf("%d ", head->data);
      inorder(head->right);
    }
}

int main()
{
  struct node *head=NULL;
  
  head=creat(head,1);
  creat(head,2);
  creat(head,3);

  inorder(head);
  return 0;
}
