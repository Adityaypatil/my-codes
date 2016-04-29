#include<stdio.h>
#include<stdlib.h>

main()
{
  int data1= 40,data2=50;
  int max;
  asm("cmp %%rdx,%%rcx\n\t"
      "jg m1\n\t"
      "mov %%rcx,%%rax\n\t"
      "m1:\n\t"
      "mov %%rdx,%%rax"
      ""
      :"=a"(max)
      :"d"(data1),"c"(data2));
  printf("maximum= %d",max);
}
