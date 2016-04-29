#include<stdio.h>
#include<stdlib.h>


struct node 
{

  int data;
  struct node *next;
}*Start=NULL;




struct node *insert(struct node *Start,int data)
{
  struct node *newnode,*curr;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next=NULL;
 
  if(Start==NULL)
    {
      Start=newnode;
      curr=newnode;
    }
  
  else
    {
      curr->next=newnode;
      curr=newnode;
    } 

  return Start;

}



void display(struct node *Start)
{
  struct node *new;

  new=Start;
  while(new!=NULL)
    {
      printf("%d--> ",new->data);
      new=new->next;
    }
  printf("NULL");
  printf("\n");
 
}





int FindLoop(struct node *start)
{ int loopexist=-1,cnt=0;
  struct node *fast,*slow;
  
  fast=start;
  slow=start;

  while(slow && fast)
{
  fast=fast->next;

  if(fast==slow)
    { loopexist=1;
      break;
    
    }
   if(fast==NULL)
     loopexist=0;

  fast=fast->next;
  if(fast==slow)
    {
      loopexist=1;
      break;
    }

  slow=slow->next;
}
 
  /*  if(loopexist)
    {
      slow=start;
      while(slow!=fast)
	{
	  fast=fast->next;
	  slow=slow->next;
	}
      return slow->data;
      }
  */
  
//to find length of loop

  cnt=1;
if(loopexist)
    {
      fast=fast->next;
      while(slow!=fast)
	{fast=fast->next;
	  cnt++;
	}
      return cnt;
    }
  




  return 0;
}













int main()
{
  int ans,ele;
  Start=insert(Start,105);
  insert(Start,201);
  insert(Start,301);
  insert(Start,40);
  insert(Start,50);

  printf("\n1. Linklist:");
  display(Start);

  Start->next->next->next->next=Start->next->next;
    
  ans=FindLoop(Start);
  if(ans) 
   {  printf("2. Loop is present\n");
     //printf("   The loop is detected at data element =%d\n",ans);
      printf("   Length of loop is=%d\n",ans);
   }
  else printf("2. Loop is Not present\n");

 
  


  return 0;

}
