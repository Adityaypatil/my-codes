#include<stdio.h>
#include<stdlib.h>




struct node
{
  int data;
  struct node *next;
}*top=NULL;



void push(struct node **top,int data)
{

  struct node *newnode=(struct node *)malloc(sizeof(struct node ));

  if(!newnode) return NULL;

  newnode->data=data;
  newnode->next=*top;
  *top=newnode;
}



struct node *finder(struct node **old,struct node **new,int data)
{
  

  push(&old,data);
  // if((Isempty(&new)) || (new->data >=data))
    push(&new,data);
    //else
    push(&new,top1->data);
}



int pop(struct node **top)
{int ele;
  struct node *temp;

  temp=*top;
  *top=(*top)->next;
  ele=temp->data;
  free(temp);

  return ele;
}



void display(struct node *top)
{
  struct node *temp=top;

  while(temp!=NULL)
    {
      printf("%d\t",temp->data);
      temp=temp->next;

    }
  printf("\n");
}



int main()
{

  finder(&top,&top1,5);
  finder(&top,&top1,2);
  finder(&top,&top1,7);
  /*  push(&top,5);
  push(&top,2);
  push(&top,7);
  push(&top,2);
  push(&top,1);
  push(&top,1);
  push(&top,4);
  */
  display(top);

  return 0;
}
