#include<stdio.h>
struct data
{
	int arr[10];
};

int main(int argc,char *argv[])
{
	int i=0;
	char buff[100];
	struct data d;
	FILE *f1=fopen(argv[1],"r");
	FILE *f2=fopen(argv[2],"w");
	
	while(!feof(f1))
	{
		fscanf(f1,"%d",&d.arr[i]);
		i++;
	}
	fclose(f1);
	
	int add=0;
	for( i=0;i<10;i++)
		add=add+d.arr[i];
	
	//printf("%d\n",add);
	fprintf(f2,"%d",add);
	return 0;
}
