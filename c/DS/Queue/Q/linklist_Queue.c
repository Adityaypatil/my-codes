#include<stdio.h>
#include<stdlib.h>


struct node
{
  int data;
  struct node *next;
}*front=NULL,*rear=NULL;


int isEmpty(struct node *Queue)
{
  if(front==NULL || front==rear)
    return 1;
  else
    return 0;  
}


struct node *create(struct node *Queue,int data)
{
  struct node *newnode=(struct node *)malloc(sizeof(struct node));

  newnode->data=data;
  newnode->next=NULL;


  if(rear==NULL)
    {
      rear=newnode;
      front=newnode; 
   }
  else
    {
      rear->next=newnode;
      rear=newnode;
    }

  return Queue;

}
 


int DeQueue(struct node *Queue)
{
  int ele;
  while(front!=rear)
    {
      ele=front->data;
      front=front->next;
      return ele;
    }
}




void display(struct node *Queue)
{
  struct node *temp=front;
  while(temp!=rear->next)
    {
      printf("%d\t",temp->data);
      temp=temp->next;
    }
}

int main()
{
  struct node *Queue=NULL;

  Queue=create(Queue,10);
  create(Queue,20);
  create(Queue,30);

  printf("front=%d\n",front->data);
  printf("rear=%d\n",rear->data);
  display(Queue);


  printf("deleted =%d\n",DeQueue(Queue));

  display(Queue);
  printf("front=%d",front->data);
  printf("rear=%d",rear->data);


  return 0;
 }
