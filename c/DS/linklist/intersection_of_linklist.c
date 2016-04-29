#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};


void display(struct node *start)
{
  struct node *temp=start;
  while(temp!=NULL)
    {
      printf("%d-->",temp->data);
      temp=temp->next;       


    }
  printf("NULL\n");

}



int getIntersection(struct node *head1,struct node *head2)
{
  int L1=0,L2=0,diff=0,i;
  struct node *curr1=head1;
 struct node *curr2=head2;


 while(curr1!=NULL)
   {
     L1++;
     curr1=curr1->next;
   }

 while(curr2!=NULL)
   {
    L2++;
    curr2=curr2->next;
    }

 if(L1<L2)
   {
     curr1=head2;
     curr2=head1;
     diff=L2-L1;
   }

else
  {
    curr1=head1;
    curr2=head2;
    diff=L1-L2;
  }

 for(i=0;i<diff;i++)
   
     curr1=curr1->next;

     while(curr1!=NULL && curr2!=NULL)
       {
	 if(curr1==curr2)
	   return curr1->data;
	 curr1=curr1->next;
	 curr2=curr2->next;


       }
   
     return NULL;
}


int main()
{
struct node* newNode;
  struct node* head1 =
    (struct node*) malloc(sizeof(struct node));
head1->data  = 10;

  struct node* head2 =
    (struct node*) malloc(sizeof(struct node));
head2->data  = 3;

newNode = (struct node*) malloc (sizeof(struct node));
newNode->data = 6;
head2->next = newNode;

newNode = (struct node*) malloc (sizeof(struct node));
newNode->data = 9;
head2->next->next = newNode;

newNode = (struct node*) malloc (sizeof(struct node));
newNode->data = 15;
head1->next = newNode;
head2->next->next->next  = newNode;

newNode = (struct node*) malloc (sizeof(struct node));
newNode->data = 30;
head1->next->next= newNode;

head1->next->next->next = NULL;



 display(head1);
 display(head2);

printf("\n The node of intersection is %d \n",
       getIntersection(head1, head2));

}  

