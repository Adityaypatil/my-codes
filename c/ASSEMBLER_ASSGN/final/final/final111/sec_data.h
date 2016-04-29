int section_data()
{
	fscanf(fp,"%s%s",st.name,st.type);
	printf("%s %s ",st.name,st.type);

	search_key = st.name;
	search_value= binary_search_MOT(m,0,count,search_key);
	// Search found
	if(search_value == 0)
	{
		printf("\nMnemonic Found");
		printf("\nError... Variable name same as mnemonic name\n");
		exit(0);
	}	
	else
	{
		search_value= binary_search_RTAB(r,0,count,search_key);
	//	printf("\nMnemonic NotFound");
		if(search_value == 0)
		{
			//printf("\nReg Found");
			printf("\nError... Variable name same as Register name\n");
			exit(0);

		}
		else
		{
			//printf("\nReg NotFound");
		}
		if(strcmp(search_key,"section") == 0)
		{
			printf("\nError... section is not use as variable name\n");
			exit(0);

		}
	}
	
	while(strcmp(st.name,"section") != 0)
	{
		
	if(strcmp(st.type,"db") == 0)
	{
			fgets(st.value_char,sizeof(st.value_char),fp);
	//		printf("%s \n",st.value_char);
	
	}
	else if(strcmp(st.type,"dd") == 0 || strcmp(st.type,"dq") == 0 || strcmp(st.type,"dw") == 0)
	{
		fscanf(fp,"%s",st.value_char);
		//printf("%d \n",atoi(st.value_char));
	}
	else
	{
		printf("\nError... Not a data type of .data\n");
		exit(0);
	}
	// Entry in symbol table
	
	entry_in_stab(st,s);
	
	fscanf(fp,"%s%s",st.name,st.type);
//	printf("%s %s ",st.name,st.type);
	
	}
	if(strcmp(st.type,".text") == 0)
	{
		section_text();
	}
	else if(strcmp(st.type,".bss") == 0)
	{
		section_bss();
	}
	else
	{
		printf("\nInvalid Instruction\n");
	}
	return 0;
}

