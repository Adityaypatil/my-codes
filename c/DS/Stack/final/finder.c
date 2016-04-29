#include<stdio.h>
#include<stdlib.h>


struct node
{
  int data;
  struct node *next;
}*top=NULL,*top1=NULL;


struct node *push(struct node **top,int data)
{
  struct node *newnode=(struct node *)malloc(sizeof(struct node));

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


int isEmpty(struct node **t)
{
  if(*t==NULL)
    return 1;
  else
   return 0;
}



struct node *finder(struct node *top,struct node *top1,int data)
{
  push(&top,data);

  if(isEmpty(&top1) || ((top1)->data >=data))
       push(&top1,data);
       
    else
      push(&top1,((top1)->data));


}




void display(struct node **top)
{
  struct node *temp=*top;

  while(temp!=NULL)
    {
      printf("%d\t",temp->data);
      temp=temp->next;
    }
  printf("\n");
}


int  main()
{
  struct node *top1=NULL;
  
  /*  finder(top,top1,10);
  finder(top,top1,20);
  finder(top,top1,30);
  finder(top,top1,50);
  */
  
  push(&top,10);
  push(&top,22);
  push(&top,60);
  push(&top,1);
  push(&top,55);
  

  display(&top);
   display(&top1);

  // printf("popped element is =%d\n",pop(&top));

  return 0;
}














