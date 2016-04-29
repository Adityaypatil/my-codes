void   Working_On_SourceCode()
{
  int i=1;
  char *line=(char*)malloc(sizeof(char)*SIZE);
  if(fgets(line,SIZE,input_file)!=NULL)
    while(i)
      {
	IntLineNumber++;
	/* Section Checking*/
	
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

