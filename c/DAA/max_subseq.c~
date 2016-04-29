#include<stdio.h>
#include<stdlib.h>


int max_subseq(int arr[],int n);

int max_subseq(int arr[],int n)
{
int *marr,i,j,max=0;

marr=(int *)malloc(sizeof(int));

for(i=0;i<n;i++)
	{
		marr[i]=arr[i];
	}

for ( i = 1; i < n; i++ )
	for (j=0;j<i;j++)

	if(arr[i] > arr[j] && marr[i]<marr[j] +arr[i])
		marr[i]=marr[j]+arr[i];
		
	for ( i = 1; i < n; i++ )
		
		if(	max<marr[i])
		max=marr[i];

//free(marr);

return max;
}

int main()
{
int n=0;
int arr[]={1,101,2,3,100,4,5};
n= (sizeof(arr)/sizeof(arr[0]));
printf("Maximum sum of given sequence is: %d\n",max_subseq(arr,n));
return 0;
}
