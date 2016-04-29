#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define OPSIZE 15
#define Bool int
#define SIZE 100

#define eax 1
#define ebx 2



FILE *input_file , *obfile;
int input_file_len=0;
int Line_num=0;
int serial_no=0;
int location_cnt=0;
int forword_ref=0;
typedef struct opcode 
{
  char opcode[4] ;
  char opcode_name[7];
}OpcodeTable;

OpcodeTable opcodes[]= 
  { 
    { "100" , "add" }, 
    { "101" , "sub" },
    { "102" , "mul" },
    { "103" , "div" },
    { "104" , "mov" },
    { "105" , "load"},
    { "106" , "store"},
    { "106" , "and" },
    { "107" , "or"  },
    { "108" , "not" },
    { "109" , "xor" },
    { "110" , "jump"},
    { "111" , "jc"  },
    { "112" , "jz"  },
    { "113" , "ret"}
  };
typedef struct instr_format
{
  char operand1[16];
  char opcode[8];
  char mode[4];
  char operand2[18];
  struct instr_format *next;
}Instruction;

Instruction *TempInstPtr=NULL,*InstFmt=NULL;




struct static_error_table
{
  int error_no;
  char description[100];
};

struct static_error_table staticErrorTable []=
  {
    {  1   ,   "Error : Section Name Error\n"},
    {  2   ,   "Error :Variable Not Defined\n"},
    {  3   ,   "Warrning : Variable Name Always start with alphabet\n"} ,
    {  4   ,   "Lvalue Error"},
    {  5   ,   "Wromg Instruction"},
    {  6   ,   " Type mismatch"},
    {  7   ,    "Memory as first operand not allowed"}
  };


typedef struct dynamic_error_table 
{
    int sr_no;
    int err_no;
    int line_no;
    struct dynamic_error_table *next;
}dynamicErrorTable;


dynamicErrorTable *error_table_head=NULL;




/*for data function*/


char *types[] ={"db","dw","dd","time"};

//Functions

void Working_On_SourceCode();
void Data_section(char *);
void Text_section(char *);
Bool IsFound(char *source[],char*);
void Insert_In_ErrorTab(int,int,int);
char * IsOpcode(char *);
void errortab_display();
//symtab

#define TABSIZE 19
#define Key int

typedef struct symbol_table
{
    struct bucket *link;
    
}SymbolTable;

SymbolTable symTab[TABSIZE];    

typedef struct bucket 
{
    
    unsigned int defined : 1;   //1 :defined ,0:NotDefined
    unsigned int used    : 1;   //1:Used ,0:Not Used
    unsigned int type    : 2;   //1:identifier ,2:lable 
    unsigned int other   : 28;  //extra
    int address ;      //adrres of the symbol
    char *symbol;               //name of symbol
    struct bucket *next;        //next such node
}Bucket;



//Functions 

Bucket *CreateBucket(char *,int,int,int);

void CreateTable();
void Insert_In_Symbol(char *,int,int,int);
Bucket * GetSymbol(char *);
void FreeSymbolTable();
Key HashFunction( char *);
void symboltab_display();
char* itoa(int);
int IsNumber(char*);
Bool IsIdentifier(char *);
void Forward_reff(char*);
void insert_instruction(char*,int,int);
void Int_instr();
void Writing_Into_ObjectCode();
void FreeErrorTable();

