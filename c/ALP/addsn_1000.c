#include<stdio.h>



int add1()
{
int i,sum;

for(i=0;i<50000;i++)
	{
		sum=sum+i;
//		printf("\nbye");
	}
printf("\nAddision is of 1 to 500	=> %d",sum);
}

int add2()
{
int i, sum1;

for(i=50001;i<100000;i++)
	{
		sum1=sum1+i;
//	printf("\nhi");
	}
printf("\n Addision is of 501 to 100o => %d\n",sum1);

}

int main()
{

add1();
add2();
}

