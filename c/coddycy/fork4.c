#include<stdio.h>

main()
{
int pid;
pid =fork();
if(pid == 0)
	printf("\nChild porcess \n");
}
