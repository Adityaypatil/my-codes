#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define len_1 50

char *runencode(char *src)
{
	int rlen;char count[len_1]; 
	int len=strlen(src);
	char *dest=(char *)malloc(sizeof(len*2+1));
	
	int i,j,k;
	
	for(i=0;i<len;i++)	
	{
		dest[j++]=src[i];
		
		rlen=1;
		while(i+1 < len && src[i]==src[i+1])
			{
			rlen++;
			i++;
			}
		sprintf(count,"%d",rlen);
		for(k = 0; *(count+k); k++, j++)
   		 { 
    			  dest[j] = count[k]; 
   		 } 		

	}
	dest[j]='\0';
	return dest;
}
int main()
{
	char str[]="geeksforgeeks";
	char *result=runencode(str);
	printf("%s",result);
	return 0;
}
 
