#include<stdio.h>

main()
{
int pid;

pid = fork();

if (pid > 0)

	printf("\nParent process is %d\n",pid);
	
}
