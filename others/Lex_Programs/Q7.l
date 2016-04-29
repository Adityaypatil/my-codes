%{
	#include<stdio.h>
%}

start .*"the".*
%%
{start}{5,} {fprintf(yyout,"%s\n",yytext);}
. ;
%%

main()
{
	yyin=fopen("ip7","r");
	yyout=fopen("op7","w");
	yylex();
}

int yywrap()
{
	return 1;
}

