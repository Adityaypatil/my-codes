
void Writing_Into_ObjectCode()
{
  Instruction *head=InstFmt;
  
  if(!head)
    printf("Empty...\n");
  else
    {
      
    while(head)
      {
	fprintf(obfile,"%s\t%s\t%s\t%s\n",head->opcode,head->mode,head->operand1,head->operand2);
	head=head->next;
	
      }
    }
}

