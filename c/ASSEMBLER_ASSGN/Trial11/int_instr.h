void  Int_instr()
{
  Instruction *prev_ptr=TempInstPtr,*new_node=(Instruction *)malloc(sizeof(Instruction));
  bzero(new_node,sizeof(Instruction));
  TempInstPtr=new_node;
  if(!InstFmt)
    {
      InstFmt=new_node;
      InstFmt->next=new_node;
    }
  else
    
    {
    prev_ptr->next=new_node;
    new_node->next=NULL;
  }
}


