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
#include "scope.h"

extern int yylex();
extern int yylex_destroy();
extern int yyparse();
extern void yyerror(const char* s);
extern FILE* yyin;

//yynerrs //global variable counting errors


#line 90 "./src/syntax.tab.c"

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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4704

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  346

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
       0,   173,   173,   177,   178,   179,   180,   184,   185,   189,
     193,   219,   223,   235,   236,   240,   241,   242,   243,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   259,   267,
     268,   272,   273,   277,   278,   282,   286,   290,   291,   300,
     309,   310,   314,   315,   323,   324,   328,   329,   333,   334,
     338,   339,   343,   344,   348,   349,   350,   351,   352,   356,
     357,   358,   359,   360,   364,   368,   369,   370,   374,   375,
     379,   380,   384,   385,   389,   393,   397,   398,   399,   403,
     405,   409,   413,   421,   425,   429
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

#define YYPACT_NINF (-200)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3717,  2169,   985,  4073,    53,   145,  4088,    34,   551,   -20,
      -7,   664,    16,    31,    44,    23,    77,   918,  2202,    95,
    2239,  2272,  2305,  2338,  2371,  2404,  2437,  2470,  2503,    47,
      60,    -8,    12,     6,    42,  4094,  4102,  4108,  4123,    67,
      73,    79,    92,  2536,   115,  4137,   147,  4143,  4152,   157,
     160,   976,    14,   -26,   128,  4158,  4172,   198,    20,   918,
     664,  1020,   177,   170,    85,   162,  4187,  4193,   146,  2569,
    -200,  2606,  2639,  2672,   551,     5,   346,   585,     5,   771,
    4037,     5,  2705,  2738,  2771,  3991,   207,    69,    90,    -3,
    2804,    40,   217,   225,   664,  2837,   232,   233,   241,   242,
     243,  4201,  2870,  3750,    21,    62,  4207,  4222,   261,   271,
     272,  4236,  4007,   187,   251,   124,    -3,  2903,  3878,   551,
     246,   259,   262,   276,   277,   221,  3783,  2936,   280,   282,
     284,   137,   186,   286,   274,   301,   293,   120,   288,   289,
     323,   200,  2973,   234,   274,  3907,  4022,   300,   255,   334,
    3006,  3039,   308,   266,  3907,  3072,   817,  4491,  4485,  4497,
     159,   918,   336,   339,   918,    65,   100,   104,   321,  4520,
    4526,  4532,  4555,  4561,  4567,  4590,  4243,  4251,   730,  4257,
     249,  4007,   341,   342,   918,   150,   193,   144,   190,  4285,
    4291,  4297,  4325,  4331,  4337,  4365,  3105,   317,   325,   664,
    2202,  3141,  3177,  3213,  3249,   314,   320,   326,  3285,   347,
     506,   328,   344,   664,  2202,  1127,  1160,  1193,  1226,   349,
     354,   355,  1259,   357,  3816,   411,   340,  3849,    14,  4596,
    4602,   114,  4625,  4631,   352,   918,  4051,  4051,  4051,    14,
    4371,  4377,   219,  4405,  4411,   365,  4007,  4066,  4066,  4066,
     918,   664,   362,  3321,  3357,  3393,  3429,  3465,   918,   664,
     366,  3501,  1292,  1325,  1358,  1391,  4022,   267,  4637,   140,
     351,  4660,  4666,   269,  4417,   253,   206,  4445,  4451,   371,
     367,  3537,  3573,   375,   372,  1424,  1457,   377,  4672,  4457,
    3936,   551,  3878,   551,  1490,   384,   385,   664,  2202,  1526,
    1562,  1598,  1634,  1670,   379,   381,   391,  1706,   395,   397,
    1743,   399,   918,   664,   401,  3609,  3965,  1776,  1812,  1848,
    1884,  4022,  3878,  4022,   388,   407,  1920,  1956,  3645,   420,
    1993,   422,  3936,   551,  3965,  3878,  2026,   419,  3681,  2063,
    3936,  4022,  2096,   427,  3936,  2132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -200,  -200,  -200,   393,   358,  -200,   348,  -200,   634,   722,
    -200,  -199,    96,   116,   520,   -11,   620,   705,    -4,   755,
     550,   587,  -166,  -162,    22,   132,   230,  -185,   747,  -200,
    -200,   758,   778,   785,   337,  -200,   382,   480,  -200,  -200
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,   114,   115,    24,    25,
     103,    69,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    78,    81,    36,    37,    38,    88,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,   253,   237,   113,    58,    89,    74,   238,     2,     3,
      57,    59,    90,   166,     6,   261,     7,   176,   177,   178,
     -43,    75,   248,   179,    60,   180,   -41,   249,    66,   -14,
     -39,   181,    15,    16,   -42,   -40,    17,    55,    56,   170,
      86,   182,   183,   267,   -43,   184,   -67,    63,   186,    93,
     -41,   -67,    76,    77,   273,   166,   -45,   -45,   -42,   -40,
     166,   166,    64,   -54,   -54,   -54,   -54,   -54,   -54,    51,
     104,   116,    76,    77,   190,    65,   -44,   -44,   117,   235,
     -45,   170,    67,    86,    52,    73,   170,   170,   156,   157,
     158,   -54,   205,    97,   159,    70,   160,   -39,   -38,   315,
     -44,   -66,   161,   107,   237,    82,   -66,   219,   186,   238,
     248,   -68,   162,   163,   -41,   249,   164,   -69,   -43,   236,
     -33,   -33,   111,   -33,   -33,   -33,   -33,   112,   -42,   -33,
      83,   -33,   -41,    91,   190,   152,   -43,   -33,   -33,   145,
     -33,   -33,   166,   -33,   -33,   -33,   -42,   -33,   -33,   171,
      53,   -33,    54,    84,   -40,   -33,   -13,   231,   -43,   247,
     166,   135,   229,   230,   246,   156,   157,   158,   170,   -65,
      99,   159,   -40,   160,   -65,    96,   -43,   242,   101,   161,
     166,   -43,   -39,   170,   191,   -76,   170,   -39,   252,   162,
     163,   171,   132,   164,   133,   -77,   171,   171,   -78,   202,
      76,    77,   260,   190,   -45,   -45,   170,   -41,   -54,   -54,
     -54,   -54,   -54,   -54,   216,    95,    76,    77,   -17,   203,
     -44,   -44,   -45,   -17,   186,   -41,   139,   -45,   140,    52,
     -41,   269,   -18,   -42,   217,   186,   -54,   -18,   -44,   148,
     280,   149,   275,   -44,   191,   -37,   166,   172,   284,   118,
     190,   -42,   240,   241,   166,   287,   -42,   170,   170,   170,
     272,   190,   166,   119,   120,   121,   128,   -40,   190,   190,
     190,   278,   170,   122,   123,   124,   129,   130,   171,   304,
     170,   219,   192,   134,   -74,   -40,   314,   -15,   170,   172,
     -40,   141,   -15,   171,   172,   172,   171,   -70,   -16,   288,
     -71,   289,   325,   -16,   112,   205,   112,   143,   166,    18,
     329,   219,   331,   191,   -72,   -73,   171,   166,   -81,   166,
     -84,   304,   -85,   205,   219,   144,   146,   224,   147,   304,
     343,    76,    77,   304,   170,   -45,   -45,   166,   227,   153,
     154,   232,   192,   170,   233,   170,   243,   244,   250,   -50,
     -50,   -50,   254,   -45,   173,   -50,   251,   -50,   255,   258,
     191,    76,    77,   170,   256,   -44,   -44,   171,   171,   171,
     171,   191,   -38,   -50,   -50,   259,   172,   -50,   191,   191,
     191,   191,   171,   -44,   268,   257,   301,   262,   216,   193,
     171,   172,   263,   264,   172,   265,   173,   274,   171,   174,
     281,   173,   173,   290,   285,   291,   302,   292,   217,   -37,
     293,   192,   202,    71,   172,   312,   313,   317,   216,   318,
     332,   -54,   -54,   -54,   -54,   -54,   -54,   266,   301,   319,
     202,   216,   203,   320,   194,   321,   301,   323,   217,   326,
     301,   174,   228,   -54,   171,   333,   174,   174,   302,   193,
     203,   217,   334,   171,   335,   171,   302,   341,   192,   344,
     302,   126,     0,     0,   136,   172,   172,   172,   172,   192,
       0,     0,     0,   171,     0,     0,   192,   192,   192,   192,
     172,     0,     0,   173,     0,     0,     0,     0,   172,     0,
       0,     0,     0,     0,   194,     0,   172,   175,   173,     0,
       0,   173,     0,     0,     0,     0,   -27,   -27,     0,   -27,
     -27,   -27,   -27,     0,     0,   -27,     0,   -27,   193,     0,
       0,   173,     0,   -27,   -27,   -27,   -27,   -27,   174,   -27,
     -27,   -27,   195,   -27,   -27,     0,     0,   -27,     0,   175,
       0,   -27,   172,   174,   175,   175,   174,     0,     0,     0,
       0,   172,     0,   172,     2,     3,    57,     0,     0,     0,
       6,     0,     7,   194,     0,   193,   174,   168,     8,     0,
       0,   172,   173,   173,   173,   173,   193,     0,    15,    16,
       0,     0,    17,   193,   193,   193,   193,   173,   -51,   -51,
     -51,     0,   195,     0,   -51,   173,   -51,     0,     0,     0,
       0,     0,   188,   173,   169,     0,     0,     0,     0,   168,
     194,     0,   -51,   -51,   168,   168,   -51,   174,   174,   174,
     174,   194,     0,   204,     0,   105,   175,     0,   194,   194,
     194,   194,   174,     0,     0,     0,     0,    68,   218,   189,
     174,   175,     0,     0,   175,     0,   169,     0,   174,   173,
       0,   169,   169,     0,    72,     0,     0,     0,   173,     0,
     173,   195,   188,     0,   175,   106,     0,     2,     3,    61,
       0,     0,    87,     6,     0,     7,     0,     0,   173,    92,
       0,     8,     0,     0,    98,   100,     0,     0,     0,     0,
       0,    15,    16,     0,   174,    17,   168,     0,     0,   189,
       0,     0,     0,   174,     0,   174,     0,     0,   195,     0,
       0,   168,     0,     0,   168,   175,   175,   175,   175,   195,
       0,     0,   165,   174,     0,     0,   195,   195,   195,   195,
     175,   188,   131,   169,   168,     0,     0,   127,   175,   138,
     -54,   -54,   -54,   -54,   -54,   -54,   175,     0,   169,     0,
       0,   169,   137,     0,     0,     0,     0,   185,     0,     0,
       0,   239,   -54,     0,   165,     0,   226,   -54,   189,   165,
     165,   169,   167,     0,   -53,   -53,   -53,     0,   188,   151,
     -53,     0,   -53,     0,   234,   168,   270,     0,   155,   188,
       0,     0,   175,     0,     0,     0,   188,   276,   -53,   -53,
     168,   175,   -53,   175,   245,     0,     0,   187,   168,     0,
     303,     0,   218,     0,   167,   189,   168,   185,     0,   167,
     167,   175,   169,   169,   271,   201,   189,   -59,   -59,   -59,
     -59,   -59,   -59,   189,   189,   277,   204,   169,     0,     0,
     215,     0,   218,     0,     0,   169,     0,     0,    87,   -59,
     206,   165,   303,   169,   204,   218,   142,     0,     0,    87,
     303,   207,   168,     0,   303,   220,   150,   187,     0,   165,
     279,   168,     0,   168,     0,     0,   221,     0,   283,     0,
       0,   208,     0,     0,     0,     0,   226,     0,   209,   165,
       0,   168,     0,     0,     0,     0,   222,     0,     0,   169,
       0,   167,     0,   223,     0,     0,     0,     0,   169,     0,
     169,   309,     0,   311,     0,     0,   167,     0,     0,   167,
       0,   156,   157,   158,   299,     0,   310,   159,   169,   160,
       0,     0,   324,   185,     0,   161,   187,     0,     0,   167,
       0,   226,     0,   226,   185,   162,   163,     0,     0,   164,
     328,     0,     0,   337,     0,   165,   330,     0,     0,     0,
       0,   226,     0,   165,     0,     0,   336,     0,   338,   339,
       0,   165,     0,     0,   342,     0,     0,     0,   345,     2,
       3,    85,     0,   187,     0,     6,     0,     7,     0,     0,
     167,     0,     0,     8,   187,   -59,   -59,   -59,   -59,   -59,
     -59,   187,     0,    15,    16,   167,     0,    17,     0,     0,
       0,     0,   300,   167,   215,     0,     0,   165,     0,     0,
       0,   167,     0,   -59,     0,     0,   165,     0,   165,     0,
     -54,   -54,   -54,   -54,   -54,   -54,    94,   305,   201,   220,
       0,     0,     0,     0,   215,     0,   165,     0,   306,     0,
     221,    52,     0,     0,   300,     0,   201,   215,   -54,     0,
       0,     0,   300,   206,     0,     0,   300,   167,   307,   220,
     222,     0,     0,     0,   207,   308,   167,   223,   167,   305,
     221,   206,   220,     0,     0,     0,     0,   305,     0,     0,
     306,   305,   207,   221,   208,     0,   167,     0,   306,     0,
     222,   209,   306,     0,     0,     0,     0,   223,     0,     0,
     307,     0,   208,   222,     0,     0,     0,   308,   307,   209,
     223,     0,   307,     0,     0,   308,     0,   -19,   -19,   308,
     -19,   -19,   -19,   -19,     0,     0,   -19,     0,   -19,     0,
       0,     0,     0,     0,   -19,   -19,   -19,   -19,   -19,     0,
     -19,   -19,   -19,     0,   -19,   -19,     0,     0,   -19,     0,
     -20,   -20,   -19,   -20,   -20,   -20,   -20,     0,     0,   -20,
       0,   -20,     0,     0,     0,     0,     0,   -20,   -20,   -20,
     -20,   -20,     0,   -20,   -20,   -20,     0,   -20,   -20,     0,
       0,   -20,     0,   -21,   -21,   -20,   -21,   -21,   -21,   -21,
       0,     0,   -21,     0,   -21,     0,     0,     0,     0,     0,
     -21,   -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,     0,
     -21,   -21,     0,     0,   -21,     0,   -22,   -22,   -21,   -22,
     -22,   -22,   -22,     0,     0,   -22,     0,   -22,     0,     0,
       0,     0,     0,   -22,   -22,   -22,   -22,   -22,     0,   -22,
     -22,   -22,     0,   -22,   -22,     0,     0,   -22,     0,   -26,
     -26,   -22,   -26,   -26,   -26,   -26,     0,     0,   -26,     0,
     -26,     0,     0,     0,     0,     0,   -26,   -26,   -26,   -26,
     -26,     0,   -26,   -26,   -26,     0,   -26,   -26,     0,     0,
     -26,     0,   -75,   -75,   -26,   -75,   -75,   -75,   -75,     0,
       0,   -75,     0,   -75,     0,     0,     0,     0,     0,   -75,
     -75,   -75,   -75,   -75,     0,   -75,   -75,   -75,     0,   -75,
     -75,     0,     0,   -75,     0,   -24,   -24,   -75,   -24,   -24,
     -24,   -24,     0,     0,   -24,     0,   -24,     0,     0,     0,
       0,     0,   -24,   -24,   -24,   -24,   -24,     0,   -24,   -24,
     -24,     0,   -24,   -24,     0,     0,   -24,     0,   -25,   -25,
     -24,   -25,   -25,   -25,   -25,     0,     0,   -25,     0,   -25,
       0,     0,     0,     0,     0,   -25,   -25,   -25,   -25,   -25,
       0,   -25,   -25,   -25,     0,   -25,   -25,     0,     0,   -25,
       0,   -23,   -23,   -25,   -23,   -23,   -23,   -23,     0,     0,
     -23,     0,   -23,     0,     0,     0,     0,     0,   -23,   -23,
     -23,   -23,   -23,     0,   -23,   -23,   -23,     0,   -23,   -23,
       0,     0,   -23,     0,   -36,   -36,   -23,   -36,   -36,   -36,
     -36,     0,     0,   -36,     0,   -36,     0,     0,     0,     0,
       0,   -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,   -36,
       0,   -36,   -36,     0,     0,   -36,     0,   -28,   -28,   -36,
     -28,   -28,   -28,   -28,     0,     0,   -28,     0,   -28,     0,
       0,     0,     0,     0,   -28,   -28,   -28,   -28,   -28,     0,
     -28,   -28,   -28,     0,   -28,   -28,     0,     0,   -28,     0,
       0,   -27,   -28,   -27,   -27,   -27,   -27,     0,     0,   -27,
       0,   -27,     0,     0,     0,     0,     0,   -27,   -27,   -27,
     -27,   -27,     0,   -27,   -27,   -27,     0,   -27,   -27,     0,
       0,   -27,     0,     0,     0,   -27,   -27,   -33,     0,   -33,
     -33,   -33,   -33,     0,     0,   -33,     0,   -33,     0,     0,
       0,     0,     0,   -33,   -33,   316,   -33,   -33,     0,   -33,
     -33,   -33,     0,   -33,   -33,     0,     0,   -33,     0,     0,
       0,   -33,   -33,   -19,     0,   -19,   -19,   -19,   -19,     0,
       0,   -19,     0,   -19,     0,     0,     0,     0,     0,   -19,
     -19,   -19,   -19,   -19,     0,   -19,   -19,   -19,     0,   -19,
     -19,     0,     0,   -19,     0,     0,     0,   -19,   -19,   -20,
       0,   -20,   -20,   -20,   -20,     0,     0,   -20,     0,   -20,
       0,     0,     0,     0,     0,   -20,   -20,   -20,   -20,   -20,
       0,   -20,   -20,   -20,     0,   -20,   -20,     0,     0,   -20,
       0,     0,     0,   -20,   -20,   -21,     0,   -21,   -21,   -21,
     -21,     0,     0,   -21,     0,   -21,     0,     0,     0,     0,
       0,   -21,   -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,
       0,   -21,   -21,     0,     0,   -21,     0,     0,     0,   -21,
     -21,   -22,     0,   -22,   -22,   -22,   -22,     0,     0,   -22,
       0,   -22,     0,     0,     0,     0,     0,   -22,   -22,   -22,
     -22,   -22,     0,   -22,   -22,   -22,     0,   -22,   -22,     0,
       0,   -22,     0,     0,     0,   -22,   -22,   -26,     0,   -26,
     -26,   -26,   -26,     0,     0,   -26,     0,   -26,     0,     0,
       0,     0,     0,   -26,   -26,   -26,   -26,   -26,     0,   -26,
     -26,   -26,     0,   -26,   -26,     0,     0,   -26,     0,     0,
       0,   -26,   -26,   -33,   -33,     0,   -33,   -33,   -33,   -33,
       0,     0,   -33,     0,   -33,     0,     0,     0,     0,     0,
     -33,   -33,   322,   -33,   -33,     0,   -33,   -33,   -33,     0,
     -33,   -33,     0,     0,   -33,     0,     0,   -75,   -33,   -75,
     -75,   -75,   -75,     0,     0,   -75,     0,   -75,     0,     0,
       0,     0,     0,   -75,   -75,   -75,   -75,   -75,     0,   -75,
     -75,   -75,     0,   -75,   -75,     0,     0,   -75,     0,     0,
       0,   -75,   -75,   -24,     0,   -24,   -24,   -24,   -24,     0,
       0,   -24,     0,   -24,     0,     0,     0,     0,     0,   -24,
     -24,   -24,   -24,   -24,     0,   -24,   -24,   -24,     0,   -24,
     -24,     0,     0,   -24,     0,     0,     0,   -24,   -24,   -25,
       0,   -25,   -25,   -25,   -25,     0,     0,   -25,     0,   -25,
       0,     0,     0,     0,     0,   -25,   -25,   -25,   -25,   -25,
       0,   -25,   -25,   -25,     0,   -25,   -25,     0,     0,   -25,
       0,     0,     0,   -25,   -25,   -23,     0,   -23,   -23,   -23,
     -23,     0,     0,   -23,     0,   -23,     0,     0,     0,     0,
       0,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,
       0,   -23,   -23,     0,     0,   -23,     0,     0,     0,   -23,
     -23,   -36,     0,   -36,   -36,   -36,   -36,     0,     0,   -36,
       0,   -36,     0,     0,     0,     0,     0,   -36,   -36,   -36,
     -36,   -36,     0,   -36,   -36,   -36,     0,   -36,   -36,     0,
       0,   -36,     0,     0,     0,   -36,   -36,   -28,     0,   -28,
     -28,   -28,   -28,     0,     0,   -28,     0,   -28,     0,     0,
       0,     0,     0,   -28,   -28,   -28,   -28,   -28,     0,   -28,
     -28,   -28,     0,   -28,   -28,     0,     0,   -28,     0,     0,
       0,   -28,   -28,   -34,   -34,     0,   -34,   -34,   -34,   -34,
       0,     0,   -34,     0,   -34,     0,     0,     0,     0,     0,
     -34,   -34,   -34,   -34,   -34,     0,   -34,   -34,   -34,     0,
     -34,   -34,     0,     0,   -34,     0,     0,   -33,   -34,   -33,
     -33,   -33,   -33,     0,     0,   -33,     0,   -33,     0,     0,
       0,     0,     0,   -33,   -33,   340,   -33,   -33,     0,   -33,
     -33,   -33,     0,   -33,   -33,     0,     0,   -33,     0,     0,
       0,   -33,   -33,   -35,   -35,     0,   -35,   -35,   -35,   -35,
       0,     0,   -35,     0,   -35,     0,     0,     0,     0,     0,
     -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,   -35,     0,
     -35,   -35,     0,     0,   -35,     0,     0,   -34,   -35,   -34,
     -34,   -34,   -34,     0,     0,   -34,     0,   -34,     0,     0,
       0,     0,     0,   -34,   -34,   -34,   -34,   -34,     0,   -34,
     -34,   -34,     0,   -34,   -34,     0,     0,   -34,     0,     0,
       0,   -34,   -34,   -35,     0,   -35,   -35,   -35,   -35,     0,
       0,   -35,     0,   -35,     0,     0,     0,     0,     0,   -35,
     -35,   -35,   -35,   -35,     0,   -35,   -35,   -35,     0,   -35,
     -35,     0,     0,   -35,     0,     0,     0,   -35,   -35,   -27,
     -27,     0,   -27,   -27,   -27,   -27,     0,     0,   -27,     0,
     -27,     0,     0,     0,     0,     0,   -27,   -27,     0,   -27,
     -27,     0,   -27,   -27,   -27,     0,   -27,   -27,     0,     0,
     -27,     0,     0,   -32,   -27,   -32,   -32,   -32,   -32,     0,
       0,   -32,     0,   -32,     0,     0,     0,     0,     0,   -32,
     -32,     0,   -32,   -32,     0,   -32,   -32,   -32,     0,   -32,
     -32,     0,     0,   -32,     0,     0,     0,   -32,   -32,    -2,
       1,     0,     2,     3,     4,     5,     0,     0,     6,     0,
       7,     0,     0,     0,     0,     0,     8,     9,     0,    10,
      11,     0,    12,    13,    14,     0,    15,    16,     0,     0,
      17,     0,    -4,    -4,    18,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,     0,     0,     0,     0,    -4,
      -4,     0,    -4,    -4,     0,    -4,    -4,    -4,     0,    -4,
      -4,     0,     0,    -4,     0,    -7,    -7,    -4,    -7,    -7,
      -7,    -7,     0,     0,    -7,     0,    -7,     0,     0,     0,
       0,     0,    -7,    -7,     0,    -7,    -7,     0,    -7,    -7,
      -7,     0,    -7,    -7,     0,     0,    -7,     0,    -8,    -8,
      -7,    -8,    -8,    -8,    -8,     0,     0,    -8,     0,    -8,
       0,     0,     0,     0,     0,    -8,    -8,     0,    -8,    -8,
       0,    -8,    -8,    -8,     0,    -8,    -8,     0,     0,    -8,
       0,    -6,    -6,    -8,    -6,    -6,    -6,    -6,     0,     0,
      -6,     0,    -6,     0,     0,     0,     0,     0,    -6,    -6,
       0,    -6,    -6,     0,    -6,    -6,    -6,     0,    -6,    -6,
       0,     0,    -6,     0,   -19,   -19,    -6,   -19,   -19,   -19,
     -19,     0,     0,   -19,     0,   -19,     0,     0,     0,     0,
       0,   -19,   -19,     0,   -19,   -19,     0,   -19,   -19,   -19,
       0,   -19,   -19,     0,     0,   -19,     0,   -20,   -20,   -19,
     -20,   -20,   -20,   -20,     0,     0,   -20,     0,   -20,     0,
       0,     0,     0,     0,   -20,   -20,     0,   -20,   -20,     0,
     -20,   -20,   -20,     0,   -20,   -20,     0,     0,   -20,     0,
     -21,   -21,   -20,   -21,   -21,   -21,   -21,     0,     0,   -21,
       0,   -21,     0,     0,     0,     0,     0,   -21,   -21,     0,
     -21,   -21,     0,   -21,   -21,   -21,     0,   -21,   -21,     0,
       0,   -21,     0,   -22,   -22,   -21,   -22,   -22,   -22,   -22,
       0,     0,   -22,     0,   -22,     0,     0,     0,     0,     0,
     -22,   -22,     0,   -22,   -22,     0,   -22,   -22,   -22,     0,
     -22,   -22,     0,     0,   -22,     0,   -26,   -26,   -22,   -26,
     -26,   -26,   -26,     0,     0,   -26,     0,   -26,     0,     0,
       0,     0,     0,   -26,   -26,     0,   -26,   -26,     0,   -26,
     -26,   -26,     0,   -26,   -26,     0,     0,   -26,     0,     0,
     -30,   -26,   -30,   -30,   -30,   -30,     0,     0,   -30,     0,
     -30,     0,     0,     0,     0,     0,   -30,   -30,     0,   -30,
     -30,     0,   -30,   -30,   -30,     0,   -30,   -30,     0,     0,
     -30,     0,     0,     0,   -30,   102,    -3,    -3,     0,    -3,
      -3,    -3,    -3,     0,     0,    -3,     0,    -3,     0,     0,
       0,     0,     0,    -3,    -3,     0,    -3,    -3,     0,    -3,
      -3,    -3,     0,    -3,    -3,     0,     0,    -3,     0,    -5,
      -5,    -3,    -5,    -5,    -5,    -5,     0,     0,    -5,     0,
      -5,     0,     0,     0,     0,     0,    -5,    -5,     0,    -5,
      -5,     0,    -5,    -5,    -5,     0,    -5,    -5,     0,     0,
      -5,     0,   -75,   -75,    -5,   -75,   -75,   -75,   -75,     0,
       0,   -75,     0,   -75,     0,     0,     0,     0,     0,   -75,
     -75,     0,   -75,   -75,     0,   -75,   -75,   -75,     0,   -75,
     -75,     0,     0,   -75,     0,   -24,   -24,   -75,   -24,   -24,
     -24,   -24,     0,     0,   -24,     0,   -24,     0,     0,     0,
       0,     0,   -24,   -24,     0,   -24,   -24,     0,   -24,   -24,
     -24,     0,   -24,   -24,     0,     0,   -24,     0,   -25,   -25,
     -24,   -25,   -25,   -25,   -25,     0,     0,   -25,     0,   -25,
       0,     0,     0,     0,     0,   -25,   -25,     0,   -25,   -25,
       0,   -25,   -25,   -25,     0,   -25,   -25,     0,     0,   -25,
       0,   -23,   -23,   -25,   -23,   -23,   -23,   -23,     0,     0,
     -23,     0,   -23,     0,     0,     0,     0,     0,   -23,   -23,
       0,   -23,   -23,     0,   -23,   -23,   -23,     0,   -23,   -23,
       0,     0,   -23,     0,    -9,    -9,   -23,    -9,    -9,    -9,
      -9,     0,     0,    -9,     0,    -9,     0,     0,     0,     0,
       0,    -9,    -9,     0,    -9,    -9,     0,    -9,    -9,    -9,
       0,    -9,    -9,     0,     0,    -9,     0,   -36,   -36,    -9,
     -36,   -36,   -36,   -36,     0,     0,   -36,     0,   -36,     0,
       0,     0,     0,     0,   -36,   -36,     0,   -36,   -36,     0,
     -36,   -36,   -36,     0,   -36,   -36,     0,     0,   -36,     0,
     -28,   -28,   -36,   -28,   -28,   -28,   -28,     0,     0,   -28,
       0,   -28,     0,     0,     0,     0,     0,   -28,   -28,     0,
     -28,   -28,     0,   -28,   -28,   -28,     0,   -28,   -28,     0,
       0,   -28,     0,   -10,   -10,   -28,   -10,   -10,   -10,   -10,
       0,     0,   -10,     0,   -10,     0,     0,     0,     0,     0,
     -10,   -10,     0,   -10,   -10,     0,   -10,   -10,   -10,     0,
     -10,   -10,     0,     0,   -10,     0,     0,   -31,   -10,   -31,
     -31,   -31,   -31,     0,     0,   -31,     0,   -31,     0,     0,
       0,     0,     0,   -31,   -31,     0,   -31,   -31,     0,   -31,
     -31,   -31,     0,   -31,   -31,     0,     0,   -31,     0,     0,
       0,   -31,   -31,   -11,   -11,     0,   -11,   -11,   -11,   -11,
       0,     0,   -11,     0,   -11,     0,     0,     0,     0,     0,
     -11,   -11,     0,   -11,   -11,     0,   -11,   -11,   -11,     0,
     -11,   -11,     0,     0,   -11,     0,   -12,   -12,   -11,   -12,
     -12,   -12,   -12,     0,     0,   -12,     0,   -12,     0,     0,
       0,     0,     0,   -12,   -12,     0,   -12,   -12,     0,   -12,
     -12,   -12,     0,   -12,   -12,     0,     0,   -12,     0,   -34,
     -34,   -12,   -34,   -34,   -34,   -34,     0,     0,   -34,     0,
     -34,     0,     0,     0,     0,     0,   -34,   -34,     0,   -34,
     -34,     0,   -34,   -34,   -34,     0,   -34,   -34,     0,     0,
     -34,     0,   -35,   -35,   -34,   -35,   -35,   -35,   -35,     0,
       0,   -35,     0,   -35,     0,     0,     0,     0,     0,   -35,
     -35,     0,   -35,   -35,     0,   -35,   -35,   -35,     0,   -35,
     -35,     0,     0,   -35,     0,     0,   -27,   -35,   -27,   -27,
     -27,   -27,     0,     0,   -27,     0,   -27,     0,     0,     0,
       0,     0,   -27,   -27,     0,   -27,   -27,     0,   -27,   -27,
     -27,     0,   -27,   -27,     0,     0,   -27,     0,     0,     0,
     -27,   -27,   -19,     0,   -19,   -19,   -19,   -19,     0,     0,
     -19,     0,   -19,     0,     0,     0,     0,     0,   -19,   -19,
       0,   -19,   -19,     0,   -19,   -19,   -19,     0,   -19,   -19,
       0,     0,   -19,     0,     0,     0,   -19,   -19,   -20,     0,
     -20,   -20,   -20,   -20,     0,     0,   -20,     0,   -20,     0,
       0,     0,     0,     0,   -20,   -20,     0,   -20,   -20,     0,
     -20,   -20,   -20,     0,   -20,   -20,     0,     0,   -20,     0,
       0,     0,   -20,   -20,   -21,     0,   -21,   -21,   -21,   -21,
       0,     0,   -21,     0,   -21,     0,     0,     0,     0,     0,
     -21,   -21,     0,   -21,   -21,     0,   -21,   -21,   -21,     0,
     -21,   -21,     0,     0,   -21,     0,     0,     0,   -21,   -21,
     -22,     0,   -22,   -22,   -22,   -22,     0,     0,   -22,     0,
     -22,     0,     0,     0,     0,     0,   -22,   -22,     0,   -22,
     -22,     0,   -22,   -22,   -22,     0,   -22,   -22,     0,     0,
     -22,     0,     0,     0,   -22,   -22,   -26,     0,   -26,   -26,
     -26,   -26,     0,     0,   -26,     0,   -26,     0,     0,     0,
       0,     0,   -26,   -26,     0,   -26,   -26,     0,   -26,   -26,
     -26,     0,   -26,   -26,     0,     0,   -26,     0,     0,     0,
     -26,   -26,   -30,     0,   -30,   -30,   -30,   -30,     0,     0,
     -30,     0,   -30,     0,     0,     0,     0,     0,   -30,   -30,
       0,   -30,   -30,     0,   -30,   -30,   -30,     0,   -30,   -30,
       0,     0,   -30,     0,     0,     0,   -30,   282,   -75,     0,
     -75,   -75,   -75,   -75,     0,     0,   -75,     0,   -75,     0,
       0,     0,     0,     0,   -75,   -75,     0,   -75,   -75,     0,
     -75,   -75,   -75,     0,   -75,   -75,     0,     0,   -75,     0,
       0,     0,   -75,   -75,   -24,     0,   -24,   -24,   -24,   -24,
       0,     0,   -24,     0,   -24,     0,     0,     0,     0,     0,
     -24,   -24,     0,   -24,   -24,     0,   -24,   -24,   -24,     0,
     -24,   -24,     0,     0,   -24,     0,     0,     0,   -24,   -24,
     -25,     0,   -25,   -25,   -25,   -25,     0,     0,   -25,     0,
     -25,     0,     0,     0,     0,     0,   -25,   -25,     0,   -25,
     -25,     0,   -25,   -25,   -25,     0,   -25,   -25,     0,     0,
     -25,     0,     0,     0,   -25,   -25,   -23,     0,   -23,   -23,
     -23,   -23,     0,     0,   -23,     0,   -23,     0,     0,     0,
       0,     0,   -23,   -23,     0,   -23,   -23,     0,   -23,   -23,
     -23,     0,   -23,   -23,     0,     0,   -23,     0,     0,     0,
     -23,   -23,   -30,     0,   -30,   -30,   -30,   -30,     0,     0,
     -30,     0,   -30,     0,     0,     0,     0,     0,   -30,   -30,
       0,   -30,   -30,     0,   -30,   -30,   -30,     0,   -30,   -30,
       0,     0,   -30,     0,     0,     0,   -30,   286,   -36,     0,
     -36,   -36,   -36,   -36,     0,     0,   -36,     0,   -36,     0,
       0,     0,     0,     0,   -36,   -36,     0,   -36,   -36,     0,
     -36,   -36,   -36,     0,   -36,   -36,     0,     0,   -36,     0,
       0,     0,   -36,   -36,   -28,     0,   -28,   -28,   -28,   -28,
       0,     0,   -28,     0,   -28,     0,     0,     0,     0,     0,
     -28,   -28,     0,   -28,   -28,     0,   -28,   -28,   -28,     0,
     -28,   -28,     0,     0,   -28,     0,     0,     0,   -28,   -28,
     -30,     0,   -30,   -30,   -30,   -30,     0,     0,   -30,     0,
     -30,     0,     0,     0,     0,     0,   -30,   -30,     0,   -30,
     -30,     0,   -30,   -30,   -30,     0,   -30,   -30,     0,     0,
     -30,     0,     0,     0,   -30,   327,   -34,     0,   -34,   -34,
     -34,   -34,     0,     0,   -34,     0,   -34,     0,     0,     0,
       0,     0,   -34,   -34,     0,   -34,   -34,     0,   -34,   -34,
     -34,     0,   -34,   -34,     0,     0,   -34,     0,     0,     0,
     -34,   -34,   -35,     0,   -35,   -35,   -35,   -35,     0,     0,
     -35,     0,   -35,     0,     0,     0,     0,     0,   -35,   -35,
       0,   -35,   -35,     0,   -35,   -35,   -35,     0,   -35,   -35,
       0,     0,   -35,     0,     0,     0,   -35,   -35,     1,     0,
       2,     3,     4,     5,     0,     0,     6,     0,     7,     0,
       0,     0,     0,     0,     8,     9,     0,    10,    11,     0,
      12,    13,    14,     0,    15,    16,     0,     0,    17,     0,
       0,   196,    18,     2,     3,     4,   125,     0,     0,     6,
       0,     7,     0,     0,     0,     0,     0,     8,   197,     0,
     198,   199,     0,    12,    13,    14,     0,    15,    16,     0,
       0,    17,     0,     0,   -29,   200,   -29,   -29,   -29,   -29,
       0,     0,   -29,     0,   -29,     0,     0,     0,     0,     0,
     -29,   -29,     0,   -29,   -29,     0,   -29,   -29,   -29,     0,
     -29,   -29,     0,     0,   -29,     0,     0,    -9,   -29,    -9,
      -9,    -9,    -9,     0,     0,    -9,     0,    -9,     0,     0,
       0,     0,     0,    -9,    -9,     0,    -9,    -9,     0,    -9,
      -9,    -9,     0,    -9,    -9,     0,     0,    -9,     0,     0,
     -10,    -9,   -10,   -10,   -10,   -10,     0,     0,   -10,     0,
     -10,     0,     0,     0,     0,     0,   -10,   -10,     0,   -10,
     -10,     0,   -10,   -10,   -10,     0,   -10,   -10,     0,   210,
     -10,     2,     3,     4,   -10,     0,     0,     6,     0,     7,
       0,     0,     0,     0,     0,     8,   211,     0,   212,   213,
       0,    12,    13,    14,     0,    15,    16,     0,     1,    17,
       2,     3,     4,   214,     0,     0,     6,     0,     7,     0,
       0,     0,     0,     0,     8,     9,     0,    10,    11,     0,
      12,    13,    14,     0,    15,    16,     0,   294,    17,     2,
       3,     4,    18,     0,     0,     6,     0,     7,     0,     0,
       0,     0,     0,     8,   295,     0,   296,   297,     0,    12,
      13,    14,     0,    15,    16,     0,   196,    17,     2,     3,
       4,   298,     0,     0,     6,     0,     7,     0,     0,     0,
       0,     0,     8,   197,     0,   198,   199,     0,    12,    13,
      14,     0,    15,    16,     0,     0,    17,     0,     0,     0,
     200,   -54,   -54,   -54,   -54,   -54,   -54,    94,     0,     0,
     176,   177,   178,     0,     0,     0,   179,   108,   180,     0,
     109,   110,    52,     0,   181,   156,   157,   225,     0,   -54,
       0,   159,     0,   160,   182,   183,     0,     0,   184,   161,
     -52,   -52,   -52,     0,     0,     0,   -52,     0,   -52,   162,
     163,     0,     0,   164,   156,   157,   158,     0,     0,     0,
     159,     0,   160,     0,   -52,   -52,     0,     0,   -52,   176,
     177,   178,     0,     0,     0,   179,     0,   180,   162,   163,
       0,     0,   164,   -61,   -61,   -61,   -61,   -61,   -61,     0,
       0,     0,     0,   182,   183,     0,     0,   184,   -63,   -63,
     -63,   -63,   -63,   -63,   -47,   -47,    79,    80,   -47,   -47,
       0,   -61,   -49,   -49,   -49,   -49,   -49,   -49,   -55,   -55,
     -55,   -55,   -55,   -55,     0,     0,   -63,     0,     0,     0,
       0,     0,   -47,   -57,   -57,   -57,   -57,   -57,   -57,     0,
     -49,     0,     0,     0,     0,     0,   -55,   -58,   -58,   -58,
     -58,   -58,   -58,   -79,   -79,   -79,   -79,   -79,   -79,     0,
       0,   -57,   -80,   -80,   -80,   -80,   -80,   -80,   -60,   -60,
     -60,   -60,   -60,   -60,     0,   -58,     0,     0,     0,     0,
       0,   -79,   -62,   -62,   -62,   -62,   -62,   -62,     0,     0,
     -80,     0,     0,     0,     0,     0,   -60,   -82,   -82,   -82,
     -82,   -82,   -82,   -83,   -83,   -83,   -83,   -83,   -83,     0,
     -62,   -56,   -56,   -56,   -56,   -56,   -56,   -46,   -46,    79,
      80,   -46,   -46,     0,     0,   -82,     0,     0,     0,     0,
       0,   -83,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -56,
       0,     0,     0,     0,     0,   -46,   -64,   -64,   -64,   -64,
     -64,   -64,     0,   -59,   -59,   -59,   -59,   -59,   -59,     0,
     -48,   -61,   -61,   -61,   -61,   -61,   -61,   -63,   -63,   -63,
     -63,   -63,   -63,     0,   -64,   -59,     0,     0,     0,     0,
     -59,     0,     0,   -61,     0,     0,     0,     0,   -61,   -63,
       0,     0,     0,     0,   -63,   -47,   -47,    79,    80,   -47,
     -47,   -49,   -49,   -49,   -49,   -49,   -49,   -55,   -55,   -55,
     -55,   -55,   -55,     0,     0,     0,     0,   -47,     0,     0,
       0,     0,   -47,   -49,     0,     0,     0,     0,   -49,   -55,
       0,     0,     0,     0,   -55,   -57,   -57,   -57,   -57,   -57,
     -57,   -58,   -58,   -58,   -58,   -58,   -58,   -79,   -79,   -79,
     -79,   -79,   -79,     0,     0,     0,     0,   -57,     0,     0,
       0,     0,   -57,   -58,     0,     0,     0,     0,   -58,   -79,
       0,     0,     0,     0,   -79,   -80,   -80,   -80,   -80,   -80,
     -80,   -60,   -60,   -60,   -60,   -60,   -60,   -62,   -62,   -62,
     -62,   -62,   -62,     0,     0,     0,     0,   -80,     0,     0,
       0,     0,   -80,   -60,     0,     0,     0,     0,   -60,   -62,
       0,     0,     0,     0,   -62,   -82,   -82,   -82,   -82,   -82,
     -82,   -83,   -83,   -83,   -83,   -83,   -83,   -56,   -56,   -56,
     -56,   -56,   -56,     0,     0,     0,     0,   -82,     0,     0,
       0,     0,   -82,   -83,     0,     0,     0,     0,   -83,   -56,
       0,     0,     0,     0,   -56,   -46,   -46,    79,    80,   -46,
     -46,   -48,   -48,   -48,   -48,   -48,   -48,   -64,   -64,   -64,
     -64,   -64,   -64,     0,     0,     0,     0,   -46,     0,     0,
       0,     0,   -46,   -48,     0,     0,     0,     0,   -48,   -64,
       0,     0,     0,     0,   -64,   -54,   -54,   -54,   -54,   -54,
     -54,   -61,   -61,   -61,   -61,   -61,   -61,   -63,   -63,   -63,
     -63,   -63,   -63,     0,     0,     0,   228,   -54,     0,     0,
       0,     0,     0,   -61,     0,     0,     0,     0,     0,   -63,
     -47,   -47,    79,    80,   -47,   -47,   -49,   -49,   -49,   -49,
     -49,   -49,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,     0,   -47,     0,     0,     0,     0,     0,   -49,     0,
       0,     0,     0,     0,   -55,   -57,   -57,   -57,   -57,   -57,
     -57,   -58,   -58,   -58,   -58,   -58,   -58,   -79,   -79,   -79,
     -79,   -79,   -79,     0,     0,     0,     0,   -57,     0,     0,
       0,     0,     0,   -58,     0,     0,     0,     0,     0,   -79,
     -80,   -80,   -80,   -80,   -80,   -80,   -60,   -60,   -60,   -60,
     -60,   -60,   -62,   -62,   -62,   -62,   -62,   -62,     0,     0,
       0,     0,   -80,     0,     0,     0,     0,     0,   -60,     0,
       0,     0,     0,     0,   -62,   -82,   -82,   -82,   -82,   -82,
     -82,   -83,   -83,   -83,   -83,   -83,   -83,   -56,   -56,   -56,
     -56,   -56,   -56,     0,     0,     0,     0,   -82,     0,     0,
       0,     0,     0,   -83,     0,     0,     0,     0,     0,   -56,
     -46,   -46,    79,    80,   -46,   -46,   -48,   -48,   -48,   -48,
     -48,   -48,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,
       0,     0,   -46,     0,     0,     0,     0,     0,   -48,     0,
       0,     0,     0,     0,   -64
};

static const yytype_int16 yycheck[] =
{
      11,   200,   168,     6,     8,    31,    14,   169,     3,     4,
       5,    31,    38,    17,     9,   214,    11,     3,     4,     5,
      14,    15,   188,     9,    31,    11,    14,   189,     5,    32,
      38,    17,    27,    28,    14,    14,    31,     3,     4,    17,
      51,    27,    28,   228,    38,    31,    32,    31,    52,    60,
      38,    37,    10,    11,   239,    59,    14,    15,    38,    38,
      64,    65,    31,    10,    11,    12,    13,    14,    15,    16,
      74,    31,    10,    11,    52,    31,    14,    15,    38,    14,
      38,    59,     5,    94,    31,    38,    64,    65,     3,     4,
       5,    38,   103,     8,     9,     0,    11,    32,    38,   298,
      38,    32,    17,    81,   270,    38,    37,   118,   112,   271,
     276,    38,    27,    28,    14,   277,    31,    38,    14,    15,
       0,     1,    32,     3,     4,     5,     6,    37,    14,     9,
      38,    11,    32,     5,   112,   146,    32,    17,    18,    19,
      20,    21,   146,    23,    24,    25,    32,    27,    28,    17,
       5,    31,     7,    38,    14,    35,    32,   161,    14,    15,
     164,    37,     3,     4,    14,     3,     4,     5,   146,    32,
       8,     9,    32,    11,    37,     5,    32,   181,    32,    17,
     184,    37,    32,   161,    52,    38,   164,    37,   199,    27,
      28,    59,     5,    31,     7,    38,    64,    65,    38,   103,
      10,    11,   213,   181,    14,    15,   184,    14,    10,    11,
      12,    13,    14,    15,   118,    38,    10,    11,    32,   103,
      14,    15,    32,    37,   228,    32,     5,    37,     7,    31,
      37,   235,    32,    14,   118,   239,    38,    37,    32,     5,
     251,     7,   246,    37,   112,    38,   250,    17,   259,    32,
     228,    32,     3,     4,   258,   266,    37,   235,   236,   237,
     238,   239,   266,    38,    32,    32,     5,    14,   246,   247,
     248,   249,   250,    32,    32,    32,     5,     5,   146,   290,
     258,   292,    52,    32,    38,    32,   297,    32,   266,    59,
      37,     5,    37,   161,    64,    65,   164,    38,    32,    32,
      38,    32,   313,    37,    37,   316,    37,     6,   312,    35,
     321,   322,   323,   181,    38,    38,   184,   321,    38,   323,
      38,   332,    38,   334,   335,    32,    38,    38,     5,   340,
     341,    10,    11,   344,   312,    14,    15,   341,    38,     5,
      32,     5,   112,   321,     5,   323,     5,     5,    31,     3,
       4,     5,    38,    32,    17,     9,    31,    11,    38,    31,
     228,    10,    11,   341,    38,    14,    15,   235,   236,   237,
     238,   239,    32,    27,    28,    31,   146,    31,   246,   247,
     248,   249,   250,    32,    32,    38,   290,    38,   292,    52,
     258,   161,    38,    38,   164,    38,    59,    32,   266,    17,
      38,    64,    65,    32,    38,    38,   290,    32,   292,    32,
      38,   181,   316,    20,   184,    31,    31,    38,   322,    38,
      32,    10,    11,    12,    13,    14,    15,    16,   332,    38,
     334,   335,   316,    38,    52,    38,   340,    38,   322,    38,
     344,    59,    31,    32,   312,    38,    64,    65,   332,   112,
     334,   335,    32,   321,    32,   323,   340,    38,   228,    32,
     344,   103,    -1,    -1,   116,   235,   236,   237,   238,   239,
      -1,    -1,    -1,   341,    -1,    -1,   246,   247,   248,   249,
     250,    -1,    -1,   146,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,   112,    -1,   266,    17,   161,    -1,
      -1,   164,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,   181,    -1,
      -1,   184,    -1,    17,    18,    19,    20,    21,   146,    23,
      24,    25,    52,    27,    28,    -1,    -1,    31,    -1,    59,
      -1,    35,   312,   161,    64,    65,   164,    -1,    -1,    -1,
      -1,   321,    -1,   323,     3,     4,     5,    -1,    -1,    -1,
       9,    -1,    11,   181,    -1,   228,   184,    17,    17,    -1,
      -1,   341,   235,   236,   237,   238,   239,    -1,    27,    28,
      -1,    -1,    31,   246,   247,   248,   249,   250,     3,     4,
       5,    -1,   112,    -1,     9,   258,    11,    -1,    -1,    -1,
      -1,    -1,    52,   266,    17,    -1,    -1,    -1,    -1,    59,
     228,    -1,    27,    28,    64,    65,    31,   235,   236,   237,
     238,   239,    -1,   103,    -1,    75,   146,    -1,   246,   247,
     248,   249,   250,    -1,    -1,    -1,    -1,    17,   118,    52,
     258,   161,    -1,    -1,   164,    -1,    59,    -1,   266,   312,
      -1,    64,    65,    -1,    20,    -1,    -1,    -1,   321,    -1,
     323,   181,   112,    -1,   184,    78,    -1,     3,     4,     5,
      -1,    -1,    52,     9,    -1,    11,    -1,    -1,   341,    59,
      -1,    17,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,   312,    31,   146,    -1,    -1,   112,
      -1,    -1,    -1,   321,    -1,   323,    -1,    -1,   228,    -1,
      -1,   161,    -1,    -1,   164,   235,   236,   237,   238,   239,
      -1,    -1,    17,   341,    -1,    -1,   246,   247,   248,   249,
     250,   181,   112,   146,   184,    -1,    -1,   103,   258,   119,
      10,    11,    12,    13,    14,    15,   266,    -1,   161,    -1,
      -1,   164,   118,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    31,    32,    -1,    59,    -1,   146,    37,   181,    64,
      65,   184,    17,    -1,     3,     4,     5,    -1,   228,   145,
       9,    -1,    11,    -1,   164,   235,   236,    -1,   154,   239,
      -1,    -1,   312,    -1,    -1,    -1,   246,   247,    27,    28,
     250,   321,    31,   323,   184,    -1,    -1,    52,   258,    -1,
     290,    -1,   292,    -1,    59,   228,   266,   112,    -1,    64,
      65,   341,   235,   236,   237,   103,   239,    10,    11,    12,
      13,    14,    15,   246,   247,   248,   316,   250,    -1,    -1,
     118,    -1,   322,    -1,    -1,   258,    -1,    -1,   228,    32,
     103,   146,   332,   266,   334,   335,   134,    -1,    -1,   239,
     340,   103,   312,    -1,   344,   118,   144,   112,    -1,   164,
     250,   321,    -1,   323,    -1,    -1,   118,    -1,   258,    -1,
      -1,   103,    -1,    -1,    -1,    -1,   266,    -1,   103,   184,
      -1,   341,    -1,    -1,    -1,    -1,   118,    -1,    -1,   312,
      -1,   146,    -1,   118,    -1,    -1,    -1,    -1,   321,    -1,
     323,   291,    -1,   293,    -1,    -1,   161,    -1,    -1,   164,
      -1,     3,     4,     5,   290,    -1,   292,     9,   341,    11,
      -1,    -1,   312,   228,    -1,    17,   181,    -1,    -1,   184,
      -1,   321,    -1,   323,   239,    27,    28,    -1,    -1,    31,
     316,    -1,    -1,   333,    -1,   250,   322,    -1,    -1,    -1,
      -1,   341,    -1,   258,    -1,    -1,   332,    -1,   334,   335,
      -1,   266,    -1,    -1,   340,    -1,    -1,    -1,   344,     3,
       4,     5,    -1,   228,    -1,     9,    -1,    11,    -1,    -1,
     235,    -1,    -1,    17,   239,    10,    11,    12,    13,    14,
      15,   246,    -1,    27,    28,   250,    -1,    31,    -1,    -1,
      -1,    -1,   290,   258,   292,    -1,    -1,   312,    -1,    -1,
      -1,   266,    -1,    38,    -1,    -1,   321,    -1,   323,    -1,
      10,    11,    12,    13,    14,    15,    16,   290,   316,   292,
      -1,    -1,    -1,    -1,   322,    -1,   341,    -1,   290,    -1,
     292,    31,    -1,    -1,   332,    -1,   334,   335,    38,    -1,
      -1,    -1,   340,   316,    -1,    -1,   344,   312,   290,   322,
     292,    -1,    -1,    -1,   316,   290,   321,   292,   323,   332,
     322,   334,   335,    -1,    -1,    -1,    -1,   340,    -1,    -1,
     332,   344,   334,   335,   316,    -1,   341,    -1,   340,    -1,
     322,   316,   344,    -1,    -1,    -1,    -1,   322,    -1,    -1,
     332,    -1,   334,   335,    -1,    -1,    -1,   332,   340,   334,
     335,    -1,   344,    -1,    -1,   340,    -1,     0,     1,   344,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,
       0,     1,    35,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,     0,     1,    35,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,     0,     1,    35,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,     0,
       1,    35,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,     0,     1,    35,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,     0,     1,    35,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,    -1,     0,     1,
      35,     3,     4,     5,     6,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    31,
      -1,     0,     1,    35,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,     0,     1,    35,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    31,    -1,     0,     1,    35,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,
      -1,     1,    35,     3,     4,     5,     6,    -1,    -1,     9,
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
      -1,    35,    36,     0,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,     1,    35,     3,
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
      -1,    35,    36,     0,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,     1,    35,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
      -1,    35,    36,     0,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,     1,    35,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
      -1,    35,    36,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,     0,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,     1,    35,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,     0,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,     0,     1,    35,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,     0,     1,    35,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,    -1,     0,     1,
      35,     3,     4,     5,     6,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    31,
      -1,     0,     1,    35,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,     0,     1,    35,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    31,    -1,     0,     1,    35,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,
       0,     1,    35,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,     0,     1,    35,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,     0,     1,    35,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
       1,    35,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,     0,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,     0,
       1,    35,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,     0,     1,    35,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,     0,     1,    35,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,    -1,     0,     1,
      35,     3,     4,     5,     6,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    31,
      -1,     0,     1,    35,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,     0,     1,    35,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    31,    -1,     0,     1,    35,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,
       0,     1,    35,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,     0,     1,    35,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,     1,    35,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
      -1,    35,    36,     0,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,     0,     1,    35,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,     0,
       1,    35,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,     0,     1,    35,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,     1,    35,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,
      35,    36,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,
      -1,    -1,    35,    36,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,
      35,    36,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,
      -1,    -1,    35,    36,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,
      35,    36,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,
      -1,    -1,    35,    36,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,
      35,    36,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,
      -1,     1,    35,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,     1,    35,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,     1,    35,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
       1,    35,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,     1,
      31,     3,     4,     5,    35,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,     1,    31,
       3,     4,     5,    35,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    25,    -1,    27,    28,    -1,     1,    31,     3,
       4,     5,    35,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,     1,    31,     3,     4,
       5,    35,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,
      35,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,     9,    26,    11,    -1,
      29,    30,    31,    -1,    17,     3,     4,     5,    -1,    38,
      -1,     9,    -1,    11,    27,    28,    -1,    -1,    31,    17,
       3,     4,     5,    -1,    -1,    -1,     9,    -1,    11,    27,
      28,    -1,    -1,    31,     3,     4,     5,    -1,    -1,    -1,
       9,    -1,    11,    -1,    27,    28,    -1,    -1,    31,     3,
       4,     5,    -1,    -1,    -1,     9,    -1,    11,    27,    28,
      -1,    -1,    31,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    31,    10,    11,
      12,    13,    14,    15,    10,    11,    12,    13,    14,    15,
      -1,    38,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    38,    10,    11,    12,    13,    14,    15,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    38,    10,    11,    12,
      13,    14,    15,    10,    11,    12,    13,    14,    15,    -1,
      -1,    38,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    38,    10,    11,    12,    13,    14,    15,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    38,    10,    11,    12,
      13,    14,    15,    10,    11,    12,    13,    14,    15,    -1,
      38,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    38,    10,    11,    12,    13,    14,    15,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    38,    10,    11,    12,    13,
      14,    15,    -1,    10,    11,    12,    13,    14,    15,    -1,
      38,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    38,    32,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    32,    -1,    -1,    -1,    -1,    37,    32,
      -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,    32,    -1,    -1,    -1,    -1,    37,    32,
      -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,    32,    -1,    -1,    -1,    -1,    37,    32,
      -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,    32,    -1,    -1,    -1,    -1,    37,    32,
      -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,    32,    -1,    -1,    -1,    -1,    37,    32,
      -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,    32,    -1,    -1,    -1,    -1,    37,    32,
      -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    32,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    32,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    32,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    32,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    32,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     9,    11,    17,    18,
      20,    21,    23,    24,    25,    27,    28,    31,    35,    47,
      48,    49,    50,    51,    54,    55,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    70,    71,    72,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    16,    31,     5,     7,     3,     4,     5,    64,    31,
      31,     5,    61,    31,    31,    31,     5,     5,    62,    57,
       0,    49,    54,    38,    14,    15,    10,    11,    68,    12,
      13,    69,    38,    38,    38,     5,    61,    62,    73,    31,
      38,     5,    62,    61,    16,    38,     5,     8,    62,     8,
      62,    32,    36,    56,    64,    66,    67,    70,    26,    29,
      30,    32,    37,     6,    52,    53,    31,    38,    32,    38,
      32,    32,    32,    32,    32,     6,    50,    54,     5,     5,
       5,    62,     5,     7,    32,    37,    52,    54,    62,     5,
       7,     5,    55,     6,    32,    19,    38,     5,     5,     7,
      55,    54,    61,     5,    32,    54,     3,     4,     5,     9,
      11,    17,    27,    28,    31,    63,    64,    65,    66,    67,
      70,    71,    72,    80,    82,    83,     3,     4,     5,     9,
      11,    17,    27,    28,    31,    63,    64,    65,    66,    67,
      70,    71,    72,    80,    82,    83,     1,    18,    20,    21,
      35,    55,    58,    59,    60,    61,    74,    77,    78,    79,
       1,    18,    20,    21,    35,    55,    58,    59,    60,    61,
      74,    77,    78,    79,    38,     5,    62,    38,    31,     3,
       4,    64,     5,     5,    62,    14,    15,    68,    69,    31,
       3,     4,    64,     5,     5,    62,    14,    15,    68,    69,
      31,    31,    61,    57,    38,    38,    38,    38,    31,    31,
      61,    57,    38,    38,    38,    38,    16,    73,    32,    64,
      66,    67,    70,    73,    32,    64,    66,    67,    70,    62,
      61,    38,    36,    62,    61,    38,    36,    61,    32,    32,
      32,    38,    32,    38,     1,    18,    20,    21,    35,    54,
      55,    58,    59,    60,    61,    74,    77,    78,    79,    62,
      54,    62,    31,    31,    61,    57,    19,    38,    38,    38,
      38,    38,    19,    38,    62,    61,    38,    36,    54,    61,
      54,    61,    32,    38,    32,    32,    54,    62,    54,    54,
      19,    38,    54,    61,    32,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    55,    56,
      56,    57,    57,    58,    58,    59,    60,    61,    61,    62,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    72,    73,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    78,    79,    79,    79,    80,
      80,    81,    82,    83,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     3,
       4,     6,     7,     1,     0,     4,     5,     2,     3,     1,
       1,     1,     1,     2,     2,     2,     1,     1,     3,     2,
       0,     3,     0,     5,     7,     9,     3,     3,     1,     1,
       3,     1,     2,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       2,     1,     2,     1,     4,     3,     1,     0,     1,     1,
       4,     4,     4,     4,     4,     2,     1,     1,     1,     1,
       1,     5,     2,     2,     5,     5
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
#line 173 "./src/syntax.y"
                    {}
#line 2524 "./src/syntax.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 177 "./src/syntax.y"
                                {}
#line 2530 "./src/syntax.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 178 "./src/syntax.y"
                  {}
#line 2536 "./src/syntax.tab.c"
    break;

  case 5: /* declarationList: declarationList statement  */
#line 179 "./src/syntax.y"
                                {}
#line 2542 "./src/syntax.tab.c"
    break;

  case 6: /* declarationList: statement  */
#line 180 "./src/syntax.y"
                {}
#line 2548 "./src/syntax.tab.c"
    break;

  case 7: /* declaration: varDeclaration  */
#line 184 "./src/syntax.y"
                   {}
#line 2554 "./src/syntax.tab.c"
    break;

  case 8: /* declaration: funcDeclaration  */
#line 185 "./src/syntax.y"
                      {}
#line 2560 "./src/syntax.tab.c"
    break;

  case 9: /* varDeclaration: TYPE ID DELIM_SEMICOLLON  */
#line 189 "./src/syntax.y"
                             {
        /* printf("%s %s %s\n", $1.text, $2.text, $3.text); */
        createSymbol((yyvsp[-1].t_token).text, (yyvsp[-2].t_token).text, (yyvsp[-1].t_token).line, (yyvsp[-1].t_token).column, (yyvsp[-1].t_token).scope->scopeValue, (yyvsp[-1].t_token).scope->parentScope, 0); //line and column still not working
    }
#line 2569 "./src/syntax.tab.c"
    break;

  case 10: /* varDeclaration: TYPE LIST_TYPE ID DELIM_SEMICOLLON  */
#line 193 "./src/syntax.y"
                                         {
        char* temp;
        temp = (char*) malloc(sizeof((yyvsp[-3].t_token).text) + sizeof((yyvsp[-2].t_token).text) + 3);
        strcpy(temp, (yyvsp[-3].t_token).text);
        strcat(temp, " ");
        strcat(temp, (yyvsp[-2].t_token).text);
        /* printf("%s %s %s %s - %s\n", $1.text, $2.text, $3.text, $4.text, temp); */
        createSymbol((yyvsp[-1].t_token).text, temp, (yyvsp[-1].t_token).line, (yyvsp[-1].t_token).column, (yyvsp[-1].t_token).scope->scopeValue, (yyvsp[-1].t_token).scope->parentScope, 0); //line and column still not working
    }
#line 2583 "./src/syntax.tab.c"
    break;

  case 11: /* funcDeclaration: TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R bodyStatement  */
#line 219 "./src/syntax.y"
                                                                   {
        /* printf("%s %s %s %s - escopo %d %d\n", $1.text, $2.text, $3.text, $5.text, $2.scope->scopeValue, $2.scope->parentScope); */
        createSymbol((yyvsp[-4].t_token).text, (yyvsp[-5].t_token).text, (yyvsp[-4].t_token).line, (yyvsp[-4].t_token).column, (yyvsp[-4].t_token).scope->scopeValue, (yyvsp[-4].t_token).scope->parentScope, 1); //line and column still not working
    }
#line 2592 "./src/syntax.tab.c"
    break;

  case 12: /* funcDeclaration: TYPE LIST_TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R bodyStatement  */
#line 223 "./src/syntax.y"
                                                                               {
        char* temp;
        temp = (char*) malloc(sizeof((yyvsp[-6].t_token).text) + sizeof((yyvsp[-5].t_token).text) + 3);
        strcpy(temp, (yyvsp[-6].t_token).text);
        strcat(temp, " ");
        strcat(temp, (yyvsp[-5].t_token).text);
        /* printf("%s %s %s %s %s - %s - escopo %d %d\n", $1.text, $2.text, $3.text, $4.text, $6.text, temp, $3.scope->scopeValue, $3.scope->parentScope); */
        createSymbol((yyvsp[-4].t_token).text, temp, (yyvsp[-4].t_token).line, (yyvsp[-4].t_token).column, (yyvsp[-4].t_token).scope->scopeValue, (yyvsp[-4].t_token).scope->parentScope, 1); //line and column still not working
    }
#line 2606 "./src/syntax.tab.c"
    break;

  case 13: /* parameters: parameterList  */
#line 235 "./src/syntax.y"
                  {}
#line 2612 "./src/syntax.tab.c"
    break;

  case 14: /* parameters: %empty  */
#line 236 "./src/syntax.y"
      {}
#line 2618 "./src/syntax.tab.c"
    break;

  case 15: /* parameterList: parameterList DELIM_COMMA TYPE ID  */
#line 240 "./src/syntax.y"
                                      {}
#line 2624 "./src/syntax.tab.c"
    break;

  case 16: /* parameterList: parameterList DELIM_COMMA TYPE LIST_TYPE ID  */
#line 241 "./src/syntax.y"
                                                  {}
#line 2630 "./src/syntax.tab.c"
    break;

  case 17: /* parameterList: TYPE ID  */
#line 242 "./src/syntax.y"
              {}
#line 2636 "./src/syntax.tab.c"
    break;

  case 18: /* parameterList: TYPE LIST_TYPE ID  */
#line 243 "./src/syntax.y"
                        {}
#line 2642 "./src/syntax.tab.c"
    break;

  case 19: /* statement: bodyStatement  */
#line 247 "./src/syntax.y"
                  {}
#line 2648 "./src/syntax.tab.c"
    break;

  case 20: /* statement: ifStatement  */
#line 248 "./src/syntax.y"
                  {}
#line 2654 "./src/syntax.tab.c"
    break;

  case 21: /* statement: loopStatement  */
#line 249 "./src/syntax.y"
                    {}
#line 2660 "./src/syntax.tab.c"
    break;

  case 22: /* statement: returnStatement  */
#line 250 "./src/syntax.y"
                      {}
#line 2666 "./src/syntax.tab.c"
    break;

  case 23: /* statement: listStatement DELIM_SEMICOLLON  */
#line 251 "./src/syntax.y"
                                     {}
#line 2672 "./src/syntax.tab.c"
    break;

  case 24: /* statement: writeOp DELIM_SEMICOLLON  */
#line 252 "./src/syntax.y"
                               {}
#line 2678 "./src/syntax.tab.c"
    break;

  case 25: /* statement: readOp DELIM_SEMICOLLON  */
#line 253 "./src/syntax.y"
                              {}
#line 2684 "./src/syntax.tab.c"
    break;

  case 26: /* statement: expressionStatement  */
#line 254 "./src/syntax.y"
                          {}
#line 2690 "./src/syntax.tab.c"
    break;

  case 27: /* statement: error  */
#line 255 "./src/syntax.y"
            {}
#line 2696 "./src/syntax.tab.c"
    break;

  case 28: /* bodyStatement: DELIM_CUR_BRACKET_L statementList DELIM_CUR_BRACKET_R  */
#line 259 "./src/syntax.y"
                                                          {}
#line 2702 "./src/syntax.tab.c"
    break;

  case 29: /* localDeclaration: localDeclaration varDeclaration  */
#line 267 "./src/syntax.y"
                                    {}
#line 2708 "./src/syntax.tab.c"
    break;

  case 30: /* localDeclaration: %empty  */
#line 268 "./src/syntax.y"
      {}
#line 2714 "./src/syntax.tab.c"
    break;

  case 31: /* statementList: statementList localDeclaration statement  */
#line 272 "./src/syntax.y"
                                             {}
#line 2720 "./src/syntax.tab.c"
    break;

  case 32: /* statementList: %empty  */
#line 273 "./src/syntax.y"
      {}
#line 2726 "./src/syntax.tab.c"
    break;

  case 33: /* ifStatement: IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R statement  */
#line 277 "./src/syntax.y"
                                                                                    {}
#line 2732 "./src/syntax.tab.c"
    break;

  case 34: /* ifStatement: IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R statement ELSE_KEY statement  */
#line 278 "./src/syntax.y"
                                                                                         {}
#line 2738 "./src/syntax.tab.c"
    break;

  case 35: /* loopStatement: FOR_KEY DELIM_PARENT_L expression DELIM_SEMICOLLON simpleExpression DELIM_SEMICOLLON expression DELIM_PARENT_R statement  */
#line 282 "./src/syntax.y"
                                                                                                                             {}
#line 2744 "./src/syntax.tab.c"
    break;

  case 36: /* returnStatement: RETURN_KEY expression DELIM_SEMICOLLON  */
#line 286 "./src/syntax.y"
                                           {}
#line 2750 "./src/syntax.tab.c"
    break;

  case 37: /* expression: ID ASSIGN_OP expression  */
#line 290 "./src/syntax.y"
                            {}
#line 2756 "./src/syntax.tab.c"
    break;

  case 38: /* expression: simpleExpression  */
#line 291 "./src/syntax.y"
                       {}
#line 2762 "./src/syntax.tab.c"
    break;

  case 39: /* simpleExpression: logicBinExpression  */
#line 300 "./src/syntax.y"
                       {}
#line 2768 "./src/syntax.tab.c"
    break;

  case 40: /* logicBinExpression: logicBinExpression LOGIC_OP logicUnExpression  */
#line 309 "./src/syntax.y"
                                                  {}
#line 2774 "./src/syntax.tab.c"
    break;

  case 41: /* logicBinExpression: logicUnExpression  */
#line 310 "./src/syntax.y"
                        {}
#line 2780 "./src/syntax.tab.c"
    break;

  case 42: /* logicUnExpression: EXCLA_OP logicUnExpression  */
#line 314 "./src/syntax.y"
                               {}
#line 2786 "./src/syntax.tab.c"
    break;

  case 43: /* logicUnExpression: binExpression  */
#line 315 "./src/syntax.y"
                    {}
#line 2792 "./src/syntax.tab.c"
    break;

  case 44: /* binExpression: binExpression BINARY_OP sumExpression  */
#line 323 "./src/syntax.y"
                                          {}
#line 2798 "./src/syntax.tab.c"
    break;

  case 45: /* binExpression: sumExpression  */
#line 324 "./src/syntax.y"
                    {}
#line 2804 "./src/syntax.tab.c"
    break;

  case 46: /* sumExpression: sumExpression sumOP mulExpression  */
#line 328 "./src/syntax.y"
                                      {}
#line 2810 "./src/syntax.tab.c"
    break;

  case 47: /* sumExpression: mulExpression  */
#line 329 "./src/syntax.y"
                    {}
#line 2816 "./src/syntax.tab.c"
    break;

  case 48: /* mulExpression: mulExpression mulOP factor  */
#line 333 "./src/syntax.y"
                               {}
#line 2822 "./src/syntax.tab.c"
    break;

  case 49: /* mulExpression: factor  */
#line 334 "./src/syntax.y"
             {}
#line 2828 "./src/syntax.tab.c"
    break;

  case 50: /* sumOP: PLUS_OP  */
#line 338 "./src/syntax.y"
            {}
#line 2834 "./src/syntax.tab.c"
    break;

  case 51: /* sumOP: MINUS_OP  */
#line 339 "./src/syntax.y"
               {}
#line 2840 "./src/syntax.tab.c"
    break;

  case 52: /* mulOP: MUL_OP  */
#line 343 "./src/syntax.y"
           {}
#line 2846 "./src/syntax.tab.c"
    break;

  case 53: /* mulOP: DIV_OP  */
#line 344 "./src/syntax.y"
             {}
#line 2852 "./src/syntax.tab.c"
    break;

  case 54: /* factor: ID  */
#line 348 "./src/syntax.y"
       {}
#line 2858 "./src/syntax.tab.c"
    break;

  case 55: /* factor: constant  */
#line 349 "./src/syntax.y"
               {}
#line 2864 "./src/syntax.tab.c"
    break;

  case 56: /* factor: DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 350 "./src/syntax.y"
                                                     {}
#line 2870 "./src/syntax.tab.c"
    break;

  case 57: /* factor: functionCall  */
#line 351 "./src/syntax.y"
                   {}
#line 2876 "./src/syntax.tab.c"
    break;

  case 58: /* factor: listExpression  */
#line 352 "./src/syntax.y"
                     {}
#line 2882 "./src/syntax.tab.c"
    break;

  case 59: /* constant: INT  */
#line 356 "./src/syntax.y"
        {}
#line 2888 "./src/syntax.tab.c"
    break;

  case 60: /* constant: MINUS_OP INT  */
#line 357 "./src/syntax.y"
                   {}
#line 2894 "./src/syntax.tab.c"
    break;

  case 61: /* constant: FLOAT  */
#line 358 "./src/syntax.y"
            {}
#line 2900 "./src/syntax.tab.c"
    break;

  case 62: /* constant: MINUS_OP FLOAT  */
#line 359 "./src/syntax.y"
                     {}
#line 2906 "./src/syntax.tab.c"
    break;

  case 63: /* constant: NULL_CONST  */
#line 360 "./src/syntax.y"
                 {}
#line 2912 "./src/syntax.tab.c"
    break;

  case 64: /* functionCall: ID DELIM_PARENT_L parametersPass DELIM_PARENT_R  */
#line 364 "./src/syntax.y"
                                                    {}
#line 2918 "./src/syntax.tab.c"
    break;

  case 65: /* parametersPass: parametersPass DELIM_COMMA simpleExpression  */
#line 368 "./src/syntax.y"
                                                {}
#line 2924 "./src/syntax.tab.c"
    break;

  case 66: /* parametersPass: simpleExpression  */
#line 369 "./src/syntax.y"
                       {}
#line 2930 "./src/syntax.tab.c"
    break;

  case 67: /* parametersPass: %empty  */
#line 370 "./src/syntax.y"
      {}
#line 2936 "./src/syntax.tab.c"
    break;

  case 68: /* writeOp: write  */
#line 374 "./src/syntax.y"
          {}
#line 2942 "./src/syntax.tab.c"
    break;

  case 69: /* writeOp: writeln  */
#line 375 "./src/syntax.y"
              {}
#line 2948 "./src/syntax.tab.c"
    break;

  case 70: /* write: OUTPUT_KEY DELIM_PARENT_L STRING DELIM_PARENT_R  */
#line 379 "./src/syntax.y"
                                                    {}
#line 2954 "./src/syntax.tab.c"
    break;

  case 71: /* write: OUTPUT_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 380 "./src/syntax.y"
                                                                {}
#line 2960 "./src/syntax.tab.c"
    break;

  case 72: /* writeln: OUTPUTLN_KEY DELIM_PARENT_L STRING DELIM_PARENT_R  */
#line 384 "./src/syntax.y"
                                                      {}
#line 2966 "./src/syntax.tab.c"
    break;

  case 73: /* writeln: OUTPUTLN_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 385 "./src/syntax.y"
                                                                  {}
#line 2972 "./src/syntax.tab.c"
    break;

  case 74: /* readOp: INPUT_KEY DELIM_PARENT_L ID DELIM_PARENT_R  */
#line 389 "./src/syntax.y"
                                               {}
#line 2978 "./src/syntax.tab.c"
    break;

  case 75: /* expressionStatement: expression DELIM_SEMICOLLON  */
#line 393 "./src/syntax.y"
                                {}
#line 2984 "./src/syntax.tab.c"
    break;

  case 76: /* listStatement: listAssign  */
#line 397 "./src/syntax.y"
               {}
#line 2990 "./src/syntax.tab.c"
    break;

  case 77: /* listStatement: listMap  */
#line 398 "./src/syntax.y"
              {}
#line 2996 "./src/syntax.tab.c"
    break;

  case 78: /* listStatement: listFilter  */
#line 399 "./src/syntax.y"
                 {}
#line 3002 "./src/syntax.tab.c"
    break;

  case 79: /* listExpression: listHeader  */
#line 403 "./src/syntax.y"
               {}
#line 3008 "./src/syntax.tab.c"
    break;

  case 80: /* listExpression: listTailDestructor  */
#line 405 "./src/syntax.y"
                         {}
#line 3014 "./src/syntax.tab.c"
    break;

  case 81: /* listAssign: ID ASSIGN_OP ID ASSIGN_LISTOP ID  */
#line 409 "./src/syntax.y"
                                     {}
#line 3020 "./src/syntax.tab.c"
    break;

  case 82: /* listHeader: HEADER_LISTOP ID  */
#line 413 "./src/syntax.y"
                     {}
#line 3026 "./src/syntax.tab.c"
    break;

  case 83: /* listTailDestructor: TAILDES_LISTOP ID  */
#line 421 "./src/syntax.y"
                      {}
#line 3032 "./src/syntax.tab.c"
    break;

  case 84: /* listMap: ID ASSIGN_OP ID MAP_LISTOP ID  */
#line 425 "./src/syntax.y"
                                  {}
#line 3038 "./src/syntax.tab.c"
    break;

  case 85: /* listFilter: ID ASSIGN_OP ID FILTER_LISTOP ID  */
#line 429 "./src/syntax.y"
                                     {}
#line 3044 "./src/syntax.tab.c"
    break;


#line 3048 "./src/syntax.tab.c"

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

#line 433 "./src/syntax.y"

/* Additional C code */

void yyerror(const char* s){
    printf("Syntax error: %s\nLine: %d - Column: %d\n", s, line, column);
    syntaticError = syntaticError + 1;
}

int main(int argc, char **argv){
    FILE *filep;

    line = 1;
    column = 1;
    lexicalError = 0;
    syntaticError = 0;

    /* createSymbol("Teste");
    printTable(); */

    /* Inicializa a pilha de escopo com um valor para o escopo global */
    lastScopeValue++;
    pushScope(lastScopeValue, -1);



    if(argc >= 2) {
        filep = fopen(argv[1], "r");

        if(filep != NULL){
            /* print_start(); */

            yyin = filep;
            /* yylex(); */
            yyparse();
            fclose(yyin);

            printf("Analyzer completed with %d lexical and %d syntatic errors.\n\n\n", lexicalError, syntaticError);


            /* printTable(); */
            printTable2();

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
