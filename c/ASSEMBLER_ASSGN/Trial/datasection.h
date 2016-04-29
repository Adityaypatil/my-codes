void InDataSection(char *line)
{
  char identifier[30],type[5],value[10];
 
  sscanf(line,"%s %s %s",identifier,type,value);
  fprintf(obfile,"%d\t%d\t%d\n",++location_cnt,atoi(value),line);
  
  
  if(IsIdentifier(identifier))
    InsertSymbol(identifier,1,0,location_cnt);
  
  if(!IsFound(types,type))
   InsertIntoErrorTable(IntLineNumber,6,++serialNumber);
 
}
