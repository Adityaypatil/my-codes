#include<malloc.h>

void btoy(char *str)
{
	while(*str !='\0')
		{
			if(*str >=98 && *str <=121)
			{
				printf("%c",*str);
					}
		str++;
		}	
printf("\n");
}



int main()
{
	char str[50]="abcd erdf yyzz";

	printf("%s\n",str);
	btoy(str);
	return 0;

}
