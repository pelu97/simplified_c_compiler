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
extern int yyparse();

#line 80 "syntax.tab.c"

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
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    ID = 260,                      /* ID  */
    TYPE = 261,                    /* TYPE  */
    STRING = 262,                  /* STRING  */
    NULL = 263,                    /* NULL  */
    ARITHMETIC_OP = 264,           /* ARITHMETIC_OP  */
    LOGIC_OP = 265,                /* LOGIC_OP  */
    BINARY_OP = 266,               /* BINARY_OP  */
    ASSIGN_OP = 267,               /* ASSIGN_OP  */
    EXCLA_OP = 268,                /* EXCLA_OP  */
    FLOW_KEY = 269,                /* FLOW_KEY  */
    INPUT_KEY = 270,               /* INPUT_KEY  */
    OUTPUT_KEY = 271,              /* OUTPUT_KEY  */
    LIST_OP = 272,                 /* LIST_OP  */
    DELIM_PARENT = 273,            /* DELIM_PARENT  */
    DELIM_BRACKET = 274,           /* DELIM_BRACKET  */
    DELIM_CUR_BRACKET = 275,       /* DELIM_CUR_BRACKET  */
    DELIM_COMMA = 276,             /* DELIM_COMMA  */
    DELIM_SEMICOLLON = 277,        /* DELIM_SEMICOLLON  */
    DELIM_SQUOTE = 278,            /* DELIM_SQUOTE  */
    DELIM_DQUOTE = 279,            /* DELIM_DQUOTE  */
    SINGLE_COMMENT = 280,          /* SINGLE_COMMENT  */
    MULTI_COMMENT = 281,           /* MULTI_COMMENT  */
    FORMAT_BLANKSPACE = 282,       /* FORMAT_BLANKSPACE  */
    FORMAT_NEWLINE = 283,          /* FORMAT_NEWLINE  */
    FORMAT_TAB = 284,              /* FORMAT_TAB  */
    IF_KEYWORD = 285,              /* IF_KEYWORD  */
    ELSE_KEYWORD = 286,            /* ELSE_KEYWORD  */
    FOR_KEYWORD = 287,             /* FOR_KEYWORD  */
    RETURN_KEYWORD = 288,          /* RETURN_KEYWORD  */
    WRITE_KEYWORD = 289,           /* WRITE_KEYWORD  */
    WRITELN_KEYWORD = 290,         /* WRITELN_KEYWORD  */
    READ_KEYWORD = 291             /* READ_KEYWORD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


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
  YYSYMBOL_NULL = 8,                       /* NULL  */
  YYSYMBOL_ARITHMETIC_OP = 9,              /* ARITHMETIC_OP  */
  YYSYMBOL_LOGIC_OP = 10,                  /* LOGIC_OP  */
  YYSYMBOL_BINARY_OP = 11,                 /* BINARY_OP  */
  YYSYMBOL_ASSIGN_OP = 12,                 /* ASSIGN_OP  */
  YYSYMBOL_EXCLA_OP = 13,                  /* EXCLA_OP  */
  YYSYMBOL_FLOW_KEY = 14,                  /* FLOW_KEY  */
  YYSYMBOL_INPUT_KEY = 15,                 /* INPUT_KEY  */
  YYSYMBOL_OUTPUT_KEY = 16,                /* OUTPUT_KEY  */
  YYSYMBOL_LIST_OP = 17,                   /* LIST_OP  */
  YYSYMBOL_DELIM_PARENT = 18,              /* DELIM_PARENT  */
  YYSYMBOL_DELIM_BRACKET = 19,             /* DELIM_BRACKET  */
  YYSYMBOL_DELIM_CUR_BRACKET = 20,         /* DELIM_CUR_BRACKET  */
  YYSYMBOL_DELIM_COMMA = 21,               /* DELIM_COMMA  */
  YYSYMBOL_DELIM_SEMICOLLON = 22,          /* DELIM_SEMICOLLON  */
  YYSYMBOL_DELIM_SQUOTE = 23,              /* DELIM_SQUOTE  */
  YYSYMBOL_DELIM_DQUOTE = 24,              /* DELIM_DQUOTE  */
  YYSYMBOL_SINGLE_COMMENT = 25,            /* SINGLE_COMMENT  */
  YYSYMBOL_MULTI_COMMENT = 26,             /* MULTI_COMMENT  */
  YYSYMBOL_FORMAT_BLANKSPACE = 27,         /* FORMAT_BLANKSPACE  */
  YYSYMBOL_FORMAT_NEWLINE = 28,            /* FORMAT_NEWLINE  */
  YYSYMBOL_FORMAT_TAB = 29,                /* FORMAT_TAB  */
  YYSYMBOL_IF_KEYWORD = 30,                /* IF_KEYWORD  */
  YYSYMBOL_ELSE_KEYWORD = 31,              /* ELSE_KEYWORD  */
  YYSYMBOL_FOR_KEYWORD = 32,               /* FOR_KEYWORD  */
  YYSYMBOL_RETURN_KEYWORD = 33,            /* RETURN_KEYWORD  */
  YYSYMBOL_WRITE_KEYWORD = 34,             /* WRITE_KEYWORD  */
  YYSYMBOL_WRITELN_KEYWORD = 35,           /* WRITELN_KEYWORD  */
  YYSYMBOL_READ_KEYWORD = 36,              /* READ_KEYWORD  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '+'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '*'  */
  YYSYMBOL_46_ = 46,                       /* '/'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_48_ = 48,                       /* '?'  */
  YYSYMBOL_49_ = 49,                       /* '!'  */
  YYSYMBOL_50_ = 50,                       /* '%'  */
  YYSYMBOL_51_ = 51,                       /* ">>"  */
  YYSYMBOL_52_ = 52,                       /* "<<"  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_declarationList = 55,           /* declarationList  */
  YYSYMBOL_declaration = 56,               /* declaration  */
  YYSYMBOL_varDeclaration = 57,            /* varDeclaration  */
  YYSYMBOL_varDeclList = 58,               /* varDeclList  */
  YYSYMBOL_varDeclId = 59,                 /* varDeclId  */
  YYSYMBOL_funcDeclaration = 60,           /* funcDeclaration  */
  YYSYMBOL_parameters = 61,                /* parameters  */
  YYSYMBOL_parameterList = 62,             /* parameterList  */
  YYSYMBOL_statement = 63,                 /* statement  */
  YYSYMBOL_bodyStatement = 64,             /* bodyStatement  */
  YYSYMBOL_localDeclaration = 65,          /* localDeclaration  */
  YYSYMBOL_statementList = 66,             /* statementList  */
  YYSYMBOL_ifStatement = 67,               /* ifStatement  */
  YYSYMBOL_loopStatement = 68,             /* loopStatement  */
  YYSYMBOL_expression = 69,                /* expression  */
  YYSYMBOL_simpleExpression = 70,          /* simpleExpression  */
  YYSYMBOL_logicExpression = 71,           /* logicExpression  */
  YYSYMBOL_binExpression = 72,             /* binExpression  */
  YYSYMBOL_sumExpression = 73,             /* sumExpression  */
  YYSYMBOL_mulExpression = 74,             /* mulExpression  */
  YYSYMBOL_sumOP = 75,                     /* sumOP  */
  YYSYMBOL_mulOP = 76,                     /* mulOP  */
  YYSYMBOL_factor = 77,                    /* factor  */
  YYSYMBOL_functionCall = 78,              /* functionCall  */
  YYSYMBOL_listStatement = 79,             /* listStatement  */
  YYSYMBOL_listAssign = 80,                /* listAssign  */
  YYSYMBOL_listHeader = 81,                /* listHeader  */
  YYSYMBOL_listTail = 82,                  /* listTail  */
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
#define YYLAST   551

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
       2,     2,     2,    49,     2,     2,     2,    50,     2,     2,
      37,    38,    45,    43,    39,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    42,
       2,     2,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      35,    36,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    67,    68,    72,    73,    77,    81,    82,
      86,    90,    94,    95,    99,   100,   104,   105,   106,   107,
     111,   115,   116,   120,   121,   125,   126,   130,   138,   139,
     143,   144,   148,   149,   153,   154,   158,   159,   163,   164,
     168,   169,   173,   174,   178,   179,   180,   184,   207,   208,
     209,   210,   211,   212,   216,   220,   224,   228,   232,   236
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
  "TYPE", "STRING", "NULL", "ARITHMETIC_OP", "LOGIC_OP", "BINARY_OP",
  "ASSIGN_OP", "EXCLA_OP", "FLOW_KEY", "INPUT_KEY", "OUTPUT_KEY",
  "LIST_OP", "DELIM_PARENT", "DELIM_BRACKET", "DELIM_CUR_BRACKET",
  "DELIM_COMMA", "DELIM_SEMICOLLON", "DELIM_SQUOTE", "DELIM_DQUOTE",
  "SINGLE_COMMENT", "MULTI_COMMENT", "FORMAT_BLANKSPACE", "FORMAT_NEWLINE",
  "FORMAT_TAB", "IF_KEYWORD", "ELSE_KEYWORD", "FOR_KEYWORD",
  "RETURN_KEYWORD", "WRITE_KEYWORD", "WRITELN_KEYWORD", "READ_KEYWORD",
  "'('", "')'", "','", "'{'", "'}'", "';'", "'+'", "'-'", "'*'", "'/'",
  "':'", "'?'", "'!'", "'%'", "\">>\"", "\"<<\"", "$accept", "program",
  "declarationList", "declaration", "varDeclaration", "varDeclList",
  "varDeclId", "funcDeclaration", "parameters", "parameterList",
  "statement", "bodyStatement", "localDeclaration", "statementList",
  "ifStatement", "loopStatement", "expression", "simpleExpression",
  "logicExpression", "binExpression", "sumExpression", "mulExpression",
  "sumOP", "mulOP", "factor", "functionCall", "listStatement",
  "listAssign", "listHeader", "listTail", "listTailDestructor", "listMap",
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
     285,   286,   287,   288,   289,   290,   291,    40,    41,    44,
     123,   125,    59,    43,    45,    42,    47,    58,    63,    33,
      37,   292,   293
};
#endif

#define YYPACT_NINF (-85)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,     5,    12,    30,    69,   173,   227,    11,   487,   494,
     -85,   395,    20,   498,   501,    27,    -9,   -11,   133,   103,
      40,    37,    35,    77,     2,    45,    75,   112,   502,   509,
     512,   513,   514,   517,   521,   522,   524,   525,   526,   116,
     120,   129,   171,    51,   529,   533,   -85,   228,   499,   148,
     129,   129,    99,   160,   180,   438,   167,   177,   186,   119,
     108,    23,   155,    71,   168,   184,   209,   214,    20,   218,
     247,   129,   208,   117,   162,   238,   257,   286,   440,   257,
     171,   383,   534,   243,   536,   -85,   -85,   255,   196,   296,
     480,   101,   206,   215,   253,   387,   225,   265,   442,   537,
     275,   265,   538,   383,   129,   436,   446,   330,   235,   244,
     254,    20,   383,    13,    15,    19,     2,   264,   129,   319,
     323,   332,   158,   117,   137,   312,   447,   321,   453,   459,
     459,   292,   455,   232,    51,    20,   322,   117,   341,   442,
     272,   282,   129,   339,   348,   361,   370,   293,   301,   310,
     307,   371,   379,   388,   372,    20,   390,   453,   453,   485,
     392,   373,   398,   408,   417,   429
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
       0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   -85,   396,   -41,   357,    -7,   -85,   -15,   -85,
     -85,   175,   305,   -37,   -85,   -85,   -76,   -36,    24,    43,
      -2,   -29,   -84,    -6,   -42,   -39,   -85,   -85,   -85,   -85,
     -85,   -85,   -85
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     5,     8,     9,     6,    16,    17,
      28,    29,    43,    83,    30,    31,    60,    61,    53,    54,
      55,    56,    76,    79,    57,    58,    32,    33,    34,    35,
      36,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     109,    14,    63,   110,    94,    52,    64,   123,   -22,     1,
       7,   -10,    10,   108,    69,    70,   -10,   -10,   -10,   -10,
     113,    -7,   100,   129,    -9,    -9,    15,   -12,    20,    19,
      -2,   120,    18,   112,   121,    89,     1,    93,   109,   109,
     107,   110,   110,   -22,   119,    95,    39,    92,    12,    40,
      44,   108,   108,    87,   -10,   115,    -7,    62,   -13,   157,
      -9,   109,   125,   154,   110,   -29,   105,   126,   127,    -4,
     109,    91,    41,   110,   108,    -4,   132,   -21,   107,   107,
      45,   120,   136,   108,   121,   106,   145,   109,   148,   146,
     110,   110,   -24,    63,   138,   153,   131,   150,   121,   144,
     147,   107,   130,   125,   105,   105,   156,   133,    21,    71,
     107,   -34,   -21,   137,    42,   145,   164,    46,   146,   146,
     151,    47,   117,   106,   106,    48,   143,   105,   163,   -44,
     -44,    80,   137,    22,    49,    23,   105,    72,   158,   -34,
     161,   130,    50,    24,    74,    75,   106,   -44,   -44,   139,
      81,    25,    26,    27,   118,   106,   111,   158,   -44,   -44,
     113,   -44,   -44,   -44,   -44,   -44,    51,   -40,   -44,   -44,
     -31,   -15,   -15,    -5,    68,   -44,    59,   -37,   -37,    -5,
     -44,   -44,   -44,   -44,   103,    68,   -44,   -39,   -39,    84,
     -30,   -44,   -44,   -44,   -44,   111,   -45,   -45,   -31,   -40,
     -44,   -44,   -44,   -44,   -44,   -37,   -46,   -46,   104,    82,
     -37,   -37,    77,    78,    85,   -39,   -36,   -36,   -30,    86,
     -39,   -39,   -39,   -39,   -45,   -38,   -38,    -6,    71,   -45,
     -45,   -45,   -45,    -6,   -46,   -47,   -47,    -8,    -8,   -46,
     -46,   -46,   -46,   -41,   -36,   -37,   -37,    90,   116,   -36,
     -36,    77,    78,   -38,   -39,   -39,   -33,    71,   -38,   -38,
     -38,   -38,    49,   -47,   -45,   -45,   -14,   -14,   -47,   -47,
     -47,   -47,    99,    -8,   -44,   -41,   102,   -37,   -37,   -37,
      77,    78,   -46,   -46,   -23,    88,   -39,   -39,   -39,   -39,
     -39,   -42,   -44,    96,    51,   -28,   -45,   -45,   -45,   -45,
     -45,   135,   -44,   -36,   -36,    24,    71,   -44,   -44,   -44,
     -44,   -38,   -38,   101,   -46,   -46,   -46,   -46,   -46,   155,
     -47,   -47,    71,   -42,   -44,   -44,   -44,   -44,   -44,   -37,
     149,    71,    71,   -39,   -32,   -36,   -36,   -36,    77,    78,
     -35,   128,   -45,   -38,   -38,   -38,   -38,   -38,   159,   -34,
     -29,   -36,   -47,   -47,   -47,   -47,   -47,   -37,   -37,   140,
     152,   -39,   -37,   -37,    77,    78,   -39,   -39,   -39,   -39,
     -45,   -39,   -35,    74,    75,   -45,   -45,   -45,   -45,   -36,
     -45,   -34,    74,    75,   -36,   -36,    77,    78,   122,   -46,
     -37,   -37,   -37,    77,    78,    -3,   103,   112,   -38,    11,
      71,    -3,   -47,   -39,   -39,   -39,   -39,   -39,   -46,   160,
     -28,   165,   -45,   -45,   -45,   -45,   -45,   -46,   -36,   114,
     104,   134,   -46,   -46,   -46,   -46,   -38,   -38,   162,    98,
     -47,   -38,   -38,   -38,   -38,   -47,   -47,   -47,   -47,   -47,
     -46,   -46,   -46,   -46,   -46,   -43,   -31,   124,   -35,    73,
     -36,   -36,   -36,    77,    78,    50,   -30,   112,   141,   -38,
     -38,   -38,   -38,   -38,   122,   112,     0,     0,     0,     0,
       0,   -47,   -47,   -47,   -47,   -47,   -35,   -43,   -31,    51,
     -25,    74,    75,     0,     0,   -20,   -25,    -7,   -30,   -33,
     142,   -20,    13,    -7,    -9,     0,   104,   -32,   -10,    -9,
      -9,    -8,   -11,   -10,   -10,     0,    -8,    -8,   -11,   -16,
       0,    97,   -17,   -18,   -19,   -16,   -20,   -48,   -17,   -18,
     -19,   -49,   -50,   -48,   -51,   -52,   -53,   -49,   -50,   -55,
     -51,   -52,   -53,   -56,   -20,   -55,   -54,   -26,   -27,   -56,
     -20,     0,   -54,   -26,   -27,     0,    65,     0,     0,     0,
      66,    67
};

static const yytype_int16 yycheck[] =
{
      42,     8,    43,    42,    80,    41,    43,    91,     6,     6,
       5,     0,     0,    42,    50,    51,     5,     6,     5,     6,
       5,     6,    98,   107,     5,     6,     6,    38,    39,    38,
       0,    73,     5,    10,    73,    71,     6,    79,    80,    81,
      42,    80,    81,    41,    73,    81,     6,    76,    37,    12,
       5,    80,    81,    68,    41,    62,    41,     6,    38,   143,
      41,   103,    98,   139,   103,    42,    42,   103,   104,     0,
     112,    73,    37,   112,   103,     6,   112,     6,    80,    81,
       5,   123,   118,   112,   123,    42,   128,   129,   130,   128,
     129,   130,    41,   134,   123,   137,   111,   134,   137,   128,
     129,   103,   108,   139,    80,    81,   142,   114,     5,    10,
     112,    10,    41,   119,    37,   157,   158,     5,   157,   158,
     135,     5,     5,    80,    81,     5,   128,   103,   157,    10,
      11,    12,   138,    30,     5,    32,   112,    38,   144,    38,
     155,   147,    13,    40,    43,    44,   103,    10,    11,    12,
      42,    48,    49,    50,    37,   112,    37,   163,    10,    11,
       5,    42,    43,    44,    45,    46,    37,     5,    10,    11,
      10,    38,    39,     0,    37,    38,     5,    10,    11,     6,
      43,    44,    45,    46,    13,    37,    38,    10,    11,     5,
      10,    43,    44,    45,    46,    37,    10,    11,    38,    37,
      42,    43,    44,    45,    46,    38,    10,    11,    37,    41,
      43,    44,    45,    46,     5,    38,    10,    11,    38,     5,
      43,    44,    45,    46,    38,    10,    11,     0,    10,    43,
      44,    45,    46,     6,    38,    10,    11,     5,     6,    43,
      44,    45,    46,     5,    38,    10,    11,    72,    40,    43,
      44,    45,    46,    38,    10,    11,    38,    10,    43,    44,
      45,    46,     5,    38,    10,    11,    38,    39,    43,    44,
      45,    46,    97,    41,    10,    37,   101,    42,    43,    44,
      45,    46,    10,    11,    41,    38,    42,    43,    44,    45,
      46,     5,    10,    38,    37,    42,    42,    43,    44,    45,
      46,    37,    38,    10,    11,    40,    10,    43,    44,    45,
      46,    10,    11,    38,    42,    43,    44,    45,    46,    37,
      10,    11,    10,    37,    42,    43,    44,    45,    46,    10,
      38,    10,    10,    10,    38,    42,    43,    44,    45,    46,
      10,    11,    10,    42,    43,    44,    45,    46,    41,    10,
      38,    10,    42,    43,    44,    45,    46,    38,    10,    38,
      38,    38,    43,    44,    45,    46,    43,    44,    45,    46,
      38,    10,    42,    43,    44,    43,    44,    45,    46,    38,
      10,    42,    43,    44,    43,    44,    45,    46,     5,    10,
      42,    43,    44,    45,    46,     0,    13,    10,    10,     3,
      10,     6,    10,    42,    43,    44,    45,    46,    10,    38,
      38,    38,    42,    43,    44,    45,    46,    38,    10,    62,
      37,   116,    43,    44,    45,    46,    38,    10,    38,    42,
      38,    43,    44,    45,    46,    43,    44,    45,    46,    10,
      42,    43,    44,    45,    46,     5,    10,     5,    10,    11,
      42,    43,    44,    45,    46,    13,    10,    10,     5,    42,
      43,    44,    45,    46,     5,    10,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    38,    37,    42,    37,
       0,    43,    44,    -1,    -1,     0,     6,     0,    42,    42,
      37,     6,     5,     6,     0,    -1,    37,    42,     0,     5,
       6,     0,     0,     5,     6,    -1,     5,     6,     6,     0,
      -1,    31,     0,     0,     0,     6,    31,     0,     6,     6,
       6,     0,     0,     6,     0,     0,     0,     6,     6,     0,
       6,     6,     6,     0,     0,     6,     0,     0,     0,     6,
       6,    -1,     6,     6,     6,    -1,    47,    -1,    -1,    -1,
      51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    54,    55,    56,    57,    60,     5,    58,    59,
       0,    56,    37,     5,    59,     6,    61,    62,     5,    38,
      39,     5,    30,    32,    40,    48,    49,    50,    63,    64,
      67,    68,    79,    80,    81,    82,    83,    84,    85,     6,
      12,    37,    37,    65,     5,     5,     5,     5,     5,     5,
      13,    37,    70,    71,    72,    73,    74,    77,    78,     5,
      69,    70,     6,    57,    66,    47,    51,    52,    37,    70,
      70,    10,    38,    11,    43,    44,    75,    45,    46,    76,
      12,    42,    41,    66,     5,     5,     5,    61,    38,    70,
      64,    73,    74,    77,    69,    70,    38,    31,    42,    64,
      69,    38,    64,    13,    37,    71,    72,    73,    74,    77,
      78,    37,    10,     5,    58,    59,    40,     5,    37,    74,
      77,    78,     5,    75,     5,    70,    70,    70,    11,    75,
      76,    61,    70,    59,    65,    37,    70,    76,    74,    12,
      38,     5,    37,    73,    74,    77,    78,    74,    77,    38,
      66,    61,    38,    77,    69,    37,    70,    75,    76,    41,
      38,    61,    38,    74,    77,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    58,    58,
      59,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      64,    65,    65,    66,    66,    67,    67,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    77,    78,    79,    79,
      79,    79,    79,    79,    80,    81,    82,    83,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     2,     1,
       1,     6,     1,     0,     4,     2,     1,     1,     1,     1,
       4,     2,     0,     2,     0,     5,     7,     9,     3,     1,
       1,     1,     3,     2,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     1,     1,
       1,     1,     1,     1,     5,     2,     2,     2,     5,     5
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
#line 63 "./src/syntax.y"
                    { printf('%d', yyvsp[0]); }
#line 1417 "syntax.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 67 "./src/syntax.y"
                                {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1423 "syntax.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 68 "./src/syntax.y"
                  {printf('%d', yyvsp[0]);}
#line 1429 "syntax.tab.c"
    break;

  case 5: /* declaration: varDeclaration  */
#line 72 "./src/syntax.y"
                   {printf('%d', yyvsp[0]);}
#line 1435 "syntax.tab.c"
    break;

  case 6: /* declaration: funcDeclaration  */
#line 73 "./src/syntax.y"
                      {printf('%d', yyvsp[0]);}
#line 1441 "syntax.tab.c"
    break;

  case 7: /* varDeclaration: TYPE varDeclList  */
#line 77 "./src/syntax.y"
                     {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1447 "syntax.tab.c"
    break;

  case 8: /* varDeclList: varDeclList varDeclId  */
#line 81 "./src/syntax.y"
                          {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1453 "syntax.tab.c"
    break;

  case 9: /* varDeclList: varDeclId  */
#line 82 "./src/syntax.y"
                {printf('%d', yyvsp[0]);}
#line 1459 "syntax.tab.c"
    break;

  case 10: /* varDeclId: ID  */
#line 86 "./src/syntax.y"
       {printf('%d', yyvsp[0]);}
#line 1465 "syntax.tab.c"
    break;

  case 11: /* funcDeclaration: TYPE ID '(' parameters ')' statement  */
#line 90 "./src/syntax.y"
                                         {printf('%d %d %d %d %d %d', yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1471 "syntax.tab.c"
    break;

  case 12: /* parameters: parameterList  */
#line 94 "./src/syntax.y"
                  {printf('%d', yyvsp[0]);}
#line 1477 "syntax.tab.c"
    break;

  case 13: /* parameters: %empty  */
#line 95 "./src/syntax.y"
      {}
#line 1483 "syntax.tab.c"
    break;

  case 14: /* parameterList: parameterList ',' TYPE ID  */
#line 99 "./src/syntax.y"
                              {printf('%d %d %d', yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 1489 "syntax.tab.c"
    break;

  case 15: /* parameterList: TYPE ID  */
#line 100 "./src/syntax.y"
              {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1495 "syntax.tab.c"
    break;

  case 16: /* statement: bodyStatement  */
#line 104 "./src/syntax.y"
                  {printf('%d', yyvsp[0]);}
#line 1501 "syntax.tab.c"
    break;

  case 17: /* statement: ifStatement  */
#line 105 "./src/syntax.y"
                  {printf('%d', yyvsp[0]);}
#line 1507 "syntax.tab.c"
    break;

  case 18: /* statement: loopStatement  */
#line 106 "./src/syntax.y"
                    {printf('%d', yyvsp[0]);}
#line 1513 "syntax.tab.c"
    break;

  case 19: /* statement: listStatement  */
#line 107 "./src/syntax.y"
                    {printf('%d', yyvsp[0]);}
#line 1519 "syntax.tab.c"
    break;

  case 20: /* bodyStatement: '{' localDeclaration statementList '}'  */
#line 111 "./src/syntax.y"
                                           {printf('%d %d %d %d', yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1525 "syntax.tab.c"
    break;

  case 21: /* localDeclaration: localDeclaration varDeclaration  */
#line 115 "./src/syntax.y"
                                    {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1531 "syntax.tab.c"
    break;

  case 22: /* localDeclaration: %empty  */
#line 116 "./src/syntax.y"
      {}
#line 1537 "syntax.tab.c"
    break;

  case 23: /* statementList: statementList statementList  */
#line 120 "./src/syntax.y"
                                {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1543 "syntax.tab.c"
    break;

  case 24: /* statementList: %empty  */
#line 121 "./src/syntax.y"
      {}
#line 1549 "syntax.tab.c"
    break;

  case 25: /* ifStatement: IF_KEYWORD '(' simpleExpression ')' bodyStatement  */
#line 125 "./src/syntax.y"
                                                      {printf('%d %d %d %d %d', yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1555 "syntax.tab.c"
    break;

  case 26: /* ifStatement: IF_KEYWORD '(' simpleExpression ')' bodyStatement ELSE_KEYWORD bodyStatement  */
#line 126 "./src/syntax.y"
                                                                                   {printf('%d %d %d %d %d %d %d', yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1561 "syntax.tab.c"
    break;

  case 27: /* loopStatement: FOR_KEYWORD '(' expression ';' simpleExpression ';' expression ')' bodyStatement  */
#line 130 "./src/syntax.y"
                                                                                     {printf('%d %d %d %d %d %d %d %d %d', yyvsp[-8], yyvsp[-7], yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1567 "syntax.tab.c"
    break;

  case 28: /* expression: ID ASSIGN_OP expression  */
#line 138 "./src/syntax.y"
                            {printf('%d %d %d', yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1573 "syntax.tab.c"
    break;

  case 29: /* expression: simpleExpression  */
#line 139 "./src/syntax.y"
                       {printf('%d', yyvsp[0]);}
#line 1579 "syntax.tab.c"
    break;

  case 30: /* simpleExpression: binExpression  */
#line 143 "./src/syntax.y"
                  {printf('%d', yyvsp[0]);}
#line 1585 "syntax.tab.c"
    break;

  case 31: /* simpleExpression: logicExpression  */
#line 144 "./src/syntax.y"
                      {printf('%d', yyvsp[0]);}
#line 1591 "syntax.tab.c"
    break;

  case 32: /* logicExpression: simpleExpression LOGIC_OP simpleExpression  */
#line 148 "./src/syntax.y"
                                               {printf('%d %d %d', yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1597 "syntax.tab.c"
    break;

  case 33: /* logicExpression: EXCLA_OP simpleExpression  */
#line 149 "./src/syntax.y"
                                {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1603 "syntax.tab.c"
    break;

  case 34: /* binExpression: sumExpression BINARY_OP sumExpression  */
#line 153 "./src/syntax.y"
                                          {printf('%d %d %d', yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1609 "syntax.tab.c"
    break;

  case 35: /* binExpression: sumExpression  */
#line 154 "./src/syntax.y"
                    {printf('%d', yyvsp[0]);}
#line 1615 "syntax.tab.c"
    break;

  case 36: /* sumExpression: sumExpression sumOP mulExpression  */
#line 158 "./src/syntax.y"
                                      {printf('%d %d %d', yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1621 "syntax.tab.c"
    break;

  case 37: /* sumExpression: mulExpression  */
#line 159 "./src/syntax.y"
                    {printf('%d', yyvsp[0]);}
#line 1627 "syntax.tab.c"
    break;

  case 38: /* mulExpression: mulExpression mulOP factor  */
#line 163 "./src/syntax.y"
                               {printf('%d %d %d', yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1633 "syntax.tab.c"
    break;

  case 39: /* mulExpression: factor  */
#line 164 "./src/syntax.y"
             {printf('%d', yyvsp[0]);}
#line 1639 "syntax.tab.c"
    break;

  case 40: /* sumOP: '+'  */
#line 168 "./src/syntax.y"
        {printf('%d', yyvsp[0]);}
#line 1645 "syntax.tab.c"
    break;

  case 41: /* sumOP: '-'  */
#line 169 "./src/syntax.y"
          {printf('%d', yyvsp[0]);}
#line 1651 "syntax.tab.c"
    break;

  case 42: /* mulOP: '*'  */
#line 173 "./src/syntax.y"
        {printf('%d', yyvsp[0]);}
#line 1657 "syntax.tab.c"
    break;

  case 43: /* mulOP: '/'  */
#line 174 "./src/syntax.y"
          {printf('%d', yyvsp[0]);}
#line 1663 "syntax.tab.c"
    break;

  case 44: /* factor: ID  */
#line 178 "./src/syntax.y"
       {printf('%d', yyvsp[0]);}
#line 1669 "syntax.tab.c"
    break;

  case 45: /* factor: functionCall  */
#line 179 "./src/syntax.y"
                   {printf('%d', yyvsp[0]);}
#line 1675 "syntax.tab.c"
    break;

  case 46: /* factor: '(' simpleExpression ')'  */
#line 180 "./src/syntax.y"
                               {printf('%d %d %d', yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1681 "syntax.tab.c"
    break;

  case 47: /* functionCall: ID '(' parameters ')'  */
#line 184 "./src/syntax.y"
                          {printf('%d %d %d %d', yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1687 "syntax.tab.c"
    break;

  case 48: /* listStatement: listAssign  */
#line 207 "./src/syntax.y"
               {printf('%d', yyvsp[0]);}
#line 1693 "syntax.tab.c"
    break;

  case 49: /* listStatement: listHeader  */
#line 208 "./src/syntax.y"
                 {printf('%d', yyvsp[0]);}
#line 1699 "syntax.tab.c"
    break;

  case 50: /* listStatement: listTail  */
#line 209 "./src/syntax.y"
               {printf('%d', yyvsp[0]);}
#line 1705 "syntax.tab.c"
    break;

  case 51: /* listStatement: listTailDestructor  */
#line 210 "./src/syntax.y"
                         {printf('%d', yyvsp[0]);}
#line 1711 "syntax.tab.c"
    break;

  case 52: /* listStatement: listMap  */
#line 211 "./src/syntax.y"
              {printf('%d', yyvsp[0]);}
#line 1717 "syntax.tab.c"
    break;

  case 53: /* listStatement: listFilter  */
#line 212 "./src/syntax.y"
                 {printf('%d', yyvsp[0]);}
#line 1723 "syntax.tab.c"
    break;

  case 54: /* listAssign: ID ASSIGN_OP ID ':' ID  */
#line 216 "./src/syntax.y"
                           {printf('%d %d %d %d %d', yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1729 "syntax.tab.c"
    break;

  case 55: /* listHeader: '?' ID  */
#line 220 "./src/syntax.y"
           {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1735 "syntax.tab.c"
    break;

  case 56: /* listTail: '!' ID  */
#line 224 "./src/syntax.y"
           {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1741 "syntax.tab.c"
    break;

  case 57: /* listTailDestructor: '%' ID  */
#line 228 "./src/syntax.y"
           {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1747 "syntax.tab.c"
    break;

  case 58: /* listMap: ID ASSIGN_OP ID ">>" ID  */
#line 232 "./src/syntax.y"
                            {printf('%d %d %d %d %d', yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1753 "syntax.tab.c"
    break;

  case 59: /* listFilter: ID ASSIGN_OP ID "<<" ID  */
#line 236 "./src/syntax.y"
                            {printf('%d %d %d %d %d', yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1759 "syntax.tab.c"
    break;


#line 1763 "syntax.tab.c"

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

#line 240 "./src/syntax.y"

/* Additional C code */

int main(int argc, char **argv){
    FILE *filep;

    if(argc >= 2) {
        filep = fopen(argv[1], "r");

        if(filep != NULL){
            /* print_start(); */

            yyin = filep;
            yylex();
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
