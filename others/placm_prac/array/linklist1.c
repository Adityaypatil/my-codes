#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

void creat(struct node **root,int data)
{
	struct node *temp,*tail;
	temp=(struct node *)malloc(sizeof(struct node ));
	temp->data=data;
	temp->next=NULL;

	if(*root==NULL)
	{
	*root=temp;
	tail=temp;
	}
	else
	{
	tail->next=temp;
	tail=temp;
	}
}

void display(struct node *root)
{
while(root!=NULL)
	{
	printf("%d",root->data);
	root=root->next;
	}
}
int main()
{
	struct node *root=NULL;
	int arr[]={1,2,3,4,5,6},i;
	int n=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<n;i++)
	{
	creat(&root,arr[i]);	
	}
	display(root);

	return 0;
}
