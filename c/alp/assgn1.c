#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int pid,i,j,k;
	printf("\nParent id ==> %d\n",getpid());
	
	for(i=0;i<10;i++)
		{
			if(pid=fork()==0)	
			{
				printf("\n%d child pid==>%d ",i,getpid());	
				for(k=0;k>10000;k++)
				printf("\n%d child terminating pid ==>%d",i,getpid());
				break;
				
			}
				
		}
		if(pid !=0)
			{
			
			for(i=0;i<10;i++)
				
