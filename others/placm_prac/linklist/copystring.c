#include<malloc.h>

char* string(char *str,char *dest,int pos)
{
	char *dest1=dest;
	while(*str !='\0' && pos >0)
	{
		*dest=*str;
		str++;dest++;
		pos--;
	}
*dest='\0';
return dest1;
}

int main()
{
	char str[30]="india is my ";
	char dest[30]={'\0'};
	int pos=5;
	//scanf("%d",&pos);
	printf("String is: %s\n",string(str,dest,pos));
	return 0;
}
