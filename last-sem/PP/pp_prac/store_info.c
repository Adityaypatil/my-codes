#include<stdio.h>

int main()
{
	char ch,name[20];
	FILE *fp;
	fp=fopen("abc.txt","w");
	
	if(fp==NULL)
		{
			printf("Does not exist");
			return;
		}	
	printf("ENter name\n");
	scanf("%s",name);
	fprintf(fp,"Name=%s\n",name);
	fclose(fp);
	
	fp = fopen("abc.txt", "r");
	ch=fgetc(fp);
	while(ch !=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fp);
	}
	fclose(fp);
	return 0;
}
