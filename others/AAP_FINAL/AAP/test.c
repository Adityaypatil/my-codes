#include<stdio.h>
#include<stdlib.h>


main()
{
  int result;
  asm("movl $10,%eax\n\t" 
  "movl $20,%ebx\n\t"
  "addl %eax,%ebx\n\t"
  "movl %ebx,result");
  printf("Resul is %d",result);
}
