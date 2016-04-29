#include<malloc.h>

void removespace(char *str) // Function of removing space from string.
{
	int i,count=0;
	for(i=0;str[i];i++)
		{
		if(str[i]!=' ')
			{
			str[count++]=str[i];
			}
		}

	str[count]='\0';	
}
int main()
{
	char s[]="g eeks for g eeks";
	removespace(s);
	printf("%s\n",s);
	return 0;
}
