%{
	#include<stdio.h>
%}

start ^the.*the$
%%
{start} {fprintf(yyout,"%s\n",yytext);}
. ;
%%

main()
{
	yyin=fopen("ip3","r");
	yyout=fopen("op3","w");
	yylex();
}

int yywrap()
{
	return 1;
}

