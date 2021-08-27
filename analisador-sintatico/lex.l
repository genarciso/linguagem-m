/*
 * Sample Scanner3: 
 * Description: Retrieve the tokens from code
 * Usage: (1) $ flex sample2.l
 *        (2) $ gcc lex.yy.c -ll (or -lfl)
 *        (3) $ ./a.out
 *        stdin> whatever you like
 *	  stdin> Ctrl-D
 */

%{
	#include "y.tab.h"
	int linha = 1;
	int comment = 0;

	void lexical_error(char* yytext) {
		fprintf(stderr, "Erro léxico na linha %d: %s\n", linha, yytext);
	}
%}

D 		[0-9]
L  		[a-zA-Z_]

%%

"/*"					{comment = 1;}
"*/"					{comment = 0;}
"//"(.)*\n				{}	
\n 						{linha++;}

[ \t\n]               	;
("#include")((\ )+|"")("<")((\ )+|"")(.)*(".h")((\ )+|"")(">") {if(!comment) printf("IMPORTATION PROCESS\n");}
\(       				{if(!comment) return L_PARENTHESIS;}
\)       				{if(!comment) return R_PARENTHESIS;}
\{       				{if(!comment) return L_KEY;}
\}       				{if(!comment) return R_KEY;} 
\[       				{if(!comment) return L_BRACKET;} 
\]       				{if(!comment) return R_BRACKET;}
"if"					{if(!comment) return IF;}
"else"					{if(!comment) return ELSE;} 
"else if"				{if(!comment) return ELSE_IF;}
"for" 					{if(!comment) return FOR;}
"do" 					{if(!comment) return DO;}
"while" 				{if(!comment) return WHILE;}
"int\ "					{if(!comment) {yylval.sValue = strdup(yytext); return TYPE;}}
"float\ "				{if(!comment) {yylval.sValue = strdup(yytext); return TYPE;}}
"double\ "				{if(!comment) {yylval.sValue = strdup(yytext); return TYPE;}}
"string\ "				{if(!comment) {yylval.sValue = strdup(yytext); return TYPE;}}
"boolean\ "				{if(!comment) {yylval.sValue = strdup(yytext); return TYPE;}}
"matriz\ "				{if(!comment) {yylval.sValue = strdup(yytext); return TYPE;}}
"void\ "				{if(!comment) {yylval.sValue = strdup(yytext); return TYPE;}}
"const\ "				{if(!comment) printf("CONSTANT\n");}
"return"[" "|";"]		{if(!comment) printf("RETURN\n");}
"true"					{if(!comment) yylval.sValue = strdup(yytext); return LITERAL_BOOLEAN;}
"false"					{if(!comment) yylval.sValue = strdup(yytext); return LITERAL_BOOLEAN;}
{L}({L}|{D})* 			{if(!comment) yylval.sValue = strdup(yytext); return ID;}
"+"						{if(!comment) return PLUS_OP;}
"-"						{if(!comment) printf("SUB_OP\n");}
"%"						{if(!comment) printf("MOD_OP\n");}
"**"					{if(!comment) printf("FACT_OP\n");}
"/"						{if(!comment) printf("DIV_OP\n");}
"*"						{if(!comment) printf("STAR\n");}
"++"					{if(!comment) return INC_OP;}
"--"					{if(!comment) return DEC_OP;}
"="						{if(!comment) return EQUAL_SIGN;}
"&"						{if(!comment) printf("ADDRESS\n");}
"&&"					{if(!comment) return AND_OP;}
"||"					{if(!comment) return OR_OP;}
"=="					{if(!comment) printf("EQ_OP\n");}
"<"						{if(!comment) printf("S_OP\n");}
"<="					{if(!comment) printf("SE_OP\n");}
">"						{if(!comment) printf("G_OP\n");}
">="					{if(!comment) printf("GEQ_OP\n");}
";"						{if(!comment) return SEMICOLON;}
","						{if(!comment) return COMMA;}
[0-9]+					{if(!comment) yylval.sValue = strdup(yytext); return LITERAL_INT;}
[0-9]*\.[0-9]+f  		{if(!comment) yylval.sValue = strdup(yytext); return LITERAL_FLOAT;}
[0-9]*\.[0-9]+  		{if(!comment) yylval.sValue = strdup(yytext); return LITERAL_DOUBLE;}
(\')([a-zA-Z])(\')		{if(!comment) yylval.sValue = strdup(yytext); return LITERAL_CHAR;}
"\""(.)*"\""			{if(!comment) yylval.sValue = strdup(yytext); return LITERAL_STRING;}
(\')(.)+(\')			{lexical_error(yytext);}

. 						{lexical_error(yytext);}
%%

int yywrap (void) {return 1;}

