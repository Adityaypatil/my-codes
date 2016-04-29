
void InsertIntoErrorTable(int line_no,int err_no,int sr_no)
{
  
  dynamicErrorTable *new_node;
    
  new_node=(dynamicErrorTable *) malloc(sizeof(dynamicErrorTable));
  
  new_node->sr_no=sr_no;
  new_node->err_no=err_no;
  new_node->line_no=line_no;
  new_node->next=error_table_head;
  error_table_head=new_node;
}
