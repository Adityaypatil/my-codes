Bool IsIdentifier(char *identifier)
{
  if(!isalpha(identifier[0]))
    {

      Insert_In_ErrorTab(Line_num,3,++serial_no);
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
}
