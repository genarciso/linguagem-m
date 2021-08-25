%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void yyerror(char *msg);
int yylex(void);
extern int yylineno;
extern char * yytext;
%}

%union {
    int    iValue;  /* integer value */
    float  fValue;  /* float value */
    double dValue   /* double value */
    char   cValue;  /* char value */
    char * sValue;  /* string value */
};

%token <sValue> LITERAL_STRING IDENTIFIER INT_TYPE FLOAT_TYPE DOUBLE_TYPE STRING_TYPE BOOLEAN_TYPE MATRIZ_TYPE VOID_TYPE
%token <iValue> LITERAL_INT
%token <fValue> LITERAL_FLOAT  
%token <dValue> LITERAL_DOUBLE

%token PLUS_OP SUB_OP DIV_OP STAR MOD_OP FACT_OP ASSINGMENT
%token INC_OP DEC_OP  
%token GE_OP SE_OP EQ_OP NE_OP G_OP S_OP
%token AND_OP OR_OP NOT_OP
%token L_PARENTHESIS R_PARENTHESIS L_KEY R_KEY L_BRACKET R_BRACKET
%token IF_STM ELSE_STM ELSE_IF_STM FOR_STM DO_STM WHILE_STM
%token TRUE_VAL FALSE_VAL
%token CONSTANT RETURN EOL ADDRESS SEMICOLON COMMA DOT
%token MALLOC_OP FREE_OP CALLOC_OP

%left GE_OP SE_OP EQ_OP NE_OP G_OP S_OP
%left AND_OP OR_OP
%left PLUS_OP SUB_OP
%left STAR DIV_OP

%start PROGRAM

%%
PROGRAM : 
        | PROGRAM STM_LIST EOL  {
                                    printf("%s\n%s", $1, $2);
                                    free($1);
                                    free($2);
                                }
        ; 

STM_LIST    : STM SEMICOLON             {$$ = $1;}
            | STM_LIST SEMICOLON STM    {
                                            int size = strlen($1) + strlen($3) + 3;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s;\n%s", $1, $3);
                                            free($1);
                                            free($3);
                                            $$ = s;
                                        }
            ;

STM : EXPRS_LIST                        {$$ = $1;}
    | IDENTIFIER ASSINGMENT EXPRS_LIST  {
                                            int size = strlen($1) + strlen($3) + 4;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s = %s", $1, $3);
                                            free($3);
                                            $$ = s;
                                        }
    | WHILE_STM L_PARENTHESIS LOG_EXPR R_PARENTHESIS L_KEY STM_LIST R_KEY   {}
    | DO_STM L_KEY STM_LIST R_KEY WHILE_STM L_PARENTHESIS LOG_EXPR R_PARENTHESIS    {}
    | IF_STM L_PARENTHESIS LOG_EXPR R_PARENTHESIS L_KEY STM_LIST R_KEY  {
                                                            int size = 12 + strlen($3) + strlen($6);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "if (%s) {\n\t%s }", $3, $6);
                                                            free($6);
                                                            $$ = s;
                                                        }
    | IF_STM L_PARENTHESIS LOG_EXPR R_PARENTHESIS L_KEY STM_LIST R_KEY ELSE_STM L_KEY STM_LIST R_KEY  {
                                                            int size = 21 + strlen($3) + strlen($6) + strlen($10);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "if (%s) {\n\t%s } else{\n\t%s}", $3, $6, $10);
                                                            free($6);
                                                            free($10)
                                                            $$ = s;
                                                        }
    | IF_STM L_PARENTHESIS LOG_EXPR R_PARENTHESIS L_KEY STM_LIST R_KEY ELSE_IF_STM L_PARENTHESIS LOG_EXPR R_PARENTHESIS L_KEY STM_LIST R_KEY ELSE_STM L_KEY STM_LIST R_KEY  {
                                    int size = 38 + strlen($3) + strlen($6) + strlen($10) + strlen($13) + strlen($17);
                                    char * s = malloc(sizeof(char) * size);
                                    sprintf(s, "if (%s) {\n\t%s }\n elseif(%s) {\n\t%s}\n else{\n\t%s}", $3, $6, $10, $13, $17);
                                    free($6);
                                    free($13);
                                    free($17)
                                    $$ = s;
                                }
    ;

EXPRS_LIST  : EXPR EXPR_LIST

EXPR    : ARIT_EXPR     { $$ = $1; }
        | LOG_EXPR      { $$ = $1; }
        ;


ARIT_EXPR   : TERM {$$ = $1;}
            | TERM PLUS_OP ARIT_EXPR {$$ = $1 + $3;}
            | TERM SUB_OP ARIT_EXPR {$$ = $1 - $3;}
            | TERM DIV_OP ARIT_EXPR {$$ = $1 / $3;}   
            ;

TERM    : LITERAL_INT {$$ = $1;}
        | LITERAL_FLOAT {$$ = $1;}
        | LITERAL_DOUBLE {$$ = $1;}
        | LITERAL_CHAR {$$ = $1;}
        | LITERAL_STRING {$$ = $1;}
        ;

LOG_EXPR : TERM_LOG {$$ = $1;}
         | ARIT_EXPR AND_OP LOG_EXPR  {$$ = $1 && $3;}
         | ARIT_EXPR OR_OP LOG_EXPR  {$$ = $1 || $3;}
         | ARIT_EXPR S_OP LOG_EXPR  {$$ = $1 < $3;}
         | ARIT_EXPR SE_OP LOG_EXPR  {$$ = $1 <= $3;}
         | ARIT_EXPR G_OP LOG_EXPR  {$$ = $1 > $3;}
         | ARIT_EXPR GE_OP LOG_EXPR  {$$ = $1 >= $3;}
         | ARIT_EXPR EQ_OP LOG_EXPR  {$$ = $1 == $3;}
         ;

TERM_LOG : TRUE_VAL {$$ = $1;}
         | FALSE_VAL {$$ = $1;}
         ;
%%

int yyerror (char *msg) {
        fprintf (stderr, "Erro na linha %d: %s em '%s'\n", yylineno, msg, yytext);
        return 0;
}

int main() {
    return yyparse();
}