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
#include "format.h"

extern int yylex();
extern int yylex_destroy();
extern int yyparse();
extern void yyerror(const char* s);
extern FILE* yyin;


#line 85 "./src/syntax.tab.c"

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
  YYSYMBOL_varDeclList = 50,               /* varDeclList  */
  YYSYMBOL_varDeclId = 51,                 /* varDeclId  */
  YYSYMBOL_funcDeclaration = 52,           /* funcDeclaration  */
  YYSYMBOL_parameters = 53,                /* parameters  */
  YYSYMBOL_parameterList = 54,             /* parameterList  */
  YYSYMBOL_statement = 55,                 /* statement  */
  YYSYMBOL_bodyStatement = 56,             /* bodyStatement  */
  YYSYMBOL_localDeclaration = 57,          /* localDeclaration  */
  YYSYMBOL_statementList = 58,             /* statementList  */
  YYSYMBOL_ifStatement = 59,               /* ifStatement  */
  YYSYMBOL_loopStatement = 60,             /* loopStatement  */
  YYSYMBOL_returnStatement = 61,           /* returnStatement  */
  YYSYMBOL_expression = 62,                /* expression  */
  YYSYMBOL_simpleExpression = 63,          /* simpleExpression  */
  YYSYMBOL_logicBinExpression = 64,        /* logicBinExpression  */
  YYSYMBOL_logicUnExpression = 65,         /* logicUnExpression  */
  YYSYMBOL_binExpression = 66,             /* binExpression  */
  YYSYMBOL_sumExpression = 67,             /* sumExpression  */
  YYSYMBOL_mulExpression = 68,             /* mulExpression  */
  YYSYMBOL_sumOP = 69,                     /* sumOP  */
  YYSYMBOL_mulOP = 70,                     /* mulOP  */
  YYSYMBOL_factor = 71,                    /* factor  */
  YYSYMBOL_constant = 72,                  /* constant  */
  YYSYMBOL_functionCall = 73,              /* functionCall  */
  YYSYMBOL_parametersPass = 74,            /* parametersPass  */
  YYSYMBOL_writeOp = 75,                   /* writeOp  */
  YYSYMBOL_write = 76,                     /* write  */
  YYSYMBOL_writeln = 77,                   /* writeln  */
  YYSYMBOL_readOp = 78,                    /* readOp  */
  YYSYMBOL_expressionStatement = 79,       /* expressionStatement  */
  YYSYMBOL_listStatement = 80,             /* listStatement  */
  YYSYMBOL_listExpression = 81,            /* listExpression  */
  YYSYMBOL_listAssign = 82,                /* listAssign  */
  YYSYMBOL_listHeader = 83,                /* listHeader  */
  YYSYMBOL_listTailDestructor = 84,        /* listTailDestructor  */
  YYSYMBOL_listMap = 85,                   /* listMap  */
  YYSYMBOL_listFilter = 86                 /* listFilter  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1749

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

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
       0,   105,   105,   109,   110,   114,   115,   119,   120,   124,
     125,   129,   133,   137,   138,   142,   143,   147,   148,   149,
     150,   151,   152,   153,   154,   158,   162,   163,   167,   168,
     172,   173,   177,   181,   185,   186,   195,   204,   205,   209,
     210,   218,   219,   223,   224,   228,   229,   233,   234,   238,
     239,   243,   244,   245,   246,   247,   251,   252,   256,   260,
     261,   262,   266,   267,   271,   272,   276,   277,   281,   285,
     289,   290,   291,   295,   297,   301,   305,   313,   317,   321
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
  "declaration", "varDeclaration", "varDeclList", "varDeclId",
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
     295,   296,   297,   298,   299
};
#endif

#define YYPACT_NINF (-188)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,    20,    39,    23,   105,   135,   138,    36,    63,   100,
     147,  -188,   174,     4,   182,   232,    63,   176,    77,   119,
     190,   210,   243,   367,  1361,   116,   273,   535,   141,    71,
      96,   143,   638,   145,   163,   173,   206,   217,   676,   809,
     234,   247,   265,   272,   302,   192,   211,    -1,     7,     3,
     213,   712,   723,   771,   780,   215,   263,   264,   284,   309,
     285,   940,   286,   968,   996,   298,   313,   307,   736,    11,
      80,    12,   676,   638,   318,   328,   341,   162,   490,  1024,
    1052,   246,   842,   311,    71,    29,   104,  1232,    29,  1260,
    1288,    29,   314,   319,   368,   401,   348,   342,   425,   438,
     355,   351,   638,   394,   365,   374,   382,   392,   393,  1080,
      95,   875,   240,   202,    16,   504,  1108,  1136,   429,   431,
     444,  1164,   770,   418,    71,   416,   434,   448,   449,   455,
     420,   395,   462,   466,   467,   439,    48,   468,   472,  1204,
     406,   478,   472,   415,   810,  1576,   326,   676,   507,   508,
     676,    47,    55,   133,   356,  1582,  1588,  1610,  1616,  1622,
    1644,  1650,   839,   872,  1386,   770,   516,   517,   676,    89,
      92,    49,   663,   905,  1392,  1398,  1425,  1431,  1437,  1464,
     493,   494,   638,   809,   424,  1025,  1053,  1081,   488,   495,
     497,  1109,   502,    63,   254,   809,  1554,   499,    11,   131,
    1656,  1678,   509,   676,  1316,  1316,  1316,    11,   181,  1470,
    1476,   511,   770,  1344,  1344,  1344,   676,   638,   506,   842,
    1137,  1165,  1193,  1221,   256,   908,   842,  1204,   441,  1684,
     171,   453,  1690,  1712,   465,  1503,   200,  1527,  1509,  1515,
     520,   515,  1249,   519,   941,   522,   524,  1718,  1542,   526,
      71,  1277,   127,   809,   969,   521,   842,   527,  1204,   528,
    1305,   531,   997,   527,  1333
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
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
    -188,  -188,  -188,   566,    57,    -6,   554,  -188,  -188,  -188,
     547,   -24,  -176,  -107,   555,   556,   558,   -23,   561,   582,
     -26,   545,   459,   388,  -150,  -149,    -7,    91,   177,  -187,
     560,  -188,  -188,   563,   565,   570,   204,  -188,   275,   361,
    -188,  -188
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,   111,     9,    10,     6,    19,    20,
     112,   184,    82,   113,   185,   186,   187,   188,    46,    47,
      48,    49,    50,    51,    88,    91,    52,    53,    54,    99,
     189,    56,    57,   190,   191,   192,    61,    62,    63,    64,
      65,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    45,    15,    71,   205,   130,   206,   219,     1,    75,
      18,   228,   152,    84,   162,   163,   164,   -40,    85,   226,
     234,   -38,   214,    -2,   215,     7,   -39,     8,   165,     1,
     -37,   156,    26,    27,    70,   -14,   -36,   166,   167,    11,
     -40,   168,   -61,   170,   -38,    97,   152,   -61,   -30,   -39,
     101,   152,   152,   -37,   -30,    36,    37,     5,   114,    38,
       5,   203,   174,   -40,   213,   156,    13,   138,    14,   -38,
     156,   156,   -11,   -11,    26,    27,    70,   256,   -36,    97,
     -40,   205,    23,   206,   117,   -40,   -38,   214,    29,   215,
     -51,   -51,   -51,   -51,   -51,   -51,   170,    36,    37,   136,
      14,    38,   193,   212,   194,    -4,   -38,   -47,   -47,   -47,
      69,    -4,   243,   152,   140,   174,   141,   -51,   143,   245,
     -36,   199,    67,   -38,   152,   -36,    72,   -25,   -38,   157,
     -47,   -47,   156,   -25,   -47,    -5,    16,    17,    -6,   208,
     156,    -5,   152,   156,    -6,   -39,   -25,   -40,   204,   259,
      24,   -51,   -51,   -51,   -51,   -51,   -51,    68,   174,   218,
     175,   156,   -39,   157,   -40,   144,   145,   146,   157,   157,
     105,    69,   170,    73,    -3,    76,    -7,   230,   -51,   147,
      -3,   170,    -7,   -10,   -10,   -37,   236,   224,   148,   149,
     152,   174,   150,    77,   241,   -39,   156,   156,   156,   233,
     174,   152,   -37,    78,   246,   174,   174,   174,   239,   156,
      -8,    79,   -39,   175,   -37,   158,    -8,   -39,   -11,   -11,
     156,   -13,    80,    86,    87,   254,    25,   -42,   -42,    83,
     157,   -37,   152,   260,   -12,   261,   -37,   131,   157,   264,
     -12,   157,   159,    26,    27,    28,   176,   -17,   -35,   158,
     -42,   156,    92,   -17,   158,   158,   175,    29,   180,   157,
     181,   182,    33,    34,    35,   -18,    36,    37,    16,    21,
      38,   -18,   -19,   177,   183,   -29,   159,   109,   -19,    -9,
      -9,   159,   159,   -56,   -56,   -56,   -56,   -56,   -56,   175,
      16,   225,    16,   244,   157,   157,   157,   157,   175,   176,
     -62,   -63,   -20,   175,   175,   175,   175,   157,   -20,   -24,
     -56,   -69,    95,   160,   -22,   -24,   158,   -69,   157,   -23,
     -22,    93,    94,   -70,   158,   -23,   177,   158,   -51,   -51,
     -51,   -51,   -51,   -51,   102,   -71,   -51,   -51,   -51,   -51,
     -51,   -51,   176,   159,   178,   158,   104,   160,    69,   157,
     -72,   159,   160,   160,   159,   -51,   198,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   102,   103,    86,    87,   -21,   177,
     -42,   -42,   159,   118,   -21,   176,   119,   120,    69,   -34,
     158,   158,   158,   158,   176,   -51,   123,   -42,   124,   176,
     176,   176,   176,   158,   -33,   -25,   125,   178,   -16,   161,
     -33,   -25,   177,   -16,   158,   126,   -31,   159,   159,   159,
     159,   177,   -31,   127,   160,   -32,   177,   177,   177,   177,
     159,   -32,   160,   128,   129,   160,   155,   -17,   -17,   -17,
     179,   159,   -15,   161,   132,   158,   133,   -15,   161,   161,
     178,   -17,   -17,   160,   -17,   -17,   -17,   -17,   -17,   134,
     -17,   -17,   195,   -68,   -17,   -28,   -60,   173,   -17,   -17,
     155,   -60,   159,    86,    87,   155,   155,   -41,   -41,   121,
     -59,   -64,   247,   178,   122,   -59,   116,   122,   160,   160,
     160,   160,   178,   179,   -41,   -65,   -66,   178,   178,   178,
     178,   160,   -67,   144,   145,   146,   248,   154,   107,   -75,
     161,   122,   160,   -78,   -79,   139,    39,   147,   161,   142,
     173,   161,   200,   201,    86,    87,   148,   149,   -41,   -41,
     150,   209,   210,   216,   217,   220,   179,   155,   172,   161,
     -35,   154,   221,   160,   222,   155,   154,   154,   155,   223,
     229,   -41,   235,   242,   115,   -57,   -57,   -57,   -57,   -57,
     -57,   249,   250,   173,   251,   -34,   155,   252,   258,   179,
     253,   183,   263,   262,   161,   161,   161,   161,   179,    12,
      22,    40,   -57,   179,   179,   179,   179,   161,     0,    42,
      43,   172,    44,   153,    55,     0,   173,    58,   161,    59,
       0,   155,   155,   232,    60,   173,     0,     0,   154,    81,
     173,   173,   238,     0,   155,     0,   154,     0,     0,   154,
       0,     0,     0,     0,   171,   155,     0,   153,     0,   161,
     151,     0,   153,   153,   172,     0,     0,   154,     0,     0,
      98,     0,     0,   100,     0,     0,     0,     0,   106,   108,
       0,    26,    27,    74,     0,     0,   155,     0,     0,     0,
       0,   169,     0,     0,   151,    29,     0,   172,     0,   151,
     151,     0,   154,   231,    36,    37,   172,   171,    38,     0,
       0,   172,   237,    86,    87,   154,     0,   -42,   -42,   144,
     145,   146,     0,   135,   153,   137,   154,     0,     0,     0,
       0,     0,   153,   147,   -42,   153,     0,     0,     0,   -42,
     197,     0,   148,   149,   169,     0,   150,     0,     0,     0,
     171,   202,     0,   153,     0,     0,     0,   154,     0,     0,
       0,   151,   -44,   -44,    89,    90,   -44,   -44,     0,   211,
       0,     0,   151,   -46,   -46,   -46,   -46,   -46,   -46,    26,
      27,    96,     0,   171,     0,     0,     0,     0,   153,   -44,
     151,     0,   171,    29,     0,     0,     0,   171,     0,    98,
     -46,   153,    36,    37,     0,     0,    38,     0,    98,     0,
       0,     0,   153,   162,   163,   164,     0,   240,     0,     0,
     169,   -52,   -52,   -52,   -52,   -52,   -52,   165,   197,   169,
     -54,   -54,   -54,   -54,   -54,   -54,   166,   167,   151,     0,
     168,     0,     0,   153,     0,     0,     0,     0,   -52,   151,
       0,   255,   -27,   -27,   -27,   -27,     0,   -54,     0,   197,
     -56,   -56,   -56,   -56,   -56,   -56,   -27,   -27,     0,   -27,
     -27,   -27,   -27,   -27,     0,   -27,   -27,     0,     0,   -27,
     151,   -56,     0,   -27,   -27,    26,    27,    28,   110,   -56,
     -56,   -56,   -56,   -56,   -56,     0,     0,     0,     0,    29,
     180,     0,   181,   182,    33,    34,    35,     0,    36,    37,
     -56,     0,    38,     0,     0,   -56,   183,   -29,   -26,   -26,
     -26,   -26,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
       0,     0,   -26,   -26,     0,   -26,   -26,   -26,   -26,   -26,
       0,   -26,   -26,   -57,     0,   -26,     0,     0,   -57,   -26,
     -26,    -7,    -7,    -7,    -7,   -44,   -44,    89,    90,   -44,
     -44,     0,     0,     0,     0,    -7,    -7,     0,    -7,    -7,
      -7,    -7,    -7,     0,    -7,    -7,   -44,     0,    -7,     0,
       0,   -44,    -7,    -7,    -8,    -8,    -8,    -8,     0,     0,
     -55,   -55,   -55,   -55,   -55,   -55,     0,     0,    -8,    -8,
       0,    -8,    -8,    -8,    -8,    -8,     0,    -8,    -8,     0,
       0,    -8,   -30,   -30,   -30,    -8,    -8,   -55,   -73,   -73,
     -73,   -73,   -73,   -73,     0,     0,   -30,   -30,   257,   -30,
     -30,   -30,   -30,   -30,     0,   -30,   -30,     0,     0,   -30,
     -25,   -25,   -25,   -30,   -30,   -73,   -74,   -74,   -74,   -74,
     -74,   -74,     0,     0,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,     0,   -25,   -25,     0,     0,   -25,   -18,   -18,
     -18,   -25,   -25,   -74,   -76,   -76,   -76,   -76,   -76,   -76,
       0,     0,   -18,   -18,     0,   -18,   -18,   -18,   -18,   -18,
       0,   -18,   -18,     0,     0,   -18,   -19,   -19,   -19,   -18,
     -18,   -76,   -77,   -77,   -77,   -77,   -77,   -77,     0,     0,
     -19,   -19,     0,   -19,   -19,   -19,   -19,   -19,     0,   -19,
     -19,     0,     0,   -19,   -20,   -20,   -20,   -19,   -19,   -77,
     -53,   -53,   -53,   -53,   -53,   -53,     0,     0,   -20,   -20,
       0,   -20,   -20,   -20,   -20,   -20,     0,   -20,   -20,     0,
       0,   -20,   -24,   -24,   -24,   -20,   -20,   -53,   -43,   -43,
      89,    90,   -43,   -43,     0,     0,   -24,   -24,     0,   -24,
     -24,   -24,   -24,   -24,     0,   -24,   -24,     0,     0,   -24,
     -69,   -69,   -69,   -24,   -24,   -43,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,   -69,   -69,     0,   -69,   -69,   -69,
     -69,   -69,     0,   -69,   -69,     0,     0,   -69,   -22,   -22,
     -22,   -69,   -69,   -45,   -58,   -58,   -58,   -58,   -58,   -58,
       0,     0,   -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,
       0,   -22,   -22,     0,     0,   -22,   -23,   -23,   -23,   -22,
     -22,   -58,     0,     0,     0,     0,     0,   144,   145,   196,
     -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,     0,   -23,
     -23,   147,     0,   -23,   -21,   -21,   -21,   -23,   -23,     0,
     148,   149,     0,     0,   150,   -48,   -48,   -48,   -21,   -21,
       0,   -21,   -21,   -21,   -21,   -21,     0,   -21,   -21,     0,
       0,   -21,   -33,   -33,   -33,   -21,   -21,     0,   -48,   -48,
       0,     0,   -48,   -50,   -50,   -50,   -33,   -33,     0,   -33,
     -33,   -33,   -33,   -33,     0,   -33,   -33,     0,     0,   -33,
     -25,   -25,   -25,   -33,   -33,     0,   -50,   -50,     0,     0,
     -50,   -49,   -49,   -49,   -25,   -25,     0,   -25,   -25,   -25,
     -25,   -25,     0,   -25,   -25,     0,     0,   -25,   -31,   -31,
     -31,   -25,   -25,     0,   -49,   -49,     0,     0,   -49,   144,
     145,   146,   -31,   -31,     0,   -31,   -31,   -31,   -31,   -31,
       0,   -31,   -31,     0,     0,   -31,   -32,   -32,   -32,   -31,
     -31,     0,   148,   149,     0,     0,   150,   162,   163,   164,
     -32,   -32,     0,   -32,   -32,   -32,   -32,   -32,     0,   -32,
     -32,     0,     0,   -32,    26,    27,    28,   -32,   -32,     0,
     166,   167,     0,     0,   168,     0,     0,     0,    29,    30,
       0,    31,    32,    33,    34,    35,     0,    36,    37,     0,
       0,    38,     0,     0,     0,    39,   -51,   -51,   -51,   -51,
     -51,   -51,   -46,   -46,   -46,   -46,   -46,   -46,   -52,   -52,
     -52,   -52,   -52,   -52,     0,     0,   207,   -51,     0,     0,
       0,     0,   -51,   -46,     0,     0,     0,     0,   -46,   -52,
       0,     0,     0,     0,   -52,   -54,   -54,   -54,   -54,   -54,
     -54,   -55,   -55,   -55,   -55,   -55,   -55,   -73,   -73,   -73,
     -73,   -73,   -73,     0,     0,     0,   -54,     0,     0,     0,
       0,   -54,   -55,     0,     0,     0,     0,   -55,   -73,     0,
       0,     0,     0,   -73,   -74,   -74,   -74,   -74,   -74,   -74,
     -76,   -76,   -76,   -76,   -76,   -76,   -77,   -77,   -77,   -77,
     -77,   -77,     0,     0,     0,   -74,     0,     0,     0,     0,
     -74,   -76,     0,     0,     0,     0,   -76,   -77,     0,     0,
       0,     0,   -77,   -53,   -53,   -53,   -53,   -53,   -53,   -43,
     -43,    89,    90,   -43,   -43,   -45,   -45,   -45,   -45,   -45,
     -45,     0,     0,     0,   -53,     0,     0,    86,    87,   -53,
     -43,   -41,   -41,     0,     0,   -43,   -45,     0,     0,     0,
       0,   -45,   -58,   -58,   -58,   -58,   -58,   -58,   -41,     0,
       0,     0,     0,   -41,   -51,   -51,   -51,   -51,   -51,   -51,
     227,     0,     0,   -58,     0,     0,     0,     0,   -58,     0,
       0,     0,     0,     0,   198,   -51,   -57,   -57,   -57,   -57,
     -57,   -57,   -44,   -44,    89,    90,   -44,   -44,   -46,   -46,
     -46,   -46,   -46,   -46,     0,     0,     0,   -57,     0,     0,
       0,     0,     0,   -44,     0,     0,     0,     0,     0,   -46,
     -52,   -52,   -52,   -52,   -52,   -52,   -54,   -54,   -54,   -54,
     -54,   -54,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,   -52,     0,     0,     0,     0,     0,   -54,     0,     0,
       0,     0,     0,   -55,   -73,   -73,   -73,   -73,   -73,   -73,
     -74,   -74,   -74,   -74,   -74,   -74,   -76,   -76,   -76,   -76,
     -76,   -76,     0,     0,     0,   -73,     0,     0,     0,     0,
       0,   -74,     0,     0,     0,     0,     0,   -76,   -77,   -77,
     -77,   -77,   -77,   -77,   -53,   -53,   -53,   -53,   -53,   -53,
     -43,   -43,    89,    90,   -43,   -43,     0,     0,     0,   -77,
       0,     0,     0,     0,     0,   -53,     0,     0,     0,     0,
       0,   -43,   -45,   -45,   -45,   -45,   -45,   -45,   -58,   -58,
     -58,   -58,   -58,   -58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -45,     0,     0,     0,     0,     0,   -58
};

static const yytype_int16 yycheck[] =
{
      24,    24,     8,    29,   154,   112,   155,   183,     6,    32,
       6,   198,    38,    14,     3,     4,     5,    14,    15,   195,
     207,    14,   172,     0,   173,     5,    14,     7,    17,     6,
      14,    38,     3,     4,     5,    31,    37,    26,    27,     0,
      37,    30,    31,    69,    37,    68,    72,    36,     0,    37,
      73,    77,    78,    37,     6,    26,    27,     0,    84,    30,
       3,    14,    69,    14,    15,    72,    30,    19,     5,    14,
      77,    78,    36,    37,     3,     4,     5,   253,    31,   102,
      31,   231,     5,   232,    91,    36,    31,   237,    17,   238,
      10,    11,    12,    13,    14,    15,   122,    26,    27,   123,
       5,    30,     7,    14,   110,     0,    14,     3,     4,     5,
      30,     6,   219,   139,   138,   122,   139,    37,   142,   226,
      31,   147,     6,    31,   150,    36,    30,     0,    36,    38,
      26,    27,   139,     6,    30,     0,    36,    37,     0,   165,
     147,     6,   168,   150,     6,    14,    19,    14,    15,   256,
      31,    10,    11,    12,    13,    14,    15,    16,   165,   182,
      69,   168,    31,    72,    31,     3,     4,     5,    77,    78,
       8,    30,   198,    30,     0,    30,     0,   203,    37,    17,
       6,   207,     6,    36,    37,    14,   212,   193,    26,    27,
     216,   198,    30,    30,   217,    14,   203,   204,   205,   206,
     207,   227,    31,    30,   227,   212,   213,   214,   215,   216,
       0,     5,    31,   122,    14,    38,     6,    36,    36,    37,
     227,    31,     5,    10,    11,   249,    36,    14,    15,    37,
     139,    31,   258,   257,     0,   258,    36,    35,   147,   263,
       6,   150,    38,     3,     4,     5,    69,     0,    37,    72,
      37,   258,    37,     6,    77,    78,   165,    17,    18,   168,
      20,    21,    22,    23,    24,     0,    26,    27,    36,    37,
      30,     6,     0,    69,    34,    35,    72,    31,     6,    36,
      37,    77,    78,    10,    11,    12,    13,    14,    15,   198,
      36,    37,    36,    37,   203,   204,   205,   206,   207,   122,
      37,    37,     0,   212,   213,   214,   215,   216,     6,     0,
      37,     0,     5,    38,     0,     6,   139,     6,   227,     0,
       6,    37,    37,    37,   147,     6,   122,   150,    10,    11,
      12,    13,    14,    15,    16,    37,    10,    11,    12,    13,
      14,    15,   165,   139,    69,   168,     5,    72,    30,   258,
      37,   147,    77,    78,   150,    37,    30,    31,    10,    11,
      12,    13,    14,    15,    16,    37,    10,    11,     0,   165,
      14,    15,   168,    25,     6,   198,    28,    29,    30,    37,
     203,   204,   205,   206,   207,    37,    31,    31,    37,   212,
     213,   214,   215,   216,     0,     0,    31,   122,    31,    38,
       6,     6,   198,    36,   227,    31,     0,   203,   204,   205,
     206,   207,     6,    31,   139,     0,   212,   213,   214,   215,
     216,     6,   147,    31,    31,   150,    38,     3,     4,     5,
      69,   227,    31,    72,     5,   258,     5,    36,    77,    78,
     165,    17,    18,   168,    20,    21,    22,    23,    24,     5,
      26,    27,    34,    37,    30,    35,    31,    69,    34,    35,
      72,    36,   258,    10,    11,    77,    78,    14,    15,    31,
      31,    37,    31,   198,    36,    36,    88,    36,   203,   204,
     205,   206,   207,   122,    31,    37,    37,   212,   213,   214,
     215,   216,    37,     3,     4,     5,    31,    38,     8,    37,
     139,    36,   227,    37,    37,    37,    34,    17,   147,    31,
     122,   150,     5,     5,    10,    11,    26,    27,    14,    15,
      30,     5,     5,    30,    30,    37,   165,   139,    69,   168,
      31,    72,    37,   258,    37,   147,    77,    78,   150,    37,
      31,    37,    31,    37,    85,    10,    11,    12,    13,    14,
      15,    31,    37,   165,    35,    31,   168,    35,    37,   198,
      34,    34,    31,    35,   203,   204,   205,   206,   207,     3,
      16,    24,    37,   212,   213,   214,   215,   216,    -1,    24,
      24,   122,    24,    38,    24,    -1,   198,    24,   227,    24,
      -1,   203,   204,   205,    24,   207,    -1,    -1,   139,    38,
     212,   213,   214,    -1,   216,    -1,   147,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    69,   227,    -1,    72,    -1,   258,
      38,    -1,    77,    78,   165,    -1,    -1,   168,    -1,    -1,
      69,    -1,    -1,    72,    -1,    -1,    -1,    -1,    77,    78,
      -1,     3,     4,     5,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    72,    17,    -1,   198,    -1,    77,
      78,    -1,   203,   204,    26,    27,   207,   122,    30,    -1,
      -1,   212,   213,    10,    11,   216,    -1,    14,    15,     3,
       4,     5,    -1,   122,   139,   124,   227,    -1,    -1,    -1,
      -1,    -1,   147,    17,    31,   150,    -1,    -1,    -1,    36,
     139,    -1,    26,    27,   122,    -1,    30,    -1,    -1,    -1,
     165,   150,    -1,   168,    -1,    -1,    -1,   258,    -1,    -1,
      -1,   139,    10,    11,    12,    13,    14,    15,    -1,   168,
      -1,    -1,   150,    10,    11,    12,    13,    14,    15,     3,
       4,     5,    -1,   198,    -1,    -1,    -1,    -1,   203,    37,
     168,    -1,   207,    17,    -1,    -1,    -1,   212,    -1,   198,
      37,   216,    26,    27,    -1,    -1,    30,    -1,   207,    -1,
      -1,    -1,   227,     3,     4,     5,    -1,   216,    -1,    -1,
     198,    10,    11,    12,    13,    14,    15,    17,   227,   207,
      10,    11,    12,    13,    14,    15,    26,    27,   216,    -1,
      30,    -1,    -1,   258,    -1,    -1,    -1,    -1,    37,   227,
      -1,   250,     3,     4,     5,     6,    -1,    37,    -1,   258,
      10,    11,    12,    13,    14,    15,    17,    18,    -1,    20,
      21,    22,    23,    24,    -1,    26,    27,    -1,    -1,    30,
     258,    31,    -1,    34,    35,     3,     4,     5,     6,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    22,    23,    24,    -1,    26,    27,
      31,    -1,    30,    -1,    -1,    36,    34,    35,     3,     4,
       5,     6,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    22,    23,    24,
      -1,    26,    27,    31,    -1,    30,    -1,    -1,    36,    34,
      35,     3,     4,     5,     6,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      22,    23,    24,    -1,    26,    27,    31,    -1,    30,    -1,
      -1,    36,    34,    35,     3,     4,     5,     6,    -1,    -1,
      10,    11,    12,    13,    14,    15,    -1,    -1,    17,    18,
      -1,    20,    21,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    30,     3,     4,     5,    34,    35,    37,    10,    11,
      12,    13,    14,    15,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    -1,    -1,    30,
       3,     4,     5,    34,    35,    37,    10,    11,    12,    13,
      14,    15,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    30,     3,     4,
       5,    34,    35,    37,    10,    11,    12,    13,    14,    15,
      -1,    -1,    17,    18,    -1,    20,    21,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    30,     3,     4,     5,    34,
      35,    37,    10,    11,    12,    13,    14,    15,    -1,    -1,
      17,    18,    -1,    20,    21,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    30,     3,     4,     5,    34,    35,    37,
      10,    11,    12,    13,    14,    15,    -1,    -1,    17,    18,
      -1,    20,    21,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    30,     3,     4,     5,    34,    35,    37,    10,    11,
      12,    13,    14,    15,    -1,    -1,    17,    18,    -1,    20,
      21,    22,    23,    24,    -1,    26,    27,    -1,    -1,    30,
       3,     4,     5,    34,    35,    37,    10,    11,    12,    13,
      14,    15,    -1,    -1,    17,    18,    -1,    20,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    30,     3,     4,
       5,    34,    35,    37,    10,    11,    12,    13,    14,    15,
      -1,    -1,    17,    18,    -1,    20,    21,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    30,     3,     4,     5,    34,
      35,    37,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      17,    18,    -1,    20,    21,    22,    23,    24,    -1,    26,
      27,    17,    -1,    30,     3,     4,     5,    34,    35,    -1,
      26,    27,    -1,    -1,    30,     3,     4,     5,    17,    18,
      -1,    20,    21,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    30,     3,     4,     5,    34,    35,    -1,    26,    27,
      -1,    -1,    30,     3,     4,     5,    17,    18,    -1,    20,
      21,    22,    23,    24,    -1,    26,    27,    -1,    -1,    30,
       3,     4,     5,    34,    35,    -1,    26,    27,    -1,    -1,
      30,     3,     4,     5,    17,    18,    -1,    20,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    30,     3,     4,
       5,    34,    35,    -1,    26,    27,    -1,    -1,    30,     3,
       4,     5,    17,    18,    -1,    20,    21,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    30,     3,     4,     5,    34,
      35,    -1,    26,    27,    -1,    -1,    30,     3,     4,     5,
      17,    18,    -1,    20,    21,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    30,     3,     4,     5,    34,    35,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    -1,    34,    10,    11,    12,    13,
      14,    15,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    36,    31,    -1,    -1,    -1,    -1,    36,    31,
      -1,    -1,    -1,    -1,    36,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    36,    31,    -1,    -1,    -1,    -1,    36,    31,    -1,
      -1,    -1,    -1,    36,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      36,    31,    -1,    -1,    -1,    -1,    36,    31,    -1,    -1,
      -1,    -1,    36,    10,    11,    12,    13,    14,    15,    10,
      11,    12,    13,    14,    15,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    31,    -1,    -1,    10,    11,    36,
      31,    14,    15,    -1,    -1,    36,    31,    -1,    -1,    -1,
      -1,    36,    10,    11,    12,    13,    14,    15,    31,    -1,
      -1,    -1,    -1,    36,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    30,    31,    10,    11,    12,    13,
      14,    15,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    31,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    31,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    31,    10,    11,
      12,    13,    14,    15,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    31,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    46,    47,    48,    49,    52,     5,     7,    50,
      51,     0,    48,    30,     5,    50,    36,    37,     6,    53,
      54,    37,    51,     5,    31,    36,     3,     4,     5,    17,
      18,    20,    21,    22,    23,    24,    26,    27,    30,    34,
      55,    56,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    71,    72,    73,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     6,    16,    30,
       5,    65,    30,    30,     5,    62,    30,    30,    30,     5,
       5,    63,    57,    37,    14,    15,    10,    11,    69,    12,
      13,    70,    37,    37,    37,     5,     5,    62,    63,    74,
      63,    62,    16,    37,     5,     8,    63,     8,    63,    31,
       6,    49,    55,    58,    65,    67,    68,    71,    25,    28,
      29,    31,    36,    31,    37,    31,    31,    31,    31,    31,
      58,    35,     5,     5,     5,    63,    56,    63,    19,    37,
      56,    62,    31,    56,     3,     4,     5,    17,    26,    27,
      30,    64,    65,    66,    67,    68,    71,    72,    73,    81,
      83,    84,     3,     4,     5,    17,    26,    27,    30,    64,
      65,    66,    67,    68,    71,    72,    73,    81,    83,    84,
      18,    20,    21,    34,    56,    59,    60,    61,    62,    75,
      78,    79,    80,     7,    50,    34,     5,    63,    30,    65,
       5,     5,    63,    14,    15,    69,    70,    30,    65,     5,
       5,    63,    14,    15,    69,    70,    30,    30,    62,    57,
      37,    37,    37,    37,    50,    37,    57,    16,    74,    31,
      65,    67,    68,    71,    74,    31,    65,    67,    68,    71,
      63,    62,    37,    58,    37,    58,    62,    31,    31,    31,
      37,    35,    35,    34,    56,    63,    57,    19,    37,    58,
      56,    62,    35,    31,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    57,    57,    58,    58,
      59,    59,    60,    61,    62,    62,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    72,    72,    73,    74,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    79,
      80,    80,    80,    81,    81,    82,    83,    84,    85,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     4,     3,
       1,     1,     6,     1,     0,     4,     2,     1,     1,     1,
       1,     2,     2,     2,     1,     4,     2,     0,     2,     0,
       5,     7,     9,     3,     3,     1,     1,     3,     1,     2,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     4,     3,
       1,     0,     1,     1,     4,     4,     4,     4,     4,     2,
       1,     1,     1,     1,     1,     5,     2,     2,     5,     5
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
#line 105 "./src/syntax.y"
                    { printf("%d\n", yyvsp[0]); }
#line 1902 "./src/syntax.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 109 "./src/syntax.y"
                                {printf("%d %d\n", yyvsp[-1], yyvsp[0]);}
#line 1908 "./src/syntax.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 110 "./src/syntax.y"
                  {printf("%d\n", yyvsp[0]);}
#line 1914 "./src/syntax.tab.c"
    break;

  case 5: /* declaration: varDeclaration  */
#line 114 "./src/syntax.y"
                   {printf("%d\n", yyvsp[0]);}
#line 1920 "./src/syntax.tab.c"
    break;

  case 6: /* declaration: funcDeclaration  */
#line 115 "./src/syntax.y"
                      {printf("%d\n", yyvsp[0]);}
#line 1926 "./src/syntax.tab.c"
    break;

  case 7: /* varDeclaration: TYPE varDeclList DELIM_SEMICOLLON  */
#line 119 "./src/syntax.y"
                                      {printf("%d %d %d\n", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1932 "./src/syntax.tab.c"
    break;

  case 8: /* varDeclaration: TYPE LIST_TYPE varDeclList DELIM_SEMICOLLON  */
#line 120 "./src/syntax.y"
                                                  {printf("%d %d %d %d\n", yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1938 "./src/syntax.tab.c"
    break;

  case 9: /* varDeclList: varDeclList DELIM_COMMA varDeclId  */
#line 124 "./src/syntax.y"
                                      {printf("%d %d\n", yyvsp[-2], yyvsp[-1]);}
#line 1944 "./src/syntax.tab.c"
    break;

  case 10: /* varDeclList: varDeclId  */
#line 125 "./src/syntax.y"
                {printf("%d\n", yyvsp[0]);}
#line 1950 "./src/syntax.tab.c"
    break;

  case 11: /* varDeclId: ID  */
#line 129 "./src/syntax.y"
       {printf("%d\n", yyvsp[0]);}
#line 1956 "./src/syntax.tab.c"
    break;

  case 12: /* funcDeclaration: TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R statement  */
#line 133 "./src/syntax.y"
                                                               {printf("%d %d %d %d %d %d\n", yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1962 "./src/syntax.tab.c"
    break;

  case 13: /* parameters: parameterList  */
#line 137 "./src/syntax.y"
                  {printf("%d\n", yyvsp[0]);}
#line 1968 "./src/syntax.tab.c"
    break;

  case 14: /* parameters: %empty  */
#line 138 "./src/syntax.y"
      {}
#line 1974 "./src/syntax.tab.c"
    break;

  case 15: /* parameterList: parameterList DELIM_COMMA TYPE ID  */
#line 142 "./src/syntax.y"
                                      {printf("%d %d %d\n", yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 1980 "./src/syntax.tab.c"
    break;

  case 16: /* parameterList: TYPE ID  */
#line 143 "./src/syntax.y"
              {printf("%d %d\n", yyvsp[-1], yyvsp[0]);}
#line 1986 "./src/syntax.tab.c"
    break;

  case 17: /* statement: bodyStatement  */
#line 147 "./src/syntax.y"
                  {printf("%d\n", yyvsp[0]);}
#line 1992 "./src/syntax.tab.c"
    break;

  case 18: /* statement: ifStatement  */
#line 148 "./src/syntax.y"
                  {printf("%d\n", yyvsp[0]);}
#line 1998 "./src/syntax.tab.c"
    break;

  case 19: /* statement: loopStatement  */
#line 149 "./src/syntax.y"
                    {printf("%d\n", yyvsp[0]);}
#line 2004 "./src/syntax.tab.c"
    break;

  case 20: /* statement: returnStatement  */
#line 150 "./src/syntax.y"
                      {printf("%d\n", yyvsp[0]);}
#line 2010 "./src/syntax.tab.c"
    break;

  case 21: /* statement: listStatement DELIM_SEMICOLLON  */
#line 151 "./src/syntax.y"
                                     {printf("%d\n", yyvsp[-1]);}
#line 2016 "./src/syntax.tab.c"
    break;

  case 22: /* statement: writeOp DELIM_SEMICOLLON  */
#line 152 "./src/syntax.y"
                               {printf("%d\n", yyvsp[-1]);}
#line 2022 "./src/syntax.tab.c"
    break;

  case 23: /* statement: readOp DELIM_SEMICOLLON  */
#line 153 "./src/syntax.y"
                              {printf("%d\n", yyvsp[-1]);}
#line 2028 "./src/syntax.tab.c"
    break;

  case 24: /* statement: expressionStatement  */
#line 154 "./src/syntax.y"
                          {printf("%d\n", yyvsp[0]);}
#line 2034 "./src/syntax.tab.c"
    break;

  case 25: /* bodyStatement: DELIM_CUR_BRACKET_L localDeclaration statementList DELIM_CUR_BRACKET_R  */
#line 158 "./src/syntax.y"
                                                                           {printf("%d %d %d %d\n", yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2040 "./src/syntax.tab.c"
    break;

  case 26: /* localDeclaration: localDeclaration varDeclaration  */
#line 162 "./src/syntax.y"
                                    {printf("%d %d\n", yyvsp[-1], yyvsp[0]);}
#line 2046 "./src/syntax.tab.c"
    break;

  case 27: /* localDeclaration: %empty  */
#line 163 "./src/syntax.y"
      {}
#line 2052 "./src/syntax.tab.c"
    break;

  case 28: /* statementList: statement statementList  */
#line 167 "./src/syntax.y"
                            {printf("%d %d\n", yyvsp[-1], yyvsp[0]);}
#line 2058 "./src/syntax.tab.c"
    break;

  case 29: /* statementList: %empty  */
#line 168 "./src/syntax.y"
      {}
#line 2064 "./src/syntax.tab.c"
    break;

  case 30: /* ifStatement: IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R bodyStatement  */
#line 172 "./src/syntax.y"
                                                                        {printf("%d %d %d %d %d\n", yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2070 "./src/syntax.tab.c"
    break;

  case 31: /* ifStatement: IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R bodyStatement ELSE_KEY bodyStatement  */
#line 173 "./src/syntax.y"
                                                                                                 {printf("%d %d %d %d %d %d %d\n", yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2076 "./src/syntax.tab.c"
    break;

  case 32: /* loopStatement: FOR_KEY DELIM_PARENT_L expression DELIM_SEMICOLLON simpleExpression DELIM_SEMICOLLON expression DELIM_PARENT_R bodyStatement  */
#line 177 "./src/syntax.y"
                                                                                                                                 {printf("%d %d %d %d %d %d %d %d %d\n", yyvsp[-8], yyvsp[-7], yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2082 "./src/syntax.tab.c"
    break;

  case 33: /* returnStatement: RETURN_KEY expression DELIM_SEMICOLLON  */
#line 181 "./src/syntax.y"
                                           {printf("%d %d\n", yyvsp[-2], yyvsp[-1]);}
#line 2088 "./src/syntax.tab.c"
    break;

  case 34: /* expression: ID ASSIGN_OP expression  */
#line 185 "./src/syntax.y"
                            {printf("%d %d %d\n", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2094 "./src/syntax.tab.c"
    break;

  case 35: /* expression: simpleExpression  */
#line 186 "./src/syntax.y"
                       {printf("%d\n", yyvsp[0]);}
#line 2100 "./src/syntax.tab.c"
    break;

  case 36: /* simpleExpression: logicBinExpression  */
#line 195 "./src/syntax.y"
                       {printf("%d\n", yyvsp[0]);}
#line 2106 "./src/syntax.tab.c"
    break;

  case 37: /* logicBinExpression: logicBinExpression LOGIC_OP logicUnExpression  */
#line 204 "./src/syntax.y"
                                                  {printf("%d %d %d\n", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2112 "./src/syntax.tab.c"
    break;

  case 38: /* logicBinExpression: logicUnExpression  */
#line 205 "./src/syntax.y"
                        {printf("%d\n", yyvsp[0]);}
#line 2118 "./src/syntax.tab.c"
    break;

  case 39: /* logicUnExpression: EXCLA_OP logicUnExpression  */
#line 209 "./src/syntax.y"
                               {printf("%d %d\n", yyvsp[-1], yyvsp[0]);}
#line 2124 "./src/syntax.tab.c"
    break;

  case 40: /* logicUnExpression: binExpression  */
#line 210 "./src/syntax.y"
                    {printf("%d\n", yyvsp[0]);}
#line 2130 "./src/syntax.tab.c"
    break;

  case 41: /* binExpression: binExpression BINARY_OP sumExpression  */
#line 218 "./src/syntax.y"
                                          {printf("%d %d %d\n", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2136 "./src/syntax.tab.c"
    break;

  case 42: /* binExpression: sumExpression  */
#line 219 "./src/syntax.y"
                    {printf("%d\n", yyvsp[0]);}
#line 2142 "./src/syntax.tab.c"
    break;

  case 43: /* sumExpression: sumExpression sumOP mulExpression  */
#line 223 "./src/syntax.y"
                                      {printf("%d %d %d\n", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2148 "./src/syntax.tab.c"
    break;

  case 44: /* sumExpression: mulExpression  */
#line 224 "./src/syntax.y"
                    {printf("%d\n", yyvsp[0]);}
#line 2154 "./src/syntax.tab.c"
    break;

  case 45: /* mulExpression: mulExpression mulOP factor  */
#line 228 "./src/syntax.y"
                               {printf("%d %d %d\n", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2160 "./src/syntax.tab.c"
    break;

  case 46: /* mulExpression: factor  */
#line 229 "./src/syntax.y"
             {printf("%d\n", yyvsp[0]);}
#line 2166 "./src/syntax.tab.c"
    break;

  case 47: /* sumOP: PLUS_OP  */
#line 233 "./src/syntax.y"
            {printf("%d\n", yyvsp[0]);}
#line 2172 "./src/syntax.tab.c"
    break;

  case 48: /* sumOP: MINUS_OP  */
#line 234 "./src/syntax.y"
               {printf("%d\n", yyvsp[0]);}
#line 2178 "./src/syntax.tab.c"
    break;

  case 49: /* mulOP: MUL_OP  */
#line 238 "./src/syntax.y"
           {printf("%d\n", yyvsp[0]);}
#line 2184 "./src/syntax.tab.c"
    break;

  case 50: /* mulOP: DIV_OP  */
#line 239 "./src/syntax.y"
             {printf("%d\n", yyvsp[0]);}
#line 2190 "./src/syntax.tab.c"
    break;

  case 51: /* factor: ID  */
#line 243 "./src/syntax.y"
       {printf("%d\n", yyvsp[0]);}
#line 2196 "./src/syntax.tab.c"
    break;

  case 52: /* factor: constant  */
#line 244 "./src/syntax.y"
               {printf("%d\n", yyvsp[0]);}
#line 2202 "./src/syntax.tab.c"
    break;

  case 53: /* factor: DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 245 "./src/syntax.y"
                                                     {printf("%d %d %d\n", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2208 "./src/syntax.tab.c"
    break;

  case 54: /* factor: functionCall  */
#line 246 "./src/syntax.y"
                   {printf("%d\n", yyvsp[0]);}
#line 2214 "./src/syntax.tab.c"
    break;

  case 55: /* factor: listExpression  */
#line 247 "./src/syntax.y"
                     {printf("%d\n", yyvsp[0]);}
#line 2220 "./src/syntax.tab.c"
    break;

  case 56: /* constant: INT  */
#line 251 "./src/syntax.y"
        {printf("%d\n", yyvsp[0]);}
#line 2226 "./src/syntax.tab.c"
    break;

  case 57: /* constant: FLOAT  */
#line 252 "./src/syntax.y"
            {printf("%d\n", yyvsp[0]);}
#line 2232 "./src/syntax.tab.c"
    break;

  case 58: /* functionCall: ID DELIM_PARENT_L parametersPass DELIM_PARENT_R  */
#line 256 "./src/syntax.y"
                                                    {printf("%d %d %d %d\n", yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2238 "./src/syntax.tab.c"
    break;

  case 59: /* parametersPass: parametersPass DELIM_COMMA simpleExpression  */
#line 260 "./src/syntax.y"
                                                {printf("%d %d %d\n", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2244 "./src/syntax.tab.c"
    break;

  case 60: /* parametersPass: simpleExpression  */
#line 261 "./src/syntax.y"
                       {printf("%d\n", yyvsp[0]);}
#line 2250 "./src/syntax.tab.c"
    break;

  case 61: /* parametersPass: %empty  */
#line 262 "./src/syntax.y"
      {}
#line 2256 "./src/syntax.tab.c"
    break;

  case 62: /* writeOp: write  */
#line 266 "./src/syntax.y"
          {printf("%d\n", yyvsp[0]);}
#line 2262 "./src/syntax.tab.c"
    break;

  case 63: /* writeOp: writeln  */
#line 267 "./src/syntax.y"
              {printf("%d\n", yyvsp[0]);}
#line 2268 "./src/syntax.tab.c"
    break;

  case 64: /* write: OUTPUT_KEY DELIM_PARENT_L STRING DELIM_PARENT_R  */
#line 271 "./src/syntax.y"
                                                    {printf("%d %d %d\n", yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 2274 "./src/syntax.tab.c"
    break;

  case 65: /* write: OUTPUT_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 272 "./src/syntax.y"
                                                                {printf("%d %d %d\n", yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 2280 "./src/syntax.tab.c"
    break;

  case 66: /* writeln: OUTPUTLN_KEY DELIM_PARENT_L STRING DELIM_PARENT_R  */
#line 276 "./src/syntax.y"
                                                      {printf("%d %d %d\n", yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 2286 "./src/syntax.tab.c"
    break;

  case 67: /* writeln: OUTPUTLN_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 277 "./src/syntax.y"
                                                                  {printf("%d %d %d\n", yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 2292 "./src/syntax.tab.c"
    break;

  case 68: /* readOp: INPUT_KEY DELIM_PARENT_L ID DELIM_PARENT_R  */
#line 281 "./src/syntax.y"
                                               {printf("%d %d %d\n", yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 2298 "./src/syntax.tab.c"
    break;

  case 69: /* expressionStatement: expression DELIM_SEMICOLLON  */
#line 285 "./src/syntax.y"
                                {printf("%d\n", yyvsp[-1]);}
#line 2304 "./src/syntax.tab.c"
    break;

  case 70: /* listStatement: listAssign  */
#line 289 "./src/syntax.y"
               {printf("%d\n", yyvsp[0]);}
#line 2310 "./src/syntax.tab.c"
    break;

  case 71: /* listStatement: listMap  */
#line 290 "./src/syntax.y"
              {printf("%d\n", yyvsp[0]);}
#line 2316 "./src/syntax.tab.c"
    break;

  case 72: /* listStatement: listFilter  */
#line 291 "./src/syntax.y"
                 {printf("%d\n", yyvsp[0]);}
#line 2322 "./src/syntax.tab.c"
    break;

  case 73: /* listExpression: listHeader  */
#line 295 "./src/syntax.y"
               {printf("%d\n", yyvsp[0]);}
#line 2328 "./src/syntax.tab.c"
    break;

  case 74: /* listExpression: listTailDestructor  */
#line 297 "./src/syntax.y"
                         {printf("%d\n", yyvsp[0]);}
#line 2334 "./src/syntax.tab.c"
    break;

  case 75: /* listAssign: ID ASSIGN_OP ID ASSIGN_LISTOP ID  */
#line 301 "./src/syntax.y"
                                     {printf("%d %d %d %d %d\n", yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2340 "./src/syntax.tab.c"
    break;

  case 76: /* listHeader: HEADER_LISTOP ID  */
#line 305 "./src/syntax.y"
                     {printf("%d %d\n", yyvsp[-1], yyvsp[0]);}
#line 2346 "./src/syntax.tab.c"
    break;

  case 77: /* listTailDestructor: TAILDES_LISTOP ID  */
#line 313 "./src/syntax.y"
                      {printf("%d %d\n", yyvsp[-1], yyvsp[0]);}
#line 2352 "./src/syntax.tab.c"
    break;

  case 78: /* listMap: ID ASSIGN_OP ID MAP_LISTOP ID  */
#line 317 "./src/syntax.y"
                                  {printf("%d %d %d %d %d\n", yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2358 "./src/syntax.tab.c"
    break;

  case 79: /* listFilter: ID ASSIGN_OP ID FILTER_LISTOP ID  */
#line 321 "./src/syntax.y"
                                     {printf("%d %d %d %d %d\n", yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2364 "./src/syntax.tab.c"
    break;


#line 2368 "./src/syntax.tab.c"

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

#line 325 "./src/syntax.y"

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
