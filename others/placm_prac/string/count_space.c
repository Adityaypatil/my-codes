#include<stdio.h>


void space(char *str)
{
int count;
	while(*str !='\0')
	{
		if(*str == ' ')
			count++;	
	str++;
	}
printf("%d",count);
}
int main()
{
	char str[20]={"hi i am adi"};
	space(str);
	return 0;
}
