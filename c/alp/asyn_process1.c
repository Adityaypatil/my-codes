
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	pid_t pid;
	int i,j,k;
	char buf[100];
	sprintf(buf,"\n%d is parent.....>>>>>",getpid());
	write(1,buf,strlen(buf));
	for(i=0;i<10;i++)
	{
		if((pid=fork())==0)
		{
				printf("\n%d child pid=%d",i,getpid());
				for(k=0;k>10000;k++);
				printf("\n%d child terminating pid=%d",i,getpid());
				exit(0);
		}
	}
	if(pid!=0)
	{
		for(i=0;i<10;i++)
		{
			sprintf(buf,"\n%d>>PARENT : %d terminated<<",i,wait(&j));
			write(1,buf,strlen(buf));
			printf("\n");
		}
		sprintf(buf,"\n%d terminated.....<<<<<",getpid());
		write(1,buf,strlen(buf));
	}
	
}

