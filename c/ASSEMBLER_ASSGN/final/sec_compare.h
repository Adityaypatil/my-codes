int section_compare(SECTAB st)
{
	
	if(strcmp(st.name,"section")==0)
	{
		if(strcmp(st.type,".data")==0)
		{
			//printf("Success data\n");
			section_data();
		}
		else if(strcmp(st.type,".bss")==0)
		{
		//	printf("Success bss\n");
			section_bss();
		}
		else if(strcmp(st.type,".text")==0)
		{
		//	printf("Success text\n");
			section_text();
		}
		
	}
	else
	{
		printf("\nInvalid Instruction\n");
	}
	printf("\n");
	return 0;
}

