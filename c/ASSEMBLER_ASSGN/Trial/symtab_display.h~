
void symboltab_display()
{printf("\n\n** Printing SYMBOL TABLE  **\n\n");
  int i=0,j=0;
  Bucket *bct_ptr;
  bct_ptr=(Bucket*)malloc(sizeof(Bucket));
  printf("----------------------------------------------------------------------\n");
   printf(" Serial  ||    Name    ||    Defined    ||     Used    ||    Address  \n");
  printf("----------------------------------------------------------------------\n");
  while(i<TABSIZE)
    {
      if(symTab[i].link)

	{
	  bct_ptr=symTab[i].link;
	  while(bct_ptr)
	    {
	     
printf(" %d\t|\t%s\t|\t%d\t|\t%d\t|\t%d  \n\n",j,bct_ptr->symbol,bct_ptr->defined,bct_ptr->used,bct_ptr->address);
	      bct_ptr=bct_ptr->next;
	      j++;
	    }
	}
      i++;
    }
}
