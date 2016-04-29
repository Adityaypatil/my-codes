#include<stdio.h>
#include<stdlib.h>

struct queue
{
  int front,rear;
  int capacity;
  int *array;
};

struct queue *creat(int capacity)
{
  struct queue *q=(struct queue *)malloc(sizeof(struct queue));
  q->front=-1;
  q->rear=-1;
  q->capacity=capacity;
  q->array=(int *)malloc(sizeof(int));
  
  if(!q->array)
    return NULL;

  return q;
}


int isfull(struct queue *q)
{
  return ((q->rear+1)%(q->capacity)==q->front);

}

void enque(struct queue *q,int data)
{
  if(isfull(q))
    printf("Overflow\n");
  else
    {
      q->rear=(q->rear+1) % q->capacity;
      q->array[q->rear]=data;
      
      if (q->front== -1)
	q->front=q->rear;
    }

}
int isempty(struct queue *q)
{
  return (q->front==-1);
}

int dequeue(struct queue *q)
{
  int data;
  if(isempty(q))
    printf("empty");
  else
    {
      data=q->array[q->front];
      if(q->front == q->rear)
	q->front =q->rear=-1;
      else
	q->front=(q->front+1)%q->capacity;
    }
 return data;
}
int display(struct queue *q)
{
  printf("%d",q->array[q->rear]);
}

int main()
{
  struct queue *q=NULL;
  q=creat(5);
  enque(q,10);
  enque(q,20);
  enque(q,30);
  display(q);
  printf("deleted data:%d",dequeue(q));
  return 0;
}
