/*
This program demonstates working of forrk.

fork() is used to create new process.

This function returns twise. It returns 0 to child and return PID of child process to parent.
*/

#include<stdio.h>

int main()
{
	// If child is running
	if(fork() == 0)
	{
		printf("Child with PID %d\n",getpid());
		
	}
	// If parent is running
	else
	{
		printf("Parent with PID %d\n",getpid());
	}
	return 0;
}
