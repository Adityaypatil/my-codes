#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
  FILE *f1,*f2;
  f1=fopen(argv[1],"w+");
  f2=fopen(argv[2],"w+");
  
  fseek(f1,0,SEEK_END);
  long fsize=ftell(f1);
  fseek(f1,0,SEEK_SET);
	

  char *buffer=malloc(fsize),*temp;
  fread(buffer,fsize,1,f1);
  fwrite(buffer,strlen(buffer),1,f2);

 
 // fread(buff2,size,1,f1);
  //fwrite(buff2,size,1,f2);
 
  return 0;
}
