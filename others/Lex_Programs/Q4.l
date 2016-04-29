%{
	#include<stdio.h>
%}

final ^.*("pune"|"mumbai").*$
%%
{final} {fprintf(yyout,"%s\n",yytext);}
. ;
%%

main()
{
	yyin=fopen("ip4","r");
	yyout=fopen("op4","w");
	yylex();
}

int yywrap()
{
	return 1;
}

