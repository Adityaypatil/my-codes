#include<stdio.h>    |
      "l:"                                                             |
      "incl %%ebx\n\t"                                                 |
      "jmp inner\n\t"                                          

int main()
{
  int array[6] = {2,1,5,3,9,4};
  int i,res=0,data=0;
  int arr[6];
  asm("xorl %%ecx,%%ecx\n\t"
      "xorl %%eax,%%eax\n\t"
      "xorl %%ebx,%%ebx\n\t"
      "movl $-1,%%edx\n\t"
      "outer:"
      "cmpl $5,%%ecx\n\t"
      "je end\n\t"
      "inner:"
      "incl %%ecx\n\t"
      "incl %%edx\n\t"
      "cmpl $4,%%ebx\n\t"
      "je outer\n\t"
      "addl %%edx,%%edi\n\t"
      "addl (%%edi),%%esi\n\t"
      "movl $4,%%eax\n\t"
      "addl %%eax,%%edi\n\t"
      "cmpl (%%edi),%%esi\n\t"
      "jl swap\n\t"
      "l:"
      "incl %%ebx\n\t"
      "jmp inner\n\t"
      "swap:"
      "pushl %%ecx\n\t"
      "movl (%%edi),%%ecx\n\t"
      "movl %%esi,%%edi\n\t"
      "movl %%ecx,%%esi\n\t"
      "popl %%ecx\n\t"
      "jmp l\n\t"
      "end:\n\t"
      ::"D"(arr),"s"(res));
       
      for(i=0;i<5;i++)
	{
	  data=(i*4);
	  asm("addl %%eax,%%esi\n\t"
	      "movl (%%edi),%%edi\n\t"
	    :"=D"(res)
	    :"s"(array),"a"(data));
	     printf("%d\n",res);
      }
}
