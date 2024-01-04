%{ 
#include<stdio.h> 
%} 
%token NUMBER 
%token DECIMAL 
%token STRING 
%token IDENTIFIER 
%token RELOP 
%token WHILE 
%token STARTPRINT 
%token ENDPRINT 
%token ELSE 
%% 
L: WHILE '(' C ')' ':' P E { printf("correct"); } ; 
C: T 
| T RELOP C 
; 
T: IDENTIFIER 
| N 
;
N: NUMBER 
| DECIMAL 
; 
E: 
| ELSE ':' P 
; 
P: STARTPRINT '(' T ')' ENDPRINT 
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