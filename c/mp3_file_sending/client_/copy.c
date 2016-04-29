#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
     FILE *fp1,*fp2;
     char c[100];
     fp1=fopen("ggg.mp3","rb");
     if(fp1==NULL)
       exit(1);
     fp2=fopen("www.mp3","wb");
     if(fp2==NULL)
       exit(1);
     //while((c=fgetc(fp1))!=EOF)
       //   fputc(c,fp2);
     while((n=fread(c,100,1,fp1)))
     {	
     	printf("%d",n);
     	
     	fwrite(c,strlen(c),1,fp2);
     }
     
     fclose(fp1);
     fclose(fp2);
     return 0;
}


