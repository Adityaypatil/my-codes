#include<stdio.h>

int count(int arr, int size)
{
int count[size];
int i,j;
	for(i=0;i<size;i++)
	{
	count[arr[i]]=count[arr[i]]+1;	
		}
	
		for(i=0;i<1024;i++)
			{
				for(j=0;j<count[i];j++)
					{
					printf("%d ",i);
					}
				}

}



int main()
{
int arr[]={11,2,3,4,11,2,1,1};

int size=sizeof(arr)/sizeof(arr[0]);

countsort(arr,size);


return 0;
}
