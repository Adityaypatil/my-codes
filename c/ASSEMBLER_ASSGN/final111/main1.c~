
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"structure.h"
#include"search.c"



#define SIZE 100


FILE *fp,*fp1,*fp2;
SECTAB st;

int i=0,j=0,LC=1,tii_counter=0,k=0;

STAB s[SIZE];LTAB l[SIZE];MOT m[MAX];RTAB r[REG_SIZE];TII t[SIZE];	
CODE c;

int s_value,count = 0;

char *s_key;	
char token_array[SIZE];

int main()
{
	
	fp = fopen("add1.asm","r");
	if(fp == NULL)
	{
		printf("\nOpening Error\n");
		exit(0);
	}
	
	
fp1 = fopen("opc.txt" , "r");

	if(fp1 == NULL)
	{
		printf("\nFile Opening Error\n");
		return 0;
	}
	
	while(!feof(fp1))
	{
		fscanf(fp1,"%s%s%s",m[count].mnemonic,m[count].mnemonic_code,m[count].number_of_parameters);
		count++;
		
	}

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
	
	fscanf(fp,"%s%s",st.name,st.type);
	
	
	s_comp(st);
	
	show_symboltable(s);
	
	printf("\n");

return 0;

}


int s_comp(SECTAB st)
{
	
	
	
	if(strncmp(st.name,"section",7)==0)
	{
		
		if(strcmp(st.type,".data")==0)
		{
			s_data();
		}

		else if(strcmp(st.type,".bss")==0)
		{
			s_bss();
		}
	
		else if(strcmp(st.type,".text")==0)
		{
			s_text();
		}
		
	}
	else
		{
		printf("\nInvalid Instruction\n");
		}

		printf("\n");
return 0;
}

int s_data()
{
	//printf("In Data section:\n");
	fscanf(fp,"%s%s",st.name,st.type);


	s_key = st.name;
	s_value= binary_search_MOT(m,0,count,s_key);
	
	if(s_value == 0)
	{
		printf("\nMnemonic Found");
		printf("\nError. Variable name same as mnemonic name\n");
		exit(0);
	}	
	else
	{
		s_value= binary_search_RTAB(r,0,count,s_key);
	
		if(s_value == 0)
		{
			printf("\nError... Variable name same as Register name\n");
			exit(0);

		}
		else
		{
			//printf("\nReg NotFound");
		}
		if(strcmp(s_key,"section") == 0)
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
		
	}
	else if(strcmp(st.type,"dd") == 0 || strcmp(st.type,"dq") == 0 || strcmp(st.type,"dw") == 0)
	{
		fscanf(fp,"%s",st.value_char);
		
	}
	else
	{
		printf("\nError... Not a data type of .data\n");
		exit(0);
	}
	
	
	entry_in_stab(st,s);
	
	fscanf(fp,"%s%s",st.name,st.type);

	}
	
	if(strcmp(st.type,".text") == 0)
	{
		s_text();
	}
	else if(strcmp(st.type,".bss") == 0)
	{
		s_bss();
	}
	else
	{
		printf("\nInvalid Instruction\n");
	}
	return 0;
}



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
		LC = LC + strlen(s[i].symbol_value);	// Byte
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
	/*else if(strcmp(st.type,"resb") == 0)
	{
		LC = LC + atoi(s);	// Byte
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
	*/
	i++;
}


int show_symboltable(STAB s[])
{

	printf("\n\t\t\t\tSymbol Table\n\n");

	printf("seq_no\tsymbol_name\tsymbol_type\tsymbol_value\t\tsymbol_address\n");
	
	for(j=0;j<i;j++)
	{
		printf("%d\t%s\t\t%s\t\t%s\t\t\t\t%d\n",s[j].seq_no,s[j].symbol_name,s[j].symbol_type,s[j].symbol_value,s[j].symbol_address);
	}

}


int s_bss()
{
	//printf("In Bss section:\n");
	fscanf(fp,"%s%s",st.name,st.type);
	s_key = st.name;
	s_value= binary_search_MOT(m,0,count,s_key);
	
	if(s_value == 0)
	{
		printf("\nMnemonic Found\n");
		printf("\nError... Variable name same as mnemonic name\n");
		exit(0);
	}
	else
	{
		s_value= binary_search_RTAB(r,0,count,s_key);
		
		if(s_value == 0)
		{
			
			printf("\nError... Variable name same as Register name\n");
			exit(0);

		}
		else
		{
			//printf("\nReg NotFound");
		}
		if(strcmp(s_key,"section") == 0)
		{
			printf("\nError... section is not use as variable name\n");
			exit(0);

		}
	}
	
	while(strcmp(st.name,"section") != 0)
	{
		
	if(strcmp(st.type,"resb") == 0)
	{
			fscanf(fp,"%s",st.value_char);
		
	
	}
	else if(strcmp(st.type,"resd") == 0 || strcmp(st.type,"resw") == 0 || strcmp(st.type,"resq") == 0)
	{
		fscanf(fp,"%s",st.value_char);
	
	}
	else
	{
		printf("\nError... Not a data type of .bss\n");
		exit(0);
	}
		
	entry_in_stab(st,s);
	
	fscanf(fp,"%s%s",st.name,st.type);

	
	}
	if(strcmp(st.type,".text") == 0)
	{
		s_text();
	}
	else if(strcmp(st.type,".data") == 0)
	{
		s_data();
	}
	else
	{
		printf("\nInvalid Instruction\n");
	}
	return 0;
}
int z=0;
int s_text()
{
	//printf("In Text section:\n");
	while(fgets(token_array,sizeof(token_array),fp))
	{
		token(token_array);
		
	}
	
}

int token(char temp[SIZE])
{
	char lable[10],operator[30],operand1[30],operand2[100],comment[100];    

	  sscanf(temp,"%s %s %s %s %s",lable,operator,operand1,operand2,comment );
  
//	printf("%s",temp);  

	  if(lable[strlen(lable)-1]!=':')
    {
      strcpy(comment,operand2);
      strcpy(operand2,operand1);
      strcpy(operand1,operator);
      strcpy(operator,lable);
      
    }
    else
   	{	
   		lable[strlen(lable)-1]='\0';
   		count++;
    
    		s_key=lable;
		s_value= binary_search_MOT(m,0,count,s_key);
	strcpy(st.type,"text");
	strcpy(st.name,lable);
	entry_in_stab(st,s);	
	}	

}

int IsIdentifier(char *identifier)
{
  if(!isalpha(identifier[0]))
    {


      return 0;
    }
  
  while(*identifier)
    {
      if( !isalnum(*identifier) )
	return 0;
      identifier++;
    }
    return 1;
}

/*
output:
		
				Symbol Table

seq_no	symbol_name	symbol_type	symbol_value		symbol_address
0	a		dd		10				1
1	b		resd		1				5
2	main		text		1				5
3	add		text		1				5

adi@adi:~/ASSEMBLER_ASSGN/final111$ 

*/
