
void   Working_On_SourceCode()
{
  int i=1;

  char *line=(char*)malloc(sizeof(char)*SIZE);
  
  if(fgets(line,SIZE,input_file)!=NULL)
	while(i)
	  {
		Line_num++;
		
		if(!strncmp ("section.data",line,12))
		  {
	
		    if(!fgets(line,SIZE,input_file))
		    	  goto end;
	
		    else
		      {
			      while(strncmp ("section.text",line,12)!=0)
				{
				 Line_num++;
					 Data_section(line);
					  if(!fgets(line,SIZE,input_file))
        				       goto end;
				}
	      
  		if(!fgets(line,SIZE,input_file))
			goto end;
	
	      Line_num++;
	      
	while(1)
			{  
			  Int_instr();
			  if(forword_ref)
			    Forward_reff(line);
			  else
			    Text_section(line);
			  if(!fgets(line,SIZE,input_file))
			    goto end;
			  Line_num;
		      }
		  }	  
	end:i=0;
	
     	 }
  
	}
}

