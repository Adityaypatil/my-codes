#include<malloc.h>

int s[10];
int top=-1;

int push(char *s)
{
	s[]=s;
	top++;
}



void check(char *s1,char *s2,int n1,int n2)
{
	int i;
	for(i=n1;n1>0;n1--)
		{
			push(s[i]);
		}

}
int main()
{
	char s1="a/b/c";
	char s2="a/b/d";
	int n1=strlen(s1)-1;
	int n2=strlen(s2)-1;
	check(s1,s2,n1,n2);
	return 0;
}
