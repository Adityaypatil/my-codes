#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define no_of_char 50

int *getcount(char *str)
{	
	int *count=(int *)calloc(sizeof(int),no_of_char);
	int i;
	for(i=0;*(str+i);i++)
		count[*(str+i)]++;
	return count;
	
}

int find(char *str)
{
	int *count=getcount(str);
	
	int index=-1,i;
	for(i=0;*(str+i);i++)
	{
		if(count[*(str+i)]==1)
			{
				index=i;
				break;
			}
	}
	free(count);
	return index;
}
int main()
{
	char str[]="geeksforgeeks";
	int index=find(str);
	if(index==-1)
	printf("All char are repeating:\n");
	else
	printf("\%c is non reapting char",str[index]);
	return 0;
}
