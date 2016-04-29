#include<stdio.h>

unsigned binary(int no)
{
	unsigned i;
	for(i=1<<31 ; i> 0;i=i/ 2)
	{
	(no & i) ? printf("1") :printf("0");
		
		}



}



int main()
{

binary(5);

return 0;
}
