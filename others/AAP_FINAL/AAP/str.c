#include<stdio.h>

int main()
{
char input [40]= {"Hello adv. assembly language.\n"};
char output[40];
int length = 29;

asm volatile("cld\n\t"
		" rep movsb"
		:
		:"S"(input),"D"(output),"c"(length));

	printf("%s",output);
}
