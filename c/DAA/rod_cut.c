#include<stdio.h>





int maximum(int a,int b)
{

return (a>b)?a:b;
}

int rod(int array[],int n)
{
int maximum_val=0,i=0;

for(i=0;i<n;i++)
	{
		maximum_val=maximum(maximum_val,array[i]+rod(array,n-i-1));
		
		return maximum_val;
	}

}

int main()
{
int arr[]={1,5,8,9,10,17,20};

int size=0;

size=sizeof(arr)/sizeof(arr[0]);
	
printf("Max value:%d\n",rod(arr,size));

return 0;
}
