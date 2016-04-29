#include<malloc.h>


void countvalues(char *str)
{
int small=0,capital=0,integer=0;
	while(*str !='\0')
	{
		if(*str >=98 && *str <=121 )
				small++;
			
		if(*str >=48 && *str <=57)
				integer++;

		if(*str >=65 && *str <=90)
				capital++;
	str++;
	}
printf(" small :%d, captials : %d ,INtegers : %d ",small,capital,integer);
			
}		
int main()
{	
	char str[ 50]="abcDE 5Glm1 O";
	countvalues(str);
	return 0;	
}
