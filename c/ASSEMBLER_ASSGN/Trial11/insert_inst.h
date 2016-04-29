
void insert_instruction(char *str,int element ,int flag)
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
