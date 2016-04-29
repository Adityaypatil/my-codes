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

