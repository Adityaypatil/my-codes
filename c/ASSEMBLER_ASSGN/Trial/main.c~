#include"main.h"
#include "wrkngsrccode.h"
#include "datasection.h"
#include "textsection.h"
#include "insrterrortable.h"
#include "boolfound.h"
#include "prnterr.h"
#include "isidentifier.h"
#include "prntsymb.h"
#include "insertsymb.h"


int main(int argc ,char *argv[])
{

  input_file=fopen(argv[1],"r");
  obfile=fopen(argv[2],"w");

  Working_On_SourceCode();
  Writing_Into_ObjectCode();

  fclose(input_file);
  fclose(obfile);
  Printing_Symbol_table();
  Print_Err_Table();

  
  return 0;
}

/* Seperate  The Section work */

/*
void   Working_On_SourceCode()
{
  int i=1;
  char *line=(char*)malloc(sizeof(char)*SIZE);
  if(fgets(line,SIZE,input_file)!=NULL)
    while(i)
      {
	IntLineNumber++;
	/* Section Checking
	
	if(!strncmp ("section.data",line,12))
	  {
	    if(!fgets(line,SIZE,input_file))
	      goto end;
	    else
	      {
	      while(strncmp ("section.text",line,12)!=0)
		{
		  IntLineNumber++;
		  InDataSection(line);
		  if(!fgets(line,SIZE,input_file))
		    goto end;
		}
	      if(!fgets(line,SIZE,input_file))
		goto end;
	      IntLineNumber++;
	      while(1)
		{
		  
		  InitializeInstruction();
		  if(forword_ref)
		    ResolveForwardRef(line);
		  else
		    InTextSection(line);
		  if(!fgets(line,SIZE,input_file))
		    goto end;
		  IntLineNumber;
	      }
	  }	  
      end:i=0;
	
      }
  
}
}
*/

/* Find One String Into Another set Of String */
/*
Bool IsFound(char *src[],char*str)
{
  int i=0;
  while(src[i])
    {
      if(!strcmp(src[i],str))
	return 1;
      i++;
    }
  return 0;
}*/
  
/*Processes statement in Data Section */
/*
void InDataSection(char *line)
{
  char identifier[30],type[5],value[10];
 
  sscanf(line,"%s %s %s",identifier,type,value);
  fprintf(obfile,"%d\t%d\t%d\n",++location_cnt,atoi(value),line);
  
  
  if(IsIdentifier(identifier))
    InsertSymbol(identifier,1,0,location_cnt);
  
  if(!IsFound(types,type))
   InsertIntoErrorTable(IntLineNumber,6,++serialNumber);
 
}
*/
/* Processes statement in text section */
/*Makes Symbol Table */
/*Also Makes Instruction line Object Form*/

/*
void InTextSection(char *line)
{
  Bucket *b=(Bucket*)malloc(sizeof(Bucket));
  char *timepass=NULL;
  int address_1,address_2,operand2_len,flag_for_op_1=1;
  char opcode[6],mode[4],op1,op2;
  char lable[30],operator[30],operand1[30],operand2[100],comment[100];    

  
  sscanf(line,"%s %s %s %s %s",lable,operator,operand1,operand2,comment );
  
  

  if(lable[strlen(lable)-1]!=':')
    {
      strcpy(comment,operand2);
      strcpy(operand2,operand1);
      strcpy(operand1,operator);
      strcpy(operator,lable);
      
    }
  else
    if(!IsIdentifier(lable))
      
InsertSymbol(lable,1,0,++location_cnt);
  timepass=IsOpcode(operator);

  if (timepass)
    {
      strcpy(opcode,timepass);
      InsertToInstruction(opcode,1,0);
      if(strcmp("113",opcode)==0)
	{
	  forword_ref=1;
	  goto final;
	}
      if(IsNumber(operand1))
	//check the instr_format jump,
	InsertIntoErrorTable(IntLineNumber,4,++serialNumber);
      else
      {
	  if(operand1[0]=='[')
	    InsertIntoErrorTable(IntLineNumber,7,++serialNumber);
	  else    
	    {
	      mode[0]='1';   
	      if(strcmp("eax",operand1)==0)
		op1='1';
	      else
		if(strcmp("ebx",operand1)==0)
		  op1='2';
		else
		  {
		    flag_for_op_1=0;
		    b=GetSymbol(operand1);
		    if(!b)
		      {
			address_1=location_cnt;
			InsertSymbol(operand1,0,1,address_1);
		      }
		    else
		      address_1=b->address;
		    mode[0]='0';
		  }
	    }
      }
      
	//For Operand 2
		    
      if(strcmp("ebx",operand2)==0)
	op2='2';	
      else
	if(strcmp("eax",operand2)==0)
	  op2='1';
      
      if(op2=='1' ||op2=='2')
	{
	  mode[1]='1';
	  mode[2]='1';
	    mode[3]='\0';
	    InsertToInstruction(mode,2,0);
	    if(flag_for_op_1)
	      InsertToInstruction(itoa(op1-48),3,0);
	    else
	      InsertToInstruction(itoa(address_1),3,0);
	    InsertToInstruction(itoa(op2-48),4,0);
	  }
	else
	  if(IsNumber(operand2))
	    {
	    mode[1]='0';
	    mode[2]='1';
	    mode[3]='\0';
	    InsertToInstruction(mode,2,0);
	    if(flag_for_op_1)
	      InsertToInstruction(itoa(op1-48),3,0);
	    else
	      InsertToInstruction(itoa(address_1),3,0);
	    InsertToInstruction(operand2,4,1);
	    }
	  else
	    {
	      mode[1]='1';
	      mode[2]='0';
	      mode[3]='\0';
	      operand2_len=strlen(operand2);
	      if(operand2[0]=='[' && operand2[operand2_len-1]==']')
		{
		  operand2[operand2_len-1]='\0';
		  b=GetSymbol(&operand2[1]);
		  if(!b)
		    {
		      address_2=location_cnt;
		      InsertSymbol(operand1,0,1,address_2);
		    }
		  else
		    address_2=b->address;
		  InsertToInstruction(mode,2,0);
		  if(flag_for_op_1)
		    InsertToInstruction(itoa(op1-48),3,0);
		  else
		    InsertToInstruction(itoa(address_1),3,0);
		  InsertToInstruction(itoa(address_2),4,1);
		  
		}
	      else
		{
		  b=GetSymbol(operand2);
		  if(!b)
		    {
		      address_2=location_cnt;
		      InsertSymbol(operand2,0,1,address_2);
		    }
		  else
		    address_2=b->address;
		  InsertToInstruction(mode,2,0);
		  if(flag_for_op_1)
		    InsertToInstruction(itoa(op1),3,0);
		  else
		    InsertToInstruction(itoa(address_1),3,0);
		  InsertToInstruction(itoa(address_2),4,0);
		}
	    }
    }
  else
    InsertIntoErrorTable(IntLineNumber,5,++serialNumber);
 final:
  return ;
 
}
*/
/* Inserts The Error Into Error Table*/
/*
void InsertIntoErrorTable(int line_no,int err_no,int sr_no)
{
  
  dynamicErrorTable *new_node;
    
  new_node=(dynamicErrorTable *) malloc(sizeof(dynamicErrorTable));
  
  new_node->sr_no=sr_no;
  new_node->err_no=err_no;
  new_node->line_no=line_no;
  new_node->next=error_table_head;
  error_table_head=new_node;
}
*/

/*

void Print_Err_Table()
{printf("\n\n** Printing ERROR TABLE ** \n");
  dynamicErrorTable *head=error_table_head;
   
   printf("----------------------------------------------------------------------\n");
   printf("Serial  ||   Line_no    ||    Error_description    \n");
  printf("----------------------------------------------------------------------\n"); 
  while(head)
    {
      printf(" %d\t | \t%d\t | \t%s\n",head->sr_no,head->line_no,staticErrorTable[head->err_no].description);
      head= head->next;
      
    }
}
  
*/
  
    


/* Checks THe Identifier Valid Or Not */

/*
Bool IsIdentifier(char *identifier)
{
  if(!isalpha(identifier[0]))
    {

      InsertIntoErrorTable(IntLineNumber,3,++serialNumber);
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
	    
*/	
	
//symtab Operations 

/*
  pre    : Symbol Table defined 
  post   : Symbol Table is initialized to initial values
  usages : Use for inserting the symbol from sorce code 

*/

Bucket *CreateBucket(char *name,int defined,int used,int address)
{
    Bucket *newNode=(Bucket *) malloc(sizeof(Bucket));
    newNode->symbol=(char *) malloc(sizeof(strlen(name)));
    strcpy(newNode->symbol,name);
    newNode->defined=defined;
    newNode->used=used;
    newNode->address=address;
    newNode->next=NULL;
    return newNode;
}

/*Creates The Initial Table*/
void CreateTable()
{
  int i=0;
  
  while(i<TABSIZE)
    symTab[i++].link=NULL;
}


/*
void Printing_Symbol_table()
{printf("\n\n** Printing SYMBOL TABLE  **\n\n");
  int i=0,j=0;
  Bucket *bct_ptr;
  bct_ptr=(Bucket*)malloc(sizeof(Bucket));
  printf("----------------------------------------------------------------------\n");
   printf(" Serial  ||    Name    ||    Defined    ||     Used    ||    Address  \n");
  printf("----------------------------------------------------------------------\n");
  while(i<TABSIZE)
    {
      if(symTab[i].link)

	{
	  bct_ptr=symTab[i].link;
	  while(bct_ptr)
	    {
	     
printf(" %d\t|\t%s\t|\t%d\t|\t%d\t|\t%d  \n\n",j,bct_ptr->symbol,bct_ptr->defined,bct_ptr->used,bct_ptr->address);
	      bct_ptr=bct_ptr->next;
	      j++;
	    }
	}
      i++;
    }
}
*/




/* Insert Symbol Into Symbol Table */
/*
void InsertSymbol(char *name,int defined,int used,int address)
{
  
  Bucket *bket=CreateBucket(name,defined, used, address);
  Key key;
  key=HashFunction(bket->symbol);
  Bucket *tempNode;
  tempNode=symTab[key].link;
  symTab[key].link=bket;
  
  symTab[key].link->next=tempNode;
}

*/
/* Returns The Address To The Node Containing Given Symbol Info */

Bucket * GetSymbol(char * symbol)
{
    Key key;
    Bucket *bucketPtr;
    int found;
    
    key = HashFunction(symbol);
    bucketPtr = symTab[key].link;
    
    found = 0;
    while (bucketPtr != NULL && found == 0)
    {
	if (strcmp(symbol, bucketPtr->symbol) == 0)
	    found = 1;
	else
	    bucketPtr = bucketPtr->next;
    }
    return  bucketPtr;
}

/* Free The Memory Allocated By The Symbol table */


/* Gives The Hash Key For Perticular Symbol*/

Key HashFunction( char *cadidateKey)
{
    char *charPtr;
    int key;
    
    charPtr = cadidateKey;
    key = 0;
    while (*charPtr)
	key = ((key << 1) ^ (*charPtr++)) & 0x3fff;
    
    return (key % TABSIZE);
}

/* Returns The Opcode For Mnemonic */
/*
char* IsOpcode(char *op)	
{
  int flag=0,i=0,j;
  while(i<OPSIZE)
    {
      
      if((j=strcmp(op,opcodes[i].opcode_name))==0)
	{
	  
	  flag=1;
	  break;
	}
      i++;
    }
  if(flag)
    return opcodes[i].opcode;
  else
    return NULL;
}

/*Converts  Integer To string */


char* itoa(int no)
{
  char *str;
  int no1=0,c=0;
  while(no)
    {
      no1=no1*10+(no%10);
      no=no/10;
      c++;
      
    }//while
  str=(char*)malloc(sizeof(char)*c);  
  c=0;
  while(no1)
    {
      str[c++]=(no1%10)+48;
      no1=no1/10;
      
    }//while
  str[c]='\0';
  return str;
}

/* Checks The Content of string is Number or not*/

int IsNumber(char *numstr)
{
  while(*numstr)
    {
      if(!isdigit(*numstr))
	return 0;
      numstr++;
    }
  return 1;
}
*/
/* Handles Forword Reference Problem*/

void ResolveForwardRef(char *line)
{
  char identifier[30],type[5],value[10];
  sscanf(line,"%s %s %s",identifier,type,value);
  fprintf(obfile,"%d\t%d\t%d\n",++location_cnt,atoi(value),line);
  
  if(IsIdentifier(identifier))
    {
      //take sym entry and handle ref here
      InsertSymbol(identifier,1,0,location_cnt);
    }
  //Insert the symbol as identifier  in sybol table
  if(!IsFound(types,type))
    InsertIntoErrorTable(IntLineNumber,6,++serialNumber);
}

/* Initializes the Instruction To zero*/

void  InitializeInstruction()
{
  Instruction *prev_ptr=TempInstPtr,*new_node=(Instruction *)malloc(sizeof(Instruction));
  bzero(new_node,sizeof(Instruction));
  TempInstPtr=new_node;
  if(!InstFmt)
    {
      InstFmt=new_node;
      InstFmt->next=new_node;
    }
  else
    
    {
    prev_ptr->next=new_node;
    new_node->next=NULL;
  }
}



 
void InsertToInstruction(char *str,int element ,int flag)
{
  switch(element)
    {
    case 1:
      strcpy(TempInstPtr->opcode,str);
      break;
      
    case 2:
      strcpy(TempInstPtr->mode,str);
      break;
    case 3:
      if(flag)
	{
	  strcpy(TempInstPtr->operand1,"[");
	  strcpy(TempInstPtr->operand1,str);
	  strcat(TempInstPtr->operand1,"]");
	}
      else
	strcpy(TempInstPtr->operand1,str);
      break;
      
    case 4:
      if(flag)
	{
	  strcpy(TempInstPtr->operand2,"[");
	  strcat(TempInstPtr->operand2,str);
	  strcat(TempInstPtr->operand2,"]");
	}
      else
	strcpy(TempInstPtr->operand2,str);
      break;
    }
}   


/* Actual Writting Of Instructiobn In Object Form */

void Writing_Into_ObjectCode()
{
  Instruction *head=InstFmt;
  
  if(!head)
    printf("Empty...\n");
  else
    {
      
    while(head)
      {
	fprintf(obfile,"%s\t%s\t%s\t%s\n",head->opcode,head->mode,head->operand1,head->operand2);
	head=head->next;
	
      }
    }
}

//output

/*~/Downloads/Pass1/Trial$ ./a.out fact.asm new


** Printing SYMBOL TABLE  **

----------------------------------------------------------------------
 Serial  ||    Name    ||    Defined    ||     Used    ||    Address
----------------------------------------------------------------------
 0      |       main:   |       1       |       0       |       2

 1      |       next:   |       1       |       0       |       3

 2      |       n1      |       1       |       0       |       1

 3      |       Exit:   |       1       |       0       |       4



** Printing ERROR TABLE **
----------------------------------------------------------------------
Serial  ||   Line_no    ||    Error_description
----------------------------------------------------------------------
 3       |      3        |      Memory as first operand not allowed
 2       |      3        |      Lvalue Error
 1       |      3        |       Type mismatch


*/
