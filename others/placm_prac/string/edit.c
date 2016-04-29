#include<stdio.h>

int isedit(char *s1,char*s2)
{
	int m=strlen(s1)-1;
	int n=strlen(s2)-1;
	printf("%d %d\n",m,n);
	if (abs(m-n)>1)
		return 0;
	int count=0;
	int i=0,j=0;
	while(i<m && j<n)	
	{
	if(s1[i]!=s2[j])
		{
		if(count==1)
			return 0;
		
		if(m>n)
			i++;
		else
		if(m<n)
			j++;
		else
		{
			i++;j++;
		}
			count++;
		}
	else
	{
		i++;j++;
	}
}
	if(i<m || j<n)
		count++;

	return count==1;
}

int main()
{
	char s1[]="gff";
	char s2[]="gffgg";
	if(isedit(s1,s2))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
