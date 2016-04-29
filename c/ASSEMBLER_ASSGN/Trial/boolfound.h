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
