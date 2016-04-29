%{
	#include<stdio.h>
%}

rule ^[ ][^aeiouA-Z]([a-z][a-z]|[a-z][a-z][a-z])[ ]$
%%
{rule} {fprintf(yyout,"%s\n",yytext);}
. ;
%%

main()
{
	yyin=fopen("ip2","r");
	yyout=fopen("op2","w");	
	yylex();
}

int yywrap()
{
	return 1;
}

