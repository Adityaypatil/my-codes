
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"structure.h"
#include"search.c"
struct MOTtable
  {
	char Mnemonic[6];
	char Opcode[3];
  };

char token_array[SIZE];

int main()
{
int cnt=0;
/*
FILE *fp,*fp1,*fp2;

	
	fp = fopen("add1.asm","r");
	if(fp == NULL)
	{
		printf("\nFile opening Error\n");
		exit(0);
	}
	
	// Filling Mnemonic Table
	fp1 = fopen("instr.txt" , "r");

	if(fp1 == NULL)
	{
		printf("\nFile Opening Error\n");
		return 0;
	}
	
		
	while(!feof(fp1))
	{
		fscanf(fp1,"%s%s%s",);
		//printf("%s %s %s\n",);
		count++;
		
	}


	fp2 = fopen("register.txt","r");
	if(fp2 == NULL)
	{
		printf("\nFile Opening Error\n");
		return 0;
	}
*/

// static struct MOTtable MOT[14]={MOV 11,ADD 12,ADDi 13,ADC 14,SUB 15,SUBi 16,SBB 17,INC 18,DEC 19,MUL 20,DIV 21,CLC 22,CLD 23,CLC 24};
int section_text()
{
	while(!feof(fp))
	{
		fgets(token_array,sizeof(token_array),fp);
		printf("%s\n",token_array);	
		tokenizer(token_array);
	}
}

int tokenizer(char temp[SIZE])
{
	int i=0,j=0;
	for(i=0;temp[i] != '\0';)
	{
		if(temp[i] == ' ' || temp[i] == ',' || temp[i] == '\t' || temp[i] == '\r' || temp[i] == '\n')
		{
			i++;
			j=0;
		}
		else
		{
			c.label[j] = temp[i];
			if(temp[i+1] == ' ' || temp[i+1] == ',' || temp[i+1] == '\t' || temp[i+1] == '\r' || temp[i+1] == '\n')
			{
				c.label[j+1] = '\0';
				printf("%s\n",c.label);
				search_key = c.label;
				if(k==1)
				{
					entry_in_tii(c.label);
					printf("Main Success\n");
					j=0;k=0;
					//bzero(c.label,sizeof(c.label));
					
				}
				else
				{
					if(strcmp(search_key,"global") == 0)
					{
						k++;
					}
				
					search_value= binary_search_MOT(m,0,count,search_key);
					// Search found
					if(search_value != 0)
					{
						printf("\nError... \n");
						exit(0);
					}
					j=0;
					//bzero(c.label,sizeof(c.label));
				}
			}
			i++;
			j++;
		}
	}
}		


	


