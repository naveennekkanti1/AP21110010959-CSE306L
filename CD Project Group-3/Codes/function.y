%{
#include<stdio.h>
#include<string.h>
%}

%token NUMBER
%token DECIMAL
%token STRING
%token IDENTIFIER
%token OP
%token DEF
%token STARTPRINT
%token ENDPRINT
%token RETURN

%%
F: DEF '(' N ')' ':' V{ printf("correct");}
;

N: IDENTIFIER '(' P ')' 
;

P :  
| STRING','P  
| NUMBER','P 
| DECIMAL','P 
| IDENTIFIER','P 
| STRING 
| NUMBER 
| DECIMAL 
| IDENTIFIER 
;

V : STARTPRINT '(' E ')' ENDPRINT
| RETURN '(' E ')' 
;

E : IDENTIFIER 
| IDENTIFIER OP IDENTIFIER 
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