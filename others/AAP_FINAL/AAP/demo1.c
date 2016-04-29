#include<stdio.h>
#include<stdlib.h>
main()
{
  printf("Using exit function");
  asm ("movl $1, %eax\n\t""movl $0,%ebx\n\t""int $0x80");
}
