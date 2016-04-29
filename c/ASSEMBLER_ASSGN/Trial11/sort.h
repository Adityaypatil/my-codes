
Bucket *CreateBucket(char *name,int defined,int used,int address)
{
    Bucket *newNode=(Bucket *) malloc(sizeof(Bucket));
    newNode->symbol=(char *) malloc(sizeof(strlen(name)));
    strcpy(newNode->symbol,name);
    newNode->defined=defined;
    newNode->used=used;
    newNode->address=address;
    newNode->next=NULL;
    return newNode;
}

void CreateTable()
{
  int i=0;
  
  while(i<TABSIZE)
    symTab[i++].link=NULL;
}



Bucket * GetSymbol(char * symbol)
{
    Key key;
    Bucket *bp;
    int found;
    
    key = HashFunction(symbol);
    bp = symTab[key].link;
    
    found = 0;
    while (bp != NULL && found == 0)
    {
	if (strcmp(symbol, bp->symbol) == 0)
	    found = 1;
	else
	    bp = bp->next;
    }
    return  bp;
}

Key HashFunction( char *C_Key)
{
    char *charPtr;
    int key;
    
    charPtr = C_Key;
    key = 0;
    while (*charPtr)
	key = ((key << 1) ^ (*charPtr++)) & 0x3fff;
    
    return (key % TABSIZE);
}

