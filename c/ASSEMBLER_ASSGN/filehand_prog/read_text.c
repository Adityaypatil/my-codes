#include<stdio.h>

void main()
{
FILE *fp;
int count=0,i;
char chr,src[120];
fp=fopen("abc.txt","r");

//fgets(src,120,fp);
chr=fgetc(fp);
/*while(chr !=EOF)
{
	if(chr == 'n')
		{
		cnt=cnt+1;
		}
	chr=getc(fp);
}*/
//printf("Total line is :%d",cnt);

//while(chr !=EOF)
//{
while(1)
{	
	if(chr == EOF)
	
	break;

	if(chr == ' ')
		count++;
	//printf("%c",chr);
		
chr=fgetc(fp);
}
printf("%d",count);
fclose(fp);

}
