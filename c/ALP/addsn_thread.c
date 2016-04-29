////////////////////////////////////////////////////////////////////////////////
//
//	 Addition of 1 to 1000 numbers using threads.						
//
///////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */

int sum1,sum;

void* add1()						// function which adds 1 to 500 numbers.
{
	int i;
	for(i=0;i<500;i++)
		{	
			sum1=sum1+i;
	
		}

	printf("\nThread1--> Addition of  0 to 500 => %d",sum1);
	
	pthread_exit(0);
}


void* add2()						// function which adds 501 to 1000 numbers.			
{

	int i;

	for(i=501;i<1000;i++)
	
		{	
			sum=sum+i;

		}

	printf("\nThread2--> Addition of 501 to 1000 => %d",sum);

	pthread_exit(0);
}


int main()
{

  pthread_t thread1,thread2;

	 pthread_create(&thread1,NULL,(void *)add1,NULL);	// threads create
	 pthread_create(&thread2,NULL,(void *)add2,NULL);	

	 pthread_join(thread1, NULL);				// threads join
	 pthread_join(thread2, NULL);
              

  printf("\n\nTotal addition is =>%d\n",sum+sum1); // total answer return

exit(0);


}
