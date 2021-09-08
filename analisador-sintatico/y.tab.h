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
    LITERAL_INT = 269,
    LITERAL_FLOAT = 270,
    LITERAL_DOUBLE = 271,
    TRUE_VAL = 272,
    FALSE_VAL = 273,
    PLUS_OP = 274,
    SUB_OP = 275,
    DIV_OP = 276,
    STAR = 277,
    MOD_OP = 278,
    FACT_OP = 279,
    ASSINGMENT = 280,
    INC_OP = 281,
    DEC_OP = 282,
    GE_OP = 283,
    SE_OP = 284,
    EQ_OP = 285,
    NE_OP = 286,
    G_OP = 287,
    S_OP = 288,
    AND_OP = 289,
    OR_OP = 290,
    NOT_OP = 291,
    L_PARENTHESIS = 292,
    R_PARENTHESIS = 293,
    L_KEY = 294,
    R_KEY = 295,
    L_BRACKET = 296,
    R_BRACKET = 297,
    IF_STM = 298,
    ELSE_STM = 299,
    ELSE_IF_STM = 300,
    FOR_STM = 301,
    DO_STM = 302,
    WHILE_STM = 303,
    SWITCH_STM = 304,
    CONTINUE = 305,
    BREAK = 306,
    PRINT = 307,
    PRINTF = 308,
    CASE = 309,
    DEFAULT = 310,
    CONSTANT = 311,
    RETURN = 312,
    EOL = 313,
    ADDRESS = 314,
    SEMICOLON = 315,
    COMMA = 316,
    DOT = 317,
    DOUBLE_DOT = 318,
    MALLOC_OP = 319,
    FREE_OP = 320,
    CALLOC_OP = 321,
    SCANF = 322
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
#define LITERAL_INT 269
#define LITERAL_FLOAT 270
#define LITERAL_DOUBLE 271
#define TRUE_VAL 272
#define FALSE_VAL 273
#define PLUS_OP 274
#define SUB_OP 275
#define DIV_OP 276
#define STAR 277
#define MOD_OP 278
#define FACT_OP 279
#define ASSINGMENT 280
#define INC_OP 281
#define DEC_OP 282
#define GE_OP 283
#define SE_OP 284
#define EQ_OP 285
#define NE_OP 286
#define G_OP 287
#define S_OP 288
#define AND_OP 289
#define OR_OP 290
#define NOT_OP 291
#define L_PARENTHESIS 292
#define R_PARENTHESIS 293
#define L_KEY 294
#define R_KEY 295
#define L_BRACKET 296
#define R_BRACKET 297
#define IF_STM 298
#define ELSE_STM 299
#define ELSE_IF_STM 300
#define FOR_STM 301
#define DO_STM 302
#define WHILE_STM 303
#define SWITCH_STM 304
#define CONTINUE 305
#define BREAK 306
#define PRINT 307
#define PRINTF 308
#define CASE 309
#define DEFAULT 310
#define CONSTANT 311
#define RETURN 312
#define EOL 313
#define ADDRESS 314
#define SEMICOLON 315
#define COMMA 316
#define DOT 317
#define DOUBLE_DOT 318
#define MALLOC_OP 319
#define FREE_OP 320
#define CALLOC_OP 321
#define SCANF 322

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
