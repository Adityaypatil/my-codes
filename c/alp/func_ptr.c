#include<stdio.h>

void func(int x,int y)
{
	printf("\n %d !!\n",x+y);
}


int main()
{
	void (*foo)(int,int);
	
	foo = &func;
	foo(2,4);	
	return 0;
}
