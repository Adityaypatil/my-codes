#include<stdio.h>
#include<stdlib.h>


struct node 
{
  int data;
  struct node *next;
}*head=NULL;




struct node *insert(struct node *head,int data)
{
  struct node *curr;
  struct node *newnode=(struct node *)malloc(sizeof(struct node));

  newnode->data=data;
  newnode->next=NULL;

  if(head==NULL)
    {
      head=newnode;
      curr=newnode;
    }
  else
    {
      curr->next=newnode;
      curr=newnode;
    }

  return head;
}






int KthElement(struct node *head,int n)
{
  int cnt=0;
  struct node *ref=head;
  struct node *main=head;


  while(cnt!=n)
    {
      cnt++;
      ref=ref->next;
    }

  while(ref!=NULL)
    {
      main=main->next;
      ref=ref->next;
    }

  return main->data;
}






int KthEle(struct node *head,int n)
{int cnt=0,pos=-1,i;

  struct node *temp=head;
  

  while(temp!=NULL)
    {
      cnt++;
     temp=temp->next;
    }
     
   
   pos=cnt-n+1;
   

  temp=head;
  for(i=1;i<pos;i++)
    {
       temp=temp->next;
    }
  return temp->data;
}




void display(struct node *head)
{
  struct node *temp=head;

  while(temp!=NULL)
    {
      printf("%d-->",temp->data);
      temp=temp->next;
    }
  printf("\n");
}


int main()
{ 
  int n=4,ele=-1,ele1=-1;

  
  head=insert(head,10);
  insert(head,20);
  insert(head,35);
  insert(head,45);
  insert(head,55);
  insert(head,22);
  insert(head,11);
  insert(head,99);


  printf("1.  The original link list is:");
  display(head);


  ele= KthElement(head,n);
   printf("\n2.(i)  The element at %dth position from end is =%d\n",n,ele);
   printf("\t(Using 2 pointer method)\n");



   ele1=KthEle(head,n);
   printf("\n2.(ii)  The element at %dth position from end is=%d\n",n,ele1);
   printf("\t(Using simple mathematical fromulla\n");    
   

   return 0;
}
