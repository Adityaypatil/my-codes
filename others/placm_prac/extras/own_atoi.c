#include<stdio.h>
#include<stdlib.h>

int myatoi(char *str)
{
int res=0,i;

for(i=0;str[i]!=0;i++)
		res=res*10 + str[i]	- '0';	
	return res;
}



int main()
{
char str[]="8890";
int val=myatoi(str);
printf("\n%d",val);

return 0;
}
