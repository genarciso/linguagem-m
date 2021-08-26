%{
#include <stdio.h>
#include <string.h>
#include "./estrutura-de-dados/hashTable.h"
#include "./estrutura-de-dados/tuple.h"
#include "./estrutura-de-dados/utils.h"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;
int scope = 0;
char ***varNamesScope;
HashTable *symbolTable;


%}

%union {
    int    iValue;  /* integer value */
    char   cValue;  /* char value */
    char * sValue;      /* string value */
     struct RuleInfo * lValue;
};

%token <sValue> ID TYPE COMMA SEMICOLON L_PARENTHESIS R_PARENTHESIS L_KEY R_KEY L_BRACKET R_BRACKET 
%token <sValue> IF WHILE DO ELSE ELSE_IF FOR AND_OP OR_OP PLUS_OP SUB_OP DIV_OP FACT_OP
%token <sValue> LITERAL_INT LITERAL_FLOAT LITERAL_DOUBLE LITERAL_CHAR LITERAL_STRING LITERAL_BOOLEAN EQUAL

%start PROGRAM

%type <sValue> DECLS_STM_LIST DECLS DECL IDS STM_LIST STM ASSINGMENT WHILE_STM FOR_STM DO_STM IF_STM ELSE_STM ELSE_IF_STM BLOCK INITIALIZATION
%type <lValue> TERM ARIT_EXPR LOG_EXPR EXPR

%%
PROGRAM : DECLS_STM_LIST{
        printf("%s\n", $1);
         printf("%d\n", scope);
        printf("\nClosing application... Bye...\n");
        free($1);
       }  
     ;

DECLS_STM_LIST : DECLS {$$ = $1;} 
               | STM_LIST {$$ = $1;}
               | DECLS DECLS_STM_LIST {
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
          char **varNames = malloc(utils_countComan($2) + 2 * sizeof(char**));
          int index = 0;
          strcpy(idscpy, $2);
          varName = strtok(idscpy, ",");
          while (varName != NULL) {
               type = utils_strRemoveSpace($1);
               Tuple *tuple = tuple_create(varName, type);
               free(type);
               key = utils_strAppendInt(varName, scope);
               Tuple *result = hashTable_find(symbolTable, key);
               if(result != NULL) {printf("variavel %s ja declarada\n", varName); exit(EXIT_FAILURE);}
               hashTable_insert(symbolTable, key, tuple);
               varNames[index] = key;
               index++;
               varName = strtok(NULL, ",");
          }
          varNames[index] = NULL;
          varNamesScope[scope] = varNames;
          free(idscpy);

          int size = strlen($1) + strlen($3) + 3;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "%s %s;\n", $1, $2);
          free($2);
          $$ = s;
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
       ASSINGMENT
     | IF_STM
     | WHILE_STM
     | INITIALIZATION
     ;

ASSINGMENT : ID EQUAL ID SEMICOLON {
          Tuple *rhsVar, *lhsVar;

          rhsVar = utils_findVar(symbolTable, $1, scope);
          if(rhsVar == NULL) {
               printf("variavel %s nao foi declarada\n", $1);
               exit(EXIT_FAILURE);
          }
          
          lhsVar = utils_findVar(symbolTable, $3, scope);
          if(lhsVar == NULL) {
               printf("variavel %s nao foi declarada\n", $3); 
               exit(EXIT_FAILURE);
          }

          if(strcmp(rhsVar->type, lhsVar->type) != 0) {
               printf("os tipos das variaveis %s e %s nao sao compativeis\n", $1, $3); 
               exit(EXIT_FAILURE);
          }

          int size = strlen($1) + strlen($3) + 5;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "%s = %s;\n", $1, $3);

          $$ = s;
     }
     | ID EQUAL EXPR SEMICOLON {    
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

          int size = strlen($1) + strlen($3->value) + 5;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "%s = %s;\n", $1, $3->value);

          $$ = s;
     }
     ;

INITIALIZATION : 
                 TYPE ID EQUAL ID SEMICOLON {
                    char *type = utils_strRemoveSpace($1);
                    Tuple *rhsVar = utils_findVar(symbolTable, $1, scope);
                    if(rhsVar == NULL) {
                         printf("variavel %s nao foi declarada\n", $1);
                         exit(EXIT_FAILURE);
                    }
                    if(strcmp(type, rhsVar->type) != 0) {
                         printf("tipo da variavel %s incompativel com o da %s\n", $2, rhsVar->name);
                         exit(EXIT_FAILURE);
                    }
                    int size = strlen($1) + strlen($2) + strlen($4) + 5;
                    char * s = malloc(sizeof(char) * size);
                    sprintf(s, "%s %s = %s;\n", $1, $2,$4);
                    $$ = s;

                    free(type);
                 }
               | TYPE ID EQUAL EXPR SEMICOLON {
                    char *type = utils_strRemoveSpace($1);
                    if(strcmp(type, $4->type) != 0) {
                         printf("tipo da variavel %s incompativel com a expressao %s\n", $2, $4->value);
                         exit(EXIT_FAILURE);
                    }
                    int size = strlen($1) + strlen($2) + strlen($4->value) + 5;
                    char * s = malloc(sizeof(char) * size);
                    sprintf(s, "%s %s = %s;\n", $1, $2,$4->value);
                    $$ = s;

                    free(type);
               }
               ;

IF_STM : IF L_PARENTHESIS LOG_EXPR R_PARENTHESIS BLOCK {
          int size = strlen($3->value) + strlen($5) + 6;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "if(%s) %s\n", $3->value, $5);
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

BLOCK : L_KEY {scope++;} DECLS_STM_LIST R_KEY {
          utils_removeVarScope(symbolTable, varNamesScope[scope]);
          int size = strlen($3) + 5;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "{\n%s\n}", $3);
          free($3);
          $$ = s;
          scope--;
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
     varNamesScope = malloc(10 * sizeof(char***));
    return yyparse ( );
}

int yyerror (char *msg) {
    fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
    return 0;
}