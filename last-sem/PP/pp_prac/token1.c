#include<stdio.h>
#include<string.h>
int main(void)
{
char msg[]="aditya yashwant patil";
char *word;

word= strtok(msg," ");
while(word != NULL )
	{
		printf("%s\n",word);	
		word=strtok(NULL," ")
	}
return 0;
}
