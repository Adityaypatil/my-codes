#include<stdio.h>
#include<stdlib.h>

struct stack
{
  int top;
  int *array;
  int capacity;
};

struct stack *creatstack(int capacity)
{
  struct stack *s=(struct stack *)malloc(sizeof(struct stack));
  if(!s)
    return NULL;
  s->top=-1;
  s->capacity=capacity;
  s->array=malloc(s->capacity *sizeof(int));

  if(!s->array)
    return NULL;

  return s;
  
}


int isstackempty(struct stack *s)
{
  return ((s->top==-1));
}
int isstackfull(struct stack *s)
{
  return (s->top==(s->capacity-1));
}

void push(struct stack *s,int data)
{
  if(isstackfull(s))
    printf("\nOverflow");
  else
    s->array[++s->top]=data;

}
void pop(struct stack *s)
{
  if(isstackempty(s))
    printf("\nEmpty");
  else
    s->array[s->top--];

}
void display(struct stack *s)
{
  
    printf("%d ",s->array[s->top]);
}
int main()
{
  struct stack *s=NULL;
  s=creatstack(4);
  push(s,10);
  push(s,20);
  push(s,30);
  pop(s);
  display(s);
 return 0;
}
