#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
  FILE *f1,*f2;
  f1=fopen(argv[1],"w+");
  f2=fopen(argv[2],"w+");

  char *buff="Aditya Patil";

  fwrite(buff,strlen(buff),1,f1);

  int check=strlen(buff);

  printf("Buff 1 %d\n",check);

  char *buff2=malloc(strlen(buff));

  int size=strlen(buff);

  printf("Buff 1 Later %d\n",size);		

  fread(buff2,size,1,f1);
  fwrite(buff2,size,1,f2);
 
  return 0;
}
