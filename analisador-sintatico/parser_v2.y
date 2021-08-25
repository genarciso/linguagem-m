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
int currentScope = 0;
HashTable *symbolTable;


%}

%union {
	int    iValue; 	/* integer value */
	char   cValue; 	/* char value */
	char * sValue;      /* string value */
     struct LITERAL * lValue;
};

%token <sValue> ID TYPE COMMA SEMICOLON IF_STM L_PARENTHESIS R_PARENTHESIS L_KEY R_KEY AND_OP OR_OP PLUS_OP SUB_OP DIV_OP FACT_OP ASSINGMENT
%token <sValue> LITERAL_INT LITERAL_FLOAT LITERAL_DOUBLE LITERAL_CHAR LITERAL_STRING

%start PROGRAM

%type <sValue> DECLS DECL IDS STM_LIST STM   
%type <lValue> TERM ARIT_EXPR LOG_EXPR EXPR

%%
PROGRAM : DECLS STM_LIST{
	    printf("%s\n%s", $1, $2);
	    printf("\nClosing application... Bye...\n");
	    free($1);
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
               varName = strtok(NULL, ",");
          }
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
               sprintf(s, "%s;\n%s", $1, $2);
               free($1);
               free($2);
               $$ = s;
          }
         ;

STM : 
       ID ASSINGMENT ID SEMICOLON {
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
          sprintf(s, "%s + %s;\n", $1, $3);

          $$ = s;
     }
     | ID ASSINGMENT EXPR SEMICOLON {    
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
          sprintf(s, "%s + %s;\n", $1, $3->value);

          $$ = s;
     }
     | IF_STM L_PARENTHESIS LOG_EXPR R_PARENTHESIS L_KEY {scope++;} STM_LIST R_KEY {scope--;}{
          ;
     }
     ;

EXPR : LOG_EXPR {$$ = $1;}
     | ARIT_EXPR {$$ = $1;}
     ;

LOG_EXPR : EXPR {$$ = utils_createLiteral("t", "t");}
         | EXPR AND_OP LOG_EXPR  {$$ = utils_createLiteral("t", "t");}
         | EXPR OR_OP LOG_EXPR   {$$ = utils_createLiteral("t", "t");}
         ; 

ARIT_EXPR : TERM {$$ = $1;}
          | TERM PLUS_OP ARIT_EXPR {
               if(strcmp($1->type, $3->type) == 0) {
                    int size = strlen($1->value) + strlen($3->value) + 4;
                    char * s = malloc(sizeof(char) * size);
                    sprintf(s, "%s + %s", $1->value, $3->value);
                    $$ = utils_createLiteral(s, $1->type);
               }else {
                    printf("tipo diferentes entre %s e %s\n", $1->value, $3->value); 
                    exit(EXIT_FAILURE);
               }
          } 
          ;

TERM : LITERAL_INT    {$$ = utils_createLiteral($1, "int");}
     | LITERAL_FLOAT  {$$ = utils_createLiteral($1, "float");;}
     | LITERAL_DOUBLE {$$ = utils_createLiteral($1, "double");;}
     | LITERAL_CHAR   {$$ = utils_createLiteral($1, "char");;}
     | LITERAL_STRING {$$ = utils_createLiteral($1, "string");;}
     ;
%%

int main (void) {
     symbolTable = hashTable_create(20);
	return yyparse ( );
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}