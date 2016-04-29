#include<stdio.h>
#include<stdlib.h>
#include"structure.h"

#define s 100

char token_array[200];

int sec_text()
{
	while(!feof(fp))
	{
	fgets(token_array,sizeof(token_array),fp)
	printf("%s",token_array);		
	token(token_array);
	
}
	
int token(char temp[s])
	{
		int i=0,j=0;
		for(i=0;temp[i] != '\0';)
		i++;
		else
		{
			if(temp[i] == ' ' || temp[i] == ',' )
			
			i++;
							







int main()
{
FILE *fp;

fp=fopen();

}


