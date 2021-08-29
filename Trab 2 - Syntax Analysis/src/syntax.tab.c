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
#line 2 "./src/syntax.y"

/* C declarations */
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yylex_destroy();
extern int yyparse();
extern void yyerror(const char* s);
extern FILE* yyin;

#line 83 "./src/syntax.tab.c"

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
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_NULL_CONST = 8,                 /* NULL_CONST  */
  YYSYMBOL_PLUS_OP = 9,                    /* PLUS_OP  */
  YYSYMBOL_MINUS_OP = 10,                  /* MINUS_OP  */
  YYSYMBOL_DIV_OP = 11,                    /* DIV_OP  */
  YYSYMBOL_MUL_OP = 12,                    /* MUL_OP  */
  YYSYMBOL_LOGIC_OP = 13,                  /* LOGIC_OP  */
  YYSYMBOL_BINARY_OP = 14,                 /* BINARY_OP  */
  YYSYMBOL_ASSIGN_OP = 15,                 /* ASSIGN_OP  */
  YYSYMBOL_EXCLA_OP = 16,                  /* EXCLA_OP  */
  YYSYMBOL_IF_KEY = 17,                    /* IF_KEY  */
  YYSYMBOL_ELSE_KEY = 18,                  /* ELSE_KEY  */
  YYSYMBOL_FOR_KEY = 19,                   /* FOR_KEY  */
  YYSYMBOL_RETURN_KEY = 20,                /* RETURN_KEY  */
  YYSYMBOL_INPUT_KEY = 21,                 /* INPUT_KEY  */
  YYSYMBOL_OUTPUT_KEY = 22,                /* OUTPUT_KEY  */
  YYSYMBOL_OUTPUTLN_KEY = 23,              /* OUTPUTLN_KEY  */
  YYSYMBOL_ASSIGN_LISTOP = 24,             /* ASSIGN_LISTOP  */
  YYSYMBOL_HEADER_LISTOP = 25,             /* HEADER_LISTOP  */
  YYSYMBOL_TAILDES_LISTOP = 26,            /* TAILDES_LISTOP  */
  YYSYMBOL_MAP_LISTOP = 27,                /* MAP_LISTOP  */
  YYSYMBOL_FILTER_LISTOP = 28,             /* FILTER_LISTOP  */
  YYSYMBOL_DELIM_PARENT = 29,              /* DELIM_PARENT  */
  YYSYMBOL_DELIM_BRACKET = 30,             /* DELIM_BRACKET  */
  YYSYMBOL_DELIM_CUR_BRACKET = 31,         /* DELIM_CUR_BRACKET  */
  YYSYMBOL_DELIM_COMMA = 32,               /* DELIM_COMMA  */
  YYSYMBOL_DELIM_SEMICOLLON = 33,          /* DELIM_SEMICOLLON  */
  YYSYMBOL_DELIM_SQUOTE = 34,              /* DELIM_SQUOTE  */
  YYSYMBOL_DELIM_DQUOTE = 35,              /* DELIM_DQUOTE  */
  YYSYMBOL_SINGLE_COMMENT = 36,            /* SINGLE_COMMENT  */
  YYSYMBOL_MULTI_COMMENT = 37,             /* MULTI_COMMENT  */
  YYSYMBOL_FORMAT_BLANKSPACE = 38,         /* FORMAT_BLANKSPACE  */
  YYSYMBOL_FORMAT_NEWLINE = 39,            /* FORMAT_NEWLINE  */
  YYSYMBOL_FORMAT_TAB = 40,                /* FORMAT_TAB  */
  YYSYMBOL_IF_KEYWORD = 41,                /* IF_KEYWORD  */
  YYSYMBOL_ELSE_KEYWORD = 42,              /* ELSE_KEYWORD  */
  YYSYMBOL_FOR_KEYWORD = 43,               /* FOR_KEYWORD  */
  YYSYMBOL_RETURN_KEYWORD = 44,            /* RETURN_KEYWORD  */
  YYSYMBOL_WRITE_KEYWORD = 45,             /* WRITE_KEYWORD  */
  YYSYMBOL_WRITELN_KEYWORD = 46,           /* WRITELN_KEYWORD  */
  YYSYMBOL_READ_KEYWORD = 47,              /* READ_KEYWORD  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '}'  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_declarationList = 56,           /* declarationList  */
  YYSYMBOL_declaration = 57,               /* declaration  */
  YYSYMBOL_varDeclaration = 58,            /* varDeclaration  */
  YYSYMBOL_varDeclList = 59,               /* varDeclList  */
  YYSYMBOL_varDeclId = 60,                 /* varDeclId  */
  YYSYMBOL_funcDeclaration = 61,           /* funcDeclaration  */
  YYSYMBOL_parameters = 62,                /* parameters  */
  YYSYMBOL_parameterList = 63,             /* parameterList  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_bodyStatement = 65,             /* bodyStatement  */
  YYSYMBOL_localDeclaration = 66,          /* localDeclaration  */
  YYSYMBOL_statementList = 67,             /* statementList  */
  YYSYMBOL_ifStatement = 68,               /* ifStatement  */
  YYSYMBOL_loopStatement = 69,             /* loopStatement  */
  YYSYMBOL_returnStatement = 70,           /* returnStatement  */
  YYSYMBOL_expression = 71,                /* expression  */
  YYSYMBOL_simpleExpression = 72,          /* simpleExpression  */
  YYSYMBOL_logicBinExpression = 73,        /* logicBinExpression  */
  YYSYMBOL_logicUnExpression = 74,         /* logicUnExpression  */
  YYSYMBOL_binExpression = 75,             /* binExpression  */
  YYSYMBOL_sumExpression = 76,             /* sumExpression  */
  YYSYMBOL_mulExpression = 77,             /* mulExpression  */
  YYSYMBOL_sumOP = 78,                     /* sumOP  */
  YYSYMBOL_mulOP = 79,                     /* mulOP  */
  YYSYMBOL_factor = 80,                    /* factor  */
  YYSYMBOL_functionCall = 81,              /* functionCall  */
  YYSYMBOL_writeOp = 82,                   /* writeOp  */
  YYSYMBOL_write = 83,                     /* write  */
  YYSYMBOL_writeln = 84,                   /* writeln  */
  YYSYMBOL_readOp = 85,                    /* readOp  */
  YYSYMBOL_listStatement = 86,             /* listStatement  */
  YYSYMBOL_listAssign = 87,                /* listAssign  */
  YYSYMBOL_listHeader = 88,                /* listHeader  */
  YYSYMBOL_listTail = 89,                  /* listTail  */
  YYSYMBOL_listTailDestructor = 90,        /* listTailDestructor  */
  YYSYMBOL_listMap = 91,                   /* listMap  */
  YYSYMBOL_listFilter = 92                 /* listFilter  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1877

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  294

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      49,    50,     2,     2,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   106,   107,   111,   112,   116,   120,   121,
     125,   129,   133,   134,   138,   139,   143,   144,   145,   146,
     147,   148,   149,   153,   157,   158,   162,   163,   167,   168,
     172,   176,   180,   181,   190,   199,   200,   204,   205,   213,
     214,   218,   219,   223,   224,   228,   229,   233,   234,   238,
     239,   240,   244,   248,   249,   253,   254,   258,   259,   263,
     267,   268,   269,   270,   271,   272,   276,   280,   284,   288,
     292,   296
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "ID",
  "TYPE", "STRING", "NULL_CONST", "PLUS_OP", "MINUS_OP", "DIV_OP",
  "MUL_OP", "LOGIC_OP", "BINARY_OP", "ASSIGN_OP", "EXCLA_OP", "IF_KEY",
  "ELSE_KEY", "FOR_KEY", "RETURN_KEY", "INPUT_KEY", "OUTPUT_KEY",
  "OUTPUTLN_KEY", "ASSIGN_LISTOP", "HEADER_LISTOP", "TAILDES_LISTOP",
  "MAP_LISTOP", "FILTER_LISTOP", "DELIM_PARENT", "DELIM_BRACKET",
  "DELIM_CUR_BRACKET", "DELIM_COMMA", "DELIM_SEMICOLLON", "DELIM_SQUOTE",
  "DELIM_DQUOTE", "SINGLE_COMMENT", "MULTI_COMMENT", "FORMAT_BLANKSPACE",
  "FORMAT_NEWLINE", "FORMAT_TAB", "IF_KEYWORD", "ELSE_KEYWORD",
  "FOR_KEYWORD", "RETURN_KEYWORD", "WRITE_KEYWORD", "WRITELN_KEYWORD",
  "READ_KEYWORD", "','", "'('", "')'", "'{'", "'}'", "';'", "$accept",
  "program", "declarationList", "declaration", "varDeclaration",
  "varDeclList", "varDeclId", "funcDeclaration", "parameters",
  "parameterList", "statement", "bodyStatement", "localDeclaration",
  "statementList", "ifStatement", "loopStatement", "returnStatement",
  "expression", "simpleExpression", "logicBinExpression",
  "logicUnExpression", "binExpression", "sumExpression", "mulExpression",
  "sumOP", "mulOP", "factor", "functionCall", "writeOp", "write",
  "writeln", "readOp", "listStatement", "listAssign", "listHeader",
  "listTail", "listTailDestructor", "listMap", "listFilter", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,    44,    40,
      41,   123,   125,    59
};
#endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-72)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,    14,    33,    17,    28,    96,   126,    20,     9,    35,
    -143,   182,     1,    31,    32,   -10,   170,    44,    47,   258,
    1700,    43,    85,    82,    86,   104,    40,   132,   135,   148,
     204,   214,   886,   227,   229,   424,   445,   690,   760,   765,
     791,   792,   793,   794,   823,   826,   869,   870,   871,   225,
     238,   874,    75,   231,    61,   239,    75,   917,   918,   322,
     420,  1748,   808,  1746,  1773,  1788,   243,   221,   307,   919,
     922,   910,   398,    93,   932,   217,   215,    40,     1,   714,
     240,   239,     6,    11,    59,     6,    79,   120,     6,   241,
     244,   248,   249,   261,   266,   934,  1073,   263,   324,   352,
     353,   319,   311,   965,   321,  1803,   755,  1863,  1818,  1833,
     977,   984,   987,  1002,  1003,   337,  1006,  1018,  1022,  1025,
     373,   343,  1848,   370,   316,  1043,   354,   370,  1044,    75,
      75,    16,    72,    84,   630,   577,   637,   699,   264,   311,
      75,   350,    -5,   101,   251,   133,   374,   403,   429,   151,
     392,   418,   379,   404,   348,   405,   406,   414,   459,   460,
     886,  1092,  1111,  1130,  1149,  1168,  1187,  1206,  1225,  1244,
    1263,  1282,  1301,  1320,  1339,  1358,     1,   753,   790,   814,
     886,   192,   775,   416,    99,   457,    75,   140,   140,   140,
     231,     1,   164,   461,   311,   145,   145,   145,   465,  1377,
      75,   231,   464,   385,    75,  1396,  1415,   953,   975,   838,
     712,   483,   527,   546,   493,   356,   361,  1434,  1453,   910,
     462,   266,   910,   316,   836,   105,   693,   884,  1725,   470,
     474,   448,   186,   283,   508,   517,   408,   475,   480,   348,
       1,   329,   994,   492,   385,   147,   147,   147,   495,   504,
     514,   523,   524,   458,  1731,   862,   525,   526,   571,   509,
     570,   587,   542,   311,  1472,   544,   590,  1016,   731,   609,
     653,  1491,  1510,  1529,  1548,  1567,  1586,   419,  1605,  1624,
    1643,   886,  1035,   543,   672,   910,   554,   316,   556,  1662,
     567,  1054,   554,  1681
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,   633,    21,   539,    -8,  -143,   -72,  -143,
     617,   -20,  -142,   -92,   618,   625,   632,   -31,   -25,   -14,
     208,   228,   205,   130,  -132,  -121,   -23,    56,   634,   635,
     636,   639,   648,   651,   679,   680,   681,   695,   696
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    95,     8,     9,     6,    15,    16,
      96,   161,    71,    97,   162,   163,   164,    57,   141,   131,
     132,   133,   134,   135,    85,    88,   136,   137,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    58,   188,    64,   115,    18,   104,    14,   194,    -7,
       1,   149,    59,   196,   189,    -7,   -45,    -2,   219,     7,
     -10,     5,    76,     1,     5,   197,   -10,    75,    -4,   186,
     147,    80,    64,    10,    -4,    -9,    17,    19,   222,   142,
      20,    -9,    91,    93,   -10,    54,   103,    -8,   -34,    49,
     -10,   -13,    58,    -8,    64,    56,    55,    13,    64,    64,
     -45,   -49,    64,    59,   -46,   109,   -34,   -49,   -10,    12,
     -49,   -49,   -49,   -49,   -49,   -49,    77,   121,   246,   147,
      74,   120,    65,    -9,   -48,   -36,   179,    51,   142,    56,
     247,   129,   -10,   126,   188,    -8,    -5,   -38,   187,   183,
      50,   196,    -5,   125,   220,   185,   189,   128,   -46,   148,
      78,    65,   -37,   197,   -36,   193,   147,    98,   -35,   230,
      99,   100,   -36,   205,   130,   -47,    -6,   253,   -48,   206,
     256,   212,    -6,    65,   -38,    52,   246,    65,    65,   285,
     207,    65,    83,    84,    65,    74,   -40,   -40,   247,   -37,
     181,   -49,   241,    53,   -36,   -35,    63,   -49,   148,   229,
     -49,   -49,   -49,   -49,   -49,   -49,   228,   147,   265,   -47,
     238,   147,   147,   147,   235,   237,   142,   -37,   147,   243,
     212,    66,    -3,   146,    67,    63,   -40,   142,    -3,   130,
     250,   252,   257,   288,   140,   148,   204,    68,   183,   -35,
      78,   -49,   -49,   -49,   -49,   -49,   -49,    63,   264,    69,
     213,    63,    63,   255,   206,   108,   212,   -37,    21,    70,
     -12,   212,   212,   212,   270,   207,    74,   -11,    90,   -16,
      72,    62,   146,   -11,    60,   -16,   138,   129,   283,   -35,
     147,   191,   282,    73,   149,   -49,   148,   139,    89,   142,
     148,   148,   148,   148,    61,    55,   290,   148,   145,   213,
      62,   143,   183,    79,   -38,   195,   289,   101,   102,   146,
     130,   177,   293,   -49,   -49,   -49,   -49,   -49,   -49,   190,
     140,   144,    62,    61,   211,    60,    62,   107,    56,   106,
     105,   110,    83,    84,   111,   213,   -39,   -39,   112,   113,
     213,   213,   213,   213,   -38,    61,   -15,   145,   -15,    61,
     143,   114,    74,   191,    92,   116,   181,   -49,   227,   148,
     146,   182,   -34,   129,   146,   146,   234,   139,   -34,   117,
     144,   146,   129,   211,   -49,    81,   -39,   184,   -49,   -49,
     -49,   -49,   -49,   -49,   145,   -49,   -49,   192,   -49,   -49,
     -49,   -49,   -49,   202,   -49,   -49,   130,   118,   119,   210,
     140,    74,   208,   249,   203,   130,    74,   144,   251,   211,
     180,   122,   129,   -28,   211,   211,   269,   129,   240,   -28,
     -49,   -49,   209,   -42,   -42,    86,    87,   -42,   -42,   -26,
     241,   123,   226,   146,   225,   145,   124,   204,   143,   145,
     233,   203,   232,   -33,   127,   130,   145,   198,   210,   143,
     130,   242,   -44,   -44,   -44,   -44,   -44,   -44,   144,   -23,
     -36,    32,   144,   199,   -17,   -23,   -36,   -42,   200,   144,
     -17,   209,   259,   -36,   204,   260,   261,   -23,   -50,   -50,
     -50,   -50,   -50,   -50,   210,   -18,   -14,   208,   -14,   210,
     268,   -18,   267,   201,   214,   215,   -44,   -51,   -51,   -51,
     -51,   -51,   -51,   216,   217,   218,   -33,   209,   145,   -49,
     236,   143,   209,   -49,   -49,   -49,   -49,   -49,   -49,   239,
     -49,   -49,   -50,   -49,   -49,   -49,   -49,   -49,   -42,   -49,
     -49,   144,   -42,   -42,    86,    87,   -42,   -42,   248,   -42,
     -42,   -51,   -42,   -42,   -42,   -42,   -42,   224,   -42,   -42,
     276,   231,   254,   240,   278,   -49,   -49,   -41,   -41,    86,
      87,   -41,   -41,   -32,   258,   262,   -43,   -43,   -43,   -43,
     -43,   -43,   -44,   263,   -42,   -42,   -44,   -44,   -44,   -44,
     -44,   -44,   266,   -44,   -44,   271,   -44,   -44,   -44,   -44,
     -44,   -50,   -44,   -44,   272,   -50,   -50,   -50,   -50,   -50,
     -50,   -41,   -50,   -50,   273,   -50,   -50,   -50,   -50,   -50,
     -43,   -50,   -50,   274,   275,   279,   -32,   277,   -44,   -44,
     -52,   -52,   -52,   -52,   -52,   -52,   -42,   -42,    86,    87,
     -42,   -42,   280,   281,   284,   -51,   287,   -50,   -50,   -51,
     -51,   -51,   -51,   -51,   -51,   160,   -51,   -51,   291,   -51,
     -51,   -51,   -51,   -51,   -41,   -51,   -51,   292,   -41,   -41,
      86,    87,   -41,   -41,   -52,   -41,   -41,   -42,   -41,   -41,
     -41,   -41,   -41,   178,   -41,   -41,    11,    33,    35,    83,
      84,   -51,   -51,   -40,   -40,    36,   -44,   -44,   -44,   -44,
     -44,   -44,    37,     0,    38,    39,    40,     0,   -43,    41,
     -41,   -41,   -43,   -43,   -43,   -43,   -43,   -43,    42,   -43,
     -43,    43,   -43,   -43,   -43,   -43,   -43,   -52,   -43,   -43,
     -40,   -52,   -52,   -52,   -52,   -52,   -52,   -44,   -52,   -52,
     -19,   -52,   -52,   -52,   -52,   -52,   -19,   -52,   -52,    44,
      45,    46,    83,    84,   -43,   -43,   -39,   -39,   -50,   -50,
     -50,   -50,   -50,   -50,   -37,    47,    48,   -40,     0,     0,
     -37,    83,    84,   -52,   -52,   -40,   -40,   -37,   -40,   -40,
       0,   -40,   -40,   -40,   -40,   -40,   -39,   -40,   -40,     0,
      83,    84,     0,   -39,   -39,   -39,     0,   -39,   -39,   -50,
     -39,   -39,   -39,   -39,   -39,   -35,   -39,   -39,   -10,   -10,
     -21,   -35,     0,   -40,   -40,   -53,   -21,     0,   -35,   -10,
     -10,   -53,   -10,   -10,   -10,   -10,   -10,     0,   -10,   -10,
       0,     0,   -39,   -39,   -49,   -49,   -49,   -49,   -49,   -49,
     223,   -54,   -22,   -20,   -60,    -7,    -7,   -54,   -22,   -20,
     -60,   -10,     0,     0,   -10,   -10,    -7,    -7,   -40,    -7,
      -7,    -7,    -7,    -7,   -40,    -7,    -7,    83,    84,    -9,
      -9,   -40,   -40,   -61,   176,   -49,   -62,     0,     0,   -61,
      -9,    -9,   -62,    -9,    -9,    -9,    -9,    -9,   221,    -9,
      -9,    -7,    -7,   -38,     0,   -51,   -51,   -51,   -51,   -51,
     -51,   -38,   245,     0,   -38,   -38,     0,   -38,   -38,   -38,
     -38,   -38,    -9,   -38,   -38,    -9,    -9,    -8,    -8,   -63,
     -64,   -65,     0,     0,   -68,   -63,   -64,   -65,    -8,    -8,
     -68,    -8,    -8,    -8,    -8,    -8,   -51,    -8,    -8,   -38,
     -38,   -25,   -25,   -41,   -41,    86,    87,   -41,   -41,     0,
       0,     0,   -25,   -25,     0,   -25,   -25,   -25,   -25,   -25,
      -8,   -25,   -25,    -8,    -8,   150,    94,   -31,   -33,   -67,
       0,     0,   -69,   -31,   -33,   -67,   151,   152,   -69,   153,
     154,   155,   156,   157,   -41,   158,   159,   -25,   -25,   -24,
     -24,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,
     -24,   -24,     0,   -24,   -24,   -24,   -24,   -24,   -34,   -24,
     -24,   160,   -27,     0,     0,   -32,   244,     0,     0,   -34,
     -34,   -32,   -34,   -34,   -34,   -34,   -34,   -59,   -34,   -34,
     -36,   176,   -49,   -59,   -55,   -24,   -24,   -56,   -36,     0,
     -55,   -36,   -36,   -56,   -36,   -36,   -36,   -36,   -36,   -37,
     -36,   -36,   -57,   -58,   -34,   -34,   -23,   -37,   -57,   -58,
     -37,   -37,   -23,   -37,   -37,   -37,   -37,   -37,   -66,   -37,
     -37,   -35,   -70,     0,   -66,   -71,   -36,   -36,   -70,   -35,
       0,   -71,   -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,
     -28,   -35,   -35,   -29,   -30,   -37,   -37,     0,     0,   -29,
     -30,   -28,   -28,   286,   -28,   -28,   -28,   -28,   -28,   -23,
     -28,   -28,     0,     0,     0,     0,     0,   -35,   -35,     0,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   150,   -23,
     -23,     0,     0,     0,     0,     0,   -28,   -28,     0,   151,
     152,     0,   153,   154,   155,   156,   157,   -16,   158,   159,
       0,     0,     0,     0,     0,   -23,   -23,     0,   -16,   -16,
       0,   -16,   -16,   -16,   -16,   -16,   -17,   -16,   -16,     0,
       0,     0,     0,     0,   160,   -27,     0,   -17,   -17,     0,
     -17,   -17,   -17,   -17,   -17,   -18,   -17,   -17,     0,     0,
       0,     0,     0,   -16,   -16,     0,   -18,   -18,     0,   -18,
     -18,   -18,   -18,   -18,   -19,   -18,   -18,     0,     0,     0,
       0,     0,   -17,   -17,     0,   -19,   -19,     0,   -19,   -19,
     -19,   -19,   -19,   -21,   -19,   -19,     0,     0,     0,     0,
       0,   -18,   -18,     0,   -21,   -21,     0,   -21,   -21,   -21,
     -21,   -21,   -53,   -21,   -21,     0,     0,     0,     0,     0,
     -19,   -19,     0,   -53,   -53,     0,   -53,   -53,   -53,   -53,
     -53,   -54,   -53,   -53,     0,     0,     0,     0,     0,   -21,
     -21,     0,   -54,   -54,     0,   -54,   -54,   -54,   -54,   -54,
     -22,   -54,   -54,     0,     0,     0,     0,     0,   -53,   -53,
       0,   -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,   -20,
     -22,   -22,     0,     0,     0,     0,     0,   -54,   -54,     0,
     -20,   -20,     0,   -20,   -20,   -20,   -20,   -20,   -60,   -20,
     -20,     0,     0,     0,     0,     0,   -22,   -22,     0,   -60,
     -60,     0,   -60,   -60,   -60,   -60,   -60,   -61,   -60,   -60,
       0,     0,     0,     0,     0,   -20,   -20,     0,   -61,   -61,
       0,   -61,   -61,   -61,   -61,   -61,   -62,   -61,   -61,     0,
       0,     0,     0,     0,   -60,   -60,     0,   -62,   -62,     0,
     -62,   -62,   -62,   -62,   -62,   -63,   -62,   -62,     0,     0,
       0,     0,     0,   -61,   -61,     0,   -63,   -63,     0,   -63,
     -63,   -63,   -63,   -63,   -64,   -63,   -63,     0,     0,     0,
       0,     0,   -62,   -62,     0,   -64,   -64,     0,   -64,   -64,
     -64,   -64,   -64,   -65,   -64,   -64,     0,     0,     0,     0,
       0,   -63,   -63,     0,   -65,   -65,     0,   -65,   -65,   -65,
     -65,   -65,   -68,   -65,   -65,     0,     0,     0,     0,     0,
     -64,   -64,     0,   -68,   -68,     0,   -68,   -68,   -68,   -68,
     -68,   -31,   -68,   -68,     0,     0,     0,     0,     0,   -65,
     -65,     0,   -31,   -31,     0,   -31,   -31,   -31,   -31,   -31,
     -33,   -31,   -31,     0,     0,     0,     0,     0,   -68,   -68,
       0,   -33,   -33,     0,   -33,   -33,   -33,   -33,   -33,   -67,
     -33,   -33,     0,     0,     0,     0,     0,   -31,   -31,     0,
     -67,   -67,     0,   -67,   -67,   -67,   -67,   -67,   -69,   -67,
     -67,     0,     0,     0,     0,     0,   -33,   -33,     0,   -69,
     -69,     0,   -69,   -69,   -69,   -69,   -69,   -32,   -69,   -69,
       0,     0,     0,     0,     0,   -67,   -67,     0,   -32,   -32,
       0,   -32,   -32,   -32,   -32,   -32,   -59,   -32,   -32,     0,
       0,     0,     0,     0,   -69,   -69,     0,   -59,   -59,     0,
     -59,   -59,   -59,   -59,   -59,   -55,   -59,   -59,     0,     0,
       0,     0,     0,   -32,   -32,     0,   -55,   -55,     0,   -55,
     -55,   -55,   -55,   -55,   -56,   -55,   -55,     0,     0,     0,
       0,     0,   -59,   -59,     0,   -56,   -56,     0,   -56,   -56,
     -56,   -56,   -56,   -57,   -56,   -56,     0,     0,     0,     0,
       0,   -55,   -55,     0,   -57,   -57,     0,   -57,   -57,   -57,
     -57,   -57,   -58,   -57,   -57,     0,     0,     0,     0,     0,
     -56,   -56,     0,   -58,   -58,     0,   -58,   -58,   -58,   -58,
     -58,   -23,   -58,   -58,     0,     0,     0,     0,     0,   -57,
     -57,     0,   -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,
     -66,   -23,   -23,     0,     0,     0,     0,     0,   -58,   -58,
       0,   -66,   -66,     0,   -66,   -66,   -66,   -66,   -66,   -70,
     -66,   -66,     0,     0,     0,     0,     0,   -23,   -23,     0,
     -70,   -70,     0,   -70,   -70,   -70,   -70,   -70,   -71,   -70,
     -70,     0,     0,     0,     0,     0,   -66,   -66,     0,   -71,
     -71,     0,   -71,   -71,   -71,   -71,   -71,   -29,   -71,   -71,
       0,     0,     0,     0,     0,   -70,   -70,     0,   -29,   -29,
       0,   -29,   -29,   -29,   -29,   -29,   -30,   -29,   -29,     0,
       0,     0,     0,     0,   -71,   -71,     0,   -30,   -30,     0,
     -30,   -30,   -30,   -30,   -30,    22,   -30,   -30,     0,     0,
       0,     0,     0,   -29,   -29,     0,    23,    24,     0,    25,
      26,    27,    28,    29,     0,    30,    31,     0,     0,     0,
       0,     0,   -30,   -30,   -43,   -43,   -43,   -43,   -43,   -43,
     -52,   -52,   -52,   -52,   -52,   -52,   -42,     0,   -38,     0,
       0,    32,   -42,     0,   -38,   -42,   -42,    86,    87,   -42,
     -42,   -38,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -44,     0,   -43,     0,     0,     0,   -44,
       0,   -52,   -44,   -44,   -44,   -44,   -44,   -44,   -50,     0,
       0,     0,     0,     0,   -50,     0,     0,   -50,   -50,   -50,
     -50,   -50,   -50,   -51,     0,     0,     0,     0,     0,   -51,
       0,     0,   -51,   -51,   -51,   -51,   -51,   -51,   -41,     0,
       0,     0,     0,     0,   -41,     0,     0,   -41,   -41,    86,
      87,   -41,   -41,   -43,     0,     0,     0,     0,     0,   -43,
       0,     0,   -43,   -43,   -43,   -43,   -43,   -43,   -52,     0,
       0,     0,     0,     0,   -52,     0,     0,   -52,   -52,   -52,
     -52,   -52,   -52,   -39,     0,     0,     0,     0,     0,   -39,
       0,     0,    83,    84,     0,     0,   -39,   -39
};

static const yytype_int16 yycheck[] =
{
      20,    26,   134,    26,    96,    13,    78,     6,    13,     0,
       6,     5,    26,   145,   135,     6,     5,     0,   160,     5,
       0,     0,    53,     6,     3,   146,     6,    52,     0,    13,
      53,    56,    55,     0,     6,     0,     5,     5,   180,    53,
      50,     6,    67,    68,     0,     5,    77,     0,    53,     6,
       6,    50,    77,     6,    77,    49,    16,    48,    81,    82,
      49,     0,    85,    77,     5,    88,    50,     6,    48,    49,
       9,    10,    11,    12,    13,    14,    15,   102,   210,   102,
       5,   101,    26,    48,     5,    13,    94,     5,   102,    49,
     211,    16,    48,   124,   226,    48,     0,    13,    14,   124,
      15,   233,     6,   123,   176,   130,   227,   127,    49,    53,
      49,    55,    13,   234,    13,   140,   139,    24,    13,   191,
      27,    28,    50,   154,    49,     5,     0,   219,    49,   154,
     222,   154,     6,    77,    50,    49,   268,    81,    82,   281,
     154,    85,     9,    10,    88,     5,    13,    14,   269,    50,
       5,     0,     5,    49,    53,    50,    26,     6,   102,   190,
       9,    10,    11,    12,    13,    14,   189,   190,   240,    49,
     201,   194,   195,   196,   197,   200,   190,    13,   201,   204,
     203,    49,     0,    53,    49,    55,    53,   201,     6,    49,
     215,   216,   223,   285,    49,   139,    49,    49,   223,    13,
      49,     9,    10,    11,    12,    13,    14,    77,   239,     5,
     154,    81,    82,   221,   239,    85,   239,    53,    48,     5,
      50,   244,   245,   246,   247,   239,     5,     0,     7,     0,
       5,    26,   102,     6,    26,     6,     5,    16,   263,    53,
     263,    49,   262,     5,     5,    53,   190,    16,     5,   263,
     194,   195,   196,   197,    26,    16,   287,   201,    53,   203,
      55,    53,   287,    55,    13,    14,   286,    50,    53,   139,
      49,     5,   292,     9,    10,    11,    12,    13,    14,    15,
      49,    53,    77,    55,   154,    77,    81,    82,    49,    81,
      50,    50,     9,    10,    50,   239,    13,    14,    50,    50,
     244,   245,   246,   247,    53,    77,    48,   102,    50,    81,
     102,    50,     5,    49,     7,    52,     5,    53,   188,   263,
     190,     5,     0,    16,   194,   195,   196,    16,     6,     5,
     102,   201,    16,   203,     5,    13,    53,   129,     9,    10,
      11,    12,    13,    14,   139,    16,    17,   139,    19,    20,
      21,    22,    23,     5,    25,    26,    49,     5,     5,   154,
      49,     5,   154,     7,    16,    49,     5,   139,     7,   239,
      51,    50,    16,     0,   244,   245,   246,    16,    49,     6,
      51,    52,   154,     9,    10,    11,    12,    13,    14,    52,
       5,    18,   187,   263,   186,   190,    53,    49,   190,   194,
     195,    16,   194,    53,    50,    49,   201,    15,   203,   201,
      49,   203,     9,    10,    11,    12,    13,    14,   190,     0,
       0,    51,   194,     5,     0,     6,     6,    53,    49,   201,
       6,   203,    24,    13,    49,    27,    28,    18,     9,    10,
      11,    12,    13,    14,   239,     0,    48,   239,    50,   244,
     245,     6,   244,    49,    49,    49,    53,     9,    10,    11,
      12,    13,    14,    49,     5,     5,    50,   239,   263,     5,
       5,   263,   244,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    53,    19,    20,    21,    22,    23,     5,    25,
      26,   263,     9,    10,    11,    12,    13,    14,     5,    16,
      17,    53,    19,    20,    21,    22,    23,    50,    25,    26,
      52,    50,    50,    49,     5,    51,    52,     9,    10,    11,
      12,    13,    14,    53,    50,    50,     9,    10,    11,    12,
      13,    14,     5,    53,    51,    52,     9,    10,    11,    12,
      13,    14,    50,    16,    17,    50,    19,    20,    21,    22,
      23,     5,    25,    26,    50,     9,    10,    11,    12,    13,
      14,    53,    16,    17,    50,    19,    20,    21,    22,    23,
      53,    25,    26,    50,    50,     5,    50,    52,    51,    52,
       9,    10,    11,    12,    13,    14,     9,    10,    11,    12,
      13,    14,     5,    51,    50,     5,    53,    51,    52,     9,
      10,    11,    12,    13,    14,    51,    16,    17,    52,    19,
      20,    21,    22,    23,     5,    25,    26,    50,     9,    10,
      11,    12,    13,    14,    53,    16,    17,    50,    19,    20,
      21,    22,    23,    94,    25,    26,     3,    20,    20,     9,
      10,    51,    52,    13,    14,    20,     9,    10,    11,    12,
      13,    14,    20,    -1,    20,    20,    20,    -1,     5,    20,
      51,    52,     9,    10,    11,    12,    13,    14,    20,    16,
      17,    20,    19,    20,    21,    22,    23,     5,    25,    26,
      50,     9,    10,    11,    12,    13,    14,    50,    16,    17,
       0,    19,    20,    21,    22,    23,     6,    25,    26,    20,
      20,    20,     9,    10,    51,    52,    13,    14,     9,    10,
      11,    12,    13,    14,     0,    20,    20,     5,    -1,    -1,
       6,     9,    10,    51,    52,    13,    14,    13,    16,    17,
      -1,    19,    20,    21,    22,    23,     5,    25,    26,    -1,
       9,    10,    -1,    50,    13,    14,    -1,    16,    17,    50,
      19,    20,    21,    22,    23,     0,    25,    26,     5,     6,
       0,     6,    -1,    51,    52,     0,     6,    -1,    13,    16,
      17,     6,    19,    20,    21,    22,    23,    -1,    25,    26,
      -1,    -1,    51,    52,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     5,     6,     6,     6,     6,
       6,    48,    -1,    -1,    51,    52,    16,    17,     0,    19,
      20,    21,    22,    23,     6,    25,    26,     9,    10,     5,
       6,    13,    14,     0,    49,    50,     0,    -1,    -1,     6,
      16,    17,     6,    19,    20,    21,    22,    23,    48,    25,
      26,    51,    52,     5,    -1,     9,    10,    11,    12,    13,
      14,    13,    14,    -1,    16,    17,    -1,    19,    20,    21,
      22,    23,    48,    25,    26,    51,    52,     5,     6,     0,
       0,     0,    -1,    -1,     0,     6,     6,     6,    16,    17,
       6,    19,    20,    21,    22,    23,    50,    25,    26,    51,
      52,     5,     6,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    16,    17,    -1,    19,    20,    21,    22,    23,
      48,    25,    26,    51,    52,     5,     6,     0,     0,     0,
      -1,    -1,     0,     6,     6,     6,    16,    17,     6,    19,
      20,    21,    22,    23,    50,    25,    26,    51,    52,     5,
       6,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      16,    17,    -1,    19,    20,    21,    22,    23,     5,    25,
      26,    51,    52,    -1,    -1,     0,    13,    -1,    -1,    16,
      17,     6,    19,    20,    21,    22,    23,     0,    25,    26,
       5,    49,    50,     6,     0,    51,    52,     0,    13,    -1,
       6,    16,    17,     6,    19,    20,    21,    22,    23,     5,
      25,    26,     0,     0,    51,    52,     0,    13,     6,     6,
      16,    17,     6,    19,    20,    21,    22,    23,     0,    25,
      26,     5,     0,    -1,     6,     0,    51,    52,     6,    13,
      -1,     6,    16,    17,    -1,    19,    20,    21,    22,    23,
       5,    25,    26,     0,     0,    51,    52,    -1,    -1,     6,
       6,    16,    17,    18,    19,    20,    21,    22,    23,     5,
      25,    26,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,     5,    25,
      26,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    16,
      17,    -1,    19,    20,    21,    22,    23,     5,    25,    26,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    16,    17,
      -1,    19,    20,    21,    22,    23,     5,    25,    26,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    16,    17,    -1,
      19,    20,    21,    22,    23,     5,    25,    26,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    16,    17,    -1,    19,
      20,    21,    22,    23,     5,    25,    26,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    16,    17,    -1,    19,    20,
      21,    22,    23,     5,    25,    26,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    16,    17,    -1,    19,    20,    21,
      22,    23,     5,    25,    26,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    16,    17,    -1,    19,    20,    21,    22,
      23,     5,    25,    26,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    16,    17,    -1,    19,    20,    21,    22,    23,
       5,    25,    26,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    16,    17,    -1,    19,    20,    21,    22,    23,     5,
      25,    26,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      16,    17,    -1,    19,    20,    21,    22,    23,     5,    25,
      26,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    16,
      17,    -1,    19,    20,    21,    22,    23,     5,    25,    26,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    16,    17,
      -1,    19,    20,    21,    22,    23,     5,    25,    26,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    16,    17,    -1,
      19,    20,    21,    22,    23,     5,    25,    26,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    16,    17,    -1,    19,
      20,    21,    22,    23,     5,    25,    26,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    16,    17,    -1,    19,    20,
      21,    22,    23,     5,    25,    26,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    16,    17,    -1,    19,    20,    21,
      22,    23,     5,    25,    26,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    16,    17,    -1,    19,    20,    21,    22,
      23,     5,    25,    26,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    16,    17,    -1,    19,    20,    21,    22,    23,
       5,    25,    26,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    16,    17,    -1,    19,    20,    21,    22,    23,     5,
      25,    26,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      16,    17,    -1,    19,    20,    21,    22,    23,     5,    25,
      26,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    16,
      17,    -1,    19,    20,    21,    22,    23,     5,    25,    26,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    16,    17,
      -1,    19,    20,    21,    22,    23,     5,    25,    26,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    16,    17,    -1,
      19,    20,    21,    22,    23,     5,    25,    26,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    16,    17,    -1,    19,
      20,    21,    22,    23,     5,    25,    26,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    16,    17,    -1,    19,    20,
      21,    22,    23,     5,    25,    26,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    16,    17,    -1,    19,    20,    21,
      22,    23,     5,    25,    26,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    16,    17,    -1,    19,    20,    21,    22,
      23,     5,    25,    26,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    16,    17,    -1,    19,    20,    21,    22,    23,
       5,    25,    26,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    16,    17,    -1,    19,    20,    21,    22,    23,     5,
      25,    26,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      16,    17,    -1,    19,    20,    21,    22,    23,     5,    25,
      26,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    16,
      17,    -1,    19,    20,    21,    22,    23,     5,    25,    26,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    16,    17,
      -1,    19,    20,    21,    22,    23,     5,    25,    26,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    16,    17,    -1,
      19,    20,    21,    22,    23,     5,    25,    26,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    16,    17,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    51,    52,     9,    10,    11,    12,    13,    14,
       9,    10,    11,    12,    13,    14,     0,    -1,     0,    -1,
      -1,    51,     6,    -1,     6,     9,    10,    11,    12,    13,
      14,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    -1,    50,    -1,    -1,    -1,     6,
      -1,    50,     9,    10,    11,    12,    13,    14,     0,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,     0,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,     0,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,     0,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,     0,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,     0,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,     9,    10,    -1,    -1,    13,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    55,    56,    57,    58,    61,     5,    59,    60,
       0,    57,    49,    48,     6,    62,    63,     5,    60,     5,
      50,    48,     5,    16,    17,    19,    20,    21,    22,    23,
      25,    26,    51,    64,    65,    68,    69,    70,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     6,
      15,     5,    49,    49,     5,    16,    49,    71,    72,    73,
      74,    75,    76,    77,    80,    81,    49,    49,    49,     5,
       5,    66,     5,     5,     5,    72,    71,    15,    49,    74,
      72,    13,    14,     9,    10,    78,    11,    12,    79,     5,
       7,    72,     7,    72,     6,    58,    64,    67,    24,    27,
      28,    50,    53,    71,    62,    50,    74,    76,    77,    80,
      50,    50,    50,    50,    50,    67,    52,     5,     5,     5,
      65,    72,    50,    18,    53,    65,    71,    50,    65,    16,
      49,    73,    74,    75,    76,    77,    80,    81,     5,    16,
      49,    72,    73,    74,    75,    76,    77,    80,    81,     5,
       5,    16,    17,    19,    20,    21,    22,    23,    25,    26,
      51,    65,    68,    69,    70,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    49,     5,    59,    60,
      51,     5,     5,    72,    74,    72,    13,    14,    78,    79,
      15,    49,    74,    72,    13,    14,    78,    79,    15,     5,
      49,    49,     5,    16,    49,    71,    72,    73,    74,    75,
      76,    77,    80,    81,    49,    49,    49,     5,     5,    66,
      62,    48,    66,    15,    50,    74,    76,    77,    80,    71,
      62,    50,    74,    76,    77,    80,     5,    72,    71,    15,
      49,     5,    74,    72,    13,    14,    78,    79,     5,     7,
      72,     7,    72,    67,    50,    60,    67,    71,    50,    24,
      27,    28,    50,    53,    71,    62,    50,    74,    76,    77,
      80,    50,    50,    50,    50,    50,    52,    52,     5,     5,
       5,    51,    65,    72,    50,    66,    18,    53,    67,    65,
      71,    52,    50,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      60,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    65,    66,    66,    67,    67,    68,    68,
      69,    70,    71,    71,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    81,    82,    82,    83,    83,    84,    84,    85,
      86,    86,    86,    86,    86,    86,    87,    88,    89,    90,
      91,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     3,     1,
       1,     6,     1,     0,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     2,     0,     2,     0,     5,     7,
       9,     2,     3,     1,     1,     3,     1,     2,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     1,     1,     4,     4,     4,     4,     4,
       1,     1,     1,     1,     1,     1,     5,     2,     2,     2,
       5,     5
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
#line 102 "./src/syntax.y"
                    { printf("%d", yyvsp[0]); }
#line 1671 "./src/syntax.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 106 "./src/syntax.y"
                                {printf("%d %d", yyvsp[-1], yyvsp[0]);}
#line 1677 "./src/syntax.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 107 "./src/syntax.y"
                  {printf("%d", yyvsp[0]);}
#line 1683 "./src/syntax.tab.c"
    break;

  case 5: /* declaration: varDeclaration  */
#line 111 "./src/syntax.y"
                   {printf("%d", yyvsp[0]);}
#line 1689 "./src/syntax.tab.c"
    break;

  case 6: /* declaration: funcDeclaration  */
#line 112 "./src/syntax.y"
                      {printf("%d", yyvsp[0]);}
#line 1695 "./src/syntax.tab.c"
    break;

  case 7: /* varDeclaration: TYPE varDeclList  */
#line 116 "./src/syntax.y"
                     {printf("%d %d", yyvsp[-1], yyvsp[0]);}
#line 1701 "./src/syntax.tab.c"
    break;

  case 8: /* varDeclList: varDeclList ',' varDeclId  */
#line 120 "./src/syntax.y"
                              {printf("%d %d", yyvsp[-2], yyvsp[-1]);}
#line 1707 "./src/syntax.tab.c"
    break;

  case 9: /* varDeclList: varDeclId  */
#line 121 "./src/syntax.y"
                {printf("%d", yyvsp[0]);}
#line 1713 "./src/syntax.tab.c"
    break;

  case 10: /* varDeclId: ID  */
#line 125 "./src/syntax.y"
       {printf("%d", yyvsp[0]);}
#line 1719 "./src/syntax.tab.c"
    break;

  case 11: /* funcDeclaration: TYPE ID '(' parameters ')' statement  */
#line 129 "./src/syntax.y"
                                         {printf("%d %d %d %d %d %d", yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1725 "./src/syntax.tab.c"
    break;

  case 12: /* parameters: parameterList  */
#line 133 "./src/syntax.y"
                  {printf("%d", yyvsp[0]);}
#line 1731 "./src/syntax.tab.c"
    break;

  case 13: /* parameters: %empty  */
#line 134 "./src/syntax.y"
      {}
#line 1737 "./src/syntax.tab.c"
    break;

  case 14: /* parameterList: parameterList ',' TYPE ID  */
#line 138 "./src/syntax.y"
                              {printf("%d %d %d", yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 1743 "./src/syntax.tab.c"
    break;

  case 15: /* parameterList: TYPE ID  */
#line 139 "./src/syntax.y"
              {printf("%d %d", yyvsp[-1], yyvsp[0]);}
#line 1749 "./src/syntax.tab.c"
    break;

  case 16: /* statement: bodyStatement  */
#line 143 "./src/syntax.y"
                  {printf("%d", yyvsp[0]);}
#line 1755 "./src/syntax.tab.c"
    break;

  case 17: /* statement: ifStatement  */
#line 144 "./src/syntax.y"
                  {printf("%d", yyvsp[0]);}
#line 1761 "./src/syntax.tab.c"
    break;

  case 18: /* statement: loopStatement  */
#line 145 "./src/syntax.y"
                    {printf("%d", yyvsp[0]);}
#line 1767 "./src/syntax.tab.c"
    break;

  case 19: /* statement: returnStatement  */
#line 146 "./src/syntax.y"
                      {printf("%d", yyvsp[0]);}
#line 1773 "./src/syntax.tab.c"
    break;

  case 20: /* statement: listStatement  */
#line 147 "./src/syntax.y"
                    {printf("%d", yyvsp[0]);}
#line 1779 "./src/syntax.tab.c"
    break;

  case 21: /* statement: writeOp  */
#line 148 "./src/syntax.y"
              {printf("%d", yyvsp[0]);}
#line 1785 "./src/syntax.tab.c"
    break;

  case 22: /* statement: readOp  */
#line 149 "./src/syntax.y"
             {printf("%d", yyvsp[0]);}
#line 1791 "./src/syntax.tab.c"
    break;

  case 23: /* bodyStatement: '{' localDeclaration statementList '}'  */
#line 153 "./src/syntax.y"
                                           {printf("%d %d %d %d", yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1797 "./src/syntax.tab.c"
    break;

  case 24: /* localDeclaration: localDeclaration varDeclaration  */
#line 157 "./src/syntax.y"
                                    {printf("%d %d", yyvsp[-1], yyvsp[0]);}
#line 1803 "./src/syntax.tab.c"
    break;

  case 25: /* localDeclaration: %empty  */
#line 158 "./src/syntax.y"
      {}
#line 1809 "./src/syntax.tab.c"
    break;

  case 26: /* statementList: statement statementList  */
#line 162 "./src/syntax.y"
                            {printf("%d %d", yyvsp[-1], yyvsp[0]);}
#line 1815 "./src/syntax.tab.c"
    break;

  case 27: /* statementList: %empty  */
#line 163 "./src/syntax.y"
      {}
#line 1821 "./src/syntax.tab.c"
    break;

  case 28: /* ifStatement: IF_KEY '(' simpleExpression ')' bodyStatement  */
#line 167 "./src/syntax.y"
                                                  {printf("%d %d %d %d %d", yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1827 "./src/syntax.tab.c"
    break;

  case 29: /* ifStatement: IF_KEY '(' simpleExpression ')' bodyStatement ELSE_KEY bodyStatement  */
#line 168 "./src/syntax.y"
                                                                           {printf("%d %d %d %d %d %d %d", yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1833 "./src/syntax.tab.c"
    break;

  case 30: /* loopStatement: FOR_KEY '(' expression ';' simpleExpression ';' expression ')' bodyStatement  */
#line 172 "./src/syntax.y"
                                                                                 {printf("%d %d %d %d %d %d %d %d %d", yyvsp[-8], yyvsp[-7], yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1839 "./src/syntax.tab.c"
    break;

  case 31: /* returnStatement: RETURN_KEY expression  */
#line 176 "./src/syntax.y"
                          {printf("%d %d", yyvsp[-1], yyvsp[0]);}
#line 1845 "./src/syntax.tab.c"
    break;

  case 32: /* expression: ID ASSIGN_OP expression  */
#line 180 "./src/syntax.y"
                            {printf("%d %d %d", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1851 "./src/syntax.tab.c"
    break;

  case 33: /* expression: simpleExpression  */
#line 181 "./src/syntax.y"
                       {printf("%d", yyvsp[0]);}
#line 1857 "./src/syntax.tab.c"
    break;

  case 34: /* simpleExpression: logicBinExpression  */
#line 190 "./src/syntax.y"
                       {printf("%d", yyvsp[0]);}
#line 1863 "./src/syntax.tab.c"
    break;

  case 35: /* logicBinExpression: logicBinExpression LOGIC_OP logicUnExpression  */
#line 199 "./src/syntax.y"
                                                  {printf("%d %d %d", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1869 "./src/syntax.tab.c"
    break;

  case 36: /* logicBinExpression: logicUnExpression  */
#line 200 "./src/syntax.y"
                        {printf("%d", yyvsp[0]);}
#line 1875 "./src/syntax.tab.c"
    break;

  case 37: /* logicUnExpression: EXCLA_OP logicUnExpression  */
#line 204 "./src/syntax.y"
                               {printf("%d %d", yyvsp[-1], yyvsp[0]);}
#line 1881 "./src/syntax.tab.c"
    break;

  case 38: /* logicUnExpression: binExpression  */
#line 205 "./src/syntax.y"
                    {printf("%d", yyvsp[0]);}
#line 1887 "./src/syntax.tab.c"
    break;

  case 39: /* binExpression: binExpression BINARY_OP sumExpression  */
#line 213 "./src/syntax.y"
                                          {printf("%d %d %d", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1893 "./src/syntax.tab.c"
    break;

  case 40: /* binExpression: sumExpression  */
#line 214 "./src/syntax.y"
                    {printf("%d", yyvsp[0]);}
#line 1899 "./src/syntax.tab.c"
    break;

  case 41: /* sumExpression: sumExpression sumOP mulExpression  */
#line 218 "./src/syntax.y"
                                      {printf("%d %d %d", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1905 "./src/syntax.tab.c"
    break;

  case 42: /* sumExpression: mulExpression  */
#line 219 "./src/syntax.y"
                    {printf("%d", yyvsp[0]);}
#line 1911 "./src/syntax.tab.c"
    break;

  case 43: /* mulExpression: mulExpression mulOP factor  */
#line 223 "./src/syntax.y"
                               {printf("%d %d %d", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1917 "./src/syntax.tab.c"
    break;

  case 44: /* mulExpression: factor  */
#line 224 "./src/syntax.y"
             {printf("%d", yyvsp[0]);}
#line 1923 "./src/syntax.tab.c"
    break;

  case 45: /* sumOP: PLUS_OP  */
#line 228 "./src/syntax.y"
            {printf("%d", yyvsp[0]);}
#line 1929 "./src/syntax.tab.c"
    break;

  case 46: /* sumOP: MINUS_OP  */
#line 229 "./src/syntax.y"
               {printf("%d", yyvsp[0]);}
#line 1935 "./src/syntax.tab.c"
    break;

  case 47: /* mulOP: MUL_OP  */
#line 233 "./src/syntax.y"
           {printf("%d", yyvsp[0]);}
#line 1941 "./src/syntax.tab.c"
    break;

  case 48: /* mulOP: DIV_OP  */
#line 234 "./src/syntax.y"
             {printf("%d", yyvsp[0]);}
#line 1947 "./src/syntax.tab.c"
    break;

  case 49: /* factor: ID  */
#line 238 "./src/syntax.y"
       {printf("%d", yyvsp[0]);}
#line 1953 "./src/syntax.tab.c"
    break;

  case 50: /* factor: functionCall  */
#line 239 "./src/syntax.y"
                   {printf("%d", yyvsp[0]);}
#line 1959 "./src/syntax.tab.c"
    break;

  case 51: /* factor: '(' simpleExpression ')'  */
#line 240 "./src/syntax.y"
                               {printf("%d %d %d", yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1965 "./src/syntax.tab.c"
    break;

  case 52: /* functionCall: ID '(' parameters ')'  */
#line 244 "./src/syntax.y"
                          {printf("%d %d %d %d", yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1971 "./src/syntax.tab.c"
    break;

  case 53: /* writeOp: write  */
#line 248 "./src/syntax.y"
          {printf("%d", yyvsp[0]);}
#line 1977 "./src/syntax.tab.c"
    break;

  case 54: /* writeOp: writeln  */
#line 249 "./src/syntax.y"
              {printf("%d", yyvsp[0]);}
#line 1983 "./src/syntax.tab.c"
    break;

  case 55: /* write: OUTPUT_KEY '(' STRING ')'  */
#line 253 "./src/syntax.y"
                              {printf("%d %d %d", yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 1989 "./src/syntax.tab.c"
    break;

  case 56: /* write: OUTPUT_KEY '(' simpleExpression ')'  */
#line 254 "./src/syntax.y"
                                          {printf("%d %d %d", yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 1995 "./src/syntax.tab.c"
    break;

  case 57: /* writeln: OUTPUTLN_KEY '(' STRING ')'  */
#line 258 "./src/syntax.y"
                                {printf("%d %d %d", yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 2001 "./src/syntax.tab.c"
    break;

  case 58: /* writeln: OUTPUTLN_KEY '(' simpleExpression ')'  */
#line 259 "./src/syntax.y"
                                            {printf("%d %d %d", yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 2007 "./src/syntax.tab.c"
    break;

  case 59: /* readOp: INPUT_KEY '(' ID ')'  */
#line 263 "./src/syntax.y"
                         {printf("%d %d %d", yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 2013 "./src/syntax.tab.c"
    break;

  case 60: /* listStatement: listAssign  */
#line 267 "./src/syntax.y"
               {printf("%d", yyvsp[0]);}
#line 2019 "./src/syntax.tab.c"
    break;

  case 61: /* listStatement: listHeader  */
#line 268 "./src/syntax.y"
                 {printf("%d", yyvsp[0]);}
#line 2025 "./src/syntax.tab.c"
    break;

  case 62: /* listStatement: listTail  */
#line 269 "./src/syntax.y"
               {printf("%d", yyvsp[0]);}
#line 2031 "./src/syntax.tab.c"
    break;

  case 63: /* listStatement: listTailDestructor  */
#line 270 "./src/syntax.y"
                         {printf("%d", yyvsp[0]);}
#line 2037 "./src/syntax.tab.c"
    break;

  case 64: /* listStatement: listMap  */
#line 271 "./src/syntax.y"
              {printf("%d", yyvsp[0]);}
#line 2043 "./src/syntax.tab.c"
    break;

  case 65: /* listStatement: listFilter  */
#line 272 "./src/syntax.y"
                 {printf("%d", yyvsp[0]);}
#line 2049 "./src/syntax.tab.c"
    break;

  case 66: /* listAssign: ID ASSIGN_OP ID ASSIGN_LISTOP ID  */
#line 276 "./src/syntax.y"
                                     {printf("%d %d %d %d %d", yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2055 "./src/syntax.tab.c"
    break;

  case 67: /* listHeader: HEADER_LISTOP ID  */
#line 280 "./src/syntax.y"
                     {printf("%d %d", yyvsp[-1], yyvsp[0]);}
#line 2061 "./src/syntax.tab.c"
    break;

  case 68: /* listTail: EXCLA_OP ID  */
#line 284 "./src/syntax.y"
                {printf("%d %d", yyvsp[-1], yyvsp[0]);}
#line 2067 "./src/syntax.tab.c"
    break;

  case 69: /* listTailDestructor: TAILDES_LISTOP ID  */
#line 288 "./src/syntax.y"
                      {printf("%d %d", yyvsp[-1], yyvsp[0]);}
#line 2073 "./src/syntax.tab.c"
    break;

  case 70: /* listMap: ID ASSIGN_OP ID MAP_LISTOP ID  */
#line 292 "./src/syntax.y"
                                  {printf("%d %d %d %d %d", yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2079 "./src/syntax.tab.c"
    break;

  case 71: /* listFilter: ID ASSIGN_OP ID FILTER_LISTOP ID  */
#line 296 "./src/syntax.y"
                                     {printf("%d %d %d %d %d", yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2085 "./src/syntax.tab.c"
    break;


#line 2089 "./src/syntax.tab.c"

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


#if !defined yyoverflow
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

  return yyresult;
}

#line 300 "./src/syntax.y"

/* Additional C code */

void yyerror(const char* s){
    printf("Syntax error: %s\n", s);
}

int main(int argc, char **argv){
    FILE *filep;

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
