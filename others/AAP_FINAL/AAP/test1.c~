#include<stdio.h>


main()
{
	int data1=10;
	int data2=20;
	int result;

  asm("imull %%edx,%%ecx\n\t"
      "movl %%ecx,%%eax"
    :"=a"(result)
    :"d"(data1), "c"(data2));

printf("Result is %d\n",result);
}
