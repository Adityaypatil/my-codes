#include<stdio.h>
int data1=10;
int data2=20;
int result;
main()
{
 /* asm("imull %%edx,%%ecx\n\t"
      "movl %%ecx,%%eax"
    :"=a"(result)
    :"d"(data1), "c"(data2));
*/
	result = data1 * data2;
printf("Result is %d",result);
}
