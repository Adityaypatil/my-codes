#include<stdio.h>

int main()
{
  char ch;
  FILE *fp;
  fp=fopen("abc.txt","w");
  printf("Enter data\n");
  while(ch=getchar()!=EOF)
    {
      putc(ch,fp);
    }
  fclose(fp);
  fp=fopen("abc.txt","r");
  while(ch=getchar()!=EOF)
    printf("%c",ch);
    fclose(fp);
  return 0;
}
