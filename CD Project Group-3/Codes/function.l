%{
#include "function.tab.h"
%}

%%

"def" { return DEF; }

"<print>" { return STARTPRINT; }

"</print>" { return ENDPRINT; }

"return" { return RETURN; }

[0-9]* { return NUMBER; }

[0-9]*\.[0-9]* { return DECIMAL; }

\'[a-zA-Z]*\' { return STRING; }

[a-zA-Z][a-zA-Z0-9]* { return IDENTIFIER; }

["+" | "-" | "*" | "%" | "//" | "<" | ">" | "=="] { return OP; }

\n return 0;

. return yytext[0];

%%