/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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


#line 98 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    CALLOC_OP = 321
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

#line 292 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   296

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  221

#define YYUNDEFTOK  2
#define YYMAXUTOK   321


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    85,    86,    97,   104,   114,   115,   116,
     117,   118,   119,   120,   121,   125,   129,   136,   143,   150,
     153,   181,   205,   232,   238,   244,   250,   258,   259,   267,
     268,   276,   277,   280,   281,   284,   301,   304,   320,   323,
     338,   349,   359,   360,   368,   377,   378,   382,   392,   402,
     402,   402,   415,   416,   418,   425,   433,   433,   460,   460,
     460,   494,   494,   505,   506,   507,   508,   509,   510,   511,
     512,   515,   519,   520,   528,   552,   553,   566,   578,   590,
     602,   617,   620,   621,   635,   636,   650,   658,   670,   680,
     681,   693,   694,   697,   698,   699,   702,   703,   704,   705,
     706,   707,   710,   715,   724,   737,   738,   739,   754,   760,
     766,   773,   779,   787,   788,   790,   791
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LITERAL_STRING", "IDENTIFIER",
  "INT_TYPE", "FLOAT_TYPE", "DOUBLE_TYPE", "STRING_TYPE", "BOOLEAN_TYPE",
  "MATRIZ_TYPE", "VOID_TYPE", "LITERAL_CHAR", "CHAR_TYPE", "LITERAL_INT",
  "LITERAL_FLOAT", "LITERAL_DOUBLE", "TRUE_VAL", "FALSE_VAL", "PLUS_OP",
  "SUB_OP", "DIV_OP", "STAR", "MOD_OP", "FACT_OP", "ASSINGMENT", "INC_OP",
  "DEC_OP", "GE_OP", "SE_OP", "EQ_OP", "NE_OP", "G_OP", "S_OP", "AND_OP",
  "OR_OP", "NOT_OP", "L_PARENTHESIS", "R_PARENTHESIS", "L_KEY", "R_KEY",
  "L_BRACKET", "R_BRACKET", "IF_STM", "ELSE_STM", "ELSE_IF_STM", "FOR_STM",
  "DO_STM", "WHILE_STM", "SWITCH_STM", "CONTINUE", "BREAK", "PRINT",
  "PRINTF", "CASE", "DEFAULT", "CONSTANT", "RETURN", "EOL", "ADDRESS",
  "SEMICOLON", "COMMA", "DOT", "DOUBLE_DOT", "MALLOC_OP", "FREE_OP",
  "CALLOC_OP", "$accept", "program", "decls_list", "stm_list", "stm",
  "decls", "decl", "assingment", "initialization", "print_stm", "id_list",
  "expres_list", "expr", "cond_stm", "if_struct", "else_struct",
  "elseif_list", "elseif_struct", "switch_struct", "case_list_switch",
  "case_switch", "loop_stm", "while_struct", "for_struct", "$@1", "$@2",
  "for_struct_stm", "uniry_op", "fun_call", "$@3", "fun_struct", "$@4",
  "$@5", "block", "$@6", "type", "par_list", "par_term", "arit_expr",
  "base", "arit_expr_right", "arit_expr_base", "log_expr", "comp_expr",
  "op_log", "op_comp", "param_list_call", "term", "term_num", "log_term",
  "literal_term", "literal_string", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321
};
# endif

#define YYPACT_NINF (-119)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-39)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     175,    10,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
      46,  -119,   175,     2,     6,    25,  -119,    47,    72,  -119,
    -119,  -119,  -119,  -119,    -9,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,    72,  -119,     4,  -119,  -119,    44,
      79,   119,  -119,  -119,  -119,    40,    72,  -119,    87,   123,
      45,   122,   122,   122,   122,   122,   122,  -119,  -119,  -119,
     206,  -119,  -119,  -119,  -119,  -119,  -119,   122,    18,    18,
    -119,   220,    32,  -119,  -119,  -119,   122,  -119,  -119,  -119,
    -119,  -119,  -119,    34,   119,    34,  -119,  -119,    90,  -119,
      36,   123,  -119,    61,   220,    63,  -119,  -119,  -119,   159,
      23,    68,    69,    63,    73,    74,    92,    96,    60,   159,
      67,    75,    94,    98,   127,   129,  -119,  -119,  -119,  -119,
    -119,  -119,   132,   133,   130,    17,  -119,    72,  -119,   156,
      72,   104,    18,    18,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,    72,  -119,  -119,   -14,  -119,  -119,    72,   212,   220,
     157,   217,  -119,   181,  -119,   -20,   -16,  -119,   171,   196,
      63,   182,   231,    72,    63,   210,  -119,    87,  -119,    87,
      72,  -119,   -30,    72,   229,   222,  -119,   205,   226,   228,
    -119,   230,  -119,   224,   225,    -2,   209,   104,   216,   205,
    -119,  -119,    72,    63,  -119,   199,  -119,   211,   213,  -119,
     227,  -119,    10,  -119,   234,  -119,   218,   159,   159,    63,
    -119,   232,   233,  -119,    63,   215,   219,  -119,  -119,   237,
    -119
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    64,    65,    66,    68,    69,    70,    63,    67,
       0,     2,     3,     0,     0,     0,    19,     0,     0,     1,
       4,    16,    17,    18,    27,    20,   116,   107,   115,   108,
     109,   110,   111,   112,     0,    21,    89,    75,    81,    82,
      31,    86,    84,   105,   106,     0,     0,    58,     0,    89,
       0,     0,     0,     0,     0,     0,     0,    93,    94,    95,
       0,    98,    96,   100,   101,    99,    97,     0,     0,     0,
      22,    71,    27,    28,    85,    87,     0,    76,    77,    78,
      79,    80,    83,    89,    88,    90,    91,    92,     0,    59,
      72,     0,    74,     0,    71,     0,    73,    61,    60,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     8,    33,    34,     9,
      45,    46,     0,     0,     0,    89,    56,     0,    49,     0,
       0,     0,     0,     0,    62,     6,     7,    12,    13,    10,
      11,    29,    14,    15,    27,    54,    55,   102,     0,     0,
       0,     0,   113,     0,   114,     0,     0,    30,   103,     0,
       0,     0,     0,     0,     0,     0,    23,     0,    25,     0,
     102,    57,    36,     0,     0,     0,    47,    42,     0,     0,
     104,     0,    35,     0,    38,     0,     0,     0,     0,    42,
      24,    26,     0,     0,    39,     0,    48,     0,     0,    43,
       0,    37,   107,    53,     0,    52,     0,     0,     0,     0,
      50,     0,     0,    40,     0,     0,     0,    51,    44,     0,
      41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,   261,  -104,  -119,  -119,    49,     0,     8,  -119,
     -44,   137,   -15,  -119,  -119,  -119,    97,  -119,  -119,    91,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,    93,  -119,  -119,
    -119,  -119,  -119,   -97,  -119,     7,   188,  -119,   -17,   146,
     235,  -119,   -32,   236,  -119,  -119,   115,  -118,  -119,  -119,
      99,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,   108,   109,    12,   110,   111,   112,   113,
      25,   114,   115,   116,   117,   182,   183,   184,   118,   188,
     189,   119,   120,   121,   149,   214,   204,   122,   123,   147,
      16,    71,    93,    98,    99,   124,    89,    90,    83,    37,
      38,    39,    40,    41,    60,    67,   159,    42,    43,    44,
     153,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    36,    50,    35,    73,   135,   129,    17,    15,    86,
      87,    46,    14,   152,   -38,   181,    46,    49,   166,    17,
      15,    26,   168,    51,    52,    53,    54,    55,    47,    36,
      28,    70,    57,    58,    59,    18,    51,    52,    53,    54,
      55,   167,   -32,   145,   146,   169,    19,    48,    18,    13,
      85,    24,    48,    51,    52,    53,    54,    55,   195,    91,
     126,    13,    21,   172,   -32,   -32,    22,   176,    56,   152,
      68,    69,   154,   155,   156,    26,    27,   -32,    88,    57,
      58,    59,   125,    75,    28,    23,    29,    30,    31,    32,
      33,    72,   125,    48,    92,   148,   201,    94,   151,    95,
     134,    88,    97,   211,   212,   127,   128,    26,    27,    34,
     130,   131,   213,    57,    58,    59,    28,   217,    29,    30,
      31,    32,    33,   178,    36,   179,    27,   136,   154,   132,
      36,   175,   158,   133,   144,   137,    29,    30,    31,    32,
      33,   185,    51,    52,    53,    54,    55,    61,    62,    63,
      64,    65,    66,    36,   138,   158,   162,   161,   139,    76,
     200,    74,    26,   100,     2,     3,     4,     5,     6,     7,
       8,    28,     9,    29,    30,    31,    32,    33,   206,     1,
       2,     3,     4,     5,     6,     7,     8,   140,     9,   141,
     125,   125,   142,   143,   163,   203,    34,    77,    78,    79,
      80,    81,   101,   202,   150,   102,   103,   104,   105,    26,
      27,   106,   107,    29,    30,    31,    32,    33,    28,   165,
      29,    30,    31,    32,    33,     2,     3,     4,     5,     6,
       7,     8,   170,     9,   171,   174,    76,    51,    52,    53,
      54,    55,   173,    76,   145,   146,    57,    58,    59,   177,
     160,    57,    58,    59,    46,   164,    57,    58,    59,   187,
     186,    57,    58,    59,   190,   209,   191,   192,   193,   196,
     181,   198,   210,    20,   207,   218,   208,   220,   157,   219,
     199,   194,    96,   215,   216,   180,   197,     0,   205,     0,
       0,    82,     0,     0,     0,     0,    84
};

static const yytype_int16 yycheck[] =
{
       0,    18,    34,    18,    48,   109,   103,     0,     0,    68,
      69,    25,    12,   131,    44,    45,    25,    34,    38,    12,
      12,     3,    38,    19,    20,    21,    22,    23,    37,    46,
      12,    46,    34,    35,    36,    25,    19,    20,    21,    22,
      23,    61,    38,    26,    27,    61,     0,    61,    25,     0,
      67,     4,    61,    19,    20,    21,    22,    23,    60,    76,
      37,    12,    60,   160,    60,    61,    60,   164,    24,   187,
      30,    31,   131,   132,   133,     3,     4,    60,    71,    34,
      35,    36,    99,    38,    12,    60,    14,    15,    16,    17,
      18,     4,   109,    61,     4,   127,   193,    61,   130,    38,
      40,    94,    39,   207,   208,    37,    37,     3,     4,    37,
      37,    37,   209,    34,    35,    36,    12,   214,    14,    15,
      16,    17,    18,   167,   141,   169,     4,    60,   187,    37,
     147,   163,   147,    37,     4,    60,    14,    15,    16,    17,
      18,   173,    19,    20,    21,    22,    23,    28,    29,    30,
      31,    32,    33,   170,    60,   170,   149,   149,    60,    37,
     192,    38,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   195,     4,
       5,     6,     7,     8,     9,    10,    11,    60,    13,    60,
     207,   208,    60,    60,    37,   195,    37,    51,    52,    53,
      54,    55,    43,     4,    48,    46,    47,    48,    49,     3,
       4,    52,    53,    14,    15,    16,    17,    18,    12,    38,
      14,    15,    16,    17,    18,     5,     6,     7,     8,     9,
      10,    11,    61,    13,    38,     4,    37,    19,    20,    21,
      22,    23,    60,    37,    26,    27,    34,    35,    36,    39,
      38,    34,    35,    36,    25,    38,    34,    35,    36,    54,
      38,    34,    35,    36,    38,    38,    38,    37,    44,    60,
      45,    55,    38,    12,    63,    60,    63,    40,   141,    60,
     189,   184,    94,    51,    51,   170,   187,    -1,   195,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    13,
      68,    69,    72,    73,    74,    75,    97,   102,    25,     0,
      69,    60,    60,    60,     4,    77,     3,     4,    12,    14,
      15,    16,    17,    18,    37,    79,   105,   106,   107,   108,
     109,   110,   114,   115,   116,   118,    25,    37,    61,   105,
     109,    19,    20,    21,    22,    23,    24,    34,    35,    36,
     111,    28,    29,    30,    31,    32,    33,   112,    30,    31,
      79,    98,     4,    77,    38,    38,    37,   106,   106,   106,
     106,   106,   107,   105,   110,   105,   118,   118,   102,   103,
     104,   105,     4,    99,    61,    38,   103,    39,   100,   101,
       4,    43,    46,    47,    48,    49,    52,    53,    70,    71,
      73,    74,    75,    76,    78,    79,    80,    81,    85,    88,
      89,    90,    94,    95,   102,   105,    37,    37,    37,   100,
      37,    37,    37,    37,    40,    70,    60,    60,    60,    60,
      60,    60,    60,    60,     4,    26,    27,    96,   109,    91,
      48,   109,   114,   117,   118,   118,   118,    78,    79,   113,
      38,    75,   102,    37,    38,    38,    38,    61,    38,    61,
      61,    38,   100,    60,     4,   109,   100,    39,    77,    77,
     113,    45,    82,    83,    84,   109,    38,    54,    86,    87,
      38,    38,    37,    44,    83,    60,    60,   117,    55,    86,
     109,   100,     4,    74,    93,    94,   105,    63,    63,    38,
      38,    70,    70,   100,    92,    51,    51,   100,    60,    60,
      40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    72,    72,    72,
      73,    74,    75,    76,    76,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    82,    82,    83,    83,
      84,    85,    86,    86,    87,    88,    88,    89,    89,    91,
      92,    90,    93,    93,    94,    94,    96,    95,    98,    99,
      97,   101,   100,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   103,   104,   105,   105,   105,   105,   105,
     105,   106,   107,   107,   108,   108,   109,   109,   109,   110,
     110,   110,   110,   111,   111,   111,   112,   112,   112,   112,
     112,   112,   113,   113,   113,   114,   114,   114,   115,   115,
     115,   116,   116,   117,   117,   118,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     3,     4,     4,     6,     4,     6,     1,     3,     2,
       3,     1,     1,     1,     1,     6,     0,     3,     0,     2,
       5,    12,     0,     2,     6,     1,     1,     5,     7,     0,
       0,    11,     1,     1,     2,     2,     0,     5,     0,     0,
       8,     0,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     3,     2,     1,     3,     3,     3,     3,
       3,     1,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 68 "parser.y"
                        {
                            //printf("%s", $1);
                            printf("\ncompilation complete...\n");
                            
                            FILE *p;
                            if (!(p = fopen("final.c","w"))) 
                            {                         
                                printf("Erro! Impossivel abrir o arquivo!\n");
                                exit(1);
                            }
                            fprintf(p,"#include <stdlib.h>\n#include <stdio.h>\n#include <math.h>\n\n%s\n\n", (yyvsp[0].sValue));
	                        fclose(p);

                            free((yyvsp[0].sValue));
                        }
#line 1667 "y.tab.c"
    break;

  case 3:
#line 85 "parser.y"
                   {(yyval.sValue) = (yyvsp[0].sValue);}
#line 1673 "y.tab.c"
    break;

  case 4:
#line 86 "parser.y"
                             {
                                int size = strlen((yyvsp[-1].sValue)) + strlen((yyvsp[0].sValue)) + 3;
                                char * s = malloc(sizeof(char) * size);
                                sprintf(s, "%s\n%s\n", (yyvsp[-1].sValue), (yyvsp[0].sValue));
                                free((yyvsp[-1].sValue));
                                free((yyvsp[0].sValue));
                                
                                (yyval.sValue) = s;
                             }
#line 1687 "y.tab.c"
    break;

  case 5:
#line 97 "parser.y"
                                 {
                                            int size = strlen((yyvsp[0].sValue)) + 2;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s;", (yyvsp[0].sValue));
                                            free((yyvsp[0].sValue));
                                            (yyval.sValue) = s;
                                        }
#line 1699 "y.tab.c"
    break;

  case 6:
#line 104 "parser.y"
                              {
                                            int size = strlen((yyvsp[-1].sValue)) + strlen((yyvsp[0].sValue)) + 3;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s;\n%s", (yyvsp[-1].sValue), (yyvsp[0].sValue));
                                            free((yyvsp[-1].sValue));
                                            
                                            (yyval.sValue) = s;
                                        }
#line 1712 "y.tab.c"
    break;

  case 7:
#line 114 "parser.y"
                               {(yyval.sValue) = (yyvsp[-1].sValue);}
#line 1718 "y.tab.c"
    break;

  case 8:
#line 115 "parser.y"
                               {(yyval.sValue) = (yyvsp[0].sValue);}
#line 1724 "y.tab.c"
    break;

  case 9:
#line 116 "parser.y"
                               {(yyval.sValue) = (yyvsp[0].sValue);}
#line 1730 "y.tab.c"
    break;

  case 10:
#line 117 "parser.y"
                               {(yyval.sValue) = (yyvsp[-1].sValue);}
#line 1736 "y.tab.c"
    break;

  case 11:
#line 118 "parser.y"
                               {(yyval.sValue) = (yyvsp[-1].sValue);}
#line 1742 "y.tab.c"
    break;

  case 12:
#line 119 "parser.y"
                               {(yyval.sValue) = (yyvsp[-1].sValue);}
#line 1748 "y.tab.c"
    break;

  case 13:
#line 120 "parser.y"
                               {(yyval.sValue) = (yyvsp[-1].sValue);}
#line 1754 "y.tab.c"
    break;

  case 14:
#line 121 "parser.y"
                               { int size = 2 + strlen((yyvsp[-1].strValue)->value);
                                char * s = malloc(sizeof(char) * size);
                                sprintf(s, "%s;", (yyvsp[-1].strValue)->value);
                                (yyval.sValue) = s; }
#line 1763 "y.tab.c"
    break;

  case 15:
#line 125 "parser.y"
                               {(yyval.sValue) = (yyvsp[-1].sValue);}
#line 1769 "y.tab.c"
    break;

  case 16:
#line 129 "parser.y"
                                        {
                                            int size = strlen((yyvsp[-1].sValue)) + 2;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s;", (yyvsp[-1].sValue));
                                            free((yyvsp[-1].sValue));
                                            (yyval.sValue) = s;
                                        }
#line 1781 "y.tab.c"
    break;

  case 17:
#line 136 "parser.y"
                                        {
                                            int size = strlen((yyvsp[-1].sValue)) + 2;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s", (yyvsp[-1].sValue));
                                            free((yyvsp[-1].sValue));
                                            (yyval.sValue) = s;
                                        }
#line 1793 "y.tab.c"
    break;

  case 18:
#line 143 "parser.y"
                                        {
                                            int size = strlen((yyvsp[-1].sValue)) + 2;
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s", (yyvsp[-1].sValue));
                                            free((yyvsp[-1].sValue));
                                            (yyval.sValue) = s;
                                        }
#line 1805 "y.tab.c"
    break;

  case 19:
#line 150 "parser.y"
                                        {(yyval.sValue) = (yyvsp[0].sValue);}
#line 1811 "y.tab.c"
    break;

  case 20:
#line 153 "parser.y"
                    {
            char *key, *varName, *type;
            char *idscpy = malloc(strlen((yyvsp[0].sValue)) * sizeof(char));

            strcpy(idscpy, (yyvsp[0].sValue));
            varName = strtok(idscpy, ",");
            while (varName != NULL) {
                type = utils_strRemoveSpace((yyvsp[-1].sValue));
                key = utils_strAppendInt(varName, scope); 
                Tuple *result = hashTable_find(symbolTable, key);
                if(result != NULL) {printf("Erro na linha %d : variavel %s ja declarada\n", yylineno, varName); exit(EXIT_FAILURE);}
                utils_addVarSymbolTable(symbolTable, type, varName, key);
                free(type);
                list_add(varNamesScope[scope], key);
                varName = strtok(NULL, ",");
            }

            free(idscpy);

            int size = strlen((yyvsp[-1].sValue)) + strlen((yyvsp[0].sValue)) + 2;
            char * s = malloc(sizeof(char) * size);
            sprintf(s, "%s %s", (yyvsp[-1].sValue), (yyvsp[0].sValue));
            free((yyvsp[0].sValue));
            (yyval.sValue) = s;
        }
#line 1841 "y.tab.c"
    break;

  case 21:
#line 181 "parser.y"
                                          {    
               Tuple *lhsVar = utils_findVar(symbolTable, (yyvsp[-2].sValue), scope);
               if(lhsVar == NULL) {
                    printf("Erro na linha %d : variavel %s nao foi declarada\n", yylineno, (yyvsp[-2].sValue));
                    exit(EXIT_FAILURE);
               }
               
               (yyvsp[0].strValue)->type = utils_convertTypeAssigment(lhsVar->type, (yyvsp[0].strValue)->type);
               if(strcmp(lhsVar->type, (yyvsp[0].strValue)->type) != 0) {
                    printf("o tipo da variavel %s (%s) ", (yyvsp[-2].sValue), lhsVar->type); 
                    printf("e da expressao do tipo %s sao incompativeis\n", (yyvsp[0].strValue)->type); 
                    exit(EXIT_FAILURE);
               }
              
               int size = strlen((yyvsp[-2].sValue)) + strlen((yyvsp[0].strValue)->value) + 4;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s = %s", (yyvsp[-2].sValue), (yyvsp[0].strValue)->value);

               (yyval.sValue) = s;
          }
#line 1866 "y.tab.c"
    break;

  case 22:
#line 205 "parser.y"
                                               {

               Tuple *lhsVar = utils_findVar(symbolTable, (yyvsp[-2].sValue), scope);
               if(lhsVar != NULL) {
                    printf("Erro na linha %d : variavel %s ja foi declarada\n", yylineno, (yyvsp[-2].sValue));
                    exit(EXIT_FAILURE);
               }
               char *type = utils_strRemoveSpace((yyvsp[-3].sValue));
               (yyvsp[0].strValue)->type = utils_convertTypeAssigment(type, (yyvsp[0].strValue)->type);
               if(strcmp(type, (yyvsp[0].strValue)->type) != 0) {
                    printf("tipo da variavel %s incompativel com a expressao do tipo %s\n", (yyvsp[-2].sValue), (yyvsp[0].strValue)->type);
                    exit(EXIT_FAILURE);
               }
               
               char *key = utils_strAppendInt((yyvsp[-2].sValue), scope); 
               utils_addVarSymbolTable(symbolTable, type, (yyvsp[-2].sValue), key);
               free(type);
               list_add(varNamesScope[scope], key);

               int size = strlen((yyvsp[-3].sValue)) + strlen((yyvsp[-2].sValue)) + strlen((yyvsp[0].strValue)->value) + 5;
               char * s = malloc(sizeof(char) * size);
               sprintf(s, "%s %s = %s;", (yyvsp[-3].sValue), (yyvsp[-2].sValue),(yyvsp[0].strValue)->value);
               (yyval.sValue) = s;

          }
#line 1896 "y.tab.c"
    break;

  case 23:
#line 232 "parser.y"
                                                               {
                                                                    int size = 8 + strlen((yyvsp[-1].strValue)->value);
                                                                    char * s = malloc(sizeof(char) * size);
                                                                    sprintf(s, "print(%s)", (yyvsp[-1].strValue)->value);
                                                                    (yyval.sValue) = s; 
                                                                }
#line 1907 "y.tab.c"
    break;

  case 24:
#line 238 "parser.y"
                                                                             {
                                                                                int size = 10 + strlen((yyvsp[-3].strValue)->value) + strlen((yyvsp[-1].sValue));
                                                                                char * s = malloc(sizeof(char) * size);
                                                                                sprintf(s, "print(%s, %s)", (yyvsp[-3].strValue)->value, (yyvsp[-1].sValue));
                                                                                (yyval.sValue) = s;  
                                                                            }
#line 1918 "y.tab.c"
    break;

  case 25:
#line 244 "parser.y"
                                                                {
                                                                    int size = 9 + strlen((yyvsp[-1].strValue)->value);
                                                                    char * s = malloc(sizeof(char) * size);
                                                                    sprintf(s, "printf(%s)", (yyvsp[-1].strValue)->value);
                                                                    (yyval.sValue) = s; 
                                                                }
#line 1929 "y.tab.c"
    break;

  case 26:
#line 250 "parser.y"
                                                                              {
                                                                                int size = 11 + strlen((yyvsp[-3].strValue)->value) + strlen((yyvsp[-1].sValue));
                                                                                char * s = malloc(sizeof(char) * size);
                                                                                sprintf(s, "printf(%s, %s)", (yyvsp[-3].strValue)->value, (yyvsp[-1].sValue));
                                                                                (yyval.sValue) = s;  
                                                                            }
#line 1940 "y.tab.c"
    break;

  case 27:
#line 258 "parser.y"
                                    {(yyval.sValue) = (yyvsp[0].sValue);}
#line 1946 "y.tab.c"
    break;

  case 28:
#line 259 "parser.y"
                                   { 
                                        int size = 2 + strlen((yyvsp[-2].sValue)) + strlen((yyvsp[0].sValue));
                                        char * s = malloc(sizeof(char) * size);
                                        sprintf(s, "%s,%s", (yyvsp[-2].sValue), (yyvsp[0].sValue));
                                        (yyval.sValue) = s;
                                    }
#line 1957 "y.tab.c"
    break;

  case 29:
#line 267 "parser.y"
                                         {(yyval.sValue) = (yyvsp[-1].strValue)->value;}
#line 1963 "y.tab.c"
    break;

  case 30:
#line 268 "parser.y"
                                         { 
                                            int size = 2 + strlen((yyvsp[-2].strValue)->value) + strlen((yyvsp[0].sValue));
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s;%s", (yyvsp[-2].strValue)->value, (yyvsp[0].sValue));
                                            (yyval.sValue) = s;
                                        }
#line 1974 "y.tab.c"
    break;

  case 31:
#line 276 "parser.y"
                    { (yyval.strValue) = (yyvsp[0].strValue); }
#line 1980 "y.tab.c"
    break;

  case 32:
#line 277 "parser.y"
                    { (yyval.strValue) = (yyvsp[0].strValue); }
#line 1986 "y.tab.c"
    break;

  case 33:
#line 280 "parser.y"
                            {(yyval.sValue) = (yyvsp[0].sValue);}
#line 1992 "y.tab.c"
    break;

  case 34:
#line 281 "parser.y"
                            {(yyval.sValue) = (yyvsp[0].sValue);}
#line 1998 "y.tab.c"
    break;

  case 35:
#line 284 "parser.y"
                                                                           {
                                                            if(strcmp((yyvsp[0].sValue), "e") != 0) {
                                                                int size = 70 + strlen((yyvsp[-3].strValue)->value) + strlen((yyvsp[-1].sValue)) + strlen((yyvsp[0].sValue));
                                                                char * s = malloc(sizeof(char) * size);
                                                                sprintf(s, "\n{\nif(!(%s)) goto endIf%d;\n%s\ngoto endAllIf%d;\nendIf%d:;\n%s\nendAllIf%d:;\n}\n", (yyvsp[-3].strValue)->value, ifCount, (yyvsp[-1].sValue), endAllIf, ifCount, (yyvsp[0].sValue), endAllIf);
                                                                ifCount++;
                                                                endAllIf++;
                                                                (yyval.sValue) = s;
                                                            }else {
                                                                int size = 60 + strlen((yyvsp[-3].strValue)->value) + strlen((yyvsp[-1].sValue));
                                                                char * s = malloc(sizeof(char) * size);
                                                                sprintf(s, "\n{\nif(!(%s)) goto endIf%d;\n%s\n endIf%d:;\n}\n", (yyvsp[-3].strValue)->value, ifCount, (yyvsp[-1].sValue), ifCount);
                                                                ifCount++;
                                                                (yyval.sValue) = s;
                                                            }
                                                        }
#line 2019 "y.tab.c"
    break;

  case 36:
#line 301 "parser.y"
                {char * s = malloc(sizeof(char) * 2);
                 sprintf(s, "e");
                 (yyval.sValue) = s;}
#line 2027 "y.tab.c"
    break;

  case 37:
#line 304 "parser.y"
                                         {
                                                if(strcmp((yyvsp[-2].sValue), "e") != 0) {
                                                    int size = 32 + strlen((yyvsp[-2].sValue)) + strlen((yyvsp[0].sValue));
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s\nnextIf%d: if(0) goto endIf%d;\n%s\nendIf%d:;\n\n", (yyvsp[-2].sValue), ifCount, ifCount, (yyvsp[0].sValue), ifCount);
                                                    ifCount++;
                                                    (yyval.sValue) = s;
                                                }else {
                                                    int size = 32 + strlen((yyvsp[0].sValue));
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "\nif(0) goto endIf%d;\n%s\nendIf%d:;\n\n", ifCount, (yyvsp[0].sValue), ifCount);
                                                    ifCount++;
                                                    (yyval.sValue) = s;
                                                }
                                            }
#line 2047 "y.tab.c"
    break;

  case 38:
#line 320 "parser.y"
                   {char * s = malloc(sizeof(char) * 2);
                    sprintf(s, "e");
                    (yyval.sValue) = s;}
#line 2055 "y.tab.c"
    break;

  case 39:
#line 323 "parser.y"
                                            { 
                                                if(strcmp((yyvsp[0].sValue), "e") != 0) {
                                                    int size = 4 + strlen((yyvsp[-1].sValue)) + strlen((yyvsp[0].sValue));
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s\n%s\n", (yyvsp[-1].sValue), (yyvsp[0].sValue));
                                                    (yyval.sValue) = s;
                                                }else {
                                                    int size = 2 + strlen((yyvsp[-1].sValue));
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s\n", (yyvsp[-1].sValue));
                                                    (yyval.sValue) = s;
                                                }
                                            }
#line 2073 "y.tab.c"
    break;

  case 40:
#line 338 "parser.y"
                                                                         {
                                        int size = 52 + strlen((yyvsp[-2].strValue)->value) + strlen((yyvsp[0].sValue));
                                        char * s = malloc(sizeof(char) * size);
                                        sprintf(s, "\n{\nif(!(%s)) goto endIf%d;\n%s\ngoto endAllIf%d;\nendIf%d:;\n}\n", (yyvsp[-2].strValue)->value, ifCount, (yyvsp[0].sValue), endAllIf, ifCount);
                                        ifCount++;
                                        free((yyvsp[0].sValue));
                                        (yyval.sValue) = s;
                                    
                                }
#line 2087 "y.tab.c"
    break;

  case 41:
#line 349 "parser.y"
                                                                                                                                                    {
                                        int size = 34 + strlen((yyvsp[-9].strValue)->value) + strlen((yyvsp[-6].sValue)) + strlen((yyvsp[-3].sValue));
                                        char * s = malloc(sizeof(char) * size);
                                        sprintf(s, "switch(%s) {\n\t%s\n\tdefault: %s\nbreak;\n}", (yyvsp[-9].strValue)->value, (yyvsp[-6].sValue), (yyvsp[-3].sValue));
                                        free((yyvsp[-6].sValue));
                                        free((yyvsp[-3].sValue));
                                        (yyval.sValue) = s;
                                    }
#line 2100 "y.tab.c"
    break;

  case 42:
#line 359 "parser.y"
                  {}
#line 2106 "y.tab.c"
    break;

  case 43:
#line 360 "parser.y"
                                               { 
                                                    int size = 2 + strlen((yyvsp[-1].sValue)) + strlen((yyvsp[0].sValue));
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s %s", (yyvsp[-1].sValue), (yyvsp[0].sValue));
                                                    (yyval.sValue) = s;
                                                }
#line 2117 "y.tab.c"
    break;

  case 44:
#line 368 "parser.y"
                                                                   {
                                                                        int size = 17 + strlen((yyvsp[-4].strValue)->value) + strlen((yyvsp[-2].sValue));
                                                                        char * s = malloc(sizeof(char) * size);
                                                                        sprintf(s, "case %s:\n\t%s\nbreak;\n", (yyvsp[-4].strValue)->value, (yyvsp[-2].sValue));
                                                                        free((yyvsp[-2].sValue));
                                                                        (yyval.sValue) = s;
                                                                    }
#line 2129 "y.tab.c"
    break;

  case 45:
#line 377 "parser.y"
                            {(yyval.sValue) = (yyvsp[0].sValue);}
#line 2135 "y.tab.c"
    break;

  case 46:
#line 378 "parser.y"
                            {(yyval.sValue) = (yyvsp[0].sValue);}
#line 2141 "y.tab.c"
    break;

  case 47:
#line 382 "parser.y"
                                                                     {
                    int size = 72 + strlen((yyvsp[-2].strValue)->value) + strlen((yyvsp[0].sValue));
                    char * s = malloc(sizeof(char) * size);
                    sprintf(s, "\n{\nloopStart%d: if(!(%s)) goto loopEnd%d;\n%s\ngoto loopStart%d;\nloopEnd%d:;\n}\n", loopCount, (yyvsp[-2].strValue)->value, loopCount, (yyvsp[0].sValue), loopCount, loopCount);
                    loopCount++;
                    free((yyvsp[-2].strValue));
                    free((yyvsp[0].sValue));
                    (yyval.sValue) = s;

            }
#line 2156 "y.tab.c"
    break;

  case 48:
#line 392 "parser.y"
                                                                                    {
                int size = 62 + strlen((yyvsp[-5].sValue)) + strlen((yyvsp[-2].strValue)->value);
                char * s = malloc(sizeof(char) * size);
                sprintf(s, "\n{\nloopStart%d:\n%s\nif(%s) goto loopStart%d;\n}\n", loopCount, (yyvsp[-5].sValue), (yyvsp[-2].strValue)->value, loopCount);
                free((yyvsp[-5].sValue));
                free((yyvsp[-2].strValue));
                (yyval.sValue) = s;
            }
#line 2169 "y.tab.c"
    break;

  case 49:
#line 402 "parser.y"
                                    {scope++;}
#line 2175 "y.tab.c"
    break;

  case 50:
#line 402 "parser.y"
                                                                                                                        {scope--;}
#line 2181 "y.tab.c"
    break;

  case 51:
#line 402 "parser.y"
                                                                                                                                         {
                int size = 76 + strlen((yyvsp[-7].sValue)) + strlen((yyvsp[-5].strValue)->value) + strlen((yyvsp[-3].strValue)->value) + strlen((yyvsp[0].sValue));
                char * s = malloc(sizeof(char) * size);
                sprintf(s, "\n{\n%s;\nloopStart%d: if(!(%s)) goto loopEnd%d;\n%s\n%s;\ngoto loopStart%d;\nloopEnd%d:;\n}\n", (yyvsp[-7].sValue), loopCount, (yyvsp[-5].strValue)->value, loopCount, (yyvsp[0].sValue), (yyvsp[-3].strValue)->value, loopCount, loopCount);
                loopCount++;
                free((yyvsp[-7].sValue));
                free((yyvsp[-5].strValue));
                free((yyvsp[-3].strValue));
                free((yyvsp[0].sValue));
                (yyval.sValue) = s;
            }
#line 2197 "y.tab.c"
    break;

  case 52:
#line 415 "parser.y"
                          {(yyval.strValue) = (yyvsp[0].strValue);}
#line 2203 "y.tab.c"
    break;

  case 53:
#line 416 "parser.y"
                            {(yyval.strValue) = utils_createStaticInfo((yyvsp[0].sValue), "null"); }
#line 2209 "y.tab.c"
    break;

  case 54:
#line 418 "parser.y"
                                                       { 
                                                            int size = 3 + strlen((yyvsp[-1].strValue)->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s++", (yyvsp[-1].strValue)->value);
                                                            (yyval.strValue) = utils_createStaticInfo(s, (yyvsp[-1].strValue)->type);
                                                            free(s);
                                                        }
#line 2221 "y.tab.c"
    break;

  case 55:
#line 425 "parser.y"
                                                        { 
                                                            int size = 3 + strlen((yyvsp[-1].strValue)->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s--", (yyvsp[-1].strValue)->value);
                                                            (yyval.strValue) = utils_createStaticInfo(s, (yyvsp[-1].strValue)->type);
                                                            free(s);
                                                        }
#line 2233 "y.tab.c"
    break;

  case 56:
#line 433 "parser.y"
                                   {funParamsTypes = list_create(5);}
#line 2239 "y.tab.c"
    break;

  case 57:
#line 433 "parser.y"
                                                                                                    {
                                        Tuple *result = hashTable_find(symbolTable, (yyvsp[-4].sValue));
                                        if(result == NULL) {printf("Erro na linha %d : funcao %s nao foi declarada\n", yylineno, (yyvsp[-4].sValue)); exit(EXIT_FAILURE);}

                                        if(strcmp((yyvsp[-1].sValue), "e") != 0) {
                                            if(funParamsTypes->size != result->paramsType->size) {printf("Erro na linha %d : faltando parametros\n", yylineno); exit(EXIT_FAILURE);}

                                            for(int i = 0; i < funParamsTypes->size;i++) {
                                                if(strcmp(list_get(funParamsTypes, i), list_get(result->paramsType, i)) != 0) {
                                                    printf("Erro na linha %d : tipo do parametro invalido\n", yylineno); 
                                                    exit(EXIT_FAILURE);
                                                }
                                            }
                                            int size = 3 + strlen((yyvsp[-4].sValue)) + strlen((yyvsp[-1].sValue));
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s(%s)", (yyvsp[-4].sValue), (yyvsp[-1].sValue));
                                            (yyval.sValue) = s;
                                        }else {
                                            if(result->paramsType != NULL) {printf("Erro na linha %d : faltando parametros\n", yylineno); exit(EXIT_FAILURE);}
                                            int size = 3 + strlen((yyvsp[-4].sValue));
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s()", (yyvsp[-4].sValue));
                                            (yyval.sValue) = s;
                                        }

}
#line 2270 "y.tab.c"
    break;

  case 58:
#line 460 "parser.y"
                                            {scope++; funParamsTypes = list_create(5);}
#line 2276 "y.tab.c"
    break;

  case 59:
#line 460 "parser.y"
                                                                                                 {scope--;}
#line 2282 "y.tab.c"
    break;

  case 60:
#line 460 "parser.y"
                                                                                                                                { 
                                        if(strcmp((yyvsp[-3].sValue), "e") != 0) {
                                            int size = 5 + strlen((yyvsp[-7].sValue)) + strlen((yyvsp[-6].sValue)) + strlen((yyvsp[-3].sValue)) + strlen((yyvsp[0].sValue));
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s %s(%s) %s", (yyvsp[-7].sValue), (yyvsp[-6].sValue), (yyvsp[-3].sValue), (yyvsp[0].sValue));
                                            (yyval.sValue) = s;

                                            char *type = utils_strRemoveSpace((yyvsp[-7].sValue));
                                            Tuple *result = hashTable_find(symbolTable, (yyvsp[-6].sValue));
                                            if(result != NULL) {printf("Erro na linha %d : funcao %s ja foi declarada\n", yylineno, (yyvsp[-6].sValue)); exit(EXIT_FAILURE);}
                                            utils_addVarSymbolTable(symbolTable, type, (yyvsp[-6].sValue), (yyvsp[-6].sValue));
                                            Tuple *FunTuple = tuple_create((yyvsp[-6].sValue), type);
                                            FunTuple->paramsType = funParamsTypes;
                                            hashTable_insert(symbolTable, (yyvsp[-6].sValue), FunTuple);
                                            free(type);
                                        }else {

                                            char *type = utils_strRemoveSpace((yyvsp[-7].sValue));
                                            Tuple *result = hashTable_find(symbolTable, (yyvsp[-6].sValue));
                                            if(result != NULL) {printf("Erro na linha %d : funcao %s ja foi declarada\n", yylineno, (yyvsp[-6].sValue)); exit(EXIT_FAILURE);}
                                            utils_addVarSymbolTable(symbolTable, type, (yyvsp[-6].sValue), (yyvsp[-6].sValue));
                                            Tuple *FunTuple = tuple_create((yyvsp[-6].sValue), type);
                                            FunTuple->paramsType = NULL;
                                            hashTable_insert(symbolTable, (yyvsp[-6].sValue), FunTuple);
                                            free(type);

                                            int size = 5 + strlen((yyvsp[-7].sValue)) + strlen((yyvsp[-6].sValue)) + strlen((yyvsp[0].sValue));
                                            char * s = malloc(sizeof(char) * size);
                                            sprintf(s, "%s %s() %s", (yyvsp[-7].sValue), (yyvsp[-6].sValue), (yyvsp[0].sValue));
                                            (yyval.sValue) = s;
                                        }
                                    }
#line 2319 "y.tab.c"
    break;

  case 61:
#line 494 "parser.y"
              {scope++;}
#line 2325 "y.tab.c"
    break;

  case 62:
#line 494 "parser.y"
                                        {
          utils_removeVarScope(symbolTable, varNamesScope[scope]);
          int size = strlen((yyvsp[-1].sValue)) + 8;
          char * s = malloc(sizeof(char) * size);
          sprintf(s, "{\n%s\n}", (yyvsp[-1].sValue));
          free((yyvsp[-1].sValue));
          (yyval.sValue) = s;
          scope--;
     }
#line 2339 "y.tab.c"
    break;

  case 63:
#line 505 "parser.y"
                    {(yyval.sValue) = (yyvsp[0].sValue);}
#line 2345 "y.tab.c"
    break;

  case 64:
#line 506 "parser.y"
                    {(yyval.sValue) = (yyvsp[0].sValue);}
#line 2351 "y.tab.c"
    break;

  case 65:
#line 507 "parser.y"
                    {(yyval.sValue) = (yyvsp[0].sValue);}
#line 2357 "y.tab.c"
    break;

  case 66:
#line 508 "parser.y"
                    {(yyval.sValue) = (yyvsp[0].sValue);}
#line 2363 "y.tab.c"
    break;

  case 67:
#line 509 "parser.y"
                    {(yyval.sValue) = (yyvsp[0].sValue);}
#line 2369 "y.tab.c"
    break;

  case 68:
#line 510 "parser.y"
                    {(yyval.sValue) = (yyvsp[0].sValue);}
#line 2375 "y.tab.c"
    break;

  case 69:
#line 511 "parser.y"
                    {(yyval.sValue) = (yyvsp[0].sValue);}
#line 2381 "y.tab.c"
    break;

  case 70:
#line 512 "parser.y"
                    {(yyval.sValue) = (yyvsp[0].sValue);}
#line 2387 "y.tab.c"
    break;

  case 71:
#line 515 "parser.y"
                                    {  char * s = malloc(sizeof(char) * 2);
                                        sprintf(s, "e");
                                        (yyval.sValue) = s;
                                    }
#line 2396 "y.tab.c"
    break;

  case 72:
#line 519 "parser.y"
                                    { (yyval.sValue) = (yyvsp[0].sValue); }
#line 2402 "y.tab.c"
    break;

  case 73:
#line 520 "parser.y"
                                    { 
                                        int size = 2 + strlen((yyvsp[-2].sValue)) + strlen((yyvsp[0].sValue));
                                        char * s = malloc(sizeof(char) * size);
                                        sprintf(s, "%s,%s", (yyvsp[-2].sValue), (yyvsp[0].sValue));
                                        (yyval.sValue) = s;
                                    }
#line 2413 "y.tab.c"
    break;

  case 74:
#line 528 "parser.y"
                            { 
                                char *key, *type;

                                type = utils_strRemoveSpace((yyvsp[-1].sValue));
                                key = utils_strAppendInt((yyvsp[0].sValue), scope); 
                                Tuple *result = hashTable_find(symbolTable, key);
                                if(result != NULL) {printf("Erro na linha %d : argumento %s ja foi declarada\n", yylineno, (yyvsp[0].sValue)); exit(EXIT_FAILURE);}
                                utils_addVarSymbolTable(symbolTable, type, (yyvsp[0].sValue), key);
                                free(type);
                                list_add(varNamesScope[scope], key);
                                
                                char* typeCpy = malloc(sizeof(char) * strlen((yyvsp[-1].sValue)));
                                strcpy(typeCpy, (yyvsp[-1].sValue));
                                list_add(funParamsTypes, typeCpy);

                                int size = strlen((yyvsp[-1].sValue)) + strlen((yyvsp[0].sValue)) + 2;
                                char * s = malloc(sizeof(char) * size);
                                sprintf(s, "%s %s", (yyvsp[-1].sValue), (yyvsp[0].sValue));
                                free((yyvsp[0].sValue));
                                (yyval.sValue) = s;
                            }
#line 2439 "y.tab.c"
    break;

  case 76:
#line 553 "parser.y"
                                              { 
                                                            
                                                            if(!utils_isANumberType((yyvsp[-2].strValue)->type) || !utils_isANumberType((yyvsp[0].strValue)->type)) {
                                                                printf("Erro: operacao + so pode ser usada para tipos numericos \n");
                                                                exit(EXIT_FAILURE);
                                                            }
                                                            
                                                            int size = 4 + strlen((yyvsp[-2].strValue)->value) + strlen((yyvsp[0].strValue)->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s + %s", (yyvsp[-2].strValue)->value, (yyvsp[0].strValue)->value);
                                                            (yyval.strValue) = utils_createStaticInfo(s, utils_convertType((yyvsp[-2].strValue)->type, (yyvsp[0].strValue)->type));
                                                            free(s);
                                                        }
#line 2457 "y.tab.c"
    break;

  case 77:
#line 566 "parser.y"
                                                        {
                                                            if(!utils_isANumberType((yyvsp[-2].strValue)->type) || !utils_isANumberType((yyvsp[0].strValue)->type)) {
                                                                printf("Erro: operacao - so pode ser usada para tipos numericos \n");
                                                                exit(EXIT_FAILURE);
                                                            }

                                                            int size = 4 + strlen((yyvsp[-2].strValue)->value) + strlen((yyvsp[0].strValue)->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s - %s", (yyvsp[-2].strValue)->value, (yyvsp[0].strValue)->value);
                                                            (yyval.strValue) = utils_createStaticInfo(s, utils_convertType((yyvsp[-2].strValue)->type, (yyvsp[0].strValue)->type));
                                                            free(s);
                                                        }
#line 2474 "y.tab.c"
    break;

  case 78:
#line 578 "parser.y"
                                                        { 
                                                            if(!utils_isANumberType((yyvsp[-2].strValue)->type) || !utils_isANumberType((yyvsp[0].strValue)->type)) {
                                                                printf("Erro: operacao / so pode ser usada para tipos numericos \n");
                                                                exit(EXIT_FAILURE);
                                                            }

                                                            int size = 4 + strlen((yyvsp[-2].strValue)->value) + strlen((yyvsp[0].strValue)->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s / %s", (yyvsp[-2].strValue)->value, (yyvsp[0].strValue)->value);
                                                            (yyval.strValue) = utils_createStaticInfo(s, utils_convertType((yyvsp[-2].strValue)->type, (yyvsp[0].strValue)->type));
                                                            free(s);
                                                        }
#line 2491 "y.tab.c"
    break;

  case 79:
#line 590 "parser.y"
                                                        { 
                                                            if(!utils_isANumberType((yyvsp[-2].strValue)->type) || !utils_isANumberType((yyvsp[0].strValue)->type)) {
                                                                printf("Erro: operacao * so pode ser usada para tipos numericos \n");
                                                                exit(EXIT_FAILURE);
                                                            }

                                                            int size = 4 + strlen((yyvsp[-2].strValue)->value) + strlen((yyvsp[0].strValue)->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s * %s", (yyvsp[-2].strValue)->value, (yyvsp[0].strValue)->value);
                                                            (yyval.strValue) = utils_createStaticInfo(s, utils_convertType((yyvsp[-2].strValue)->type, (yyvsp[0].strValue)->type));
                                                            free(s);
                                                        }
#line 2508 "y.tab.c"
    break;

  case 80:
#line 602 "parser.y"
                                                        { 
                                                            if(!utils_isANumberType((yyvsp[-2].strValue)->type) || !utils_isANumberType((yyvsp[0].strValue)->type)) {
                                                                printf("Erro: operacao %s so pode ser usada para tipos numericos \n", "%");
                                                                exit(EXIT_FAILURE);
                                                            }

                                                            int size = 4 + strlen((yyvsp[-2].strValue)->value) + strlen((yyvsp[0].strValue)->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "%s %s %s", (yyvsp[-2].strValue)->value, "%", (yyvsp[0].strValue)->value);
                                                            (yyval.strValue) = utils_createStaticInfo(s, utils_convertType((yyvsp[-2].strValue)->type, (yyvsp[0].strValue)->type));
                                                            free(s);
                                                        }
#line 2525 "y.tab.c"
    break;

  case 81:
#line 617 "parser.y"
                       {(yyval.strValue) = (yyvsp[0].strValue);}
#line 2531 "y.tab.c"
    break;

  case 82:
#line 620 "parser.y"
                                 {(yyval.strValue) = (yyvsp[0].strValue);}
#line 2537 "y.tab.c"
    break;

  case 83:
#line 621 "parser.y"
                                                                   { 
                                                            if(!utils_isANumberType((yyvsp[-2].strValue)->type) || !utils_isANumberType((yyvsp[0].strValue)->type)) {
                                                                printf("Erro: operacao %s so pode ser usada para tipos numericos \n", "%");
                                                                exit(EXIT_FAILURE);
                                                            }

                                                            int size = 8 + strlen((yyvsp[-2].strValue)->value) + strlen((yyvsp[0].strValue)->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "pow(%s, %s)", (yyvsp[-2].strValue)->value, (yyvsp[0].strValue)->value);
                                                            (yyval.strValue) = utils_createStaticInfo(s, utils_convertType((yyvsp[-2].strValue)->type, (yyvsp[0].strValue)->type));
                                                            free(s);
                                                        }
#line 2554 "y.tab.c"
    break;

  case 84:
#line 635 "parser.y"
                      {(yyval.strValue) = (yyvsp[0].strValue);}
#line 2560 "y.tab.c"
    break;

  case 85:
#line 636 "parser.y"
                                                           { 
                                                            if(!utils_isANumberType((yyvsp[-1].strValue)->type)) {
                                                                printf("Erro: operacao + so pode ser usada para tipos numericos \n");
                                                                exit(EXIT_FAILURE);
                                                            }

                                                            int size = 3 + strlen((yyvsp[-1].strValue)->value);
                                                            char * s = malloc(sizeof(char) * size);
                                                            sprintf(s, "(%s)", (yyvsp[-1].strValue)->value);
                                                            (yyval.strValue) = utils_createStaticInfo(s, (yyvsp[-1].strValue)->type);
                                                            free(s);
                                                        }
#line 2577 "y.tab.c"
    break;

  case 86:
#line 650 "parser.y"
                                               {
                                                    if(strcmp((yyvsp[0].strValue)->type, "boolean")) {
                                                        printf("Erro: expresao nao boolean < %s > \n", (yyvsp[0].strValue)->value);
                                                        exit(EXIT_FAILURE);
                                                    }
                                                    (yyval.strValue) = (yyvsp[0].strValue);

                                                }
#line 2590 "y.tab.c"
    break;

  case 87:
#line 658 "parser.y"
                                               {    
                                                    if(strcmp((yyvsp[-1].strValue)->type, "boolean")) {
                                                        printf("Erro: expresao nao boolean < %s > \n", (yyvsp[-1].strValue)->value);
                                                        exit(EXIT_FAILURE);
                                                    }

                                                    int size = 3 + strlen((yyvsp[-1].strValue)->value);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "(%s)", (yyvsp[-1].strValue)->value);
                                                    (yyval.strValue) = utils_createStaticInfo(s, "boolean");
                                                    free(s);
                                                }
#line 2607 "y.tab.c"
    break;

  case 88:
#line 670 "parser.y"
                                               { 
                                                    int size = 3 + strlen((yyvsp[-2].strValue)->value) + strlen((yyvsp[-1].sValue)) + strlen((yyvsp[0].strValue)->value);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s %s %s", (yyvsp[-2].strValue)->value, (yyvsp[-1].sValue), (yyvsp[0].strValue)->value);
                                                    (yyval.strValue) = utils_createStaticInfo(s, "boolean");
                                                    free(s);
                                                }
#line 2619 "y.tab.c"
    break;

  case 89:
#line 680 "parser.y"
                                                {(yyval.strValue) = (yyvsp[0].strValue);}
#line 2625 "y.tab.c"
    break;

  case 90:
#line 681 "parser.y"
                                                { 
                                                    if(!utils_isANumberType((yyvsp[-2].strValue)->type) || !utils_isANumberType((yyvsp[0].strValue)->type)) {
                                                        printf("Erro na linha %d : operacao %s so pode ser usada para tipos numericos \n", yylineno, (yyvsp[-1].sValue));
                                                        exit(EXIT_FAILURE);
                                                    }

                                                    int size = 3 + strlen((yyvsp[-2].strValue)->value) + strlen((yyvsp[-1].sValue)) + strlen((yyvsp[0].strValue)->value);
                                                    char * s = malloc(sizeof(char) * size);
                                                    sprintf(s, "%s %s %s", (yyvsp[-2].strValue)->value, (yyvsp[-1].sValue), (yyvsp[0].strValue)->value);
                                                    (yyval.strValue) = utils_createStaticInfo(s, "boolean");
                                                    free(s);
                                                }
#line 2642 "y.tab.c"
    break;

  case 91:
#line 693 "parser.y"
                                                  {(yyvsp[-2].strValue) == (yyvsp[0].strValue);}
#line 2648 "y.tab.c"
    break;

  case 92:
#line 694 "parser.y"
                                                  {(yyvsp[-2].strValue) != (yyvsp[0].strValue);}
#line 2654 "y.tab.c"
    break;

  case 93:
#line 697 "parser.y"
                    {(yyval.sValue) = strdup("&&");}
#line 2660 "y.tab.c"
    break;

  case 94:
#line 698 "parser.y"
                    {(yyval.sValue) = strdup("||");}
#line 2666 "y.tab.c"
    break;

  case 95:
#line 699 "parser.y"
                    {(yyval.sValue) = strdup("!") ;}
#line 2672 "y.tab.c"
    break;

  case 96:
#line 702 "parser.y"
                    {(yyval.sValue) = strdup("<=") ;}
#line 2678 "y.tab.c"
    break;

  case 97:
#line 703 "parser.y"
                    {(yyval.sValue) = strdup("<")  ;}
#line 2684 "y.tab.c"
    break;

  case 98:
#line 704 "parser.y"
                    {(yyval.sValue) = strdup(">=") ;}
#line 2690 "y.tab.c"
    break;

  case 99:
#line 705 "parser.y"
                    {(yyval.sValue) = strdup(">")  ;}
#line 2696 "y.tab.c"
    break;

  case 100:
#line 706 "parser.y"
                    {(yyval.sValue) = strdup("==") ;}
#line 2702 "y.tab.c"
    break;

  case 101:
#line 707 "parser.y"
                    {(yyval.sValue) = strdup("!=") ;}
#line 2708 "y.tab.c"
    break;

  case 102:
#line 710 "parser.y"
                                          {  char * s = malloc(sizeof(char) * 2);
                                        sprintf(s, "e");
                                        (yyval.sValue) = s;
                                    }
#line 2717 "y.tab.c"
    break;

  case 103:
#line 715 "parser.y"
                 {              
                                char* typeCpy = malloc(sizeof(char) * strlen((yyvsp[0].strValue)->type));
                                strcpy(typeCpy, (yyvsp[0].strValue)->type);
                                list_add(funParamsTypes, typeCpy);
                                
                                char *s = malloc(sizeof(char) * strlen((yyvsp[0].strValue)->value));
                                strcpy(s, (yyvsp[0].strValue)->value);
                                (yyval.sValue) = s;
                 }
#line 2731 "y.tab.c"
    break;

  case 104:
#line 724 "parser.y"
                                       {
                                char* typeCpy = malloc(sizeof(char) * strlen((yyvsp[-2].strValue)->type));
                                strcpy(typeCpy, (yyvsp[-2].strValue)->type);
                                list_add(funParamsTypes, typeCpy);

                                int size = 2 + strlen((yyvsp[-2].strValue)->value) + strlen((yyvsp[0].sValue));
                                char *s = malloc(sizeof(char) * size);
                                sprintf(s, "%s, %s", (yyvsp[-2].strValue)->value, (yyvsp[0].sValue));
                                (yyval.sValue) = s;

            }
#line 2747 "y.tab.c"
    break;

  case 105:
#line 737 "parser.y"
                        {(yyval.strValue) = (yyvsp[0].strValue);}
#line 2753 "y.tab.c"
    break;

  case 106:
#line 738 "parser.y"
                        {(yyval.strValue) = (yyvsp[0].strValue);}
#line 2759 "y.tab.c"
    break;

  case 107:
#line 739 "parser.y"
                        {
                            Tuple *lhsVar = utils_findVar(symbolTable, (yyvsp[0].sValue), scope);
                            if(lhsVar == NULL) {
                                    printf("Erro na linha %d :variavel %s nao foi declarada\n", yylineno, (yyvsp[0].sValue));
                                    exit(EXIT_FAILURE);
                            }
 
                            StaticInfo *aux = utils_createStaticInfo((yyvsp[0].sValue), lhsVar->type); 
                            (yyval.strValue) = aux;
                        }
#line 2774 "y.tab.c"
    break;

  case 108:
#line 754 "parser.y"
                                 { 
                                    char * s = malloc(sizeof(int));
                                    sprintf(s, "%d", (yyvsp[0].iValue));
                                    (yyval.strValue) = utils_createStaticInfo(s, "int");
                                    free(s); 
                                }
#line 2785 "y.tab.c"
    break;

  case 109:
#line 760 "parser.y"
                                 { 
                                    char * s = malloc(sizeof(float));
                                    sprintf(s, "%f", (yyvsp[0].fValue));
                                    (yyval.strValue) = utils_createStaticInfo(s, "float");
                                    free(s); 
                                }
#line 2796 "y.tab.c"
    break;

  case 110:
#line 766 "parser.y"
                                 { 
                                    char * s = malloc(sizeof(double));
                                    sprintf(s, "%f", (yyvsp[0].dValue));
                                    (yyval.strValue) = utils_createStaticInfo(s, "double");
                                    free(s); 
                                }
#line 2807 "y.tab.c"
    break;

  case 111:
#line 773 "parser.y"
                        { 
                            char * s = malloc(sizeof(int));
                            sprintf(s, "%d", (yyvsp[0].bValue));
                            (yyval.strValue) = utils_createStaticInfo(s, "boolean");
                            free(s);
                        }
#line 2818 "y.tab.c"
    break;

  case 112:
#line 779 "parser.y"
                        {   
                            char * s = malloc(sizeof(int));
                            sprintf(s, "%d", (yyvsp[0].bValue));
                            (yyval.strValue) = utils_createStaticInfo(s, "boolean");
                            free(s); 
                        }
#line 2829 "y.tab.c"
    break;

  case 113:
#line 787 "parser.y"
                                        {(yyval.strValue) = (yyvsp[0].strValue);}
#line 2835 "y.tab.c"
    break;

  case 114:
#line 788 "parser.y"
                                        {(yyval.strValue) = (yyvsp[0].strValue);}
#line 2841 "y.tab.c"
    break;

  case 115:
#line 790 "parser.y"
                                        { (yyval.strValue) = utils_createStaticInfo((yyvsp[0].sValue), "char"); }
#line 2847 "y.tab.c"
    break;

  case 116:
#line 791 "parser.y"
                                        { (yyval.strValue) = utils_createStaticInfo((yyvsp[0].sValue), "string"); }
#line 2853 "y.tab.c"
    break;


#line 2857 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 794 "parser.y"


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
