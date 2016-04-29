#include<malloc.h>

void evenodd(char *str)
{
int even=0,odd=0,icnt=0;
	while(*str !='\0')	
	{
		if(*str == ' ' && *str != '\0')
			icnt++;
			str++;

		if(icnt%2==0)
		{
			even++;
			icnt=0;
		}
		if(icnt%2 !=0)
		{
			odd++;
			icnt=0;
		}
	str++;
	}
printf("Even %d, odd %d",even,odd);
}
int main()
{
	char str[30]="India is my country";
	evenodd(str);
	return 0;
}
