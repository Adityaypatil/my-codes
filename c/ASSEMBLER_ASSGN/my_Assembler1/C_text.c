#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"structure.h"

#include"search.c"
FILE *fp,*fp1,*fp2;
SECTAB st;
int i=0,j=0,LC=1,tii_counter=0,k=0;
STAB s[SIZE];
LTAB l[SIZE];
MOT m[MAX];
RTAB r[REG_SIZE];
TII t[SIZE];	
CODE c;
int search_value,count = 0;
char *search_key;	
char token_array[SIZE];



int main()
{
	
	fp = fopen("textt.asm","r");
	if(fp == NULL)
	{
		printf("\nFile opening Error\n");
		exit(0);
	}
	
	// Filling Mnemonic Table
	fp1 = fopen("opcode.txt" , "r");

	if(fp1 == NULL)
	{
		printf("\nFile Opening Error\n");
		return 0;
	}
	while(!feof(fp1))
	{
		fscanf(fp1,"%s%s%s",m[count].mnemonic,m[count].mnemonic_code,m[count].number_of_parameters);
		//printf("%s %s %s\n",m[count].mnemonic,m[count].mnemonic_code,m[count].number_of_parameters);
		count++;
		
	}

	// Filling Register Table
	count = 0;
	fp2 = fopen("register.txt","r");
	if(fp2 == NULL)
	{
		printf("\nFile Opening Error\n");
		return 0;
	}
	while(!feof(fp2))
	{
		fscanf(fp2,"%s%s",r[count].reg,r[count].reg_opcode);
		count++;
		
	}
	
	// section fields
	fscanf(fp,"%s%s",st.name,st.type);
//	printf("%s %s\n",st.name,st.type);
	
//	section_compare(st);
	
	// Display Symbol Table
	display_stab(s);
	printf("\n");
	return 0;
}



int section_text()
{
	while(!feof(fp))
	{
		fgets(token_array,sizeof(token_array),fp);
		printf("%s\n",token_array);	
		tokenizer(token_array);
		//ch_opcode();

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
			//			entry_in_tii(c.label);
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





































































































































































