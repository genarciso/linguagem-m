%{
#include <stdio.h>
#include <string.h>
#include "./estrutura-de-dados/hashTable.h"
#include "./estrutura-de-dados/list.h"
#include "./estrutura-de-dados/tuple.h"
#include "./estrutura-de-dados/utils.h"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;
int scope = 0;
List **varNamesScope;
HashTable *symbolTable;


%}

%union {
     int    iValue;      /* integer value */
     char   cValue;      /* char value */
     char * sValue;      /* string value */
     struct RuleInfo * lValue;
};

%token <sValue> ID TYPE COMMA SEMICOLON L_PARENTHESIS R_PARENTHESIS L_KEY R_KEY L_BRACKET R_BRACKET 
%token <sValue> IF WHILE FOR DO ELSE ELSE_IF AND_OP OR_OP PLUS_OP SUB_OP DIV_OP FACT_OP INC_OP DEC_OP
%token <sValue> LITERAL_INT LITERAL_FLOAT LITERAL_DOUBLE LITERAL_CHAR LITERAL_STRING LITERAL_BOOLEAN EQUAL_SIGN

%start PROGRAM

%type <sValue> DECLS_STM_LIST DECLS DECL IDS STM_LIST STM ASSINGMENT WHILE_STM FOR_STM IF_STM_CPL IF_STM BLOCK INITIALIZATION UNARY_OP INCREMENT LOOP_STM DECREMENT ELSE_IF_STM ELSE_STM ELSE_IF_STM_LIST
%type <lValue> TERM ARIT_EXPR LOG_EXPR EXPR 

%%
PROGRAM : DECLS_STM_LIST{
         printf("%s\n", $1);
         printf("\nClosing application... Bye...\n");
         free($1);
       }  
      ;

DECLS_STM_LIST : 
               DECLS DECLS_STM_LIST {
                    int size = strlen($1) + strlen($2) + 3;
                    char * s = malloc(sizeof(char) * size);
                    sprintf(s, "%s\n%s\n", $1, $2);
                    free($2);
                    $$ = s;
               }
               | STM_LIST DECLS_STM_LIST{
                    int size = strlen($1) + strlen($2) + 3;
                    char * s = malloc(sizeof(char) * size);
                    sprintf(s, "%s\n%s\n", $1, $2);
                    free($2);
                    $$ = s;
               }
               | DECLS {$$ = $1;} 
               | STM_LIST {$$ = $1;}
               ;

DECLS :  DECL       {$$ = $1;}
       | DECL DECLS {
           int size = strlen($1) + strlen($2) + 2;
           char * s = malloc(sizeof(char) * size);
           sprintf(s, "%s\n%s", $1, $2);
           free($1);
           free($2);
           $$ = s;
       }
       ;

DECL : TYPE IDS SEMICOLON {
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

          int size = strlen($1) + strlen($3) + 3;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "%s %s;", $1, $2);
          free($2);
          $$ = s;
     }
     | INITIALIZATION SEMICOLON {
          int size = strlen($1) + 2;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "%s;", $1);
          $$ = s;
          free($1);
     }
     ;

IDS : ID {$$ = $1;}
    | ID COMMA IDS {
      int size = strlen($1) + strlen($3) + 3;
      char * s = malloc(sizeof(char) * size);
      sprintf(s, "%s,%s", $1, $3);
      free($3);
      $$ = s;
    }
    ;

STM_LIST : STM           {$$ = $1;}
         | STM STM_LIST  {
               int size = strlen($1) + strlen($2) + 3;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s\n%s", $1, $2);
               free($1);
               free($2);
               $$ = s;
          }
         ;

STM : 
       IF_STM_CPL
     | ASSINGMENT SEMICOLON {
          int size = strlen($1) + 2;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "%s;", $1);
          $$ = s;
          free($1);
     }
     | UNARY_OP SEMICOLON {
          int size = strlen($1) + 2;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "%s;", $1);
          $$ = s;
          free($1);
     }
     | LOOP_STM
     ;

LOOP_STM : 
            WHILE_STM
          | FOR_STM
          ;

ASSINGMENT : 
               ID EQUAL_SIGN EXPR {    
               Tuple *rhsVar = utils_findVar(symbolTable, $1, scope);
               if(rhsVar == NULL) {
                    printf("variavel %s nao foi declarada\n", $1);
                    exit(EXIT_FAILURE);
               }

               if(strcmp(rhsVar->type, $3->type) != 0) {
                    printf("o tipo da variavel %s (%s) ", $1, rhsVar->type); 
                    printf("e da expressao %s (%s) sao incompativeis\n", $3->value, $3->type); 
                    exit(EXIT_FAILURE);
               }

               int size = strlen($1) + strlen($3->value) + 4;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s = %s", $1, $3->value);

               $$ = s;
          }
          ;

INITIALIZATION : 
               TYPE ID EQUAL_SIGN EXPR {
               char *type = utils_strRemoveSpace($1);
               if(strcmp(type, $4->type) != 0) {
                    printf("tipo da variavel %s incompativel com a expressao %s\n", $2, $4->value);
                    exit(EXIT_FAILURE);
               }

               char *key = utils_strAppendInt($2, scope); 
               utils_addVarSymbolTable(symbolTable, type, $2, key);
               free(type);
               list_add(varNamesScope[scope], key);

               int size = strlen($1) + strlen($2) + strlen($4->value) + 4;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s %s = %s", $1, $2,$4->value);
               $$ = s;

          }
          ;

IF_STM_CPL : 
       IF_STM {$$ = $1;}
     |
       IF_STM ELSE_IF_STM_LIST {
          int size = strlen($1) + strlen($2) + 2;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "%s %s", $1, $2);
          free($1);
          free($2);
          $$ = s;
     }
     | IF_STM ELSE_IF_STM_LIST ELSE_STM {
          int size = strlen($1) + strlen($2) + strlen($3) + 2;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "%s %s %s", $1, $2, $3);
          free($1);
          free($2);
          free($3);
          $$ = s;
     }
     | IF_STM ELSE_STM {
          int size = strlen($1) + strlen($2) + 2;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "%s %s", $1, $2);
          free($1);
          free($2);
          $$ = s;
     }
     ;

IF_STM : IF L_PARENTHESIS LOG_EXPR R_PARENTHESIS BLOCK {
          int size = strlen($3->value) + strlen($5) + 6;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "if(%s) %s", $3->value, $5);
          $$ = s;
     }
     ;

ELSE_IF_STM_LIST : 
                   ELSE_IF_STM {$$ = $1;}
                 | ELSE_IF_STM ELSE_IF_STM_LIST {
                    int size = strlen($1) + strlen($2) + 2;
                    char * s = malloc(sizeof(char) * size);
                    sprintf(s, "%s %s", $1, $2);
                    free($1);
                    free($2);
                    $$ = s;
                 }
                 ;


ELSE_IF_STM :
            ELSE_IF L_PARENTHESIS LOG_EXPR R_PARENTHESIS BLOCK {
               int size = strlen($3->value) + strlen($5) + 11;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "else if(%s) %s", $3->value, $5);
               //free($3);
               //free($5);
               $$ = s;
          }
          ;

ELSE_STM : ELSE BLOCK {
          int size = strlen($2) + 6;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "else %s", $2);
          //free($1);
          //free($2);
          $$ = s;
     }
     ;

WHILE_STM : WHILE L_PARENTHESIS LOG_EXPR R_PARENTHESIS BLOCK {
          int size = strlen($3->value) + strlen($5) + 10;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "while(%s) %s\n", $3->value, $5);
          free($5);
          $$ = s;
     }
     ;

FOR_STM: FOR L_PARENTHESIS INITIALIZATION SEMICOLON LOG_EXPR SEMICOLON UNARY_OP R_PARENTHESIS BLOCK {
               int size = strlen($3) + strlen($5->value) + strlen($7)  + strlen($9) + 13;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "for(%s;%s;%s) %s\n", $3, $5->value, $7, $9);
               free($3);
               free($5);
               free($7);
               free($9);
               $$ = s;
          }
       ;

BLOCK : L_KEY {scope++;} DECLS_STM_LIST R_KEY {
          //hashTable_display(symbolTable);
          utils_removeVarScope(symbolTable, varNamesScope[scope]);
          int size = strlen($3) + 5;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "{\n%s\n}", $3);
          //free($3);
          $$ = s;
          scope--;
     }
     ;

UNARY_OP: INCREMENT {$$ = $1;}
        | DECREMENT {$$ = $1;}
        ;

INCREMENT : ID INC_OP {
               Tuple *var = utils_findVar(symbolTable, $1, scope);
               if(var == NULL) {
                    printf("variavel %s nao foi declarada\n", $1);
                    exit(EXIT_FAILURE);
               }

               if(!(strcmp(var->type, "int") == 0  || strcmp(var->type, "float") == 0 || strcmp(var->type, "double") == 0)) {
                    printf("operacao ++ incompativel com a variavel %s\n", $1);
                    exit(EXIT_FAILURE);
               }

               int size = strlen($1) + 3;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s++", $1);
               $$ = s;
          }
          ;

DECREMENT : ID DEC_OP {
               Tuple *var = utils_findVar(symbolTable, $1, scope);
               if(var == NULL) {
                    printf("variavel %s nao foi declarada\n", $1);
                    exit(EXIT_FAILURE);
               }

               if(!(strcmp(var->type, "int") == 0  || strcmp(var->type, "float") == 0 || strcmp(var->type, "double") == 0)) {
                    printf("operacao -- incompativel com a variavel %s\n", $1);
                    exit(EXIT_FAILURE);
               }

               int size = strlen($1) + 3;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s--", $1);
               $$ = s;
          }
          ;

EXPR : LOG_EXPR {$$ = $1;}
     | ARIT_EXPR {$$ = $1;}
     ;

LOG_EXPR : TERM  { $$ = $1; }
         | EXPR AND_OP LOG_EXPR  {
              if(strcmp($1->type,"boolean") != 0) {
                    printf("%s nao e um boolean\n", $1->value);
                    exit(EXIT_FAILURE);
               }

               if(strcmp($3->type,"boolean") != 0) {
                    printf("%s nao e um boolean\n", $3->value);
                    exit(EXIT_FAILURE);
               }

               int size = strlen($1->value) + strlen($3->value) + 5;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s && %s", $1->value, $3->value);
               $$ = utils_createRuleInfo(s, $1->type);
               utils_freeRuleInfo($1);
               utils_freeRuleInfo($3);
          }
         | EXPR OR_OP LOG_EXPR  {
              if(strcmp($1->type,"boolean") != 0) {
                    printf("%s nao e um boolean\n", $1->value);
                    exit(EXIT_FAILURE);
               }

               if(strcmp($3->type,"boolean") != 0) {
                    printf("%s nao e um boolean\n", $3->value);
                    exit(EXIT_FAILURE);
               }

               int size = strlen($1->value) + strlen($3->value) + 5;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s || %s", $1->value, $3->value);
               $$ = utils_createRuleInfo(s, $1->type);
               utils_freeRuleInfo($1);
               utils_freeRuleInfo($3);
          }
         ; 

ARIT_EXPR : TERM { $$ = $1; }
          | TERM PLUS_OP ARIT_EXPR {
               if(strcmp($1->type, $3->type) == 0) {
                    int size = strlen($1->value) + strlen($3->value) + 4;
                    char * s = malloc(sizeof(char) * size);
                    sprintf(s, "%s + %s", $1->value, $3->value);
                    
                    $$ = utils_createRuleInfo(s, $1->type);
                    utils_freeRuleInfo($1);
                    utils_freeRuleInfo($3);
               }else {
                    printf("tipo diferentes entre %s e %s\n", $1->value, $3->value); 
                    exit(EXIT_FAILURE);
               }
          } 
          ;

TERM : LITERAL_INT    {$$ = utils_createRuleInfo($1, "int");}
     | LITERAL_FLOAT  {$$ = utils_createRuleInfo($1, "float");}
     | LITERAL_DOUBLE {$$ = utils_createRuleInfo($1, "double");}
     | LITERAL_CHAR   {$$ = utils_createRuleInfo($1, "char");}
     | LITERAL_STRING {$$ = utils_createRuleInfo($1, "string");}
     | ID {
          Tuple *var = utils_findVar(symbolTable, $1, scope);
          if(var == NULL) {
               printf("variavel %s nao foi declarada\n", $1);
               exit(EXIT_FAILURE);
          }

          $$ = utils_createRuleInfo($1, var->type);
     }
     | LITERAL_BOOLEAN {$$ = utils_createRuleInfo($1, "boolean");}
     ;
%%

int main (void) {
     symbolTable = hashTable_create(20);
     varNamesScope = malloc(10 * sizeof(List**));

     for(int i = 0; i < 10; i++) {
          varNamesScope[i] = list_create(10);
     }

     return yyparse ( );
}

int yyerror (char *msg) {
     fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
     return 0;
}