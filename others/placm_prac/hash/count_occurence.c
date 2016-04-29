#include<malloc.h>

void check(char *a, int n)
{
	int hash[26]={0},i;
	
	for(i=0;i<n;i++)
	{
		hash[a[i]-97]++;
	}
	
	for(i=0;i<26;i++)
		printf("%d ",hash[i]);
}	

int main()
{	
	char a[]="abcda";
	int n=sizeof(a)-1;
	check(a,n);
	return 0;
}
	
