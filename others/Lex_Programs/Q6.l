%{
	#include<stdio.h>
%}

rule ^.*("aa"|"uu").*$
%%
{rule} {fprintf(yyout,"%s\n",yytext);}
. ;
%%

main()
{
	yyin=fopen("ip6","r");
	yyout=fopen("op6","w");
	yylex();
}

int yywrap()
{
	return 1;
}

