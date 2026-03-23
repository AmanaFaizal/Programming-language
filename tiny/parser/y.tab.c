/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "code.y"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <DLists.h>
#include <Tokenizer.h>
#include <Trees.h>

extern TREENODE *root;
typedef struct {
    DNODE mynode;
    TREENODE *nodeptr;
} T_NODE;


#line 87 "y.tab.c"

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

#line 225 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NEQ = 3,                        /* NEQ  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_FALSE = 5,                      /* FALSE  */
  YYSYMBOL_TO = 6,                         /* TO  */
  YYSYMBOL_VAR = 7,                        /* VAR  */
  YYSYMBOL_IDENTIFIER = 8,                 /* IDENTIFIER  */
  YYSYMBOL_POOL = 9,                       /* POOL  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_READ = 11,                      /* READ  */
  YYSYMBOL_REPEAT = 12,                    /* REPEAT  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_UNTIL = 14,                     /* UNTIL  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_THEN = 16,                      /* THEN  */
  YYSYMBOL_SWAP = 17,                      /* SWAP  */
  YYSYMBOL_OF = 18,                        /* OF  */
  YYSYMBOL_MOD = 19,                       /* MOD  */
  YYSYMBOL_CASE = 20,                      /* CASE  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_OUTPUT = 22,                    /* OUTPUT  */
  YYSYMBOL_EXIT = 23,                      /* EXIT  */
  YYSYMBOL_GTE = 24,                       /* GTE  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_DO = 26,                        /* DO  */
  YYSYMBOL_BEGINX = 27,                    /* BEGINX  */
  YYSYMBOL_BOOLEAN = 28,                   /* BOOLEAN  */
  YYSYMBOL_TRUE = 29,                      /* TRUE  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_INTEGER_NUM = 31,               /* INTEGER_NUM  */
  YYSYMBOL_INTEGER = 32,                   /* INTEGER  */
  YYSYMBOL_EOFX = 33,                      /* EOFX  */
  YYSYMBOL_POWER = 34,                     /* POWER  */
  YYSYMBOL_LTE = 35,                       /* LTE  */
  YYSYMBOL_LOOP = 36,                      /* LOOP  */
  YYSYMBOL_OR = 37,                        /* OR  */
  YYSYMBOL_ASSIGNMENT = 38,                /* ASSIGNMENT  */
  YYSYMBOL_PROGRAM = 39,                   /* PROGRAM  */
  YYSYMBOL_DOWNTO = 40,                    /* DOWNTO  */
  YYSYMBOL_41_ = 41,                       /* ':'  */
  YYSYMBOL_42_ = 42,                       /* '.'  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* '>'  */
  YYSYMBOL_49_ = 49,                       /* '='  */
  YYSYMBOL_50_ = 50,                       /* '+'  */
  YYSYMBOL_51_ = 51,                       /* '-'  */
  YYSYMBOL_52_ = 52,                       /* '*'  */
  YYSYMBOL_53_ = 53,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_Tiny = 55,                      /* Tiny  */
  YYSYMBOL_Dclns = 56,                     /* Dclns  */
  YYSYMBOL_DclnList = 57,                  /* DclnList  */
  YYSYMBOL_Dcln = 58,                      /* Dcln  */
  YYSYMBOL_NameList = 59,                  /* NameList  */
  YYSYMBOL_Name = 60,                      /* Name  */
  YYSYMBOL_Type = 61,                      /* Type  */
  YYSYMBOL_Body = 62,                      /* Body  */
  YYSYMBOL_StatementList = 63,             /* StatementList  */
  YYSYMBOL_CaseList = 64,                  /* CaseList  */
  YYSYMBOL_CaseItem = 65,                  /* CaseItem  */
  YYSYMBOL_ElsePart = 66,                  /* ElsePart  */
  YYSYMBOL_Statement = 67,                 /* Statement  */
  YYSYMBOL_ExprList = 68,                  /* ExprList  */
  YYSYMBOL_Expression = 69,                /* Expression  */
  YYSYMBOL_SimpleExpr = 70,                /* SimpleExpr  */
  YYSYMBOL_Term = 71,                      /* Term  */
  YYSYMBOL_Factor = 72,                    /* Factor  */
  YYSYMBOL_Primary = 73                    /* Primary  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,    52,    50,    44,    51,    42,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    43,
      47,    49,    48,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,   127,   164,   185,   197,   214,   242,   254,
     271,   306,   339,   374,   423,   435,   452,   467,   481,   506,
     530,   540,   579,   618,   654,   704,   768,   818,   896,   974,
    1024,  1088,  1135,  1168,  1181,  1202,  1214,  1231,  1243,  1282,
    1321,  1360,  1386,  1412,  1438,  1477,  1518,  1544,  1570,  1584,
    1610,  1636,  1675,  1689,  1728,  1742,  1765,  1788,  1824,  1857,
    1890,  1923,  1956,  1968,  2001,  2015
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NEQ", "END", "FALSE",
  "TO", "VAR", "IDENTIFIER", "POOL", "IF", "READ", "REPEAT", "ELSE",
  "UNTIL", "FOR", "THEN", "SWAP", "OF", "MOD", "CASE", "WHILE", "OUTPUT",
  "EXIT", "GTE", "NOT", "DO", "BEGINX", "BOOLEAN", "TRUE", "AND",
  "INTEGER_NUM", "INTEGER", "EOFX", "POWER", "LTE", "LOOP", "OR",
  "ASSIGNMENT", "PROGRAM", "DOWNTO", "':'", "'.'", "';'", "','", "'('",
  "')'", "'<'", "'>'", "'='", "'+'", "'-'", "'*'", "'/'", "$accept",
  "Tiny", "Dclns", "DclnList", "Dcln", "NameList", "Name", "Type", "Body",
  "StatementList", "CaseList", "CaseItem", "ElsePart", "Statement",
  "ExprList", "Expression", "SimpleExpr", "Term", "Factor", "Primary", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -25,    13,    27,   -53,   -10,   -53,    41,    13,    31,    13,
      32,    15,   -53,   101,    13,    33,   -53,    14,    13,    75,
     101,    13,    75,    75,    36,   -53,   101,   -14,   -53,     0,
     -53,    35,   -53,   -53,   -53,   -53,   -53,   -53,   -53,    75,
     -53,   -53,   -53,    75,    75,    75,   -53,    66,     2,   -12,
     -53,    51,     4,    49,    71,    62,    75,     1,    13,    75,
     -53,   101,   -53,   -53,    44,   -53,   -53,   101,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    60,   101,    19,   -53,   -53,   -53,
     -53,   -53,   -53,    79,    23,    23,    23,    23,    23,    23,
      23,    23,   -12,   -12,   -53,   -53,   -53,   -53,   -53,     5,
      53,     3,   -53,   -53,    75,   -53,   101,    75,    75,   101,
     101,   -53,    91,   -53,   -53,    72,    73,   -53,   -53,   -53,
     101,   101,   -53,   -53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    10,     0,     1,     4,     0,     0,     3,
       0,     0,     8,    34,     0,     0,     5,     0,     0,     0,
      34,     0,     0,     0,     0,    32,    34,     0,    33,     0,
      14,     0,     6,    12,    11,     7,     9,    61,    58,     0,
      60,    63,    59,     0,     0,     0,    62,     0,    37,    48,
      52,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    34,     2,    57,     0,    56,    55,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,    35,    31,    22,
      21,    15,    64,    24,    39,    40,    44,    38,    45,    41,
      42,    43,    46,    47,    51,    49,    50,    53,    29,     0,
       0,    20,    17,    26,     0,    23,    34,     0,     0,    34,
      34,    16,     0,    36,    25,     0,     0,    18,    19,    30,
      34,    34,    27,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,   -53,    92,   -53,    -1,   -53,    94,    10,
     -53,    -8,   -53,   -52,   -53,   -21,    70,   -22,    -9,   -16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,     9,    10,    11,    46,    35,    28,    29,
     111,   112,   122,    30,    86,    47,    48,    49,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       4,    54,    55,    58,    60,    68,    12,    78,    12,    91,
      88,   117,    27,    31,     1,    93,   120,    36,    82,    27,
      53,     3,    64,    63,    59,    27,    69,     5,    65,    66,
      52,     6,    70,   113,   110,    87,    57,    71,    90,    72,
      79,    80,    33,    61,    61,   118,    34,    61,     7,    73,
      74,    75,    76,    77,   102,   103,    17,    89,    13,    18,
      27,   108,   109,   114,   124,   115,    27,   127,   128,   104,
     105,   106,   107,    76,    77,    16,    32,    62,   132,   133,
      37,    56,    67,     3,    27,    81,    38,    83,    85,    84,
      92,   110,   116,   123,   119,   129,   125,   126,   130,   131,
      39,    15,    14,   121,    40,     0,    41,     0,    42,     3,
       0,    19,     0,    20,     0,    27,    21,     0,    27,    27,
      43,    22,    23,    24,    25,    44,    45,     0,    13,    27,
      27,     0,     0,     0,     0,     0,     0,    26,    94,    95,
      96,    97,    98,    99,   100,   101
};

static const yytype_int16 yycheck[] =
{
       1,    22,    23,    17,     4,     3,     7,    19,     9,    61,
       9,     6,    13,    14,    39,    67,    13,    18,    14,    20,
      21,     8,    43,    39,    38,    26,    24,     0,    44,    45,
      20,    41,    30,    85,    31,    56,    26,    35,    59,    37,
      52,    53,    28,    43,    43,    40,    32,    43,     7,    47,
      48,    49,    50,    51,    76,    77,    41,    58,    27,    44,
      61,    82,    83,    44,   116,    46,    67,   119,   120,    78,
      79,    80,    81,    50,    51,    43,    43,    42,   130,   131,
       5,    45,    16,     8,    85,    34,    11,    38,    26,    18,
      46,    31,    13,   114,    41,     4,   117,   118,    26,    26,
      25,     9,     8,   111,    29,    -1,    31,    -1,    33,     8,
      -1,    10,    -1,    12,    -1,   116,    15,    -1,   119,   120,
      45,    20,    21,    22,    23,    50,    51,    -1,    27,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    36,    68,    69,
      70,    71,    72,    73,    74,    75
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    55,     8,    60,     0,    41,     7,    56,    57,
      58,    59,    60,    27,    62,    58,    43,    41,    44,    10,
      12,    15,    20,    21,    22,    23,    36,    60,    62,    63,
      67,    60,    43,    28,    32,    61,    60,     5,    11,    25,
      29,    31,    33,    45,    50,    51,    60,    69,    70,    71,
      72,    73,    63,    60,    69,    69,    45,    63,    17,    38,
       4,    43,    42,    73,    69,    73,    73,    16,     3,    24,
      30,    35,    37,    47,    48,    49,    50,    51,    19,    52,
      53,    34,    14,    38,    18,    26,    68,    69,     9,    60,
      69,    67,    46,    67,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    69,    69,
      31,    64,    65,    67,    44,    46,    13,     6,    40,    41,
      13,    65,    66,    69,    67,    69,    69,    67,    67,     4,
      26,    26,    67,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      60,    61,    61,    62,    63,    63,    64,    64,    65,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    70,    70,    71,
      71,    71,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     0,     2,     3,     3,     1,     3,
       1,     1,     1,     3,     1,     3,     2,     1,     3,     2,
       0,     3,     3,     4,     4,     6,     4,     8,     8,     4,
       6,     3,     1,     1,     0,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Tiny: PROGRAM Name ':' Dclns Body Name '.'  */
#line 80 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-6].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-6].info).string,
		                                TREETAG_LINE,(yyvsp[-6].info).line,
		                                TREETAG_COLUMN,(yyvsp[-6].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-5].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-5].dlist)));

		while (DCount(&(yyvsp[-3].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-3].dlist)));

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"program",
		                                TREETAG_LINE,(yyvsp[-6].info).line,
		                                TREETAG_COLUMN,(yyvsp[-6].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		t->mynode = *(DHead(&r));
		root = t->nodeptr;

             }
#line 1406 "y.tab.c"
    break;

  case 3: /* Dclns: VAR DclnList  */
#line 128 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"dclns",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1446 "y.tab.c"
    break;

  case 4: /* Dclns: %empty  */
#line 164 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"dclns",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1470 "y.tab.c"
    break;

  case 5: /* DclnList: Dcln ';'  */
#line 186 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		(yyval.dlist) = r;

             }
#line 1486 "y.tab.c"
    break;

  case 6: /* DclnList: DclnList Dcln ';'  */
#line 198 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		(yyval.dlist) = r;

             }
#line 1505 "y.tab.c"
    break;

  case 7: /* Dcln: NameList ':' Type  */
#line 215 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"dcln",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1535 "y.tab.c"
    break;

  case 8: /* NameList: Name  */
#line 243 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1551 "y.tab.c"
    break;

  case 9: /* NameList: NameList ',' Name  */
#line 255 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1570 "y.tab.c"
    break;

  case 10: /* Name: IDENTIFIER  */
#line 272 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<identifier>",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1607 "y.tab.c"
    break;

  case 11: /* Type: INTEGER  */
#line 307 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"integer",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1644 "y.tab.c"
    break;

  case 12: /* Type: BOOLEAN  */
#line 340 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"boolean",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1681 "y.tab.c"
    break;

  case 13: /* Body: BEGINX StatementList END  */
#line 375 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-2].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-2].info).string,
		                                TREETAG_LINE,(yyvsp[-2].info).line,
		                                TREETAG_COLUMN,(yyvsp[-2].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"block",
		                                TREETAG_LINE,(yyvsp[-2].info).line,
		                                TREETAG_COLUMN,(yyvsp[-2].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1732 "y.tab.c"
    break;

  case 14: /* StatementList: Statement  */
#line 424 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1748 "y.tab.c"
    break;

  case 15: /* StatementList: StatementList ';' Statement  */
#line 436 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1767 "y.tab.c"
    break;

  case 16: /* CaseList: CaseList CaseItem  */
#line 453 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1786 "y.tab.c"
    break;

  case 17: /* CaseList: CaseItem  */
#line 468 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1802 "y.tab.c"
    break;

  case 18: /* CaseItem: INTEGER_NUM ':' Statement  */
#line 482 "code.y"
             {
		DLIST r;

		InitDList(&r);

		if ((yyvsp[-2].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-2].info).string,
		                                TREETAG_LINE,(yyvsp[-2].info).line,
		                                TREETAG_COLUMN,(yyvsp[-2].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1829 "y.tab.c"
    break;

  case 19: /* ElsePart: ELSE Statement  */
#line 507 "code.y"
             {
		DLIST r;

		InitDList(&r);

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1856 "y.tab.c"
    break;

  case 20: /* ElsePart: %empty  */
#line 530 "code.y"
             {
		DLIST r;

		InitDList(&r);

		(yyval.dlist) = r;

             }
#line 1869 "y.tab.c"
    break;

  case 21: /* Statement: Name ASSIGNMENT Expression  */
#line 541 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"assign",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1912 "y.tab.c"
    break;

  case 22: /* Statement: Name SWAP Name  */
#line 580 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"swap",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1955 "y.tab.c"
    break;

  case 23: /* Statement: OUTPUT '(' ExprList ')'  */
#line 619 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"output",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1995 "y.tab.c"
    break;

  case 24: /* Statement: IF Expression THEN Statement  */
#line 655 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"if",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2049 "y.tab.c"
    break;

  case 25: /* Statement: IF Expression THEN Statement ELSE Statement  */
#line 705 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-5].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-5].info).string,
		                                TREETAG_LINE,(yyvsp[-5].info).line,
		                                TREETAG_COLUMN,(yyvsp[-5].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-4].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-4].dlist)));

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"if",
		                                TREETAG_LINE,(yyvsp[-5].info).line,
		                                TREETAG_COLUMN,(yyvsp[-5].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2117 "y.tab.c"
    break;

  case 26: /* Statement: WHILE Expression DO Statement  */
#line 769 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"while",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2171 "y.tab.c"
    break;

  case 27: /* Statement: FOR Name ASSIGNMENT Expression TO Expression DO Statement  */
#line 819 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-7].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-7].info).string,
		                                TREETAG_LINE,(yyvsp[-7].info).line,
		                                TREETAG_COLUMN,(yyvsp[-7].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-6].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-6].dlist)));

		if ((yyvsp[-5].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-5].info).string,
		                                TREETAG_LINE,(yyvsp[-5].info).line,
		                                TREETAG_COLUMN,(yyvsp[-5].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-4].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-4].dlist)));

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"for_to",
		                                TREETAG_LINE,(yyvsp[-7].info).line,
		                                TREETAG_COLUMN,(yyvsp[-7].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2253 "y.tab.c"
    break;

  case 28: /* Statement: FOR Name ASSIGNMENT Expression DOWNTO Expression DO Statement  */
#line 897 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-7].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-7].info).string,
		                                TREETAG_LINE,(yyvsp[-7].info).line,
		                                TREETAG_COLUMN,(yyvsp[-7].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-6].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-6].dlist)));

		if ((yyvsp[-5].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-5].info).string,
		                                TREETAG_LINE,(yyvsp[-5].info).line,
		                                TREETAG_COLUMN,(yyvsp[-5].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-4].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-4].dlist)));

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"for_downto",
		                                TREETAG_LINE,(yyvsp[-7].info).line,
		                                TREETAG_COLUMN,(yyvsp[-7].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2335 "y.tab.c"
    break;

  case 29: /* Statement: REPEAT StatementList UNTIL Expression  */
#line 975 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"repeat",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2389 "y.tab.c"
    break;

  case 30: /* Statement: CASE Expression OF CaseList ElsePart END  */
#line 1025 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-5].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-5].info).string,
		                                TREETAG_LINE,(yyvsp[-5].info).line,
		                                TREETAG_COLUMN,(yyvsp[-5].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-4].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-4].dlist)));

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"case",
		                                TREETAG_LINE,(yyvsp[-5].info).line,
		                                TREETAG_COLUMN,(yyvsp[-5].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2457 "y.tab.c"
    break;

  case 31: /* Statement: LOOP StatementList POOL  */
#line 1089 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-2].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-2].info).string,
		                                TREETAG_LINE,(yyvsp[-2].info).line,
		                                TREETAG_COLUMN,(yyvsp[-2].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"loop",
		                                TREETAG_LINE,(yyvsp[-2].info).line,
		                                TREETAG_COLUMN,(yyvsp[-2].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2508 "y.tab.c"
    break;

  case 32: /* Statement: EXIT  */
#line 1136 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"exit",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2545 "y.tab.c"
    break;

  case 33: /* Statement: Body  */
#line 1169 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 2561 "y.tab.c"
    break;

  case 34: /* Statement: %empty  */
#line 1181 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<null>",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2585 "y.tab.c"
    break;

  case 35: /* ExprList: Expression  */
#line 1203 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 2601 "y.tab.c"
    break;

  case 36: /* ExprList: ExprList ',' Expression  */
#line 1215 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 2620 "y.tab.c"
    break;

  case 37: /* Expression: SimpleExpr  */
#line 1232 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 2636 "y.tab.c"
    break;

  case 38: /* Expression: SimpleExpr LTE SimpleExpr  */
#line 1244 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<=",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2679 "y.tab.c"
    break;

  case 39: /* Expression: SimpleExpr NEQ SimpleExpr  */
#line 1283 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<>",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2722 "y.tab.c"
    break;

  case 40: /* Expression: SimpleExpr GTE SimpleExpr  */
#line 1322 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,">=",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2765 "y.tab.c"
    break;

  case 41: /* Expression: SimpleExpr '<' SimpleExpr  */
#line 1361 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2795 "y.tab.c"
    break;

  case 42: /* Expression: SimpleExpr '>' SimpleExpr  */
#line 1387 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,">",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2825 "y.tab.c"
    break;

  case 43: /* Expression: SimpleExpr '=' SimpleExpr  */
#line 1413 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"=",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2855 "y.tab.c"
    break;

  case 44: /* Expression: SimpleExpr AND SimpleExpr  */
#line 1439 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"and",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2898 "y.tab.c"
    break;

  case 45: /* Expression: SimpleExpr OR SimpleExpr  */
#line 1478 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"or",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2941 "y.tab.c"
    break;

  case 46: /* SimpleExpr: SimpleExpr '+' Term  */
#line 1519 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"+",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2971 "y.tab.c"
    break;

  case 47: /* SimpleExpr: SimpleExpr '-' Term  */
#line 1545 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"-",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3001 "y.tab.c"
    break;

  case 48: /* SimpleExpr: Term  */
#line 1571 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3017 "y.tab.c"
    break;

  case 49: /* Term: Term '*' Factor  */
#line 1585 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"*",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3047 "y.tab.c"
    break;

  case 50: /* Term: Term '/' Factor  */
#line 1611 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"/",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3077 "y.tab.c"
    break;

  case 51: /* Term: Term MOD Factor  */
#line 1637 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"mod",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3120 "y.tab.c"
    break;

  case 52: /* Term: Factor  */
#line 1676 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3136 "y.tab.c"
    break;

  case 53: /* Factor: Primary POWER Factor  */
#line 1690 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"**",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3179 "y.tab.c"
    break;

  case 54: /* Factor: Primary  */
#line 1729 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3195 "y.tab.c"
    break;

  case 55: /* Primary: '-' Primary  */
#line 1743 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"-",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3222 "y.tab.c"
    break;

  case 56: /* Primary: '+' Primary  */
#line 1766 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"+",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3249 "y.tab.c"
    break;

  case 57: /* Primary: NOT Primary  */
#line 1789 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"not",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3289 "y.tab.c"
    break;

  case 58: /* Primary: READ  */
#line 1825 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"read",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3326 "y.tab.c"
    break;

  case 59: /* Primary: EOFX  */
#line 1858 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"eof",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3363 "y.tab.c"
    break;

  case 60: /* Primary: TRUE  */
#line 1891 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"true",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3400 "y.tab.c"
    break;

  case 61: /* Primary: FALSE  */
#line 1924 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"false",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3437 "y.tab.c"
    break;

  case 62: /* Primary: Name  */
#line 1957 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3453 "y.tab.c"
    break;

  case 63: /* Primary: INTEGER_NUM  */
#line 1969 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<integer>",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3490 "y.tab.c"
    break;

  case 64: /* Primary: '(' Expression ')'  */
#line 2002 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		(yyval.dlist) = r;

             }
#line 3506 "y.tab.c"
    break;

  case 65: /* Name: IDENTIFIER  */
#line 2016 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<identifier>",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3543 "y.tab.c"
    break;


#line 3547 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

