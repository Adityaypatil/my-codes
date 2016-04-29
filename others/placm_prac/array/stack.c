#include<malloc.h>
#define MAX 100
int stack[MAX];
int top=-1;

int isfull()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}	

void push(int value)
{
	if(isfull())
		printf("Full \n");
	else
	{
		top++;
		stack[top]=value;
		printf("Pushed Element is = %d\n",value);
	}
}

int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
	

void pop()
{
	if(isempty())
		printf("Empty Stack\n");
	else
	{
		printf("Popped Element is = %d \n",stack[top]);
		top--;
	}
}

void display()
{
	int i;
	for(i=0;i<=top;i++)
		printf("%d ",stack[i]);
}		
int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	pop();
	pop();
	pop();
	push(5);
	push(6);
	display();
	return 0;
}

