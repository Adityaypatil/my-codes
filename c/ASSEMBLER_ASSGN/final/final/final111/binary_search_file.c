// Binary Search On Opcode_Table

#include<stdio.h>
#include<string.h>
#include"structure.h"

// Structure For Storing Mnemonics
/*typedef struct mnemonics_table
{
	char mnemonic[10];
	char mnemonic_code[13];
	char number_of_parameters[10];
}MOT;
*/
int binary_search(MOT m[MAX],int low,int high,char *key);
int binary_search1(RTAB r[REG_SIZE],int low,int high,char *key);

int main()
{
	FILE *fp;
	char filename[20];
	MOT m[MAX];
	RTAB r[REG_SIZE];
	int search_value,count = 0,i;
	char *search_key;
	fp = fopen("opcode.txt" , "r");

	if(fp == NULL)
	{
		printf("\nFile Opening Error\n");
		return 0;
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s",m[count].mnemonic,m[count].mnemonic_code,m[count].number_of_parameters);
		//printf("%s %s %s\n",m[count].mnemonic,m[count].mnemonic_code,m[count].number_of_parameters);
		count++;
		
	}
	
	search_key = "not";
	search_value= binary_search(m,0,count,search_key);
	// Search found
	if(search_value == 0)
	{
		printf("\nMnemonic Found");
	}
	else
	{
		printf("\nMnemonic NotFound");
	}
	printf("\n");
	fclose(fp);
	
	// Filling Register Table
	count = 0;
	fp = fopen("register.txt","r");
	if(fp == NULL)
	{
		printf("\nFile Opening Error\n");
		return 0;
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s%s",r[count].reg,r[count].reg_opcode);
		count++;
		
	}
	for(i=0;i<count-2;i++)
	{
		printf("%s %s\n",r[i].reg,r[i].reg_opcode);
	}
	search_key="EAX";
	search_value= binary_search1(r,0,count,search_key);
	// Search found
	if(search_value == 0)
	{
		printf("\nReg Found");
	}
	else
	{
		printf("\nReg NotFound");
	}
	
	printf("\n");
	return 0;
}

int binary_search(MOT m[MAX],int low,int high,char *key)
{
	int mid;
	if(low < high)
	{
		mid = (low+high)/2;
		if(strcmp(key,m[mid].mnemonic)==0)
		{
			return 0;
		}
		else if(strcmp(key,m[mid].mnemonic) > 0)
           	binary_search(m,mid+1,high,key);
	    else if(strcmp(key,m[mid].mnemonic) < 0)
            binary_search(m,low,mid,key);
	}
	else
		return 1;
}

int binary_search1(RTAB r[REG_SIZE],int low,int high,char *key)
{
	int mid;
	if(low < high)
	{
		mid = (low+high)/2;
		if(strcmp(key,r[mid].reg)==0)
		{
			return 0;
		}
		else if(strcmp(key,r[mid].reg) > 0)
           	binary_search1(r,mid+1,high,key);
	    else if(strcmp(key,r[mid].reg) < 0)
            binary_search1(r,low,mid,key);
	}
	else
		return 1;
}
