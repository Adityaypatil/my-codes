#include<stdio.h>
#include<stdlib.h>

main()
{
  int arr[10]={1,5,2,8,4,-1};
  int add=0;
  asm(
        "xor %%rax,%%rbx\n\t"
        "lp1:\n\t"
        "cmp %%rbx,$-1\n\t"
	"je end\n\t"
        "add %%rbx,%%rcx\n\t"
	"mov %%rcx,%%rax\n\t"
	"add %rbx,8\n\t"
	"jmp lp1\n\t"
	"end:\n\t"	
	
	:"=a"(add)
	:"b"(arr));

  printf("addition=%d",add);

}
