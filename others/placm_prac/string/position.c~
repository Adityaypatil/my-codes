#include<malloc.h>

void printpos(char *str)
{
	int pos=3,count=1;
	while(*str !='\0')
		{
		if(*str == ' ')
			{
				count++;
			}
				
		else if(count == pos)
			{
				while(*str != ' ' && *str !='\0')
				{
					printf("%c",*str);
					str++;	
				}
		break;
			}	
		str++;
	}
}
int main()
{
        char str[30]="India is my country";
       printpos(str);
}
