%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%%
^A0 {printf("<table>\n<tr>\n");}
^A[0-­9]* {printf("</tr>\n<tr>\n");}
^[B-Z][0-­9]*;	
[0­-9]* {printf("<td> "); ECHO; printf("</td>\n");}
[0­-9]*"."[0-­9]* {printf("</td> "); ECHO; printf("</td>/n");}
\"[^"]*\" {printf("<td> "); yytext[yyleng-1]=' '; printf("%s </td>\n",yytext+1);}
=	;
[ \n]	;
.	ECHO;
%%

main() 
{
  printf("<html>\n");
  yylex();
  printf("</tr>\n</table>\n</html>\n");
  
}

int yywrap(void)
{
	return 1;
}
