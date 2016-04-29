#include<stdio.h>
#include<stdlib.h>


struct node 
{
  int data;
  struct node *next;  
}*top=NULL;


struct node *push(struct node **top,int data)
{
  struct node *newnode=(struct node *)malloc(sizeof(struct node));

  newnode->data=data;
  newnode->next=*top;
  *top=newnode;

  //return newnode;
}


void display(struct node **top)
{

  struct node *new=*top;

  while(new!=NULL)
    {
      printf("%d\t",new->data);
      new=new->next;
    }


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





int main()
{
  push(&top,11);
  push(&top,15);
  push(&top,20);
  push(&top,22);

  display(&top);

  printf("\npopped element is=%d\n",pop(&top));
  return 0;
}
