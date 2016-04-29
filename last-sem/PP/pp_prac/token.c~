#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp=fopen("demo","rw+");
	char* word=malloc(256);
	int c;
	while(fp!=EOF)
	{
		fgets(word,10,fp);
		printf("%s\n",word);
	}
	return 0;
	
}
