
%{
	#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "y.tab.h"
    

    int linha = 1;
    int comment = 0;

    void lexical_error(char* yytext) {
        fprintf(stderr, "Erro lexico na linha %d: %s\n", linha, yytext);
    }
%}

D       [0-9]
L       [a-zA-Z_]

%%

"/*"                    {comment = 1;}
"*/"                    {comment = 0;}
"//"(.)*\n              {}  
\n                      {linha++;
                         return EOL;
                        }
[" " | \t]              {}
("#include")((\ )+|"")("<")((\ )+|"")(.)*(".h")((\ )+|"")(">") { if(!comment) return IMPORTATION PROCESS; }
\(                      { if(!comment) return L_PARENTHESIS; }
\)                      { if(!comment) return R_PARENTHESIS; }
\{                      { if(!comment) return L_KEY; }
\}                      { if(!comment) return R_KEY; }
\[                      { if(!comment) return L_BRACKET; }
\]                      { if(!comment) return R_BRACKET; }
"if"                    { if(!comment) return IF_STM; }
"else"                  { if(!comment) return ELSE_STM; }
"else if"               { if(!comment) return ELSE_IF_STM;}
"for"                   { if(!comment) return FOR_STM; }
"do"                    { if(!comment) return DO_STM; }
"while"                 { if(!comment) return WHILE_STM; }
"int\ "                 { if(!comment) { 
                            yylval.sValue = strdup(yytext);
                            return INT_TYPE; }
                          }
                        }
"float\ "               { if(!comment) {
                            yylval.sValue = strdup(yytext);
                            return FLOAT_TYPE; 
                          }
                        }
"double\ "              { if(!comment) {
                            yylval.sValue = strdup(yytext);
                            return DOUBLE_TYPE; 
                          }
                        }
"string\ "              { if(!comment) {
                            yylval.sValue = strdup(yytext);
                            return STRING_TYPE; 
                          }
                        }
"boolean\ "             { if(!comment) {
                            yylval.sValue = strdup(yytext);
                            return BOOLEAN_TYPE; 
                          }
                        }
"matriz\ "              { if(!comment) { 
                            yylval.sValue = strdup(yytext);
                            return MATRIZ_TYPE; 
                          }
                        }
"void\ "                { if(!comment) {
                            yylval.sValue = strdup(yytext);
                            return VOID_TYPE; 
                          }
                        }
"const\ "               { if(!comment) return CONSTANT; }
"return"[" "|";"]       { if(!comment) return RETURN; }
"true"                  { if(!comment) return TRUE_VAL; }
"false"                 { if(!comment) return FALSE_VAL; }
{L}({L}|{D})*           { if(!comment) {
                            yylval.sValue = strdup(yytext);
                            return IDENTIFIER;
                          }
                        }
"+"                     { if(!comment) return PLUS_OP; }
"-"                     { if(!comment) return SUB_OP; }
"%"                     { if(!comment) return MOD_OP; }
"**"                    { if(!comment) return FACT_OP; }
"/"                     { if(!comment) return DIV_OP; }
"*"                     { if(!comment) return STAR; }
"++"                    { if(!comment) return INC_OP; }
"--"                    { if(!comment) return DEC_OP; }
"="                     { if(!comment) return ASSINGMENT; }
"&"                     { if(!comment) return ADDRESS; }
"&&"                    { if(!comment) return AND_OP; }
"||"                    { if(!comment) return OR_OP; }
"=="                    { if(!comment) return EQ_OP; }
"!="                    { if(!comment) return NE_OP; }
"!"                     { if(!comment) return NOT_OP; }
"<"                     { if(!comment) return S_OP; }
"<="                    { if(!comment) return SE_OP; }
">"                     { if(!comment) return G_OP; }
">="                    { if(!comment) return GE_OP; }
";"                     { if(!comment) return SEMICOLON; }
","                     { if(!comment) return COMMA; }
"."                     { if(!comment) return DOT; }    
"malloc\ "              { if(!comment) return MALLOC_OP; }
"calloc\ "              { if(!comment) return CALLOC_OP; }
"free"                  { if(!comment) return FREE_OP; }
[0-9]+                  { if(!comment) { 
                            yylval.iValue = atoi(yytext);
                            return LITERAL_INT;
                        } }
[0-9]*\.[0-9]+f         { if(!comment) {
                            yylval.fValue = atof(yytext);
                            return LITERAL_FLOAT;
                        } }
[0-9]*\.[0-9]+          { if(!comment) {
                            yylval.dValue = atof(yytext);
                            return LITERAL_DOUBLE;
                        } }
(\')([a-zA-Z])(\')      { if(!comment) {
                            yylval.cValue = strdup(yytext);
                            return LITERAL_CHAR;
                        } }
"\""(.)*"\""            { if(!comment) {
                            yylval.sValue = strdup(yytext);
                            return LITERAL_STRING;
                        } }
(\')(.)+(\')            { lexical_error("Char nao pode ter mais de um caractere"); }

.                       {lexical_error(yytext);}

%%

int yywrap() {
  return 1;
}
