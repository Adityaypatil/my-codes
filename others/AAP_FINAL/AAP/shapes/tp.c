#include<stdio.h>
void add(int a,int b)
{
	int ans;
	ans=a+b;
	printf("%d\n",ans);
}
void sub(int a,int b)
{
	int ans;
	ans=a-b;
	printf("%d\n",ans);
}
void mul(int a,int b)
{
	int ans;
	ans=a*b;
	printf("%d\n",ans);
}
void div(int a,int b)
{
	int ans;
	ans=a/b;
	printf("%d\n",ans);
}
main()
{
	
	add(10,20);
	sub(20,10);
	mul(30,2);
	div(30,2);
}

