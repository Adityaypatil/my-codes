#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  int len1;
  char str1[100]="aditya patil,13143,mca";
  char temp[100];
  char comma=',';
  char com1;
  asm("movl $0,%%ebx\n\t"
      "movl $15,%%ecx\n\t"
      "repnz scasb\n\t"
      "subl %%esi,%%edi\n\t"
      "decl %%edi\n\t"
      "movl $4,%%eax\n\t"
      "movl $1,%%ebx\n\t"
      "movl %%esi,%%ecx\n\t"
      "movl %%edi,%%edx\n\t"
      "int $0x80\n\t"
      ::"a"(comma),"S"(str1),"D"(str1));
  printf("\n");
}
