%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "../estrutura-de-dados/hashTable.h"
#include "../estrutura-de-dados/list.h"
#include "../estrutura-de-dados/tuple.h"
#include "../estrutura-de-dados/utils.h"

void yyerror(char *msg);
int yylex(void);
extern int yylineno;
extern char * yytext;

int scope = 0;
List **varNamesScope;
HashTable *symbolTable;

//typedef enum { false = 0, true = !false } bool;

%}

%union {
    int    iValue;  /* integer value */
    float  fValue;  /* float value */
    double dValue;  /* double value */
    char * cValue;  /* char value */
    char * sValue;  /* string value */
    int    bValue;  /* boolean value */
    int line;
};

%start program

%token <sValue> LITERAL_STRING IDENTIFIER INT_TYPE FLOAT_TYPE DOUBLE_TYPE STRING_TYPE BOOLEAN_TYPE MATRIZ_TYPE VOID_TYPE LITERAL_CHAR CHAR_TYPE
%token <iValue> LITERAL_INT
%token <fValue> LITERAL_FLOAT  
%token <dValue> LITERAL_DOUBLE
%token <bValue> TRUE_VAL FALSE_VAL

%token PLUS_OP SUB_OP DIV_OP STAR MOD_OP FACT_OP ASSINGMENT
%token INC_OP DEC_OP  
%token GE_OP SE_OP EQ_OP NE_OP G_OP S_OP
%token AND_OP OR_OP NOT_OP
%token L_PARENTHESIS R_PARENTHESIS L_KEY R_KEY L_BRACKET R_BRACKET
%token IF_STM ELSE_STM ELSE_IF_STM FOR_STM DO_STM WHILE_STM SWITCH_STM CONTINUE BREAK PRINT PRINTF CASE DEFAULT
%token CONSTANT RETURN EOL ADDRESS SEMICOLON COMMA DOT DOUBLE_DOT
%token MALLOC_OP FREE_OP CALLOC_OP

%type <sValue> stm stm_list expres_list arit_expr log_expr expr term log_term op_log op_comp comp_expr term_num literal_string if_struct else_struct elseif_list elseif_struct switch_struct case_switch case_list_switch for_struct while_struct loop_stm cond_stm literal_term type par_list par_term fun_struct print_stm 
%type <sValue> id_list decl assingment initialization block

%left AND_OP OR_OP
%left GE_OP SE_OP EQ_OP NE_OP G_OP S_OP
%left PLUS_OP SUB_OP
%left STAR DIV_OP
%right FACT_OP MOD_OP

%%
/*
program : stm_list EOL  {
                            printf("%s", $1);
                            printf("\nClosing application... Bye...\n");
                            free($1);
                        }
        ; 
*/

program : stm_list  {
                            printf("%s", $1);
                            printf("\nClosing application... Bye...\n");
                            free($1);
                        }
        ;

stm_list    : stm SEMICOLON                {
                                            int size = strlen($1) + 2;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s;", $1);
                                            free($1);
                                            $$ = s;
                                        }
            | stm SEMICOLON stm_list    {
                                            int size = strlen($1) + strlen($3) + 3;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s;\n%s", $1, $3);
                                            free($1);
                                            free($3);
                                            $$ = s;
                                        }
            ;

stm : decl           {$$ = $1;} // TO DO: FAZER A ESTRUTURA DE DECLARAÇÔES
    | cond_stm       {$$ = $1;}
    | loop_stm       {$$ = $1;}
    | fun_struct     {$$ = $1;}
    | print_stm      {$$ = $1;}
    | expres_list    {$$ = $1;}
    | assingment     {$$ = $1;}
    | initialization {$$ = $1;}
    ;

decl : type id_list {
            char *key, *varName, *type;
            char *idscpy = malloc(strlen($2) * sizeof(char));

            strcpy(idscpy, $2);
            varName = strtok(idscpy, ",");
            while (varName != NULL) {
                type = utils_strRemoveSpace($1);
                key = utils_strAppendInt(varName, scope); 
                Tuple *result = hashTable_find(symbolTable, key);
                if(result != NULL) {printf("variavel %s ja declarada\n", varName); exit(EXIT_FAILURE);}
                utils_addVarSymbolTable(symbolTable, type, varName, key);
                free(type);
                list_add(varNamesScope[scope], key);
                varName = strtok(NULL, ",");
            }

            free(idscpy);

            int size = strlen($1) + strlen($2) + 2;
            char * s = malloc(sizeof(char) * size);
            sprintf(s, "%s %s", $1, $2);
            free($2);
            $$ = s;
        }
       ;

assingment : 
               IDENTIFIER ASSINGMENT expr {    
               Tuple *lhsVar = utils_findVar(symbolTable, $1, scope);
               if(lhsVar == NULL) {
                    printf("variavel %s nao foi declarada\n", $1);
                    exit(EXIT_FAILURE);
               }
               /*
               if(strcmp(rhsVar->type, $3->type) != 0) {
                    printf("o tipo da variavel %s (%s) ", $1, rhsVar->type); 
                    printf("e da expressao %s (%s) sao incompativeis\n", $3->value, $3->type); 
                    exit(EXIT_FAILURE);
               }
              */
               int size = strlen($1) + strlen($3) + 4;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s = %s", $1, $3);

               $$ = s;
          }
          ;


initialization : 
               type IDENTIFIER ASSINGMENT expr {
               char *type = utils_strRemoveSpace($1);
               /*
               if(strcmp(type, $4->type) != 0) {
                    printf("tipo da variavel %s incompativel com a expressao %s\n", $2, $4->value);
                    exit(EXIT_FAILURE);
               }
               */
               char *key = utils_strAppendInt($2, scope); 
               utils_addVarSymbolTable(symbolTable, type, $2, key);
               free(type);
               list_add(varNamesScope[scope], key);

               int size = strlen($1) + strlen($2) + strlen($4) + 4;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s %s = %s", $1, $2,$4);
               $$ = s;

          }
          ;

print_stm   : PRINT L_PARENTHESIS literal_string R_PARENTHESIS {
                                                                    int size = 8 + strlen($3);
                                                                    char * s = malloc(sizeof(char) * size);
                                                                    sprintf(s, "print(%s)", $3);
                                                                    $$ = s; 
                                                                }
            | PRINT L_PARENTHESIS literal_string COMMA id_list R_PARENTHESIS {
                                                                                int size = 10 + strlen($3) + strlen($5);
                                                                                char * s = malloc(sizeof(char) * size);
                                                                                sprintf(s, "print(%s, %s)", $3, $5);
                                                                                $$ = s;  
                                                                            }
            | PRINTF L_PARENTHESIS literal_string R_PARENTHESIS {
                                                                    int size = 9 + strlen($3);
                                                                    char * s = malloc(sizeof(char) * size);
                                                                    sprintf(s, "printf(%s)", $3);
                                                                    $$ = s; 
                                                                }
            | PRINTF L_PARENTHESIS literal_string COMMA id_list R_PARENTHESIS {
                                                                                int size = 11 + strlen($3) + strlen($5);
                                                                                char * s = malloc(sizeof(char) * size);
                                                                                sprintf(s, "printf(%s, %s)", $3, $5);
                                                                                $$ = s;  
                                                                            }
            ;

id_list : IDENTIFIER                {$$ = $1;}
        | IDENTIFIER COMMA id_list { 
                                        int size = 2 + strlen($1) + strlen($3);
                                        char * s = malloc(sizeof(char) * size);
                                        sprintf(s, "%s,%s", $1, $3);
                                        $$ = s;
                                    }
        ;

expres_list : expr SEMICOLON             {}
            | expr SEMICOLON expres_list {}
            ;

expr    : log_expr      { $$ = $1; }
        ;

cond_stm: if_struct         {$$ = $1;}
        | switch_struct     {$$ = $1;}
        ;

if_struct   : IF_STM L_PARENTHESIS log_expr R_PARENTHESIS block else_struct{
                                                            int size = 7 + strlen($3) + strlen($5) + strlen($6);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "if(%s) %s %s", $3, $5, $6);
                                                            $$ = s;
                                                        }
            ;
else_struct :   {char * s = malloc(sizeof(char) * 2);
                 sprintf(s, "e");
                 $$ = s;}
            | elseif_list ELSE_STM block {
                                                if(strcmp($1, "e") != 0) {
                                                    int size = 7 + strlen($1) + strlen($3);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s\nelse %s", $1, $3);
                                                    $$ = s;
                                                }else {
                                                    int size = 7 + strlen($3);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "\nelse %s", $3);
                                                    $$ = s;
                                                }
                                            }
            ;
elseif_list     :  {char * s = malloc(sizeof(char) * 2);
                    sprintf(s, "e");
                    $$ = s;}
                | elseif_struct elseif_list { 
                                                int size = 2 + strlen($1) + strlen($2);
                                                char * s = malloc(sizeof(char) * size);
                                                sprintf(s, "%s %s", $1, $2);
                                                $$ = s;
                                            }
                ;

elseif_struct   : ELSE_IF_STM L_PARENTHESIS log_expr R_PARENTHESIS L_KEY stm_list R_KEY {
                                    int size = 14 + strlen($3) + strlen($6);
                                    char * s = malloc(sizeof(char) * size);
                                    sprintf(s, "\nelseif(%s){\n\t%s}", $3, $6);
                                    free($6);
                                    $$ = s;
                                }
                ;

switch_struct   : SWITCH_STM L_PARENTHESIS literal_term R_PARENTHESIS L_KEY case_list_switch DEFAULT DOUBLE_DOT stm_list BREAK SEMICOLON R_KEY      {
                                        int size = 34 + strlen($3) + strlen($6) + strlen($9);
                                        char * s = malloc(sizeof(char) * size);
                                        sprintf(s, "switch(%s) {\n\t%s\n\tdefault: %s\nbreak;\n}", $3, $6, $9);
                                        free($6);
                                        free($9);
                                        $$ = s;
                                    }
                ;

case_list_switch: {}
                | case_switch case_list_switch { 
                                                    int size = 2 + strlen($1) + strlen($2);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s %s", $1, $2);
                                                    $$ = s;
                                                }
                ;

case_switch: CASE literal_term DOUBLE_DOT stm_list BREAK SEMICOLON {
                                                                        int size = 17 + strlen($2) + strlen($4);
                                                                        char * s = malloc(sizeof(char) * size);
                                                                        sprintf(s, "case %s:\n\t%s\nbreak;\n", $2, $4);
                                                                        free($4);
                                                                        $$ = s;
                                                                    }       
            ;      

loop_stm: while_struct      {$$ = $1;}
        | for_struct        {$$ = $1;}   
        ; 


while_struct: WHILE_STM L_PARENTHESIS log_expr R_PARENTHESIS L_KEY stm_list R_KEY   {}
            | DO_STM L_KEY stm_list R_KEY WHILE_STM L_PARENTHESIS log_expr R_PARENTHESIS    {}
            ;

for_struct  : FOR_STM L_PARENTHESIS SEMICOLON log_expr SEMICOLON R_PARENTHESIS L_KEY stm_list R_KEY {} // INCOMPLETO
            ;

fun_struct  : type IDENTIFIER L_PARENTHESIS par_list R_PARENTHESIS L_KEY stm_list R_KEY

block : L_KEY {scope++;} stm_list R_KEY {
          utils_removeVarScope(symbolTable, varNamesScope[scope]);
          int size = strlen($3) + 5;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "{\n%s\n}", $3);
          //free($3);
          $$ = s;
          scope--;
     }
     ;

type: VOID_TYPE     {$$ = $1;}
    | INT_TYPE      {$$ = $1;}
    | FLOAT_TYPE    {$$ = $1;}
    | DOUBLE_TYPE   {$$ = $1;}
    | CHAR_TYPE     {$$ = $1;}      
    | STRING_TYPE   {$$ = $1;}
    | BOOLEAN_TYPE  {$$ = $1;}
    | MATRIZ_TYPE   {$$ = $1;}
    ;

par_list:                           {}
        | par_term                  {$$ = $1;}
        | par_term COMMA par_list   { 
                                        int size = 2 + strlen($1) + strlen($3);
                                        char * s = malloc(sizeof(char) * size);
                                        sprintf(s, "%s,%s", $1, $3);
                                        $$ = s;
                                    }
        ;

par_term: type IDENTIFIER   { 
                                int size = 2 + strlen($1) + strlen($2);
                                char * s = malloc(sizeof(char) * size);
                                sprintf(s, "%s %s", $1, $2);
                                $$ = s;
                            }
        ;


arit_expr   : term {$$ = $1;}
            | L_PARENTHESIS arit_expr R_PARENTHESIS     { 
                                                            int size = 3 + strlen($2);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "(%s)", $2);
                                                            $$ = s;
                                                        }
            | arit_expr PLUS_OP term                    { 
                                                            int size = 4 + strlen($1) + strlen($3);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s + %s", $1, $3);
                                                            $$ = s;
                                                        }
            | arit_expr SUB_OP term                     { 
                                                            int size = 4 + strlen($1) + strlen($3);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s - %s", $1, $3);
                                                            $$ = s;
                                                        }
            | arit_expr DIV_OP term                     { 
                                                            int size = 4 + strlen($1) + strlen($3);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s / %s", $1, $3);
                                                            $$ = s;
                                                        }
            | arit_expr STAR term                       { 
                                                            int size = 4 + strlen($1) + strlen($3);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s * %s", $1, $3);
                                                            $$ = s;
                                                        }
            | arit_expr MOD_OP term                     { 
                                                            int size = 4 + strlen($1) + strlen($3);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s %s %s", $1, "%", $3);
                                                            $$ = s;
                                                        }
            | arit_expr INC_OP                          { 
                                                            int size = 3 + strlen($1);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s++", $1);
                                                            $$ = s;
                                                        }
            | arit_expr DEC_OP                          { 
                                                            int size = 3 + strlen($1);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s--", $1);
                                                            $$ = s;
                                                        }
            ;


comp_expr   : term                                  {$$ = $1;}
            | comp_expr op_comp arit_expr           { 
                                                        int size = 3 + strlen($1) + strlen($2) + strlen($3);
                                                        char * s = malloc(sizeof(char) * size);
                                                        sprintf(s, "%s %s %s", $1, $2, $3);
                                                        $$ = s;
                                                    }
            | literal_string EQ_OP literal_string   {$1 == $3;}
            | literal_string NE_OP literal_string   {$1 != $3;}
            ;

log_expr: comp_expr                            {$$ = $1;}
        | L_PARENTHESIS log_expr R_PARENTHESIS { 
                                                    int size = 3 + strlen($2);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "(%s)", $2);
                                                    $$ = s;
                                                }
        | log_expr op_log comp_expr            { 
                                                    int size = 3 + strlen($1) + strlen($2) + strlen($3);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s %s %s", $1, $2, $3);
                                                    $$ = s;
                                                }

        ;

term_num        : LITERAL_INT           { 
                                            char * s = malloc(sizeof(int));
                                            sprintf(s, "%d", $1);
                                            $$ = s;
                                        }
                | LITERAL_FLOAT         { 
                                            char * s = malloc(sizeof(float));
                                            sprintf(s, "%f", $1);
                                            $$ = s;
                                        }
                | LITERAL_DOUBLE        { 
                                            char * s = malloc(sizeof(double));
                                            sprintf(s, "%f", $1);
                                            $$ = s;
                                        }

literal_string  : LITERAL_CHAR          {$$ = strdup($1);}
                | LITERAL_STRING        {$$ = strdup($1);}
                ;

term    : term_num      {$$ = $1;}
        | IDENTIFIER    {$$ = $1;}
        | log_term      {$$ = $1;}

literal_term    : term                  {$$ = $1;}
                | literal_string        {$$ = $1;}

op_log  : AND_OP    {$$ = strdup("&&");}
        | OR_OP     {$$ = strdup("||");}
        | NOT_OP    {$$ = strdup("!") ;}
        ;

op_comp : SE_OP     {$$ = strdup("<=") ;}
        | S_OP      {$$ = strdup("<")  ;}
        | GE_OP     {$$ = strdup(">=") ;}
        | G_OP      {$$ = strdup(">")  ;}
        | EQ_OP     {$$ = strdup("==") ;}
        | NE_OP     {$$ = strdup("!=") ;}
        ;


log_term : TRUE_VAL     { 
                            char * s = malloc(sizeof(int));
                            sprintf(s, "%d", $1);
                            $$ = s;
                        }
         | FALSE_VAL    { 
                            char * s = malloc(sizeof(int));
                            sprintf(s, "%d", $1);
                            $$ = s;
                        }
         ;
%%

void yyerror (char *msg) {
        fprintf (stderr, "Erro na linha %d: %s em '%s'\n", yylval.line, msg, yytext);
}

int main() {
    symbolTable = hashTable_create(20);
    varNamesScope = malloc(10 * sizeof(List**));

    for(int i = 0; i < 10; i++) {
        varNamesScope[i] = list_create(10);
    }


    return yyparse();
}