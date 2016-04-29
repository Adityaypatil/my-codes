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





struct node *reverse(struct node *temp)
{
  struct node *prev=NULL;
  struct node *curr=temp;
  struct node *nextnode;

  while(curr!=NULL)
    {
      nextnode=curr->next;
      curr->next=prev;
      prev=curr;
      curr=nextnode;
    }
  temp=prev;
  return temp;
}







int palindrome(struct node *head)
{ 
  
  int cnt1=0,cnt2=0;
  struct node *temp2=head;
  struct node *temp,*temp1;
  struct node *slowptr=head;
  struct node *fastptr=head;
  struct node *temp3;
  

while(fastptr!=NULL && fastptr->next!=NULL)
    {
      fastptr=fastptr->next->next;
      slowptr=slowptr->next;
   
    }
     

if(fastptr==NULL)
       {temp=slowptr;}
else
       temp=slowptr->next;


printf("2.  Middle ele =%d\n",slowptr->data);
 


 printf("3.  The first half of list is:");
while(temp2!=slowptr)
    {
      printf("%d-->",temp2->data);
      temp2=temp2->next;
      cnt1++;
     }
printf("\n");


  temp1=reverse(temp);
  temp3=temp1;


  printf("4. The second (reversed) half of list");
while(temp3!=NULL)
    {
      printf("%d-->",temp3->data);
      temp3=temp3->next;
      cnt2++;
    }
 printf("\n");

temp2=head;



if(cnt1 == cnt2)
  {
     while(temp2!=slowptr && temp1!=NULL)
    {
      
         if(temp2->data != temp1->data)
	  { 
          
	    return 0;
	  }

	  temp2=temp2->next;
	  temp1=temp1->next;
  	   
    
    }
  return 1;
 }

else
    {
      return 0;
    }

  
}

   




int main()
{int ans=-1;
  struct node *temp;

  head=insert(head,10);
  insert(head,20);
  insert(head,40);
  insert(head,20);
  insert(head,10);

  printf("The original linklist is:"); 
  display(head);

  

    ans=palindrome(head);
  if(ans==1)
    printf("5.  Yes the linklist is palindrome\n");
  else
    printf("5.  No not palindrome\n");
  
  return 0;
}
