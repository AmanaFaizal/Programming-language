/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NEQ = 258,                     /* NEQ  */
    END = 259,                     /* END  */
    FALSE = 260,                   /* FALSE  */
    VAR = 261,                     /* VAR  */
    IDENTIFIER = 262,              /* IDENTIFIER  */
    IF = 263,                      /* IF  */
    READ = 264,                    /* READ  */
    ELSE = 265,                    /* ELSE  */
    THEN = 266,                    /* THEN  */
    MOD = 267,                     /* MOD  */
    WHILE = 268,                   /* WHILE  */
    OUTPUT = 269,                  /* OUTPUT  */
    GTE = 270,                     /* GTE  */
    NOT = 271,                     /* NOT  */
    DO = 272,                      /* DO  */
    BEGINX = 273,                  /* BEGINX  */
    BOOLEAN = 274,                 /* BOOLEAN  */
    INTEGER_NUM = 275,             /* INTEGER_NUM  */
    TRUE = 276,                    /* TRUE  */
    AND = 277,                     /* AND  */
    INTEGER = 278,                 /* INTEGER  */
    EOFX = 279,                    /* EOFX  */
    POWER = 280,                   /* POWER  */
    LTE = 281,                     /* LTE  */
    OR = 282,                      /* OR  */
    ASSIGNMENT = 283,              /* ASSIGNMENT  */
    PROGRAM = 284                  /* PROGRAM  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NEQ 258
#define END 259
#define FALSE 260
#define VAR 261
#define IDENTIFIER 262
#define IF 263
#define READ 264
#define ELSE 265
#define THEN 266
#define MOD 267
#define WHILE 268
#define OUTPUT 269
#define GTE 270
#define NOT 271
#define DO 272
#define BEGINX 273
#define BOOLEAN 274
#define INTEGER_NUM 275
#define TRUE 276
#define AND 277
#define INTEGER 278
#define EOFX 279
#define POWER 280
#define LTE 281
#define OR 282
#define ASSIGNMENT 283
#define PROGRAM 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "code.y"

   TOKEN_INFO info;
   DLIST dlist;

#line 130 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
