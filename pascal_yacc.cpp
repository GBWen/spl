/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "pascal.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sstream>
#include <assert.h>
#include "SymbolTable.hpp"
#include "G4.h"
#include "GS.h"
using namespace std;

SymbolTable* programTable = new SymbolTable(NULL);
SymbolTable* current = programTable;

int errorCount = 0;


#line 84 "pascal_yacc.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "pascal_yacc.hpp".  */
#ifndef YY_YY_PASCAL_YACC_HPP_INCLUDED
# define YY_YY_PASCAL_YACC_HPP_INCLUDED
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
    TOK_LP = 258,
    TOK_RP = 259,
    TOK_LB = 260,
    TOK_RB = 261,
    TOK_DOT = 262,
    TOK_COMMA = 263,
    TOK_SEMI = 264,
    TOK_COLON = 265,
    TOK_MUL = 266,
    TOK_DIV = 267,
    TOK_PLUS = 268,
    TOK_MINUS = 269,
    TOK_GE = 270,
    TOK_GT = 271,
    TOK_LE = 272,
    TOK_LT = 273,
    TOK_EQUAL = 274,
    TOK_UNEQUAL = 275,
    TOK_ASSIGN = 276,
    TOK_PROGRAM = 277,
    TOK_PROCEDURE = 278,
    TOK_FUNCTION = 279,
    TOK_EXIT = 280,
    TOK_LABEL = 281,
    TOK_CONST = 282,
    TOK_TYPE = 283,
    TOK_VAR = 284,
    TOK_ARRAY = 285,
    TOK_RECORD = 286,
    TOK_INTEGER = 287,
    TOK_REAL = 288,
    TOK_CHAR = 289,
    TOK_STRING = 290,
    TOK_BOOLEAN = 291,
    TOK_BEGIN = 292,
    TOK_END = 293,
    TOK_IF = 294,
    TOK_THEN = 295,
    TOK_ELSE = 296,
    TOK_FOR = 297,
    TOK_TO = 298,
    TOK_DOWNTO = 299,
    TOK_DO = 300,
    TOK_CASE = 301,
    TOK_OF = 302,
    TOK_WHILE = 303,
    TOK_REPEAT = 304,
    TOK_UNTIL = 305,
    TOK_GOTO = 306,
    TOK_OR = 307,
    TOK_AND = 308,
    TOK_XOR = 309,
    TOK_NOT = 310,
    TOK_MOD = 311,
    TOK_SHL = 312,
    TOK_SHR = 313,
    TOK_WRITELN = 314,
    TOK_WRITE = 315,
    TOK_MAXINT = 316,
    TOK_READ = 317,
    TOK_READLN = 318,
    TOK_ABS = 319,
    TOK_CHR = 320,
    TOK_ODD = 321,
    TOK_ORD = 322,
    TOK_PRED = 323,
    TOK_SQR = 324,
    TOK_SQRT = 325,
    TOK_SUCC = 326,
    NAME = 327,
    CONST_INTEGER = 328,
    CONST_REAL = 329,
    CONST_CHAR = 330,
    CONST_STRING = 331,
    CONST_BOOLEAN = 332
  };
#endif
/* Tokens.  */
#define TOK_LP 258
#define TOK_RP 259
#define TOK_LB 260
#define TOK_RB 261
#define TOK_DOT 262
#define TOK_COMMA 263
#define TOK_SEMI 264
#define TOK_COLON 265
#define TOK_MUL 266
#define TOK_DIV 267
#define TOK_PLUS 268
#define TOK_MINUS 269
#define TOK_GE 270
#define TOK_GT 271
#define TOK_LE 272
#define TOK_LT 273
#define TOK_EQUAL 274
#define TOK_UNEQUAL 275
#define TOK_ASSIGN 276
#define TOK_PROGRAM 277
#define TOK_PROCEDURE 278
#define TOK_FUNCTION 279
#define TOK_EXIT 280
#define TOK_LABEL 281
#define TOK_CONST 282
#define TOK_TYPE 283
#define TOK_VAR 284
#define TOK_ARRAY 285
#define TOK_RECORD 286
#define TOK_INTEGER 287
#define TOK_REAL 288
#define TOK_CHAR 289
#define TOK_STRING 290
#define TOK_BOOLEAN 291
#define TOK_BEGIN 292
#define TOK_END 293
#define TOK_IF 294
#define TOK_THEN 295
#define TOK_ELSE 296
#define TOK_FOR 297
#define TOK_TO 298
#define TOK_DOWNTO 299
#define TOK_DO 300
#define TOK_CASE 301
#define TOK_OF 302
#define TOK_WHILE 303
#define TOK_REPEAT 304
#define TOK_UNTIL 305
#define TOK_GOTO 306
#define TOK_OR 307
#define TOK_AND 308
#define TOK_XOR 309
#define TOK_NOT 310
#define TOK_MOD 311
#define TOK_SHL 312
#define TOK_SHR 313
#define TOK_WRITELN 314
#define TOK_WRITE 315
#define TOK_MAXINT 316
#define TOK_READ 317
#define TOK_READLN 318
#define TOK_ABS 319
#define TOK_CHR 320
#define TOK_ODD 321
#define TOK_ORD 322
#define TOK_PRED 323
#define TOK_SQR 324
#define TOK_SQRT 325
#define TOK_SUCC 326
#define NAME 327
#define CONST_INTEGER 328
#define CONST_REAL 329
#define CONST_CHAR 330
#define CONST_STRING 331
#define CONST_BOOLEAN 332

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 19 "pascal.y" /* yacc.c:355  */

	ValueNode* value;
    TreeNode* tree;

#line 283 "pascal_yacc.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PASCAL_YACC_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 298 "pascal_yacc.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   462

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  323

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   332

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   111,   111,   121,   127,   127,   135,   143,   151,   162,
     166,   172,   176,   183,   191,   191,   199,   204,   210,   214,
     221,   230,   230,   238,   241,   244,   247,   250,   256,   259,
     265,   270,   276,   280,   287,   296,   296,   304,   307,   310,
     316,   320,   324,   330,   337,   345,   354,   364,   367,   370,
     373,   376,   382,   394,   403,   407,   414,   421,   421,   429,
     433,   440,   445,   451,   455,   462,   474,   474,   482,   486,
     490,   494,   498,   501,   508,   521,   521,   537,   549,   549,
     562,   568,   574,   578,   582,   589,   599,   612,   620,   627,
     633,   639,   643,   649,   654,   660,   663,   666,   669,   672,
     675,   678,   681,   684,   687,   694,   699,   709,   720,   723,
     729,   732,   738,   746,   749,   756,   759,   765,   778,   782,
     788,   800,   811,   826,   829,   835,   846,   850,   857,   864,
     870,   870,   878,   885,   890,   897,   902,   907,   912,   917,
     922,   927,   933,   938,   943,   948,   953,   959,   964,   969,
     974,   979,   984,   989,   995,   998,  1004,  1010,  1014,  1021,
    1024,  1027,  1031,  1035,  1041,  1049,  1052,  1055,  1058,  1061,
    1064,  1067,  1070,  1076,  1080
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_LP", "TOK_RP", "TOK_LB", "TOK_RB",
  "TOK_DOT", "TOK_COMMA", "TOK_SEMI", "TOK_COLON", "TOK_MUL", "TOK_DIV",
  "TOK_PLUS", "TOK_MINUS", "TOK_GE", "TOK_GT", "TOK_LE", "TOK_LT",
  "TOK_EQUAL", "TOK_UNEQUAL", "TOK_ASSIGN", "TOK_PROGRAM", "TOK_PROCEDURE",
  "TOK_FUNCTION", "TOK_EXIT", "TOK_LABEL", "TOK_CONST", "TOK_TYPE",
  "TOK_VAR", "TOK_ARRAY", "TOK_RECORD", "TOK_INTEGER", "TOK_REAL",
  "TOK_CHAR", "TOK_STRING", "TOK_BOOLEAN", "TOK_BEGIN", "TOK_END",
  "TOK_IF", "TOK_THEN", "TOK_ELSE", "TOK_FOR", "TOK_TO", "TOK_DOWNTO",
  "TOK_DO", "TOK_CASE", "TOK_OF", "TOK_WHILE", "TOK_REPEAT", "TOK_UNTIL",
  "TOK_GOTO", "TOK_OR", "TOK_AND", "TOK_XOR", "TOK_NOT", "TOK_MOD",
  "TOK_SHL", "TOK_SHR", "TOK_WRITELN", "TOK_WRITE", "TOK_MAXINT",
  "TOK_READ", "TOK_READLN", "TOK_ABS", "TOK_CHR", "TOK_ODD", "TOK_ORD",
  "TOK_PRED", "TOK_SQR", "TOK_SQRT", "TOK_SUCC", "NAME", "CONST_INTEGER",
  "CONST_REAL", "CONST_CHAR", "CONST_STRING", "CONST_BOOLEAN", "$accept",
  "program", "program_head", "$@1", "routine", "sub_routine",
  "routine_head", "label_part", "label_list", "single_label", "$@2",
  "const_part", "const_expr_list", "const_expr", "$@3", "const_value",
  "SYS_CON", "type_part", "type_decl_list", "type_definition", "$@4",
  "type_decl", "simple_type_decl", "SYS_TYPE", "array_type_decl",
  "record_type_decl", "field_decl_list", "field_decl", "$@5", "name_list",
  "var_part", "var_decl_list", "var_decl", "$@6", "routine_part",
  "function_decl", "function_head", "$@7", "procedure_decl",
  "procedure_head", "$@8", "parameters", "para_decl_list",
  "para_type_list", "var_para_list", "val_para_list", "routine_body",
  "compound_stmt", "stmt_list", "stmt", "non_label_stmt", "assign_stmt",
  "proc_stmt", "SYS_PROC", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "$@9", "goto_stmt", "expression_list", "expression", "expr",
  "term", "factor", "SYS_FUNCT", "args_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332
};
# endif

#define YYPACT_NINF -227

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-227)))

#define YYTABLE_NINF -62

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,  -227,   -44,    38,   172,    44,    52,  -227,  -227,     5,
      74,    57,   102,   375,  -227,  -227,  -227,   129,   142,  -227,
    -227,  -227,  -227,    13,   127,  -227,  -227,  -227,   242,  -227,
     138,     8,  -227,    14,   140,  -227,   167,  -227,   113,   103,
     113,   113,  -227,   119,  -227,  -227,   168,   145,   166,  -227,
     188,  -227,  -227,  -227,   199,  -227,  -227,  -227,  -227,  -227,
    -227,   194,   150,  -227,  -227,   191,    10,  -227,    20,   116,
     113,   113,   113,   113,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,   151,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,   410,    16,     7,  -227,   210,   195,    94,   241,   281,
    -227,   113,   113,   113,   146,   113,   335,  -227,   113,  -227,
     208,   211,   201,  -227,  -227,  -227,    64,    19,  -227,   149,
     158,   218,  -227,   238,  -227,   239,   245,   331,  -227,  -227,
     113,   113,   173,   113,   113,   113,   113,   113,   113,   320,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,    88,   320,   113,   249,   416,    36,    98,   416,
     233,   416,  -227,    47,  -227,  -227,   192,   150,   258,    21,
    -227,  -227,  -227,  -227,  -227,   259,   276,   256,  -227,  -227,
    -227,  -227,   278,   213,   201,  -227,  -227,  -227,  -227,  -227,
    -227,   172,   172,  -227,  -227,    54,   115,   436,  -227,    16,
      16,    16,    16,    16,    16,   248,     7,     7,     7,     7,
    -227,  -227,  -227,  -227,  -227,  -227,    71,   404,  -227,   282,
     284,    70,  -227,  -227,   416,  -227,  -227,   113,   274,   113,
     113,  -227,    99,   289,   236,  -227,    11,  -227,   118,   291,
     292,  -227,  -227,  -227,   294,   297,   297,   296,    57,   298,
    -227,  -227,  -227,   320,  -227,  -227,  -227,  -227,   113,   307,
     320,   320,  -227,  -227,   416,   113,   416,   416,  -227,   310,
     313,   315,  -227,  -227,   201,   250,   150,  -227,   -13,  -227,
     316,  -227,  -227,  -227,  -227,   398,  -227,   319,   325,   416,
      59,   286,  -227,   328,  -227,  -227,   192,   317,    48,  -227,
     329,   332,   236,   320,  -227,  -227,   150,  -227,   201,  -227,
     317,  -227,    12,   236,   236,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     0,     0,     0,     1,    14,     0,
       0,     0,    17,     0,    12,     5,     3,     0,     0,     2,
      92,     6,    89,     0,    31,    11,    15,    13,     0,    21,
       0,     0,    19,     0,    62,   104,   113,    90,     0,     0,
       0,     0,    92,     0,   116,   115,     0,   108,     0,    97,
       0,    94,    95,    96,   110,    98,    99,   100,   101,   102,
     103,     0,     0,    18,    35,     0,     0,    33,     0,    72,
       0,     0,     0,     0,    28,   165,   166,   167,   168,   169,
     170,   171,   172,   154,    23,    24,    25,    26,    29,   159,
      27,     0,   141,   146,   153,   157,     0,     0,     0,     0,
     132,     0,     0,     0,     0,     0,     0,    91,     0,    22,
       0,     0,     0,    32,    66,    60,     0,     0,    64,     0,
       0,     0,    70,     0,    71,     0,     0,     0,   162,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   174,     0,     0,   134,
       0,   105,    93,     0,    20,    36,     0,     0,     0,     0,
      49,    50,    48,    51,    47,    41,     0,     0,    37,    40,
      38,    39,     0,     0,     0,    63,    78,    75,    73,    68,
      69,     0,     0,   114,   160,     0,     0,   134,   164,   135,
     136,   137,   138,   139,   140,   119,   142,   143,   144,   145,
     147,   148,   150,   149,   151,   152,     0,     0,   130,     0,
       0,     0,   127,   121,   120,   112,   109,     0,     0,     0,
       0,   111,     0,     0,     0,    57,     0,    55,     0,     0,
       0,    34,    67,    59,     0,    81,    81,     0,     0,     0,
     155,   156,   163,     0,   117,   158,   123,   124,     0,     0,
       0,     0,   125,   126,   173,     0,   133,   107,    42,     0,
       0,     0,    53,    54,     0,     0,     0,    65,     0,    79,
       0,    74,     7,    77,   118,     0,   131,     0,     0,   106,
       0,     0,    58,     0,    46,    43,     0,    88,     0,    83,
       0,     0,     0,     0,   129,   128,     0,    44,     0,    56,
      87,    80,     0,     0,     0,    76,   122,    45,    52,    84,
      82,    85,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -227,  -227,  -227,  -227,  -227,   152,   334,  -227,  -227,   339,
    -227,  -227,  -227,   327,  -227,   -62,  -227,  -227,  -227,   290,
    -227,  -178,  -226,  -227,  -227,  -227,  -227,   125,  -227,  -159,
    -227,  -227,   246,  -227,  -227,   234,  -227,  -227,   243,  -227,
    -227,   121,  -227,    53,  -227,  -227,   122,   -10,   333,  -136,
     267,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,   157,  -227,  -227,   254,   -36,   324,    65,   -47,
    -227,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    10,   247,   248,    12,    13,    14,
      17,    24,    31,    32,    61,    89,    90,    34,    66,    67,
     111,   177,   178,   179,   180,   181,   236,   237,   271,   116,
      69,   117,   118,   182,   121,   122,   123,   246,   124,   125,
     245,   279,   298,   299,   300,   301,    21,    49,    28,    50,
      51,    52,    53,    54,    55,   254,    56,    57,    58,   258,
      59,   221,   222,   259,    60,   158,   156,    92,    93,    94,
      95,   157
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     110,    22,    91,   205,    97,    98,   244,   232,   270,    29,
     238,    64,   235,   319,    29,    64,   296,   223,   144,   145,
     114,   114,   235,   126,   163,   128,   129,     1,     6,   140,
     141,   -16,   -16,   -30,   -30,   127,   -16,   -16,     7,   -30,
     226,   296,   -61,   -61,   227,   -16,   195,   -30,     2,   272,
     176,   231,   311,    15,   155,   227,   -61,   312,   250,   115,
     146,    16,   227,   147,   148,   149,   216,   159,   142,   161,
     143,   218,   183,   306,   184,   255,   315,   238,    18,   227,
      30,    19,    65,   115,   115,    30,    65,   321,   322,   218,
     220,   115,   115,   115,    20,   197,   293,   210,   211,   212,
     213,   214,   215,   268,   228,   233,   229,   183,   262,   133,
     134,   135,   136,   137,   138,   217,    71,   284,   224,   297,
      74,   251,   176,   229,   287,   288,   183,    72,   274,    23,
     318,    74,    84,    85,    86,    87,    88,   310,    26,   119,
     120,   152,   219,    84,    85,    86,    87,    88,   102,    74,
     103,    27,   104,   297,   130,    33,   131,    62,   132,   220,
     219,    84,    85,    86,    87,    88,   105,   316,    73,    68,
      70,   101,   176,     8,    74,    96,   106,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,   264,   100,   266,   267,   -10,   -10,   107,     9,   -10,
     -10,   -10,   108,   109,   166,   206,   207,   208,   209,   -10,
     112,    74,   176,   150,   295,   167,   151,   164,   160,   188,
     165,   186,   285,    84,    85,    86,    87,    88,   307,   289,
     187,   168,   169,   170,   171,   172,   173,   174,    22,   166,
     176,   119,   120,    35,   317,   198,   176,   191,   192,   193,
     167,   176,   176,   225,   230,    -8,   133,   134,   135,   136,
     137,   138,    74,   234,   115,   241,   239,    36,   170,   171,
     172,   173,   174,   175,    84,    85,    86,    87,    88,    20,
      37,    38,    35,   240,    39,   243,   153,   242,    40,   253,
      41,    42,   260,    43,   261,   265,   269,    74,   275,   276,
     278,    44,    45,   277,    46,   281,    36,   283,   175,    84,
      85,    86,    87,    88,    47,    48,   286,   290,    20,   291,
      38,    35,   294,    39,   292,   183,   302,    40,   304,    41,
      42,   154,    43,   308,   305,   194,    35,   309,    11,   313,
      44,    45,   314,    46,   249,    36,   133,   134,   135,   136,
     137,   138,    25,    47,    48,   189,   113,    20,    63,    38,
      36,   273,    39,   185,   190,   320,    40,   280,    41,    42,
     282,    43,    20,   162,    38,    99,     8,    39,   263,    44,
      45,    40,    46,    41,    42,   196,    43,     0,     0,     0,
       0,     0,    47,    48,    44,    45,     0,    46,    -9,    -9,
       0,     9,    -9,    -9,    -9,     0,     0,    47,     0,     0,
       0,     0,    -9,   133,   134,   135,   136,   137,   138,   133,
     134,   135,   136,   137,   138,   133,   134,   135,   136,   137,
     138,   133,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,   252,   303,     0,     0,     0,   256,   257,     0,
     139,   133,   134,   135,   136,   137,   138,   199,   200,   201,
     202,   203,   204
};

static const yytype_int16 yycheck[] =
{
      62,    11,    38,   139,    40,    41,   184,   166,   234,     1,
     169,     1,     1,     1,     1,     1,    29,   153,    11,    12,
       1,     1,     1,    70,   108,    72,    73,     1,    72,    13,
      14,    23,    24,    23,    24,    71,    28,    29,     0,    29,
       4,    29,    23,    24,     8,    37,   130,    37,    22,    38,
     112,     4,     4,     9,   101,     8,    37,     9,     4,    72,
      53,     9,     8,    56,    57,    58,   150,   103,    52,   105,
      54,     1,     8,    14,    10,     4,   302,   236,    73,     8,
      72,     7,    72,    72,    72,    72,    72,   313,   314,     1,
     152,    72,    72,    72,    37,   131,   274,   144,   145,   146,
     147,   148,   149,     4,     6,   167,     8,     8,    38,    15,
      16,    17,    18,    19,    20,   151,     3,   253,   154,   278,
      61,     6,   184,     8,   260,   261,     8,    14,    10,    27,
     308,    61,    73,    74,    75,    76,    77,   296,     9,    23,
      24,    47,    72,    73,    74,    75,    76,    77,     3,    61,
       5,     9,     7,   312,     3,    28,     5,    19,     7,   221,
      72,    73,    74,    75,    76,    77,    21,   303,    55,    29,
       3,     3,   234,     1,    61,    72,    10,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,   227,    73,   229,   230,    23,    24,     9,    26,    27,
      28,    29,     3,     9,     3,   140,   141,   142,   143,    37,
      19,    61,   274,     3,   276,    14,    21,     9,    72,     1,
       9,    72,   258,    73,    74,    75,    76,    77,   290,   265,
      72,    30,    31,    32,    33,    34,    35,    36,   248,     3,
     302,    23,    24,     1,   306,    72,   308,     9,     9,     4,
      14,   313,   314,     4,    21,    37,    15,    16,    17,    18,
      19,    20,    61,     5,    72,     9,     7,    25,    32,    33,
      34,    35,    36,    72,    73,    74,    75,    76,    77,    37,
      38,    39,     1,     7,    42,    72,    45,     9,    46,    41,
      48,    49,    10,    51,    10,    21,     7,    61,     7,     7,
       3,    59,    60,     9,    62,     9,    25,     9,    72,    73,
      74,    75,    76,    77,    72,    73,     9,     7,    37,     6,
      39,     1,    72,    42,     9,     8,    10,    46,     9,    48,
      49,    50,    51,    47,     9,     4,     1,     9,     4,    10,
      59,    60,    10,    62,   192,    25,    15,    16,    17,    18,
      19,    20,    13,    72,    73,   121,    66,    37,    31,    39,
      25,   236,    42,   117,   121,   312,    46,   246,    48,    49,
     248,    51,    37,   106,    39,    42,     1,    42,   221,    59,
      60,    46,    62,    48,    49,   131,    51,    -1,    -1,    -1,
      -1,    -1,    72,    73,    59,    60,    -1,    62,    23,    24,
      -1,    26,    27,    28,    29,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    37,    15,    16,    17,    18,    19,    20,    15,
      16,    17,    18,    19,    20,    15,    16,    17,    18,    19,
      20,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,     6,    45,    -1,    -1,    -1,    43,    44,    -1,
      40,    15,    16,    17,    18,    19,    20,   133,   134,   135,
     136,   137,   138
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    22,    79,    80,    81,    72,     0,     1,    26,
      82,    84,    85,    86,    87,     9,     9,    88,    73,     7,
      37,   124,   125,    27,    89,    87,     9,     9,   126,     1,
      72,    90,    91,    28,    95,     1,    25,    38,    39,    42,
      46,    48,    49,    51,    59,    60,    62,    72,    73,   125,
     127,   128,   129,   130,   131,   132,   134,   135,   136,   138,
     142,    92,    19,    91,     1,    72,    96,    97,    29,   108,
       3,     3,    14,    55,    61,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    93,
      94,   144,   145,   146,   147,   148,    72,   144,   144,   126,
      73,     3,     3,     5,     7,    21,    10,     9,     3,     9,
      93,    98,    19,    97,     1,    72,   107,   109,   110,    23,
      24,   112,   113,   114,   116,   117,   147,   144,   147,   147,
       3,     5,     7,    15,    16,    17,    18,    19,    20,    40,
      13,    14,    52,    54,    11,    12,    53,    56,    57,    58,
       3,    21,    47,    45,    50,   147,   144,   149,   143,   144,
      72,   144,   128,   149,     9,     9,     3,    14,    30,    31,
      32,    33,    34,    35,    36,    72,    93,    99,   100,   101,
     102,   103,   111,     8,    10,   110,    72,    72,     1,   113,
     116,     9,     9,     4,     4,   149,   143,   144,    72,   145,
     145,   145,   145,   145,   145,   127,   146,   146,   146,   146,
     147,   147,   147,   147,   147,   147,   149,   144,     1,    72,
      93,   139,   140,   127,   144,     4,     4,     8,     6,     8,
      21,     4,   107,    93,     5,     1,   104,   105,   107,     7,
       7,     9,     9,    72,    99,   118,   115,    83,    84,    83,
       4,     6,     6,    41,   133,     4,    43,    44,   137,   141,
      10,    10,    38,   140,   144,    21,   144,   144,     4,     7,
     100,   106,    38,   105,    10,     7,     7,     9,     3,   119,
     119,     9,   124,     9,   127,   144,     9,   127,   127,   144,
       7,     6,     9,    99,    72,    93,    29,   107,   120,   121,
     122,   123,    10,    45,     9,     9,    14,    93,    47,     9,
     107,     4,     9,    10,    10,   100,   127,    93,    99,     1,
     121,   100,   100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    81,    80,    82,    83,    84,    85,
      85,    86,    86,    87,    88,    87,    89,    89,    90,    90,
      91,    92,    91,    93,    93,    93,    93,    93,    94,    94,
      95,    95,    96,    96,    97,    98,    97,    99,    99,    99,
     100,   100,   100,   100,   100,   100,   100,   101,   101,   101,
     101,   101,   102,   103,   104,   104,   105,   106,   105,   107,
     107,   108,   108,   109,   109,   110,   111,   110,   112,   112,
     112,   112,   112,   112,   113,   115,   114,   116,   118,   117,
     119,   119,   120,   120,   120,   121,   121,   122,   123,   124,
     125,   126,   126,   127,   127,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   129,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   131,   131,   132,   133,   133,
     134,   135,   136,   137,   137,   138,   139,   139,   140,   140,
     141,   140,   142,   143,   143,   144,   144,   144,   144,   144,
     144,   144,   145,   145,   145,   145,   145,   146,   146,   146,
     146,   146,   146,   146,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   148,   148,   148,   148,   148,
     148,   148,   148,   149,   149
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     0,     3,     2,     2,     5,     1,
       0,     2,     1,     3,     0,     3,     2,     0,     2,     1,
       4,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     2,     1,     4,     0,     3,     1,     1,     1,
       1,     1,     3,     4,     5,     6,     4,     1,     1,     1,
       1,     1,     6,     3,     2,     1,     4,     0,     3,     3,
       1,     2,     0,     2,     1,     4,     0,     3,     2,     2,
       1,     1,     0,     2,     4,     0,     6,     4,     0,     4,
       3,     0,     3,     1,     3,     3,     3,     2,     1,     1,
       3,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     6,     5,     1,     4,
       1,     4,     4,     1,     4,     1,     1,     5,     2,     0,
       4,     4,     8,     1,     1,     5,     2,     1,     4,     4,
       0,     3,     2,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     1,     4,     4,     1,     4,     1,
       3,     2,     2,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 111 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
        current->self = (yyval.tree);
    }
#line 1664 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 121 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 1675 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 127 "pascal.y" /* yacc.c:1646  */
    {

	}
#line 1683 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 129 "pascal.y" /* yacc.c:1646  */
    {
		(yyval.tree) = NULL;
	}
#line 1691 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 135 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 1701 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 143 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 1711 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 151 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert((yyvsp[-4].tree));
        (yyval.tree)->insert((yyvsp[-3].tree));
        (yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 1724 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 162 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 1733 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 166 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
    }
#line 1741 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 172 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-1].tree);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 1750 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 176 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 1759 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 183 "pascal.y" /* yacc.c:1646  */
    {
        // add label to decl
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
        current->insertDecl((yyvsp[-1].value)->name, (yyval.tree));
    }
#line 1772 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 191 "pascal.y" /* yacc.c:1646  */
    {
		//yyerror("Label declaration error.");
	}
#line 1780 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 193 "pascal.y" /* yacc.c:1646  */
    {
		(yyval.tree) = NULL;
	}
#line 1788 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 199 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 1798 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 204 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
    }
#line 1806 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 210 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-1].tree);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 1815 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 214 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 1824 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 221 "pascal.y" /* yacc.c:1646  */
    {
        // add const to decl
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-3].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
        current->insertDecl((yyvsp[-3].value)->name, (yyvsp[-1].tree));
    }
#line 1838 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 230 "pascal.y" /* yacc.c:1646  */
    {
		//yyerror("Const declaration error.");
	}
#line 1846 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 232 "pascal.y" /* yacc.c:1646  */
    {
		(yyval.tree) = NULL;
	}
#line 1854 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 238 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 1862 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 241 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 1870 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 244 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 1878 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 247 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 1886 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 250 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1894 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 256 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value), ValNode);
    }
#line 1902 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 259 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 1910 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 265 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 1920 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 270 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
    }
#line 1928 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 276 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-1].tree);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 1937 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 280 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 1946 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 287 "pascal.y" /* yacc.c:1646  */
    {
        // add type to decl
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-3].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
        current->insertDecl((yyvsp[-3].value)->name, (yyvsp[-1].tree));
    }
#line 1960 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 296 "pascal.y" /* yacc.c:1646  */
    {
		//yyerror("Type declaration error.");
	}
#line 1968 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 298 "pascal.y" /* yacc.c:1646  */
    {
		(yyval.tree) = NULL;
	}
#line 1976 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 304 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1984 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 307 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1992 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 310 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2000 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 316 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2009 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 320 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 2018 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 324 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 2029 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 330 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert((yyvsp[-3].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2041 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 337 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-4].value)));
        (yyval.tree)->insert((yyvsp[-3].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2054 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 345 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-5].value)));
        (yyval.tree)->insert((yyvsp[-4].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[-3].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2068 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 354 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-3].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 2080 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 364 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 2088 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 367 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 2096 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 370 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 2104 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 373 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 2112 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 376 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 2120 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 382 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-5].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-4].value)));
        (yyval.tree)->insert((yyvsp[-3].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2134 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 394 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 2145 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 403 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-1].tree);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2154 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 407 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2163 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 414 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert((yyvsp[-3].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 2175 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 421 "pascal.y" /* yacc.c:1646  */
    {
		//yyerror("Record declaration error.");
	}
#line 2183 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 423 "pascal.y" /* yacc.c:1646  */
    {
		(yyval.tree) = NULL;
	}
#line 2191 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 429 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-2].tree);
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 2200 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 433 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 2209 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 440 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2219 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 445 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
    }
#line 2227 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 451 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-1].tree);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2236 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 455 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2245 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 462 "pascal.y" /* yacc.c:1646  */
    {
        // add var to decl
        (yyval.tree) = new TreeNode(TypeNode);
        (yyval.tree)->insert((yyvsp[-3].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
        for (int i=0; i< (yyvsp[-3].tree)->Children.size(); i++){
            TreeNode *name = (yyvsp[-3].tree)->Children[i];
            current->insertDecl(name->name, (yyvsp[-1].tree));
        }
    }
#line 2262 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 474 "pascal.y" /* yacc.c:1646  */
    {
		//yyerror("Variable declaration error.");
	}
#line 2270 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 476 "pascal.y" /* yacc.c:1646  */
    {
		(yyval.tree) = NULL;
	}
#line 2278 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 482 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-1].tree);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2287 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 486 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-1].tree);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2296 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 490 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2305 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 494 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2314 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 498 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
    }
#line 2322 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 501 "pascal.y" /* yacc.c:1646  */
    {
		(yyval.tree) = (yyvsp[-1].tree);
		//yyerror("Procedure / Function declaration error.");
	}
#line 2331 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 508 "pascal.y" /* yacc.c:1646  */
    {
        // change the SymbolTable to sub-program
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert((yyvsp[-3].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
        current->self = (yyval.tree);
        current = current->father;
    }
#line 2346 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 521 "pascal.y" /* yacc.c:1646  */
    {
        // add the function to father's SymbolTable
        SymbolTable* tmp = new SymbolTable(current);
        current->insertProc((yyvsp[0].value)->name, tmp);
        current = tmp;
    }
#line 2357 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 526 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-5].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-4].value)));
        (yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2370 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 537 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert((yyvsp[-3].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
        current->self = (yyval.tree);
        current = current->father;
    }
#line 2384 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 549 "pascal.y" /* yacc.c:1646  */
    {
        SymbolTable* tmp = new SymbolTable(current);
        current->insertProc((yyvsp[0].value)->name, tmp);
        current = tmp;
    }
#line 2394 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 553 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-3].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2405 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 562 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 2416 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 568 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
    }
#line 2424 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 574 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-2].tree);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2433 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 578 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2442 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 582 "pascal.y" /* yacc.c:1646  */
    {
		(yyval.tree) = (yyvsp[-2].tree);
		//yyerror("Parameter declaration error.");
	}
#line 2451 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 589 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
		TreeNode* tmp = (yyvsp[-2].tree)->Children[1];
		for (int i=0; i<tmp->Children.size(); i++){
			current->insertParameter(tmp->Children[i]->name, 1, (yyvsp[0].tree));
		}
    }
#line 2466 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 599 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
		TreeNode* tmp = (yyvsp[-2].tree)->Children[0];
		for (int i=0; i<tmp->Children.size(); i++){
			current->insertParameter(tmp->Children[i]->name, 0, (yyvsp[0].tree));
		}
    }
#line 2481 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 612 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2491 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 620 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2500 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 627 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2508 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 633 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-1].tree);
    }
#line 2516 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 639 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-2].tree);
        (yyval.tree)->insert((yyvsp[-1].tree));
    }
#line 2525 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 643 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ProgrameNode);
    }
#line 2533 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 649 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), StatementNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2543 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 654 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2551 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 660 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2559 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 663 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2567 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 666 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2575 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 669 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2583 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 672 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2591 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 675 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2599 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 678 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2607 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 681 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2615 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 684 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2623 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 687 "pascal.y" /* yacc.c:1646  */
    {
		(yyval.tree) = NULL;
		//yyerror("Statement Error.");
	}
#line 2632 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 694 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2642 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 699 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		TreeNode *name = new TreeNode((yyvsp[-5].value));
        name->insert(new TreeNode((yyvsp[-4].value)));
        name->insertChild((yyvsp[-3].tree));
        name->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert(name);
        (yyval.tree)->insert((yyvsp[0].tree));

    }
#line 2657 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 709 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		TreeNode *dot = new TreeNode((yyvsp[-3].value), StatementNode);
		dot->insert(new TreeNode((yyvsp[-4].value)));
		dot->insert(new TreeNode((yyvsp[-2].value)));
		(yyval.tree)->insert(dot);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2670 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 720 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value), ProcedureNode);
    }
#line 2678 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 723 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-3].value), ProcedureNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 2689 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 729 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2697 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 732 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-3].tree);
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 2708 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 738 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-3].value), StatementNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
		TreeNode* args = new TreeNode(StatementNode);
		args->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(args);
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 2721 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 746 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value), StatementNode);
	}
#line 2729 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 749 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-3].value), StatementNode);
        (yyval.tree)->insert((yyvsp[-1].tree));
    }
#line 2738 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 756 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value), StatementNode);
    }
#line 2746 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 759 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value), StatementNode);
    }
#line 2754 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 765 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-4].value), StatementNode);
		(yyval.tree)->insert(new TreeNode((yyvsp[-4].value)));
        (yyval.tree)->insert((yyvsp[-3].tree));
		TreeNode *then = new TreeNode((yyvsp[-2].value));
		then->insert((yyvsp[-1].tree));
		(yyval.tree)->insert(then);
		if ((yyvsp[0].tree) != NULL)
			(yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2769 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 778 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), StatementNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2778 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 782 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = NULL;
    }
#line 2786 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 788 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-3].value), StatementNode);
		TreeNode *repeat = new TreeNode((yyvsp[-3].value));
		repeat->insert((yyvsp[-2].tree));
        (yyval.tree)->insert(repeat);
		TreeNode *until = new TreeNode((yyvsp[-1].value));
		until->insert((yyvsp[0].tree));
        (yyval.tree)->insert(until);
    }
#line 2800 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 800 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-3].value), StatementNode);
		(yyval.tree)->insert(new TreeNode((yyvsp[-3].value)));
        (yyval.tree)->insert((yyvsp[-2].tree));
		TreeNode *tok_do = new TreeNode((yyvsp[-1].value));
		tok_do->insert((yyvsp[0].tree));
        (yyval.tree)->insert(tok_do);
    }
#line 2813 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 811 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-7].value), StatementNode);
		(yyval.tree)->insert(new TreeNode((yyvsp[-7].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-6].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[-5].value)));
        (yyval.tree)->insert((yyvsp[-4].tree));
        (yyval.tree)->insert((yyvsp[-3].tree));
        (yyval.tree)->insert((yyvsp[-2].tree));
		TreeNode *tok_do = new TreeNode((yyvsp[-1].value));
		tok_do->insert((yyvsp[0].tree));
        (yyval.tree)->insert(tok_do);
    }
#line 2830 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 826 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 2838 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 829 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 2846 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 835 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-4].value), StatementNode);
		(yyval.tree)->insert(new TreeNode((yyvsp[-4].value)));
		TreeNode *of = new TreeNode((yyvsp[-2].value));
		of->insert((yyvsp[-1].tree));
		(yyval.tree)->insert((yyvsp[-3].tree));
        (yyval.tree)->insert(of);
    }
#line 2859 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 846 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-1].tree);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2868 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 850 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(StatementNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2877 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 857 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-2].value));
		// to make the $$->name to be case:
		(yyval.tree)->name = "case" + (yyval.tree)->name;
        (yyval.tree)->insert((yyvsp[-3].tree));
		(yyval.tree)->insert((yyvsp[-1].tree));
    }
#line 2889 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 864 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-2].value));
		(yyval.tree)->name = "case" + (yyval.tree)->name;
		(yyval.tree)->insert(new TreeNode((yyvsp[-3].value)));
		(yyval.tree)->insert((yyvsp[-1].tree));
    }
#line 2900 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 870 "pascal.y" /* yacc.c:1646  */
    {

	}
#line 2908 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 872 "pascal.y" /* yacc.c:1646  */
    {
		(yyval.tree) = NULL;
	}
#line 2916 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 878 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), StatementNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 2925 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 885 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-2].tree);
		(yyval.tree)->insert(new TreeNode((yyvsp[-1].value)));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2935 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 890 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ExpressionNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2944 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 897 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2954 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 902 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2964 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 907 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2974 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 912 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2984 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 917 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 2994 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 922 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3004 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 927 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 3012 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 933 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3022 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 938 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3032 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 943 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3042 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 948 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3052 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 953 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 3060 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 959 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3070 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 964 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3080 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 969 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3090 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 974 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3100 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 979 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3110 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 984 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[-2].tree));
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3120 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 989 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 3128 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 995 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 3136 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 998 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-3].value), ProcedureNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 3147 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1004 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-3].value));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insertChild((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 3158 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1010 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[0].tree);
		(yyval.tree)->type = ProcedureNode;
    }
#line 3167 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1014 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-3].tree);
		(yyval.tree)->type = ProcedureNode;
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 3179 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1021 "pascal.y" /* yacc.c:1646  */
    {
		(yyval.tree) = (yyvsp[0].tree);
    }
#line 3187 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1024 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-1].tree);
    }
#line 3195 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1027 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3204 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1031 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), ExpressionNode);
		(yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3213 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1035 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-3].value));
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert((yyvsp[-1].tree));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 3224 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1041 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[-1].value), StatementNode);
        (yyval.tree)->insert(new TreeNode((yyvsp[-2].value)));
        (yyval.tree)->insert(new TreeNode((yyvsp[0].value)));
    }
#line 3234 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1049 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 3242 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1052 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 3250 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1055 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 3258 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1058 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 3266 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1061 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 3274 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1064 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 3282 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1067 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 3290 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1070 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode((yyvsp[0].value));
    }
#line 3298 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1076 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = (yyvsp[-2].tree);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3307 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1080 "pascal.y" /* yacc.c:1646  */
    {
        (yyval.tree) = new TreeNode(ExpressionNode);
        (yyval.tree)->insert((yyvsp[0].tree));
    }
#line 3316 "pascal_yacc.cpp" /* yacc.c:1646  */
    break;


#line 3320 "pascal_yacc.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1086 "pascal.y" /* yacc.c:1906  */


int main(){
        int result = yyparse();
		if (errorCount == 0){
	        //programTable->print(1);

	        Generate4 Gen;
	        Gen.VisitTree(programTable);
            //Gen.Print();
            new GS(Gen);
		}else{
			fprintf(stderr, "There still have %d error exist(s).\n", errorCount);
		}


        return result;
}

void yyerror(const char* s){
	fprintf(stderr, "ERROR at line %d : %s when parsing (%s)\n", yylineno, s, yytext);
	errorCount++;
}
