#include<stdio.h>

int global = 30;// mem allocates in data section

int main()
{
	int local =10;// mem in stack
	
	int *p=(int*)malloc(4);// mem gets allocate in heap
	*p=10;
	
	if(fork() == 0)
		{
			// change value in global and local
			local=11;
			global=31;
		
			*p=50;
			
			printf("Child with PID %d \n",getpid());
		printf("Value of local variable %d , global %d , heap %d of child process\n",local,global,*p);			
		}
	
	//if parent is running
	
		else
		{

		printf("Parent with PID %d \n",getpid());
		printf("Value of local variable %d , global %d , heap %d of parent process\n",local,global,*p);
	
		}
		return 0;
		
	
	

}

