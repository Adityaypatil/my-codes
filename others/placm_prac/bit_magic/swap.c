#include<stdio.h>


unsigned test(char c)
{

unsigned char c1,c2;

c1=c & 0X0F;
c2=c & 0XF0;

c1= c1 << 4;
c2= c2>> 4;
 return(c2|c1);

}

int main()
{
char c=12;

printf("Swap value is %x",test(c));

return 0;
}
