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

