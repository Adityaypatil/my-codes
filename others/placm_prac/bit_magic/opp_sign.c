#include<stdio.h>
#include<stdbool.h>

bool checksign(int x,int y)
{

return ((x^y <0));
}



int main()
{
int no1,no2;

scanf("%d",&no1);
scanf("%d",&no2);

if (checksign(no1,no2)==true)
	printf("SIgn are opposite!\n");
else
	printf("Signs are same!");

return 0;
}
