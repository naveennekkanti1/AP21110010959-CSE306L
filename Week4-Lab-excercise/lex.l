digit [0-9]*
letter [a-zA-Z]
id {letter}({letter}|{digit})*
int_num {digit}+
uint_num 0|({int_num})
float_num ({int_num}\.{digit}+)|({int_num}\.)|(\.{digit}+)
exp_num ({int_num}|{float_num})[eE][+-]?{int_num}
num {int_num}|{float_num}|{exp_num}

%{
    #include<stdio.h>
    #include<string.h>
    int i=0,j=0,cnt=0,n=0,com=0,scom=0;
    char st[10][10];
    int look_up(char st[10][10],char *id,int n);
%}

%%

\n {scom=0;n++;}
"//" {scom=1;}
"/*" {com=1;}
"*/" {com=0;}
int|float|char|double|string|else|struct|extern|long|switch|union|return|void {if(!com&&!scom) fprintf(yyout," \n %s is keyword",yytext);}
"<=" {if (!com&&!scom) fprintf(yyout,"\n %s is Relational operator Lessthan or Equal to",yytext);}
"<" {if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Lessthan",yytext);}
">=" {if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Greaterthan or Equal to",yytext);}
">" {if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Greaterthan",yytext);}
"==" {if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Equal to",yytext);}
"!=" {if (!com&&!scom) fprintf(yyout,"\n %s is Relational operator Not Equal to",yytext);}
":=" {if (!com&&!scom) fprintf(yyout,"\n %s is Assignment Operator",yytext);}

{num} {if(!com&&!scom) fprintf(yyout,"\n %s is numeric constant",yytext);}
{id} {if(!com&&!scom) fprintf(yyout,"\n %s is identifier",yytext); cnt++;
    if(!look_up(st,yytext,i))
        strcpy(st[i++],yytext);
}

. {if (!com&&!scom) fprintf(yyout,"\n %s is invalid input",yytext);}

%%

int main()
{
    yyin =fopen("x.txt","r");
    yyout=fopen("y.txt","w");
    yylex();
    fprintf(yyout,"\n\n the contents of symbol table are :\n");
    for(j=0;j<i;j++)
        fprintf(yyout,"\n %s",st[j]);
    fprintf(yyout,"\n\n");
    return 0;
}

int yywrap()
{
    return 1;
}

int look_up(char st[10][10],char *id,int n)
{
    for(j=0;j<n;j++)
        if(!strcmp(st[j],id))
            return 1;
    return 0;
}