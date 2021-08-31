/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "./src/syntax.y"

/* C declarations */
#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "symbol_table.h"

extern int yylex();
extern int yylex_destroy();
extern int yyparse();
extern void yyerror(const char* s);
extern FILE* yyin;

//yynerrs //global variable counting errors


#line 88 "./src/syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_TYPE = 6,                       /* TYPE  */
  YYSYMBOL_LIST_TYPE = 7,                  /* LIST_TYPE  */
  YYSYMBOL_STRING = 8,                     /* STRING  */
  YYSYMBOL_NULL_CONST = 9,                 /* NULL_CONST  */
  YYSYMBOL_PLUS_OP = 10,                   /* PLUS_OP  */
  YYSYMBOL_MINUS_OP = 11,                  /* MINUS_OP  */
  YYSYMBOL_DIV_OP = 12,                    /* DIV_OP  */
  YYSYMBOL_MUL_OP = 13,                    /* MUL_OP  */
  YYSYMBOL_LOGIC_OP = 14,                  /* LOGIC_OP  */
  YYSYMBOL_BINARY_OP = 15,                 /* BINARY_OP  */
  YYSYMBOL_ASSIGN_OP = 16,                 /* ASSIGN_OP  */
  YYSYMBOL_EXCLA_OP = 17,                  /* EXCLA_OP  */
  YYSYMBOL_IF_KEY = 18,                    /* IF_KEY  */
  YYSYMBOL_ELSE_KEY = 19,                  /* ELSE_KEY  */
  YYSYMBOL_FOR_KEY = 20,                   /* FOR_KEY  */
  YYSYMBOL_RETURN_KEY = 21,                /* RETURN_KEY  */
  YYSYMBOL_INPUT_KEY = 22,                 /* INPUT_KEY  */
  YYSYMBOL_OUTPUT_KEY = 23,                /* OUTPUT_KEY  */
  YYSYMBOL_OUTPUTLN_KEY = 24,              /* OUTPUTLN_KEY  */
  YYSYMBOL_ASSIGN_LISTOP = 25,             /* ASSIGN_LISTOP  */
  YYSYMBOL_HEADER_LISTOP = 26,             /* HEADER_LISTOP  */
  YYSYMBOL_TAILDES_LISTOP = 27,            /* TAILDES_LISTOP  */
  YYSYMBOL_MAP_LISTOP = 28,                /* MAP_LISTOP  */
  YYSYMBOL_FILTER_LISTOP = 29,             /* FILTER_LISTOP  */
  YYSYMBOL_DELIM_PARENT_L = 30,            /* DELIM_PARENT_L  */
  YYSYMBOL_DELIM_PARENT_R = 31,            /* DELIM_PARENT_R  */
  YYSYMBOL_DELIM_BRACKET_L = 32,           /* DELIM_BRACKET_L  */
  YYSYMBOL_DELIM_BRACKET_R = 33,           /* DELIM_BRACKET_R  */
  YYSYMBOL_DELIM_CUR_BRACKET_L = 34,       /* DELIM_CUR_BRACKET_L  */
  YYSYMBOL_DELIM_CUR_BRACKET_R = 35,       /* DELIM_CUR_BRACKET_R  */
  YYSYMBOL_DELIM_COMMA = 36,               /* DELIM_COMMA  */
  YYSYMBOL_DELIM_SEMICOLLON = 37,          /* DELIM_SEMICOLLON  */
  YYSYMBOL_DELIM_SQUOTE = 38,              /* DELIM_SQUOTE  */
  YYSYMBOL_DELIM_DQUOTE = 39,              /* DELIM_DQUOTE  */
  YYSYMBOL_SINGLE_COMMENT = 40,            /* SINGLE_COMMENT  */
  YYSYMBOL_MULTI_COMMENT = 41,             /* MULTI_COMMENT  */
  YYSYMBOL_FORMAT_BLANKSPACE = 42,         /* FORMAT_BLANKSPACE  */
  YYSYMBOL_FORMAT_NEWLINE = 43,            /* FORMAT_NEWLINE  */
  YYSYMBOL_FORMAT_TAB = 44,                /* FORMAT_TAB  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_declarationList = 47,           /* declarationList  */
  YYSYMBOL_declaration = 48,               /* declaration  */
  YYSYMBOL_varDeclaration = 49,            /* varDeclaration  */
  YYSYMBOL_funcDeclaration = 50,           /* funcDeclaration  */
  YYSYMBOL_parameters = 51,                /* parameters  */
  YYSYMBOL_parameterList = 52,             /* parameterList  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_bodyStatement = 54,             /* bodyStatement  */
  YYSYMBOL_localDeclaration = 55,          /* localDeclaration  */
  YYSYMBOL_statementList = 56,             /* statementList  */
  YYSYMBOL_ifStatement = 57,               /* ifStatement  */
  YYSYMBOL_loopStatement = 58,             /* loopStatement  */
  YYSYMBOL_returnStatement = 59,           /* returnStatement  */
  YYSYMBOL_expression = 60,                /* expression  */
  YYSYMBOL_simpleExpression = 61,          /* simpleExpression  */
  YYSYMBOL_logicBinExpression = 62,        /* logicBinExpression  */
  YYSYMBOL_logicUnExpression = 63,         /* logicUnExpression  */
  YYSYMBOL_binExpression = 64,             /* binExpression  */
  YYSYMBOL_sumExpression = 65,             /* sumExpression  */
  YYSYMBOL_mulExpression = 66,             /* mulExpression  */
  YYSYMBOL_sumOP = 67,                     /* sumOP  */
  YYSYMBOL_mulOP = 68,                     /* mulOP  */
  YYSYMBOL_factor = 69,                    /* factor  */
  YYSYMBOL_constant = 70,                  /* constant  */
  YYSYMBOL_functionCall = 71,              /* functionCall  */
  YYSYMBOL_parametersPass = 72,            /* parametersPass  */
  YYSYMBOL_writeOp = 73,                   /* writeOp  */
  YYSYMBOL_write = 74,                     /* write  */
  YYSYMBOL_writeln = 75,                   /* writeln  */
  YYSYMBOL_readOp = 76,                    /* readOp  */
  YYSYMBOL_expressionStatement = 77,       /* expressionStatement  */
  YYSYMBOL_listStatement = 78,             /* listStatement  */
  YYSYMBOL_listExpression = 79,            /* listExpression  */
  YYSYMBOL_listAssign = 80,                /* listAssign  */
  YYSYMBOL_listHeader = 81,                /* listHeader  */
  YYSYMBOL_listTailDestructor = 82,        /* listTailDestructor  */
  YYSYMBOL_listMap = 83,                   /* listMap  */
  YYSYMBOL_listFilter = 84                 /* listFilter  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1711

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  264

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   168,   168,   172,   173,   177,   178,   182,   185,   203,
     207,   208,   212,   213,   214,   215,   219,   220,   221,   222,
     223,   224,   225,   226,   230,   234,   235,   239,   240,   244,
     245,   249,   253,   257,   258,   267,   276,   277,   281,   282,
     290,   291,   295,   296,   300,   301,   305,   306,   310,   311,
     315,   316,   317,   318,   319,   323,   324,   328,   332,   333,
     334,   338,   339,   343,   344,   348,   349,   353,   357,   361,
     362,   363,   367,   369,   373,   377,   385,   389,   393
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "ID",
  "TYPE", "LIST_TYPE", "STRING", "NULL_CONST", "PLUS_OP", "MINUS_OP",
  "DIV_OP", "MUL_OP", "LOGIC_OP", "BINARY_OP", "ASSIGN_OP", "EXCLA_OP",
  "IF_KEY", "ELSE_KEY", "FOR_KEY", "RETURN_KEY", "INPUT_KEY", "OUTPUT_KEY",
  "OUTPUTLN_KEY", "ASSIGN_LISTOP", "HEADER_LISTOP", "TAILDES_LISTOP",
  "MAP_LISTOP", "FILTER_LISTOP", "DELIM_PARENT_L", "DELIM_PARENT_R",
  "DELIM_BRACKET_L", "DELIM_BRACKET_R", "DELIM_CUR_BRACKET_L",
  "DELIM_CUR_BRACKET_R", "DELIM_COMMA", "DELIM_SEMICOLLON", "DELIM_SQUOTE",
  "DELIM_DQUOTE", "SINGLE_COMMENT", "MULTI_COMMENT", "FORMAT_BLANKSPACE",
  "FORMAT_NEWLINE", "FORMAT_TAB", "$accept", "program", "declarationList",
  "declaration", "varDeclaration", "funcDeclaration", "parameters",
  "parameterList", "statement", "bodyStatement", "localDeclaration",
  "statementList", "ifStatement", "loopStatement", "returnStatement",
  "expression", "simpleExpression", "logicBinExpression",
  "logicUnExpression", "binExpression", "sumExpression", "mulExpression",
  "sumOP", "mulOP", "factor", "constant", "functionCall", "parametersPass",
  "writeOp", "write", "writeln", "readOp", "expressionStatement",
  "listStatement", "listExpression", "listAssign", "listHeader",
  "listTailDestructor", "listMap", "listFilter", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
#endif

#define YYPACT_NINF (-181)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-79)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   270,    11,    21,    89,    94,   168,    19,    55,  -181,
     224,    31,   237,   -11,   298,    30,   136,   252,   146,    86,
     336,    95,   191,   256,   284,    20,   229,    80,   131,   246,
     145,   159,   163,   119,   196,   305,   733,   278,   301,   311,
     314,   328,   165,   176,    -9,    59,    40,     8,   457,   498,
     582,   625,   188,   192,   202,   203,   330,   210,   732,   227,
     770,   799,   228,   249,   299,   403,    12,    93,    61,   305,
     246,    53,   286,   282,   132,   161,   905,   933,   230,   798,
     342,   229,   474,   541,   701,   474,  1113,  1141,   474,   349,
     361,   368,   333,   322,   761,   300,   373,   383,   307,   313,
     246,   372,   334,   357,   359,   371,   400,   961,   308,   837,
     990,   310,    72,   169,   989,  1017,   390,   394,   398,   434,
    1045,   408,   339,   229,   406,   421,   423,   424,   436,   437,
     405,   381,   448,   449,   450,   401,   141,   451,   425,  1085,
     417,   464,   425,   422,  1268,  1296,  1240,   305,   492,   494,
     305,    27,   101,    -6,   185,  1324,  1550,  1572,  1578,  1584,
    1606,  1612,  1355,  1382,   838,   408,   497,   500,   305,    56,
      83,    98,   365,  1388,  1394,  1421,  1427,  1433,  1460,  1466,
     476,   487,   246,   733,  1018,  1046,  1074,  1102,   484,   486,
     489,  1130,   490,   519,   733,   873,   871,   502,    12,   125,
    1618,  1640,   508,   305,  1169,  1169,  1169,    12,   102,  1472,
    1499,   511,   408,  1197,  1197,  1197,   305,   246,   491,   798,
    1158,  1186,  1214,  1242,   510,   798,  1085,   415,  1646,   140,
     545,  1652,  1674,   416,  1505,   117,   505,  1511,  1538,   520,
     513,  1270,   496,   906,   518,   523,  1680,  1544,   528,   229,
    1298,   186,   733,   934,   526,   798,   532,  1085,   537,  1326,
     543,   962,   532,  1354
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,  -181,   572,   257,  -181,  -181,  -181,   557,   -20,
    -180,   -98,   563,   565,   566,   -19,   580,   649,   -22,   495,
     483,   463,  -152,  -149,     5,    76,   179,  -122,   578,  -181,
    -181,   579,   583,   585,   250,  -181,   277,   375,  -181,  -181
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,   109,     6,    15,    16,   110,   184,
      79,   111,   185,   186,   187,   188,    43,    44,    45,    46,
      47,    48,    85,    88,    49,    50,    51,    97,   189,    53,
      54,   190,   191,   192,    58,    59,    60,    61,    62,    63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    42,   205,   219,    68,    81,   206,     1,   -39,   204,
      72,     9,   130,   152,   225,   162,   163,   164,    83,    84,
     214,    -2,   -41,   -41,   215,   -39,    17,     1,   -35,   165,
     -50,   -50,   -50,   -50,   -50,   -50,    65,    14,   166,   167,
     156,   203,   168,   -60,   170,   -41,    95,   152,   -60,    11,
      66,    99,   152,   152,   -39,    82,    12,   -50,   -35,   112,
      13,    20,   -11,   -50,   -50,   -50,   -50,   -50,   -50,   100,
     212,   174,   255,   -37,   156,   -38,   227,   -39,   205,   156,
     156,    95,   206,    66,   214,   233,   -36,   -35,   215,    -4,
     -50,    22,   -35,   115,    -5,    -4,   -37,   -37,   -38,   170,
      -5,    64,   136,   -50,   -50,   -50,   -50,   -50,   -50,   -36,
      69,   157,   -39,   213,   -37,   -37,   -38,   152,   140,   -37,
     141,   242,   143,    66,    76,   199,   174,   244,   152,   -39,
     -50,   -36,   -37,   -38,   -39,   144,   145,   146,   -38,   -38,
     103,   -29,   175,   208,   156,   157,   152,   -29,   -36,   147,
     157,   157,   156,   -36,   -36,   156,   -38,   258,   148,   149,
     138,    70,   150,   218,   144,   145,   146,   -10,    -6,   105,
     174,   -36,    21,   156,    -6,    73,   170,   -14,   147,    83,
      84,   229,   -14,   -40,   -40,   170,   -24,   148,   149,    74,
     235,   150,   -24,    75,   152,    83,    84,   175,   240,   -41,
     -41,    77,    80,   174,   152,   -24,   -40,   245,   156,   156,
     156,   232,   174,   -34,   158,   157,   -41,   174,   174,   174,
     238,   156,   -15,   157,    -3,    89,   157,   -15,   253,   -61,
      -3,   156,    23,    24,    67,   152,   259,    -7,   260,   -62,
      90,   175,   263,    -7,   157,   176,    26,    91,   158,    23,
      24,    71,    -8,   158,   158,    33,    34,     5,    -8,    35,
       5,   107,   156,    26,   -69,   -70,   -55,   -55,   -55,   -55,
     -55,   -55,    33,    34,   175,     7,    35,     8,    -9,   157,
     157,   157,   157,   175,    -9,   159,   -71,   102,   175,   175,
     175,   175,   157,   -55,   -56,   -56,   -56,   -56,   -56,   -56,
     176,   -16,   157,    18,    92,    19,    93,   -16,   144,   145,
     146,   -17,   160,   129,   -18,   193,   177,   -17,   158,   159,
     -18,   -56,   147,   101,   159,   159,   158,   116,   -19,   158,
     -23,   148,   149,   157,   -19,   150,   -23,   -33,   122,    23,
      24,    25,   -68,   178,   176,   131,   160,   158,   -68,   -21,
     123,   160,   160,    26,    27,   -21,    28,    29,    30,    31,
      32,   -22,    33,    34,   -12,   124,    35,   -22,   -20,   -12,
      36,   177,   -32,   194,   -20,    83,    84,   176,   -32,   -41,
     -41,   -24,   158,   158,   158,   158,   176,   -24,   125,   159,
     126,   176,   176,   176,   176,   158,   -41,   159,   178,   132,
     159,   -41,   127,   133,   -59,   158,    23,    24,    94,   -59,
     161,   162,   163,   164,   120,   177,   160,   -30,   159,   121,
      26,   -13,   -31,   -30,   160,   165,   -13,   160,   -31,    33,
      34,   128,   -58,    35,   166,   167,   158,   -58,   168,   134,
     -27,   179,   178,   -67,   161,   160,   246,   247,   177,   161,
     161,   121,   121,   159,   159,   159,   159,   177,   -63,    36,
     -64,   -65,   177,   177,   177,   177,   159,   -43,   -43,    86,
      87,   -43,   -43,   -66,   195,   178,   159,    23,    24,    67,
     160,   160,   160,   160,   178,   -74,   -77,   -78,   139,   178,
     178,   178,   178,   160,   -43,   142,   179,   200,   155,   201,
      33,    34,   209,   160,    35,   210,   216,   159,   -45,   -45,
     -45,   -45,   -45,   -45,   161,    83,    84,   217,   154,   -40,
     -40,   220,   161,   221,   224,   161,   222,   223,   241,   173,
     153,   250,   155,   -34,   160,   -45,   -40,   155,   155,   228,
     179,   -40,   234,   161,   -46,   -46,   -46,   243,   114,   172,
     249,   248,   154,   251,   -33,    83,    84,   154,   154,   -40,
     -40,   171,   252,   257,   153,   113,   183,   -46,   -46,   153,
     153,   -46,   261,   179,   262,    10,   -40,    37,   161,   161,
     161,   161,   179,    39,   173,    40,    41,   179,   179,   179,
     179,   161,   -51,   -51,   -51,   -51,   -51,   -51,    52,    55,
       0,   161,   155,    56,   172,    57,     0,     0,     0,     0,
     155,     0,     0,   155,     0,    78,   171,     0,     0,   -51,
       0,     0,   154,     0,     0,     0,     0,     0,   173,     0,
     154,   155,   161,   154,   153,   -53,   -53,   -53,   -53,   -53,
     -53,     0,   153,     0,     0,   153,    96,     0,   172,    98,
       0,   154,     0,     0,   104,   106,     0,     0,     0,     0,
     171,   173,   -53,   153,     0,     0,   155,   155,   231,     0,
     173,     0,     0,     0,     0,   173,   173,   237,     0,   155,
       0,   172,     0,     0,   151,     0,   154,   230,     0,   155,
     172,     0,     0,   171,     0,   172,   236,     0,   153,   154,
       0,   135,   171,   137,   -47,   -47,   -47,   171,     0,   154,
       0,   153,     0,     0,     0,   169,     0,     0,   151,   197,
     155,   153,     0,   151,   151,     0,     0,   -47,   -47,     0,
     202,   -47,     0,     0,     0,     0,   -26,   -26,   -26,   -26,
     154,     0,   -54,   -54,   -54,   -54,   -54,   -54,   211,     0,
     -26,   -26,   153,   -26,   -26,   -26,   -26,   -26,     0,   -26,
     -26,     0,     0,   -26,     0,     0,     0,   -26,   -26,   -54,
     169,   -50,   -50,   -50,   -50,   -50,   -50,   100,    96,     0,
     -72,   -72,   -72,   -72,   -72,   -72,   117,    96,   151,   118,
     119,    66,     0,     0,     0,     0,   239,     0,   -50,   151,
       0,    23,    24,    25,   108,     0,   197,   -72,     0,   -73,
     -73,   -73,   -73,   -73,   -73,    26,   180,   151,   181,   182,
      30,    31,    32,     0,    33,    34,     0,     0,    35,   254,
       0,     0,   183,   -28,     0,     0,   -73,   197,     0,     0,
     -25,   -25,   -25,   -25,     0,     0,     0,   169,   -50,   -50,
     -50,   -50,   -50,   -50,   -25,   -25,   169,   -25,   -25,   -25,
     -25,   -25,     0,   -25,   -25,   151,     0,   -25,   207,   -50,
       0,   -25,   -25,     0,   -50,   151,    -7,    -7,    -7,    -7,
       0,   -50,   -50,   -50,   -50,   -50,   -50,   226,     0,     0,
      -7,    -7,     0,    -7,    -7,    -7,    -7,    -7,     0,    -7,
      -7,   198,   -50,    -7,     0,     0,   151,    -7,    -7,    -8,
      -8,    -8,    -8,     0,     0,   -75,   -75,   -75,   -75,   -75,
     -75,     0,     0,    -8,    -8,     0,    -8,    -8,    -8,    -8,
      -8,     0,    -8,    -8,     0,     0,    -8,   -29,   -29,   -29,
      -8,    -8,   -75,   -76,   -76,   -76,   -76,   -76,   -76,     0,
       0,   -29,   -29,   256,   -29,   -29,   -29,   -29,   -29,     0,
     -29,   -29,     0,     0,   -29,   -24,   -24,   -24,   -29,   -29,
     -76,   -52,   -52,   -52,   -52,   -52,   -52,     0,     0,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,   -24,
       0,     0,   -24,    23,    24,    25,   -24,   -24,   -52,   -42,
     -42,    86,    87,   -42,   -42,     0,     0,    26,   180,     0,
     181,   182,    30,    31,    32,     0,    33,    34,     0,     0,
      35,   -16,   -16,   -16,   183,   -28,   -42,   -44,   -44,   -44,
     -44,   -44,   -44,     0,     0,   -16,   -16,     0,   -16,   -16,
     -16,   -16,   -16,     0,   -16,   -16,     0,     0,   -16,   -17,
     -17,   -17,   -16,   -16,   -44,   -57,   -57,   -57,   -57,   -57,
     -57,     0,     0,   -17,   -17,     0,   -17,   -17,   -17,   -17,
     -17,     0,   -17,   -17,     0,     0,   -17,   -18,   -18,   -18,
     -17,   -17,   -57,     0,     0,     0,     0,     0,   144,   145,
     196,   -18,   -18,     0,   -18,   -18,   -18,   -18,   -18,     0,
     -18,   -18,   147,     0,   -18,   -19,   -19,   -19,   -18,   -18,
       0,   148,   149,     0,     0,   150,   -49,   -49,   -49,   -19,
     -19,     0,   -19,   -19,   -19,   -19,   -19,     0,   -19,   -19,
       0,     0,   -19,   -23,   -23,   -23,   -19,   -19,     0,   -49,
     -49,     0,     0,   -49,   -48,   -48,   -48,   -23,   -23,     0,
     -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,     0,     0,
     -23,   -68,   -68,   -68,   -23,   -23,     0,   -48,   -48,     0,
       0,   -48,   144,   145,   146,   -68,   -68,     0,   -68,   -68,
     -68,   -68,   -68,     0,   -68,   -68,     0,     0,   -68,   -21,
     -21,   -21,   -68,   -68,     0,   148,   149,     0,     0,   150,
     162,   163,   164,   -21,   -21,     0,   -21,   -21,   -21,   -21,
     -21,     0,   -21,   -21,     0,     0,   -21,   -22,   -22,   -22,
     -21,   -21,     0,   166,   167,     0,     0,   168,     0,     0,
       0,   -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,     0,
     -22,   -22,     0,     0,   -22,   -20,   -20,   -20,   -22,   -22,
     -50,   -50,   -50,   -50,   -50,   -50,     0,     0,     0,   -20,
     -20,     0,   -20,   -20,   -20,   -20,   -20,     0,   -20,   -20,
     198,   -50,   -20,   -32,   -32,   -32,   -20,   -20,   -55,   -55,
     -55,   -55,   -55,   -55,     0,     0,     0,   -32,   -32,     0,
     -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,     0,   -55,
     -32,   -24,   -24,   -24,   -32,   -32,   -56,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,   -24,   -24,     0,   -24,   -24,
     -24,   -24,   -24,     0,   -24,   -24,     0,   -56,   -24,   -30,
     -30,   -30,   -24,   -24,   -43,   -43,    86,    87,   -43,   -43,
       0,     0,     0,   -30,   -30,     0,   -30,   -30,   -30,   -30,
     -30,     0,   -30,   -30,     0,   -43,   -30,   -31,   -31,   -31,
     -30,   -30,     0,     0,     0,   -55,   -55,   -55,   -55,   -55,
     -55,   -31,   -31,     0,   -31,   -31,   -31,   -31,   -31,     0,
     -31,   -31,     0,     0,   -31,     0,   -55,     0,   -31,   -31,
       0,   -55,   -56,   -56,   -56,   -56,   -56,   -56,   -43,   -43,
      86,    87,   -43,   -43,   -45,   -45,   -45,   -45,   -45,   -45,
       0,     0,     0,   -56,     0,     0,     0,     0,   -56,   -43,
       0,     0,     0,     0,   -43,   -45,     0,     0,     0,     0,
     -45,   -51,   -51,   -51,   -51,   -51,   -51,   -53,   -53,   -53,
     -53,   -53,   -53,   -54,   -54,   -54,   -54,   -54,   -54,     0,
       0,     0,   -51,     0,     0,     0,     0,   -51,   -53,     0,
       0,     0,     0,   -53,   -54,     0,     0,     0,     0,   -54,
     -72,   -72,   -72,   -72,   -72,   -72,   -73,   -73,   -73,   -73,
     -73,   -73,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,
       0,   -72,     0,     0,     0,     0,   -72,   -73,     0,     0,
       0,     0,   -73,   -75,     0,     0,     0,     0,   -75,   -76,
     -76,   -76,   -76,   -76,   -76,   -52,   -52,   -52,   -52,   -52,
     -52,   -42,   -42,    86,    87,   -42,   -42,     0,     0,     0,
     -76,     0,     0,     0,     0,   -76,   -52,     0,     0,     0,
       0,   -52,   -42,     0,     0,     0,     0,   -42,   -44,   -44,
     -44,   -44,   -44,   -44,   -57,   -57,   -57,   -57,   -57,   -57,
     -45,   -45,   -45,   -45,   -45,   -45,     0,     0,     0,   -44,
       0,     0,     0,     0,   -44,   -57,     0,     0,     0,     0,
     -57,   -45,   -51,   -51,   -51,   -51,   -51,   -51,   -53,   -53,
     -53,   -53,   -53,   -53,   -54,   -54,   -54,   -54,   -54,   -54,
       0,     0,     0,   -51,     0,     0,     0,     0,     0,   -53,
       0,     0,     0,     0,     0,   -54,   -72,   -72,   -72,   -72,
     -72,   -72,   -73,   -73,   -73,   -73,   -73,   -73,   -75,   -75,
     -75,   -75,   -75,   -75,     0,     0,     0,   -72,     0,     0,
       0,     0,     0,   -73,     0,     0,     0,     0,     0,   -75,
     -76,   -76,   -76,   -76,   -76,   -76,   -52,   -52,   -52,   -52,
     -52,   -52,   -42,   -42,    86,    87,   -42,   -42,     0,     0,
       0,   -76,     0,     0,     0,     0,     0,   -52,     0,     0,
       0,     0,     0,   -42,   -44,   -44,   -44,   -44,   -44,   -44,
     -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -44,     0,     0,     0,     0,
       0,   -57
};

static const yytype_int16 yycheck[] =
{
      20,    20,   154,   183,    26,    14,   155,     6,    14,    15,
      29,     0,   110,    35,   194,     3,     4,     5,    10,    11,
     172,     0,    14,    15,   173,    31,    37,     6,    37,    17,
      10,    11,    12,    13,    14,    15,    16,     6,    26,    27,
      35,    14,    30,    31,    66,    37,    65,    69,    36,    30,
      30,    70,    74,    75,    14,    15,    37,    37,    31,    81,
       5,    31,    31,    10,    11,    12,    13,    14,    15,    16,
      14,    66,   252,    14,    69,    14,   198,    37,   230,    74,
      75,   100,   231,    30,   236,   207,    14,    31,   237,     0,
      37,     5,    36,    88,     0,     6,    37,    14,    37,   121,
       6,     6,   122,    10,    11,    12,    13,    14,    15,    37,
      30,    35,    14,    15,    31,    14,    14,   139,   138,    36,
     139,   219,   142,    30,     5,   147,   121,   225,   150,    31,
      37,    14,    31,    31,    36,     3,     4,     5,    36,    14,
       8,     0,    66,   165,   139,    69,   168,     6,    31,    17,
      74,    75,   147,    36,    14,   150,    31,   255,    26,    27,
      19,    30,    30,   182,     3,     4,     5,    31,     0,     8,
     165,    31,    36,   168,     6,    30,   198,    31,    17,    10,
      11,   203,    36,    14,    15,   207,     0,    26,    27,    30,
     212,    30,     6,    30,   216,    10,    11,   121,   217,    14,
      15,     5,    37,   198,   226,    19,    37,   226,   203,   204,
     205,   206,   207,    37,    35,   139,    31,   212,   213,   214,
     215,   216,    31,   147,     0,    37,   150,    36,   248,    37,
       6,   226,     3,     4,     5,   257,   256,     0,   257,    37,
      37,   165,   262,     6,   168,    66,    17,    37,    69,     3,
       4,     5,     0,    74,    75,    26,    27,     0,     6,    30,
       3,    31,   257,    17,    37,    37,    10,    11,    12,    13,
      14,    15,    26,    27,   198,     5,    30,     7,     0,   203,
     204,   205,   206,   207,     6,    35,    37,     5,   212,   213,
     214,   215,   216,    37,    10,    11,    12,    13,    14,    15,
     121,     0,   226,     5,     5,     7,     7,     6,     3,     4,
       5,     0,    35,     5,     0,     7,    66,     6,   139,    69,
       6,    37,    17,    37,    74,    75,   147,     5,     0,   150,
       0,    26,    27,   257,     6,    30,     6,    37,    31,     3,
       4,     5,     0,    66,   165,    35,    69,   168,     6,     0,
      37,    74,    75,    17,    18,     6,    20,    21,    22,    23,
      24,     0,    26,    27,    31,    31,    30,     6,     0,    36,
      34,   121,     0,    34,     6,    10,    11,   198,     6,    14,
      15,     0,   203,   204,   205,   206,   207,     6,    31,   139,
      31,   212,   213,   214,   215,   216,    31,   147,   121,     5,
     150,    36,    31,     5,    31,   226,     3,     4,     5,    36,
      35,     3,     4,     5,    31,   165,   139,     0,   168,    36,
      17,    31,     0,     6,   147,    17,    36,   150,     6,    26,
      27,    31,    31,    30,    26,    27,   257,    36,    30,     5,
      35,    66,   165,    37,    69,   168,    31,    31,   198,    74,
      75,    36,    36,   203,   204,   205,   206,   207,    37,    34,
      37,    37,   212,   213,   214,   215,   216,    10,    11,    12,
      13,    14,    15,    37,    37,   198,   226,     3,     4,     5,
     203,   204,   205,   206,   207,    37,    37,    37,    37,   212,
     213,   214,   215,   216,    37,    31,   121,     5,    35,     5,
      26,    27,     5,   226,    30,     5,    30,   257,    10,    11,
      12,    13,    14,    15,   139,    10,    11,    30,    35,    14,
      15,    37,   147,    37,     5,   150,    37,    37,    37,    66,
      35,    35,    69,    31,   257,    37,    31,    74,    75,    31,
     165,    36,    31,   168,     3,     4,     5,    37,    85,    66,
      37,    31,    69,    35,    31,    10,    11,    74,    75,    14,
      15,    66,    34,    37,    69,    82,    34,    26,    27,    74,
      75,    30,    35,   198,    31,     3,    31,    20,   203,   204,
     205,   206,   207,    20,   121,    20,    20,   212,   213,   214,
     215,   216,    10,    11,    12,    13,    14,    15,    20,    20,
      -1,   226,   139,    20,   121,    20,    -1,    -1,    -1,    -1,
     147,    -1,    -1,   150,    -1,    35,   121,    -1,    -1,    37,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,   165,    -1,
     147,   168,   257,   150,   139,    10,    11,    12,    13,    14,
      15,    -1,   147,    -1,    -1,   150,    66,    -1,   165,    69,
      -1,   168,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,
     165,   198,    37,   168,    -1,    -1,   203,   204,   205,    -1,
     207,    -1,    -1,    -1,    -1,   212,   213,   214,    -1,   216,
      -1,   198,    -1,    -1,    35,    -1,   203,   204,    -1,   226,
     207,    -1,    -1,   198,    -1,   212,   213,    -1,   203,   216,
      -1,   121,   207,   123,     3,     4,     5,   212,    -1,   226,
      -1,   216,    -1,    -1,    -1,    66,    -1,    -1,    69,   139,
     257,   226,    -1,    74,    75,    -1,    -1,    26,    27,    -1,
     150,    30,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
     257,    -1,    10,    11,    12,    13,    14,    15,   168,    -1,
      17,    18,   257,    20,    21,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    37,
     121,    10,    11,    12,    13,    14,    15,    16,   198,    -1,
      10,    11,    12,    13,    14,    15,    25,   207,   139,    28,
      29,    30,    -1,    -1,    -1,    -1,   216,    -1,    37,   150,
      -1,     3,     4,     5,     6,    -1,   226,    37,    -1,    10,
      11,    12,    13,    14,    15,    17,    18,   168,    20,    21,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    30,   249,
      -1,    -1,    34,    35,    -1,    -1,    37,   257,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,   198,    10,    11,
      12,    13,    14,    15,    17,    18,   207,    20,    21,    22,
      23,    24,    -1,    26,    27,   216,    -1,    30,    30,    31,
      -1,    34,    35,    -1,    36,   226,     3,     4,     5,     6,
      -1,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      17,    18,    -1,    20,    21,    22,    23,    24,    -1,    26,
      27,    30,    31,    30,    -1,    -1,   257,    34,    35,     3,
       4,     5,     6,    -1,    -1,    10,    11,    12,    13,    14,
      15,    -1,    -1,    17,    18,    -1,    20,    21,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    30,     3,     4,     5,
      34,    35,    37,    10,    11,    12,    13,    14,    15,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    30,     3,     4,     5,    34,    35,
      37,    10,    11,    12,    13,    14,    15,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    30,     3,     4,     5,    34,    35,    37,    10,
      11,    12,    13,    14,    15,    -1,    -1,    17,    18,    -1,
      20,    21,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      30,     3,     4,     5,    34,    35,    37,    10,    11,    12,
      13,    14,    15,    -1,    -1,    17,    18,    -1,    20,    21,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    30,     3,
       4,     5,    34,    35,    37,    10,    11,    12,    13,    14,
      15,    -1,    -1,    17,    18,    -1,    20,    21,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    30,     3,     4,     5,
      34,    35,    37,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    17,    18,    -1,    20,    21,    22,    23,    24,    -1,
      26,    27,    17,    -1,    30,     3,     4,     5,    34,    35,
      -1,    26,    27,    -1,    -1,    30,     3,     4,     5,    17,
      18,    -1,    20,    21,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    30,     3,     4,     5,    34,    35,    -1,    26,
      27,    -1,    -1,    30,     3,     4,     5,    17,    18,    -1,
      20,    21,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      30,     3,     4,     5,    34,    35,    -1,    26,    27,    -1,
      -1,    30,     3,     4,     5,    17,    18,    -1,    20,    21,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    30,     3,
       4,     5,    34,    35,    -1,    26,    27,    -1,    -1,    30,
       3,     4,     5,    17,    18,    -1,    20,    21,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    30,     3,     4,     5,
      34,    35,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    30,     3,     4,     5,    34,    35,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    22,    23,    24,    -1,    26,    27,
      30,    31,    30,     3,     4,     5,    34,    35,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    22,    23,    24,    -1,    26,    27,    -1,    31,
      30,     3,     4,     5,    34,    35,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      22,    23,    24,    -1,    26,    27,    -1,    31,    30,     3,
       4,     5,    34,    35,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    22,    23,
      24,    -1,    26,    27,    -1,    31,    30,     3,     4,     5,
      34,    35,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      15,    17,    18,    -1,    20,    21,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    31,    -1,    34,    35,
      -1,    36,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    31,
      -1,    -1,    -1,    -1,    36,    31,    -1,    -1,    -1,    -1,
      36,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    31,    -1,
      -1,    -1,    -1,    36,    31,    -1,    -1,    -1,    -1,    36,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    36,    31,    -1,    -1,
      -1,    -1,    36,    31,    -1,    -1,    -1,    -1,    36,    10,
      11,    12,    13,    14,    15,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    36,    31,    -1,    -1,    -1,
      -1,    36,    31,    -1,    -1,    -1,    -1,    36,    10,    11,
      12,    13,    14,    15,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    36,    31,    -1,    -1,    -1,    -1,
      36,    31,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    31,    10,    11,    12,    13,
      14,    15,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    31,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    31,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    46,    47,    48,    49,    50,     5,     7,     0,
      48,    30,    37,     5,     6,    51,    52,    37,     5,     7,
      31,    36,     5,     3,     4,     5,    17,    18,    20,    21,
      22,    23,    24,    26,    27,    30,    34,    53,    54,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    69,
      70,    71,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     6,    16,    30,     5,    63,    30,
      30,     5,    60,    30,    30,    30,     5,     5,    61,    55,
      37,    14,    15,    10,    11,    67,    12,    13,    68,    37,
      37,    37,     5,     7,     5,    60,    61,    72,    61,    60,
      16,    37,     5,     8,    61,     8,    61,    31,     6,    49,
      53,    56,    63,    65,    66,    69,     5,    25,    28,    29,
      31,    36,    31,    37,    31,    31,    31,    31,    31,     5,
      56,    35,     5,     5,     5,    61,    54,    61,    19,    37,
      54,    60,    31,    54,     3,     4,     5,    17,    26,    27,
      30,    62,    63,    64,    65,    66,    69,    70,    71,    79,
      81,    82,     3,     4,     5,    17,    26,    27,    30,    62,
      63,    64,    65,    66,    69,    70,    71,    79,    81,    82,
      18,    20,    21,    34,    54,    57,    58,    59,    60,    73,
      76,    77,    78,     7,    34,    37,     5,    61,    30,    63,
       5,     5,    61,    14,    15,    67,    68,    30,    63,     5,
       5,    61,    14,    15,    67,    68,    30,    30,    60,    55,
      37,    37,    37,    37,     5,    55,    16,    72,    31,    63,
      65,    66,    69,    72,    31,    63,    65,    66,    69,    61,
      60,    37,    56,    37,    56,    60,    31,    31,    31,    37,
      35,    35,    34,    54,    61,    55,    19,    37,    56,    54,
      60,    35,    31,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    50,
      51,    51,    52,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    55,    55,    56,    56,    57,
      57,    58,    59,    60,    60,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    69,    69,    69,    70,    70,    71,    72,    72,
      72,    73,    73,    74,    74,    75,    75,    76,    77,    78,
      78,    78,    79,    79,    80,    81,    82,    83,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     4,     6,
       1,     0,     4,     5,     2,     3,     1,     1,     1,     1,
       2,     2,     2,     1,     4,     2,     0,     2,     0,     5,
       7,     9,     3,     3,     1,     1,     3,     1,     2,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     4,     3,     1,
       0,     1,     1,     4,     4,     4,     4,     4,     2,     1,
       1,     1,     1,     1,     5,     2,     2,     5,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: declarationList  */
#line 168 "./src/syntax.y"
                    {}
#line 1894 "./src/syntax.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 172 "./src/syntax.y"
                                {}
#line 1900 "./src/syntax.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 173 "./src/syntax.y"
                  {}
#line 1906 "./src/syntax.tab.c"
    break;

  case 5: /* declaration: varDeclaration  */
#line 177 "./src/syntax.y"
                   {}
#line 1912 "./src/syntax.tab.c"
    break;

  case 6: /* declaration: funcDeclaration  */
#line 178 "./src/syntax.y"
                      {}
#line 1918 "./src/syntax.tab.c"
    break;

  case 7: /* varDeclaration: TYPE ID DELIM_SEMICOLLON  */
#line 182 "./src/syntax.y"
                             {
        printf("%s %s %s\n", (yyvsp[-2].t_token).text, (yyvsp[-1].t_token).text, (yyvsp[0].t_token).text);
    }
#line 1926 "./src/syntax.tab.c"
    break;

  case 8: /* varDeclaration: TYPE LIST_TYPE ID DELIM_SEMICOLLON  */
#line 185 "./src/syntax.y"
                                         {}
#line 1932 "./src/syntax.tab.c"
    break;

  case 9: /* funcDeclaration: TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R statement  */
#line 203 "./src/syntax.y"
                                                               {}
#line 1938 "./src/syntax.tab.c"
    break;

  case 10: /* parameters: parameterList  */
#line 207 "./src/syntax.y"
                  {}
#line 1944 "./src/syntax.tab.c"
    break;

  case 11: /* parameters: %empty  */
#line 208 "./src/syntax.y"
      {}
#line 1950 "./src/syntax.tab.c"
    break;

  case 12: /* parameterList: parameterList DELIM_COMMA TYPE ID  */
#line 212 "./src/syntax.y"
                                      {}
#line 1956 "./src/syntax.tab.c"
    break;

  case 13: /* parameterList: parameterList DELIM_COMMA TYPE LIST_TYPE ID  */
#line 213 "./src/syntax.y"
                                                  {}
#line 1962 "./src/syntax.tab.c"
    break;

  case 14: /* parameterList: TYPE ID  */
#line 214 "./src/syntax.y"
              {}
#line 1968 "./src/syntax.tab.c"
    break;

  case 15: /* parameterList: TYPE LIST_TYPE ID  */
#line 215 "./src/syntax.y"
                        {}
#line 1974 "./src/syntax.tab.c"
    break;

  case 16: /* statement: bodyStatement  */
#line 219 "./src/syntax.y"
                  {}
#line 1980 "./src/syntax.tab.c"
    break;

  case 17: /* statement: ifStatement  */
#line 220 "./src/syntax.y"
                  {}
#line 1986 "./src/syntax.tab.c"
    break;

  case 18: /* statement: loopStatement  */
#line 221 "./src/syntax.y"
                    {}
#line 1992 "./src/syntax.tab.c"
    break;

  case 19: /* statement: returnStatement  */
#line 222 "./src/syntax.y"
                      {}
#line 1998 "./src/syntax.tab.c"
    break;

  case 20: /* statement: listStatement DELIM_SEMICOLLON  */
#line 223 "./src/syntax.y"
                                     {}
#line 2004 "./src/syntax.tab.c"
    break;

  case 21: /* statement: writeOp DELIM_SEMICOLLON  */
#line 224 "./src/syntax.y"
                               {}
#line 2010 "./src/syntax.tab.c"
    break;

  case 22: /* statement: readOp DELIM_SEMICOLLON  */
#line 225 "./src/syntax.y"
                              {}
#line 2016 "./src/syntax.tab.c"
    break;

  case 23: /* statement: expressionStatement  */
#line 226 "./src/syntax.y"
                          {}
#line 2022 "./src/syntax.tab.c"
    break;

  case 24: /* bodyStatement: DELIM_CUR_BRACKET_L localDeclaration statementList DELIM_CUR_BRACKET_R  */
#line 230 "./src/syntax.y"
                                                                           {}
#line 2028 "./src/syntax.tab.c"
    break;

  case 25: /* localDeclaration: localDeclaration varDeclaration  */
#line 234 "./src/syntax.y"
                                    {}
#line 2034 "./src/syntax.tab.c"
    break;

  case 26: /* localDeclaration: %empty  */
#line 235 "./src/syntax.y"
      {}
#line 2040 "./src/syntax.tab.c"
    break;

  case 27: /* statementList: statement statementList  */
#line 239 "./src/syntax.y"
                            {}
#line 2046 "./src/syntax.tab.c"
    break;

  case 28: /* statementList: %empty  */
#line 240 "./src/syntax.y"
      {}
#line 2052 "./src/syntax.tab.c"
    break;

  case 29: /* ifStatement: IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R bodyStatement  */
#line 244 "./src/syntax.y"
                                                                        {}
#line 2058 "./src/syntax.tab.c"
    break;

  case 30: /* ifStatement: IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R bodyStatement ELSE_KEY bodyStatement  */
#line 245 "./src/syntax.y"
                                                                                                 {}
#line 2064 "./src/syntax.tab.c"
    break;

  case 31: /* loopStatement: FOR_KEY DELIM_PARENT_L expression DELIM_SEMICOLLON simpleExpression DELIM_SEMICOLLON expression DELIM_PARENT_R bodyStatement  */
#line 249 "./src/syntax.y"
                                                                                                                                 {}
#line 2070 "./src/syntax.tab.c"
    break;

  case 32: /* returnStatement: RETURN_KEY expression DELIM_SEMICOLLON  */
#line 253 "./src/syntax.y"
                                           {}
#line 2076 "./src/syntax.tab.c"
    break;

  case 33: /* expression: ID ASSIGN_OP expression  */
#line 257 "./src/syntax.y"
                            {}
#line 2082 "./src/syntax.tab.c"
    break;

  case 34: /* expression: simpleExpression  */
#line 258 "./src/syntax.y"
                       {}
#line 2088 "./src/syntax.tab.c"
    break;

  case 35: /* simpleExpression: logicBinExpression  */
#line 267 "./src/syntax.y"
                       {}
#line 2094 "./src/syntax.tab.c"
    break;

  case 36: /* logicBinExpression: logicBinExpression LOGIC_OP logicUnExpression  */
#line 276 "./src/syntax.y"
                                                  {}
#line 2100 "./src/syntax.tab.c"
    break;

  case 37: /* logicBinExpression: logicUnExpression  */
#line 277 "./src/syntax.y"
                        {}
#line 2106 "./src/syntax.tab.c"
    break;

  case 38: /* logicUnExpression: EXCLA_OP logicUnExpression  */
#line 281 "./src/syntax.y"
                               {}
#line 2112 "./src/syntax.tab.c"
    break;

  case 39: /* logicUnExpression: binExpression  */
#line 282 "./src/syntax.y"
                    {}
#line 2118 "./src/syntax.tab.c"
    break;

  case 40: /* binExpression: binExpression BINARY_OP sumExpression  */
#line 290 "./src/syntax.y"
                                          {}
#line 2124 "./src/syntax.tab.c"
    break;

  case 41: /* binExpression: sumExpression  */
#line 291 "./src/syntax.y"
                    {}
#line 2130 "./src/syntax.tab.c"
    break;

  case 42: /* sumExpression: sumExpression sumOP mulExpression  */
#line 295 "./src/syntax.y"
                                      {}
#line 2136 "./src/syntax.tab.c"
    break;

  case 43: /* sumExpression: mulExpression  */
#line 296 "./src/syntax.y"
                    {}
#line 2142 "./src/syntax.tab.c"
    break;

  case 44: /* mulExpression: mulExpression mulOP factor  */
#line 300 "./src/syntax.y"
                               {}
#line 2148 "./src/syntax.tab.c"
    break;

  case 45: /* mulExpression: factor  */
#line 301 "./src/syntax.y"
             {}
#line 2154 "./src/syntax.tab.c"
    break;

  case 46: /* sumOP: PLUS_OP  */
#line 305 "./src/syntax.y"
            {}
#line 2160 "./src/syntax.tab.c"
    break;

  case 47: /* sumOP: MINUS_OP  */
#line 306 "./src/syntax.y"
               {}
#line 2166 "./src/syntax.tab.c"
    break;

  case 48: /* mulOP: MUL_OP  */
#line 310 "./src/syntax.y"
           {}
#line 2172 "./src/syntax.tab.c"
    break;

  case 49: /* mulOP: DIV_OP  */
#line 311 "./src/syntax.y"
             {}
#line 2178 "./src/syntax.tab.c"
    break;

  case 50: /* factor: ID  */
#line 315 "./src/syntax.y"
       {}
#line 2184 "./src/syntax.tab.c"
    break;

  case 51: /* factor: constant  */
#line 316 "./src/syntax.y"
               {}
#line 2190 "./src/syntax.tab.c"
    break;

  case 52: /* factor: DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 317 "./src/syntax.y"
                                                     {}
#line 2196 "./src/syntax.tab.c"
    break;

  case 53: /* factor: functionCall  */
#line 318 "./src/syntax.y"
                   {}
#line 2202 "./src/syntax.tab.c"
    break;

  case 54: /* factor: listExpression  */
#line 319 "./src/syntax.y"
                     {}
#line 2208 "./src/syntax.tab.c"
    break;

  case 55: /* constant: INT  */
#line 323 "./src/syntax.y"
        {}
#line 2214 "./src/syntax.tab.c"
    break;

  case 56: /* constant: FLOAT  */
#line 324 "./src/syntax.y"
            {}
#line 2220 "./src/syntax.tab.c"
    break;

  case 57: /* functionCall: ID DELIM_PARENT_L parametersPass DELIM_PARENT_R  */
#line 328 "./src/syntax.y"
                                                    {}
#line 2226 "./src/syntax.tab.c"
    break;

  case 58: /* parametersPass: parametersPass DELIM_COMMA simpleExpression  */
#line 332 "./src/syntax.y"
                                                {}
#line 2232 "./src/syntax.tab.c"
    break;

  case 59: /* parametersPass: simpleExpression  */
#line 333 "./src/syntax.y"
                       {}
#line 2238 "./src/syntax.tab.c"
    break;

  case 60: /* parametersPass: %empty  */
#line 334 "./src/syntax.y"
      {}
#line 2244 "./src/syntax.tab.c"
    break;

  case 61: /* writeOp: write  */
#line 338 "./src/syntax.y"
          {}
#line 2250 "./src/syntax.tab.c"
    break;

  case 62: /* writeOp: writeln  */
#line 339 "./src/syntax.y"
              {}
#line 2256 "./src/syntax.tab.c"
    break;

  case 63: /* write: OUTPUT_KEY DELIM_PARENT_L STRING DELIM_PARENT_R  */
#line 343 "./src/syntax.y"
                                                    {}
#line 2262 "./src/syntax.tab.c"
    break;

  case 64: /* write: OUTPUT_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 344 "./src/syntax.y"
                                                                {}
#line 2268 "./src/syntax.tab.c"
    break;

  case 65: /* writeln: OUTPUTLN_KEY DELIM_PARENT_L STRING DELIM_PARENT_R  */
#line 348 "./src/syntax.y"
                                                      {}
#line 2274 "./src/syntax.tab.c"
    break;

  case 66: /* writeln: OUTPUTLN_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 349 "./src/syntax.y"
                                                                  {}
#line 2280 "./src/syntax.tab.c"
    break;

  case 67: /* readOp: INPUT_KEY DELIM_PARENT_L ID DELIM_PARENT_R  */
#line 353 "./src/syntax.y"
                                               {}
#line 2286 "./src/syntax.tab.c"
    break;

  case 68: /* expressionStatement: expression DELIM_SEMICOLLON  */
#line 357 "./src/syntax.y"
                                {}
#line 2292 "./src/syntax.tab.c"
    break;

  case 69: /* listStatement: listAssign  */
#line 361 "./src/syntax.y"
               {}
#line 2298 "./src/syntax.tab.c"
    break;

  case 70: /* listStatement: listMap  */
#line 362 "./src/syntax.y"
              {}
#line 2304 "./src/syntax.tab.c"
    break;

  case 71: /* listStatement: listFilter  */
#line 363 "./src/syntax.y"
                 {}
#line 2310 "./src/syntax.tab.c"
    break;

  case 72: /* listExpression: listHeader  */
#line 367 "./src/syntax.y"
               {}
#line 2316 "./src/syntax.tab.c"
    break;

  case 73: /* listExpression: listTailDestructor  */
#line 369 "./src/syntax.y"
                         {}
#line 2322 "./src/syntax.tab.c"
    break;

  case 74: /* listAssign: ID ASSIGN_OP ID ASSIGN_LISTOP ID  */
#line 373 "./src/syntax.y"
                                     {}
#line 2328 "./src/syntax.tab.c"
    break;

  case 75: /* listHeader: HEADER_LISTOP ID  */
#line 377 "./src/syntax.y"
                     {}
#line 2334 "./src/syntax.tab.c"
    break;

  case 76: /* listTailDestructor: TAILDES_LISTOP ID  */
#line 385 "./src/syntax.y"
                      {}
#line 2340 "./src/syntax.tab.c"
    break;

  case 77: /* listMap: ID ASSIGN_OP ID MAP_LISTOP ID  */
#line 389 "./src/syntax.y"
                                  {}
#line 2346 "./src/syntax.tab.c"
    break;

  case 78: /* listFilter: ID ASSIGN_OP ID FILTER_LISTOP ID  */
#line 393 "./src/syntax.y"
                                     {}
#line 2352 "./src/syntax.tab.c"
    break;


#line 2356 "./src/syntax.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 397 "./src/syntax.y"

/* Additional C code */

void yyerror(const char* s){
    printf("Syntax error: %s\nLine: %d - Column: %d\n", s, line, column);
    error = error + 1;
}

int main(int argc, char **argv){
    FILE *filep;

    line = 1;
    column = 1;
    error = 0;

    /* createSymbol("Teste");
    printTable(); */


    if(argc >= 2) {
        filep = fopen(argv[1], "r");

        if(filep != NULL){
            /* print_start(); */

            yyin = filep;
            /* yylex(); */
            yyparse();
            fclose(yyin);

            /* print_end(); */
        }
        else{
            printf("Error while opening the file.\n");

        }

    }
    else{
        printf("No file has been chosen.\n");
    }

    yylex_destroy();

    return 0;
}
