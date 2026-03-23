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
    TO = 261,                      /* TO  */
    VAR = 262,                     /* VAR  */
    IDENTIFIER = 263,              /* IDENTIFIER  */
    POOL = 264,                    /* POOL  */
    IF = 265,                      /* IF  */
    READ = 266,                    /* READ  */
    REPEAT = 267,                  /* REPEAT  */
    ELSE = 268,                    /* ELSE  */
    UNTIL = 269,                   /* UNTIL  */
    FOR = 270,                     /* FOR  */
    THEN = 271,                    /* THEN  */
    SWAP = 272,                    /* SWAP  */
    OF = 273,                      /* OF  */
    MOD = 274,                     /* MOD  */
    CASE = 275,                    /* CASE  */
    WHILE = 276,                   /* WHILE  */
    OUTPUT = 277,                  /* OUTPUT  */
    EXIT = 278,                    /* EXIT  */
    GTE = 279,                     /* GTE  */
    NOT = 280,                     /* NOT  */
    DO = 281,                      /* DO  */
    BEGINX = 282,                  /* BEGINX  */
    BOOLEAN = 283,                 /* BOOLEAN  */
    TRUE = 284,                    /* TRUE  */
    AND = 285,                     /* AND  */
    INTEGER_NUM = 286,             /* INTEGER_NUM  */
    INTEGER = 287,                 /* INTEGER  */
    EOFX = 288,                    /* EOFX  */
    POWER = 289,                   /* POWER  */
    LTE = 290,                     /* LTE  */
    LOOP = 291,                    /* LOOP  */
    OR = 292,                      /* OR  */
    ASSIGNMENT = 293,              /* ASSIGNMENT  */
    PROGRAM = 294,                 /* PROGRAM  */
    DOWNTO = 295                   /* DOWNTO  */
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
#define TO 261
#define VAR 262
#define IDENTIFIER 263
#define POOL 264
#define IF 265
#define READ 266
#define REPEAT 267
#define ELSE 268
#define UNTIL 269
#define FOR 270
#define THEN 271
#define SWAP 272
#define OF 273
#define MOD 274
#define CASE 275
#define WHILE 276
#define OUTPUT 277
#define EXIT 278
#define GTE 279
#define NOT 280
#define DO 281
#define BEGINX 282
#define BOOLEAN 283
#define TRUE 284
#define AND 285
#define INTEGER_NUM 286
#define INTEGER 287
#define EOFX 288
#define POWER 289
#define LTE 290
#define LOOP 291
#define OR 292
#define ASSIGNMENT 293
#define PROGRAM 294
#define DOWNTO 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "code.y"

   TOKEN_INFO info;
   DLIST dlist;

#line 152 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
