/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 19 "pascal.y" /* yacc.c:1909  */

	ValueNode* value;
    TreeNode* tree;

#line 213 "pascal_yacc.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PASCAL_YACC_HPP_INCLUDED  */
