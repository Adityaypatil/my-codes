#include<stdio.h>

int reverse_string(char *start,char *end)
{
	char temp;
	while(start<end)
	{
		temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}	
}

void check(char *str,int n)
{
	char *temp_begin=str;
	char *temp=str;	
	while(*temp)
	{
		temp++;
		if(*temp == ' ')
		{
			reverse_string(temp_begin,temp-1);
			temp_begin=temp+1;
		}
		else if(*temp == '\0')
		{
			reverse_string(temp_begin,temp-1);
		}	
		
	}
//	reverse_string(str,temp-1);
	printf("%s\n",str );
}

int main()
{
	char str[]="My name is Aditya";
	int n=sizeof(str)-1;
	check(str,n);
	return 0;
}

