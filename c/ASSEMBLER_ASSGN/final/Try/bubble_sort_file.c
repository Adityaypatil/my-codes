// Bubble sort on opcode file

#include<stdio.h>
#include<string.h>

int bubble_sort(char a[60][10],int n);
const char *byte_to_binary(int x);

int main(int argc,char argv[])
{
	//char a[10][20] = {"x","a","b"};
	int i,count=0,size;
	FILE *fp,*fp1;
	char filename[20];
	char str[60][10];
	fp = fopen("new.txt" , "r");
//	size = sizeof(str)/sizeof(str[0]);

	if(fp == NULL)
	{
		printf("\nFile Opening Error\n");
		return 0;
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s",str[count]);
		count++;
	}
  
/*	for(i=0;i<count-1;i++)
	{
		printf("%s\n",str[i]);
	}
*/	
	bubble_sort(str,count);
	printf("\nAfter Sort\n");
/*	for(i=0;i<count-1;i++)
	{
		printf("%s\n",str[i]);
	}
*/	fclose(fp);
	fp1 = fopen("new1.txt","w");
	if(fp1 == NULL)
	{
		printf("\nFile Opening Error\n");
		return 0;
	}
	for(i=0;i<count-1;i++)
	{
		fprintf(fp1,"%s %s\n",str[i],byte_to_binary(i));
	}
	printf("\n");
	fclose(fp1);
	return 0;
}

const char *byte_to_binary(int x)
{
    static char b[13] ={0};
    b[0] = '\0';

    int z;
    for (z = 4096; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }
	//printf("\nSizeof = %d\n",sizeof(b));
    return b;
}

int bubble_sort(char a[60][10],int n)
{
	int i,j;
	char temp[20];
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-2;j++)
		{
			if((strcmp(a[j],a[j+1]))>0)
			{
				strcpy(temp, a[j]);
				strcpy(a[j], a[j+1]);
				strcpy(a[j+1], temp);
			}
		}
	}
	return 0;
}
