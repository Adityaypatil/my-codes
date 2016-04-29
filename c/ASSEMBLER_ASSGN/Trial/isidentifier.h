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
	    

