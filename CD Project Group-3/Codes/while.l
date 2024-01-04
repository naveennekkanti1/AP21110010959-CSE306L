%{ 
#include "while.tab.h" 
%} 
%% 
"while" { return WHILE; } 
"else" { return ELSE; } 
"<print>" { return STARTPRINT; } 
"</print>" { return ENDPRINT; } 
[0-9]* { return NUMBER; } 
[0-9]\.[0-9] { return DECIMAL; }
\'[a-zA-Z]*\' { return STRING; } 
[a-zA-Z][a-zA-Z0-9]* { return IDENTIFIER; } ["<"|">"|"<="|">="|"="|"=="|"<>"] { return RELOP; } \n return 0; 
. return yytext[0]; 
%% 