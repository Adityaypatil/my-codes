#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
}*top=NULL;


void push(struct node **top,int data)
{
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  
  

  if(!newnode) return NULL;
  newnode->data=data;
      newnode->next=*top;
      *top=newnode;
    
      
}


int pop(struct node **top)
{
  int ele;
  struct node *temp;

  temp=*top;
  *top=(*top)->next;
  ele=temp->data;
  free(temp);

  return ele;

}



void display(struct node *top)
{struct node *temp=top;

  
  while(temp!=NULL)
    {
      printf("%d-->",temp->data);
      temp=temp->next;
    }
}


int main()
{

  push(&top,10);
  push(&top,20);
  push(&top,30);

  display(top);
  
 
  printf("\nPopped element =%d\n",pop(&top));

}

