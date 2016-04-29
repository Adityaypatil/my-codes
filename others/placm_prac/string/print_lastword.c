#include<malloc.h>

void print(char *str)
{
	
	char *pos1=str;
        while(*str !='\0')
        {
         if(*str == ' ')     
        	{
			pos1=str;
		}
	str++;
        }
	
	while(*pos1 !='\0')
	{
		printf("%c",*pos1);
		pos1++;
	}
}
int main()
{
        char str[30]="India is my country";
        print(str);
return 0;
}
