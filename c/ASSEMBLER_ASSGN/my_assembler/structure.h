#include<stdio.h>
#define MAX 50
#define REG_SIZE 20

typedef struct symtab
{
	char symbol_name[20],symbol_value[50],symbol_type[20];
	int symbol_address,seq_no;
}STAB;

typedef struct mnemonics_table
{
	char mnemonic[10];
	char mnemonic_code[13];
	char number_of_parameters[10];
	int length;
}MOT;

typedef struct code
{
	char label[10];
	char mnemonic[10];
	char op1[10];
	char op2[10];
}CODE;

typedef struct ltab
{
	char literal_name[10];
	int literal_address;
	int literal_no;
}LTAB;

typedef struct register_table
{
	char reg[10];
	char reg_opcode[10];
}RTAB;

typedef struct section_table
{
	char name[10];
	char type[10];
	char value_char[50];
	int value_int;
}SECTAB;

typedef struct table_of_incomplete_instructions
{
	char name[10];
	int address;
}TII;


