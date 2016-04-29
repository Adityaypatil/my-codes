#include<malloc.h>

void len(char *str)
{
	int len;
	while(*str !='\0')
	{
	len++;
	str++;
	}
printf("%d",len);
}

int main()
{
	char *str="India is my";
	len(str);
	return 0;
}
