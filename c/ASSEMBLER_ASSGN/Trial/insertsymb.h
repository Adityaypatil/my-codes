void InsertSymbol(char *name,int defined,int used,int address)
{
  
  Bucket *bket=CreateBucket(name,defined, used, address);
  Key key;
  key=HashFunction(bket->symbol);
  Bucket *tempNode;
  tempNode=symTab[key].link;
  symTab[key].link=bket;
  
  symTab[key].link->next=tempNode;
}


