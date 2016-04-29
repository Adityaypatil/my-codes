#include<stdio.h>
#include<stdlib.h>

int main()
{
  int val1=10,val2=10;
int result;

  asm ("add %%rdx,%%rcx\n\t"
       "mov %%rcx,%%rax"
       
       :"=a"(result)
       :"d"(val1),"c"(val2));

  printf("Result is :%d",result);
}

