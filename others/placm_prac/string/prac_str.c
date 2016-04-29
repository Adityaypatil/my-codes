#include<malloc.h>

void swap(char *s1,int start,int end)
{
	int i;
	for(i=end;i>=start;i--)
	{
		s1[i+1]=s1[i];
	}
}

int tell_mismatch(char *s1, char *s2, int n)
{
	int i;
	for(i=n;i>=0;i--)
	{
		if(s1[i]!=s2[i])
			return i;
	}
	return 0;
}

int check(char *s1,char *s2)
{
	int n1=strlen(s1)-1;
	int n2=strlen(s2)-1;
	int res=0,count=0;			
	char temp;	
	
	if(n1!=n2)
		return;

	while(1)
	{
		res=tell_mismatch(s1,s2,n1-1);
		if(res==0)
		{
			printf("%d ",count);
			return;
		}
		else
		{	
			count++;
			temp=s1[res];
			swap(s1,0,res-1);
			s1[0]=temp;

		}			

	}
}
int main()
{
	char s1[]="EACBD";
	char s2[]="EABCD";
	check(s1,s2);
	return 0;
}


