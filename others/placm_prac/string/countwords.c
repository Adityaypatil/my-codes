#include<malloc.h>


void word(char *str)
{
int count=0,a=0;
	while(*str !='\0')
		{
			if(*str == ' ')
				count++;		
			str++;
		}
	a=count+1;
printf("Count :%d",a);
}
int main()
{
	char str[]="India is my country";
	word(str);
	return 0;
}


