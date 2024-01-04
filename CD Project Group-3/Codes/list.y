%{ 
#include<stdio.h> 
%} 
%token NUMBER
%token DECIMAL 
%token STRING 
%token IDENTIFIER 
%% 
S: L { printf("correct");} 
; 
L: IDENTIFIER'='V { $$ = $1 = $3; } ; 
V: '('A')' { $$ = ( $2 ); } 
; 
A : 
| STRING','A { $$ = $1,$3; } | NUMBER','A { $$ = $1,$3; } | DECIMAL','A { $$ = $1,$3; } | STRING { $$ = $1; } 
| NUMBER { $$ = $1; } 
| DECIMAL { $$ = $1; } 
; 
%% 
int main(){ 
yyparse(); 
} 
int yywrap(){ 
return 1; 
} 
void yyerror(char *s){ 
printf("Error %s",s); 
}