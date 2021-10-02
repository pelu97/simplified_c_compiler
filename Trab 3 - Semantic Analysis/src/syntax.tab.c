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
#include "../lib/base.h"
#include "../lib/symbol_table.h"
#include "../lib/scope.h"
#include "../lib/tree.h"
#include "../lib/semantic.h"

extern int yylex();
extern int yylex_destroy();
extern int yyparse();
extern void yyerror(const char* s);
extern FILE* yyin;

//yynerrs //global variable counting errors

/*
For semantic analysis:

-- 1 or 2 passes?

--Type check:
-check function parameters: quantity and types on every use;
-check operators arguments types;

--Scope:
-check if variables used (identifiers) have been declared inside the scope or in any parent scope;

--Main
-detect existence of main function;
--Checando, mas poderia registrar a linha do registro;
--Poderia estender parte da checagem para todas as funções - verificar e informar caso ocorram redefinições de funções


---Notes:
-Function parameters: preciso armazenar quantos parâmetros e os tipos deles no registro de funções na tabela de símbolos, para que seja possível
verificar se as chamadas à função estão corretas;
Talvez uma lista de um struct próprio para isso; ou talvez um vetor de strings e uma variável para armazenar a quantidade, onde cada string é o tipo
Parâmetros estão sendo armazenados - vetor de símbolos, é possível acessar o que quiser
*/


#line 117 "./src/syntax.tab.c"

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
  YYSYMBOL_parameterSimple = 54,           /* parameterSimple  */
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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4727

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  344

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
       0,   201,   201,   209,   218,   221,   229,   235,   238,   244,
     268,   311,   339,   374,   378,   384,   392,   399,   421,   452,
     455,   458,   461,   464,   467,   470,   473,   476,   482,   493,
     501,   507,   517,   523,   531,   544,   557,   567,   576,   587,
     598,   609,   615,   625,   635,   646,   652,   663,   669,   682,
     688,   691,   697,   700,   706,   723,   726,   729,   732,   738,
     753,   768,   783,   798,   815,   837,   845,   848,   854,   857,
     863,   866,   876,   879,   889,   907,   913,   916,   919,   925,
     929,   935,   967,   989,  1007,  1031
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
  "funcDeclaration", "parameters", "parameterList", "parameterSimple",
  "statement", "bodyStatement", "localDeclaration", "statementList",
  "ifStatement", "loopStatement", "returnStatement", "expression",
  "simpleExpression", "logicBinExpression", "logicUnExpression",
  "binExpression", "sumExpression", "mulExpression", "sumOP", "mulOP",
  "factor", "constant", "functionCall", "parametersPass", "writeOp",
  "write", "writeln", "readOp", "expressionStatement", "listStatement",
  "listExpression", "listAssign", "listHeader", "listTailDestructor",
  "listMap", "listFilter", YY_NULLPTR
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

#define YYPACT_NINF (-220)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3740,  2192,   351,   693,    60,     6,   699,   230,   176,   -14,
     -12,   406,    -8,    62,    87,    90,   119,   871,  2225,   139,
    2262,  2295,  2328,  2361,  2394,  2427,  2460,  2493,  2526,   108,
     115,    -9,     1,    12,    20,   707,   939,  1020,  1031,   121,
     128,   152,   154,  2559,   158,  4128,   161,  4143,  4149,   164,
     170,  4047,     5,    17,   151,  4157,  4163,    51,    30,   871,
     406,   282,   173,   200,  4017,  4032,  4178,  4192,   143,  2592,
    -220,  2629,  2662,  2695,   176,   167,   603,   831,   167,   956,
    4092,   167,  2728,  2761,  2794,   433,   189,    14,    48,    -4,
    2827,    50,   182,   193,   406,  2860,   205,   235,   246,   254,
     255,  4198,  2893,  3773,    39,   150,  4207,  4213,   283,   284,
     285,  4227,  4062,    38,   270,    65,    85,    -4,  2926,  3901,
     176,   266,   268,   269,   274,   287,    79,  3806,  2959,   288,
     292,   294,   181,   203,   310,   298,   335,   311,   110,   304,
     306,   341,   226,  2996,   236,   298,  3930,  4077,   314,  3029,
    3062,   321,  3930,  3095,   384,  4497,  4491,  4520,   253,   871,
     350,   352,   871,    24,    91,   137,   209,  4526,  4532,  4555,
    4561,  4567,  4590,  4596,   535,  4248,  4242,  4256,   277,  4062,
     363,   364,   871,   111,   112,    64,   234,  4284,  4290,  4296,
    4324,  4330,  4336,  4364,  3128,   342,   344,   406,  2225,  3164,
    3200,  3236,  3272,   338,   340,   343,  3308,   347,  1105,   348,
     349,   406,  2225,  1150,  1183,  1216,  1249,   354,   366,   367,
    1282,   387,  3839,  4484,   356,  3872,     5,  4602,  4625,   118,
    4631,  4637,   359,   871,  4106,  4106,  4106,     5,  4370,  4376,
     126,  4404,  4410,   361,  4062,  4121,  4121,  4121,   871,   406,
     388,  3344,  3380,  3416,  3452,  3488,   871,   406,   389,  3524,
    1315,  1348,  1381,  1414,  4077,   237,  4660,   177,   215,  4666,
    4672,   238,  4416,   169,   774,  4444,  4450,   369,   390,  3560,
    3596,   397,   394,  1447,  1480,   403,  4695,  4456,  3959,   176,
    3901,   176,  1513,   405,   408,   406,  2225,  1549,  1585,  1621,
    1657,  1693,   402,   412,   413,  1729,   415,   416,  1766,   417,
     871,   406,   419,  3632,  3988,  1799,  1835,  1871,  1907,  4077,
    3901,  4077,   420,   422,  1943,  1979,  3668,   426,  2016,   429,
    3959,   176,  3988,  3901,  2049,   430,  3704,  2086,  3959,  4077,
    2119,   437,  3959,  2155
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
       0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -220,  -220,  -220,   450,   371,  -220,   358,  -220,   250,    70,
     -78,  -220,  -192,   198,   353,   438,   -11,   708,    35,    -5,
     827,   684,   604,  -165,  -163,   103,   259,   318,  -219,   643,
    -220,  -220,   678,   748,   762,   355,  -220,   414,   568,  -220,
    -220
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,   114,   115,   116,    24,
      25,   103,    69,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    78,    81,    36,    37,    38,    88,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,   235,   113,    58,   236,    74,   251,   265,   174,   175,
     176,    53,   164,    54,   177,   -41,   178,    59,   271,    60,
     259,   246,   179,    63,   247,   199,   -43,    75,   -14,   -39,
      76,    77,   180,   181,   -45,   -45,   182,   -67,   233,   -41,
      86,   213,   -67,   133,   -42,   134,   -66,   184,    89,    93,
     -43,   -66,   163,   -40,   164,    90,   -39,   143,   -45,   164,
     164,   -54,   -54,   -54,   -54,   -54,   -54,   149,   -42,   104,
     -54,   -54,   -54,   -54,   -54,   -54,    51,   -40,   -43,   245,
     111,   117,    52,    86,   140,   112,   141,   183,   118,   -54,
      72,    52,   203,    64,   163,    66,   -43,   -13,   -54,   163,
     163,   -43,   136,   235,   313,   -41,   236,   184,   217,   246,
     -33,   -33,   247,   -33,   -33,   -33,   -33,   -16,    65,   -33,
     168,   -33,   -16,   -41,    67,   244,   -41,   -33,   -33,   146,
     -33,   -33,   -42,   -33,   -33,   -33,   151,   -33,   -33,    70,
     -42,   -33,   164,   -39,   -41,   -33,    73,   183,   -39,   -41,
     -42,   -43,   234,   -38,   229,   188,    91,   164,   -42,    82,
      76,    77,   168,   -42,   -44,   -44,   -68,   168,   168,   -43,
       2,     3,    57,   128,   240,   101,     6,   164,     7,     2,
       3,    57,   163,   -40,   107,     6,   250,     7,   -44,   138,
     -69,   -40,    83,     8,    15,    16,    84,   163,    17,   -76,
     258,   -40,   -77,    15,    16,    96,   -40,    17,   -78,   -40,
     298,    95,   213,   -65,   119,   188,   150,   163,   -65,    76,
      77,   184,   153,   -45,   -45,    76,    77,   -37,   267,   -44,
     -44,   120,   184,    55,    56,   -17,   199,   121,   278,   273,
     -17,   -45,   213,   164,    76,    77,   282,   -44,   -45,   -45,
     168,   164,   298,   285,   199,   213,   227,   228,   -18,   164,
     298,   183,   168,   -18,   298,   168,   -45,   122,   -15,   286,
     287,   -45,   183,   -15,   112,   112,   169,   302,   123,   217,
     238,   239,   188,   163,   312,   168,   124,   125,   129,   130,
     131,   163,   -54,   -54,   -54,   -54,   -54,   -54,    94,   163,
     323,   200,   135,   203,   -74,   164,   -70,   -71,   327,   217,
     329,   189,   -72,    52,   164,   142,   164,   214,   169,   302,
     -54,   203,   217,   169,   169,   -73,   -81,   302,   341,   188,
     -84,   302,   -85,    18,   164,   170,   168,   168,   168,   270,
     188,   113,   147,   145,   222,   163,   148,   188,   188,   188,
     276,   168,   225,   152,   163,   230,   163,   231,   297,   168,
     308,   -59,   -59,   -59,   -59,   -59,   -59,   168,   241,   242,
     190,   189,   171,   248,   163,   249,   252,   170,   253,   256,
     257,   254,   170,   170,   326,   255,   144,     0,   -38,   -59,
     328,   266,   260,   272,   -59,   -59,   -59,   -59,   -59,   -59,
     334,   288,   336,   337,   261,   262,   169,   191,   340,     2,
       3,    61,   343,   168,   171,     6,   -59,     7,   169,   171,
     171,   169,   168,     8,   168,   263,   279,   283,   289,   290,
     190,   172,   291,    15,    16,   -37,   310,    17,   189,   311,
     315,   169,   168,   -54,   -54,   -54,   -54,   -54,   -54,    94,
     316,   317,   330,   318,   319,   321,   201,   324,   332,   108,
     331,   333,   109,   110,    52,   170,   192,   191,   339,   342,
      71,   -54,   215,   172,   127,   137,     0,   170,   172,   172,
     170,     0,     0,     0,     0,   189,   299,     0,   214,     0,
       0,     0,   169,   169,   169,   169,   189,   190,     0,     0,
     170,     0,   171,   189,   189,   189,   189,   169,     0,     0,
       0,     0,   200,     0,   171,   169,     0,   171,   214,     0,
       0,     0,     0,   169,     0,     0,   192,     0,   299,     0,
     200,   214,     0,     0,   191,     0,   299,   171,     0,     0,
     299,   202,     0,     0,   190,   -59,   -59,   -59,   -59,   -59,
     -59,   170,   170,   170,   170,   190,     0,   216,     0,     0,
       0,   172,   190,   190,   190,   190,   170,   -59,     0,   169,
       0,     0,   -59,   172,   170,     0,   172,     0,   169,     0,
     169,   191,   170,     0,     0,   173,     0,     0,   171,   171,
     171,   171,   191,   192,     0,     0,   172,     0,   169,   191,
     191,   191,   191,   171,     0,     0,   -50,   -50,   -50,     0,
       0,   171,   -50,     0,   -50,     0,     0,     0,     0,   171,
     193,   167,     0,     0,     0,     0,     0,   173,   170,     0,
     -50,   -50,   173,   173,   -50,     0,     0,   170,     0,   170,
     192,   300,     0,   215,     0,     0,     0,   172,   172,   172,
     172,   192,     0,     0,     0,     0,   187,   170,   192,   192,
     192,   192,   172,   167,     0,   171,     0,   201,   167,   167,
     172,     0,     0,   215,   171,     0,   171,     0,   172,     0,
     193,     0,   106,   300,     0,   201,   215,     0,     0,     0,
       0,   300,     0,     0,   171,   300,     0,     0,     0,     0,
       0,   166,     0,   -61,   -61,   -61,   -61,   -61,   -61,   -63,
     -63,   -63,   -63,   -63,   -63,   173,   187,   -47,   -47,    79,
      80,   -47,   -47,     0,   172,    68,   301,   173,   216,     0,
     173,   -61,     0,   172,     0,   172,   186,   -63,     0,     0,
       0,     0,     0,   166,     0,   -47,   204,   193,   166,   166,
     173,   167,   202,   172,     0,     0,     0,     0,   216,   105,
      87,     0,   218,   167,     0,     0,   167,    92,   301,     0,
     202,   216,    98,   100,     0,     0,   301,     0,     0,     0,
     301,   205,     0,   187,    76,    77,   167,     0,   -44,   -44,
       0,     0,     0,     0,   193,     0,   186,   219,     0,     0,
       0,   173,   173,   173,   173,   193,   -44,     0,     0,     0,
       0,   -44,   193,   193,   193,   193,   173,     0,     0,     0,
     132,     0,     0,     0,   173,     0,     0,     0,   139,     0,
     187,   166,   173,     0,   -51,   -51,   -51,   167,   167,   269,
     -51,   187,   -51,   166,   165,     0,   166,     0,   187,   187,
     275,   206,   167,     0,     0,   224,     0,     0,   -51,   -51,
     167,     0,   -51,   186,     0,   207,   166,   220,   167,     0,
     232,     0,     0,     0,   154,   155,   156,     0,   173,   185,
     157,   221,   158,     0,     0,     0,   165,   173,   159,   173,
     243,   165,   165,     0,     0,     0,     0,     0,   160,   161,
       0,     0,   162,     0,     0,     0,     0,   173,     0,     0,
     186,     0,     0,     0,   167,     0,     0,   166,   268,     0,
       0,   186,     0,   167,     0,   167,     0,     0,   186,   274,
       0,   303,   166,   218,    87,     0,     0,     0,     0,   185,
     166,     0,     0,   167,     0,    87,     0,     0,   166,   -49,
     -49,   -49,   -49,   -49,   -49,     0,   277,   204,     0,   -53,
     -53,   -53,     0,   218,   281,   -53,   304,   -53,   219,     0,
       0,     0,   224,   303,   165,   204,   218,   -49,     0,     0,
       0,   303,     0,   -53,   -53,   303,   165,   -53,     0,   165,
       0,     0,   205,     0,   166,     0,     0,   307,   219,   309,
       0,     0,     0,   166,     0,   166,   185,     0,   304,   165,
     205,   219,     0,     0,     0,     0,   304,     0,   322,     0,
     304,     0,     0,   166,     0,     0,     0,   224,     0,   224,
     -55,   -55,   -55,   -55,   -55,   -55,   305,     0,   220,   335,
       0,   -57,   -57,   -57,   -57,   -57,   -57,   224,     0,     0,
     306,     0,   221,   185,     0,     0,     0,     0,   -55,     0,
     165,     0,   206,     0,   185,     0,     0,     0,   220,   -57,
       0,   185,     0,     0,     0,   165,   207,     0,   305,     0,
     206,   220,   221,   165,     0,     0,   305,     0,     0,     0,
     305,   165,   306,     0,   207,   221,     0,     0,     0,     0,
     306,     0,     0,     0,   306,   -27,   -27,     0,   -27,   -27,
     -27,   -27,     0,     0,   -27,     0,   -27,     0,     0,     0,
       0,     0,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,
     -27,     0,   -27,   -27,     0,     0,   -27,   165,     0,     0,
     -27,     0,     0,     0,     0,     0,   165,     0,   165,     0,
     -19,   -19,     0,   -19,   -19,   -19,   -19,     0,     0,   -19,
       0,   -19,     0,     0,     0,     0,   165,   -19,   -19,   -19,
     -19,   -19,     0,   -19,   -19,   -19,     0,   -19,   -19,     0,
       0,   -19,     0,   -20,   -20,   -19,   -20,   -20,   -20,   -20,
       0,     0,   -20,     0,   -20,     0,     0,     0,     0,     0,
     -20,   -20,   -20,   -20,   -20,     0,   -20,   -20,   -20,     0,
     -20,   -20,     0,     0,   -20,     0,   -21,   -21,   -20,   -21,
     -21,   -21,   -21,     0,     0,   -21,     0,   -21,     0,     0,
       0,     0,     0,   -21,   -21,   -21,   -21,   -21,     0,   -21,
     -21,   -21,     0,   -21,   -21,     0,     0,   -21,     0,   -22,
     -22,   -21,   -22,   -22,   -22,   -22,     0,     0,   -22,     0,
     -22,     0,     0,     0,     0,     0,   -22,   -22,   -22,   -22,
     -22,     0,   -22,   -22,   -22,     0,   -22,   -22,     0,     0,
     -22,     0,   -26,   -26,   -22,   -26,   -26,   -26,   -26,     0,
       0,   -26,     0,   -26,     0,     0,     0,     0,     0,   -26,
     -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,     0,   -26,
     -26,     0,     0,   -26,     0,   -75,   -75,   -26,   -75,   -75,
     -75,   -75,     0,     0,   -75,     0,   -75,     0,     0,     0,
       0,     0,   -75,   -75,   -75,   -75,   -75,     0,   -75,   -75,
     -75,     0,   -75,   -75,     0,     0,   -75,     0,   -24,   -24,
     -75,   -24,   -24,   -24,   -24,     0,     0,   -24,     0,   -24,
       0,     0,     0,     0,     0,   -24,   -24,   -24,   -24,   -24,
       0,   -24,   -24,   -24,     0,   -24,   -24,     0,     0,   -24,
       0,   -25,   -25,   -24,   -25,   -25,   -25,   -25,     0,     0,
     -25,     0,   -25,     0,     0,     0,     0,     0,   -25,   -25,
     -25,   -25,   -25,     0,   -25,   -25,   -25,     0,   -25,   -25,
       0,     0,   -25,     0,   -23,   -23,   -25,   -23,   -23,   -23,
     -23,     0,     0,   -23,     0,   -23,     0,     0,     0,     0,
       0,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,
       0,   -23,   -23,     0,     0,   -23,     0,   -36,   -36,   -23,
     -36,   -36,   -36,   -36,     0,     0,   -36,     0,   -36,     0,
       0,     0,     0,     0,   -36,   -36,   -36,   -36,   -36,     0,
     -36,   -36,   -36,     0,   -36,   -36,     0,     0,   -36,     0,
     -28,   -28,   -36,   -28,   -28,   -28,   -28,     0,     0,   -28,
       0,   -28,     0,     0,     0,     0,     0,   -28,   -28,   -28,
     -28,   -28,     0,   -28,   -28,   -28,     0,   -28,   -28,     0,
       0,   -28,     0,     0,   -27,   -28,   -27,   -27,   -27,   -27,
       0,     0,   -27,     0,   -27,     0,     0,     0,     0,     0,
     -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,     0,
     -27,   -27,     0,     0,   -27,     0,     0,     0,   -27,   -27,
     -33,     0,   -33,   -33,   -33,   -33,     0,     0,   -33,     0,
     -33,     0,     0,     0,     0,     0,   -33,   -33,   314,   -33,
     -33,     0,   -33,   -33,   -33,     0,   -33,   -33,     0,     0,
     -33,     0,     0,     0,   -33,   -33,   -19,     0,   -19,   -19,
     -19,   -19,     0,     0,   -19,     0,   -19,     0,     0,     0,
       0,     0,   -19,   -19,   -19,   -19,   -19,     0,   -19,   -19,
     -19,     0,   -19,   -19,     0,     0,   -19,     0,     0,     0,
     -19,   -19,   -20,     0,   -20,   -20,   -20,   -20,     0,     0,
     -20,     0,   -20,     0,     0,     0,     0,     0,   -20,   -20,
     -20,   -20,   -20,     0,   -20,   -20,   -20,     0,   -20,   -20,
       0,     0,   -20,     0,     0,     0,   -20,   -20,   -21,     0,
     -21,   -21,   -21,   -21,     0,     0,   -21,     0,   -21,     0,
       0,     0,     0,     0,   -21,   -21,   -21,   -21,   -21,     0,
     -21,   -21,   -21,     0,   -21,   -21,     0,     0,   -21,     0,
       0,     0,   -21,   -21,   -22,     0,   -22,   -22,   -22,   -22,
       0,     0,   -22,     0,   -22,     0,     0,     0,     0,     0,
     -22,   -22,   -22,   -22,   -22,     0,   -22,   -22,   -22,     0,
     -22,   -22,     0,     0,   -22,     0,     0,     0,   -22,   -22,
     -26,     0,   -26,   -26,   -26,   -26,     0,     0,   -26,     0,
     -26,     0,     0,     0,     0,     0,   -26,   -26,   -26,   -26,
     -26,     0,   -26,   -26,   -26,     0,   -26,   -26,     0,     0,
     -26,     0,     0,     0,   -26,   -26,   -33,   -33,     0,   -33,
     -33,   -33,   -33,     0,     0,   -33,     0,   -33,     0,     0,
       0,     0,     0,   -33,   -33,   320,   -33,   -33,     0,   -33,
     -33,   -33,     0,   -33,   -33,     0,     0,   -33,     0,     0,
     -75,   -33,   -75,   -75,   -75,   -75,     0,     0,   -75,     0,
     -75,     0,     0,     0,     0,     0,   -75,   -75,   -75,   -75,
     -75,     0,   -75,   -75,   -75,     0,   -75,   -75,     0,     0,
     -75,     0,     0,     0,   -75,   -75,   -24,     0,   -24,   -24,
     -24,   -24,     0,     0,   -24,     0,   -24,     0,     0,     0,
       0,     0,   -24,   -24,   -24,   -24,   -24,     0,   -24,   -24,
     -24,     0,   -24,   -24,     0,     0,   -24,     0,     0,     0,
     -24,   -24,   -25,     0,   -25,   -25,   -25,   -25,     0,     0,
     -25,     0,   -25,     0,     0,     0,     0,     0,   -25,   -25,
     -25,   -25,   -25,     0,   -25,   -25,   -25,     0,   -25,   -25,
       0,     0,   -25,     0,     0,     0,   -25,   -25,   -23,     0,
     -23,   -23,   -23,   -23,     0,     0,   -23,     0,   -23,     0,
       0,     0,     0,     0,   -23,   -23,   -23,   -23,   -23,     0,
     -23,   -23,   -23,     0,   -23,   -23,     0,     0,   -23,     0,
       0,     0,   -23,   -23,   -36,     0,   -36,   -36,   -36,   -36,
       0,     0,   -36,     0,   -36,     0,     0,     0,     0,     0,
     -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,   -36,     0,
     -36,   -36,     0,     0,   -36,     0,     0,     0,   -36,   -36,
     -28,     0,   -28,   -28,   -28,   -28,     0,     0,   -28,     0,
     -28,     0,     0,     0,     0,     0,   -28,   -28,   -28,   -28,
     -28,     0,   -28,   -28,   -28,     0,   -28,   -28,     0,     0,
     -28,     0,     0,     0,   -28,   -28,   -34,   -34,     0,   -34,
     -34,   -34,   -34,     0,     0,   -34,     0,   -34,     0,     0,
       0,     0,     0,   -34,   -34,   -34,   -34,   -34,     0,   -34,
     -34,   -34,     0,   -34,   -34,     0,     0,   -34,     0,     0,
     -33,   -34,   -33,   -33,   -33,   -33,     0,     0,   -33,     0,
     -33,     0,     0,     0,     0,     0,   -33,   -33,   338,   -33,
     -33,     0,   -33,   -33,   -33,     0,   -33,   -33,     0,     0,
     -33,     0,     0,     0,   -33,   -33,   -35,   -35,     0,   -35,
     -35,   -35,   -35,     0,     0,   -35,     0,   -35,     0,     0,
       0,     0,     0,   -35,   -35,   -35,   -35,   -35,     0,   -35,
     -35,   -35,     0,   -35,   -35,     0,     0,   -35,     0,     0,
     -34,   -35,   -34,   -34,   -34,   -34,     0,     0,   -34,     0,
     -34,     0,     0,     0,     0,     0,   -34,   -34,   -34,   -34,
     -34,     0,   -34,   -34,   -34,     0,   -34,   -34,     0,     0,
     -34,     0,     0,     0,   -34,   -34,   -35,     0,   -35,   -35,
     -35,   -35,     0,     0,   -35,     0,   -35,     0,     0,     0,
       0,     0,   -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,
     -35,     0,   -35,   -35,     0,     0,   -35,     0,     0,     0,
     -35,   -35,   -27,   -27,     0,   -27,   -27,   -27,   -27,     0,
       0,   -27,     0,   -27,     0,     0,     0,     0,     0,   -27,
     -27,     0,   -27,   -27,     0,   -27,   -27,   -27,     0,   -27,
     -27,     0,     0,   -27,     0,     0,   -32,   -27,   -32,   -32,
     -32,   -32,     0,     0,   -32,     0,   -32,     0,     0,     0,
       0,     0,   -32,   -32,     0,   -32,   -32,     0,   -32,   -32,
     -32,     0,   -32,   -32,     0,     0,   -32,     0,     0,     0,
     -32,   -32,    -2,     1,     0,     2,     3,     4,     5,     0,
       0,     6,     0,     7,     0,     0,     0,     0,     0,     8,
       9,     0,    10,    11,     0,    12,    13,    14,     0,    15,
      16,     0,     0,    17,     0,    -4,    -4,    18,    -4,    -4,
      -4,    -4,     0,     0,    -4,     0,    -4,     0,     0,     0,
       0,     0,    -4,    -4,     0,    -4,    -4,     0,    -4,    -4,
      -4,     0,    -4,    -4,     0,     0,    -4,     0,    -7,    -7,
      -4,    -7,    -7,    -7,    -7,     0,     0,    -7,     0,    -7,
       0,     0,     0,     0,     0,    -7,    -7,     0,    -7,    -7,
       0,    -7,    -7,    -7,     0,    -7,    -7,     0,     0,    -7,
       0,    -8,    -8,    -7,    -8,    -8,    -8,    -8,     0,     0,
      -8,     0,    -8,     0,     0,     0,     0,     0,    -8,    -8,
       0,    -8,    -8,     0,    -8,    -8,    -8,     0,    -8,    -8,
       0,     0,    -8,     0,    -6,    -6,    -8,    -6,    -6,    -6,
      -6,     0,     0,    -6,     0,    -6,     0,     0,     0,     0,
       0,    -6,    -6,     0,    -6,    -6,     0,    -6,    -6,    -6,
       0,    -6,    -6,     0,     0,    -6,     0,   -19,   -19,    -6,
     -19,   -19,   -19,   -19,     0,     0,   -19,     0,   -19,     0,
       0,     0,     0,     0,   -19,   -19,     0,   -19,   -19,     0,
     -19,   -19,   -19,     0,   -19,   -19,     0,     0,   -19,     0,
     -20,   -20,   -19,   -20,   -20,   -20,   -20,     0,     0,   -20,
       0,   -20,     0,     0,     0,     0,     0,   -20,   -20,     0,
     -20,   -20,     0,   -20,   -20,   -20,     0,   -20,   -20,     0,
       0,   -20,     0,   -21,   -21,   -20,   -21,   -21,   -21,   -21,
       0,     0,   -21,     0,   -21,     0,     0,     0,     0,     0,
     -21,   -21,     0,   -21,   -21,     0,   -21,   -21,   -21,     0,
     -21,   -21,     0,     0,   -21,     0,   -22,   -22,   -21,   -22,
     -22,   -22,   -22,     0,     0,   -22,     0,   -22,     0,     0,
       0,     0,     0,   -22,   -22,     0,   -22,   -22,     0,   -22,
     -22,   -22,     0,   -22,   -22,     0,     0,   -22,     0,   -26,
     -26,   -22,   -26,   -26,   -26,   -26,     0,     0,   -26,     0,
     -26,     0,     0,     0,     0,     0,   -26,   -26,     0,   -26,
     -26,     0,   -26,   -26,   -26,     0,   -26,   -26,     0,     0,
     -26,     0,     0,   -30,   -26,   -30,   -30,   -30,   -30,     0,
       0,   -30,     0,   -30,     0,     0,     0,     0,     0,   -30,
     -30,     0,   -30,   -30,     0,   -30,   -30,   -30,     0,   -30,
     -30,     0,     0,   -30,     0,     0,     0,   -30,   102,    -3,
      -3,     0,    -3,    -3,    -3,    -3,     0,     0,    -3,     0,
      -3,     0,     0,     0,     0,     0,    -3,    -3,     0,    -3,
      -3,     0,    -3,    -3,    -3,     0,    -3,    -3,     0,     0,
      -3,     0,    -5,    -5,    -3,    -5,    -5,    -5,    -5,     0,
       0,    -5,     0,    -5,     0,     0,     0,     0,     0,    -5,
      -5,     0,    -5,    -5,     0,    -5,    -5,    -5,     0,    -5,
      -5,     0,     0,    -5,     0,   -75,   -75,    -5,   -75,   -75,
     -75,   -75,     0,     0,   -75,     0,   -75,     0,     0,     0,
       0,     0,   -75,   -75,     0,   -75,   -75,     0,   -75,   -75,
     -75,     0,   -75,   -75,     0,     0,   -75,     0,   -24,   -24,
     -75,   -24,   -24,   -24,   -24,     0,     0,   -24,     0,   -24,
       0,     0,     0,     0,     0,   -24,   -24,     0,   -24,   -24,
       0,   -24,   -24,   -24,     0,   -24,   -24,     0,     0,   -24,
       0,   -25,   -25,   -24,   -25,   -25,   -25,   -25,     0,     0,
     -25,     0,   -25,     0,     0,     0,     0,     0,   -25,   -25,
       0,   -25,   -25,     0,   -25,   -25,   -25,     0,   -25,   -25,
       0,     0,   -25,     0,   -23,   -23,   -25,   -23,   -23,   -23,
     -23,     0,     0,   -23,     0,   -23,     0,     0,     0,     0,
       0,   -23,   -23,     0,   -23,   -23,     0,   -23,   -23,   -23,
       0,   -23,   -23,     0,     0,   -23,     0,    -9,    -9,   -23,
      -9,    -9,    -9,    -9,     0,     0,    -9,     0,    -9,     0,
       0,     0,     0,     0,    -9,    -9,     0,    -9,    -9,     0,
      -9,    -9,    -9,     0,    -9,    -9,     0,     0,    -9,     0,
     -36,   -36,    -9,   -36,   -36,   -36,   -36,     0,     0,   -36,
       0,   -36,     0,     0,     0,     0,     0,   -36,   -36,     0,
     -36,   -36,     0,   -36,   -36,   -36,     0,   -36,   -36,     0,
       0,   -36,     0,   -28,   -28,   -36,   -28,   -28,   -28,   -28,
       0,     0,   -28,     0,   -28,     0,     0,     0,     0,     0,
     -28,   -28,     0,   -28,   -28,     0,   -28,   -28,   -28,     0,
     -28,   -28,     0,     0,   -28,     0,   -10,   -10,   -28,   -10,
     -10,   -10,   -10,     0,     0,   -10,     0,   -10,     0,     0,
       0,     0,     0,   -10,   -10,     0,   -10,   -10,     0,   -10,
     -10,   -10,     0,   -10,   -10,     0,     0,   -10,     0,     0,
     -31,   -10,   -31,   -31,   -31,   -31,     0,     0,   -31,     0,
     -31,     0,     0,     0,     0,     0,   -31,   -31,     0,   -31,
     -31,     0,   -31,   -31,   -31,     0,   -31,   -31,     0,     0,
     -31,     0,     0,     0,   -31,   -31,   -11,   -11,     0,   -11,
     -11,   -11,   -11,     0,     0,   -11,     0,   -11,     0,     0,
       0,     0,     0,   -11,   -11,     0,   -11,   -11,     0,   -11,
     -11,   -11,     0,   -11,   -11,     0,     0,   -11,     0,   -12,
     -12,   -11,   -12,   -12,   -12,   -12,     0,     0,   -12,     0,
     -12,     0,     0,     0,     0,     0,   -12,   -12,     0,   -12,
     -12,     0,   -12,   -12,   -12,     0,   -12,   -12,     0,     0,
     -12,     0,   -34,   -34,   -12,   -34,   -34,   -34,   -34,     0,
       0,   -34,     0,   -34,     0,     0,     0,     0,     0,   -34,
     -34,     0,   -34,   -34,     0,   -34,   -34,   -34,     0,   -34,
     -34,     0,     0,   -34,     0,   -35,   -35,   -34,   -35,   -35,
     -35,   -35,     0,     0,   -35,     0,   -35,     0,     0,     0,
       0,     0,   -35,   -35,     0,   -35,   -35,     0,   -35,   -35,
     -35,     0,   -35,   -35,     0,     0,   -35,     0,     0,   -27,
     -35,   -27,   -27,   -27,   -27,     0,     0,   -27,     0,   -27,
       0,     0,     0,     0,     0,   -27,   -27,     0,   -27,   -27,
       0,   -27,   -27,   -27,     0,   -27,   -27,     0,     0,   -27,
       0,     0,     0,   -27,   -27,   -19,     0,   -19,   -19,   -19,
     -19,     0,     0,   -19,     0,   -19,     0,     0,     0,     0,
       0,   -19,   -19,     0,   -19,   -19,     0,   -19,   -19,   -19,
       0,   -19,   -19,     0,     0,   -19,     0,     0,     0,   -19,
     -19,   -20,     0,   -20,   -20,   -20,   -20,     0,     0,   -20,
       0,   -20,     0,     0,     0,     0,     0,   -20,   -20,     0,
     -20,   -20,     0,   -20,   -20,   -20,     0,   -20,   -20,     0,
       0,   -20,     0,     0,     0,   -20,   -20,   -21,     0,   -21,
     -21,   -21,   -21,     0,     0,   -21,     0,   -21,     0,     0,
       0,     0,     0,   -21,   -21,     0,   -21,   -21,     0,   -21,
     -21,   -21,     0,   -21,   -21,     0,     0,   -21,     0,     0,
       0,   -21,   -21,   -22,     0,   -22,   -22,   -22,   -22,     0,
       0,   -22,     0,   -22,     0,     0,     0,     0,     0,   -22,
     -22,     0,   -22,   -22,     0,   -22,   -22,   -22,     0,   -22,
     -22,     0,     0,   -22,     0,     0,     0,   -22,   -22,   -26,
       0,   -26,   -26,   -26,   -26,     0,     0,   -26,     0,   -26,
       0,     0,     0,     0,     0,   -26,   -26,     0,   -26,   -26,
       0,   -26,   -26,   -26,     0,   -26,   -26,     0,     0,   -26,
       0,     0,     0,   -26,   -26,   -30,     0,   -30,   -30,   -30,
     -30,     0,     0,   -30,     0,   -30,     0,     0,     0,     0,
       0,   -30,   -30,     0,   -30,   -30,     0,   -30,   -30,   -30,
       0,   -30,   -30,     0,     0,   -30,     0,     0,     0,   -30,
     280,   -75,     0,   -75,   -75,   -75,   -75,     0,     0,   -75,
       0,   -75,     0,     0,     0,     0,     0,   -75,   -75,     0,
     -75,   -75,     0,   -75,   -75,   -75,     0,   -75,   -75,     0,
       0,   -75,     0,     0,     0,   -75,   -75,   -24,     0,   -24,
     -24,   -24,   -24,     0,     0,   -24,     0,   -24,     0,     0,
       0,     0,     0,   -24,   -24,     0,   -24,   -24,     0,   -24,
     -24,   -24,     0,   -24,   -24,     0,     0,   -24,     0,     0,
       0,   -24,   -24,   -25,     0,   -25,   -25,   -25,   -25,     0,
       0,   -25,     0,   -25,     0,     0,     0,     0,     0,   -25,
     -25,     0,   -25,   -25,     0,   -25,   -25,   -25,     0,   -25,
     -25,     0,     0,   -25,     0,     0,     0,   -25,   -25,   -23,
       0,   -23,   -23,   -23,   -23,     0,     0,   -23,     0,   -23,
       0,     0,     0,     0,     0,   -23,   -23,     0,   -23,   -23,
       0,   -23,   -23,   -23,     0,   -23,   -23,     0,     0,   -23,
       0,     0,     0,   -23,   -23,   -30,     0,   -30,   -30,   -30,
     -30,     0,     0,   -30,     0,   -30,     0,     0,     0,     0,
       0,   -30,   -30,     0,   -30,   -30,     0,   -30,   -30,   -30,
       0,   -30,   -30,     0,     0,   -30,     0,     0,     0,   -30,
     284,   -36,     0,   -36,   -36,   -36,   -36,     0,     0,   -36,
       0,   -36,     0,     0,     0,     0,     0,   -36,   -36,     0,
     -36,   -36,     0,   -36,   -36,   -36,     0,   -36,   -36,     0,
       0,   -36,     0,     0,     0,   -36,   -36,   -28,     0,   -28,
     -28,   -28,   -28,     0,     0,   -28,     0,   -28,     0,     0,
       0,     0,     0,   -28,   -28,     0,   -28,   -28,     0,   -28,
     -28,   -28,     0,   -28,   -28,     0,     0,   -28,     0,     0,
       0,   -28,   -28,   -30,     0,   -30,   -30,   -30,   -30,     0,
       0,   -30,     0,   -30,     0,     0,     0,     0,     0,   -30,
     -30,     0,   -30,   -30,     0,   -30,   -30,   -30,     0,   -30,
     -30,     0,     0,   -30,     0,     0,     0,   -30,   325,   -34,
       0,   -34,   -34,   -34,   -34,     0,     0,   -34,     0,   -34,
       0,     0,     0,     0,     0,   -34,   -34,     0,   -34,   -34,
       0,   -34,   -34,   -34,     0,   -34,   -34,     0,     0,   -34,
       0,     0,     0,   -34,   -34,   -35,     0,   -35,   -35,   -35,
     -35,     0,     0,   -35,     0,   -35,     0,     0,     0,     0,
       0,   -35,   -35,     0,   -35,   -35,     0,   -35,   -35,   -35,
       0,   -35,   -35,     0,     0,   -35,     0,     0,     0,   -35,
     -35,     1,     0,     2,     3,     4,     5,     0,     0,     6,
       0,     7,     0,     0,     0,     0,     0,     8,     9,     0,
      10,    11,     0,    12,    13,    14,     0,    15,    16,     0,
       0,    17,     0,     0,   194,    18,     2,     3,     4,   126,
       0,     0,     6,     0,     7,     0,     0,     0,     0,     0,
       8,   195,     0,   196,   197,     0,    12,    13,    14,     0,
      15,    16,     0,     0,    17,     0,     0,   -29,   198,   -29,
     -29,   -29,   -29,     0,     0,   -29,     0,   -29,     0,     0,
       0,     0,     0,   -29,   -29,     0,   -29,   -29,     0,   -29,
     -29,   -29,     0,   -29,   -29,     0,     0,   -29,     0,     0,
      -9,   -29,    -9,    -9,    -9,    -9,     0,     0,    -9,     0,
      -9,     0,     0,     0,     0,     0,    -9,    -9,     0,    -9,
      -9,     0,    -9,    -9,    -9,     0,    -9,    -9,     0,     0,
      -9,     0,     0,   -10,    -9,   -10,   -10,   -10,   -10,     0,
       0,   -10,     0,   -10,     0,     0,     0,     0,     0,   -10,
     -10,     0,   -10,   -10,     0,   -10,   -10,   -10,     0,   -10,
     -10,     0,   208,   -10,     2,     3,     4,   -10,     0,     0,
       6,     0,     7,     0,     0,     0,     0,     0,     8,   209,
       0,   210,   211,     0,    12,    13,    14,     0,    15,    16,
       0,     1,    17,     2,     3,     4,   212,     0,     0,     6,
       0,     7,     0,     0,     0,     0,     0,     8,     9,     0,
      10,    11,     0,    12,    13,    14,     0,    15,    16,     0,
     292,    17,     2,     3,     4,    18,     0,     0,     6,     0,
       7,     0,     0,     0,     0,     0,     8,   293,     0,   294,
     295,     0,    12,    13,    14,     0,    15,    16,     0,   194,
      17,     2,     3,     4,   296,     0,     0,     6,     0,     7,
       0,     0,     0,     0,     0,     8,   195,     0,   196,   197,
       0,    12,    13,    14,     0,    15,    16,     0,     0,    17,
     154,   155,   156,   198,     0,    97,   157,     0,   158,     0,
       0,     0,     0,     0,   159,   154,   155,   156,     0,     0,
      99,   157,     0,   158,   160,   161,     0,     0,   162,   159,
       2,     3,    85,     0,     0,     0,     6,     0,     7,   160,
     161,     0,     0,   162,     8,   174,   175,   176,     0,     0,
       0,   177,     0,   178,    15,    16,     0,     0,    17,   179,
     154,   155,   223,     0,     0,     0,   157,     0,   158,   180,
     181,     0,     0,   182,   159,   -52,   -52,   -52,     0,     0,
       0,   -52,     0,   -52,   160,   161,     0,     0,   162,   154,
     155,   156,     0,     0,     0,   157,     0,   158,     0,   -52,
     -52,     0,     0,   -52,   174,   175,   176,     0,     0,     0,
     177,     0,   178,   160,   161,     0,     0,   162,   -58,   -58,
     -58,   -58,   -58,   -58,     0,     0,     0,     0,   180,   181,
       0,     0,   182,   -79,   -79,   -79,   -79,   -79,   -79,   -80,
     -80,   -80,   -80,   -80,   -80,     0,   -58,   -60,   -60,   -60,
     -60,   -60,   -60,   -62,   -62,   -62,   -62,   -62,   -62,     0,
       0,   -79,     0,     0,     0,     0,     0,   -80,   -82,   -82,
     -82,   -82,   -82,   -82,     0,   -60,     0,     0,     0,     0,
       0,   -62,   -83,   -83,   -83,   -83,   -83,   -83,   -56,   -56,
     -56,   -56,   -56,   -56,     0,     0,   -82,   -46,   -46,    79,
      80,   -46,   -46,   -48,   -48,   -48,   -48,   -48,   -48,     0,
     -83,     0,     0,     0,     0,     0,   -56,   -64,   -64,   -64,
     -64,   -64,   -64,     0,     0,   -46,     0,     0,     0,     0,
       0,   -48,   -54,   -54,   -54,   -54,   -54,   -54,   -61,   -61,
     -61,   -61,   -61,   -61,     0,   -64,   -63,   -63,   -63,   -63,
     -63,   -63,     0,   237,   -54,     0,     0,     0,     0,   -54,
     -61,     0,     0,     0,     0,   -61,     0,     0,   -63,     0,
       0,     0,     0,   -63,   -47,   -47,    79,    80,   -47,   -47,
     -49,   -49,   -49,   -49,   -49,   -49,   -55,   -55,   -55,   -55,
     -55,   -55,     0,     0,     0,     0,   -47,     0,     0,     0,
       0,   -47,   -49,     0,     0,     0,     0,   -49,   -55,     0,
       0,     0,     0,   -55,   -57,   -57,   -57,   -57,   -57,   -57,
     -58,   -58,   -58,   -58,   -58,   -58,   -79,   -79,   -79,   -79,
     -79,   -79,     0,     0,     0,     0,   -57,     0,     0,     0,
       0,   -57,   -58,     0,     0,     0,     0,   -58,   -79,     0,
       0,     0,     0,   -79,   -80,   -80,   -80,   -80,   -80,   -80,
     -60,   -60,   -60,   -60,   -60,   -60,   -62,   -62,   -62,   -62,
     -62,   -62,     0,     0,     0,     0,   -80,     0,     0,     0,
       0,   -80,   -60,     0,     0,     0,     0,   -60,   -62,     0,
       0,     0,     0,   -62,   -82,   -82,   -82,   -82,   -82,   -82,
     -83,   -83,   -83,   -83,   -83,   -83,   -56,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,     0,   -82,     0,     0,     0,
       0,   -82,   -83,     0,     0,     0,     0,   -83,   -56,     0,
       0,     0,     0,   -56,   -46,   -46,    79,    80,   -46,   -46,
     -48,   -48,   -48,   -48,   -48,   -48,   -64,   -64,   -64,   -64,
     -64,   -64,     0,     0,     0,     0,   -46,     0,     0,     0,
       0,   -46,   -48,     0,     0,     0,     0,   -48,   -64,     0,
       0,     0,     0,   -64,   -54,   -54,   -54,   -54,   -54,   -54,
     264,   -54,   -54,   -54,   -54,   -54,   -54,   -61,   -61,   -61,
     -61,   -61,   -61,     0,     0,   226,   -54,     0,     0,     0,
       0,     0,   226,   -54,     0,     0,     0,     0,     0,   -61,
     -63,   -63,   -63,   -63,   -63,   -63,   -47,   -47,    79,    80,
     -47,   -47,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,
       0,     0,   -63,     0,     0,     0,     0,     0,   -47,     0,
       0,     0,     0,     0,   -49,   -55,   -55,   -55,   -55,   -55,
     -55,   -57,   -57,   -57,   -57,   -57,   -57,   -58,   -58,   -58,
     -58,   -58,   -58,     0,     0,     0,     0,   -55,     0,     0,
       0,     0,     0,   -57,     0,     0,     0,     0,     0,   -58,
     -79,   -79,   -79,   -79,   -79,   -79,   -80,   -80,   -80,   -80,
     -80,   -80,   -60,   -60,   -60,   -60,   -60,   -60,     0,     0,
       0,     0,   -79,     0,     0,     0,     0,     0,   -80,     0,
       0,     0,     0,     0,   -60,   -62,   -62,   -62,   -62,   -62,
     -62,   -82,   -82,   -82,   -82,   -82,   -82,   -83,   -83,   -83,
     -83,   -83,   -83,     0,     0,     0,     0,   -62,     0,     0,
       0,     0,     0,   -82,     0,     0,     0,     0,     0,   -83,
     -56,   -56,   -56,   -56,   -56,   -56,   -46,   -46,    79,    80,
     -46,   -46,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,
       0,     0,   -56,     0,     0,     0,     0,     0,   -46,     0,
       0,     0,     0,     0,   -48,   -64,   -64,   -64,   -64,   -64,
     -64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -64
};

static const yytype_int16 yycheck[] =
{
      11,   166,     6,     8,   167,    14,   198,   226,     3,     4,
       5,     5,    17,     7,     9,    14,    11,    31,   237,    31,
     212,   186,    17,    31,   187,   103,    14,    15,    32,    38,
      10,    11,    27,    28,    14,    15,    31,    32,    14,    38,
      51,   119,    37,     5,    14,     7,    32,    52,    31,    60,
      38,    37,    17,    14,    59,    38,    32,   135,    38,    64,
      65,    10,    11,    12,    13,    14,    15,   145,    38,    74,
      10,    11,    12,    13,    14,    15,    16,    38,    14,    15,
      32,    31,    31,    94,     5,    37,     7,    52,    38,    38,
      20,    31,   103,    31,    59,     5,    32,    32,    38,    64,
      65,    37,    37,   268,   296,    14,   269,   112,   119,   274,
       0,     1,   275,     3,     4,     5,     6,    32,    31,     9,
      17,    11,    37,    32,     5,    14,    14,    17,    18,    19,
      20,    21,    14,    23,    24,    25,   147,    27,    28,     0,
      14,    31,   147,    32,    32,    35,    38,   112,    37,    37,
      32,    14,    15,    38,   159,    52,     5,   162,    32,    38,
      10,    11,    59,    37,    14,    15,    38,    64,    65,    32,
       3,     4,     5,   103,   179,    32,     9,   182,    11,     3,
       4,     5,   147,    14,    81,     9,   197,    11,    38,   119,
      38,    14,    38,    17,    27,    28,    38,   162,    31,    38,
     211,    32,    38,    27,    28,     5,    37,    31,    38,    32,
     288,    38,   290,    32,    32,   112,   146,   182,    37,    10,
      11,   226,   152,    14,    15,    10,    11,    38,   233,    14,
      15,    38,   237,     3,     4,    32,   314,    32,   249,   244,
      37,    32,   320,   248,    10,    11,   257,    32,    14,    15,
     147,   256,   330,   264,   332,   333,     3,     4,    32,   264,
     338,   226,   159,    37,   342,   162,    32,    32,    32,    32,
      32,    37,   237,    37,    37,    37,    17,   288,    32,   290,
       3,     4,   179,   248,   295,   182,    32,    32,     5,     5,
       5,   256,    10,    11,    12,    13,    14,    15,    16,   264,
     311,   103,    32,   314,    38,   310,    38,    38,   319,   320,
     321,    52,    38,    31,   319,     5,   321,   119,    59,   330,
      38,   332,   333,    64,    65,    38,    38,   338,   339,   226,
      38,   342,    38,    35,   339,    17,   233,   234,   235,   236,
     237,     6,    38,    32,    38,   310,     5,   244,   245,   246,
     247,   248,    38,    32,   319,     5,   321,     5,   288,   256,
     290,    10,    11,    12,    13,    14,    15,   264,     5,     5,
      52,   112,    17,    31,   339,    31,    38,    59,    38,    31,
      31,    38,    64,    65,   314,    38,   136,    -1,    32,    38,
     320,    32,    38,    32,    10,    11,    12,    13,    14,    15,
     330,    32,   332,   333,    38,    38,   147,    52,   338,     3,
       4,     5,   342,   310,    59,     9,    32,    11,   159,    64,
      65,   162,   319,    17,   321,    38,    38,    38,    38,    32,
     112,    17,    38,    27,    28,    32,    31,    31,   179,    31,
      38,   182,   339,    10,    11,    12,    13,    14,    15,    16,
      38,    38,    32,    38,    38,    38,   103,    38,    32,    26,
      38,    32,    29,    30,    31,   147,    52,   112,    38,    32,
      20,    38,   119,    59,   103,   117,    -1,   159,    64,    65,
     162,    -1,    -1,    -1,    -1,   226,   288,    -1,   290,    -1,
      -1,    -1,   233,   234,   235,   236,   237,   179,    -1,    -1,
     182,    -1,   147,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   314,    -1,   159,   256,    -1,   162,   320,    -1,
      -1,    -1,    -1,   264,    -1,    -1,   112,    -1,   330,    -1,
     332,   333,    -1,    -1,   179,    -1,   338,   182,    -1,    -1,
     342,   103,    -1,    -1,   226,    10,    11,    12,    13,    14,
      15,   233,   234,   235,   236,   237,    -1,   119,    -1,    -1,
      -1,   147,   244,   245,   246,   247,   248,    32,    -1,   310,
      -1,    -1,    37,   159,   256,    -1,   162,    -1,   319,    -1,
     321,   226,   264,    -1,    -1,    17,    -1,    -1,   233,   234,
     235,   236,   237,   179,    -1,    -1,   182,    -1,   339,   244,
     245,   246,   247,   248,    -1,    -1,     3,     4,     5,    -1,
      -1,   256,     9,    -1,    11,    -1,    -1,    -1,    -1,   264,
      52,    17,    -1,    -1,    -1,    -1,    -1,    59,   310,    -1,
      27,    28,    64,    65,    31,    -1,    -1,   319,    -1,   321,
     226,   288,    -1,   290,    -1,    -1,    -1,   233,   234,   235,
     236,   237,    -1,    -1,    -1,    -1,    52,   339,   244,   245,
     246,   247,   248,    59,    -1,   310,    -1,   314,    64,    65,
     256,    -1,    -1,   320,   319,    -1,   321,    -1,   264,    -1,
     112,    -1,    78,   330,    -1,   332,   333,    -1,    -1,    -1,
      -1,   338,    -1,    -1,   339,   342,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    10,    11,    12,    13,    14,    15,    10,
      11,    12,    13,    14,    15,   147,   112,    10,    11,    12,
      13,    14,    15,    -1,   310,    17,   288,   159,   290,    -1,
     162,    38,    -1,   319,    -1,   321,    52,    38,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    38,   103,   179,    64,    65,
     182,   147,   314,   339,    -1,    -1,    -1,    -1,   320,    75,
      52,    -1,   119,   159,    -1,    -1,   162,    59,   330,    -1,
     332,   333,    64,    65,    -1,    -1,   338,    -1,    -1,    -1,
     342,   103,    -1,   179,    10,    11,   182,    -1,    14,    15,
      -1,    -1,    -1,    -1,   226,    -1,   112,   119,    -1,    -1,
      -1,   233,   234,   235,   236,   237,    32,    -1,    -1,    -1,
      -1,    37,   244,   245,   246,   247,   248,    -1,    -1,    -1,
     112,    -1,    -1,    -1,   256,    -1,    -1,    -1,   120,    -1,
     226,   147,   264,    -1,     3,     4,     5,   233,   234,   235,
       9,   237,    11,   159,    17,    -1,   162,    -1,   244,   245,
     246,   103,   248,    -1,    -1,   147,    -1,    -1,    27,    28,
     256,    -1,    31,   179,    -1,   103,   182,   119,   264,    -1,
     162,    -1,    -1,    -1,     3,     4,     5,    -1,   310,    52,
       9,   119,    11,    -1,    -1,    -1,    59,   319,    17,   321,
     182,    64,    65,    -1,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,    -1,    -1,   339,    -1,    -1,
     226,    -1,    -1,    -1,   310,    -1,    -1,   233,   234,    -1,
      -1,   237,    -1,   319,    -1,   321,    -1,    -1,   244,   245,
      -1,   288,   248,   290,   226,    -1,    -1,    -1,    -1,   112,
     256,    -1,    -1,   339,    -1,   237,    -1,    -1,   264,    10,
      11,    12,    13,    14,    15,    -1,   248,   314,    -1,     3,
       4,     5,    -1,   320,   256,     9,   288,    11,   290,    -1,
      -1,    -1,   264,   330,   147,   332,   333,    38,    -1,    -1,
      -1,   338,    -1,    27,    28,   342,   159,    31,    -1,   162,
      -1,    -1,   314,    -1,   310,    -1,    -1,   289,   320,   291,
      -1,    -1,    -1,   319,    -1,   321,   179,    -1,   330,   182,
     332,   333,    -1,    -1,    -1,    -1,   338,    -1,   310,    -1,
     342,    -1,    -1,   339,    -1,    -1,    -1,   319,    -1,   321,
      10,    11,    12,    13,    14,    15,   288,    -1,   290,   331,
      -1,    10,    11,    12,    13,    14,    15,   339,    -1,    -1,
     288,    -1,   290,   226,    -1,    -1,    -1,    -1,    38,    -1,
     233,    -1,   314,    -1,   237,    -1,    -1,    -1,   320,    38,
      -1,   244,    -1,    -1,    -1,   248,   314,    -1,   330,    -1,
     332,   333,   320,   256,    -1,    -1,   338,    -1,    -1,    -1,
     342,   264,   330,    -1,   332,   333,    -1,    -1,    -1,    -1,
     338,    -1,    -1,    -1,   342,     0,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,   310,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,   319,    -1,   321,    -1,
       0,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,   339,    17,    18,    19,
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
       0,     1,    35,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,     1,    35,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,
      35,    36,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,
      -1,    -1,    35,    36,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,     0,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
       1,    35,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,
      35,    36,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,     1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,
      -1,    -1,    35,    36,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,     0,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
       1,    35,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,     0,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
       1,    35,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,
      35,    36,     0,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,     1,    35,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,
      35,    36,     0,     1,    -1,     3,     4,     5,     6,    -1,
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
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,     0,
       1,    35,     3,     4,     5,     6,    -1,    -1,     9,    -1,
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
      25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,     1,
      35,     3,     4,     5,     6,    -1,    -1,     9,    -1,    11,
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
      -1,    -1,    -1,    35,    36,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,
      36,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
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
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,     1,    35,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    -1,    27,
      28,    -1,     1,    31,     3,     4,     5,    35,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      -1,     1,    31,     3,     4,     5,    35,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
       1,    31,     3,     4,     5,    35,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,     1,
      31,     3,     4,     5,    35,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    31,
       3,     4,     5,    35,    -1,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,     3,     4,     5,    -1,    -1,
       8,     9,    -1,    11,    27,    28,    -1,    -1,    31,    17,
       3,     4,     5,    -1,    -1,    -1,     9,    -1,    11,    27,
      28,    -1,    -1,    31,    17,     3,     4,     5,    -1,    -1,
      -1,     9,    -1,    11,    27,    28,    -1,    -1,    31,    17,
       3,     4,     5,    -1,    -1,    -1,     9,    -1,    11,    27,
      28,    -1,    -1,    31,    17,     3,     4,     5,    -1,    -1,
      -1,     9,    -1,    11,    27,    28,    -1,    -1,    31,     3,
       4,     5,    -1,    -1,    -1,     9,    -1,    11,    -1,    27,
      28,    -1,    -1,    31,     3,     4,     5,    -1,    -1,    -1,
       9,    -1,    11,    27,    28,    -1,    -1,    31,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    31,    10,    11,    12,    13,    14,    15,    10,
      11,    12,    13,    14,    15,    -1,    38,    10,    11,    12,
      13,    14,    15,    10,    11,    12,    13,    14,    15,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    38,    10,    11,
      12,    13,    14,    15,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    38,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    -1,    -1,    38,    10,    11,    12,
      13,    14,    15,    10,    11,    12,    13,    14,    15,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    38,    10,    11,    12,
      13,    14,    15,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    38,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    -1,    38,    10,    11,    12,    13,
      14,    15,    -1,    31,    32,    -1,    -1,    -1,    -1,    37,
      32,    -1,    -1,    -1,    -1,    37,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    37,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    37,    32,    -1,    -1,    -1,    -1,    37,    32,    -1,
      -1,    -1,    -1,    37,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    37,    32,    -1,    -1,    -1,    -1,    37,    32,    -1,
      -1,    -1,    -1,    37,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    37,    32,    -1,    -1,    -1,    -1,    37,    32,    -1,
      -1,    -1,    -1,    37,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    37,    32,    -1,    -1,    -1,    -1,    37,    32,    -1,
      -1,    -1,    -1,    37,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    37,    32,    -1,    -1,    -1,    -1,    37,    32,    -1,
      -1,    -1,    -1,    37,    10,    11,    12,    13,    14,    15,
      16,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    32,
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
      -1,    -1,    -1,    -1,    32,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     9,    11,    17,    18,
      20,    21,    23,    24,    25,    27,    28,    31,    35,    47,
      48,    49,    50,    51,    55,    56,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    71,    72,    73,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    16,    31,     5,     7,     3,     4,     5,    65,    31,
      31,     5,    62,    31,    31,    31,     5,     5,    63,    58,
       0,    49,    55,    38,    14,    15,    10,    11,    69,    12,
      13,    70,    38,    38,    38,     5,    62,    63,    74,    31,
      38,     5,    63,    62,    16,    38,     5,     8,    63,     8,
      63,    32,    36,    57,    65,    67,    68,    71,    26,    29,
      30,    32,    37,     6,    52,    53,    54,    31,    38,    32,
      38,    32,    32,    32,    32,    32,     6,    50,    55,     5,
       5,     5,    63,     5,     7,    32,    37,    52,    55,    63,
       5,     7,     5,    56,    54,    32,    19,    38,     5,    56,
      55,    62,    32,    55,     3,     4,     5,     9,    11,    17,
      27,    28,    31,    64,    65,    66,    67,    68,    71,    72,
      73,    81,    83,    84,     3,     4,     5,     9,    11,    17,
      27,    28,    31,    64,    65,    66,    67,    68,    71,    72,
      73,    81,    83,    84,     1,    18,    20,    21,    35,    56,
      59,    60,    61,    62,    75,    78,    79,    80,     1,    18,
      20,    21,    35,    56,    59,    60,    61,    62,    75,    78,
      79,    80,    38,     5,    63,    38,    31,     3,     4,    65,
       5,     5,    63,    14,    15,    69,    70,    31,     3,     4,
      65,     5,     5,    63,    14,    15,    69,    70,    31,    31,
      62,    58,    38,    38,    38,    38,    31,    31,    62,    58,
      38,    38,    38,    38,    16,    74,    32,    65,    67,    68,
      71,    74,    32,    65,    67,    68,    71,    63,    62,    38,
      36,    63,    62,    38,    36,    62,    32,    32,    32,    38,
      32,    38,     1,    18,    20,    21,    35,    55,    56,    59,
      60,    61,    62,    75,    78,    79,    80,    63,    55,    63,
      31,    31,    62,    58,    19,    38,    38,    38,    38,    38,
      19,    38,    63,    62,    38,    36,    55,    62,    55,    62,
      32,    38,    32,    32,    55,    63,    55,    55,    19,    38,
      55,    62,    32,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    57,
      57,    58,    58,    59,    59,    60,    61,    62,    62,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    73,    74,    74,    74,    75,    75,
      76,    76,    77,    77,    78,    79,    80,    80,    80,    81,
      81,    82,    83,    84,    85,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     3,
       4,     6,     7,     1,     0,     3,     1,     2,     3,     1,
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
#line 201 "./src/syntax.y"
                    {
        (yyval.t_node) = (yyvsp[0].t_node);
        /* printf("Declaration list - initialize tree\n"); */
        initializeTree((yyval.t_node));
    }
#line 2562 "./src/syntax.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 209 "./src/syntax.y"
                                {
        (yyval.t_node) = createNode("Declaration List - Declaration");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

    }
#line 2576 "./src/syntax.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 218 "./src/syntax.y"
                  {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2584 "./src/syntax.tab.c"
    break;

  case 5: /* declarationList: declarationList statement  */
#line 221 "./src/syntax.y"
                                {
        (yyval.t_node) = createNode("Declaration List - Statement");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);
    }
#line 2597 "./src/syntax.tab.c"
    break;

  case 6: /* declarationList: statement  */
#line 229 "./src/syntax.y"
                {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2605 "./src/syntax.tab.c"
    break;

  case 7: /* declaration: varDeclaration  */
#line 235 "./src/syntax.y"
                   {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2613 "./src/syntax.tab.c"
    break;

  case 8: /* declaration: funcDeclaration  */
#line 238 "./src/syntax.y"
                      {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2621 "./src/syntax.tab.c"
    break;

  case 9: /* varDeclaration: TYPE ID DELIM_SEMICOLLON  */
#line 244 "./src/syntax.y"
                             {
        char* temp;

        /* printf("%s %s %s\n", $1.text, $2.text, $3.text); */
        createSymbol((yyvsp[-1].t_token).text, (yyvsp[-2].t_token).text, (yyvsp[-1].t_token).line, (yyvsp[-1].t_token).column, (yyvsp[-1].t_token).scope->scopeValue, (yyvsp[-1].t_token).scope->parentScope, 1);
        /* printf("variable declaration\n"); */

        temp = (char*) malloc(strlen((yyvsp[-1].t_token).text) + strlen("Variable Declaration - ID: ") + 1);

        /* printf("allocated memory\n"); */
        strcpy(temp, "Variable Declaration - ID: ");
        /* printf("copied first string\n"); */
        strcat(temp, (yyvsp[-1].t_token).text);
        /* printf("concatenated second string\n"); */

        temp = add_color(temp, COLOR_GREEN);

        (yyval.t_node) = createNode(temp);
        /* initializeTree($$); */

        freeScopeToken((yyvsp[-1].t_token).scope);
        free(temp);

    }
#line 2650 "./src/syntax.tab.c"
    break;

  case 10: /* varDeclaration: TYPE LIST_TYPE ID DELIM_SEMICOLLON  */
#line 268 "./src/syntax.y"
                                         {
        char* temp;
        char* temp2;

        temp = (char*) malloc(strlen((yyvsp[-3].t_token).text) + strlen((yyvsp[-2].t_token).text) + 3);
        strcpy(temp, (yyvsp[-3].t_token).text);
        strcat(temp, " ");
        strcat(temp, (yyvsp[-2].t_token).text);
        /* printf("%s %s %s %s - %s\n", $1.text, $2.text, $3.text, $4.text, temp); */
        createSymbol((yyvsp[-1].t_token).text, temp, (yyvsp[-1].t_token).line, (yyvsp[-1].t_token).column, (yyvsp[-1].t_token).scope->scopeValue, (yyvsp[-1].t_token).scope->parentScope, 1);


        temp2 = (char*) malloc(strlen((yyvsp[-1].t_token).text) + strlen("Variable Declaration - List Type ID: ") + 1);

        strcpy(temp2, "Variable Declaration - List Type ID: ");
        strcat(temp2, (yyvsp[-1].t_token).text);

        temp2 = add_color(temp2, COLOR_GREEN);

        (yyval.t_node) = createNode(temp2);

        freeScopeToken((yyvsp[-1].t_token).scope);
        free(temp);
        free(temp2);

    }
#line 2681 "./src/syntax.tab.c"
    break;

  case 11: /* funcDeclaration: TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R bodyStatement  */
#line 311 "./src/syntax.y"
                                                                   {
        char* temp;
        t_symbol* symbol;
        /* printf("%s %s %s %s - escopo %d %d\n", $1.text, $2.text, $3.text, $5.text, $2.scope->scopeValue, $2.scope->parentScope); */
        symbol = createSymbol((yyvsp[-4].t_token).text, (yyvsp[-5].t_token).text, (yyvsp[-4].t_token).line, (yyvsp[-4].t_token).column, (yyvsp[-4].t_token).scope->scopeValue, (yyvsp[-4].t_token).scope->parentScope, 0);

        temp = (char*) malloc(strlen((yyvsp[-4].t_token).text) + strlen("Function Declaration - ID: ") + 1);

        strcpy(temp, "Function Declaration - ID: ");
        strcat(temp, (yyvsp[-4].t_token).text);

        temp = add_color(temp, COLOR_GREEN);

        (yyval.t_node) = createNode(temp);

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

        freeScopeToken((yyvsp[-4].t_token).scope);
        free(temp);

        /* printf("function declaration test\n"); */

        installParam(symbol);

    }
#line 2714 "./src/syntax.tab.c"
    break;

  case 12: /* funcDeclaration: TYPE LIST_TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R bodyStatement  */
#line 339 "./src/syntax.y"
                                                                               {
        char* temp;
        char* temp2;
        t_symbol* symbol;

        temp = (char*) malloc(sizeof((yyvsp[-6].t_token).text) + sizeof((yyvsp[-5].t_token).text) + 3);
        strcpy(temp, (yyvsp[-6].t_token).text);
        strcat(temp, " ");
        strcat(temp, (yyvsp[-5].t_token).text);
        /* printf("%s %s %s %s %s - %s - escopo %d %d\n", $1.text, $2.text, $3.text, $4.text, $6.text, temp, $3.scope->scopeValue, $3.scope->parentScope); */
        symbol = createSymbol((yyvsp[-4].t_token).text, temp, (yyvsp[-4].t_token).line, (yyvsp[-4].t_token).column, (yyvsp[-4].t_token).scope->scopeValue, (yyvsp[-4].t_token).scope->parentScope, 0);

        temp2 = (char*) malloc(strlen((yyvsp[-4].t_token).text) + strlen("Function Declaration - List Type ID: ") + 1);

        strcpy(temp2, "Function Declaration - List Type ID: ");
        strcat(temp2, (yyvsp[-4].t_token).text);

        temp2 = add_color(temp2, COLOR_GREEN);

        (yyval.t_node) = createNode(temp2);

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

        freeScopeToken((yyvsp[-4].t_token).scope);
        free(temp);
        free(temp2);

        installParam(symbol);
    }
#line 2751 "./src/syntax.tab.c"
    break;

  case 13: /* parameters: parameterList  */
#line 374 "./src/syntax.y"
                  {
        /* printf("parameters of function declaration test\n"); */
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2760 "./src/syntax.tab.c"
    break;

  case 14: /* parameters: %empty  */
#line 378 "./src/syntax.y"
      {
        (yyval.t_node) = createEmptyNode();
    }
#line 2768 "./src/syntax.tab.c"
    break;

  case 15: /* parameterList: parameterList DELIM_COMMA parameterSimple  */
#line 384 "./src/syntax.y"
                                              {
        (yyval.t_node) = createNode("Parameters list");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);
    }
#line 2781 "./src/syntax.tab.c"
    break;

  case 16: /* parameterList: parameterSimple  */
#line 392 "./src/syntax.y"
                      {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2789 "./src/syntax.tab.c"
    break;

  case 17: /* parameterSimple: TYPE ID  */
#line 399 "./src/syntax.y"
            {
        char* temp;
        t_symbol* symbol;

        symbol = createSymbol((yyvsp[0].t_token).text, (yyvsp[-1].t_token).text, (yyvsp[0].t_token).line, (yyvsp[0].t_token).column, lastScopeValue+1, (yyvsp[0].t_token).scope->scopeValue, 1);
        /* $2.scope->scopeValue lastScopeValue+1 $2.scope->parentScope*/
        temp = (char*) malloc(strlen((yyvsp[0].t_token).text) + strlen("Parameter Declaration - ID: ") + 3);

        strcpy(temp, "Parameter Declaration - ID: ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_GREEN);

        (yyval.t_node) = createNode(temp);

        freeScopeToken((yyvsp[0].t_token).scope);
        free(temp);


        addParam(symbol);

    }
#line 2816 "./src/syntax.tab.c"
    break;

  case 18: /* parameterSimple: TYPE LIST_TYPE ID  */
#line 421 "./src/syntax.y"
                       {
        char* temp;
        char* temp2;
        t_symbol* symbol;

        temp = (char*) malloc(strlen((yyvsp[-2].t_token).text) + strlen((yyvsp[-1].t_token).text) + 3);
        strcpy(temp, (yyvsp[-2].t_token).text);
        strcat(temp, " ");
        strcat(temp, (yyvsp[-1].t_token).text);

        symbol = createSymbol((yyvsp[0].t_token).text, temp, (yyvsp[0].t_token).line, (yyvsp[0].t_token).column, lastScopeValue+1, (yyvsp[0].t_token).scope->scopeValue, 1);
        /* $3.scope->scopeValue lastScopeValue+1 $3.scope->parentScope*/
        temp2 = (char*) malloc(strlen((yyvsp[0].t_token).text) + strlen("Parameter Declaration - List Type ID: ") + 3);

        strcpy(temp2, "Parameter Declaration - List Type ID: ");
        strcat(temp2, (yyvsp[0].t_token).text);

        temp2 = add_color(temp2, COLOR_GREEN);

        (yyval.t_node) = createNode(temp2);

        freeScopeToken((yyvsp[0].t_token).scope);
        free(temp);
        free(temp2);

        addParam(symbol);

    }
#line 2849 "./src/syntax.tab.c"
    break;

  case 19: /* statement: bodyStatement  */
#line 452 "./src/syntax.y"
                  {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2857 "./src/syntax.tab.c"
    break;

  case 20: /* statement: ifStatement  */
#line 455 "./src/syntax.y"
                  {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2865 "./src/syntax.tab.c"
    break;

  case 21: /* statement: loopStatement  */
#line 458 "./src/syntax.y"
                    {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2873 "./src/syntax.tab.c"
    break;

  case 22: /* statement: returnStatement  */
#line 461 "./src/syntax.y"
                      {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2881 "./src/syntax.tab.c"
    break;

  case 23: /* statement: listStatement DELIM_SEMICOLLON  */
#line 464 "./src/syntax.y"
                                     {
        (yyval.t_node) = (yyvsp[-1].t_node);
    }
#line 2889 "./src/syntax.tab.c"
    break;

  case 24: /* statement: writeOp DELIM_SEMICOLLON  */
#line 467 "./src/syntax.y"
                               {
        (yyval.t_node) = (yyvsp[-1].t_node);
    }
#line 2897 "./src/syntax.tab.c"
    break;

  case 25: /* statement: readOp DELIM_SEMICOLLON  */
#line 470 "./src/syntax.y"
                              {
        (yyval.t_node) = (yyvsp[-1].t_node);
    }
#line 2905 "./src/syntax.tab.c"
    break;

  case 26: /* statement: expressionStatement  */
#line 473 "./src/syntax.y"
                          {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2913 "./src/syntax.tab.c"
    break;

  case 27: /* statement: error  */
#line 476 "./src/syntax.y"
            {
        (yyval.t_node) = createNode(COLOR_RED "SYNTAX ERROR" COLOR_RESET);
    }
#line 2921 "./src/syntax.tab.c"
    break;

  case 28: /* bodyStatement: DELIM_CUR_BRACKET_L statementList DELIM_CUR_BRACKET_R  */
#line 482 "./src/syntax.y"
                                                          {
        (yyval.t_node) = (yyvsp[-1].t_node);
        freeScopeToken((yyvsp[-2].t_token).scope);
    }
#line 2930 "./src/syntax.tab.c"
    break;

  case 29: /* localDeclaration: localDeclaration varDeclaration  */
#line 493 "./src/syntax.y"
                                    {
        (yyval.t_node) = createNode("Local Declaration");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);
    }
#line 2943 "./src/syntax.tab.c"
    break;

  case 30: /* localDeclaration: %empty  */
#line 501 "./src/syntax.y"
      {
        (yyval.t_node) = createEmptyNode();
    }
#line 2951 "./src/syntax.tab.c"
    break;

  case 31: /* statementList: statementList localDeclaration statement  */
#line 507 "./src/syntax.y"
                                             {
        (yyval.t_node) = createNode("Statement List");

        addChild((yyval.t_node), 3);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[-1].t_node);
        (yyval.t_node)->child[2] = (yyvsp[0].t_node);

    }
#line 2966 "./src/syntax.tab.c"
    break;

  case 32: /* statementList: %empty  */
#line 517 "./src/syntax.y"
      {
        (yyval.t_node) = createEmptyNode();
    }
#line 2974 "./src/syntax.tab.c"
    break;

  case 33: /* ifStatement: IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R statement  */
#line 523 "./src/syntax.y"
                                                                                    {
        (yyval.t_node) = createNode(COLOR_BLUE "If Statement" COLOR_RESET);

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);
    }
#line 2987 "./src/syntax.tab.c"
    break;

  case 34: /* ifStatement: IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R statement ELSE_KEY statement  */
#line 531 "./src/syntax.y"
                                                                                         {
        (yyval.t_node) = createNode(COLOR_BLUE "If-Else Statement" COLOR_RESET);

        addChild((yyval.t_node), 3);

        (yyval.t_node)->child[0] = (yyvsp[-4].t_node);
        (yyval.t_node)->child[1] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[2] = (yyvsp[0].t_node);

    }
#line 3002 "./src/syntax.tab.c"
    break;

  case 35: /* loopStatement: FOR_KEY DELIM_PARENT_L expression DELIM_SEMICOLLON simpleExpression DELIM_SEMICOLLON expression DELIM_PARENT_R statement  */
#line 544 "./src/syntax.y"
                                                                                                                             {
        (yyval.t_node) = createNode(COLOR_BLUE "For Statement" COLOR_RESET);

        addChild((yyval.t_node), 4);

        (yyval.t_node)->child[0] = (yyvsp[-6].t_node);
        (yyval.t_node)->child[1] = (yyvsp[-4].t_node);
        (yyval.t_node)->child[2] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[3] = (yyvsp[0].t_node);
    }
#line 3017 "./src/syntax.tab.c"
    break;

  case 36: /* returnStatement: RETURN_KEY expression DELIM_SEMICOLLON  */
#line 557 "./src/syntax.y"
                                           {
        (yyval.t_node) = createNode(COLOR_BLUE "Return Statement" COLOR_RESET);

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);
    }
#line 3029 "./src/syntax.tab.c"
    break;

  case 37: /* expression: ID ASSIGN_OP expression  */
#line 567 "./src/syntax.y"
                            {
        (yyval.t_node) = createNode("Assign Operation");

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[0].t_node);
        freeScopeToken((yyvsp[-2].t_token).scope);

    }
#line 3043 "./src/syntax.tab.c"
    break;

  case 38: /* expression: simpleExpression  */
#line 576 "./src/syntax.y"
                       {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3051 "./src/syntax.tab.c"
    break;

  case 39: /* simpleExpression: logicBinExpression  */
#line 587 "./src/syntax.y"
                       {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3059 "./src/syntax.tab.c"
    break;

  case 40: /* logicBinExpression: logicBinExpression LOGIC_OP logicUnExpression  */
#line 598 "./src/syntax.y"
                                                  {
        (yyval.t_node) = createNode("Logic Binary Expression");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

        addNodeType((yyval.t_node), "logic");

    }
#line 3075 "./src/syntax.tab.c"
    break;

  case 41: /* logicBinExpression: logicUnExpression  */
#line 609 "./src/syntax.y"
                        {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3083 "./src/syntax.tab.c"
    break;

  case 42: /* logicUnExpression: EXCLA_OP logicUnExpression  */
#line 615 "./src/syntax.y"
                               {
        (yyval.t_node) = createNode("Exclamation Expression");

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[0].t_node);

        addNodeType((yyval.t_node), "logic");

    }
#line 3098 "./src/syntax.tab.c"
    break;

  case 43: /* logicUnExpression: binExpression  */
#line 625 "./src/syntax.y"
                    {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3106 "./src/syntax.tab.c"
    break;

  case 44: /* binExpression: binExpression BINARY_OP sumExpression  */
#line 635 "./src/syntax.y"
                                          {
        (yyval.t_node) = createNode("Binary Expression");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

        addNodeType((yyval.t_node), "binary");

    }
#line 3122 "./src/syntax.tab.c"
    break;

  case 45: /* binExpression: sumExpression  */
#line 646 "./src/syntax.y"
                    {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3130 "./src/syntax.tab.c"
    break;

  case 46: /* sumExpression: sumExpression sumOP mulExpression  */
#line 652 "./src/syntax.y"
                                      {
        (yyval.t_node) = createNode("Sum Expression");

        addChild((yyval.t_node), 3);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[-1].t_node);
        (yyval.t_node)->child[2] = (yyvsp[0].t_node);

        addNodeTypeChildren((yyval.t_node));
    }
#line 3146 "./src/syntax.tab.c"
    break;

  case 47: /* sumExpression: mulExpression  */
#line 663 "./src/syntax.y"
                    {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3154 "./src/syntax.tab.c"
    break;

  case 48: /* mulExpression: mulExpression mulOP factor  */
#line 669 "./src/syntax.y"
                               {
        (yyval.t_node) = createNode("Multiplication Expression");

        addChild((yyval.t_node), 3);

        addChild((yyval.t_node), 3);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[-1].t_node);
        (yyval.t_node)->child[2] = (yyvsp[0].t_node);

        addNodeTypeChildren((yyval.t_node));
    }
#line 3172 "./src/syntax.tab.c"
    break;

  case 49: /* mulExpression: factor  */
#line 682 "./src/syntax.y"
             {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3180 "./src/syntax.tab.c"
    break;

  case 50: /* sumOP: PLUS_OP  */
#line 688 "./src/syntax.y"
            {
        (yyval.t_node) = createNode("+ Operator");
    }
#line 3188 "./src/syntax.tab.c"
    break;

  case 51: /* sumOP: MINUS_OP  */
#line 691 "./src/syntax.y"
               {
        (yyval.t_node) = createNode("- Operator");
    }
#line 3196 "./src/syntax.tab.c"
    break;

  case 52: /* mulOP: MUL_OP  */
#line 697 "./src/syntax.y"
           {
        (yyval.t_node) = createNode("* Operator");
    }
#line 3204 "./src/syntax.tab.c"
    break;

  case 53: /* mulOP: DIV_OP  */
#line 700 "./src/syntax.y"
             {
        (yyval.t_node) = createNode("/ Operator");
    }
#line 3212 "./src/syntax.tab.c"
    break;

  case 54: /* factor: ID  */
#line 706 "./src/syntax.y"
       {
        char* temp;

        temp = (char*) malloc(strlen((yyvsp[0].t_token).text) + strlen("ID:  ") + 3);

        strcpy(temp, "ID:  ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_YELLOW);

        (yyval.t_node) = createNode(temp);

        freeScopeToken((yyvsp[0].t_token).scope);
        free(temp);

        addNodeTypeId((yyval.t_node), (yyvsp[0].t_token).text);
    }
#line 3234 "./src/syntax.tab.c"
    break;

  case 55: /* factor: constant  */
#line 723 "./src/syntax.y"
               {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3242 "./src/syntax.tab.c"
    break;

  case 56: /* factor: DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 726 "./src/syntax.y"
                                                     {
        (yyval.t_node) = (yyvsp[-1].t_node);
    }
#line 3250 "./src/syntax.tab.c"
    break;

  case 57: /* factor: functionCall  */
#line 729 "./src/syntax.y"
                   {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3258 "./src/syntax.tab.c"
    break;

  case 58: /* factor: listExpression  */
#line 732 "./src/syntax.y"
                     {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3266 "./src/syntax.tab.c"
    break;

  case 59: /* constant: INT  */
#line 738 "./src/syntax.y"
        {
        char* temp;

        temp = (char*) malloc(strlen("Constant Integer: ") + strlen((yyvsp[0].t_token).text) + 1);
        strcpy(temp, "Constant Integer: ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_YELLOW);

        (yyval.t_node) = createNode(temp);

        free(temp);

        addNodeType((yyval.t_node), "int");
    }
#line 3286 "./src/syntax.tab.c"
    break;

  case 60: /* constant: MINUS_OP INT  */
#line 753 "./src/syntax.y"
                   {
        char* temp;

        temp = (char*) malloc(strlen("Constant Negative Integer: ") + strlen((yyvsp[0].t_token).text) + 1);
        strcpy(temp, "Constant Negative Integer: ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_YELLOW);

        (yyval.t_node) = createNode(temp);

        free(temp);

        addNodeType((yyval.t_node), "int");
    }
#line 3306 "./src/syntax.tab.c"
    break;

  case 61: /* constant: FLOAT  */
#line 768 "./src/syntax.y"
            {
        char* temp;

        temp = (char*) malloc(strlen("Constant Float: ") + strlen((yyvsp[0].t_token).text) + 1);
        strcpy(temp, "Constant Float: ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_YELLOW);

        (yyval.t_node) = createNode(temp);

        free(temp);

        addNodeType((yyval.t_node), "float");
    }
#line 3326 "./src/syntax.tab.c"
    break;

  case 62: /* constant: MINUS_OP FLOAT  */
#line 783 "./src/syntax.y"
                     {
        char* temp;

        temp = (char*) malloc(strlen("Constant Negative Float: ") + strlen((yyvsp[0].t_token).text) + 1);
        strcpy(temp, "Constant Negative Float: ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_YELLOW);

        (yyval.t_node) = createNode(temp);

        free(temp);

        addNodeType((yyval.t_node), "float");
    }
#line 3346 "./src/syntax.tab.c"
    break;

  case 63: /* constant: NULL_CONST  */
#line 798 "./src/syntax.y"
                 {
        char* temp;

        temp = malloc(strlen("Constant NULL") + 1);
        strcpy(temp, "Constant NULL");

        temp = add_color(temp, COLOR_YELLOW);

        (yyval.t_node) = createNode(temp);

        free(temp);

        addNodeType((yyval.t_node), "null");
    }
#line 3365 "./src/syntax.tab.c"
    break;

  case 64: /* functionCall: ID DELIM_PARENT_L parametersPass DELIM_PARENT_R  */
#line 815 "./src/syntax.y"
                                                    {
        char* temp;

        temp = (char*) malloc(strlen("Function Call - ID: ") + strlen((yyvsp[-3].t_token).text) + 1);
        strcpy(temp, "Function Call - ID: ");
        strcat(temp, (yyvsp[-3].t_token).text);

        (yyval.t_node) = createNode(temp);

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);
        freeScopeToken((yyvsp[-3].t_token).scope);
        free(temp);

        addFunctionName((yyval.t_node), (yyvsp[-3].t_token).text);

        checkFunctionCall((yyval.t_node));
    }
#line 3389 "./src/syntax.tab.c"
    break;

  case 65: /* parametersPass: parametersPass DELIM_COMMA simpleExpression  */
#line 837 "./src/syntax.y"
                                                {
        (yyval.t_node) = createNode("Parameters Passing");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);
    }
#line 3402 "./src/syntax.tab.c"
    break;

  case 66: /* parametersPass: simpleExpression  */
#line 845 "./src/syntax.y"
                       {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3410 "./src/syntax.tab.c"
    break;

  case 67: /* parametersPass: %empty  */
#line 848 "./src/syntax.y"
      {
        (yyval.t_node) = createEmptyNode();
    }
#line 3418 "./src/syntax.tab.c"
    break;

  case 68: /* writeOp: write  */
#line 854 "./src/syntax.y"
          {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3426 "./src/syntax.tab.c"
    break;

  case 69: /* writeOp: writeln  */
#line 857 "./src/syntax.y"
              {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3434 "./src/syntax.tab.c"
    break;

  case 70: /* write: OUTPUT_KEY DELIM_PARENT_L STRING DELIM_PARENT_R  */
#line 863 "./src/syntax.y"
                                                    {
        (yyval.t_node) = createNode(COLOR_BLUE "Output String" COLOR_RESET);
    }
#line 3442 "./src/syntax.tab.c"
    break;

  case 71: /* write: OUTPUT_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 866 "./src/syntax.y"
                                                                {
        (yyval.t_node) = createNode(COLOR_BLUE "Output Expression" COLOR_RESET);

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);
    }
#line 3454 "./src/syntax.tab.c"
    break;

  case 72: /* writeln: OUTPUTLN_KEY DELIM_PARENT_L STRING DELIM_PARENT_R  */
#line 876 "./src/syntax.y"
                                                      {
        (yyval.t_node) = createNode(COLOR_BLUE "OutputLn String" COLOR_RESET);
    }
#line 3462 "./src/syntax.tab.c"
    break;

  case 73: /* writeln: OUTPUTLN_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 879 "./src/syntax.y"
                                                                  {
        (yyval.t_node) = createNode(COLOR_BLUE "OutputLn Expression" COLOR_RESET);

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);
    }
#line 3474 "./src/syntax.tab.c"
    break;

  case 74: /* readOp: INPUT_KEY DELIM_PARENT_L ID DELIM_PARENT_R  */
#line 889 "./src/syntax.y"
                                               {
        char* temp;

        temp = (char*) malloc(strlen((yyvsp[-1].t_token).text) + strlen("Read - Input ID: ") + 3);

        strcpy(temp, "Read - Input ID: ");
        strcat(temp, (yyvsp[-1].t_token).text);

        temp = add_color(temp, COLOR_BLUE);

        (yyval.t_node) = createNode(temp);

        freeScopeToken((yyvsp[-1].t_token).scope);
        free(temp);
    }
#line 3494 "./src/syntax.tab.c"
    break;

  case 75: /* expressionStatement: expression DELIM_SEMICOLLON  */
#line 907 "./src/syntax.y"
                                {
        (yyval.t_node) = (yyvsp[-1].t_node);
    }
#line 3502 "./src/syntax.tab.c"
    break;

  case 76: /* listStatement: listAssign  */
#line 913 "./src/syntax.y"
               {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3510 "./src/syntax.tab.c"
    break;

  case 77: /* listStatement: listMap  */
#line 916 "./src/syntax.y"
              {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3518 "./src/syntax.tab.c"
    break;

  case 78: /* listStatement: listFilter  */
#line 919 "./src/syntax.y"
                 {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3526 "./src/syntax.tab.c"
    break;

  case 79: /* listExpression: listHeader  */
#line 925 "./src/syntax.y"
               {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3534 "./src/syntax.tab.c"
    break;

  case 80: /* listExpression: listTailDestructor  */
#line 929 "./src/syntax.y"
                         {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3542 "./src/syntax.tab.c"
    break;

  case 81: /* listAssign: ID ASSIGN_OP ID ASSIGN_LISTOP ID  */
#line 935 "./src/syntax.y"
                                     {
        char* temp;

        /* temp = (char*) malloc(strlen($1.text) + strlen($3.text) + strlen($5.text) + strlen("List Assignment - ID1: ") + strlen(" - ID2: ") + strlen(" - ID3: ") + 3); */
        temp = (char*) malloc(strlen((yyvsp[-4].t_token).text) + strlen((yyvsp[-2].t_token).text) + strlen((yyvsp[0].t_token).text) + strlen("List Assignment - IDs: ") + 6);

        /* strcpy(temp, "List Assignment - ID1: ");
        strcat(temp, $1.text);
        strcat(temp, " - ID2: ");
        strcat(temp, $3.text);
        strcat(temp, " - ID3: ");
        strcat(temp, $5.text); */

        strcpy(temp, "List Assignment - IDs: ");
        strcat(temp, (yyvsp[-4].t_token).text);
        strcat(temp, ", ");
        strcat(temp, (yyvsp[-2].t_token).text);
        strcat(temp, ", ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_CYAN);

        (yyval.t_node) = createNode(temp);

        freeScopeToken((yyvsp[-4].t_token).scope);
        freeScopeToken((yyvsp[-2].t_token).scope);
        freeScopeToken((yyvsp[0].t_token).scope);
        free(temp);
    }
#line 3576 "./src/syntax.tab.c"
    break;

  case 82: /* listHeader: HEADER_LISTOP ID  */
#line 967 "./src/syntax.y"
                     {
        char* temp;

        temp = (char*) malloc(strlen((yyvsp[0].t_token).text) + strlen("List Header - ID: ") + 3);

        strcpy(temp, "List Header - ID: ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_CYAN);

        (yyval.t_node) = createNode(temp);

        freeScopeToken((yyvsp[0].t_token).scope);
        free(temp);
    }
#line 3596 "./src/syntax.tab.c"
    break;

  case 83: /* listTailDestructor: TAILDES_LISTOP ID  */
#line 989 "./src/syntax.y"
                      {
        char* temp;

        temp = (char*) malloc(strlen((yyvsp[0].t_token).text) + strlen("List Tail Destructor - ID: ") + 3);

        strcpy(temp, "List Tail Destructor - ID: ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_CYAN);

        (yyval.t_node) = createNode(temp);

        freeScopeToken((yyvsp[0].t_token).scope);
        free(temp);
    }
#line 3616 "./src/syntax.tab.c"
    break;

  case 84: /* listMap: ID ASSIGN_OP ID MAP_LISTOP ID  */
#line 1007 "./src/syntax.y"
                                  {
        char* temp;

        temp = (char*) malloc(strlen((yyvsp[-4].t_token).text) + strlen((yyvsp[-2].t_token).text) + strlen((yyvsp[0].t_token).text) + strlen("List Map - IDs: ") + 6);

        strcpy(temp, "List Map - IDs: ");
        strcat(temp, (yyvsp[-4].t_token).text);
        strcat(temp, ", ");
        strcat(temp, (yyvsp[-2].t_token).text);
        strcat(temp, ", ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_CYAN);

        (yyval.t_node) = createNode(temp);

        freeScopeToken((yyvsp[-4].t_token).scope);
        freeScopeToken((yyvsp[-2].t_token).scope);
        freeScopeToken((yyvsp[0].t_token).scope);
        free(temp);
    }
#line 3642 "./src/syntax.tab.c"
    break;

  case 85: /* listFilter: ID ASSIGN_OP ID FILTER_LISTOP ID  */
#line 1031 "./src/syntax.y"
                                     {
        char* temp;

        temp = (char*) malloc(strlen((yyvsp[-4].t_token).text) + strlen((yyvsp[-2].t_token).text) + strlen((yyvsp[0].t_token).text) + strlen("List Filter - IDs: ") + 6);

        strcpy(temp, "List Filter - IDs: ");
        strcat(temp, (yyvsp[-4].t_token).text);
        strcat(temp, ", ");
        strcat(temp, (yyvsp[-2].t_token).text);
        strcat(temp, ", ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_CYAN);

        (yyval.t_node) = createNode(temp);

        freeScopeToken((yyvsp[-4].t_token).scope);
        freeScopeToken((yyvsp[-2].t_token).scope);
        freeScopeToken((yyvsp[0].t_token).scope);
        free(temp);
    }
#line 3668 "./src/syntax.tab.c"
    break;


#line 3672 "./src/syntax.tab.c"

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

#line 1055 "./src/syntax.y"

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
            printTree();

            printParams();

            semanticAnalysis();

            /* print_end(); */
        }
        else{
            printf("Error while opening the file.\n");

        }

    }
    else{
        printf("No file has been chosen.\n");
    }

    /* test_colors(); */

    yylex_destroy();

    freeTable();
    freeScope();
    freeTree();

    return 0;
}
