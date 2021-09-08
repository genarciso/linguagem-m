%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include "../estrutura-de-dados/hashTable.h"
#include "../estrutura-de-dados/list.h"
#include "../estrutura-de-dados/tuple.h"
#include "../estrutura-de-dados/utils.h"

void yyerror(char *msg);
int yylex(void);
extern int yylineno;
extern char * yytext;

int scope = 0;
unsigned int loopCount = 0;
unsigned int ifCount = 0;
unsigned int endAllIf = 0;
List **varNamesScope;
List *funParamsTypes;
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
    struct StaticInfo * strValue;
};

%start program

%token <sValue> LITERAL_STRING IDENTIFIER INT_TYPE FLOAT_TYPE DOUBLE_TYPE STRING_TYPE BOOLEAN_TYPE MATRIZ_TYPE VOID_TYPE LITERAL_CHAR CHAR_TYPE SCAN
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

%type <sValue> stm stm_list expres_list op_log op_comp if_struct else_struct elseif_list elseif_struct switch_struct case_switch case_list_switch for_struct while_struct loop_stm cond_stm type par_list par_term fun_struct print_stm 
%type <sValue> id_list decl assingment initialization block decls decls_list param_list_call fun_call scan_stm
%type <strValue> term term_num log_term literal_term literal_string expr comp_expr log_expr arit_expr arit_expr_base for_struct_stm base uniry_op arit_expr_right 

%left AND_OP OR_OP
%left GE_OP SE_OP EQ_OP NE_OP G_OP S_OP
%left PLUS_OP SUB_OP
%left STAR DIV_OP
%right FACT_OP MOD_OP

%%

program : decls_list    {
                            //printf("%s", $1);
                            printf("\ncompilation complete...\n");
                            
                            FILE *p;
                            if (!(p = fopen("final.c","w"))) 
                            {                         
                                printf("Erro! Impossivel abrir o arquivo!\n");
                                exit(1);
                            }
                            fprintf(p,"#include <stdlib.h>\n#include <stdio.h>\n#include <math.h>\n\n%s\n\n", $1);
	                        fclose(p);

                            free($1);
                        }
        ;

decls_list : decls {$$ = $1;}
           | decls decls_list{
                                int size = strlen($1) + strlen($2) + 3;
                                char * s = malloc(sizeof(char) * size);
                                sprintf(s, "%s\n%s\n", $1, $2);
                                free($1);
                                free($2);
                                
                                $$ = s;
                             }
            ;

stm_list    : stm                {
                                            int size = strlen($1) + 2;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s;", $1);
                                            free($1);
                                            $$ = s;
                                        }
            | stm stm_list    {
                                            int size = strlen($1) + strlen($2) + 3;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s;\n%s", $1, $2);
                                            free($1);
                                            
                                            $$ = s;
                                        }
            ;

stm : decl           SEMICOLON {$$ = $1;}
    | cond_stm                 {$$ = $1;}
    | loop_stm                 {$$ = $1;} 
    | print_stm      SEMICOLON {$$ = $1;}
    | scan_stm       SEMICOLON {$$ = $1;}
    | expres_list    SEMICOLON {$$ = $1;}
    | assingment     SEMICOLON {$$ = $1;}
    | initialization SEMICOLON {$$ = $1;}
    | uniry_op       SEMICOLON { int size = 2 + strlen($1->value);
                                char * s = malloc(sizeof(char) * size);
                                sprintf(s, "%s;", $1->value);
                                $$ = s; }
    | fun_call       SEMICOLON {$$ = $1;}
    ;

decls :
        decl            SEMICOLON       {
                                            int size = strlen($1) + 2;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s;", $1);
                                            free($1);
                                            $$ = s;
                                        }
      | assingment      SEMICOLON       {
                                            int size = strlen($1) + 2;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s", $1);
                                            free($1);
                                            $$ = s;
                                        }
      | initialization  SEMICOLON       {
                                            int size = strlen($1) + 2;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s", $1);
                                            free($1);
                                            $$ = s;
                                        }
      | fun_struct                      {$$ = $1;}
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
                if(result != NULL) {printf("Erro na linha %d : variavel %s ja declarada\n", yylineno, varName); exit(EXIT_FAILURE);}
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
                    printf("Erro na linha %d : variavel %s nao foi declarada\n", yylineno, $1);
                    exit(EXIT_FAILURE);
               }
               
               $3->type = utils_convertTypeAssigment(lhsVar->type, $3->type);
               if(strcmp(lhsVar->type, $3->type) != 0) {
                    printf("o tipo da variavel %s (%s) ", $1, lhsVar->type); 
                    printf("e da expressao do tipo %s sao incompativeis\n", $3->type); 
                    exit(EXIT_FAILURE);
               }
              
               int size = strlen($1) + strlen($3->value) + 4;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s = %s", $1, $3->value);

               $$ = s;
          }
          ;


initialization : 
               type IDENTIFIER ASSINGMENT expr {

               Tuple *lhsVar = utils_findVar(symbolTable, $2, scope);
               if(lhsVar != NULL) {
                    printf("Erro na linha %d : variavel %s ja foi declarada\n", yylineno, $2);
                    exit(EXIT_FAILURE);
               }
               char *type = utils_strRemoveSpace($1);
               $4->type = utils_convertTypeAssigment(type, $4->type);
               if(strcmp(type, $4->type) != 0) {
                    printf("tipo da variavel %s incompativel com a expressao do tipo %s\n", $2, $4->type);
                    exit(EXIT_FAILURE);
               }
               
               char *key = utils_strAppendInt($2, scope); 
               utils_addVarSymbolTable(symbolTable, type, $2, key);
               free(type);
               list_add(varNamesScope[scope], key);

               int size = strlen($1) + strlen($2) + strlen($4->value) + 5;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s %s = %s;", $1, $2,$4->value);
               $$ = s;

          }
          ;

print_stm   : PRINT L_PARENTHESIS literal_string R_PARENTHESIS {
                                                                    int size = 8 + strlen($3->value);
                                                                    char * s = malloc(sizeof(char) * size);
                                                                    sprintf(s, "print(%s)", $3->value);
                                                                    $$ = s; 
                                                                }
            | PRINT L_PARENTHESIS literal_string COMMA id_list R_PARENTHESIS {
                                                                                int size = 10 + strlen($3->value) + strlen($5);
                                                                                char * s = malloc(sizeof(char) * size);
                                                                                sprintf(s, "print(%s, %s)", $3->value, $5);
                                                                                $$ = s;  
                                                                            }
            | PRINTF L_PARENTHESIS literal_string R_PARENTHESIS {
                                                                    int size = 9 + strlen($3->value);
                                                                    char * s = malloc(sizeof(char) * size);
                                                                    sprintf(s, "printf(%s)", $3->value);
                                                                    $$ = s; 
                                                                }
            | PRINTF L_PARENTHESIS literal_string COMMA id_list R_PARENTHESIS {
                                                                                int size = 11 + strlen($3->value) + strlen($5);
                                                                                char * s = malloc(sizeof(char) * size);
                                                                                sprintf(s, "printf(%s, %s)", $3->value, $5);
                                                                                $$ = s;  
                                                                            }
            ;

scan_stm   : SCAN L_PARENTHESIS IDENTIFIER R_PARENTHESIS        {

                                                                    Tuple *var = utils_findVar(symbolTable, $3, scope);
                                                                    if(var == NULL) {
                                                                            printf("Erro na linha %d : variavel %s nao foi declarada\n", yylineno, $3);
                                                                            exit(EXIT_FAILURE);
                                                                    }

                                                                    if(utils_isANumberType(var->type)) {
                                                                        int size = 8 + strlen(var->name);
                                                                        char * s = malloc(sizeof(char) * size);
                                                                        if(strcmp(var->type, "int") == 0) {
                                                                            sprintf(s, "scanf(\"%si\", &%s);", "%", var->name);
                                                                        }else if(strcmp(var->type, "float") == 0) {
                                                                            sprintf(s, "scanf(\"%sf\", &%s);", "%", var->name);
                                                                        }else {
                                                                            sprintf(s, "scanf(\"%sle\", &%s);", "%", var->name);
                                                                            
                                                                        }
                                                                         $$ = s;
                                                                    }else {
                                                                        printf("Erro na linha %d : tipo da variavel %s nao suportada pelo scan\n", yylineno, var->name);
                                                                        exit(EXIT_FAILURE);
                                                                    }
                                                                    
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

expres_list : expr SEMICOLON             {$$ = $1->value;}
            | expr SEMICOLON expres_list { 
                                            int size = 2 + strlen($1->value) + strlen($3);
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s;%s", $1->value, $3);
                                            $$ = s;
                                        }
            ;

expr    : log_expr  { $$ = $1; }
        | arit_expr { $$ = $1; }
        ;

cond_stm: if_struct         {$$ = $1;}
        | switch_struct     {$$ = $1;}
        ;

if_struct   : IF_STM L_PARENTHESIS log_expr R_PARENTHESIS block else_struct{
                                                            if(strcmp($6, "e") != 0) {
                                                                int size = 70 + strlen($3->value) + strlen($5) + strlen($6);
                                                                char * s = malloc(sizeof(char) * size);
                                                                sprintf(s, "\n{\nif(!(%s)) goto endIf%d;\n%s\ngoto endAllIf%d;\nendIf%d:;\n%s\nendAllIf%d:;\n}\n", $3->value, ifCount, $5, endAllIf, ifCount, $6, endAllIf);
                                                                ifCount++;
                                                                endAllIf++;
                                                                $$ = s;
                                                            }else {
                                                                int size = 60 + strlen($3->value) + strlen($5);
                                                                char * s = malloc(sizeof(char) * size);
                                                                sprintf(s, "\n{\nif(!(%s)) goto endIf%d;\n%s\n endIf%d:;\n}\n", $3->value, ifCount, $5, ifCount);
                                                                ifCount++;
                                                                $$ = s;
                                                            }
                                                        }
            ;
else_struct :   {char * s = malloc(sizeof(char) * 2);
                 sprintf(s, "e");
                 $$ = s;}
            | elseif_list ELSE_STM block {
                                                if(strcmp($1, "e") != 0) {
                                                    int size = 32 + strlen($1) + strlen($3);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s\nnextIf%d: if(0) goto endIf%d;\n%s\nendIf%d:;\n\n", $1, ifCount, ifCount, $3, ifCount);
                                                    ifCount++;
                                                    $$ = s;
                                                }else {
                                                    int size = 32 + strlen($3);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "\nif(0) goto endIf%d;\n%s\nendIf%d:;\n\n", ifCount, $3, ifCount);
                                                    ifCount++;
                                                    $$ = s;
                                                }
                                            }
            ;
elseif_list     :  {char * s = malloc(sizeof(char) * 2);
                    sprintf(s, "e");
                    $$ = s;}
                | elseif_struct elseif_list { 
                                                if(strcmp($2, "e") != 0) {
                                                    int size = 4 + strlen($1) + strlen($2);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s\n%s\n", $1, $2);
                                                    $$ = s;
                                                }else {
                                                    int size = 2 + strlen($1);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s\n", $1);
                                                    $$ = s;
                                                }
                                            }
                ;

elseif_struct   : ELSE_IF_STM L_PARENTHESIS log_expr R_PARENTHESIS block {
                                        int size = 52 + strlen($3->value) + strlen($5);
                                        char * s = malloc(sizeof(char) * size);
                                        sprintf(s, "\n{\nif(!(%s)) goto endIf%d;\n%s\ngoto endAllIf%d;\nendIf%d:;\n}\n", $3->value, ifCount, $5, endAllIf, ifCount);
                                        ifCount++;
                                        free($5);
                                        $$ = s;
                                    
                                }
                ;

switch_struct   : SWITCH_STM L_PARENTHESIS literal_term R_PARENTHESIS L_KEY case_list_switch DEFAULT DOUBLE_DOT stm_list BREAK SEMICOLON R_KEY      {
                                        int size = 34 + strlen($3->value) + strlen($6) + strlen($9);
                                        char * s = malloc(sizeof(char) * size);
                                        sprintf(s, "switch(%s) {\n\t%s\n\tdefault: %s\nbreak;\n}", $3->value, $6, $9);
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
                                                                        int size = 17 + strlen($2->value) + strlen($4);
                                                                        char * s = malloc(sizeof(char) * size);
                                                                        sprintf(s, "case %s:\n\t%s\nbreak;\n", $2->value, $4);
                                                                        free($4);
                                                                        $$ = s;
                                                                    }       
            ;      

loop_stm: while_struct      {$$ = $1;}
        | for_struct        {$$ = $1;}   
        ; 


while_struct: WHILE_STM L_PARENTHESIS log_expr R_PARENTHESIS block   {
                    int size = 72 + strlen($3->value) + strlen($5);
                    char * s = malloc(sizeof(char) * size);
                    sprintf(s, "\n{\nloopStart%d: if(!(%s)) goto loopEnd%d;\n%s\ngoto loopStart%d;\nloopEnd%d:;\n}\n", loopCount, $3->value, loopCount, $5, loopCount, loopCount);
                    loopCount++;
                    free($3);
                    free($5);
                    $$ = s;

            }
            | DO_STM block WHILE_STM L_PARENTHESIS log_expr R_PARENTHESIS SEMICOLON {
                int size = 62 + strlen($2) + strlen($5->value);
                char * s = malloc(sizeof(char) * size);
                sprintf(s, "\n{\nloopStart%d:\n%s\nif(%s) goto loopStart%d;\n}\n", loopCount, $2, $5->value, loopCount);
                free($2);
                free($5);
                $$ = s;
            }
            ;

for_struct  : FOR_STM L_PARENTHESIS {scope++;} initialization SEMICOLON log_expr SEMICOLON for_struct_stm R_PARENTHESIS {scope--;} block {
                int size = 76 + strlen($4) + strlen($6->value) + strlen($8->value) + strlen($11);
                char * s = malloc(sizeof(char) * size);
                sprintf(s, "\n{\n%s;\nloopStart%d: if(!(%s)) goto loopEnd%d;\n%s\n%s;\ngoto loopStart%d;\nloopEnd%d:;\n}\n", $4, loopCount, $6->value, loopCount, $11, $8->value, loopCount, loopCount);
                loopCount++;
                free($4);
                free($6);
                free($8);
                free($11);
                $$ = s;
            } 
            ;

for_struct_stm : uniry_op {$$ = $1;}
               | assingment {$$ = utils_createStaticInfo($1, "null"); }

uniry_op:    arit_expr INC_OP                          { 
                                                            int size = 3 + strlen($1->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s++", $1->value);
                                                            $$ = utils_createStaticInfo(s, $1->type);
                                                            free(s);
                                                        }
            | arit_expr DEC_OP                          { 
                                                            int size = 3 + strlen($1->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s--", $1->value);
                                                            $$ = utils_createStaticInfo(s, $1->type);
                                                            free(s);
                                                        }

fun_call: IDENTIFIER L_PARENTHESIS {funParamsTypes = list_create(5);} param_list_call R_PARENTHESIS {
                                        Tuple *result = hashTable_find(symbolTable, $1);
                                        if(result == NULL) {printf("Erro na linha %d : funcao %s nao foi declarada\n", yylineno, $1); exit(EXIT_FAILURE);}

                                        if(strcmp($4, "e") != 0) {
                                            if(funParamsTypes->size != result->paramsType->size) {printf("Erro na linha %d : faltando parametros\n", yylineno); exit(EXIT_FAILURE);}

                                            for(int i = 0; i < funParamsTypes->size;i++) {
                                                if(strcmp(list_get(funParamsTypes, i), list_get(result->paramsType, i)) != 0) {
                                                    printf("Erro na linha %d : tipo do parametro invalido\n", yylineno); 
                                                    exit(EXIT_FAILURE);
                                                }
                                            }
                                            int size = 3 + strlen($1) + strlen($4);
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s(%s)", $1, $4);
                                            $$ = s;
                                        }else {
                                            if(result->paramsType != NULL) {printf("Erro na linha %d : faltando parametros\n", yylineno); exit(EXIT_FAILURE);}
                                            int size = 3 + strlen($1);
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s()", $1);
                                            $$ = s;
                                        }

};

fun_struct  : type IDENTIFIER L_PARENTHESIS {scope++; funParamsTypes = list_create(5);} par_list {scope--;} R_PARENTHESIS block { 
                                        if(strcmp($5, "e") != 0) {
                                            int size = 5 + strlen($1) + strlen($2) + strlen($5) + strlen($8);
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s %s(%s) %s", $1, $2, $5, $8);
                                            $$ = s;

                                            char *type = utils_strRemoveSpace($1);
                                            Tuple *result = hashTable_find(symbolTable, $2);
                                            if(result != NULL) {printf("Erro na linha %d : funcao %s ja foi declarada\n", yylineno, $2); exit(EXIT_FAILURE);}
                                            utils_addVarSymbolTable(symbolTable, type, $2, $2);
                                            Tuple *FunTuple = tuple_create($2, type);
                                            FunTuple->paramsType = funParamsTypes;
                                            hashTable_insert(symbolTable, $2, FunTuple);
                                            free(type);
                                        }else {

                                            char *type = utils_strRemoveSpace($1);
                                            Tuple *result = hashTable_find(symbolTable, $2);
                                            if(result != NULL) {printf("Erro na linha %d : funcao %s ja foi declarada\n", yylineno, $2); exit(EXIT_FAILURE);}
                                            utils_addVarSymbolTable(symbolTable, type, $2, $2);
                                            Tuple *FunTuple = tuple_create($2, type);
                                            FunTuple->paramsType = NULL;
                                            hashTable_insert(symbolTable, $2, FunTuple);
                                            free(type);

                                            int size = 5 + strlen($1) + strlen($2) + strlen($8);
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s %s() %s", $1, $2, $8);
                                            $$ = s;
                                        }
                                    }
;

block : L_KEY {scope++;} stm_list R_KEY {
          utils_removeVarScope(symbolTable, varNamesScope[scope]);
          int size = strlen($3) + 8;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "{\n%s\n}", $3);
          free($3);
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

par_list:                           {  char * s = malloc(sizeof(char) * 2);
                                        sprintf(s, "e");
                                        $$ = s;
                                    }
        | par_term                  { $$ = $1; }
        | par_term COMMA par_list   { 
                                        int size = 2 + strlen($1) + strlen($3);
                                        char * s = malloc(sizeof(char) * size);
                                        sprintf(s, "%s,%s", $1, $3);
                                        $$ = s;
                                    }
        ;

par_term: type IDENTIFIER   { 
                                char *key, *type;

                                type = utils_strRemoveSpace($1);
                                key = utils_strAppendInt($2, scope); 
                                Tuple *result = hashTable_find(symbolTable, key);
                                if(result != NULL) {printf("Erro na linha %d : argumento %s ja foi declarada\n", yylineno, $2); exit(EXIT_FAILURE);}
                                utils_addVarSymbolTable(symbolTable, type, $2, key);
                                free(type);
                                list_add(varNamesScope[scope], key);
                                
                                char* typeCpy = malloc(sizeof(char) * strlen($1));
                                strcpy(typeCpy, $1);
                                list_add(funParamsTypes, typeCpy);

                                int size = strlen($1) + strlen($2) + 2;
                                char * s = malloc(sizeof(char) * size);
                                sprintf(s, "%s %s", $1, $2);
                                free($2);
                                $$ = s;
                            }
        ;


arit_expr   : base
            | arit_expr PLUS_OP base          { 
                                                            
                                                            if(!utils_isANumberType($1->type) || !utils_isANumberType($3->type)) {
                                                                printf("Erro: operacao + so pode ser usada para tipos numericos \n");
                                                                exit(EXIT_FAILURE);
                                                            }
                                                            
                                                            int size = 4 + strlen($1->value) + strlen($3->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s + %s", $1->value, $3->value);
                                                            $$ = utils_createStaticInfo(s, utils_convertType($1->type, $3->type));
                                                            free(s);
                                                        }
            | arit_expr SUB_OP base                     {
                                                            if(!utils_isANumberType($1->type) || !utils_isANumberType($3->type)) {
                                                                printf("Erro: operacao - so pode ser usada para tipos numericos \n");
                                                                exit(EXIT_FAILURE);
                                                            }

                                                            int size = 4 + strlen($1->value) + strlen($3->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s - %s", $1->value, $3->value);
                                                            $$ = utils_createStaticInfo(s, utils_convertType($1->type, $3->type));
                                                            free(s);
                                                        }
            | arit_expr DIV_OP base                     { 
                                                            if(!utils_isANumberType($1->type) || !utils_isANumberType($3->type)) {
                                                                printf("Erro: operacao / so pode ser usada para tipos numericos \n");
                                                                exit(EXIT_FAILURE);
                                                            }

                                                            int size = 4 + strlen($1->value) + strlen($3->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s / %s", $1->value, $3->value);
                                                            $$ = utils_createStaticInfo(s, utils_convertType($1->type, $3->type));
                                                            free(s);
                                                        }
            | arit_expr STAR base                       { 
                                                            if(!utils_isANumberType($1->type) || !utils_isANumberType($3->type)) {
                                                                printf("Erro: operacao * so pode ser usada para tipos numericos \n");
                                                                exit(EXIT_FAILURE);
                                                            }

                                                            int size = 4 + strlen($1->value) + strlen($3->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s * %s", $1->value, $3->value);
                                                            $$ = utils_createStaticInfo(s, utils_convertType($1->type, $3->type));
                                                            free(s);
                                                        }
            | arit_expr MOD_OP base                     { 
                                                            if(!utils_isANumberType($1->type) || !utils_isANumberType($3->type)) {
                                                                printf("Erro: operacao %s so pode ser usada para tipos numericos \n", "%");
                                                                exit(EXIT_FAILURE);
                                                            }

                                                            int size = 4 + strlen($1->value) + strlen($3->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s %s %s", $1->value, "%", $3->value);
                                                            $$ = utils_createStaticInfo(s, utils_convertType($1->type, $3->type));
                                                            free(s);
                                                        }
            
            ;

base:  arit_expr_right {$$ = $1;}
    ;

arit_expr_right:  arit_expr_base {$$ = $1;}
                | arit_expr_base FACT_OP arit_expr_right           { 
                                                            if(!utils_isANumberType($1->type) || !utils_isANumberType($3->type)) {
                                                                printf("Erro: operacao %s so pode ser usada para tipos numericos \n", "%");
                                                                exit(EXIT_FAILURE);
                                                            }

                                                            int size = 8 + strlen($1->value) + strlen($3->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "pow(%s, %s)", $1->value, $3->value);
                                                            $$ = utils_createStaticInfo(s, utils_convertType($1->type, $3->type));
                                                            free(s);
                                                        }
                ;

arit_expr_base : term {$$ = $1;}
               | L_PARENTHESIS arit_expr R_PARENTHESIS     { 
                                                            if(!utils_isANumberType($2->type)) {
                                                                printf("Erro: operacao + so pode ser usada para tipos numericos \n");
                                                                exit(EXIT_FAILURE);
                                                            }

                                                            int size = 3 + strlen($2->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "(%s)", $2->value);
                                                            $$ = utils_createStaticInfo(s, $2->type);
                                                            free(s);
                                                        }                                                       
                ;

log_expr: comp_expr                            {
                                                    if(strcmp($1->type, "boolean")) {
                                                        printf("Erro: expresao nao boolean < %s > \n", $1->value);
                                                        exit(EXIT_FAILURE);
                                                    }
                                                    $$ = $1;

                                                }
        | L_PARENTHESIS log_expr R_PARENTHESIS {    
                                                    if(strcmp($2->type, "boolean")) {
                                                        printf("Erro: expresao nao boolean < %s > \n", $2->value);
                                                        exit(EXIT_FAILURE);
                                                    }

                                                    int size = 3 + strlen($2->value);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "(%s)", $2->value);
                                                    $$ = utils_createStaticInfo(s, "boolean");
                                                    free(s);
                                                }
        | log_expr op_log comp_expr            { 
                                                    int size = 3 + strlen($1->value) + strlen($2) + strlen($3->value);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s %s %s", $1->value, $2, $3->value);
                                                    $$ = utils_createStaticInfo(s, "boolean");
                                                    free(s);
                                                }

        ;

comp_expr : arit_expr                           {$$ = $1;}
          | comp_expr op_comp arit_expr         { 
                                                    if(!utils_isANumberType($1->type) || !utils_isANumberType($3->type)) {
                                                        printf("Erro na linha %d : operacao %s so pode ser usada para tipos numericos \n", yylineno, $2);
                                                        exit(EXIT_FAILURE);
                                                    }

                                                    int size = 3 + strlen($1->value) + strlen($2) + strlen($3->value);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s %s %s", $1->value, $2, $3->value);
                                                    $$ = utils_createStaticInfo(s, "boolean");
                                                    free(s);
                                                }
          | literal_string EQ_OP literal_string   {$1 == $3;}
          | literal_string NE_OP literal_string   {$1 != $3;}
          ;

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

param_list_call :                         {  char * s = malloc(sizeof(char) * 2);
                                        sprintf(s, "e");
                                        $$ = s;
                                    } 

          | expr {              
                                char* typeCpy = malloc(sizeof(char) * strlen($1->type));
                                strcpy(typeCpy, $1->type);
                                list_add(funParamsTypes, typeCpy);
                                
                                char *s = malloc(sizeof(char) * strlen($1->value));
                                strcpy(s, $1->value);
                                $$ = s;
                 }
          | expr COMMA param_list_call {
                                char* typeCpy = malloc(sizeof(char) * strlen($1->type));
                                strcpy(typeCpy, $1->type);
                                list_add(funParamsTypes, typeCpy);

                                int size = 2 + strlen($1->value) + strlen($3);
                                char *s = malloc(sizeof(char) * size);
                                sprintf(s, "%s, %s", $1->value, $3);
                                $$ = s;

            }
        ;

term    : term_num      {$$ = $1;}
        | log_term      {$$ = $1;}
        | IDENTIFIER    {
                            Tuple *lhsVar = utils_findVar(symbolTable, $1, scope);
                            if(lhsVar == NULL) {
                                    printf("Erro na linha %d :variavel %s nao foi declarada\n", yylineno, $1);
                                    exit(EXIT_FAILURE);
                            }
 
                            StaticInfo *aux = utils_createStaticInfo($1, lhsVar->type); 
                            $$ = aux;
                        }

        ;



term_num : LITERAL_INT           { 
                                    char * s = malloc(sizeof(int));
                                    sprintf(s, "%d", $1);
                                    $$ = utils_createStaticInfo(s, "int");
                                    free(s); 
                                }
         | LITERAL_FLOAT         { 
                                    char * s = malloc(sizeof(float));
                                    sprintf(s, "%f", $1);
                                    $$ = utils_createStaticInfo(s, "float");
                                    free(s); 
                                }
         | LITERAL_DOUBLE        { 
                                    char * s = malloc(sizeof(double));
                                    sprintf(s, "%f", $1);
                                    $$ = utils_createStaticInfo(s, "double");
                                    free(s); 
                                }

log_term : TRUE_VAL     { 
                            char * s = malloc(sizeof(int));
                            sprintf(s, "%d", $1);
                            $$ = utils_createStaticInfo(s, "boolean");
                            free(s);
                        }
         | FALSE_VAL    {   
                            char * s = malloc(sizeof(int));
                            sprintf(s, "%d", $1);
                            $$ = utils_createStaticInfo(s, "boolean");
                            free(s); 
                        }
         ;

literal_term    : term                  {$$ = $1;}
                | literal_string        {$$ = $1;}

literal_string  : LITERAL_CHAR          { $$ = utils_createStaticInfo($1, "char"); }
                | LITERAL_STRING        { $$ = utils_createStaticInfo($1, "string"); }
                ;

%%

void yyerror (char *msg) {
        fprintf (stderr, "Erro na linha %d: %s em '%s'\n", yylineno, msg, yytext);
}

int main() {
    symbolTable = hashTable_create(20);
    varNamesScope = malloc(10 * sizeof(List**));

    for(int i = 0; i < 10; i++) {
        varNamesScope[i] = list_create(10);
    }

    return yyparse();
}