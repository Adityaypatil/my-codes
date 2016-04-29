// Search in MOT
int binary_search_MOT(MOT m[MAX],int low,int high,char *key)
{
	int mid;
	if(low < high)
	{
		mid = (low+high)/2;
		if(strcmp(key,m[mid].mnemonic)==0)
		{
			return 0;
		}
		else if(strcmp(key,m[mid].mnemonic) > 0)
           	binary_search_MOT(m,mid+1,high,key);
	    else if(strcmp(key,m[mid].mnemonic) < 0)
             binary_search_MOT(m,low,mid,key);
	}
	else
		return 1;
}

// Search in RT
int binary_search_RTAB(RTAB r[REG_SIZE],int low,int high,char *key)
{
	int mid;
	if(low < high)
	{
		mid = (low+high)/2;
		if(strcmp(key,r[mid].reg)==0)
		{
			return 0;
		}
		else if(strcmp(key,r[mid].reg) > 0)
           	binary_search_RTAB(r,mid+1,high,key);
	    else if(strcmp(key,r[mid].reg) < 0)
            binary_search_RTAB(r,low,mid,key);
	}
	else
		return 1;
}

int search_STAB(SECTAB st,STAB s[],int count_stab)
{
	int i;
	for(i=0;i<count_stab;i++)
	{
		if(strcmp(st.name,s[i].symbol_name) == 0)
		{
			printf("\nError... Multiple declaration of variable %s\n",s[i].symbol_name);
			exit(0);
		}
	}
	return 0;
}
