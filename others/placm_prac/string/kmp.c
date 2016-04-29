#include<stdio.h>
#include<string.h>


void prefix(char *pattern,int m,int f[])
{
  int i=1,j=0;
  f[0]=0;
  while(i<m)
    {
      if(pattern[i]==pattern[j]){
	f[i]=j+1;
	i++;
	j++;
      }
      else if(j>0)
	j=f[j-1];
      else
	{
	  f[i]=0;
	  i++;
	}
    }
}
int kmp(char *text,int n,char *pattern,int m)
{
  int i=0,j=0,f[m];
  prefix(pattern,m,f);
  while(i<n)
    {
      if(text[i]==pattern[j])
	{
	  if(j==m-1)
	    return i-j;
      else
	{
	  i++;
	  j++;
	}
	}
  else if(j>0)
    {
      j=f[j-1];
    }
  else
    i++;
    }
  return -1;
}

int main()
{
  char *text="adityapatil";
  char *pattern="patil";
  int n=strlen(text);
  int m =strlen(pattern);

printf("Index :%d", kmp(text,n,pattern,m));

  return 0;
}
