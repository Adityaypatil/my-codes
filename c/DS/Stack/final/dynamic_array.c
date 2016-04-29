#include<stdio.H>
#include<stdlib.h>

struct stack
{
  int capacity;
  int top
  int *arr;
};


struct stack *create(int capacity)
{
  struct stack *s=(struct stack *)malloc(sizeof(struct stack));
  s->capacity=capacity;
  s->top=-1;
  s->arr=(int *)malloc(s->capacity * sizeof(int));
  return s;
}


void push(int data)
{
  s->arr[s->top]=s->arr[(s->top)++];
  s->arr[s->top]=data;
}

int pop()
{
  int ele;
  ele=s->arr[s->top];
  s->arr[(s->top)--];
  return ele;
}



int main()
{
  cretae(
