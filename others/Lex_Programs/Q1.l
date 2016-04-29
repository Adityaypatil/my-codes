%{
#include<stdio.h>
%}
rule ^[ ][0-9][0-9][0-9]\.[0-9][0-9][0-9]\.[0-9][0-9][0-9][0-9][ ]$
%%
{rule} {fprintf(yyout,"%s\n",yytext);}
. ;
%%
main()
{
	yyin=fopen("ip1","r");
	yyout=fopen("op1","w");
yylex();
}

int yywrap()
{
return 1;
}
