// Main code for ASSEMBLER

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"structure.h"
#include"search.c"

#define SIZE 20

// Function Prototypes

int section_compare(SECTAB st);
int section_data();
int section_text();
int entry_in_stab(SECTAB st,STAB s[]);
int display_stab(STAB s[]);

// Variable Declaration

FILE *fp,*fp1,*fp2;
SECTAB st;
int i=0,j=0,LC=1;
STAB s[SIZE];
LTAB l[SIZE];
MOT m[MAX];
RTAB r[REG_SIZE];	
int search_value,count = 0;
char *search_key;	

int main()
{
	
	fp = fopen("code.asm","r");
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
	printf("%s %s\n",st.name,st.type);
	
	section_compare(st);
	
	// Display Symbol Table
	display_stab(s);
	printf("\n");
	return 0;
}

// Section Compare
int section_compare(SECTAB st)
{
	
	if(strcmp(st.name,"section")==0)
	{
		if(strcmp(st.type,".data")==0)
		{
			printf("Success data\n");
			section_data();
		}
		else if(strcmp(st.type,".bss")==0)
		{
			printf("Success bss\n");
		}
		else if(strcmp(st.type,".text")==0)
		{
			printf("Success text\n");
		}
		
	}
	else
	{
		printf("\nInvalid Instruction\n");
	}
	printf("\n");
	return 0;
}

// Section Data
int section_data()
{
	fscanf(fp,"%s%s",st.name,st.type);
//	printf("%s %s ",st.name,st.type);

	search_key = st.name;
	search_value= binary_search_MOT(m,0,count,search_key);
	// Search found
	if(search_value == 0)
	{
		//printf("\nMnemonic Found");
		printf("\nError... Variable name same as mnemonic name\n");
		exit(0);
	}
	else
	{
		search_value= binary_search_RTAB(r,0,count,search_key);
		//printf("\nMnemonic NotFound");
		if(search_value == 0)
		{
			//printf("\nReg Found");
			printf("\nError... Variable name same as Register name\n");
			exit(0);

		}
		else
		{
			//printf("\nReg NotFound");
		}
		if(strcmp(search_key,"section") == 0)
		{
			printf("\nError... section is not use as variable name\n");
			exit(0);

		}
	}
	
	while(strcmp(st.name,"section") != 0)
	{
		
	if(strcmp(st.type,"db") == 0)
	{
			fgets(st.value_char,sizeof(st.value_char),fp);
	//		printf("%s \n",st.value_char);
	
	}
	else if(strcmp(st.type,"dd") == 0 || strcmp(st.type,"dq") == 0 || strcmp(st.type,"dw") == 0)
	{
		fscanf(fp,"%s",st.value_char);
		//printf("%d \n",atoi(st.value_char));
	}
	else
	{
		printf("\nError... Not a data type\n");
		exit(0);
	}
	// Entry in symbol table
	
	entry_in_stab(st,s);
	
	fscanf(fp,"%s%s",st.name,st.type);
//	printf("%s %s ",st.name,st.type);
	
	}
	if(strcmp(st.type,".text") == 0)
	{
		//section_text();
	}
	else if(strcmp(st.type,".bss") == 0)
	{
	//	section_bss();
	}
	else
	{
		printf("\nInvalid Instruction\n");
	}
	return 0;
}


//Entry in Symbol Table
int entry_in_stab(SECTAB st,STAB s[])
{
	search_STAB(st,s,i);
	strcpy(s[i].symbol_name,st.name);
	strcpy(s[i].symbol_value,st.value_char);
	strcpy(s[i].symbol_type,st.type);
	s[i].symbol_address = LC;
	s[i].seq_no = i;
	if(strcmp(st.type,"db") == 0)
	{
		LC = LC + 1;	// Byte
	}
	else if(strcmp(st.type,"dw") == 0)
	{
		LC = LC + 2;	// Byte
	}
	else if(strcmp(st.type,"dd") == 0)
	{
		LC = LC + 4;	// Byte
	}	
	else if(strcmp(st.type,"dq") == 0)
	{
		LC = LC + 8;	// Byte
	}
	i++;
}
// Display Symbol Table
int display_stab(STAB s[])
{
	printf("\n\t\t\t\tSymbol Table\n\n");
	printf("seq_no\tsymbol_name\tsymbol_type\tsymbol_value\t\tsymbol_address\n");
	
	for(j=0;j<i;j++)
	{
		printf("%d\t%s\t\t%s\t\t%s\t\t%d\n",s[j].seq_no,s[j].symbol_name,s[j].symbol_type,s[j].symbol_value,s[j].symbol_address);
	}
}

// Search in Symbol Table
