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
#include <string.h>
#include "base.h"
#include "symbol_table.h"

extern int yylex();
extern int yylex_destroy();
extern int yyparse();
extern void yyerror(const char* s);
extern FILE* yyin;

//yynerrs //global variable counting errors


#line 89 "./src/syntax.tab.c"

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
  YYSYMBOL_THEN_PREC = 22,                 /* THEN_PREC  */
  YYSYMBOL_INPUT_KEY = 23,                 /* INPUT_KEY  */
  YYSYMBOL_OUTPUT_KEY = 24,                /* OUTPUT_KEY  */
  YYSYMBOL_OUTPUTLN_KEY = 25,              /* OUTPUTLN_KEY  */
  YYSYMBOL_ASSIGN_LISTOP = 26,             /* ASSIGN_LISTOP  */
  YYSYMBOL_HEADER_LISTOP = 27,             /* HEADER_LISTOP  */
  YYSYMBOL_TAILDES_LISTOP = 28,            /* TAILDES_LISTOP  */
  YYSYMBOL_MAP_LISTOP = 29,                /* MAP_LISTOP  */
  YYSYMBOL_FILTER_LISTOP = 30,             /* FILTER_LISTOP  */
  YYSYMBOL_DELIM_PARENT_L = 31,            /* DELIM_PARENT_L  */
  YYSYMBOL_DELIM_PARENT_R = 32,            /* DELIM_PARENT_R  */
  YYSYMBOL_DELIM_BRACKET_L = 33,           /* DELIM_BRACKET_L  */
  YYSYMBOL_DELIM_BRACKET_R = 34,           /* DELIM_BRACKET_R  */
  YYSYMBOL_DELIM_CUR_BRACKET_L = 35,       /* DELIM_CUR_BRACKET_L  */
  YYSYMBOL_DELIM_CUR_BRACKET_R = 36,       /* DELIM_CUR_BRACKET_R  */
  YYSYMBOL_DELIM_COMMA = 37,               /* DELIM_COMMA  */
  YYSYMBOL_DELIM_SEMICOLLON = 38,          /* DELIM_SEMICOLLON  */
  YYSYMBOL_DELIM_SQUOTE = 39,              /* DELIM_SQUOTE  */
  YYSYMBOL_DELIM_DQUOTE = 40,              /* DELIM_DQUOTE  */
  YYSYMBOL_SINGLE_COMMENT = 41,            /* SINGLE_COMMENT  */
  YYSYMBOL_MULTI_COMMENT = 42,             /* MULTI_COMMENT  */
  YYSYMBOL_FORMAT_BLANKSPACE = 43,         /* FORMAT_BLANKSPACE  */
  YYSYMBOL_FORMAT_NEWLINE = 44,            /* FORMAT_NEWLINE  */
  YYSYMBOL_FORMAT_TAB = 45,                /* FORMAT_TAB  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_declarationList = 48,           /* declarationList  */
  YYSYMBOL_declaration = 49,               /* declaration  */
  YYSYMBOL_varDeclaration = 50,            /* varDeclaration  */
  YYSYMBOL_funcDeclaration = 51,           /* funcDeclaration  */
  YYSYMBOL_parameters = 52,                /* parameters  */
  YYSYMBOL_parameterList = 53,             /* parameterList  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_bodyStatement = 55,             /* bodyStatement  */
  YYSYMBOL_localDeclaration = 56,          /* localDeclaration  */
  YYSYMBOL_statementList = 57,             /* statementList  */
  YYSYMBOL_ifStatement = 58,               /* ifStatement  */
  YYSYMBOL_loopStatement = 59,             /* loopStatement  */
  YYSYMBOL_returnStatement = 60,           /* returnStatement  */
  YYSYMBOL_expression = 61,                /* expression  */
  YYSYMBOL_simpleExpression = 62,          /* simpleExpression  */
  YYSYMBOL_logicBinExpression = 63,        /* logicBinExpression  */
  YYSYMBOL_logicUnExpression = 64,         /* logicUnExpression  */
  YYSYMBOL_binExpression = 65,             /* binExpression  */
  YYSYMBOL_sumExpression = 66,             /* sumExpression  */
  YYSYMBOL_mulExpression = 67,             /* mulExpression  */
  YYSYMBOL_sumOP = 68,                     /* sumOP  */
  YYSYMBOL_mulOP = 69,                     /* mulOP  */
  YYSYMBOL_factor = 70,                    /* factor  */
  YYSYMBOL_constant = 71,                  /* constant  */
  YYSYMBOL_functionCall = 72,              /* functionCall  */
  YYSYMBOL_parametersPass = 73,            /* parametersPass  */
  YYSYMBOL_writeOp = 74,                   /* writeOp  */
  YYSYMBOL_write = 75,                     /* write  */
  YYSYMBOL_writeln = 76,                   /* writeln  */
  YYSYMBOL_readOp = 77,                    /* readOp  */
  YYSYMBOL_expressionStatement = 78,       /* expressionStatement  */
  YYSYMBOL_listStatement = 79,             /* listStatement  */
  YYSYMBOL_listExpression = 80,            /* listExpression  */
  YYSYMBOL_listAssign = 81,                /* listAssign  */
  YYSYMBOL_listHeader = 82,                /* listHeader  */
  YYSYMBOL_listTailDestructor = 83,        /* listTailDestructor  */
  YYSYMBOL_listMap = 84,                   /* listMap  */
  YYSYMBOL_listFilter = 85                 /* listFilter  */
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
#define YYLAST   2946

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  275

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   171,   171,   175,   176,   180,   181,   185,   189,   215,
     219,   231,   232,   236,   237,   238,   239,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   255,   263,   264,   268,
     269,   273,   274,   278,   282,   286,   287,   296,   305,   306,
     310,   311,   319,   320,   324,   325,   329,   330,   334,   335,
     339,   340,   344,   345,   346,   347,   348,   352,   353,   354,
     355,   356,   360,   364,   365,   366,   370,   371,   375,   376,
     380,   381,   385,   389,   393,   394,   395,   399,   401,   405,
     409,   417,   421,   425
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
  "IF_KEY", "ELSE_KEY", "FOR_KEY", "RETURN_KEY", "THEN_PREC", "INPUT_KEY",
  "OUTPUT_KEY", "OUTPUTLN_KEY", "ASSIGN_LISTOP", "HEADER_LISTOP",
  "TAILDES_LISTOP", "MAP_LISTOP", "FILTER_LISTOP", "DELIM_PARENT_L",
  "DELIM_PARENT_R", "DELIM_BRACKET_L", "DELIM_BRACKET_R",
  "DELIM_CUR_BRACKET_L", "DELIM_CUR_BRACKET_R", "DELIM_COMMA",
  "DELIM_SEMICOLLON", "DELIM_SQUOTE", "DELIM_DQUOTE", "SINGLE_COMMENT",
  "MULTI_COMMENT", "FORMAT_BLANKSPACE", "FORMAT_NEWLINE", "FORMAT_TAB",
  "$accept", "program", "declarationList", "declaration", "varDeclaration",
  "funcDeclaration", "parameters", "parameterList", "statement",
  "bodyStatement", "localDeclaration", "statementList", "ifStatement",
  "loopStatement", "returnStatement", "expression", "simpleExpression",
  "logicBinExpression", "logicUnExpression", "binExpression",
  "sumExpression", "mulExpression", "sumOP", "mulOP", "factor", "constant",
  "functionCall", "parametersPass", "writeOp", "write", "writeln",
  "readOp", "expressionStatement", "listStatement", "listExpression",
  "listAssign", "listHeader", "listTailDestructor", "listMap",
  "listFilter", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300
};
#endif

#define YYPACT_NINF (-163)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,     6,    49,    28,   194,   202,   211,    44,   102,  -163,
     238,     1,   262,    45,   156,    85,    87,     1,   265,   164,
     131,    46,   153,   128,   172,  1324,   270,   213,    46,  1360,
     247,   171,   302,   303,   658,   250,  1396,   168,   352,   339,
     315,   463,    17,  2161,   158,   188,  2170,   191,   203,   216,
     255,   275,  2191,  2008,  1432,  1468,  1504,  1540,  1576,   237,
     273,    15,    22,    -6,    12,   542,   554,  2304,  2324,   274,
     283,   293,   294,  1612,   295,  2333,   304,  2339,  2345,   306,
     320,  2200,    37,   322,   335,  2353,  2374,   285,    24,  2191,
    2170,   448,   330,   380,   586,   692,  2382,  2388,   357,  1648,
    2161,   377,  2251,  2260,   377,  2272,  2281,   377,  1684,  1720,
    1756,   243,   353,   281,   282,   355,   364,   359,  2170,  1792,
     366,   369,   379,   381,   382,  2394,    41,    56,  2403,  2423,
     407,   410,   411,  2432,  2221,  2103,  2161,   384,   387,   389,
     403,   404,   405,   413,   415,   297,   748,   417,  2132,  2230,
    1828,   425,  2132,  1864,  1324,  2727,  2733,  2704,  2739,   169,
    2191,   462,   465,  2191,    89,    96,    77,   235,  2762,  2768,
    2774,  2797,  2803,  2809,  2832,  2452,  2468,  2440,  2480,   301,
    2221,   466,   476,  2191,    74,    76,    63,   154,  2496,  2508,
    2524,  2536,  2552,  2564,  2580,  2041,  2074,   784,   452,   453,
    2170,  1324,   820,   856,   892,   928,   451,   456,   457,   964,
     458,   730,   459,  1900,    37,  2838,  2844,   118,  2867,  2873,
     468,  2191,  2293,  2293,  2293,    37,  2592,  2608,    90,  2620,
    2636,   470,  2221,  2302,  2302,  2302,  2191,  2170,   460,  1936,
    1000,  1036,  1072,  1108,  2230,  1972,   311,  2879,   161,   392,
    2902,  2908,   337,  2648,   115,   278,  2664,  2676,   472,   467,
    1144,  1180,   474,  2914,  2692,  2103,  2161,  1216,   469,  2103,
    2230,  1252,   477,  2103,  1288
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,   487,   481,  -163,   480,  -163,  -134,   -18,
    -163,  -150,   -32,   -15,   -10,   -34,   511,   488,   -37,   490,
     398,   305,  -162,  -151,    -9,     7,   103,  -153,    -4,  -163,
    -163,    -3,     5,    10,   196,  -163,   212,   289,  -163,  -163
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     5,     6,    15,    16,    54,   202,
      34,    29,   203,   204,   205,   206,    60,    61,    62,    63,
      64,    65,   104,   107,    66,    67,    68,   114,   207,    70,
      71,   208,   209,   210,    75,    76,    77,    78,    79,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,   146,    56,    26,   213,   223,    88,    14,   -41,   101,
      32,     7,    92,     8,   150,   165,    55,   224,   153,    57,
      85,    86,   102,   103,    58,   234,   -43,   -43,    -2,   100,
      69,    72,   -41,   -12,     1,     1,   -39,   235,   -40,    73,
     175,   176,   177,   169,    74,   185,   178,   112,   179,     9,
     -43,   239,   165,   -37,   180,   -38,   117,   165,   165,   170,
     -39,   246,   -40,   126,   181,   182,   102,   103,   183,   -65,
     -42,   -42,   252,   189,   -65,    11,    17,   -41,   233,   -38,
     169,    25,    12,    18,   112,   169,   169,   223,   232,   190,
     -39,   -41,   222,   234,   -42,   -41,   170,   185,   129,   224,
     -41,   170,   170,   221,   -40,   235,   -37,    13,   -39,   -41,
     -39,   -37,   165,   -39,    59,   151,    56,    21,    59,   -11,
      56,   -37,   -40,   217,    22,   189,   165,   -40,   -39,   -38,
      55,   267,   -40,    57,    55,   271,    24,    57,    58,   274,
     169,   190,    58,   228,    69,    72,   165,   -38,    69,    72,
     -40,   169,   -38,    73,   169,   171,   170,    73,    74,    27,
      28,    19,    74,    20,   102,   103,   238,   170,   -43,   -43,
     170,   189,   215,   216,   169,   -38,    35,   185,   -57,   -57,
     -57,   -57,   -57,   -57,   248,   191,   -43,   190,   185,    89,
     170,   -43,   171,   -38,    -4,   254,   -15,   171,   171,   165,
      -4,   -15,    -5,   259,   -16,   189,   -57,   165,    -5,   -16,
     262,    -6,   169,   169,   169,   251,   189,    -6,    30,    90,
      31,   190,    93,   189,   189,   189,   257,   169,   170,   170,
     170,   170,   190,   165,    94,   169,   272,   191,    -3,   190,
     190,   190,   190,   170,    -3,   102,   103,    95,   172,   -43,
     -43,   170,   171,   -52,   -52,   -52,   -52,   -52,   -52,   118,
      96,   169,    -7,   171,   173,    -8,   171,   -43,    -7,   130,
      -9,    -8,   131,   132,    82,    99,    -9,   170,   192,   -13,
      97,   -52,   -14,   191,   -13,   172,   171,   -14,   102,   103,
     172,   172,   -42,   -42,   193,   -52,   -52,   -52,   -52,   -52,
     -52,   173,   -10,   -26,   226,   227,   173,   173,   -10,   -26,
     -42,   -36,   108,   -64,   133,   -42,    82,   191,   -64,   134,
      83,   -66,    84,   -52,   171,   171,   171,   171,   191,   -63,
     192,   -67,   109,   110,   -63,   191,   191,   191,   191,   171,
     115,   174,   -74,   263,   -75,   172,   193,   171,   134,   -52,
     -52,   -52,   -52,   -52,   -52,    81,   172,   168,   -76,   172,
     195,   173,   -59,   -59,   -59,   -59,   -59,   -59,   119,   264,
      82,   194,   173,   171,   134,   173,   192,   -52,   174,   172,
      37,    38,    87,   174,   174,   120,    41,   188,    42,   125,
     -59,   -35,   193,   196,   168,   173,   135,   136,   137,   168,
     168,   138,   102,   103,    50,    51,   -42,   -42,    52,   128,
     192,   139,   142,   140,   141,   143,   144,   172,   172,   172,
     172,   192,   -72,   194,   -42,   -68,   193,   -69,   192,   192,
     192,   192,   172,   173,   173,   173,   173,   193,   174,   188,
     172,   -70,   -71,   -79,   193,   193,   193,   193,   173,   174,
     167,   -82,   174,   -83,   168,   149,   173,   152,   -52,   -52,
     -52,   -52,   -52,   -52,   118,   168,   172,   218,   168,   194,
     219,   229,   174,   -61,   -61,   -61,   -61,   -61,   -61,    82,
     187,   230,   173,   236,   237,   188,   -52,   167,   168,   240,
      10,   -36,   167,   167,   241,   242,   243,    23,   260,   127,
     247,   -61,   253,   194,   265,   266,   -35,   270,     0,   273,
     174,   174,   174,   174,   194,    53,     0,     0,     0,   188,
       0,   194,   194,   194,   194,   174,   168,   168,   250,     0,
     188,     0,   187,   174,     0,     0,     0,   188,   188,   256,
     164,   168,   166,     0,     0,     0,     0,   167,     0,   168,
       0,     0,   -45,   -45,   105,   106,   -45,   -45,   167,   174,
       0,   167,     0,    98,   -47,   -47,   -47,   -47,   -47,   -47,
     184,     0,   186,     0,     0,   168,     0,   164,   187,   166,
     -45,   167,   164,   164,   166,   166,     0,     0,     0,   155,
     156,   157,   -47,   113,   121,   158,     0,   159,     0,     0,
     116,     0,     0,   160,     0,   122,   124,     0,     0,     0,
       0,     0,   187,   161,   162,     0,     0,   163,     0,   167,
     249,     0,   184,   187,   186,     0,     0,     0,     0,     0,
     187,   255,     0,     0,   167,     0,     0,   164,     0,   166,
       0,     0,   167,     0,     0,   145,     0,   147,     0,     0,
     166,   164,     0,   166,     0,     0,     0,     0,     0,    36,
     212,    37,    38,    39,    40,     0,     0,    41,   167,    42,
     186,   164,     0,   166,   220,    43,    44,     0,    45,    46,
       0,    47,    48,    49,     0,    50,    51,     0,     0,    52,
       0,     0,     0,   154,   231,   155,   156,   157,     0,     0,
     123,   158,   184,   159,   186,     0,     0,     0,     0,   160,
       0,   166,     0,   184,     0,   186,     0,     0,     0,   161,
     162,     0,   186,   163,   164,   113,   166,     0,     0,     0,
       0,     0,   164,     0,   166,     0,   113,     0,     0,     0,
     -52,   -52,   -52,   -52,   -52,   -52,   244,   258,     0,   -31,
       0,   -31,   -31,   -31,   -31,   212,     0,   -31,   164,   -31,
     166,   214,   -52,     0,     0,   -31,   -31,   148,   -31,   -31,
       0,   -31,   -31,   -31,     0,   -31,   -31,   268,     0,   -31,
       0,   212,     0,   -31,   -31,   -25,     0,   -25,   -25,   -25,
     -25,     0,     0,   -25,     0,   -25,     0,     0,     0,     0,
       0,   -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,   -25,
       0,   -25,   -25,     0,     0,   -25,     0,     0,     0,   -25,
     -25,   -17,     0,   -17,   -17,   -17,   -17,     0,     0,   -17,
       0,   -17,     0,     0,     0,     0,     0,   -17,   -17,   -17,
     -17,   -17,     0,   -17,   -17,   -17,     0,   -17,   -17,     0,
       0,   -17,     0,     0,     0,   -17,   -17,   -18,     0,   -18,
     -18,   -18,   -18,     0,     0,   -18,     0,   -18,     0,     0,
       0,     0,     0,   -18,   -18,   -18,   -18,   -18,     0,   -18,
     -18,   -18,     0,   -18,   -18,     0,     0,   -18,     0,     0,
       0,   -18,   -18,   -19,     0,   -19,   -19,   -19,   -19,     0,
       0,   -19,     0,   -19,     0,     0,     0,     0,     0,   -19,
     -19,   -19,   -19,   -19,     0,   -19,   -19,   -19,     0,   -19,
     -19,     0,     0,   -19,     0,     0,     0,   -19,   -19,   -20,
       0,   -20,   -20,   -20,   -20,     0,     0,   -20,     0,   -20,
       0,     0,     0,     0,     0,   -20,   -20,   -20,   -20,   -20,
       0,   -20,   -20,   -20,     0,   -20,   -20,     0,     0,   -20,
       0,     0,     0,   -20,   -20,   -24,     0,   -24,   -24,   -24,
     -24,     0,     0,   -24,     0,   -24,     0,     0,     0,     0,
       0,   -24,   -24,   -24,   -24,   -24,     0,   -24,   -24,   -24,
       0,   -24,   -24,     0,     0,   -24,     0,     0,     0,   -24,
     -24,   -73,     0,   -73,   -73,   -73,   -73,     0,     0,   -73,
       0,   -73,     0,     0,     0,     0,     0,   -73,   -73,   -73,
     -73,   -73,     0,   -73,   -73,   -73,     0,   -73,   -73,     0,
       0,   -73,     0,     0,     0,   -73,   -73,   -22,     0,   -22,
     -22,   -22,   -22,     0,     0,   -22,     0,   -22,     0,     0,
       0,     0,     0,   -22,   -22,   -22,   -22,   -22,     0,   -22,
     -22,   -22,     0,   -22,   -22,     0,     0,   -22,     0,     0,
       0,   -22,   -22,   -23,     0,   -23,   -23,   -23,   -23,     0,
       0,   -23,     0,   -23,     0,     0,     0,     0,     0,   -23,
     -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,     0,   -23,
     -23,     0,     0,   -23,     0,     0,     0,   -23,   -23,   -21,
       0,   -21,   -21,   -21,   -21,     0,     0,   -21,     0,   -21,
       0,     0,     0,     0,     0,   -21,   -21,   -21,   -21,   -21,
       0,   -21,   -21,   -21,     0,   -21,   -21,     0,     0,   -21,
       0,     0,     0,   -21,   -21,   -34,     0,   -34,   -34,   -34,
     -34,     0,     0,   -34,     0,   -34,     0,     0,     0,     0,
       0,   -34,   -34,   -34,   -34,   -34,     0,   -34,   -34,   -34,
       0,   -34,   -34,     0,     0,   -34,     0,     0,     0,   -34,
     -34,   -26,     0,   -26,   -26,   -26,   -26,     0,     0,   -26,
       0,   -26,     0,     0,     0,     0,     0,   -26,   -26,   -26,
     -26,   -26,     0,   -26,   -26,   -26,     0,   -26,   -26,     0,
       0,   -26,     0,     0,     0,   -26,   -26,   -31,     0,   -31,
     -31,   -31,   -31,     0,     0,   -31,     0,   -31,     0,     0,
       0,     0,     0,   -31,   -31,   269,   -31,   -31,     0,   -31,
     -31,   -31,     0,   -31,   -31,     0,     0,   -31,     0,     0,
       0,   -31,   -31,   -32,     0,   -32,   -32,   -32,   -32,     0,
       0,   -32,     0,   -32,     0,     0,     0,     0,     0,   -32,
     -32,   -32,   -32,   -32,     0,   -32,   -32,   -32,     0,   -32,
     -32,     0,     0,   -32,     0,     0,     0,   -32,   -32,   -33,
       0,   -33,   -33,   -33,   -33,     0,     0,   -33,     0,   -33,
       0,     0,     0,     0,     0,   -33,   -33,   -33,   -33,   -33,
       0,   -33,   -33,   -33,     0,   -33,   -33,     0,     0,   -33,
       0,     0,     0,   -33,   -33,   -30,     0,   -30,   -30,   -30,
     -30,     0,     0,   -30,     0,   -30,     0,     0,     0,     0,
       0,   -30,   -30,     0,   -30,   -30,     0,   -30,   -30,   -30,
       0,   -30,   -30,     0,     0,   -30,     0,     0,     0,   -30,
     -30,   -28,     0,   -28,   -28,   -28,   -28,     0,     0,   -28,
       0,   -28,     0,     0,     0,     0,     0,   -28,   -28,     0,
     -28,   -28,     0,   -28,   -28,   -28,     0,   -28,   -28,     0,
       0,   -28,     0,     0,     0,   -28,    33,   -25,     0,   -25,
     -25,   -25,   -25,     0,     0,   -25,     0,   -25,     0,     0,
       0,     0,     0,   -25,   -25,     0,   -25,   -25,     0,   -25,
     -25,   -25,     0,   -25,   -25,     0,     0,   -25,     0,     0,
       0,   -25,   -25,   -29,     0,   -29,   -29,   -29,   -29,     0,
       0,   -29,     0,   -29,     0,     0,     0,     0,     0,   -29,
     -29,     0,   -29,   -29,     0,   -29,   -29,   -29,     0,   -29,
     -29,     0,     0,   -29,     0,     0,     0,   -29,   -29,   -17,
       0,   -17,   -17,   -17,   -17,     0,     0,   -17,     0,   -17,
       0,     0,     0,     0,     0,   -17,   -17,     0,   -17,   -17,
       0,   -17,   -17,   -17,     0,   -17,   -17,     0,     0,   -17,
       0,     0,     0,   -17,   -17,   -18,     0,   -18,   -18,   -18,
     -18,     0,     0,   -18,     0,   -18,     0,     0,     0,     0,
       0,   -18,   -18,     0,   -18,   -18,     0,   -18,   -18,   -18,
       0,   -18,   -18,     0,     0,   -18,     0,     0,     0,   -18,
     -18,   -19,     0,   -19,   -19,   -19,   -19,     0,     0,   -19,
       0,   -19,     0,     0,     0,     0,     0,   -19,   -19,     0,
     -19,   -19,     0,   -19,   -19,   -19,     0,   -19,   -19,     0,
       0,   -19,     0,     0,     0,   -19,   -19,   -20,     0,   -20,
     -20,   -20,   -20,     0,     0,   -20,     0,   -20,     0,     0,
       0,     0,     0,   -20,   -20,     0,   -20,   -20,     0,   -20,
     -20,   -20,     0,   -20,   -20,     0,     0,   -20,     0,     0,
       0,   -20,   -20,   -24,     0,   -24,   -24,   -24,   -24,     0,
       0,   -24,     0,   -24,     0,     0,     0,     0,     0,   -24,
     -24,     0,   -24,   -24,     0,   -24,   -24,   -24,     0,   -24,
     -24,     0,     0,   -24,     0,     0,     0,   -24,   -24,   -73,
       0,   -73,   -73,   -73,   -73,     0,     0,   -73,     0,   -73,
       0,     0,     0,     0,     0,   -73,   -73,     0,   -73,   -73,
       0,   -73,   -73,   -73,     0,   -73,   -73,     0,     0,   -73,
       0,     0,     0,   -73,   -73,   -22,     0,   -22,   -22,   -22,
     -22,     0,     0,   -22,     0,   -22,     0,     0,     0,     0,
       0,   -22,   -22,     0,   -22,   -22,     0,   -22,   -22,   -22,
       0,   -22,   -22,     0,     0,   -22,     0,     0,     0,   -22,
     -22,   -23,     0,   -23,   -23,   -23,   -23,     0,     0,   -23,
       0,   -23,     0,     0,     0,     0,     0,   -23,   -23,     0,
     -23,   -23,     0,   -23,   -23,   -23,     0,   -23,   -23,     0,
       0,   -23,     0,     0,     0,   -23,   -23,   -21,     0,   -21,
     -21,   -21,   -21,     0,     0,   -21,     0,   -21,     0,     0,
       0,     0,     0,   -21,   -21,     0,   -21,   -21,     0,   -21,
     -21,   -21,     0,   -21,   -21,     0,     0,   -21,     0,     0,
       0,   -21,   -21,   -34,     0,   -34,   -34,   -34,   -34,     0,
       0,   -34,     0,   -34,     0,     0,     0,     0,     0,   -34,
     -34,     0,   -34,   -34,     0,   -34,   -34,   -34,     0,   -34,
     -34,     0,     0,   -34,     0,     0,     0,   -34,   -34,   -32,
       0,   -32,   -32,   -32,   -32,     0,     0,   -32,     0,   -32,
       0,     0,     0,     0,     0,   -32,   -32,     0,   -32,   -32,
       0,   -32,   -32,   -32,     0,   -32,   -32,     0,     0,   -32,
       0,     0,     0,   -32,   -32,   -33,     0,   -33,   -33,   -33,
     -33,     0,     0,   -33,     0,   -33,     0,     0,     0,     0,
       0,   -33,   -33,     0,   -33,   -33,     0,   -33,   -33,   -33,
       0,   -33,   -33,     0,     0,   -33,     0,     0,     0,   -33,
     -33,   -28,     0,   -28,   -28,   -28,   -28,     0,     0,   -28,
       0,   -28,     0,     0,     0,     0,     0,   -28,   -28,     0,
     -28,   -28,     0,   -28,   -28,   -28,     0,   -28,   -28,     0,
       0,   -28,     0,     0,     0,   -28,   245,   -28,     0,   -28,
     -28,   -28,   -28,     0,     0,   -28,     0,   -28,     0,     0,
       0,     0,     0,   -28,   -28,     0,   -28,   -28,     0,   -28,
     -28,   -28,     0,   -28,   -28,     0,     0,   -28,     0,     0,
       0,   -28,   261,   -26,     0,   -26,   -26,   -26,   -26,     0,
       0,   -26,     0,   -26,     0,     0,     0,     0,     0,   -26,
     -26,     0,   -26,   -26,     0,   -26,   -26,   -26,     0,   -26,
     -26,     0,     0,   -26,     0,     0,     0,   -26,   -26,   -27,
       0,   -27,   -27,   -27,   -27,     0,     0,   -27,     0,   -27,
       0,     0,     0,     0,     0,   -27,   -27,     0,   -27,   -27,
       0,   -27,   -27,   -27,     0,   -27,   -27,     0,     0,   -27,
       0,     0,    -7,   -27,    -7,    -7,    -7,    -7,     0,     0,
      -7,     0,    -7,     0,     0,     0,     0,     0,    -7,    -7,
       0,    -7,    -7,     0,    -7,    -7,    -7,     0,    -7,    -7,
       0,     0,    -7,     0,     0,    -8,    -7,    -8,    -8,    -8,
      -8,     0,     0,    -8,     0,    -8,     0,     0,     0,     0,
       0,    -8,    -8,     0,    -8,    -8,     0,    -8,    -8,    -8,
       0,    -8,    -8,     0,   197,    -8,    37,    38,    39,    -8,
       0,     0,    41,     0,    42,     0,     0,     0,     0,     0,
      43,   198,     0,   199,   200,     0,    47,    48,    49,     0,
      50,    51,     0,    36,    52,    37,    38,    39,   201,     0,
       0,    41,     0,    42,     0,     0,     0,     0,     0,    43,
      44,     0,    45,    46,     0,    47,    48,    49,     0,    50,
      51,     0,     0,    52,    37,    38,    87,   154,     0,     0,
      41,     0,    42,    37,    38,    91,     0,     0,    43,    41,
       0,    42,     0,     0,     0,     0,     0,    43,    50,    51,
       0,     0,    52,     0,   155,   156,   157,    50,    51,     0,
     158,    52,   159,    37,    38,   111,     0,     0,   160,    41,
       0,    42,     0,     0,     0,     0,     0,    43,   161,   162,
       0,     0,   163,     0,   175,   176,   177,    50,    51,     0,
     178,    52,   179,   155,   156,   211,     0,     0,   180,   158,
       0,   159,     0,     0,     0,     0,     0,   160,   181,   182,
       0,     0,   183,     0,   -48,   -48,   -48,   161,   162,     0,
     -48,   163,   -48,   -49,   -49,   -49,     0,     0,     0,   -49,
       0,   -49,     0,     0,     0,   -51,   -51,   -51,   -48,   -48,
       0,   -51,   -48,   -51,   -50,   -50,   -50,   -49,   -49,     0,
     -50,   -49,   -50,     0,     0,     0,   155,   156,   157,   -51,
     -51,     0,   158,   -51,   159,   175,   176,   177,   -50,   -50,
       0,   178,   -50,   179,   -53,   -53,   -53,   -53,   -53,   -53,
     161,   162,     0,     0,   163,     0,     0,     0,     0,   181,
     182,     0,     0,   183,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,   -53,   -56,   -56,   -56,   -56,   -56,   -56,   -77,
     -77,   -77,   -77,   -77,   -77,   -78,   -78,   -78,   -78,   -78,
     -78,     0,   -55,   -58,   -58,   -58,   -58,   -58,   -58,     0,
       0,   -56,     0,     0,     0,     0,     0,   -77,     0,     0,
       0,     0,     0,   -78,   -60,   -60,   -60,   -60,   -60,   -60,
       0,   -58,   -80,   -80,   -80,   -80,   -80,   -80,   -81,   -81,
     -81,   -81,   -81,   -81,   -54,   -54,   -54,   -54,   -54,   -54,
       0,     0,   -60,   -44,   -44,   105,   106,   -44,   -44,     0,
     -80,     0,     0,     0,     0,     0,   -81,     0,     0,     0,
       0,     0,   -54,   -46,   -46,   -46,   -46,   -46,   -46,     0,
       0,   -44,   -62,   -62,   -62,   -62,   -62,   -62,     0,     0,
     -52,   -52,   -52,   -52,   -52,   -52,     0,     0,     0,     0,
       0,   -46,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
     -62,   225,   -52,     0,     0,     0,     0,   -52,   -59,   -59,
     -59,   -59,   -59,   -59,   -57,     0,     0,     0,     0,   -57,
     -61,   -61,   -61,   -61,   -61,   -61,     0,     0,     0,     0,
     -59,     0,     0,     0,     0,   -59,   -45,   -45,   105,   106,
     -45,   -45,   -61,     0,     0,     0,     0,   -61,   -47,   -47,
     -47,   -47,   -47,   -47,     0,     0,     0,     0,   -45,     0,
       0,     0,     0,   -45,   -53,   -53,   -53,   -53,   -53,   -53,
     -47,     0,     0,     0,     0,   -47,   -55,   -55,   -55,   -55,
     -55,   -55,     0,     0,     0,     0,   -53,     0,     0,     0,
       0,   -53,   -56,   -56,   -56,   -56,   -56,   -56,   -55,     0,
       0,     0,     0,   -55,   -77,   -77,   -77,   -77,   -77,   -77,
       0,     0,     0,     0,   -56,     0,     0,     0,     0,   -56,
     -78,   -78,   -78,   -78,   -78,   -78,   -77,     0,     0,     0,
       0,   -77,   -58,   -58,   -58,   -58,   -58,   -58,     0,     0,
       0,     0,   -78,     0,     0,     0,     0,   -78,   -60,   -60,
     -60,   -60,   -60,   -60,   -58,     0,     0,     0,     0,   -58,
     -80,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,     0,
     -60,     0,     0,     0,     0,   -60,   -81,   -81,   -81,   -81,
     -81,   -81,   -80,     0,     0,     0,     0,   -80,   -54,   -54,
     -54,   -54,   -54,   -54,     0,     0,     0,     0,   -81,     0,
       0,     0,     0,   -81,   -44,   -44,   105,   106,   -44,   -44,
     -54,     0,     0,     0,     0,   -54,   -46,   -46,   -46,   -46,
     -46,   -46,     0,     0,     0,     0,   -44,     0,     0,     0,
       0,   -44,   -62,   -62,   -62,   -62,   -62,   -62,   -46,     0,
       0,     0,     0,   -46,   -52,   -52,   -52,   -52,   -52,   -52,
       0,     0,     0,     0,   -62,     0,     0,     0,     0,   -62,
       0,     0,     0,     0,     0,   214,   -52,   -57,   -57,   -57,
     -57,   -57,   -57,   -59,   -59,   -59,   -59,   -59,   -59,   -61,
     -61,   -61,   -61,   -61,   -61,     0,     0,     0,     0,   -57,
       0,     0,     0,     0,     0,   -59,     0,     0,     0,     0,
       0,   -61,   -45,   -45,   105,   106,   -45,   -45,   -47,   -47,
     -47,   -47,   -47,   -47,   -53,   -53,   -53,   -53,   -53,   -53,
       0,     0,     0,     0,   -45,     0,     0,     0,     0,     0,
     -47,     0,     0,     0,     0,     0,   -53,   -55,   -55,   -55,
     -55,   -55,   -55,   -56,   -56,   -56,   -56,   -56,   -56,   -77,
     -77,   -77,   -77,   -77,   -77,     0,     0,     0,     0,   -55,
       0,     0,     0,     0,     0,   -56,     0,     0,     0,     0,
       0,   -77,   -78,   -78,   -78,   -78,   -78,   -78,   -58,   -58,
     -58,   -58,   -58,   -58,   -60,   -60,   -60,   -60,   -60,   -60,
       0,     0,     0,     0,   -78,     0,     0,     0,     0,     0,
     -58,     0,     0,     0,     0,     0,   -60,   -80,   -80,   -80,
     -80,   -80,   -80,   -81,   -81,   -81,   -81,   -81,   -81,   -54,
     -54,   -54,   -54,   -54,   -54,     0,     0,     0,     0,   -80,
       0,     0,     0,     0,     0,   -81,     0,     0,     0,     0,
       0,   -54,   -44,   -44,   105,   106,   -44,   -44,   -46,   -46,
     -46,   -46,   -46,   -46,   -62,   -62,   -62,   -62,   -62,   -62,
       0,     0,     0,     0,   -44,     0,     0,     0,     0,     0,
     -46,     0,     0,     0,     0,     0,   -62
};

static const yytype_int16 yycheck[] =
{
      34,   135,    34,    21,   154,   167,    43,     6,    14,    15,
      28,     5,    46,     7,   148,    52,    34,   168,   152,    34,
       3,     4,    10,    11,    34,   187,    14,    15,     0,    14,
      34,    34,    38,    32,     6,     6,    14,   188,    14,    34,
       3,     4,     5,    52,    34,    82,     9,    81,    11,     0,
      38,   201,    89,    38,    17,    14,    90,    94,    95,    52,
      38,   214,    38,   100,    27,    28,    10,    11,    31,    32,
      14,    15,   225,    82,    37,    31,    31,    14,    15,    38,
      89,    35,    38,    38,   118,    94,    95,   249,    14,    82,
      14,    14,    15,   255,    38,    32,    89,   134,   107,   250,
      37,    94,    95,    14,    14,   256,    32,     5,    32,    32,
      14,    37,   149,    37,   148,   149,   148,    32,   152,    32,
     152,    32,    32,   160,    37,   134,   163,    37,    32,    14,
     148,   265,    14,   148,   152,   269,     5,   152,   148,   273,
     149,   134,   152,   180,   148,   148,   183,    32,   152,   152,
      32,   160,    37,   148,   163,    52,   149,   152,   148,     6,
      32,     5,   152,     7,    10,    11,   200,   160,    14,    15,
     163,   180,     3,     4,   183,    14,     5,   214,    10,    11,
      12,    13,    14,    15,   221,    82,    32,   180,   225,    31,
     183,    37,    89,    32,     0,   232,    32,    94,    95,   236,
       6,    37,     0,   237,    32,   214,    38,   244,     6,    37,
     244,     0,   221,   222,   223,   224,   225,     6,     5,    31,
       7,   214,    31,   232,   233,   234,   235,   236,   221,   222,
     223,   224,   225,   270,    31,   244,   270,   134,     0,   232,
     233,   234,   235,   236,     6,    10,    11,    31,    52,    14,
      15,   244,   149,    10,    11,    12,    13,    14,    15,    16,
       5,   270,     0,   160,    52,     0,   163,    32,     6,    26,
       0,     6,    29,    30,    31,    38,     6,   270,    82,    32,
       5,    38,    32,   180,    37,    89,   183,    37,    10,    11,
      94,    95,    14,    15,    82,    10,    11,    12,    13,    14,
      15,    89,     0,     0,     3,     4,    94,    95,     6,     6,
      32,    38,    38,    32,    32,    37,    31,   214,    37,    37,
       5,    38,     7,    38,   221,   222,   223,   224,   225,    32,
     134,    38,    38,    38,    37,   232,   233,   234,   235,   236,
       5,    52,    38,    32,    38,   149,   134,   244,    37,    10,
      11,    12,    13,    14,    15,    16,   160,    52,    38,   163,
      38,   149,    10,    11,    12,    13,    14,    15,    38,    32,
      31,    82,   160,   270,    37,   163,   180,    38,    89,   183,
       3,     4,     5,    94,    95,     5,     9,    82,    11,    32,
      38,    38,   180,    38,    89,   183,    32,    38,    32,    94,
      95,    32,    10,    11,    27,    28,    14,    15,    31,   104,
     214,    32,     5,    32,    32,     5,     5,   221,   222,   223,
     224,   225,    38,   134,    32,    38,   214,    38,   232,   233,
     234,   235,   236,   221,   222,   223,   224,   225,   149,   134,
     244,    38,    38,    38,   232,   233,   234,   235,   236,   160,
      52,    38,   163,    38,   149,    38,   244,    32,    10,    11,
      12,    13,    14,    15,    16,   160,   270,     5,   163,   180,
       5,     5,   183,    10,    11,    12,    13,    14,    15,    31,
      82,     5,   270,    31,    31,   180,    38,    89,   183,    38,
       3,    32,    94,    95,    38,    38,    38,    17,    38,   101,
      32,    38,    32,   214,    32,    38,    32,    38,    -1,    32,
     221,   222,   223,   224,   225,    34,    -1,    -1,    -1,   214,
      -1,   232,   233,   234,   235,   236,   221,   222,   223,    -1,
     225,    -1,   134,   244,    -1,    -1,    -1,   232,   233,   234,
      52,   236,    52,    -1,    -1,    -1,    -1,   149,    -1,   244,
      -1,    -1,    10,    11,    12,    13,    14,    15,   160,   270,
      -1,   163,    -1,    52,    10,    11,    12,    13,    14,    15,
      82,    -1,    82,    -1,    -1,   270,    -1,    89,   180,    89,
      38,   183,    94,    95,    94,    95,    -1,    -1,    -1,     3,
       4,     5,    38,    82,     8,     9,    -1,    11,    -1,    -1,
      89,    -1,    -1,    17,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,   214,    27,    28,    -1,    -1,    31,    -1,   221,
     222,    -1,   134,   225,   134,    -1,    -1,    -1,    -1,    -1,
     232,   233,    -1,    -1,   236,    -1,    -1,   149,    -1,   149,
      -1,    -1,   244,    -1,    -1,   134,    -1,   136,    -1,    -1,
     160,   163,    -1,   163,    -1,    -1,    -1,    -1,    -1,     1,
     149,     3,     4,     5,     6,    -1,    -1,     9,   270,    11,
     180,   183,    -1,   183,   163,    17,    18,    -1,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    -1,    35,   183,     3,     4,     5,    -1,    -1,
       8,     9,   214,    11,   214,    -1,    -1,    -1,    -1,    17,
      -1,   221,    -1,   225,    -1,   225,    -1,    -1,    -1,    27,
      28,    -1,   232,    31,   236,   214,   236,    -1,    -1,    -1,
      -1,    -1,   244,    -1,   244,    -1,   225,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    15,    16,   236,    -1,     1,
      -1,     3,     4,     5,     6,   244,    -1,     9,   270,    11,
     270,    31,    32,    -1,    -1,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,   266,    -1,    31,
      -1,   270,    -1,    35,    36,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,
      36,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
      -1,    35,    36,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,
      36,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
      -1,    35,    36,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,
      36,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
      -1,    35,    36,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,
      36,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
      -1,    35,    36,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,
      36,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
      -1,    35,    36,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,
      36,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
      -1,    35,    36,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,
      36,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
      -1,    35,    36,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,     1,    35,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,     1,    35,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    23,    24,    25,
      -1,    27,    28,    -1,     1,    31,     3,     4,     5,    35,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,     1,    31,     3,     4,     5,    35,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,     3,     4,     5,    35,    -1,    -1,
       9,    -1,    11,     3,     4,     5,    -1,    -1,    17,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    27,    28,
      -1,    -1,    31,    -1,     3,     4,     5,    27,    28,    -1,
       9,    31,    11,     3,     4,     5,    -1,    -1,    17,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    27,    28,
      -1,    -1,    31,    -1,     3,     4,     5,    27,    28,    -1,
       9,    31,    11,     3,     4,     5,    -1,    -1,    17,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    27,    28,
      -1,    -1,    31,    -1,     3,     4,     5,    27,    28,    -1,
       9,    31,    11,     3,     4,     5,    -1,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,     3,     4,     5,    27,    28,
      -1,     9,    31,    11,     3,     4,     5,    27,    28,    -1,
       9,    31,    11,    -1,    -1,    -1,     3,     4,     5,    27,
      28,    -1,     9,    31,    11,     3,     4,     5,    27,    28,
      -1,     9,    31,    11,    10,    11,    12,    13,    14,    15,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    31,    10,    11,    12,    13,    14,    15,
      -1,    -1,    38,    10,    11,    12,    13,    14,    15,    10,
      11,    12,    13,    14,    15,    10,    11,    12,    13,    14,
      15,    -1,    38,    10,    11,    12,    13,    14,    15,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    38,    10,    11,    12,    13,    14,    15,
      -1,    38,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    10,    11,    12,    13,    14,    15,
      -1,    -1,    38,    10,    11,    12,    13,    14,    15,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    38,    10,    11,    12,    13,    14,    15,    -1,
      -1,    38,    10,    11,    12,    13,    14,    15,    -1,    -1,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    38,    10,    11,    12,    13,    14,    15,    -1,    -1,
      38,    31,    32,    -1,    -1,    -1,    -1,    37,    10,    11,
      12,    13,    14,    15,    32,    -1,    -1,    -1,    -1,    37,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,
      14,    15,    32,    -1,    -1,    -1,    -1,    37,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    37,    10,    11,    12,    13,    14,    15,
      32,    -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    37,    10,    11,    12,    13,    14,    15,    32,    -1,
      -1,    -1,    -1,    37,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    37,
      10,    11,    12,    13,    14,    15,    32,    -1,    -1,    -1,
      -1,    37,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    37,    10,    11,
      12,    13,    14,    15,    32,    -1,    -1,    -1,    -1,    37,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,
      14,    15,    32,    -1,    -1,    -1,    -1,    37,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    37,    10,    11,    12,    13,    14,    15,
      32,    -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    37,    10,    11,    12,    13,    14,    15,    32,    -1,
      -1,    -1,    -1,    37,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    31,    32,    10,    11,    12,
      13,    14,    15,    10,    11,    12,    13,    14,    15,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    32,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    32,    10,    11,    12,
      13,    14,    15,    10,    11,    12,    13,    14,    15,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    32,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    32,    10,    11,    12,
      13,    14,    15,    10,    11,    12,    13,    14,    15,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    32,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    47,    48,    49,    50,    51,     5,     7,     0,
      49,    31,    38,     5,     6,    52,    53,    31,    38,     5,
       7,    32,    37,    52,     5,    35,    55,     6,    32,    57,
       5,     7,    55,    36,    56,     5,     1,     3,     4,     5,
       6,     9,    11,    17,    18,    20,    21,    23,    24,    25,
      27,    28,    31,    50,    54,    55,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    70,    71,    72,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    16,    31,     5,     7,     3,     4,     5,    64,    31,
      31,     5,    61,    31,    31,    31,     5,     5,    62,    38,
      14,    15,    10,    11,    68,    12,    13,    69,    38,    38,
      38,     5,    61,    62,    73,     5,    62,    61,    16,    38,
       5,     8,    62,     8,    62,    32,    64,    66,    67,    70,
      26,    29,    30,    32,    37,    32,    38,    32,    32,    32,
      32,    32,     5,     5,     5,    62,    54,    62,    19,    38,
      54,    61,    32,    54,    35,     3,     4,     5,     9,    11,
      17,    27,    28,    31,    63,    64,    65,    66,    67,    70,
      71,    72,    80,    82,    83,     3,     4,     5,     9,    11,
      17,    27,    28,    31,    63,    64,    65,    66,    67,    70,
      71,    72,    80,    82,    83,    38,    38,     1,    18,    20,
      21,    35,    55,    58,    59,    60,    61,    74,    77,    78,
      79,     5,    62,    57,    31,     3,     4,    64,     5,     5,
      62,    14,    15,    68,    69,    31,     3,     4,    64,     5,
       5,    62,    14,    15,    68,    69,    31,    31,    61,    57,
      38,    38,    38,    38,    16,    36,    73,    32,    64,    66,
      67,    70,    73,    32,    64,    66,    67,    70,    62,    61,
      38,    36,    61,    32,    32,    32,    38,    54,    62,    19,
      38,    54,    61,    32,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    56,    56,    57,
      57,    58,    58,    59,    60,    61,    61,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    71,    71,    71,
      71,    71,    72,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    78,    79,    79,    79,    80,    80,    81,
      82,    83,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     4,     6,
       7,     1,     0,     4,     5,     2,     3,     1,     1,     1,
       1,     2,     2,     2,     1,     1,     3,     2,     0,     3,
       0,     5,     7,     9,     3,     3,     1,     1,     3,     1,
       2,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     2,     1,
       2,     1,     4,     3,     1,     0,     1,     1,     4,     4,
       4,     4,     4,     2,     1,     1,     1,     1,     1,     5,
       2,     2,     5,     5
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
#line 171 "./src/syntax.y"
                    {}
#line 2150 "./src/syntax.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 175 "./src/syntax.y"
                                {}
#line 2156 "./src/syntax.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 176 "./src/syntax.y"
                  {}
#line 2162 "./src/syntax.tab.c"
    break;

  case 5: /* declaration: varDeclaration  */
#line 180 "./src/syntax.y"
                   {}
#line 2168 "./src/syntax.tab.c"
    break;

  case 6: /* declaration: funcDeclaration  */
#line 181 "./src/syntax.y"
                      {}
#line 2174 "./src/syntax.tab.c"
    break;

  case 7: /* varDeclaration: TYPE ID DELIM_SEMICOLLON  */
#line 185 "./src/syntax.y"
                             {
        printf("%s %s %s\n", (yyvsp[-2].t_token).text, (yyvsp[-1].t_token).text, (yyvsp[0].t_token).text);
        createSymbol((yyvsp[-1].t_token).text, (yyvsp[-2].t_token).text, (yyvsp[-1].t_token).line, (yyvsp[-1].t_token).column); //line and column still not working
    }
#line 2183 "./src/syntax.tab.c"
    break;

  case 8: /* varDeclaration: TYPE LIST_TYPE ID DELIM_SEMICOLLON  */
#line 189 "./src/syntax.y"
                                         {
        char* temp;
        temp = (char*) malloc(sizeof((yyvsp[-3].t_token).text) + sizeof((yyvsp[-2].t_token).text) + 3);
        strcpy(temp, (yyvsp[-3].t_token).text);
        strcat(temp, " ");
        strcat(temp, (yyvsp[-2].t_token).text);
        printf("%s %s %s %s - %s\n", (yyvsp[-3].t_token).text, (yyvsp[-2].t_token).text, (yyvsp[-1].t_token).text, (yyvsp[0].t_token).text, temp);
        createSymbol((yyvsp[-1].t_token).text, temp, (yyvsp[-1].t_token).line, (yyvsp[-1].t_token).column); //line and column still not working
    }
#line 2197 "./src/syntax.tab.c"
    break;

  case 9: /* funcDeclaration: TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R bodyStatement  */
#line 215 "./src/syntax.y"
                                                                   {
        printf("%s %s %s %s \n", (yyvsp[-5].t_token).text, (yyvsp[-4].t_token).text, (yyvsp[-3].t_token).text, (yyvsp[-1].t_token).text);
        createSymbol((yyvsp[-4].t_token).text, (yyvsp[-5].t_token).text, (yyvsp[-4].t_token).line, (yyvsp[-4].t_token).column); //line and column still not working
    }
#line 2206 "./src/syntax.tab.c"
    break;

  case 10: /* funcDeclaration: TYPE LIST_TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R bodyStatement  */
#line 219 "./src/syntax.y"
                                                                               {
        char* temp;
        temp = (char*) malloc(sizeof((yyvsp[-6].t_token).text) + sizeof((yyvsp[-5].t_token).text) + 3);
        strcpy(temp, (yyvsp[-6].t_token).text);
        strcat(temp, " ");
        strcat(temp, (yyvsp[-5].t_token).text);
        printf("%s %s %s %s %s - %s\n", (yyvsp[-6].t_token).text, (yyvsp[-5].t_token).text, (yyvsp[-4].t_token).text, (yyvsp[-3].t_token).text, (yyvsp[-1].t_token).text, temp);
        createSymbol((yyvsp[-4].t_token).text, temp, (yyvsp[-4].t_token).line, (yyvsp[-4].t_token).column); //line and column still not working
    }
#line 2220 "./src/syntax.tab.c"
    break;

  case 11: /* parameters: parameterList  */
#line 231 "./src/syntax.y"
                  {}
#line 2226 "./src/syntax.tab.c"
    break;

  case 12: /* parameters: %empty  */
#line 232 "./src/syntax.y"
      {}
#line 2232 "./src/syntax.tab.c"
    break;

  case 13: /* parameterList: parameterList DELIM_COMMA TYPE ID  */
#line 236 "./src/syntax.y"
                                      {}
#line 2238 "./src/syntax.tab.c"
    break;

  case 14: /* parameterList: parameterList DELIM_COMMA TYPE LIST_TYPE ID  */
#line 237 "./src/syntax.y"
                                                  {}
#line 2244 "./src/syntax.tab.c"
    break;

  case 15: /* parameterList: TYPE ID  */
#line 238 "./src/syntax.y"
              {}
#line 2250 "./src/syntax.tab.c"
    break;

  case 16: /* parameterList: TYPE LIST_TYPE ID  */
#line 239 "./src/syntax.y"
                        {}
#line 2256 "./src/syntax.tab.c"
    break;

  case 17: /* statement: bodyStatement  */
#line 243 "./src/syntax.y"
                  {}
#line 2262 "./src/syntax.tab.c"
    break;

  case 18: /* statement: ifStatement  */
#line 244 "./src/syntax.y"
                  {}
#line 2268 "./src/syntax.tab.c"
    break;

  case 19: /* statement: loopStatement  */
#line 245 "./src/syntax.y"
                    {}
#line 2274 "./src/syntax.tab.c"
    break;

  case 20: /* statement: returnStatement  */
#line 246 "./src/syntax.y"
                      {}
#line 2280 "./src/syntax.tab.c"
    break;

  case 21: /* statement: listStatement DELIM_SEMICOLLON  */
#line 247 "./src/syntax.y"
                                     {}
#line 2286 "./src/syntax.tab.c"
    break;

  case 22: /* statement: writeOp DELIM_SEMICOLLON  */
#line 248 "./src/syntax.y"
                               {}
#line 2292 "./src/syntax.tab.c"
    break;

  case 23: /* statement: readOp DELIM_SEMICOLLON  */
#line 249 "./src/syntax.y"
                              {}
#line 2298 "./src/syntax.tab.c"
    break;

  case 24: /* statement: expressionStatement  */
#line 250 "./src/syntax.y"
                          {}
#line 2304 "./src/syntax.tab.c"
    break;

  case 25: /* statement: error  */
#line 251 "./src/syntax.y"
            {}
#line 2310 "./src/syntax.tab.c"
    break;

  case 26: /* bodyStatement: DELIM_CUR_BRACKET_L statementList DELIM_CUR_BRACKET_R  */
#line 255 "./src/syntax.y"
                                                          {}
#line 2316 "./src/syntax.tab.c"
    break;

  case 27: /* localDeclaration: localDeclaration varDeclaration  */
#line 263 "./src/syntax.y"
                                    {}
#line 2322 "./src/syntax.tab.c"
    break;

  case 28: /* localDeclaration: %empty  */
#line 264 "./src/syntax.y"
      {}
#line 2328 "./src/syntax.tab.c"
    break;

  case 29: /* statementList: statementList localDeclaration statement  */
#line 268 "./src/syntax.y"
                                             {}
#line 2334 "./src/syntax.tab.c"
    break;

  case 30: /* statementList: %empty  */
#line 269 "./src/syntax.y"
      {}
#line 2340 "./src/syntax.tab.c"
    break;

  case 31: /* ifStatement: IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R statement  */
#line 273 "./src/syntax.y"
                                                                                    {}
#line 2346 "./src/syntax.tab.c"
    break;

  case 32: /* ifStatement: IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R statement ELSE_KEY statement  */
#line 274 "./src/syntax.y"
                                                                                         {}
#line 2352 "./src/syntax.tab.c"
    break;

  case 33: /* loopStatement: FOR_KEY DELIM_PARENT_L expression DELIM_SEMICOLLON simpleExpression DELIM_SEMICOLLON expression DELIM_PARENT_R statement  */
#line 278 "./src/syntax.y"
                                                                                                                             {}
#line 2358 "./src/syntax.tab.c"
    break;

  case 34: /* returnStatement: RETURN_KEY expression DELIM_SEMICOLLON  */
#line 282 "./src/syntax.y"
                                           {}
#line 2364 "./src/syntax.tab.c"
    break;

  case 35: /* expression: ID ASSIGN_OP expression  */
#line 286 "./src/syntax.y"
                            {}
#line 2370 "./src/syntax.tab.c"
    break;

  case 36: /* expression: simpleExpression  */
#line 287 "./src/syntax.y"
                       {}
#line 2376 "./src/syntax.tab.c"
    break;

  case 37: /* simpleExpression: logicBinExpression  */
#line 296 "./src/syntax.y"
                       {}
#line 2382 "./src/syntax.tab.c"
    break;

  case 38: /* logicBinExpression: logicBinExpression LOGIC_OP logicUnExpression  */
#line 305 "./src/syntax.y"
                                                  {}
#line 2388 "./src/syntax.tab.c"
    break;

  case 39: /* logicBinExpression: logicUnExpression  */
#line 306 "./src/syntax.y"
                        {}
#line 2394 "./src/syntax.tab.c"
    break;

  case 40: /* logicUnExpression: EXCLA_OP logicUnExpression  */
#line 310 "./src/syntax.y"
                               {}
#line 2400 "./src/syntax.tab.c"
    break;

  case 41: /* logicUnExpression: binExpression  */
#line 311 "./src/syntax.y"
                    {}
#line 2406 "./src/syntax.tab.c"
    break;

  case 42: /* binExpression: binExpression BINARY_OP sumExpression  */
#line 319 "./src/syntax.y"
                                          {}
#line 2412 "./src/syntax.tab.c"
    break;

  case 43: /* binExpression: sumExpression  */
#line 320 "./src/syntax.y"
                    {}
#line 2418 "./src/syntax.tab.c"
    break;

  case 44: /* sumExpression: sumExpression sumOP mulExpression  */
#line 324 "./src/syntax.y"
                                      {}
#line 2424 "./src/syntax.tab.c"
    break;

  case 45: /* sumExpression: mulExpression  */
#line 325 "./src/syntax.y"
                    {}
#line 2430 "./src/syntax.tab.c"
    break;

  case 46: /* mulExpression: mulExpression mulOP factor  */
#line 329 "./src/syntax.y"
                               {}
#line 2436 "./src/syntax.tab.c"
    break;

  case 47: /* mulExpression: factor  */
#line 330 "./src/syntax.y"
             {}
#line 2442 "./src/syntax.tab.c"
    break;

  case 48: /* sumOP: PLUS_OP  */
#line 334 "./src/syntax.y"
            {}
#line 2448 "./src/syntax.tab.c"
    break;

  case 49: /* sumOP: MINUS_OP  */
#line 335 "./src/syntax.y"
               {}
#line 2454 "./src/syntax.tab.c"
    break;

  case 50: /* mulOP: MUL_OP  */
#line 339 "./src/syntax.y"
           {}
#line 2460 "./src/syntax.tab.c"
    break;

  case 51: /* mulOP: DIV_OP  */
#line 340 "./src/syntax.y"
             {}
#line 2466 "./src/syntax.tab.c"
    break;

  case 52: /* factor: ID  */
#line 344 "./src/syntax.y"
       {}
#line 2472 "./src/syntax.tab.c"
    break;

  case 53: /* factor: constant  */
#line 345 "./src/syntax.y"
               {}
#line 2478 "./src/syntax.tab.c"
    break;

  case 54: /* factor: DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 346 "./src/syntax.y"
                                                     {}
#line 2484 "./src/syntax.tab.c"
    break;

  case 55: /* factor: functionCall  */
#line 347 "./src/syntax.y"
                   {}
#line 2490 "./src/syntax.tab.c"
    break;

  case 56: /* factor: listExpression  */
#line 348 "./src/syntax.y"
                     {}
#line 2496 "./src/syntax.tab.c"
    break;

  case 57: /* constant: INT  */
#line 352 "./src/syntax.y"
        {}
#line 2502 "./src/syntax.tab.c"
    break;

  case 58: /* constant: MINUS_OP INT  */
#line 353 "./src/syntax.y"
                   {}
#line 2508 "./src/syntax.tab.c"
    break;

  case 59: /* constant: FLOAT  */
#line 354 "./src/syntax.y"
            {}
#line 2514 "./src/syntax.tab.c"
    break;

  case 60: /* constant: MINUS_OP FLOAT  */
#line 355 "./src/syntax.y"
                     {}
#line 2520 "./src/syntax.tab.c"
    break;

  case 61: /* constant: NULL_CONST  */
#line 356 "./src/syntax.y"
                 {}
#line 2526 "./src/syntax.tab.c"
    break;

  case 62: /* functionCall: ID DELIM_PARENT_L parametersPass DELIM_PARENT_R  */
#line 360 "./src/syntax.y"
                                                    {}
#line 2532 "./src/syntax.tab.c"
    break;

  case 63: /* parametersPass: parametersPass DELIM_COMMA simpleExpression  */
#line 364 "./src/syntax.y"
                                                {}
#line 2538 "./src/syntax.tab.c"
    break;

  case 64: /* parametersPass: simpleExpression  */
#line 365 "./src/syntax.y"
                       {}
#line 2544 "./src/syntax.tab.c"
    break;

  case 65: /* parametersPass: %empty  */
#line 366 "./src/syntax.y"
      {}
#line 2550 "./src/syntax.tab.c"
    break;

  case 66: /* writeOp: write  */
#line 370 "./src/syntax.y"
          {}
#line 2556 "./src/syntax.tab.c"
    break;

  case 67: /* writeOp: writeln  */
#line 371 "./src/syntax.y"
              {}
#line 2562 "./src/syntax.tab.c"
    break;

  case 68: /* write: OUTPUT_KEY DELIM_PARENT_L STRING DELIM_PARENT_R  */
#line 375 "./src/syntax.y"
                                                    {}
#line 2568 "./src/syntax.tab.c"
    break;

  case 69: /* write: OUTPUT_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 376 "./src/syntax.y"
                                                                {}
#line 2574 "./src/syntax.tab.c"
    break;

  case 70: /* writeln: OUTPUTLN_KEY DELIM_PARENT_L STRING DELIM_PARENT_R  */
#line 380 "./src/syntax.y"
                                                      {}
#line 2580 "./src/syntax.tab.c"
    break;

  case 71: /* writeln: OUTPUTLN_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 381 "./src/syntax.y"
                                                                  {}
#line 2586 "./src/syntax.tab.c"
    break;

  case 72: /* readOp: INPUT_KEY DELIM_PARENT_L ID DELIM_PARENT_R  */
#line 385 "./src/syntax.y"
                                               {}
#line 2592 "./src/syntax.tab.c"
    break;

  case 73: /* expressionStatement: expression DELIM_SEMICOLLON  */
#line 389 "./src/syntax.y"
                                {}
#line 2598 "./src/syntax.tab.c"
    break;

  case 74: /* listStatement: listAssign  */
#line 393 "./src/syntax.y"
               {}
#line 2604 "./src/syntax.tab.c"
    break;

  case 75: /* listStatement: listMap  */
#line 394 "./src/syntax.y"
              {}
#line 2610 "./src/syntax.tab.c"
    break;

  case 76: /* listStatement: listFilter  */
#line 395 "./src/syntax.y"
                 {}
#line 2616 "./src/syntax.tab.c"
    break;

  case 77: /* listExpression: listHeader  */
#line 399 "./src/syntax.y"
               {}
#line 2622 "./src/syntax.tab.c"
    break;

  case 78: /* listExpression: listTailDestructor  */
#line 401 "./src/syntax.y"
                         {}
#line 2628 "./src/syntax.tab.c"
    break;

  case 79: /* listAssign: ID ASSIGN_OP ID ASSIGN_LISTOP ID  */
#line 405 "./src/syntax.y"
                                     {}
#line 2634 "./src/syntax.tab.c"
    break;

  case 80: /* listHeader: HEADER_LISTOP ID  */
#line 409 "./src/syntax.y"
                     {}
#line 2640 "./src/syntax.tab.c"
    break;

  case 81: /* listTailDestructor: TAILDES_LISTOP ID  */
#line 417 "./src/syntax.y"
                      {}
#line 2646 "./src/syntax.tab.c"
    break;

  case 82: /* listMap: ID ASSIGN_OP ID MAP_LISTOP ID  */
#line 421 "./src/syntax.y"
                                  {}
#line 2652 "./src/syntax.tab.c"
    break;

  case 83: /* listFilter: ID ASSIGN_OP ID FILTER_LISTOP ID  */
#line 425 "./src/syntax.y"
                                     {}
#line 2658 "./src/syntax.tab.c"
    break;


#line 2662 "./src/syntax.tab.c"

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

#line 429 "./src/syntax.y"

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

    printTable();

    yylex_destroy();

    return 0;
}
