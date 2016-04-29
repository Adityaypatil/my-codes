%{
#include "y.tab.h"
%}

%%
[aA]+ {return ATOKEN;}
[bB]+ {return BTOKEN;}
[\n] {return END;}
.     {return yytext[0];}
%%
