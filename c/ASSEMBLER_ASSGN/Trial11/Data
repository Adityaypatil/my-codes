void Data_section(char *line)
{
  char identifier[30],type[5],value[10];
 
  sscanf(line,"%s %s %s",identifier,type,value);
  fprintf(obfile,"%d\t%d\t%d\n",++location_cnt,atoi(value),line);
  
  
	  if(IsIdentifier(identifier))
	    Insert_In_Symbol(identifier,1,0,location_cnt);
	  
	  if(!IsFound(types,type))
	   Insert_In_ErrorTab(Line_num,6,++serial_no);
 
}

