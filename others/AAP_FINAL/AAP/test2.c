#include<stdio.h>

int main()
{
  int m,a=7;
  
  asm ("movl $1,%%eax\n\t"
      "l1: imull %%ecx,%%eax\n\t"
      "decl %%ecx\n\t"
      "jnz l1\n\t"
       :"=a"(m)
       :"c"(a));
    
printf("Result is %d\n",m);

}
