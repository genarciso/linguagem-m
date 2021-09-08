/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LITERAL_STRING = 258,
    IDENTIFIER = 259,
    INT_TYPE = 260,
    FLOAT_TYPE = 261,
    DOUBLE_TYPE = 262,
    STRING_TYPE = 263,
    BOOLEAN_TYPE = 264,
    MATRIZ_TYPE = 265,
    VOID_TYPE = 266,
    LITERAL_CHAR = 267,
    CHAR_TYPE = 268,
    SCAN = 269,
    LITERAL_INT = 270,
    LITERAL_FLOAT = 271,
    LITERAL_DOUBLE = 272,
    TRUE_VAL = 273,
    FALSE_VAL = 274,
    PLUS_OP = 275,
    SUB_OP = 276,
    DIV_OP = 277,
    STAR = 278,
    MOD_OP = 279,
    FACT_OP = 280,
    ASSINGMENT = 281,
    INC_OP = 282,
    DEC_OP = 283,
    GE_OP = 284,
    SE_OP = 285,
    EQ_OP = 286,
    NE_OP = 287,
    G_OP = 288,
    S_OP = 289,
    AND_OP = 290,
    OR_OP = 291,
    NOT_OP = 292,
    L_PARENTHESIS = 293,
    R_PARENTHESIS = 294,
    L_KEY = 295,
    R_KEY = 296,
    L_BRACKET = 297,
    R_BRACKET = 298,
    IF_STM = 299,
    ELSE_STM = 300,
    ELSE_IF_STM = 301,
    FOR_STM = 302,
    DO_STM = 303,
    WHILE_STM = 304,
    SWITCH_STM = 305,
    CONTINUE = 306,
    BREAK = 307,
    PRINT = 308,
    PRINTF = 309,
    CASE = 310,
    DEFAULT = 311,
    CONSTANT = 312,
    RETURN = 313,
    EOL = 314,
    ADDRESS = 315,
    SEMICOLON = 316,
    COMMA = 317,
    DOT = 318,
    DOUBLE_DOT = 319,
    MALLOC_OP = 320,
    FREE_OP = 321,
    CALLOC_OP = 322
  };
#endif
/* Tokens.  */
#define LITERAL_STRING 258
#define IDENTIFIER 259
#define INT_TYPE 260
#define FLOAT_TYPE 261
#define DOUBLE_TYPE 262
#define STRING_TYPE 263
#define BOOLEAN_TYPE 264
#define MATRIZ_TYPE 265
#define VOID_TYPE 266
#define LITERAL_CHAR 267
#define CHAR_TYPE 268
#define SCAN 269
#define LITERAL_INT 270
#define LITERAL_FLOAT 271
#define LITERAL_DOUBLE 272
#define TRUE_VAL 273
#define FALSE_VAL 274
#define PLUS_OP 275
#define SUB_OP 276
#define DIV_OP 277
#define STAR 278
#define MOD_OP 279
#define FACT_OP 280
#define ASSINGMENT 281
#define INC_OP 282
#define DEC_OP 283
#define GE_OP 284
#define SE_OP 285
#define EQ_OP 286
#define NE_OP 287
#define G_OP 288
#define S_OP 289
#define AND_OP 290
#define OR_OP 291
#define NOT_OP 292
#define L_PARENTHESIS 293
#define R_PARENTHESIS 294
#define L_KEY 295
#define R_KEY 296
#define L_BRACKET 297
#define R_BRACKET 298
#define IF_STM 299
#define ELSE_STM 300
#define ELSE_IF_STM 301
#define FOR_STM 302
#define DO_STM 303
#define WHILE_STM 304
#define SWITCH_STM 305
#define CONTINUE 306
#define BREAK 307
#define PRINT 308
#define PRINTF 309
#define CASE 310
#define DEFAULT 311
#define CONSTANT 312
#define RETURN 313
#define EOL 314
#define ADDRESS 315
#define SEMICOLON 316
#define COMMA 317
#define DOT 318
#define DOUBLE_DOT 319
#define MALLOC_OP 320
#define FREE_OP 321
#define CALLOC_OP 322

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "parser.y"

    int    iValue;  /* integer value */
    float  fValue;  /* float value */
    double dValue;  /* double value */
    char * cValue;  /* char value */
    char * sValue;  /* string value */
    int    bValue;  /* boolean value */
    struct StaticInfo * strValue;

#line 201 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
