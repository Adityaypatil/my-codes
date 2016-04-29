#include<stdio.h>

int main(int argc,char *argv[])
{
char buff[100];
int add=0,num1,num2;
FILE *f1=fopen(argv[1],"r");
FILE *f2=fopen(argv[2],"w");

while(!feof(f1))	
{
	fgets(buff,100,f1);
	sscanf(buff,"%d %d",&num1,&num2);
	add=num1+num2;
	
}
fprintf(f2,"%d",add);
fclose(f1);
fclose(f2);	
	return 0;
}
