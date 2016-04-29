#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
FILE *f1,*f2;

f1=fopen(argv[1],"r");
f2=fopen(argv[2],"w");

	if(f1==NULL)
    	{
     	 printf("\n Error in file in p1\n");
     	 return;
    	}
    	if(f2==NULL)
     {		
   	  printf("\n Error in file in op\n");
    	  return;
    }
    
	char string[]={"<html>\n<body>\n<head>\n<table>\n"};
	char string2[1000];
	fprintf(f2,"%s",string);
	while((!feof(f1)))
		{
		fscanf(f1,"%s",string2);
		
		if(strncmp(string,"for",3)==0)			
			{
				fprintf(f2,"<table>\n<tr><td>%s</td></tr>\n",string2);
			while(!feof(f1))
				{
				if(strncmp(string2,"}",1)==0)
		 		 	{				
						fprintf(f2,"\n<tr><td>%s</td></tr>\n</table>",string2);
						break;
					}
				else
					{
						fprintf(f2,"\n<tr><td>%s<tr></tr>",string);
					}
				}	
			}
				else
				{
					fprintf(f2,"\n<tr><td>%s</td></tr>\n",string);
				}
		}
	fprintf(f2,"\n</table>\n</head>\n</body>\n<html>");
return 0;
}
