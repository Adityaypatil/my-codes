#include<stdio.h>

int main(int argc,char *argv[])
{
	FILE *f1=fopen(argv[1],"rw+");
	FILE *f2=fopen(argv[2],"rw+");
	char *word;
	fseek(f1,0,SEEK_END);
	long fsize=ftell(f1);
	
	//fseek(f1,0,SEEK_SET);
	rewind(f1);
	
	char *buff=malloc(fsize+1);
	
	fread(buff,fsize,1,f1);
	
	printf("%s",buff);
	
	//fprintf(f2,"%s",buff);
	
	/*word=strtok(buff," ");
	while(word != NULL )
	{
		fprintf(f2,"%s\n",word);	
		word=strtok(NULL," ");
	}*/
return 0;
}
