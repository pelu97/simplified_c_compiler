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

#line 80 "y.tab.c"

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
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    ID = 260,                      /* ID  */
    TYPE = 261,                    /* TYPE  */
    STRING = 262,                  /* STRING  */
    NULL = 263,                    /* NULL  */
    PLUS_OP = 264,                 /* PLUS_OP  */
    MINUS_OP = 265,                /* MINUS_OP  */
    DIV_OP = 266,                  /* DIV_OP  */
    MUL_OP = 267,                  /* MUL_OP  */
    LOGIC_OP = 268,                /* LOGIC_OP  */
    BINARY_OP = 269,               /* BINARY_OP  */
    ASSIGN_OP = 270,               /* ASSIGN_OP  */
    EXCLA_OP = 271,                /* EXCLA_OP  */
    IF_KEY = 272,                  /* IF_KEY  */
    ELSE_KEY = 273,                /* ELSE_KEY  */
    FOR_KEY = 274,                 /* FOR_KEY  */
    RETURN_KEY = 275,              /* RETURN_KEY  */
    INPUT_KEY = 276,               /* INPUT_KEY  */
    OUTPUT_KEY = 277,              /* OUTPUT_KEY  */
    OUTPUTLN_KEY = 278,            /* OUTPUTLN_KEY  */
    LIST_OP = 279,                 /* LIST_OP  */
    DELIM_PARENT = 280,            /* DELIM_PARENT  */
    DELIM_BRACKET = 281,           /* DELIM_BRACKET  */
    DELIM_CUR_BRACKET = 282,       /* DELIM_CUR_BRACKET  */
    DELIM_COMMA = 283,             /* DELIM_COMMA  */
    DELIM_SEMICOLLON = 284,        /* DELIM_SEMICOLLON  */
    DELIM_SQUOTE = 285,            /* DELIM_SQUOTE  */
    DELIM_DQUOTE = 286,            /* DELIM_DQUOTE  */
    SINGLE_COMMENT = 287,          /* SINGLE_COMMENT  */
    MULTI_COMMENT = 288,           /* MULTI_COMMENT  */
    FORMAT_BLANKSPACE = 289,       /* FORMAT_BLANKSPACE  */
    FORMAT_NEWLINE = 290,          /* FORMAT_NEWLINE  */
    FORMAT_TAB = 291,              /* FORMAT_TAB  */
    IF_KEYWORD = 292,              /* IF_KEYWORD  */
    ELSE_KEYWORD = 293,            /* ELSE_KEYWORD  */
    FOR_KEYWORD = 294,             /* FOR_KEYWORD  */
    RETURN_KEYWORD = 295,          /* RETURN_KEYWORD  */
    WRITE_KEYWORD = 296,           /* WRITE_KEYWORD  */
    WRITELN_KEYWORD = 297,         /* WRITELN_KEYWORD  */
    READ_KEYWORD = 298             /* READ_KEYWORD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define FLOAT 259
#define ID 260
#define TYPE 261
#define STRING 262
#define NULL 263
#define PLUS_OP 264
#define MINUS_OP 265
#define DIV_OP 266
#define MUL_OP 267
#define LOGIC_OP 268
#define BINARY_OP 269
#define ASSIGN_OP 270
#define EXCLA_OP 271
#define IF_KEY 272
#define ELSE_KEY 273
#define FOR_KEY 274
#define RETURN_KEY 275
#define INPUT_KEY 276
#define OUTPUT_KEY 277
#define OUTPUTLN_KEY 278
#define LIST_OP 279
#define DELIM_PARENT 280
#define DELIM_BRACKET 281
#define DELIM_CUR_BRACKET 282
#define DELIM_COMMA 283
#define DELIM_SEMICOLLON 284
#define DELIM_SQUOTE 285
#define DELIM_DQUOTE 286
#define SINGLE_COMMENT 287
#define MULTI_COMMENT 288
#define FORMAT_BLANKSPACE 289
#define FORMAT_NEWLINE 290
#define FORMAT_TAB 291
#define IF_KEYWORD 292
#define ELSE_KEYWORD 293
#define FOR_KEYWORD 294
#define RETURN_KEYWORD 295
#define WRITE_KEYWORD 296
#define WRITELN_KEYWORD 297
#define READ_KEYWORD 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_TYPE = 6,                       /* TYPE  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_NULL = 8,                       /* NULL  */
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
  YYSYMBOL_LIST_OP = 24,                   /* LIST_OP  */
  YYSYMBOL_DELIM_PARENT = 25,              /* DELIM_PARENT  */
  YYSYMBOL_DELIM_BRACKET = 26,             /* DELIM_BRACKET  */
  YYSYMBOL_DELIM_CUR_BRACKET = 27,         /* DELIM_CUR_BRACKET  */
  YYSYMBOL_DELIM_COMMA = 28,               /* DELIM_COMMA  */
  YYSYMBOL_DELIM_SEMICOLLON = 29,          /* DELIM_SEMICOLLON  */
  YYSYMBOL_DELIM_SQUOTE = 30,              /* DELIM_SQUOTE  */
  YYSYMBOL_DELIM_DQUOTE = 31,              /* DELIM_DQUOTE  */
  YYSYMBOL_SINGLE_COMMENT = 32,            /* SINGLE_COMMENT  */
  YYSYMBOL_MULTI_COMMENT = 33,             /* MULTI_COMMENT  */
  YYSYMBOL_FORMAT_BLANKSPACE = 34,         /* FORMAT_BLANKSPACE  */
  YYSYMBOL_FORMAT_NEWLINE = 35,            /* FORMAT_NEWLINE  */
  YYSYMBOL_FORMAT_TAB = 36,                /* FORMAT_TAB  */
  YYSYMBOL_IF_KEYWORD = 37,                /* IF_KEYWORD  */
  YYSYMBOL_ELSE_KEYWORD = 38,              /* ELSE_KEYWORD  */
  YYSYMBOL_FOR_KEYWORD = 39,               /* FOR_KEYWORD  */
  YYSYMBOL_RETURN_KEYWORD = 40,            /* RETURN_KEYWORD  */
  YYSYMBOL_WRITE_KEYWORD = 41,             /* WRITE_KEYWORD  */
  YYSYMBOL_WRITELN_KEYWORD = 42,           /* WRITELN_KEYWORD  */
  YYSYMBOL_READ_KEYWORD = 43,              /* READ_KEYWORD  */
  YYSYMBOL_44_ = 44,                       /* '('  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* '{'  */
  YYSYMBOL_48_ = 48,                       /* '}'  */
  YYSYMBOL_49_ = 49,                       /* ';'  */
  YYSYMBOL_50_ = 50,                       /* ':'  */
  YYSYMBOL_51_ = 51,                       /* '?'  */
  YYSYMBOL_52_ = 52,                       /* '!'  */
  YYSYMBOL_53_ = 53,                       /* '%'  */
  YYSYMBOL_54_ = 54,                       /* ">>"  */
  YYSYMBOL_55_ = 55,                       /* "<<"  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_program = 57,                   /* program  */
  YYSYMBOL_declarationList = 58,           /* declarationList  */
  YYSYMBOL_declaration = 59,               /* declaration  */
  YYSYMBOL_varDeclaration = 60,            /* varDeclaration  */
  YYSYMBOL_varDeclList = 61,               /* varDeclList  */
  YYSYMBOL_varDeclId = 62,                 /* varDeclId  */
  YYSYMBOL_funcDeclaration = 63,           /* funcDeclaration  */
  YYSYMBOL_parameters = 64,                /* parameters  */
  YYSYMBOL_parameterList = 65,             /* parameterList  */
  YYSYMBOL_statement = 66,                 /* statement  */
  YYSYMBOL_bodyStatement = 67,             /* bodyStatement  */
  YYSYMBOL_localDeclaration = 68,          /* localDeclaration  */
  YYSYMBOL_statementList = 69,             /* statementList  */
  YYSYMBOL_ifStatement = 70,               /* ifStatement  */
  YYSYMBOL_loopStatement = 71,             /* loopStatement  */
  YYSYMBOL_returnStatement = 72,           /* returnStatement  */
  YYSYMBOL_expression = 73,                /* expression  */
  YYSYMBOL_simpleExpression = 74,          /* simpleExpression  */
  YYSYMBOL_logicExpression = 75,           /* logicExpression  */
  YYSYMBOL_binExpression = 76,             /* binExpression  */
  YYSYMBOL_sumExpression = 77,             /* sumExpression  */
  YYSYMBOL_mulExpression = 78,             /* mulExpression  */
  YYSYMBOL_sumOP = 79,                     /* sumOP  */
  YYSYMBOL_mulOP = 80,                     /* mulOP  */
  YYSYMBOL_factor = 81,                    /* factor  */
  YYSYMBOL_functionCall = 82,              /* functionCall  */
  YYSYMBOL_listStatement = 83,             /* listStatement  */
  YYSYMBOL_listAssign = 84,                /* listAssign  */
  YYSYMBOL_listHeader = 85,                /* listHeader  */
  YYSYMBOL_listTail = 86,                  /* listTail  */
  YYSYMBOL_listTailDestructor = 87,        /* listTailDestructor  */
  YYSYMBOL_listMap = 88,                   /* listMap  */
  YYSYMBOL_listFilter = 89                 /* listFilter  */
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
#define YYLAST   1842

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  302

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
       2,     2,     2,    52,     2,     2,     2,    53,     2,     2,
      44,    45,     2,     2,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    49,
       2,     2,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    99,    99,   103,   104,   108,   109,   113,   117,   118,
     122,   126,   130,   131,   135,   136,   140,   141,   142,   143,
     144,   148,   152,   153,   157,   158,   162,   163,   167,   171,
     175,   176,   180,   181,   185,   186,   190,   191,   195,   196,
     200,   201,   205,   206,   210,   211,   215,   216,   217,   221,
     244,   245,   246,   247,   248,   249,   253,   257,   261,   265,
     269,   273
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
  "TYPE", "STRING", "NULL", "PLUS_OP", "MINUS_OP", "DIV_OP", "MUL_OP",
  "LOGIC_OP", "BINARY_OP", "ASSIGN_OP", "EXCLA_OP", "IF_KEY", "ELSE_KEY",
  "FOR_KEY", "RETURN_KEY", "INPUT_KEY", "OUTPUT_KEY", "OUTPUTLN_KEY",
  "LIST_OP", "DELIM_PARENT", "DELIM_BRACKET", "DELIM_CUR_BRACKET",
  "DELIM_COMMA", "DELIM_SEMICOLLON", "DELIM_SQUOTE", "DELIM_DQUOTE",
  "SINGLE_COMMENT", "MULTI_COMMENT", "FORMAT_BLANKSPACE", "FORMAT_NEWLINE",
  "FORMAT_TAB", "IF_KEYWORD", "ELSE_KEYWORD", "FOR_KEYWORD",
  "RETURN_KEYWORD", "WRITE_KEYWORD", "WRITELN_KEYWORD", "READ_KEYWORD",
  "'('", "')'", "','", "'{'", "'}'", "';'", "':'", "'?'", "'!'", "'%'",
  "\">>\"", "\"<<\"", "$accept", "program", "declarationList",
  "declaration", "varDeclaration", "varDeclList", "varDeclId",
  "funcDeclaration", "parameters", "parameterList", "statement",
  "bodyStatement", "localDeclaration", "statementList", "ifStatement",
  "loopStatement", "returnStatement", "expression", "simpleExpression",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    40,    41,    44,   123,   125,    59,
      58,    63,    33,    37,   299,   300
};
#endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,     3,    28,     7,   138,   370,   480,    25,   426,   459,
    -129,   544,    -1,   495,   548,    16,    14,   -28,   303,  1454,
      34,    48,    37,    39,    83,   266,    84,    86,    91,   587,
     600,   603,   608,   611,   615,   649,   678,   691,   703,   720,
     733,   124,   140,   168,   189,    43,   212,   168,   754,   434,
     463,   475,   559,  1672,  1691,  1706,   398,   755,   762,   767,
     376,   651,  1552,    -7,    98,    83,    -1,   516,    21,   212,
       4,    17,    46,   105,   143,   152,   105,   183,   419,   472,
     141,   193,   197,   217,   176,   225,   774,   195,  1721,   539,
     683,  1736,  1751,   196,   791,   804,   820,  -129,   357,   113,
    1766,   206,   229,   825,   239,   206,   832,   168,   168,    87,
     101,   517,   617,  1568,  1574,   312,   225,   168,   120,   127,
     233,     1,   323,   497,  1478,  1442,   259,   247,   267,   234,
     266,   315,   324,   334,  1137,  1157,  1174,  1181,  1194,  1218,
    1231,  1238,  1255,  1275,  1292,    -1,   168,    92,   168,  1781,
    1789,  1797,   968,   984,   993,   266,    64,    46,   225,  1531,
     186,   223,   252,   159,   177,   177,   189,    -1,   241,   295,
     204,   213,   213,   364,   168,   189,   523,   271,   168,  1299,
    1009,  1034,  1050,   931,   585,   634,   647,   398,  1312,  1336,
    1349,   317,   296,    -1,   355,    46,  1059,   398,  1805,   253,
     229,  1580,  1560,   168,   345,  1605,  1611,  1626,  1589,  1597,
     325,   348,  1484,   250,   168,   165,   107,   893,   906,  1499,
    1505,   709,   366,   365,   234,    -1,   572,  1075,   378,   271,
     244,   284,   284,   394,  1617,   399,  1813,  1821,   405,   412,
      -1,   385,   159,   159,  1511,    -1,   392,   204,   204,   474,
     477,   437,   225,  1356,   442,   660,  1100,   705,   168,   944,
     333,   789,   802,   718,   731,  1373,  1829,   410,   449,  1634,
    1642,  1648,   451,  1207,  1325,  1519,  1393,  1410,   266,  1113,
     282,   776,    -1,   396,   244,   244,  1654,  1525,   398,   456,
     229,   453,   847,   860,   873,   465,  1417,   469,   918,  1120,
     456,  1430
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,   514,    29,   444,    18,  -129,   -30,  -129,
     542,   -19,  -128,   -75,   561,   569,   582,   -32,   -23,   383,
     389,   327,   231,   -74,   -77,    -5,   135,   591,   621,   623,
     631,   644,   656,   657
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    78,     8,     9,     6,    16,    17,
      79,   134,    56,    80,   135,   136,   137,    48,   118,   109,
     110,   111,   112,    73,    76,   113,   114,   138,   139,   140,
     141,   142,   143,   144
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    49,   187,     1,    93,    15,   146,    -2,     7,   -42,
      70,    71,    64,     1,   -37,   170,   157,   -12,    20,    54,
      63,    18,   -43,    67,    68,   -10,    14,   197,    10,     5,
     -10,   -10,     5,    86,   146,   165,    87,   164,    84,   123,
      41,    54,    49,   -46,   -13,   172,    89,   171,   -42,   -46,
     -37,   147,   -46,   -46,   -46,   -46,   -46,   -46,    65,    19,
      54,   -43,    99,    42,    54,    98,    88,   150,    54,    12,
     104,    92,   195,   -46,   -46,   -46,   -46,   -46,   -46,   160,
     123,    43,   103,    44,   161,   162,   106,    66,    45,    57,
     148,    58,   -46,   168,   169,   154,    59,   179,   -46,    46,
     -33,   -46,   -46,   -46,   -46,   -46,   180,   232,   167,   231,
     125,   123,   233,   -46,   -32,   191,   -39,   -39,    74,    75,
     -39,   195,   238,   192,   185,   194,   158,    47,   243,    60,
     242,   165,   -33,   158,   210,   199,   193,   211,    -4,   248,
     -33,   247,   172,   223,    -4,    61,   -32,    85,   -45,    47,
     288,   222,   150,   123,   227,   228,   -39,   -44,   206,    55,
     209,   123,   102,   235,   202,   217,   123,   220,   239,   -31,
     123,   196,   185,    62,    70,    71,   -33,   160,   -36,   124,
     241,    55,    62,   285,   107,   284,   232,   -45,   152,    94,
     237,   246,   253,   243,   115,   254,   -44,   248,    95,   146,
      55,   180,    96,   203,    55,   116,   256,   151,    55,   213,
     268,    55,   108,   295,   -36,   272,   285,   125,   156,   185,
     124,   108,    97,   155,   185,   261,   185,   264,    46,   280,
     156,   -31,   279,   117,   159,   283,   146,   206,   271,   176,
     100,   116,   217,   275,   -24,   107,   -32,   123,   214,   257,
     177,   124,   291,    25,   158,    53,    47,   117,   297,   -46,
     -46,   -46,   -46,   -46,   186,   146,   158,   160,   -35,   117,
     296,   -23,   -23,   108,   173,   122,   226,    53,   178,   261,
     294,   301,   -32,   -23,   105,   -23,   -23,   177,   258,   226,
     -35,   174,   151,   124,   245,   158,    53,   201,   207,   -46,
      53,   124,   -34,   149,    91,   218,   124,   124,   146,   146,
     124,   175,   186,   -23,   -23,   178,   122,   -23,   -23,   -23,
     188,   -46,   -46,   -46,   -46,   -46,   -46,   166,   178,   189,
     151,   290,   -39,   -39,    74,    75,   -39,   -39,   -39,   190,
     212,   -34,   -39,   -39,    74,    75,   -39,   122,   -15,   -15,
     -39,    52,   -39,   -39,    70,    71,   167,   -26,   -36,   186,
     184,   -46,   234,   -26,   186,   262,   186,   186,   146,   221,
      -5,   121,   -39,    52,   -30,   101,    -5,   207,   207,   146,
     -39,   -39,   218,   218,   -39,   -39,   -39,   124,   198,   122,
     -36,   146,    52,   244,   205,   208,    52,   122,   146,    90,
     236,   216,   219,   126,    77,   146,   122,    50,   184,   146,
     -21,   251,   121,    51,   252,   127,   -21,   128,   129,   262,
     262,   -14,   -14,   255,   -22,   -22,    -7,   119,   -21,    50,
     269,    13,    -7,   120,   -31,    51,   -22,   273,   -22,   -22,
     -31,   292,   265,   121,   266,   130,   -25,    69,    50,   131,
     132,   133,    50,   267,    51,   184,   183,   -30,    51,    -9,
     184,   260,   263,   -33,    -9,    -9,   -22,   -22,   119,   -33,
     -22,   -22,   -22,   270,   120,   -32,   -33,   126,   274,   276,
      -6,   -32,   277,   122,   278,   121,    -6,   281,   -32,   127,
     204,   128,   129,   121,   286,   -10,   287,   215,   298,   119,
     -10,   -10,   121,   130,   183,   120,   -41,   -41,   -41,   -41,
     -41,   -41,   181,   299,   300,   293,   -35,    11,   182,   130,
     -25,   153,   -35,   131,   132,   133,    70,    71,   -46,    69,
     -37,   163,   -46,   -46,   -46,   -46,   -46,   -46,   224,   -34,
     -46,   119,   -46,   -46,    -3,   -34,   -41,   120,    -8,   119,
      -3,   183,    69,    -8,    -8,   120,   183,   259,   119,   -37,
     181,    29,   -37,     0,   120,   -37,   182,   225,    70,    71,
     -46,   -46,   -37,    72,   -46,   -46,   -46,   -46,     0,   121,
      31,   -46,   -46,   -46,   -46,   -46,   -46,   -11,    32,   -46,
     -39,   -46,   -46,   -11,   -39,   -39,    74,    75,   -39,   -39,
     -16,    33,   -39,   -17,   -39,   -39,   -16,   181,   -18,   -17,
      34,   -19,   181,   182,   -18,   -20,   225,   -19,   182,   -46,
     -46,   -20,     0,   -46,   -46,   -46,   -39,   -39,    74,    75,
     -39,   -39,   -39,   -39,     0,   119,   -39,   -39,   -39,   -41,
      35,   120,    36,   -41,   -41,   -41,   -41,   -41,   -41,   -50,
      37,   -41,   -47,   -41,   -41,   -50,   -47,   -47,   -47,   -47,
     -47,   -47,   -39,    38,   -47,   -48,   -47,   -47,     0,   -48,
     -48,   -48,   -48,   -48,   -48,    39,    40,   -48,   -51,   -48,
     -48,   -41,   -41,   -36,   -51,   -41,   -41,   -41,     0,   -36,
       0,   -52,    70,    71,   -47,   -47,   -36,   -52,   -47,   -47,
     -47,    81,     0,   -53,     0,    82,    83,   -48,   -48,   -53,
     -46,   -48,   -48,   -48,   -46,   -46,   -46,   -46,   -46,     0,
     -54,     0,   -46,   -38,   -46,   -46,   -54,   -38,   -38,    74,
      75,   -38,   -38,   -55,     0,   -38,   -40,   -38,   -38,   -55,
     -40,   -40,   -40,   -40,   -40,   -40,     0,     0,   -40,   282,
     -40,   -40,   -46,   -46,   -29,   -57,   -46,   -46,   -46,   249,
     -29,   -57,   -58,   250,    83,   -38,   -38,   -59,   -58,   -38,
     -38,   -38,     0,   -59,   -30,     0,     0,     0,   -40,   -40,
     -30,   -49,   -40,   -40,   -40,   -49,   -49,   -49,   -49,   -49,
     -49,   -21,     0,   -49,   -41,   -49,   -49,   -21,   -41,   -41,
     -41,   -41,   -41,     0,   -56,     0,   -41,   -47,   -41,   -41,
     -56,   -47,   -47,   -47,   -47,   -47,     0,     0,     0,   -47,
     -60,   -47,   -47,   -49,   -49,   -27,   -60,   -49,   -49,   -49,
       0,   -27,   -28,     0,     0,     0,   -41,   -41,   -28,     0,
     -41,   -41,   -41,     0,     0,     0,     0,     0,     0,   -47,
     -47,     0,   -48,   -47,   -47,   -47,   -48,   -48,   -48,   -48,
     -48,     0,     0,     0,   -48,   -38,   -48,   -48,     0,   -38,
     -38,    74,    75,   -38,     0,     0,     0,   -38,   -40,   -38,
     -38,     0,   -40,   -40,   -40,   -40,   -40,     0,     0,     0,
     -40,     0,   -40,   -40,   -48,   -48,     0,     0,   -48,   -48,
     -48,     0,   -41,   -41,   -41,   -41,   -41,   -38,   -38,     0,
       0,   -38,   -38,   -38,     0,   -47,   -47,   -47,   -47,   -47,
     -40,   -40,     0,   -49,   -40,   -40,   -40,   -49,   -49,   -49,
     -49,   -49,     0,     0,     0,   -49,   -37,   -49,   -49,     0,
      70,    71,   -41,     0,   -37,   230,     0,     0,   -37,   -36,
     -37,   -37,     0,    70,    71,   -47,     0,   -36,     0,     0,
       0,   -36,     0,   -36,   -36,   -49,   -49,     0,     0,   -49,
     -49,   -49,     0,   -10,   -10,     0,     0,     0,   -37,   -37,
       0,     0,   -37,   -37,   -37,   -10,     0,   -10,   -10,   152,
      -7,   -36,   -36,     0,     0,   -36,   -36,   -36,    -9,    -9,
       0,    -7,     0,    -7,    -7,     0,     0,     0,     0,     0,
      -9,     0,    -9,    -9,   -31,   -10,   -10,     0,     0,   -10,
     -10,   -10,   229,     0,     0,     0,   -31,     0,   -31,   -31,
       0,    -7,    -7,     0,     0,    -7,    -7,    -7,     0,   -33,
      -9,    -9,     0,     0,    -9,    -9,    -9,   -33,     0,     0,
       0,   -33,     0,   -33,   -33,   -32,   -31,   -31,     0,     0,
     -31,   -31,   -31,   -32,    -8,    -8,     0,   -32,     0,   -32,
     -32,     0,     0,     0,     0,     0,    -8,     0,    -8,    -8,
     -35,   -33,   -33,     0,     0,   -33,   -33,   -33,   229,     0,
       0,     0,   -35,     0,   -35,   -35,     0,   -32,   -32,     0,
       0,   -32,   -32,   -32,     0,   -34,    -8,    -8,     0,     0,
      -8,    -8,    -8,   229,     0,     0,     0,   -34,   -26,   -34,
     -34,     0,   -35,   -35,     0,   -21,   -35,   -35,   -35,     0,
     -26,   289,   -26,   -26,     0,     0,     0,   -21,   -21,   -21,
     -21,     0,   -16,     0,     0,     0,     0,   -34,   -34,     0,
       0,   -34,   -34,   -34,   -16,     0,   -16,   -16,     0,     0,
     -26,   -26,   -17,     0,   -26,   -26,   -26,   -21,   -21,     0,
       0,   -21,   -21,   -21,   -17,     0,   -17,   -17,     0,   -18,
       0,     0,     0,     0,   -16,   -16,   -19,     0,   -16,   -16,
     -16,   -18,     0,   -18,   -18,     0,     0,     0,   -19,   -20,
     -19,   -19,     0,     0,   -17,   -17,     0,     0,   -17,   -17,
     -17,   -20,     0,   -20,   -20,     0,   -48,   -48,   -48,   -48,
     -48,   -18,   -18,   -50,     0,   -18,   -18,   -18,   -19,   -19,
       0,     0,   -19,   -19,   -19,   -50,   -51,   -50,   -50,     0,
       0,   -20,   -20,   -52,     0,   -20,   -20,   -20,   -51,     0,
     -51,   -51,     0,     0,     0,   -52,   -48,   -52,   -52,     0,
     -53,     0,     0,     0,     0,   -50,   -50,     0,     0,   -50,
     -50,   -50,   -53,     0,   -53,   -53,     0,     0,   -51,   -51,
     -54,     0,   -51,   -51,   -51,   -52,   -52,     0,     0,   -52,
     -52,   -52,   -54,     0,   -54,   -54,     0,   -55,     0,     0,
       0,     0,   -53,   -53,   -29,     0,   -53,   -53,   -53,   -55,
       0,   -55,   -55,     0,     0,     0,   -29,   -57,   -29,   -29,
       0,     0,   -54,   -54,     0,     0,   -54,   -54,   -54,   -57,
       0,   -57,   -57,     0,   -38,   -38,    74,    75,   -38,   -55,
     -55,   -58,     0,   -55,   -55,   -55,   -29,   -29,     0,     0,
     -29,   -29,   -29,   -58,   -59,   -58,   -58,     0,     0,   -57,
     -57,   -30,     0,   -57,   -57,   -57,   -59,     0,   -59,   -59,
       0,     0,     0,   -30,   -38,   -30,   -30,     0,   -21,     0,
       0,     0,     0,   -58,   -58,     0,     0,   -58,   -58,   -58,
     -21,     0,   -21,   -21,     0,     0,   -59,   -59,   -56,     0,
     -59,   -59,   -59,   -30,   -30,     0,     0,   -30,   -30,   -30,
     -56,     0,   -56,   -56,     0,   -60,     0,     0,     0,     0,
     -21,   -21,   -27,     0,   -21,   -21,   -21,   -60,     0,   -60,
     -60,     0,     0,     0,   -27,   -28,   -27,   -27,     0,     0,
     -56,   -56,   -46,     0,   -56,   -56,   -56,   -28,   -46,   -28,
     -28,   -46,   -46,   -46,   -46,   -46,   -46,   -60,   -60,    21,
       0,   -60,   -60,   -60,   -27,   -27,     0,     0,   -27,   -27,
     -27,    22,     0,    23,    24,     0,     0,   -28,   -28,     0,
       0,   -28,   -28,   -28,     0,     0,    66,   -47,   -47,   -47,
     -47,   -47,   -47,   -48,   -48,   -48,   -48,   -48,   -48,     0,
       0,    25,     0,     0,     0,    26,    27,    28,   -38,   -38,
      74,    75,   -38,   -38,   -40,   -40,   -40,   -40,   -40,   -40,
     -49,   -49,   -49,   -49,   -49,   -49,     0,   -47,   -40,   -40,
     -40,   -40,   -40,   -48,   -49,   -49,   -49,   -49,   -49,     0,
     -46,   -46,   -46,   -46,   -46,   -46,   200,     0,   -38,     0,
       0,     0,     0,     0,   -40,     0,     0,     0,     0,     0,
     -49,   -46,   -46,   -46,   -46,   -46,   -46,     0,   -40,   -46,
     -46,   -46,   -46,   -46,   -49,   145,   -46,   -41,   -41,   -41,
     -41,   -41,   -41,   -47,   -47,   -47,   -47,   -47,   -47,   -48,
     -48,   -48,   -48,   -48,   -48,     0,   145,   -46,   -38,   -38,
      74,    75,   -38,   -38,   240,   -46,   -40,   -40,   -40,   -40,
     -40,   -40,     0,   -41,   -39,   -39,    74,    75,   -39,   -47,
     -41,   -41,   -41,   -41,   -41,   -48,   -49,   -49,   -49,   -49,
     -49,   -49,     0,     0,   -38,   -47,   -47,   -47,   -47,   -47,
       0,     0,   -40,   -48,   -48,   -48,   -48,   -48,     0,     0,
     -39,   -38,   -38,    74,    75,   -38,   -41,   -40,   -40,   -40,
     -40,   -40,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,
       0,   -47,   -39,     0,     0,     0,     0,     0,   -39,   -48,
       0,   -39,   -39,    74,    75,   -39,   -39,   -38,     0,     0,
       0,   -41,     0,   -40,     0,     0,     0,   -41,     0,   -49,
     -41,   -41,   -41,   -41,   -41,   -41,   -47,     0,     0,     0,
       0,     0,   -47,     0,     0,   -47,   -47,   -47,   -47,   -47,
     -47,   -48,     0,     0,     0,     0,     0,   -48,     0,     0,
     -48,   -48,   -48,   -48,   -48,   -48,   -38,     0,     0,     0,
       0,     0,   -38,     0,     0,   -38,   -38,    74,    75,   -38,
     -38,   -40,     0,     0,     0,     0,     0,   -40,     0,     0,
     -40,   -40,   -40,   -40,   -40,   -40,   -49,     0,     0,     0,
       0,     0,   -49,     0,     0,   -49,   -49,   -49,   -49,   -49,
     -49,   -39,     0,     0,     0,     0,     0,   -39,     0,   -41,
     -39,   -39,    74,    75,   -39,   -41,     0,   -47,   -41,   -41,
     -41,   -41,   -41,   -47,     0,   -38,   -47,   -47,   -47,   -47,
     -47,   -38,     0,   -48,   -38,   -38,    74,    75,   -38,   -48,
       0,   -40,   -48,   -48,   -48,   -48,   -48,   -40,     0,   -49,
     -40,   -40,   -40,   -40,   -40,   -49,     0,     0,   -49,   -49,
     -49,   -49,   -49
};

static const yytype_int16 yycheck[] =
{
      19,    24,   130,     6,    79,     6,    13,     0,     5,     5,
       9,    10,    44,     6,    13,    14,    90,    45,    46,    24,
      43,     5,     5,    46,    47,     0,     8,   155,     0,     0,
       5,     6,     3,    65,    13,   112,    66,   111,    45,    44,
       6,    46,    65,     0,    45,   122,    69,   121,    44,     6,
      49,     5,     9,    10,    11,    12,    13,    14,    15,    45,
      65,    44,    85,    15,    69,    84,    45,    72,    73,    44,
     102,    76,   149,     9,    10,    11,    12,    13,    14,   102,
      85,    44,   101,    44,   107,   108,   105,    44,     5,     5,
      44,     5,     0,   116,   117,    77,     5,   129,     6,    16,
      13,     9,    10,    11,    12,    13,   129,   184,    44,   183,
       5,   116,   187,    49,    13,   145,     9,    10,    11,    12,
      13,   198,   197,   146,   129,   148,    13,    44,   205,     5,
     204,   208,    45,    13,   166,   158,    44,   167,     0,   216,
      13,   215,   219,   175,     6,     5,    45,    49,     5,    44,
     278,   174,   157,   158,   177,   178,    49,     5,   163,    24,
     165,   166,    49,   193,     5,   170,   171,   172,   200,    49,
     175,   153,   177,     5,     9,    10,    49,   200,    13,    44,
     203,    46,     5,   260,    16,   259,   263,    44,     5,    48,
     195,   214,   224,   270,     5,   225,    44,   274,     5,    13,
      65,   224,     5,    44,    69,    16,   229,    72,    73,     5,
     240,    76,    44,   288,    49,   245,   293,     5,     5,   224,
      85,    44,     5,    47,   229,   230,   231,   232,    16,   252,
       5,    45,   251,    44,     5,   258,    13,   242,   243,     5,
      45,    16,   247,   248,    48,    16,    13,   252,    44,     5,
      16,   116,   282,    47,    13,    24,    44,    44,   290,     9,
      10,    11,    12,    13,   129,    13,    13,   290,    45,    44,
     289,     5,     6,    44,    15,    44,     5,    46,    44,   284,
     285,   300,    49,    17,    45,    19,    20,    16,    44,     5,
      49,    44,   157,   158,    44,    13,    65,    45,   163,    49,
      69,   166,    49,    72,    73,   170,   171,   172,    13,    13,
     175,    44,   177,    47,    48,    44,    85,    51,    52,    53,
       5,     9,    10,    11,    12,    13,    14,    15,    44,     5,
     195,    49,     9,    10,    11,    12,    13,    14,     5,     5,
      45,    45,     9,    10,    11,    12,    13,   116,    45,    46,
      17,    24,    19,    20,     9,    10,    44,     0,    13,   224,
     129,    49,    45,     6,   229,   230,   231,   232,    13,     5,
       0,    44,    49,    46,    49,    18,     6,   242,   243,    13,
      47,    48,   247,   248,    51,    52,    53,   252,   157,   158,
      45,    13,    65,    45,   163,   164,    69,   166,    13,    72,
      45,   170,   171,     5,     6,    13,   175,    24,   177,    13,
       0,    45,    85,    24,    49,    17,     6,    19,    20,   284,
     285,    45,    46,    45,     5,     6,     0,    44,    18,    46,
      45,     5,     6,    44,     0,    46,    17,    45,    19,    20,
       6,    45,    48,   116,    45,    47,    48,    13,    65,    51,
      52,    53,    69,    48,    65,   224,   129,    45,    69,     0,
     229,   230,   231,     0,     5,     6,    47,    48,    85,     6,
      51,    52,    53,   242,    85,     0,    13,     5,   247,     5,
       0,     6,     5,   252,    47,   158,     6,    45,    13,    17,
     163,    19,    20,   166,    45,     0,    45,   170,    45,   116,
       5,     6,   175,    47,   177,   116,     9,    10,    11,    12,
      13,    14,   129,    48,    45,   284,     0,     3,   129,    47,
      48,    77,     6,    51,    52,    53,     9,    10,     5,    13,
      13,    14,     9,    10,    11,    12,    13,    14,    15,     0,
      17,   158,    19,    20,     0,     6,    49,   158,     0,   166,
       6,   224,    13,     5,     6,   166,   229,   230,   175,     0,
     177,    19,    45,    -1,   175,     6,   177,    44,     9,    10,
      47,    48,    13,    14,    51,    52,    53,     5,    -1,   252,
      19,     9,    10,    11,    12,    13,    14,     0,    19,    17,
       5,    19,    20,     6,     9,    10,    11,    12,    13,    14,
       0,    19,    17,     0,    19,    20,     6,   224,     0,     6,
      19,     0,   229,   224,     6,     0,    44,     6,   229,    47,
      48,     6,    -1,    51,    52,    53,     9,    10,    11,    12,
      13,    14,    47,    48,    -1,   252,    51,    52,    53,     5,
      19,   252,    19,     9,    10,    11,    12,    13,    14,     0,
      19,    17,     5,    19,    20,     6,     9,    10,    11,    12,
      13,    14,    45,    19,    17,     5,    19,    20,    -1,     9,
      10,    11,    12,    13,    14,    19,    19,    17,     0,    19,
      20,    47,    48,     0,     6,    51,    52,    53,    -1,     6,
      -1,     0,     9,    10,    47,    48,    13,     6,    51,    52,
      53,    50,    -1,     0,    -1,    54,    55,    47,    48,     6,
       5,    51,    52,    53,     9,    10,    11,    12,    13,    -1,
       0,    -1,    17,     5,    19,    20,     6,     9,    10,    11,
      12,    13,    14,     0,    -1,    17,     5,    19,    20,     6,
       9,    10,    11,    12,    13,    14,    -1,    -1,    17,    44,
      19,    20,    47,    48,     0,     0,    51,    52,    53,    50,
       6,     6,     0,    54,    55,    47,    48,     0,     6,    51,
      52,    53,    -1,     6,     0,    -1,    -1,    -1,    47,    48,
       6,     5,    51,    52,    53,     9,    10,    11,    12,    13,
      14,     0,    -1,    17,     5,    19,    20,     6,     9,    10,
      11,    12,    13,    -1,     0,    -1,    17,     5,    19,    20,
       6,     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,
       0,    19,    20,    47,    48,     0,     6,    51,    52,    53,
      -1,     6,     0,    -1,    -1,    -1,    47,    48,     6,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,     5,    51,    52,    53,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    17,     5,    19,    20,    -1,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    17,     5,    19,
      20,    -1,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    -1,    19,    20,    47,    48,    -1,    -1,    51,    52,
      53,    -1,     9,    10,    11,    12,    13,    47,    48,    -1,
      -1,    51,    52,    53,    -1,     9,    10,    11,    12,    13,
      47,    48,    -1,     5,    51,    52,    53,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    17,     5,    19,    20,    -1,
       9,    10,    49,    -1,    13,    14,    -1,    -1,    17,     5,
      19,    20,    -1,     9,    10,    49,    -1,    13,    -1,    -1,
      -1,    17,    -1,    19,    20,    47,    48,    -1,    -1,    51,
      52,    53,    -1,     5,     6,    -1,    -1,    -1,    47,    48,
      -1,    -1,    51,    52,    53,    17,    -1,    19,    20,     5,
       6,    47,    48,    -1,    -1,    51,    52,    53,     5,     6,
      -1,    17,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    19,    20,     5,    47,    48,    -1,    -1,    51,
      52,    53,    13,    -1,    -1,    -1,    17,    -1,    19,    20,
      -1,    47,    48,    -1,    -1,    51,    52,    53,    -1,     5,
      47,    48,    -1,    -1,    51,    52,    53,    13,    -1,    -1,
      -1,    17,    -1,    19,    20,     5,    47,    48,    -1,    -1,
      51,    52,    53,    13,     5,     6,    -1,    17,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,
       5,    47,    48,    -1,    -1,    51,    52,    53,    13,    -1,
      -1,    -1,    17,    -1,    19,    20,    -1,    47,    48,    -1,
      -1,    51,    52,    53,    -1,     5,    47,    48,    -1,    -1,
      51,    52,    53,    13,    -1,    -1,    -1,    17,     5,    19,
      20,    -1,    47,    48,    -1,     5,    51,    52,    53,    -1,
      17,    18,    19,    20,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,     5,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    51,    52,    53,    17,    -1,    19,    20,    -1,    -1,
      47,    48,     5,    -1,    51,    52,    53,    47,    48,    -1,
      -1,    51,    52,    53,    17,    -1,    19,    20,    -1,     5,
      -1,    -1,    -1,    -1,    47,    48,     5,    -1,    51,    52,
      53,    17,    -1,    19,    20,    -1,    -1,    -1,    17,     5,
      19,    20,    -1,    -1,    47,    48,    -1,    -1,    51,    52,
      53,    17,    -1,    19,    20,    -1,     9,    10,    11,    12,
      13,    47,    48,     5,    -1,    51,    52,    53,    47,    48,
      -1,    -1,    51,    52,    53,    17,     5,    19,    20,    -1,
      -1,    47,    48,     5,    -1,    51,    52,    53,    17,    -1,
      19,    20,    -1,    -1,    -1,    17,    49,    19,    20,    -1,
       5,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    51,
      52,    53,    17,    -1,    19,    20,    -1,    -1,    47,    48,
       5,    -1,    51,    52,    53,    47,    48,    -1,    -1,    51,
      52,    53,    17,    -1,    19,    20,    -1,     5,    -1,    -1,
      -1,    -1,    47,    48,     5,    -1,    51,    52,    53,    17,
      -1,    19,    20,    -1,    -1,    -1,    17,     5,    19,    20,
      -1,    -1,    47,    48,    -1,    -1,    51,    52,    53,    17,
      -1,    19,    20,    -1,     9,    10,    11,    12,    13,    47,
      48,     5,    -1,    51,    52,    53,    47,    48,    -1,    -1,
      51,    52,    53,    17,     5,    19,    20,    -1,    -1,    47,
      48,     5,    -1,    51,    52,    53,    17,    -1,    19,    20,
      -1,    -1,    -1,    17,    49,    19,    20,    -1,     5,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    51,    52,    53,
      17,    -1,    19,    20,    -1,    -1,    47,    48,     5,    -1,
      51,    52,    53,    47,    48,    -1,    -1,    51,    52,    53,
      17,    -1,    19,    20,    -1,     5,    -1,    -1,    -1,    -1,
      47,    48,     5,    -1,    51,    52,    53,    17,    -1,    19,
      20,    -1,    -1,    -1,    17,     5,    19,    20,    -1,    -1,
      47,    48,     0,    -1,    51,    52,    53,    17,     6,    19,
      20,     9,    10,    11,    12,    13,    14,    47,    48,     5,
      -1,    51,    52,    53,    47,    48,    -1,    -1,    51,    52,
      53,    17,    -1,    19,    20,    -1,    -1,    47,    48,    -1,
      -1,    51,    52,    53,    -1,    -1,    44,     9,    10,    11,
      12,    13,    14,     9,    10,    11,    12,    13,    14,    -1,
      -1,    47,    -1,    -1,    -1,    51,    52,    53,     9,    10,
      11,    12,    13,    14,     9,    10,    11,    12,    13,    14,
       9,    10,    11,    12,    13,    14,    -1,    49,     9,    10,
      11,    12,    13,    49,     9,    10,    11,    12,    13,    -1,
       9,    10,    11,    12,    13,    14,    15,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      49,     9,    10,    11,    12,    13,    14,    -1,    49,     9,
      10,    11,    12,    13,    49,    44,    45,     9,    10,    11,
      12,    13,    14,     9,    10,    11,    12,    13,    14,     9,
      10,    11,    12,    13,    14,    -1,    44,    45,     9,    10,
      11,    12,    13,    14,    44,    45,     9,    10,    11,    12,
      13,    14,    -1,    45,     9,    10,    11,    12,    13,    45,
       9,    10,    11,    12,    13,    45,     9,    10,    11,    12,
      13,    14,    -1,    -1,    45,     9,    10,    11,    12,    13,
      -1,    -1,    45,     9,    10,    11,    12,    13,    -1,    -1,
      45,     9,    10,    11,    12,    13,    45,     9,    10,    11,
      12,    13,    45,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    45,     0,    -1,    -1,    -1,    -1,    -1,     6,    45,
      -1,     9,    10,    11,    12,    13,    14,    45,    -1,    -1,
      -1,     0,    -1,    45,    -1,    -1,    -1,     6,    -1,    45,
       9,    10,    11,    12,    13,    14,     0,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,     0,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
       9,    10,    11,    12,    13,    14,     0,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,     0,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
       9,    10,    11,    12,    13,    14,     0,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,     0,    -1,    -1,    -1,    -1,    -1,     6,    -1,     0,
       9,    10,    11,    12,    13,     6,    -1,     0,     9,    10,
      11,    12,    13,     6,    -1,     0,     9,    10,    11,    12,
      13,     6,    -1,     0,     9,    10,    11,    12,    13,     6,
      -1,     0,     9,    10,    11,    12,    13,     6,    -1,     0,
       9,    10,    11,    12,    13,     6,    -1,    -1,     9,    10,
      11,    12,    13
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    57,    58,    59,    60,    63,     5,    61,    62,
       0,    59,    44,     5,    62,     6,    64,    65,     5,    45,
      46,     5,    17,    19,    20,    47,    51,    52,    53,    66,
      67,    70,    71,    72,    83,    84,    85,    86,    87,    88,
      89,     6,    15,    44,    44,     5,    16,    44,    73,    74,
      75,    76,    77,    78,    81,    82,    68,     5,     5,     5,
       5,     5,     5,    74,    73,    15,    44,    74,    74,    13,
       9,    10,    14,    79,    11,    12,    80,     6,    60,    66,
      69,    50,    54,    55,    45,    49,    73,    64,    45,    74,
      77,    78,    81,    69,    48,     5,     5,     5,    67,    74,
      45,    18,    49,    67,    73,    45,    67,    16,    44,    75,
      76,    77,    78,    81,    82,     5,    16,    44,    74,    75,
      76,    77,    78,    81,    82,     5,     5,    17,    19,    20,
      47,    51,    52,    53,    67,    70,    71,    72,    83,    84,
      85,    86,    87,    88,    89,    44,    13,     5,    44,    78,
      81,    82,     5,    61,    62,    47,     5,    79,    13,     5,
      74,    74,    74,    14,    79,    80,    15,    44,    74,    74,
      14,    79,    80,    15,    44,    44,     5,    16,    44,    73,
      74,    75,    76,    77,    78,    81,    82,    68,     5,     5,
       5,    64,    74,    44,    74,    80,    62,    68,    78,    74,
      15,    45,     5,    44,    77,    78,    81,    82,    78,    81,
      73,    64,    45,     5,    44,    77,    78,    81,    82,    78,
      81,     5,    74,    73,    15,    44,     5,    74,    74,    13,
      14,    79,    80,    69,    45,    64,    45,    81,    69,    73,
      44,    74,    79,    80,    45,    44,    74,    79,    80,    50,
      54,    45,    49,    73,    64,    45,    74,     5,    44,    77,
      78,    81,    82,    78,    81,    48,    45,    48,    64,    45,
      78,    81,    64,    45,    78,    81,     5,     5,    47,    67,
      74,    45,    44,    74,    79,    80,    45,    45,    68,    18,
      49,    64,    45,    78,    81,    69,    67,    73,    45,    48,
      45,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    60,    61,    61,
      62,    63,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    67,    68,    68,    69,    69,    70,    70,    71,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    81,    82,
      83,    83,    83,    83,    83,    83,    84,    85,    86,    87,
      88,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     2,     1,
       1,     6,     1,     0,     4,     2,     1,     1,     1,     1,
       1,     4,     2,     0,     2,     0,     5,     7,     9,     2,
       3,     1,     1,     1,     3,     2,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     4,
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
#line 99 "./src/syntax.y"
                    { printf('%d', yyvsp[0]); }
#line 1782 "y.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 103 "./src/syntax.y"
                                {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1788 "y.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 104 "./src/syntax.y"
                  {printf('%d', yyvsp[0]);}
#line 1794 "y.tab.c"
    break;

  case 5: /* declaration: varDeclaration  */
#line 108 "./src/syntax.y"
                   {printf('%d', yyvsp[0]);}
#line 1800 "y.tab.c"
    break;

  case 6: /* declaration: funcDeclaration  */
#line 109 "./src/syntax.y"
                      {printf('%d', yyvsp[0]);}
#line 1806 "y.tab.c"
    break;

  case 7: /* varDeclaration: TYPE varDeclList  */
#line 113 "./src/syntax.y"
                     {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1812 "y.tab.c"
    break;

  case 8: /* varDeclList: varDeclList varDeclId  */
#line 117 "./src/syntax.y"
                          {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1818 "y.tab.c"
    break;

  case 9: /* varDeclList: varDeclId  */
#line 118 "./src/syntax.y"
                {printf('%d', yyvsp[0]);}
#line 1824 "y.tab.c"
    break;

  case 10: /* varDeclId: ID  */
#line 122 "./src/syntax.y"
       {printf('%d', yyvsp[0]);}
#line 1830 "y.tab.c"
    break;

  case 11: /* funcDeclaration: TYPE ID '(' parameters ')' statement  */
#line 126 "./src/syntax.y"
                                         {printf('%d %d %d %d %d %d', yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1836 "y.tab.c"
    break;

  case 12: /* parameters: parameterList  */
#line 130 "./src/syntax.y"
                  {printf('%d', yyvsp[0]);}
#line 1842 "y.tab.c"
    break;

  case 13: /* parameters: %empty  */
#line 131 "./src/syntax.y"
      {}
#line 1848 "y.tab.c"
    break;

  case 14: /* parameterList: parameterList ',' TYPE ID  */
#line 135 "./src/syntax.y"
                              {printf('%d %d %d', yyvsp[-3], yyvsp[-2], yyvsp[-1]);}
#line 1854 "y.tab.c"
    break;

  case 15: /* parameterList: TYPE ID  */
#line 136 "./src/syntax.y"
              {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1860 "y.tab.c"
    break;

  case 16: /* statement: bodyStatement  */
#line 140 "./src/syntax.y"
                  {printf('%d', yyvsp[0]);}
#line 1866 "y.tab.c"
    break;

  case 17: /* statement: ifStatement  */
#line 141 "./src/syntax.y"
                  {printf('%d', yyvsp[0]);}
#line 1872 "y.tab.c"
    break;

  case 18: /* statement: loopStatement  */
#line 142 "./src/syntax.y"
                    {printf('%d', yyvsp[0]);}
#line 1878 "y.tab.c"
    break;

  case 19: /* statement: returnStatement  */
#line 143 "./src/syntax.y"
                      {printf('%d', yyvsp[0]);}
#line 1884 "y.tab.c"
    break;

  case 20: /* statement: listStatement  */
#line 144 "./src/syntax.y"
                    {printf('%d', yyvsp[0]);}
#line 1890 "y.tab.c"
    break;

  case 21: /* bodyStatement: '{' localDeclaration statementList '}'  */
#line 148 "./src/syntax.y"
                                           {printf('%d %d %d %d', yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1896 "y.tab.c"
    break;

  case 22: /* localDeclaration: localDeclaration varDeclaration  */
#line 152 "./src/syntax.y"
                                    {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1902 "y.tab.c"
    break;

  case 23: /* localDeclaration: %empty  */
#line 153 "./src/syntax.y"
      {}
#line 1908 "y.tab.c"
    break;

  case 24: /* statementList: statement statementList  */
#line 157 "./src/syntax.y"
                            {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1914 "y.tab.c"
    break;

  case 25: /* statementList: %empty  */
#line 158 "./src/syntax.y"
      {}
#line 1920 "y.tab.c"
    break;

  case 26: /* ifStatement: IF_KEY '(' simpleExpression ')' bodyStatement  */
#line 162 "./src/syntax.y"
                                                  {printf('%d %d %d %d %d', yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1926 "y.tab.c"
    break;

  case 27: /* ifStatement: IF_KEY '(' simpleExpression ')' bodyStatement ELSE_KEY bodyStatement  */
#line 163 "./src/syntax.y"
                                                                           {printf('%d %d %d %d %d %d %d', yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1932 "y.tab.c"
    break;

  case 28: /* loopStatement: FOR_KEY '(' expression ';' simpleExpression ';' expression ')' bodyStatement  */
#line 167 "./src/syntax.y"
                                                                                 {printf('%d %d %d %d %d %d %d %d %d', yyvsp[-8], yyvsp[-7], yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1938 "y.tab.c"
    break;

  case 29: /* returnStatement: RETURN_KEY expression  */
#line 171 "./src/syntax.y"
                          {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1944 "y.tab.c"
    break;

  case 30: /* expression: ID ASSIGN_OP expression  */
#line 175 "./src/syntax.y"
                            {printf('%d %d %d', yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1950 "y.tab.c"
    break;

  case 31: /* expression: simpleExpression  */
#line 176 "./src/syntax.y"
                       {printf('%d', yyvsp[0]);}
#line 1956 "y.tab.c"
    break;

  case 32: /* simpleExpression: binExpression  */
#line 180 "./src/syntax.y"
                  {printf('%d', yyvsp[0]);}
#line 1962 "y.tab.c"
    break;

  case 33: /* simpleExpression: logicExpression  */
#line 181 "./src/syntax.y"
                      {printf('%d', yyvsp[0]);}
#line 1968 "y.tab.c"
    break;

  case 34: /* logicExpression: simpleExpression LOGIC_OP simpleExpression  */
#line 185 "./src/syntax.y"
                                               {printf('%d %d %d', yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1974 "y.tab.c"
    break;

  case 35: /* logicExpression: EXCLA_OP simpleExpression  */
#line 186 "./src/syntax.y"
                                {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 1980 "y.tab.c"
    break;

  case 36: /* binExpression: sumExpression BINARY_OP sumExpression  */
#line 190 "./src/syntax.y"
                                          {printf('%d %d %d', yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1986 "y.tab.c"
    break;

  case 37: /* binExpression: sumExpression  */
#line 191 "./src/syntax.y"
                    {printf('%d', yyvsp[0]);}
#line 1992 "y.tab.c"
    break;

  case 38: /* sumExpression: sumExpression sumOP mulExpression  */
#line 195 "./src/syntax.y"
                                      {printf('%d %d %d', yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1998 "y.tab.c"
    break;

  case 39: /* sumExpression: mulExpression  */
#line 196 "./src/syntax.y"
                    {printf('%d', yyvsp[0]);}
#line 2004 "y.tab.c"
    break;

  case 40: /* mulExpression: mulExpression mulOP factor  */
#line 200 "./src/syntax.y"
                               {printf('%d %d %d', yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2010 "y.tab.c"
    break;

  case 41: /* mulExpression: factor  */
#line 201 "./src/syntax.y"
             {printf('%d', yyvsp[0]);}
#line 2016 "y.tab.c"
    break;

  case 42: /* sumOP: PLUS_OP  */
#line 205 "./src/syntax.y"
            {printf('%d', yyvsp[0]);}
#line 2022 "y.tab.c"
    break;

  case 43: /* sumOP: MINUS_OP  */
#line 206 "./src/syntax.y"
               {printf('%d', yyvsp[0]);}
#line 2028 "y.tab.c"
    break;

  case 44: /* mulOP: MUL_OP  */
#line 210 "./src/syntax.y"
           {printf('%d', yyvsp[0]);}
#line 2034 "y.tab.c"
    break;

  case 45: /* mulOP: DIV_OP  */
#line 211 "./src/syntax.y"
             {printf('%d', yyvsp[0]);}
#line 2040 "y.tab.c"
    break;

  case 46: /* factor: ID  */
#line 215 "./src/syntax.y"
       {printf('%d', yyvsp[0]);}
#line 2046 "y.tab.c"
    break;

  case 47: /* factor: functionCall  */
#line 216 "./src/syntax.y"
                   {printf('%d', yyvsp[0]);}
#line 2052 "y.tab.c"
    break;

  case 48: /* factor: '(' simpleExpression ')'  */
#line 217 "./src/syntax.y"
                               {printf('%d %d %d', yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2058 "y.tab.c"
    break;

  case 49: /* functionCall: ID '(' parameters ')'  */
#line 221 "./src/syntax.y"
                          {printf('%d %d %d %d', yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2064 "y.tab.c"
    break;

  case 50: /* listStatement: listAssign  */
#line 244 "./src/syntax.y"
               {printf('%d', yyvsp[0]);}
#line 2070 "y.tab.c"
    break;

  case 51: /* listStatement: listHeader  */
#line 245 "./src/syntax.y"
                 {printf('%d', yyvsp[0]);}
#line 2076 "y.tab.c"
    break;

  case 52: /* listStatement: listTail  */
#line 246 "./src/syntax.y"
               {printf('%d', yyvsp[0]);}
#line 2082 "y.tab.c"
    break;

  case 53: /* listStatement: listTailDestructor  */
#line 247 "./src/syntax.y"
                         {printf('%d', yyvsp[0]);}
#line 2088 "y.tab.c"
    break;

  case 54: /* listStatement: listMap  */
#line 248 "./src/syntax.y"
              {printf('%d', yyvsp[0]);}
#line 2094 "y.tab.c"
    break;

  case 55: /* listStatement: listFilter  */
#line 249 "./src/syntax.y"
                 {printf('%d', yyvsp[0]);}
#line 2100 "y.tab.c"
    break;

  case 56: /* listAssign: ID ASSIGN_OP ID ':' ID  */
#line 253 "./src/syntax.y"
                           {printf('%d %d %d %d %d', yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2106 "y.tab.c"
    break;

  case 57: /* listHeader: '?' ID  */
#line 257 "./src/syntax.y"
           {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 2112 "y.tab.c"
    break;

  case 58: /* listTail: '!' ID  */
#line 261 "./src/syntax.y"
           {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 2118 "y.tab.c"
    break;

  case 59: /* listTailDestructor: '%' ID  */
#line 265 "./src/syntax.y"
           {printf('%d %d', yyvsp[-1], yyvsp[0]);}
#line 2124 "y.tab.c"
    break;

  case 60: /* listMap: ID ASSIGN_OP ID ">>" ID  */
#line 269 "./src/syntax.y"
                            {printf('%d %d %d %d %d', yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2130 "y.tab.c"
    break;

  case 61: /* listFilter: ID ASSIGN_OP ID "<<" ID  */
#line 273 "./src/syntax.y"
                            {printf('%d %d %d %d %d', yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2136 "y.tab.c"
    break;


#line 2140 "y.tab.c"

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

#line 277 "./src/syntax.y"

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
