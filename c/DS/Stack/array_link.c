#include<stdio.h>
#include<stdlib.h>

struct node
{ int top;
  int capacity;
  int *array;
};



struct node *create(int cap)
{
  struct node *stk=(struct node *)malloc(sizeof(struct node *));

  stk->capacity=cap;
  stk->top=-1;
  stk->array=(int *)malloc(stk->capacity*sizeof(int));

  return stk;
}


void push(struct node *stk,int data)
{
  if(stk->top != (stk->capacity-1))
    {
      
      stk->array[++stk->top]=data;
    }
}


void display(struct node *s)
{
  int i=s->top;

  while(i!=-1)
    {
      printf("%d\t",s->array[i]);
      i--; 
   }
  printf("\n");

}




  int main()
  {

    struct node *stack1 = create(100);

    printf("\n1. Elements in stack are:\n");
    push(stack1,10);
    push(stack1,20);
    push(stack1,30);

    display(stack1);
  }
