#include<stdio.h>
#include<stdlib.h>




struct node
{
  int data;
  struct node *left;
  struct node *right;
}*root=NULL;




struct node *create(int data)
{
  struct node *newnode=(struct node *)malloc(sizeof(struct node));

  newnode->data=data;
  newnode->left=NULL;
  newnode->right=NULL;

  return newnode;

}


struct node *zigzag(struct node *root)
{int ltor=1;
  int top=-1,top1=-1;
  struct node *currstack[20];
  struct node *nextstack[20];
  struct node *temp=NULL;

 if (root == NULL)  return;   // NULL check

    // Create two stacks to store alternate levels
 //   stack<struct node*> s1;  // For levels to be printed from right to left
 // stack<struct node*> s2;  // For levels to be printed from left to right

    // Push first level to first stack 's1'
 top=top+1;
 currstack[top]=root; 
 // s1.push(root);

    // Keep ptinting while any of the stacks has some nodes
    while (top!=-1 || top1!=-1)
      {
        // Print nodes of current level from s1 and push nodes of
        // next level to s2
        while (top!=-1)
	  {
            temp = currstack[top];
	    top=top-1;;
            printf(" %d ",temp->data);

            // Note that is right is pushed before left
            if (temp->right)
	      {
               top1=top1+1;
	       nextstack[top1]=(temp->right);
	      }
            if (temp->left)
	      {
		top1=top1+1; 
             nextstack[top1]=(temp->left);
	      }

        // Print nodes of current level from s2 and push nodes of
        // next level to s1
        while (top1!=-1)
	  {
            temp1 = nextstack[top1];
	    top1=top1-1;
            printf(" %d ",temp->data);

            // Note that is left is pushed before right
            if (temp->left)
	      {
		top=top+1;
	      currstack[top]=(temp->left);
	      }
            if (temp->right)
	      {
	      top=top+1; 
              currstack[top]=(temp->right);
	      }
	  }
      }
  }



  /*
  top=top+1;
  currstack[top]=root;

  while(top!=-1)
    {
      temp=currstack[top];
      top=top-1;
   if(temp)
   {
      printf(" %d ",temp->data);
      if(ltor)
	{
	  if(temp->left)
	    {top1=top1+1;
	      nextstack[top1]=temp->left;
	    }
	  if(temp->right)
	    {top1=top1+1;
	      nextstack[top1]=temp->right;
	    }
	}
      else
	{
	  if(temp->right)
	    {
	      top1=top1+1;
	      nextstack[top1]=temp->right;
	    }
	  if(temp->left)
	    {top1=top1+1;
	      nextstack[top1]=temp->left;
	    }
	}
   }
   if(top==-1)
     {
       ltor=0;
     }
    

   if(ltor==0)
     {

  }    

}
  */


void display(struct node *root)
{
  if(root==NULL)
    return;

  display(root->left);
  printf("%d\t",root->data);
  display(root->right);
}



int main()
{

  root=create(50);
  root->left=create(40);
  root->right=create(60);
  root->left->right=create(44);
  root->right->right=create(80);

  display(root);

  zigzag(root);


  return 0;
}

