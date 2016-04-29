#include<malloc.h>

void merge(int [], int, int, int);

void partition(int arr[],int low ,int heigh)
{
	int mid=0;
	if(low < heigh)
	{
		mid=(low+heigh)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,heigh);
		merge(arr,low,mid,heigh);	
	}

}

void merge(int arr[],int low,int mid,int heigh)
{	
	int k, temp[50],i=low,l=low,m=mid+1;	
	while((l<=mid)&&(m<=heigh))
	{
		if(arr[l]<arr[m])
		{
			temp[i]=arr[l];
			l++;
		}	
		else
		{
			temp[i]=arr[m];
			m++;
		}
		i++;	
	}
    if (l > mid)
    {
        for (k = m; k <= heigh; k++)
        {
            temp[i] = arr[k];
            i++;
        }
    }
    else
    {
        for (k = l; k <= mid; k++)
        {
             temp[i] = arr[k];
             i++;
        }
    }
    for (k = low; k <= heigh; k++)
    {
        arr[k] = temp[k];
    }
}
int main()
{
	int arr[]={13,2,10,5,15,6,17,11};
	int i,size;
	size=sizeof(arr)/sizeof(arr[0]);
	partition(arr,0,size-1);
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
	
	return 0;
}
