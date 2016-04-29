#include<stdio.h>


int missingnum(int *arr,int n)
{
int i,total;

total = (n+1)*(n+2)/2;
for(i=0;i<n;i++)
	total =total -arr[i];

return total;
}



int main()
{

int arr[]={1,2,3,5};
int n=sizeof(arr)/sizeof(arr[0]);
printf("\n Missing NUmber is : %d",missingnum(arr,n));
return 0;

}
