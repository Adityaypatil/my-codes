%{
#include<stdio.h>
#include<stdlib.h>
  %}

%token ATOKEN BTOKEN END
%nonassoc ATOKEN
%nonassoc BTOKEN
%start line

%%
line: S END {printf("Accpted");exit(0);}
S : ATOKEN S ATOKEN
  | ATOKEN B ATOKEN
  ;
B : BTOKEN B
  |BTOKEN
  ;
%%

int main()
{
  yyparse();
  yylex();
  return END;
}

yyerror(char *s)
{
  printf("Invalid:%s",s);
}
