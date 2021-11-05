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
#include "../lib/codegen.h"

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
-check function parameters: quantity and types on every use; - CHECKING
-check operators arguments types;

--Scope:
-check if variables used (identifiers) have been declared inside the scope or in any parent scope; - CHECKING

--Main
-detect existence of main function;
--Checando, mas poderia registrar a linha do registro;
--Poderia estender parte da checagem para todas as funções - verificar e informar caso ocorram redefinições de funções


---Notes:
-Function parameters: preciso armazenar quantos parâmetros e os tipos deles no registro de funções na tabela de símbolos, para que seja possível
verificar se as chamadas à função estão corretas;
Talvez uma lista de um struct próprio para isso; ou talvez um vetor de strings e uma variável para armazenar a quantidade, onde cada string é o tipo
Parâmetros estão sendo armazenados - vetor de símbolos, é possível acessar o que quiser
--Armazenar os erros em um struct e imprimir-los todos ao final? Talvez seja a melhor opção,
evita que os erros sejam impressos no meio da análise sintática, no caso daqueles que são checados
durante a sintática (chamada de função, por exemplo);

--ERRO NA CHECAGEM DA ADIÇÃO DOS TIPOS DO PARÂMETROS DE UMA FUNÇÃO
-Ao buscar os tipos, caso só exista um parâmetro e seja uma sum expression, por exemplo, é um nó que contém filhos e portanto a lógica
está errada para ele. Está buscando os tipos dos filhos sendo que os filhos não são outros argumentos. O tipo que deveria ser pego é o tipo do próprio nó; - CORRIGIDO

--Ao adicionar o tipo de uma variável no seu nó, o escopo deve ser levado em consideração para encontrar a declaração da variável; - CORRIGIDO

--Atualizar as buscas de símbolo para utilizar sempre a validação de escopo; Funções criadas, é preciso colocar em todos os locais necessários e
adicionar um tratamento para incluir um erro semântico quando não encontrar o símbolo em um escopo válido. Necessário também verificar se não há um erro do mesmo
tipo já sendo inserido em algum lugar; - CORRIGIDO

--É preciso imprimir a árvore sintática anotada. De certa forma isso facilita outras coisas pois vai ser útil ver os tipos dos nós para debug; - CORRIGIDO

--Corrigir as operações de lista para aceitarem expressões, não só ids; - CORRIGIDO

--Incluir nós de conversão de tipo; - FEITO

--Verificar, nas operações de map e de filter, se a função passada como parâmetro possui o número e o tipo correto de parâmetros; - CORRIGIDO

--Pegar o tipo do construtor de lista - basear nos parâmetros; - FEITO

--Implementar a verificação dos parâmetros em operadores - aritméticos, relacionais, de lista, todos; - FEITO

--Corrigir checagem de passagem de parâmetros para funções - é necessário converter o tipo quando possível e só exibir o erro quando não for possível; - CORRIGIDO

--Pegar tipo correto nos nós com constante NIL, utilizar a expressão que antecede o NIL - olhar na descrição da semântica, NIL é um list de algum tipo; - FEITO

--Operadores unários de lista aplicados em NIL devem gerar erro semântico; - FEITO

-- Operadores binários de lista devem ter um tipo list do lado direito do operador - pode ser NIL (NIL é lista); - FEITO

--Map e filter precisam ter uma função unária como primeiro argumento (esquerda) do operador; - FEITO

--Verificar a semântica do write, writeln e read; - FEITO

--Resolver o problema do ! - como? verificar o tipo do argumento passado para ele. Se for do tipo list, o comportamento muda. O que significa mudar o comportamento?
Basicamente mudar o tipo do nó. TALVEZ mudar também o nome do nó para a expressão de lista; - FEITO

--Adicionar type cast no return caso seja do tipo diferente do retorno da função; - FEITO

--Incluir return no final de toda função, por precaução, pois toda função deve ter um return;

--Adicionar impressão de erro quando não foi possível encontrar uma variável ou função na tabela de símbolos em um escopo válido - talvez colocar direto na função
que faz a busca na tabela seja a melhor forma; - FEITO

--Adicionar nós de conversão de tipo nas operações relacionais - caso esteja comparando um int e um float, o int deve ser convertido

--Erro ao usar o NIL no map ou filter - não está pegando o tipo direito; - CORRIGIDO

--Se declarar uma função dentro de uma função, dá problemas com o lastFuncDeclared; - NÃO É SUPORTADO PELO C, NADA PARA CORRIGIR

*/


#line 172 "./src/syntax.tab.c"

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
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_55_4 = 55,                      /* $@4  */
  YYSYMBOL_parameters = 56,                /* parameters  */
  YYSYMBOL_parameterList = 57,             /* parameterList  */
  YYSYMBOL_parameterSimple = 58,           /* parameterSimple  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_bodyStatement = 60,             /* bodyStatement  */
  YYSYMBOL_localDeclaration = 61,          /* localDeclaration  */
  YYSYMBOL_statementList = 62,             /* statementList  */
  YYSYMBOL_ifStatement = 63,               /* ifStatement  */
  YYSYMBOL_loopStatement = 64,             /* loopStatement  */
  YYSYMBOL_returnStatement = 65,           /* returnStatement  */
  YYSYMBOL_expression = 66,                /* expression  */
  YYSYMBOL_simpleExpression = 67,          /* simpleExpression  */
  YYSYMBOL_logicBinExpression = 68,        /* logicBinExpression  */
  YYSYMBOL_logicUnExpression = 69,         /* logicUnExpression  */
  YYSYMBOL_binExpression = 70,             /* binExpression  */
  YYSYMBOL_sumExpression = 71,             /* sumExpression  */
  YYSYMBOL_mulExpression = 72,             /* mulExpression  */
  YYSYMBOL_sumOP = 73,                     /* sumOP  */
  YYSYMBOL_mulOP = 74,                     /* mulOP  */
  YYSYMBOL_factor = 75,                    /* factor  */
  YYSYMBOL_constant = 76,                  /* constant  */
  YYSYMBOL_functionCall = 77,              /* functionCall  */
  YYSYMBOL_parametersPass = 78,            /* parametersPass  */
  YYSYMBOL_writeOp = 79,                   /* writeOp  */
  YYSYMBOL_write = 80,                     /* write  */
  YYSYMBOL_writeln = 81,                   /* writeln  */
  YYSYMBOL_readOp = 82,                    /* readOp  */
  YYSYMBOL_expressionStatement = 83,       /* expressionStatement  */
  YYSYMBOL_listExpression = 84,            /* listExpression  */
  YYSYMBOL_listAssign = 85,                /* listAssign  */
  YYSYMBOL_listHeader = 86,                /* listHeader  */
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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  355

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
       0,   257,   257,   265,   274,   277,   285,   291,   294,   300,
     324,   367,   371,   367,   407,   419,   407,   455,   459,   465,
     473,   480,   502,   533,   536,   539,   542,   548,   551,   554,
     557,   563,   574,   582,   588,   598,   604,   612,   625,   638,
     652,   671,   682,   693,   710,   716,   731,   741,   758,   764,
     779,   785,   805,   811,   814,   820,   823,   829,   850,   853,
     859,   868,   885,   902,   919,   936,   955,   979,   987,   990,
     996,   999,  1005,  1009,  1021,  1025,  1037,  1060,  1097,  1103,
    1145,  1152,  1180,  1199,  1226,  1232,  1267,  1273,  1308
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
  "funcDeclaration", "$@1", "$@2", "$@3", "$@4", "parameters",
  "parameterList", "parameterSimple", "statement", "bodyStatement",
  "localDeclaration", "statementList", "ifStatement", "loopStatement",
  "returnStatement", "expression", "simpleExpression",
  "logicBinExpression", "logicUnExpression", "binExpression",
  "sumExpression", "mulExpression", "sumOP", "mulOP", "factor", "constant",
  "functionCall", "parametersPass", "writeOp", "write", "writeln",
  "readOp", "expressionStatement", "listExpression", "listAssign",
  "listHeader", "listTailDestructor", "listMap", "listFilter", YY_NULLPTR
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

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3958,  2516,   434,   546,    86,   100,   818,   252,   159,   -26,
     -18,   747,     7,    49,    64,   280,    18,   880,   591,    84,
    2549,  2582,  2615,  2648,  2681,  2714,  2747,  2780,  2813,    15,
      80,    30,    33,     4,    22,   187,   990,  1034,  1350,    83,
      94,   106,   127,  2846,   263,   655,  1396,  1437,   919,  1447,
     747,     3,   -22,   168,  1521,  4232,   524,    36,   880,   747,
     143,   180,   472,   687,  4238,  4267,   176,  2879,  -200,  2916,
    2949,  2982,   159,   280,  1093,  4350,   280,  4365,  4379,   280,
    3015,  3048,   280,   280,   280,   191,    98,   124,  3081,   196,
     179,   209,   207,  3114,   234,   235,   237,   264,   268,  4273,
    3147,  3991,    56,   284,   775,  1041,  1383,  4302,  4308,  4337,
     965,     9,  3180,   279,  4119,   159,   276,   287,   289,   293,
     302,   101,  4024,  3213,   177,   189,   297,   225,   227,     9,
      58,   303,   305,   282,   231,   340,   311,   343,   321,  4148,
    1234,   317,   249,   332,   256,   335,  3250,   334,  3283,   332,
    4148,  3316,  3349,  1542,  4885,  4862,  4892,   331,   880,  4394,
     520,   880,    -4,    11,    40,   238,   376,  4915,  4922,  4945,
     531,   825,  4952,  4975,  5125,  4982,  4444,  4453,  4416,  4481,
     333,   965,  4408,   672,   880,   134,   137,   145,    77,  4775,
    4490,  4518,  4527,  4781,  4787,  4555,  4564,  4747,  4592,  3382,
     350,   352,   747,   591,  3418,  3454,  3490,  3526,   330,   355,
     360,  3562,   215,   370,   378,   747,   591,  1579,  1612,  1645,
    1678,   369,   373,   374,  1711,  4057,  4855,   385,  4090,     3,
    5005,  5012,   105,  5035,  5042,   386,   880,  4394,  4394,  4394,
    4394,  4394,  4394,     3,  4601,  4629,   174,  4638,  4666,   387,
     965,  4408,  4408,  4408,  4408,  4408,  4408,   880,   747,   391,
    3598,  3634,  3670,  3706,   880,   747,   392,  3742,  1744,  1777,
    1810,  1234,   272,  5065,   181,   337,  1514,  5131,  5154,  5072,
    5095,   291,  4675,   175,   389,  4815,  4821,  4827,  4703,  4712,
     393,   395,  3778,  3814,   399,   396,  1843,  1876,   403,  5102,
    4740,  4177,   159,  4119,   159,   122,   409,   410,   747,   591,
    1909,  1945,  1981,  2017,  2053,   404,   412,   414,  2089,   416,
    2126,   417,   880,   747,   418,  3850,  4206,  2159,  2195,  2231,
    1234,  4119,  1234,   425,   421,  2267,  2303,  3886,   429,  2340,
     430,  4177,   159,  4206,  4119,  2373,   428,  3922,  2410,  4177,
    1234,  2443,   435,  4177,  2479
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
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
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
       0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -200,  -200,  -200,   448,   326,  -200,  -200,  -200,  -200,  -200,
     344,  -200,   341,    53,    79,  -200,  -199,   468,   683,   865,
     -11,  1114,  1259,    -6,  1243,  1083,  1052,  -164,  -163,   407,
     470,   622,  -178,  1088,  -200,  -200,  1168,  1217,  1020,   837,
     121,   255,   900,   685
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    89,   143,   113,   149,
     126,   127,   128,    24,    25,   101,    67,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    76,    79,    36,
      37,    38,    87,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,   238,    57,   239,   260,    58,   176,   177,   178,   -11,
     236,   163,   179,    59,   180,   125,    88,   267,   -46,    73,
     181,     2,     3,    56,   252,   -44,   253,     6,   -42,     7,
     182,   183,    74,    75,   184,   -69,   -48,   -48,    61,    85,
     -69,   -18,   -46,   -44,    72,   186,    16,   -44,    92,    17,
     -45,   272,   163,    71,   -46,   237,   163,   163,   -36,   -36,
     -48,   -36,   -36,   -36,   -36,   281,   102,   -36,   -42,   -36,
     -43,   -44,   -46,    70,   -45,   -36,   -36,   139,   -36,   -36,
      62,   -36,   -36,   -36,    68,   -36,   -36,    74,    75,   -36,
     208,   -48,   -48,   -36,   -43,    63,   -57,   -57,   -57,   -57,
     -57,   -57,    50,   221,   186,    52,   132,    53,   133,   -48,
     325,   238,   -57,   239,   -48,   -57,   -57,    51,   -41,   -45,
     252,    80,   253,   -30,   -57,   -30,   -30,   -30,   -30,   147,
     -68,   -30,   -70,   -30,   163,   -68,    64,   -45,   172,   -30,
     -30,   -30,   -30,   -30,   -71,   -30,   -30,   -30,   250,   -30,
     -30,   -44,   232,   -30,   123,   163,   109,   -30,   -30,   -46,
     251,   110,     2,     3,    56,    81,   -42,   130,     6,   -44,
       7,   -42,   195,    90,   -44,   246,     8,   -46,   163,   172,
     204,    93,   -46,   172,   172,    94,    15,    16,   -45,   -43,
      17,   259,   146,   217,   134,   -43,   135,   -50,   -50,    77,
      78,   -50,   -50,   152,   266,   108,   -45,   -43,    99,   -67,
     -14,   -45,   -43,   -43,   -67,   -30,   -30,   112,   -30,   -30,
     -30,   -30,   148,   186,   -30,   -50,   -30,   111,   151,   -40,
     274,   195,   -30,   -30,   -30,   -30,   -30,   186,   -30,   -30,
     -30,   114,   -30,   -30,   283,   115,   -30,   291,    74,    75,
     -30,   163,   -48,   -48,   295,    54,    55,   -17,   163,   -20,
     298,   172,   137,   -21,   -20,   163,   116,   117,   -21,   118,
     -48,    65,   173,   -52,   -52,   -52,   -52,   -52,   -52,   172,
     233,   -22,   172,     2,     3,    56,   -22,   141,   -19,     6,
     315,     7,   221,   -19,    74,    75,   119,   324,   -47,   -47,
     120,   -52,   195,   247,   299,   172,   196,    15,    16,   110,
     129,    17,   334,   173,   -76,   208,   163,   173,   173,   338,
     221,   340,   -47,   300,   163,   -72,   163,   -73,   110,   136,
     315,   -74,   208,   221,   230,   231,   244,   245,   315,   352,
     -75,   140,   315,   225,   163,   142,   -12,    74,    75,   125,
     195,   -47,   -47,   145,   310,   228,   320,   172,   172,   172,
     172,   172,   172,   280,   195,   196,   150,    18,   261,   -47,
     -15,   195,   195,   195,   195,   195,   195,   289,   172,   337,
     311,   257,   217,   258,   339,   172,   -50,   -50,    77,    78,
     -50,   -50,   172,   262,   345,   173,   347,   348,   263,    74,
      75,   264,   351,   -47,   -47,   204,   354,   268,   -50,   265,
     217,   269,   270,   173,   173,   234,   173,   -41,   273,   282,
     311,   -47,   204,   217,   167,   301,   -47,   122,   311,   292,
     296,   303,   311,   302,   304,   -40,   196,   196,   248,   173,
     322,   323,   327,   172,   -61,   -61,   -61,   -61,   -61,   -61,
     328,   172,   329,   172,   330,   332,   335,   341,   190,   342,
     -61,   343,   344,   -61,   -61,   167,   350,   353,    69,   167,
     167,   172,   -61,   138,     0,   153,   154,   155,   144,     0,
      95,   156,     0,   157,   196,     0,     0,   168,     0,   158,
       0,   173,   173,   173,   173,   173,   173,   173,   196,   159,
     160,     0,     0,   161,     0,   196,   196,   196,   196,   196,
     196,   196,   173,     0,     0,     0,     0,   190,     0,   173,
       0,   191,     0,   153,   154,   155,   173,     0,   168,   156,
       0,   157,   168,   168,   -57,   -57,   -57,   -57,   -57,   -57,
       0,   -52,   -52,   -52,   -52,   -52,   -52,   167,   160,     0,
     -57,   161,     0,   -57,   -57,    51,   -63,   -63,   -63,   -63,
     -63,   -63,   -57,   -52,     0,   167,   167,   167,   167,   205,
       0,     0,   -63,     0,     0,   -63,   -63,   173,     0,     0,
     191,     0,   218,     0,   -63,   173,     0,   173,   190,   190,
     190,   167,   -35,     0,   -35,   -35,   -35,   -35,     0,     0,
     -35,     0,   -35,     0,     0,   173,     0,     0,   -35,   -35,
     168,   -35,   -35,     0,   -35,   -35,   -35,     0,   -35,   -35,
       0,     0,   -35,     0,     0,     0,   -35,   -35,   168,   168,
     168,   168,     0,     0,     0,     0,   190,     0,     0,   169,
       0,     0,     0,   167,   167,   167,   167,   167,   167,   167,
     190,   191,   191,   191,   168,     0,     0,   190,   190,   190,
     190,   190,   190,   190,   167,   -78,   -78,   -78,   -78,   -78,
     -78,   167,     0,   192,     0,   176,   177,   178,   167,     0,
     169,   179,     0,   180,   169,   169,     0,     0,     0,     0,
     153,   154,   155,   -78,     0,    97,   156,     0,   157,   191,
     183,     0,   175,   184,   158,     0,   168,   168,   168,   168,
     168,   168,   168,   191,   159,   160,     0,     0,   161,     0,
     191,   191,   191,   191,   191,   191,   191,   168,     0,   167,
       0,     0,   192,     0,   168,     0,   198,   167,     0,   167,
       0,   168,     0,   175,     0,     0,     0,   175,   175,     0,
       2,     3,     4,     0,     0,     0,     6,   167,     7,     0,
       0,     0,   169,     0,     8,     0,     0,     0,   107,   312,
       0,   218,     0,     0,    15,    16,     0,     0,    17,     0,
     169,   169,   169,   169,   206,   -49,   -49,    77,    78,   -49,
     -49,     0,   168,     0,   205,   198,     0,   219,     0,   218,
     168,     0,   168,   192,   192,   192,   169,     0,     0,   312,
       0,   205,   218,   -49,     0,     0,     0,   312,     0,     0,
     168,   312,     0,     0,     0,   175,     0,     0,   -65,   -65,
     -65,   -65,   -65,   -65,     0,   -78,   -78,   -78,   -78,   -78,
     -78,     0,     0,   175,   -65,     0,   175,   -65,   -65,     0,
       0,   192,     0,     0,   171,     0,   -65,   -78,   169,   169,
     169,   169,   169,   169,   169,   192,   198,     0,     0,   175,
       0,     0,   192,   192,   192,   192,   192,   192,   192,   169,
       0,     0,     0,   153,   154,   155,   169,     0,   194,   156,
       0,   157,     0,   169,     0,   171,     0,   158,     0,   171,
     171,     0,     0,     0,     0,     0,     0,   159,   160,     0,
       0,   161,     0,     0,   198,     0,     0,   174,     0,   106,
       0,   175,   175,   175,   175,   175,   279,     0,   198,   -80,
     -80,   -80,   -80,   -80,   -80,   198,   198,   198,   198,   198,
     288,     0,   175,     0,   169,    82,     0,   194,    83,   175,
       0,   197,   169,     0,   169,     0,   175,   -80,   174,     0,
       0,     0,   174,   174,     0,     0,   207,     0,   176,   177,
     178,     0,   169,     0,   179,     0,   180,   171,     0,   220,
       0,     0,   181,     0,   313,     0,   219,     0,     0,     0,
       0,     0,   182,   183,     0,   171,   184,     0,   171,     0,
     -84,   -84,   -84,   -84,   -84,   -84,     0,   175,     0,   206,
     197,     0,     0,     0,   219,   175,   -84,   175,   194,   -84,
     -84,   171,     0,     0,   313,     0,   206,   219,   -84,     0,
       0,     0,   313,     0,     0,   175,   313,   170,     0,     0,
     174,     0,     0,     0,   -58,   -58,   -58,   -58,   -58,   -58,
       0,   -51,   -51,   -51,   -51,   -51,   -51,     0,   174,     0,
     -58,   174,     0,   -58,   -58,     0,   194,     0,     0,   166,
       0,   193,   -58,   171,   171,   171,   171,   278,   170,   -51,
     194,   197,   170,   170,   174,     0,     0,   194,   194,   194,
     194,   287,     0,     0,   171,     0,   -53,   -53,   -53,   105,
     165,   171,   -53,   189,   -53,     0,     0,     0,   171,     0,
     166,     0,     0,     0,   166,   166,     0,     0,     0,     0,
     -53,   -53,     0,     0,   -53,     0,     0,     0,   104,   197,
     193,    66,     0,     0,   188,     0,   174,   174,   174,   174,
     174,   165,     0,   197,     0,   165,   165,     0,     0,     0,
     197,   197,   197,   197,   197,     0,   103,   174,     0,   171,
     170,     0,   189,     0,   174,    86,   314,   171,   220,   171,
       0,   174,    91,     0,     0,     0,    96,    98,   170,     0,
       0,   170,     0,     0,     0,     0,     0,   171,     0,   209,
       0,   207,   166,   188,     0,     0,   220,     0,     0,     0,
       0,   193,   222,     0,   170,     0,   314,     0,   207,   220,
     166,     0,     0,   166,   314,     0,     0,     0,   314,     0,
       0,     0,   174,   165,   124,     0,     0,     0,     0,   131,
     174,     0,   174,   189,     0,     0,   166,   153,   154,   226,
       0,   165,     0,   156,   165,   157,     0,     0,     0,   193,
     174,   158,     0,     0,   227,     0,   170,   170,   170,   277,
     164,   159,   160,   193,   188,   161,     0,   165,     0,   210,
     193,   193,   193,   286,     0,   235,   162,   170,     0,     0,
       0,   189,   223,     0,   170,     0,     0,     0,   166,   166,
     276,   170,     0,     0,   187,   189,     0,     0,   249,     0,
       0,   164,   189,   189,   285,   164,   164,     0,     0,   166,
     185,     0,   188,     0,     0,     0,   166,   162,   211,   165,
     275,   162,   162,   166,     0,     0,   188,     0,     0,     0,
       0,   224,     0,   188,   284,     0,     0,     0,     0,     0,
     165,     0,   170,    86,     0,     0,     0,   165,     0,     0,
     170,     0,   170,   187,   165,     0,     0,    86,     0,     0,
     -60,   -60,   -60,   -60,   -60,   -60,     0,     0,     0,   185,
     170,   290,     0,     0,   166,     0,   -60,     0,   294,   -60,
     -60,     0,   166,   164,   166,   227,     0,     0,   -60,   316,
       0,   222,     0,   -79,   -79,   -79,   -79,   -79,   -79,   162,
       0,   164,   166,     0,   164,   165,   -88,   -88,   -88,   -88,
     -88,   -88,     0,   165,   209,   165,   319,     0,   321,   222,
     162,   -79,   -88,     0,   187,   -88,   -88,   164,     0,   316,
       0,   209,   222,   165,   -88,     0,   333,   316,     0,     0,
       0,   316,     0,   162,   227,     0,   227,   -82,   -82,   -82,
     -82,   -82,   -82,     0,     0,     0,   346,   -86,   -86,   -86,
     -86,   -86,   -86,   -82,   227,     0,   -82,   -82,     0,   317,
       0,   223,   187,   -86,     0,   -82,   -86,    84,     0,   164,
       0,     0,     0,     0,     0,   -86,   187,     0,   185,     0,
       0,     0,     0,   187,   210,     0,     0,     0,     0,   223,
     164,     0,   185,     0,     0,     0,     0,   164,     0,   317,
       0,   210,   223,     0,   164,     0,   162,   317,   318,     0,
     224,   317,     0,   162,   -49,   -49,    77,    78,   -49,   -49,
     162,   -62,   -62,   -62,   -62,   -62,   -62,     0,     0,     0,
       0,     0,     0,   211,     0,     0,   -49,   -62,   224,     0,
     -62,   -62,   -61,   -61,   -61,   -61,   -61,   -61,   318,   -62,
     211,   224,     0,     0,     0,   164,   318,     0,   -61,     0,
     318,   -61,   -61,   164,   -61,   164,     0,     0,     0,   -23,
     -23,   162,   -23,   -23,   -23,   -23,     0,     0,   -23,   162,
     -23,   162,     0,   164,     0,     0,   -23,   -23,   -23,   -23,
     -23,     0,   -23,   -23,   -23,     0,   -23,   -23,     0,   162,
     -23,     0,   -24,   -24,   -23,   -24,   -24,   -24,   -24,     0,
       0,   -24,     0,   -24,     0,     0,     0,     0,     0,   -24,
     -24,   -24,   -24,   -24,     0,   -24,   -24,   -24,     0,   -24,
     -24,     0,     0,   -24,     0,   -25,   -25,   -24,   -25,   -25,
     -25,   -25,     0,     0,   -25,     0,   -25,     0,     0,     0,
       0,     0,   -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,
     -25,     0,   -25,   -25,     0,     0,   -25,     0,   -26,   -26,
     -25,   -26,   -26,   -26,   -26,     0,     0,   -26,     0,   -26,
       0,     0,     0,     0,     0,   -26,   -26,   -26,   -26,   -26,
       0,   -26,   -26,   -26,     0,   -26,   -26,     0,     0,   -26,
       0,   -29,   -29,   -26,   -29,   -29,   -29,   -29,     0,     0,
     -29,     0,   -29,     0,     0,     0,     0,     0,   -29,   -29,
     -29,   -29,   -29,     0,   -29,   -29,   -29,     0,   -29,   -29,
       0,     0,   -29,     0,   -77,   -77,   -29,   -77,   -77,   -77,
     -77,     0,     0,   -77,     0,   -77,     0,     0,     0,     0,
       0,   -77,   -77,   -77,   -77,   -77,     0,   -77,   -77,   -77,
       0,   -77,   -77,     0,     0,   -77,     0,   -27,   -27,   -77,
     -27,   -27,   -27,   -27,     0,     0,   -27,     0,   -27,     0,
       0,     0,     0,     0,   -27,   -27,   -27,   -27,   -27,     0,
     -27,   -27,   -27,     0,   -27,   -27,     0,     0,   -27,     0,
     -28,   -28,   -27,   -28,   -28,   -28,   -28,     0,     0,   -28,
       0,   -28,     0,     0,     0,     0,     0,   -28,   -28,   -28,
     -28,   -28,     0,   -28,   -28,   -28,     0,   -28,   -28,     0,
       0,   -28,     0,   -39,   -39,   -28,   -39,   -39,   -39,   -39,
       0,     0,   -39,     0,   -39,     0,     0,     0,     0,     0,
     -39,   -39,   -39,   -39,   -39,     0,   -39,   -39,   -39,     0,
     -39,   -39,     0,     0,   -39,     0,   -31,   -31,   -39,   -31,
     -31,   -31,   -31,     0,     0,   -31,     0,   -31,     0,     0,
       0,     0,     0,   -31,   -31,   -31,   -31,   -31,     0,   -31,
     -31,   -31,     0,   -31,   -31,     0,     0,   -31,     0,     0,
     -36,   -31,   -36,   -36,   -36,   -36,     0,     0,   -36,     0,
     -36,     0,     0,     0,     0,     0,   -36,   -36,   326,   -36,
     -36,     0,   -36,   -36,   -36,     0,   -36,   -36,     0,     0,
     -36,     0,     0,     0,   -36,   -36,   -23,     0,   -23,   -23,
     -23,   -23,     0,     0,   -23,     0,   -23,     0,     0,     0,
       0,     0,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,
     -23,     0,   -23,   -23,     0,     0,   -23,     0,     0,     0,
     -23,   -23,   -24,     0,   -24,   -24,   -24,   -24,     0,     0,
     -24,     0,   -24,     0,     0,     0,     0,     0,   -24,   -24,
     -24,   -24,   -24,     0,   -24,   -24,   -24,     0,   -24,   -24,
       0,     0,   -24,     0,     0,     0,   -24,   -24,   -25,     0,
     -25,   -25,   -25,   -25,     0,     0,   -25,     0,   -25,     0,
       0,     0,     0,     0,   -25,   -25,   -25,   -25,   -25,     0,
     -25,   -25,   -25,     0,   -25,   -25,     0,     0,   -25,     0,
       0,     0,   -25,   -25,   -26,     0,   -26,   -26,   -26,   -26,
       0,     0,   -26,     0,   -26,     0,     0,     0,     0,     0,
     -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,     0,
     -26,   -26,     0,     0,   -26,     0,     0,     0,   -26,   -26,
     -29,     0,   -29,   -29,   -29,   -29,     0,     0,   -29,     0,
     -29,     0,     0,     0,     0,     0,   -29,   -29,   -29,   -29,
     -29,     0,   -29,   -29,   -29,     0,   -29,   -29,     0,     0,
     -29,     0,     0,     0,   -29,   -29,   -36,   -36,     0,   -36,
     -36,   -36,   -36,     0,     0,   -36,     0,   -36,     0,     0,
       0,     0,     0,   -36,   -36,   331,   -36,   -36,     0,   -36,
     -36,   -36,     0,   -36,   -36,     0,     0,   -36,     0,     0,
     -77,   -36,   -77,   -77,   -77,   -77,     0,     0,   -77,     0,
     -77,     0,     0,     0,     0,     0,   -77,   -77,   -77,   -77,
     -77,     0,   -77,   -77,   -77,     0,   -77,   -77,     0,     0,
     -77,     0,     0,     0,   -77,   -77,   -27,     0,   -27,   -27,
     -27,   -27,     0,     0,   -27,     0,   -27,     0,     0,     0,
       0,     0,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,
     -27,     0,   -27,   -27,     0,     0,   -27,     0,     0,     0,
     -27,   -27,   -28,     0,   -28,   -28,   -28,   -28,     0,     0,
     -28,     0,   -28,     0,     0,     0,     0,     0,   -28,   -28,
     -28,   -28,   -28,     0,   -28,   -28,   -28,     0,   -28,   -28,
       0,     0,   -28,     0,     0,     0,   -28,   -28,   -39,     0,
     -39,   -39,   -39,   -39,     0,     0,   -39,     0,   -39,     0,
       0,     0,     0,     0,   -39,   -39,   -39,   -39,   -39,     0,
     -39,   -39,   -39,     0,   -39,   -39,     0,     0,   -39,     0,
       0,     0,   -39,   -39,   -31,     0,   -31,   -31,   -31,   -31,
       0,     0,   -31,     0,   -31,     0,     0,     0,     0,     0,
     -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,   -31,     0,
     -31,   -31,     0,     0,   -31,     0,     0,     0,   -31,   -31,
     -37,   -37,     0,   -37,   -37,   -37,   -37,     0,     0,   -37,
       0,   -37,     0,     0,     0,     0,     0,   -37,   -37,   -37,
     -37,   -37,     0,   -37,   -37,   -37,     0,   -37,   -37,     0,
       0,   -37,     0,     0,   -36,   -37,   -36,   -36,   -36,   -36,
       0,     0,   -36,     0,   -36,     0,     0,     0,     0,     0,
     -36,   -36,   349,   -36,   -36,     0,   -36,   -36,   -36,     0,
     -36,   -36,     0,     0,   -36,     0,     0,     0,   -36,   -36,
     -38,   -38,     0,   -38,   -38,   -38,   -38,     0,     0,   -38,
       0,   -38,     0,     0,     0,     0,     0,   -38,   -38,   -38,
     -38,   -38,     0,   -38,   -38,   -38,     0,   -38,   -38,     0,
       0,   -38,     0,     0,   -37,   -38,   -37,   -37,   -37,   -37,
       0,     0,   -37,     0,   -37,     0,     0,     0,     0,     0,
     -37,   -37,   -37,   -37,   -37,     0,   -37,   -37,   -37,     0,
     -37,   -37,     0,     0,   -37,     0,     0,     0,   -37,   -37,
     -38,     0,   -38,   -38,   -38,   -38,     0,     0,   -38,     0,
     -38,     0,     0,     0,     0,     0,   -38,   -38,   -38,   -38,
     -38,     0,   -38,   -38,   -38,     0,   -38,   -38,     0,     0,
     -38,     0,     0,     0,   -38,   -38,   -30,   -30,     0,   -30,
     -30,   -30,   -30,     0,     0,   -30,     0,   -30,     0,     0,
       0,     0,     0,   -30,   -30,     0,   -30,   -30,     0,   -30,
     -30,   -30,     0,   -30,   -30,     0,     0,   -30,     0,    -2,
       1,   -30,     2,     3,     4,     5,     0,     0,     6,     0,
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
       0,     0,    -6,     0,   -23,   -23,    -6,   -23,   -23,   -23,
     -23,     0,     0,   -23,     0,   -23,     0,     0,     0,     0,
       0,   -23,   -23,     0,   -23,   -23,     0,   -23,   -23,   -23,
       0,   -23,   -23,     0,     0,   -23,     0,   -24,   -24,   -23,
     -24,   -24,   -24,   -24,     0,     0,   -24,     0,   -24,     0,
       0,     0,     0,     0,   -24,   -24,     0,   -24,   -24,     0,
     -24,   -24,   -24,     0,   -24,   -24,     0,     0,   -24,     0,
     -25,   -25,   -24,   -25,   -25,   -25,   -25,     0,     0,   -25,
       0,   -25,     0,     0,     0,     0,     0,   -25,   -25,     0,
     -25,   -25,     0,   -25,   -25,   -25,     0,   -25,   -25,     0,
       0,   -25,     0,   -26,   -26,   -25,   -26,   -26,   -26,   -26,
       0,     0,   -26,     0,   -26,     0,     0,     0,     0,     0,
     -26,   -26,     0,   -26,   -26,     0,   -26,   -26,   -26,     0,
     -26,   -26,     0,     0,   -26,     0,   -29,   -29,   -26,   -29,
     -29,   -29,   -29,     0,     0,   -29,     0,   -29,     0,     0,
       0,     0,     0,   -29,   -29,     0,   -29,   -29,     0,   -29,
     -29,   -29,     0,   -29,   -29,     0,     0,   -29,     0,     0,
     -33,   -29,   -33,   -33,   -33,   -33,     0,     0,   -33,     0,
     -33,     0,     0,     0,     0,     0,   -33,   -33,     0,   -33,
     -33,     0,   -33,   -33,   -33,     0,   -33,   -33,     0,     0,
     -33,     0,     0,     0,   -33,   100,    -3,    -3,     0,    -3,
      -3,    -3,    -3,     0,     0,    -3,     0,    -3,     0,     0,
       0,     0,     0,    -3,    -3,     0,    -3,    -3,     0,    -3,
      -3,    -3,     0,    -3,    -3,     0,     0,    -3,     0,    -5,
      -5,    -3,    -5,    -5,    -5,    -5,     0,     0,    -5,     0,
      -5,     0,     0,     0,     0,     0,    -5,    -5,     0,    -5,
      -5,     0,    -5,    -5,    -5,     0,    -5,    -5,     0,     0,
      -5,     0,   -77,   -77,    -5,   -77,   -77,   -77,   -77,     0,
       0,   -77,     0,   -77,     0,     0,     0,     0,     0,   -77,
     -77,     0,   -77,   -77,     0,   -77,   -77,   -77,     0,   -77,
     -77,     0,     0,   -77,     0,   -27,   -27,   -77,   -27,   -27,
     -27,   -27,     0,     0,   -27,     0,   -27,     0,     0,     0,
       0,     0,   -27,   -27,     0,   -27,   -27,     0,   -27,   -27,
     -27,     0,   -27,   -27,     0,     0,   -27,     0,   -28,   -28,
     -27,   -28,   -28,   -28,   -28,     0,     0,   -28,     0,   -28,
       0,     0,     0,     0,     0,   -28,   -28,     0,   -28,   -28,
       0,   -28,   -28,   -28,     0,   -28,   -28,     0,     0,   -28,
       0,    -9,    -9,   -28,    -9,    -9,    -9,    -9,     0,     0,
      -9,     0,    -9,     0,     0,     0,     0,     0,    -9,    -9,
       0,    -9,    -9,     0,    -9,    -9,    -9,     0,    -9,    -9,
       0,     0,    -9,     0,   -39,   -39,    -9,   -39,   -39,   -39,
     -39,     0,     0,   -39,     0,   -39,     0,     0,     0,     0,
       0,   -39,   -39,     0,   -39,   -39,     0,   -39,   -39,   -39,
       0,   -39,   -39,     0,     0,   -39,     0,   -31,   -31,   -39,
     -31,   -31,   -31,   -31,     0,     0,   -31,     0,   -31,     0,
       0,     0,     0,     0,   -31,   -31,     0,   -31,   -31,     0,
     -31,   -31,   -31,     0,   -31,   -31,     0,     0,   -31,     0,
     -10,   -10,   -31,   -10,   -10,   -10,   -10,     0,     0,   -10,
       0,   -10,     0,     0,     0,     0,     0,   -10,   -10,     0,
     -10,   -10,     0,   -10,   -10,   -10,     0,   -10,   -10,     0,
       0,   -10,     0,     0,   -34,   -10,   -34,   -34,   -34,   -34,
       0,     0,   -34,     0,   -34,     0,     0,     0,     0,     0,
     -34,   -34,     0,   -34,   -34,     0,   -34,   -34,   -34,     0,
     -34,   -34,     0,     0,   -34,     0,     0,     0,   -34,   -34,
     -37,   -37,     0,   -37,   -37,   -37,   -37,     0,     0,   -37,
       0,   -37,     0,     0,     0,     0,     0,   -37,   -37,     0,
     -37,   -37,     0,   -37,   -37,   -37,     0,   -37,   -37,     0,
       0,   -37,     0,   -13,   -13,   -37,   -13,   -13,   -13,   -13,
       0,     0,   -13,     0,   -13,     0,     0,     0,     0,     0,
     -13,   -13,     0,   -13,   -13,     0,   -13,   -13,   -13,     0,
     -13,   -13,     0,     0,   -13,     0,   -16,   -16,   -13,   -16,
     -16,   -16,   -16,     0,     0,   -16,     0,   -16,     0,     0,
       0,     0,     0,   -16,   -16,     0,   -16,   -16,     0,   -16,
     -16,   -16,     0,   -16,   -16,     0,     0,   -16,     0,   -38,
     -38,   -16,   -38,   -38,   -38,   -38,     0,     0,   -38,     0,
     -38,     0,     0,     0,     0,     0,   -38,   -38,     0,   -38,
     -38,     0,   -38,   -38,   -38,     0,   -38,   -38,     0,     0,
     -38,     0,     0,   -30,   -38,   -30,   -30,   -30,   -30,     0,
       0,   -30,     0,   -30,     0,     0,     0,     0,     0,   -30,
     -30,     0,   -30,   -30,     0,   -30,   -30,   -30,     0,   -30,
     -30,     0,     0,   -30,     0,     0,     0,   -30,   -30,   -23,
       0,   -23,   -23,   -23,   -23,     0,     0,   -23,     0,   -23,
       0,     0,     0,     0,     0,   -23,   -23,     0,   -23,   -23,
       0,   -23,   -23,   -23,     0,   -23,   -23,     0,     0,   -23,
       0,     0,     0,   -23,   -23,   -24,     0,   -24,   -24,   -24,
     -24,     0,     0,   -24,     0,   -24,     0,     0,     0,     0,
       0,   -24,   -24,     0,   -24,   -24,     0,   -24,   -24,   -24,
       0,   -24,   -24,     0,     0,   -24,     0,     0,     0,   -24,
     -24,   -25,     0,   -25,   -25,   -25,   -25,     0,     0,   -25,
       0,   -25,     0,     0,     0,     0,     0,   -25,   -25,     0,
     -25,   -25,     0,   -25,   -25,   -25,     0,   -25,   -25,     0,
       0,   -25,     0,     0,     0,   -25,   -25,   -26,     0,   -26,
     -26,   -26,   -26,     0,     0,   -26,     0,   -26,     0,     0,
       0,     0,     0,   -26,   -26,     0,   -26,   -26,     0,   -26,
     -26,   -26,     0,   -26,   -26,     0,     0,   -26,     0,     0,
       0,   -26,   -26,   -29,     0,   -29,   -29,   -29,   -29,     0,
       0,   -29,     0,   -29,     0,     0,     0,     0,     0,   -29,
     -29,     0,   -29,   -29,     0,   -29,   -29,   -29,     0,   -29,
     -29,     0,     0,   -29,     0,     0,     0,   -29,   -29,   -33,
       0,   -33,   -33,   -33,   -33,     0,     0,   -33,     0,   -33,
       0,     0,     0,     0,     0,   -33,   -33,     0,   -33,   -33,
       0,   -33,   -33,   -33,     0,   -33,   -33,     0,     0,   -33,
       0,     0,     0,   -33,   293,   -77,     0,   -77,   -77,   -77,
     -77,     0,     0,   -77,     0,   -77,     0,     0,     0,     0,
       0,   -77,   -77,     0,   -77,   -77,     0,   -77,   -77,   -77,
       0,   -77,   -77,     0,     0,   -77,     0,     0,     0,   -77,
     -77,   -27,     0,   -27,   -27,   -27,   -27,     0,     0,   -27,
       0,   -27,     0,     0,     0,     0,     0,   -27,   -27,     0,
     -27,   -27,     0,   -27,   -27,   -27,     0,   -27,   -27,     0,
       0,   -27,     0,     0,     0,   -27,   -27,   -28,     0,   -28,
     -28,   -28,   -28,     0,     0,   -28,     0,   -28,     0,     0,
       0,     0,     0,   -28,   -28,     0,   -28,   -28,     0,   -28,
     -28,   -28,     0,   -28,   -28,     0,     0,   -28,     0,     0,
       0,   -28,   -28,   -33,     0,   -33,   -33,   -33,   -33,     0,
       0,   -33,     0,   -33,     0,     0,     0,     0,     0,   -33,
     -33,     0,   -33,   -33,     0,   -33,   -33,   -33,     0,   -33,
     -33,     0,     0,   -33,     0,     0,     0,   -33,   297,   -39,
       0,   -39,   -39,   -39,   -39,     0,     0,   -39,     0,   -39,
       0,     0,     0,     0,     0,   -39,   -39,     0,   -39,   -39,
       0,   -39,   -39,   -39,     0,   -39,   -39,     0,     0,   -39,
       0,     0,     0,   -39,   -39,   -31,     0,   -31,   -31,   -31,
     -31,     0,     0,   -31,     0,   -31,     0,     0,     0,     0,
       0,   -31,   -31,     0,   -31,   -31,     0,   -31,   -31,   -31,
       0,   -31,   -31,     0,     0,   -31,     0,     0,     0,   -31,
     -31,   -33,     0,   -33,   -33,   -33,   -33,     0,     0,   -33,
       0,   -33,     0,     0,     0,     0,     0,   -33,   -33,     0,
     -33,   -33,     0,   -33,   -33,   -33,     0,   -33,   -33,     0,
       0,   -33,     0,     0,     0,   -33,   336,   -37,     0,   -37,
     -37,   -37,   -37,     0,     0,   -37,     0,   -37,     0,     0,
       0,     0,     0,   -37,   -37,     0,   -37,   -37,     0,   -37,
     -37,   -37,     0,   -37,   -37,     0,     0,   -37,     0,     0,
       0,   -37,   -37,   -38,     0,   -38,   -38,   -38,   -38,     0,
       0,   -38,     0,   -38,     0,     0,     0,     0,     0,   -38,
     -38,     0,   -38,   -38,     0,   -38,   -38,   -38,     0,   -38,
     -38,     0,     0,   -38,     0,     0,     0,   -38,   -38,     1,
       0,     2,     3,     4,     5,     0,     0,     6,     0,     7,
       0,     0,     0,     0,     0,     8,     9,     0,    10,    11,
       0,    12,    13,    14,     0,    15,    16,     0,     0,    17,
       0,     0,   199,    18,     2,     3,     4,   121,     0,     0,
       6,     0,     7,     0,     0,     0,     0,     0,     8,   200,
       0,   201,   202,     0,    12,    13,    14,     0,    15,    16,
       0,     0,    17,     0,     0,   -32,   203,   -32,   -32,   -32,
     -32,     0,     0,   -32,     0,   -32,     0,     0,     0,     0,
       0,   -32,   -32,     0,   -32,   -32,     0,   -32,   -32,   -32,
       0,   -32,   -32,     0,     0,   -32,     0,     0,    -9,   -32,
      -9,    -9,    -9,    -9,     0,     0,    -9,     0,    -9,     0,
       0,     0,     0,     0,    -9,    -9,     0,    -9,    -9,     0,
      -9,    -9,    -9,     0,    -9,    -9,     0,     0,    -9,     0,
       0,   -10,    -9,   -10,   -10,   -10,   -10,     0,     0,   -10,
       0,   -10,     0,     0,     0,     0,     0,   -10,   -10,     0,
     -10,   -10,     0,   -10,   -10,   -10,     0,   -10,   -10,     0,
     212,   -10,     2,     3,     4,   -10,     0,     0,     6,     0,
       7,     0,     0,     0,     0,     0,     8,   213,     0,   214,
     215,     0,    12,    13,    14,     0,    15,    16,     0,     1,
      17,     2,     3,     4,   216,     0,     0,     6,     0,     7,
       0,     0,     0,     0,     0,     8,     9,     0,    10,    11,
       0,    12,    13,    14,     0,    15,    16,     0,   305,    17,
       2,     3,     4,    18,     0,     0,     6,     0,     7,     0,
       0,     0,     0,     0,     8,   306,     0,   307,   308,     0,
      12,    13,    14,     0,    15,    16,     0,   199,    17,     2,
       3,     4,   309,     0,     0,     6,     0,     7,     0,     0,
       0,     0,     0,     8,   200,     0,   201,   202,     0,    12,
      13,    14,     0,    15,    16,     0,     0,    17,     0,     0,
       0,   203,   -64,   -64,   -64,   -64,   -64,   -64,   -81,   -81,
     -81,   -81,   -81,   -81,     0,     0,     0,     0,   -64,     0,
       0,   -64,   -64,     0,   -81,     0,     0,   -81,   -81,     0,
     -64,     0,     0,     0,     0,     0,   -81,   -83,   -83,   -83,
     -83,   -83,   -83,   -59,   -59,   -59,   -59,   -59,   -59,     0,
       0,     0,     0,   -83,     0,     0,   -83,   -83,     0,   -59,
       0,     0,   -59,   -59,     0,   -83,     0,     0,     0,     0,
       0,   -59,   -85,   -85,   -85,   -85,   -85,   -85,   -87,   -87,
     -87,   -87,   -87,   -87,     0,     0,     0,     0,   -85,     0,
       0,   -85,    84,     0,   -87,     0,     0,   -87,   -87,     0,
     -85,     0,     0,     0,     0,     0,   -87,   -66,   -66,   -66,
     -66,   -66,   -66,   -54,   -54,   -54,     0,     0,     0,   -54,
       0,   -54,     0,   -66,     0,     0,   -66,   -66,   -56,   -56,
     -56,     0,     0,     0,   -56,   -66,   -56,   -54,   -54,     0,
       0,   -54,   -55,   -55,   -55,     0,     0,     0,   -55,     0,
     -55,     0,   -56,   -56,     0,     0,   -56,   153,   154,   155,
       0,     0,     0,   156,     0,   157,   -55,   -55,     0,     0,
     -55,   176,   177,   178,     0,     0,     0,   179,     0,   180,
       0,   159,   160,     0,     0,   161,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,   182,   183,     0,     0,   184,
       0,     0,   -57,     0,     0,   -57,   -57,   243,   -57,     0,
       0,     0,     0,   -57,   -61,   -61,   -61,   -61,   -61,   -61,
       0,     0,     0,   -63,   -63,   -63,   -63,   -63,   -63,     0,
     -61,     0,     0,   -61,   -61,     0,   -61,     0,     0,   -63,
       0,   -61,   -63,   -63,     0,   -63,     0,     0,     0,     0,
     -63,   -65,   -65,   -65,   -65,   -65,   -65,     0,     0,     0,
     -84,   -84,   -84,   -84,   -84,   -84,     0,   -65,     0,     0,
     -65,   -65,     0,   -65,     0,     0,   -84,     0,   -65,   -84,
     -84,     0,   -84,     0,     0,     0,     0,   -84,   -58,   -58,
     -58,   -58,   -58,   -58,     0,     0,     0,   -60,   -60,   -60,
     -60,   -60,   -60,     0,   -58,     0,     0,   -58,   -58,     0,
     -58,     0,     0,   -60,     0,   -58,   -60,   -60,     0,   -60,
       0,     0,     0,     0,   -60,   -88,   -88,   -88,   -88,   -88,
     -88,     0,     0,     0,   -82,   -82,   -82,   -82,   -82,   -82,
       0,   -88,     0,     0,   -88,   -88,     0,   -88,     0,     0,
     -82,     0,   -88,   -82,   -82,     0,   -82,     0,     0,     0,
       0,   -82,   -86,   -86,   -86,   -86,   -86,   -86,     0,     0,
       0,   -62,   -62,   -62,   -62,   -62,   -62,     0,   -86,     0,
       0,   -86,   256,     0,   -86,     0,     0,   -62,     0,   -86,
     -62,   -62,     0,   -62,     0,     0,     0,     0,   -62,   -64,
     -64,   -64,   -64,   -64,   -64,     0,     0,     0,   -81,   -81,
     -81,   -81,   -81,   -81,     0,   -64,     0,     0,   -64,   -64,
       0,   -64,     0,     0,   -81,     0,   -64,   -81,   -81,     0,
     -81,     0,     0,     0,     0,   -81,   -83,   -83,   -83,   -83,
     -83,   -83,     0,     0,     0,   -59,   -59,   -59,   -59,   -59,
     -59,     0,   -83,     0,     0,   -83,   -83,     0,   -83,     0,
       0,   -59,     0,   -83,   -59,   -59,     0,   -59,     0,     0,
       0,     0,   -59,   -85,   -85,   -85,   -85,   -85,   -85,     0,
       0,     0,   -87,   -87,   -87,   -87,   -87,   -87,     0,   -85,
       0,     0,   -85,   256,     0,   -85,     0,     0,   -87,     0,
     -85,   -87,   -87,     0,   -87,     0,     0,     0,     0,   -87,
     -66,   -66,   -66,   -66,   -66,   -66,     0,   -80,   -80,   -80,
     -80,   -80,   -80,     0,     0,     0,   -66,     0,     0,   -66,
     -66,     0,   -66,   254,     0,     0,   255,   -66,     0,   -80,
       0,     0,     0,     0,   -80,   -50,   -50,    77,    78,   -50,
     -50,   -52,   -52,   -52,   -52,   -52,   -52,   -78,   -78,   -78,
     -78,   -78,   -78,     0,     0,     0,     0,   -50,     0,     0,
       0,     0,   -50,   -52,     0,     0,     0,     0,   -52,   -78,
       0,     0,     0,     0,   -78,   -49,   -49,    77,    78,   -49,
     -49,   -51,   -51,   -51,   -51,   -51,   -51,   -79,   -79,   -79,
     -79,   -79,   -79,     0,     0,     0,     0,   -49,     0,     0,
       0,     0,   -49,   -51,     0,     0,     0,     0,   -51,   -79,
       0,     0,     0,     0,   -79,   -57,   -57,   -57,   -57,   -57,
     -57,   271,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
       0,   -57,     0,     0,   -57,   -57,   229,   -57,   -57,     0,
       0,   -57,   -57,   229,   -57,   -63,   -63,   -63,   -63,   -63,
     -63,     0,   -65,   -65,   -65,   -65,   -65,   -65,     0,     0,
       0,   -63,     0,     0,   -63,   -63,     0,   -63,   -65,     0,
       0,   -65,   -65,     0,   -65,   -84,   -84,   -84,   -84,   -84,
     -84,     0,   -58,   -58,   -58,   -58,   -58,   -58,     0,     0,
       0,   -84,     0,     0,   -84,   -84,     0,   -84,   -58,     0,
       0,   -58,   -58,     0,   -58,   -60,   -60,   -60,   -60,   -60,
     -60,     0,   -88,   -88,   -88,   -88,   -88,   -88,     0,     0,
       0,   -60,     0,     0,   -60,   -60,     0,   -60,   -88,     0,
       0,   -88,   -88,     0,   -88,   -82,   -82,   -82,   -82,   -82,
     -82,     0,   -86,   -86,   -86,   -86,   -86,   -86,     0,     0,
       0,   -82,     0,     0,   -82,   -82,     0,   -82,   -86,     0,
       0,   -86,   242,     0,   -86,   -62,   -62,   -62,   -62,   -62,
     -62,     0,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,
       0,   -62,     0,     0,   -62,   -62,     0,   -62,   -64,     0,
       0,   -64,   -64,     0,   -64,   -81,   -81,   -81,   -81,   -81,
     -81,     0,   -83,   -83,   -83,   -83,   -83,   -83,     0,     0,
       0,   -81,     0,     0,   -81,   -81,     0,   -81,   -83,     0,
       0,   -83,   -83,     0,   -83,   -59,   -59,   -59,   -59,   -59,
     -59,     0,   -85,   -85,   -85,   -85,   -85,   -85,     0,     0,
       0,   -59,     0,     0,   -59,   -59,     0,   -59,   -85,     0,
       0,   -85,   242,     0,   -85,   -87,   -87,   -87,   -87,   -87,
     -87,     0,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,
       0,   -87,     0,     0,   -87,   -87,     0,   -87,   -66,     0,
       0,   -66,   -66,     0,   -66,   -80,   -80,   -80,   -80,   -80,
     -80,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,     0,
       0,   240,     0,     0,   241,     0,     0,   -80,     0,     0,
       0,     0,     0,   -51,   -79,   -79,   -79,   -79,   -79,   -79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -79
};

static const yytype_int16 yycheck[] =
{
      11,   165,     8,   166,   203,    31,     3,     4,     5,    31,
      14,    17,     9,    31,    11,     6,    38,   216,    14,    15,
      17,     3,     4,     5,   188,    14,   189,     9,    32,    11,
      27,    28,    10,    11,    31,    32,    14,    15,    31,    50,
      37,    32,    38,    32,    14,    51,    28,    14,    59,    31,
      14,   229,    58,    38,    14,    15,    62,    63,     0,     1,
      38,     3,     4,     5,     6,   243,    72,     9,    38,    11,
      14,    38,    32,    20,    38,    17,    18,    19,    20,    21,
      31,    23,    24,    25,     0,    27,    28,    10,    11,    31,
     101,    14,    15,    35,    38,    31,    10,    11,    12,    13,
      14,    15,    16,   114,   110,     5,     5,     7,     7,    32,
     309,   275,    26,   276,    37,    29,    30,    31,    38,    14,
     284,    38,   285,     1,    38,     3,     4,     5,     6,   140,
      32,     9,    38,    11,   140,    37,    15,    32,    17,    17,
      18,    19,    20,    21,    38,    23,    24,    25,    14,    27,
      28,    14,   158,    31,   101,   161,    32,    35,    36,    14,
      15,    37,     3,     4,     5,    38,    32,   114,     9,    32,
      11,    37,    51,     5,    37,   181,    17,    32,   184,    58,
     101,    38,    37,    62,    63,     5,    27,    28,    14,    14,
      31,   202,   139,   114,     5,    14,     7,    10,    11,    12,
      13,    14,    15,   150,   215,    84,    32,    32,    32,    32,
      31,    37,    37,    32,    37,     0,     1,    38,     3,     4,
       5,     6,   143,   229,     9,    38,    11,    31,   149,    38,
     236,   110,    17,    18,    19,    20,    21,   243,    23,    24,
      25,    32,    27,    28,   250,    38,    31,   258,    10,    11,
      35,   257,    14,    15,   265,     3,     4,    32,   264,    32,
     271,   140,    37,    32,    37,   271,    32,    32,    37,    32,
      32,    16,    17,    10,    11,    12,    13,    14,    15,   158,
     159,    32,   161,     3,     4,     5,    37,     5,    32,     9,
     301,    11,   303,    37,    10,    11,    32,   308,    14,    15,
      32,    38,   181,   182,    32,   184,    51,    27,    28,    37,
      31,    31,   323,    58,    38,   326,   322,    62,    63,   330,
     331,   332,    38,    32,   330,    38,   332,    38,    37,    32,
     341,    38,   343,   344,     3,     4,     3,     4,   349,   350,
      38,    38,   353,    38,   350,     5,    35,    10,    11,     6,
     229,    14,    15,    32,   301,    38,   303,   236,   237,   238,
     239,   240,   241,   242,   243,   110,    32,    35,    38,    32,
      35,   250,   251,   252,   253,   254,   255,   256,   257,   326,
     301,    31,   303,    31,   331,   264,    10,    11,    12,    13,
      14,    15,   271,    38,   341,   140,   343,   344,    38,    10,
      11,    31,   349,    14,    15,   326,   353,    38,    32,    31,
     331,    38,    38,   158,   159,   160,   161,    32,    32,    32,
     341,    32,   343,   344,    17,    32,    37,   101,   349,    38,
      38,    32,   353,    38,    38,    32,   181,   182,   183,   184,
      31,    31,    38,   322,    10,    11,    12,    13,    14,    15,
      38,   330,    38,   332,    38,    38,    38,    32,    51,    38,
      26,    32,    32,    29,    30,    58,    38,    32,    20,    62,
      63,   350,    38,   129,    -1,     3,     4,     5,   137,    -1,
       8,     9,    -1,    11,   229,    -1,    -1,    17,    -1,    17,
      -1,   236,   237,   238,   239,   240,   241,   242,   243,    27,
      28,    -1,    -1,    31,    -1,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   110,    -1,   264,
      -1,    51,    -1,     3,     4,     5,   271,    -1,    58,     9,
      -1,    11,    62,    63,    10,    11,    12,    13,    14,    15,
      -1,    10,    11,    12,    13,    14,    15,   140,    28,    -1,
      26,    31,    -1,    29,    30,    31,    10,    11,    12,    13,
      14,    15,    38,    32,    -1,   158,   159,   160,   161,   101,
      -1,    -1,    26,    -1,    -1,    29,    30,   322,    -1,    -1,
     110,    -1,   114,    -1,    38,   330,    -1,   332,   181,   182,
     183,   184,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    11,    -1,    -1,   350,    -1,    -1,    17,    18,
     140,    20,    21,    -1,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   229,    -1,    -1,    17,
      -1,    -1,    -1,   236,   237,   238,   239,   240,   241,   242,
     243,   181,   182,   183,   184,    -1,    -1,   250,   251,   252,
     253,   254,   255,   256,   257,    10,    11,    12,    13,    14,
      15,   264,    -1,    51,    -1,     3,     4,     5,   271,    -1,
      58,     9,    -1,    11,    62,    63,    -1,    -1,    -1,    -1,
       3,     4,     5,    38,    -1,     8,     9,    -1,    11,   229,
      28,    -1,    17,    31,    17,    -1,   236,   237,   238,   239,
     240,   241,   242,   243,    27,    28,    -1,    -1,    31,    -1,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   322,
      -1,    -1,   110,    -1,   264,    -1,    51,   330,    -1,   332,
      -1,   271,    -1,    58,    -1,    -1,    -1,    62,    63,    -1,
       3,     4,     5,    -1,    -1,    -1,     9,   350,    11,    -1,
      -1,    -1,   140,    -1,    17,    -1,    -1,    -1,    83,   301,
      -1,   303,    -1,    -1,    27,    28,    -1,    -1,    31,    -1,
     158,   159,   160,   161,   101,    10,    11,    12,    13,    14,
      15,    -1,   322,    -1,   326,   110,    -1,   114,    -1,   331,
     330,    -1,   332,   181,   182,   183,   184,    -1,    -1,   341,
      -1,   343,   344,    38,    -1,    -1,    -1,   349,    -1,    -1,
     350,   353,    -1,    -1,    -1,   140,    -1,    -1,    10,    11,
      12,    13,    14,    15,    -1,    10,    11,    12,    13,    14,
      15,    -1,    -1,   158,    26,    -1,   161,    29,    30,    -1,
      -1,   229,    -1,    -1,    17,    -1,    38,    32,   236,   237,
     238,   239,   240,   241,   242,   243,   181,    -1,    -1,   184,
      -1,    -1,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,     3,     4,     5,   264,    -1,    51,     9,
      -1,    11,    -1,   271,    -1,    58,    -1,    17,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,   229,    -1,    -1,    17,    -1,    82,
      -1,   236,   237,   238,   239,   240,   241,    -1,   243,    10,
      11,    12,    13,    14,    15,   250,   251,   252,   253,   254,
     255,    -1,   257,    -1,   322,    26,    -1,   110,    29,   264,
      -1,    51,   330,    -1,   332,    -1,   271,    38,    58,    -1,
      -1,    -1,    62,    63,    -1,    -1,   101,    -1,     3,     4,
       5,    -1,   350,    -1,     9,    -1,    11,   140,    -1,   114,
      -1,    -1,    17,    -1,   301,    -1,   303,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,   158,    31,    -1,   161,    -1,
      10,    11,    12,    13,    14,    15,    -1,   322,    -1,   326,
     110,    -1,    -1,    -1,   331,   330,    26,   332,   181,    29,
      30,   184,    -1,    -1,   341,    -1,   343,   344,    38,    -1,
      -1,    -1,   349,    -1,    -1,   350,   353,    17,    -1,    -1,
     140,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      -1,    10,    11,    12,    13,    14,    15,    -1,   158,    -1,
      26,   161,    -1,    29,    30,    -1,   229,    -1,    -1,    17,
      -1,    51,    38,   236,   237,   238,   239,   240,    58,    38,
     243,   181,    62,    63,   184,    -1,    -1,   250,   251,   252,
     253,   254,    -1,    -1,   257,    -1,     3,     4,     5,    79,
      17,   264,     9,    51,    11,    -1,    -1,    -1,   271,    -1,
      58,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    76,   229,
     110,    17,    -1,    -1,    51,    -1,   236,   237,   238,   239,
     240,    58,    -1,   243,    -1,    62,    63,    -1,    -1,    -1,
     250,   251,   252,   253,   254,    -1,    73,   257,    -1,   322,
     140,    -1,   110,    -1,   264,    51,   301,   330,   303,   332,
      -1,   271,    58,    -1,    -1,    -1,    62,    63,   158,    -1,
      -1,   161,    -1,    -1,    -1,    -1,    -1,   350,    -1,   101,
      -1,   326,   140,   110,    -1,    -1,   331,    -1,    -1,    -1,
      -1,   181,   114,    -1,   184,    -1,   341,    -1,   343,   344,
     158,    -1,    -1,   161,   349,    -1,    -1,    -1,   353,    -1,
      -1,    -1,   322,   140,   110,    -1,    -1,    -1,    -1,   115,
     330,    -1,   332,   181,    -1,    -1,   184,     3,     4,     5,
      -1,   158,    -1,     9,   161,    11,    -1,    -1,    -1,   229,
     350,    17,    -1,    -1,   140,    -1,   236,   237,   238,   239,
      17,    27,    28,   243,   181,    31,    -1,   184,    -1,   101,
     250,   251,   252,   253,    -1,   161,    17,   257,    -1,    -1,
      -1,   229,   114,    -1,   264,    -1,    -1,    -1,   236,   237,
     238,   271,    -1,    -1,    51,   243,    -1,    -1,   184,    -1,
      -1,    58,   250,   251,   252,    62,    63,    -1,    -1,   257,
      51,    -1,   229,    -1,    -1,    -1,   264,    58,   101,   236,
     237,    62,    63,   271,    -1,    -1,   243,    -1,    -1,    -1,
      -1,   114,    -1,   250,   251,    -1,    -1,    -1,    -1,    -1,
     257,    -1,   322,   229,    -1,    -1,    -1,   264,    -1,    -1,
     330,    -1,   332,   110,   271,    -1,    -1,   243,    -1,    -1,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,   110,
     350,   257,    -1,    -1,   322,    -1,    26,    -1,   264,    29,
      30,    -1,   330,   140,   332,   271,    -1,    -1,    38,   301,
      -1,   303,    -1,    10,    11,    12,    13,    14,    15,   140,
      -1,   158,   350,    -1,   161,   322,    10,    11,    12,    13,
      14,    15,    -1,   330,   326,   332,   302,    -1,   304,   331,
     161,    38,    26,    -1,   181,    29,    30,   184,    -1,   341,
      -1,   343,   344,   350,    38,    -1,   322,   349,    -1,    -1,
      -1,   353,    -1,   184,   330,    -1,   332,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,   342,    10,    11,    12,
      13,    14,    15,    26,   350,    -1,    29,    30,    -1,   301,
      -1,   303,   229,    26,    -1,    38,    29,    30,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    38,   243,    -1,   229,    -1,
      -1,    -1,    -1,   250,   326,    -1,    -1,    -1,    -1,   331,
     257,    -1,   243,    -1,    -1,    -1,    -1,   264,    -1,   341,
      -1,   343,   344,    -1,   271,    -1,   257,   349,   301,    -1,
     303,   353,    -1,   264,    10,    11,    12,    13,    14,    15,
     271,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,   326,    -1,    -1,    32,    26,   331,    -1,
      29,    30,    10,    11,    12,    13,    14,    15,   341,    38,
     343,   344,    -1,    -1,    -1,   322,   349,    -1,    26,    -1,
     353,    29,    30,   330,    32,   332,    -1,    -1,    -1,     0,
       1,   322,     3,     4,     5,     6,    -1,    -1,     9,   330,
      11,   332,    -1,   350,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    -1,   350,
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
      -1,    31,    -1,     0,     1,    35,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,     0,     1,    35,     3,
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
       0,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,     1,    35,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
       0,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,     1,    35,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
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
      -1,    31,    -1,    -1,     1,    35,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
       0,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
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
      -1,    27,    28,    -1,    -1,    31,    -1,    -1,     1,    35,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,
      -1,     1,    35,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    25,    -1,    27,    28,    -1,
       1,    31,     3,     4,     5,    35,    -1,    -1,     9,    -1,
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
      24,    25,    -1,    27,    28,    -1,    -1,    31,    -1,    -1,
      -1,    35,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    29,    30,    -1,    26,    -1,    -1,    29,    30,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    38,    10,    11,    12,
      13,    14,    15,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    29,    30,    -1,    26,
      -1,    -1,    29,    30,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    38,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    29,    30,    -1,    26,    -1,    -1,    29,    30,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    38,    10,    11,    12,
      13,    14,    15,     3,     4,     5,    -1,    -1,    -1,     9,
      -1,    11,    -1,    26,    -1,    -1,    29,    30,     3,     4,
       5,    -1,    -1,    -1,     9,    38,    11,    27,    28,    -1,
      -1,    31,     3,     4,     5,    -1,    -1,    -1,     9,    -1,
      11,    -1,    27,    28,    -1,    -1,    31,     3,     4,     5,
      -1,    -1,    -1,     9,    -1,    11,    27,    28,    -1,    -1,
      31,     3,     4,     5,    -1,    -1,    -1,     9,    -1,    11,
      -1,    27,    28,    -1,    -1,    31,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    26,    -1,    -1,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    -1,
      26,    -1,    -1,    29,    30,    -1,    32,    -1,    -1,    26,
      -1,    37,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    15,    -1,    26,    -1,    -1,
      29,    30,    -1,    32,    -1,    -1,    26,    -1,    37,    29,
      30,    -1,    32,    -1,    -1,    -1,    -1,    37,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    15,    -1,    26,    -1,    -1,    29,    30,    -1,
      32,    -1,    -1,    26,    -1,    37,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      -1,    26,    -1,    -1,    29,    30,    -1,    32,    -1,    -1,
      26,    -1,    37,    29,    30,    -1,    32,    -1,    -1,    -1,
      -1,    37,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,    -1,    26,    -1,
      -1,    29,    30,    -1,    32,    -1,    -1,    26,    -1,    37,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    15,    -1,    26,    -1,    -1,    29,    30,
      -1,    32,    -1,    -1,    26,    -1,    37,    29,    30,    -1,
      32,    -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      15,    -1,    26,    -1,    -1,    29,    30,    -1,    32,    -1,
      -1,    26,    -1,    37,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    -1,    26,
      -1,    -1,    29,    30,    -1,    32,    -1,    -1,    26,    -1,
      37,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,
      10,    11,    12,    13,    14,    15,    -1,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    26,    -1,    -1,    29,
      30,    -1,    32,    26,    -1,    -1,    29,    37,    -1,    32,
      -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,    32,    -1,    -1,    -1,    -1,    37,    32,
      -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,    32,    -1,    -1,    -1,    -1,    37,    32,
      -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,    14,
      15,    16,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    31,    32,    26,    -1,
      -1,    29,    30,    31,    32,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    -1,    32,    26,    -1,
      -1,    29,    30,    -1,    32,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    -1,    32,    26,    -1,
      -1,    29,    30,    -1,    32,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    -1,    32,    26,    -1,
      -1,    29,    30,    -1,    32,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    -1,    32,    26,    -1,
      -1,    29,    30,    -1,    32,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    -1,    32,    26,    -1,
      -1,    29,    30,    -1,    32,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    -1,    32,    26,    -1,
      -1,    29,    30,    -1,    32,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    -1,    32,    26,    -1,
      -1,    29,    30,    -1,    32,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    -1,    32,    26,    -1,
      -1,    29,    30,    -1,    32,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    32,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     9,    11,    17,    18,
      20,    21,    23,    24,    25,    27,    28,    31,    35,    47,
      48,    49,    50,    51,    59,    60,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    75,    76,    77,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      16,    31,     5,     7,     3,     4,     5,    69,    31,    31,
      66,    31,    31,    31,    86,    87,    67,    62,     0,    49,
      59,    38,    14,    15,    10,    11,    73,    12,    13,    74,
      38,    38,    26,    29,    30,    66,    67,    78,    38,    52,
       5,    67,    66,    38,     5,     8,    67,     8,    67,    32,
      36,    61,    69,    71,    72,    84,    85,    89,    86,    32,
      37,    31,    38,    54,    32,    38,    32,    32,    32,    32,
      32,     6,    50,    59,    67,     6,    56,    57,    58,    31,
      59,    67,     5,     7,     5,     7,    32,    37,    56,    19,
      38,     5,     5,    53,    58,    32,    59,    66,    60,    55,
      32,    60,    59,     3,     4,     5,     9,    11,    17,    27,
      28,    31,    68,    69,    70,    71,    72,    75,    76,    77,
      84,    85,    86,    87,    88,    89,     3,     4,     5,     9,
      11,    17,    27,    28,    31,    68,    69,    70,    71,    72,
      75,    76,    77,    84,    85,    86,    87,    88,    89,     1,
      18,    20,    21,    35,    60,    63,    64,    65,    66,    79,
      82,    83,     1,    18,    20,    21,    35,    60,    63,    64,
      65,    66,    79,    82,    83,    38,     5,    67,    38,    31,
       3,     4,    69,    86,    87,    67,    14,    15,    73,    74,
      26,    29,    30,    31,     3,     4,    69,    86,    87,    67,
      14,    15,    73,    74,    26,    29,    30,    31,    31,    66,
      62,    38,    38,    38,    31,    31,    66,    62,    38,    38,
      38,    16,    78,    32,    69,    71,    72,    84,    85,    89,
      86,    78,    32,    69,    71,    72,    84,    85,    89,    86,
      67,    66,    38,    36,    67,    66,    38,    36,    66,    32,
      32,    32,    38,    32,    38,     1,    18,    20,    21,    35,
      59,    60,    63,    64,    65,    66,    79,    82,    83,    67,
      59,    67,    31,    31,    66,    62,    19,    38,    38,    38,
      38,    19,    38,    67,    66,    38,    36,    59,    66,    59,
      66,    32,    38,    32,    32,    59,    67,    59,    59,    19,
      38,    59,    66,    32,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    48,    49,    49,    50,
      50,    52,    53,    51,    54,    55,    51,    56,    56,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    61,    61,    62,    62,    63,    63,    64,    65,
      66,    66,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    74,    74,    75,    75,    75,
      75,    76,    76,    76,    76,    76,    77,    78,    78,    78,
      79,    79,    80,    80,    81,    81,    82,    83,    84,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     3,
       4,     0,     0,     8,     0,     0,     9,     1,     0,     3,
       1,     2,     3,     1,     1,     1,     1,     2,     2,     1,
       1,     3,     2,     0,     3,     0,     5,     7,     9,     3,
       3,     1,     1,     3,     1,     2,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     2,     1,     2,     1,     4,     3,     1,     0,
       1,     1,     4,     4,     4,     4,     4,     2,     1,     3,
       1,     2,     1,     2,     1,     3,     1,     3,     1
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
#line 257 "./src/syntax.y"
                    {
        (yyval.t_node) = (yyvsp[0].t_node);
        /* printf("Declaration list - initialize tree\n"); */
        initializeTree((yyval.t_node));
    }
#line 2715 "./src/syntax.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 265 "./src/syntax.y"
                                {
        (yyval.t_node) = createNode("Declaration List - Declaration", "decListDec");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

    }
#line 2729 "./src/syntax.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 274 "./src/syntax.y"
                  {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2737 "./src/syntax.tab.c"
    break;

  case 5: /* declarationList: declarationList statement  */
#line 277 "./src/syntax.y"
                                {
        (yyval.t_node) = createNode("Declaration List - Statement", "decListState");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);
    }
#line 2750 "./src/syntax.tab.c"
    break;

  case 6: /* declarationList: statement  */
#line 285 "./src/syntax.y"
                {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2758 "./src/syntax.tab.c"
    break;

  case 7: /* declaration: varDeclaration  */
#line 291 "./src/syntax.y"
                   {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2766 "./src/syntax.tab.c"
    break;

  case 8: /* declaration: funcDeclaration  */
#line 294 "./src/syntax.y"
                      {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2774 "./src/syntax.tab.c"
    break;

  case 9: /* varDeclaration: TYPE ID DELIM_SEMICOLLON  */
#line 300 "./src/syntax.y"
                             {
        char* temp;

        /* printf("%s %s %s\n", $1.text, $2.text, $3.text); */
        createSymbol((yyvsp[-1].t_token).text, (yyvsp[-2].t_token).text, (yyvsp[-1].t_token).line, (yyvsp[-1].t_token).column, (yyvsp[-1].t_token).scope->scopeValue, (yyvsp[-1].t_token).scope->parentScope, 1, (yyvsp[-2].t_token).text);
        /* printf("variable declaration\n"); */

        temp = (char*) malloc(strlen((yyvsp[-1].t_token).text) + strlen("Variable Declaration - ID: ") + 1);

        /* printf("allocated memory\n"); */
        strcpy(temp, "Variable Declaration - ID: ");
        /* printf("copied first string\n"); */
        strcat(temp, (yyvsp[-1].t_token).text);
        /* printf("concatenated second string\n"); */

        temp = add_color(temp, COLOR_GREEN);

        (yyval.t_node) = createNode(temp, "varDec");
        /* initializeTree($$); */

        freeScopeToken((yyvsp[-1].t_token).scope);
        free(temp);

    }
#line 2803 "./src/syntax.tab.c"
    break;

  case 10: /* varDeclaration: TYPE LIST_TYPE ID DELIM_SEMICOLLON  */
#line 324 "./src/syntax.y"
                                         {
        char* temp;
        char* temp2;

        temp = (char*) malloc(strlen((yyvsp[-3].t_token).text) + strlen((yyvsp[-2].t_token).text) + 3);
        strcpy(temp, (yyvsp[-3].t_token).text);
        strcat(temp, " ");
        strcat(temp, (yyvsp[-2].t_token).text);
        /* printf("%s %s %s %s - %s\n", $1.text, $2.text, $3.text, $4.text, temp); */
        createSymbol((yyvsp[-1].t_token).text, temp, (yyvsp[-1].t_token).line, (yyvsp[-1].t_token).column, (yyvsp[-1].t_token).scope->scopeValue, (yyvsp[-1].t_token).scope->parentScope, 1, (yyvsp[-3].t_token).text);


        temp2 = (char*) malloc(strlen((yyvsp[-1].t_token).text) + strlen("Variable Declaration - List Type ID: ") + 1);

        strcpy(temp2, "Variable Declaration - List Type ID: ");
        strcat(temp2, (yyvsp[-1].t_token).text);

        temp2 = add_color(temp2, COLOR_GREEN);

        (yyval.t_node) = createNode(temp2, "varDecList");

        freeScopeToken((yyvsp[-1].t_token).scope);
        free(temp);
        free(temp2);

    }
#line 2834 "./src/syntax.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 367 "./src/syntax.y"
            {
        /* printf("%s %s %s %s - escopo %d %d\n", $1.text, $2.text, $3.text, $5.text, $2.scope->scopeValue, $2.scope->parentScope); */
        createSymbol((yyvsp[0].t_token).text, (yyvsp[-1].t_token).text, (yyvsp[0].t_token).line, (yyvsp[0].t_token).column, (yyvsp[0].t_token).scope->scopeValue, (yyvsp[0].t_token).scope->parentScope, 0, (yyvsp[-1].t_token).text);
        updateLastFunc((yyvsp[0].t_token).text);
    }
#line 2844 "./src/syntax.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 371 "./src/syntax.y"
                                               {
        t_symbol* symbol;

        /* symbol = getSymbol($2.text); */
        symbol = getSymbolValidScopeFunc((yyvsp[-4].t_token).text);
        installParam(symbol);
    }
#line 2856 "./src/syntax.tab.c"
    break;

  case 13: /* funcDeclaration: TYPE ID $@1 DELIM_PARENT_L parameters DELIM_PARENT_R $@2 bodyStatement  */
#line 378 "./src/syntax.y"
                  {
        char* temp;
        t_symbol* symbol;

        temp = (char*) malloc(strlen((yyvsp[-6].t_token).text) + strlen("Function Declaration - ID: ") + 1);

        strcpy(temp, "Function Declaration - ID: ");
        strcat(temp, (yyvsp[-6].t_token).text);

        temp = add_color(temp, COLOR_GREEN);

        (yyval.t_node) = createNode(temp, "funcDec");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-3].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

        symbol = getSymbolValidScopeFunc((yyvsp[-6].t_token).text);
        addNodeSymbol((yyval.t_node), symbol);

        freeScopeToken((yyvsp[-6].t_token).scope);
        free(temp);

        /* printf("function declaration test\n"); */

        addReturnNode((yyval.t_node));

    }
#line 2890 "./src/syntax.tab.c"
    break;

  case 14: /* $@3: %empty  */
#line 407 "./src/syntax.y"
                        {
        char* temp;

        temp = (char*) malloc(sizeof((yyvsp[-2].t_token).text) + sizeof((yyvsp[-1].t_token).text) + 3);
        strcpy(temp, (yyvsp[-2].t_token).text);
        strcat(temp, " ");
        strcat(temp, (yyvsp[-1].t_token).text);
        createSymbol((yyvsp[0].t_token).text, temp, (yyvsp[0].t_token).line, (yyvsp[0].t_token).column, (yyvsp[0].t_token).scope->scopeValue, (yyvsp[0].t_token).scope->parentScope, 0, (yyvsp[-2].t_token).text);
        updateLastFunc((yyvsp[0].t_token).text);

        free(temp);
    }
#line 2907 "./src/syntax.tab.c"
    break;

  case 15: /* $@4: %empty  */
#line 419 "./src/syntax.y"
                                             {
        t_symbol* symbol;

        symbol = getSymbolValidScopeFunc((yyvsp[-4].t_token).text);

        installParam(symbol);
    }
#line 2919 "./src/syntax.tab.c"
    break;

  case 16: /* funcDeclaration: TYPE LIST_TYPE ID $@3 DELIM_PARENT_L parameters DELIM_PARENT_R $@4 bodyStatement  */
#line 426 "./src/syntax.y"
                  {
        char* temp2;
        t_symbol* symbol;

        temp2 = (char*) malloc(strlen((yyvsp[-6].t_token).text) + strlen("Function Declaration - List Type ID: ") + 1);

        strcpy(temp2, "Function Declaration - List Type ID: ");
        strcat(temp2, (yyvsp[-6].t_token).text);

        temp2 = add_color(temp2, COLOR_GREEN);

        (yyval.t_node) = createNode(temp2, "funcDecList");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-3].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

        symbol = getSymbolValidScopeFunc((yyvsp[-6].t_token).text);
        addNodeSymbol((yyval.t_node), symbol);

        freeScopeToken((yyvsp[-6].t_token).scope);
        free(temp2);

        addReturnNode((yyval.t_node));
    }
#line 2950 "./src/syntax.tab.c"
    break;

  case 17: /* parameters: parameterList  */
#line 455 "./src/syntax.y"
                  {
        /* printf("parameters of function declaration test\n"); */
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2959 "./src/syntax.tab.c"
    break;

  case 18: /* parameters: %empty  */
#line 459 "./src/syntax.y"
      {
        (yyval.t_node) = createEmptyNode();
    }
#line 2967 "./src/syntax.tab.c"
    break;

  case 19: /* parameterList: parameterList DELIM_COMMA parameterSimple  */
#line 465 "./src/syntax.y"
                                              {
        (yyval.t_node) = createNode("Parameters list", "paramList");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);
    }
#line 2980 "./src/syntax.tab.c"
    break;

  case 20: /* parameterList: parameterSimple  */
#line 473 "./src/syntax.y"
                      {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 2988 "./src/syntax.tab.c"
    break;

  case 21: /* parameterSimple: TYPE ID  */
#line 480 "./src/syntax.y"
            {
        char* temp;
        t_symbol* symbol;

        symbol = createSymbol((yyvsp[0].t_token).text, (yyvsp[-1].t_token).text, (yyvsp[0].t_token).line, (yyvsp[0].t_token).column, lastScopeValue+1, (yyvsp[0].t_token).scope->scopeValue, 1, (yyvsp[-1].t_token).text);
        /* $2.scope->scopeValue lastScopeValue+1 $2.scope->parentScope*/
        temp = (char*) malloc(strlen((yyvsp[0].t_token).text) + strlen("Parameter Declaration - ID: ") + 3);

        strcpy(temp, "Parameter Declaration - ID: ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_GREEN);

        (yyval.t_node) = createNode(temp, "paramSimple");

        freeScopeToken((yyvsp[0].t_token).scope);
        free(temp);


        addParam(symbol);

    }
#line 3015 "./src/syntax.tab.c"
    break;

  case 22: /* parameterSimple: TYPE LIST_TYPE ID  */
#line 502 "./src/syntax.y"
                       {
        char* temp;
        char* temp2;
        t_symbol* symbol;

        temp = (char*) malloc(strlen((yyvsp[-2].t_token).text) + strlen((yyvsp[-1].t_token).text) + 3);
        strcpy(temp, (yyvsp[-2].t_token).text);
        strcat(temp, " ");
        strcat(temp, (yyvsp[-1].t_token).text);

        symbol = createSymbol((yyvsp[0].t_token).text, temp, (yyvsp[0].t_token).line, (yyvsp[0].t_token).column, lastScopeValue+1, (yyvsp[0].t_token).scope->scopeValue, 1, (yyvsp[-2].t_token).text);
        /* $3.scope->scopeValue lastScopeValue+1 $3.scope->parentScope*/
        temp2 = (char*) malloc(strlen((yyvsp[0].t_token).text) + strlen("Parameter Declaration - List Type ID: ") + 3);

        strcpy(temp2, "Parameter Declaration - List Type ID: ");
        strcat(temp2, (yyvsp[0].t_token).text);

        temp2 = add_color(temp2, COLOR_GREEN);

        (yyval.t_node) = createNode(temp2, "paramSimpleList");

        freeScopeToken((yyvsp[0].t_token).scope);
        free(temp);
        free(temp2);

        addParam(symbol);

    }
#line 3048 "./src/syntax.tab.c"
    break;

  case 23: /* statement: bodyStatement  */
#line 533 "./src/syntax.y"
                  {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3056 "./src/syntax.tab.c"
    break;

  case 24: /* statement: ifStatement  */
#line 536 "./src/syntax.y"
                  {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3064 "./src/syntax.tab.c"
    break;

  case 25: /* statement: loopStatement  */
#line 539 "./src/syntax.y"
                    {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3072 "./src/syntax.tab.c"
    break;

  case 26: /* statement: returnStatement  */
#line 542 "./src/syntax.y"
                      {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3080 "./src/syntax.tab.c"
    break;

  case 27: /* statement: writeOp DELIM_SEMICOLLON  */
#line 548 "./src/syntax.y"
                               {
        (yyval.t_node) = (yyvsp[-1].t_node);
    }
#line 3088 "./src/syntax.tab.c"
    break;

  case 28: /* statement: readOp DELIM_SEMICOLLON  */
#line 551 "./src/syntax.y"
                              {
        (yyval.t_node) = (yyvsp[-1].t_node);
    }
#line 3096 "./src/syntax.tab.c"
    break;

  case 29: /* statement: expressionStatement  */
#line 554 "./src/syntax.y"
                          {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3104 "./src/syntax.tab.c"
    break;

  case 30: /* statement: error  */
#line 557 "./src/syntax.y"
            {
        (yyval.t_node) = createNode(COLOR_RED "SYNTAX ERROR" COLOR_RESET, "error");
    }
#line 3112 "./src/syntax.tab.c"
    break;

  case 31: /* bodyStatement: DELIM_CUR_BRACKET_L statementList DELIM_CUR_BRACKET_R  */
#line 563 "./src/syntax.y"
                                                          {
        (yyval.t_node) = (yyvsp[-1].t_node);
        freeScopeToken((yyvsp[-2].t_token).scope);
    }
#line 3121 "./src/syntax.tab.c"
    break;

  case 32: /* localDeclaration: localDeclaration varDeclaration  */
#line 574 "./src/syntax.y"
                                    {
        (yyval.t_node) = createNode("Local Declaration", "localDec");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);
    }
#line 3134 "./src/syntax.tab.c"
    break;

  case 33: /* localDeclaration: %empty  */
#line 582 "./src/syntax.y"
      {
        (yyval.t_node) = createEmptyNode();
    }
#line 3142 "./src/syntax.tab.c"
    break;

  case 34: /* statementList: statementList localDeclaration statement  */
#line 588 "./src/syntax.y"
                                             {
        (yyval.t_node) = createNode("Statement List", "stateList");

        addChild((yyval.t_node), 3);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[-1].t_node);
        (yyval.t_node)->child[2] = (yyvsp[0].t_node);

    }
#line 3157 "./src/syntax.tab.c"
    break;

  case 35: /* statementList: %empty  */
#line 598 "./src/syntax.y"
      {
        (yyval.t_node) = createEmptyNode();
    }
#line 3165 "./src/syntax.tab.c"
    break;

  case 36: /* ifStatement: IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R statement  */
#line 604 "./src/syntax.y"
                                                                                    {
        (yyval.t_node) = createNode(COLOR_BLUE "If Statement" COLOR_RESET, "if");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);
    }
#line 3178 "./src/syntax.tab.c"
    break;

  case 37: /* ifStatement: IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R statement ELSE_KEY statement  */
#line 612 "./src/syntax.y"
                                                                                         {
        (yyval.t_node) = createNode(COLOR_BLUE "If-Else Statement" COLOR_RESET, "ifelse");

        addChild((yyval.t_node), 3);

        (yyval.t_node)->child[0] = (yyvsp[-4].t_node);
        (yyval.t_node)->child[1] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[2] = (yyvsp[0].t_node);

    }
#line 3193 "./src/syntax.tab.c"
    break;

  case 38: /* loopStatement: FOR_KEY DELIM_PARENT_L expression DELIM_SEMICOLLON simpleExpression DELIM_SEMICOLLON expression DELIM_PARENT_R statement  */
#line 625 "./src/syntax.y"
                                                                                                                             {
        (yyval.t_node) = createNode(COLOR_BLUE "For Statement" COLOR_RESET, "for");

        addChild((yyval.t_node), 4);

        (yyval.t_node)->child[0] = (yyvsp[-6].t_node);
        (yyval.t_node)->child[1] = (yyvsp[-4].t_node);
        (yyval.t_node)->child[2] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[3] = (yyvsp[0].t_node);
    }
#line 3208 "./src/syntax.tab.c"
    break;

  case 39: /* returnStatement: RETURN_KEY expression DELIM_SEMICOLLON  */
#line 638 "./src/syntax.y"
                                           {
        (yyval.t_node) = createNode(COLOR_BLUE "Return Statement" COLOR_RESET, "return");

        addChild((yyval.t_node), 1);

        addFunctionName((yyval.t_node), lastFuncDeclared);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);

        verifyOperands((yyval.t_node));
    }
#line 3224 "./src/syntax.tab.c"
    break;

  case 40: /* expression: ID ASSIGN_OP expression  */
#line 652 "./src/syntax.y"
                            {
        (yyval.t_node) = createNode("Assign Operation", "assignOp");

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[0].t_node);
        freeScopeToken((yyvsp[-2].t_token).scope);

        addNodePosition((yyval.t_node), (yyvsp[-2].t_token).line, (yyvsp[-2].t_token).column);
        /* addNodePosition($$, $$->child[0]->line, $$->child[0]->column); */
        addNodeId((yyval.t_node), (yyvsp[-2].t_token).text);

        /* addNodePosition($3, $3->line, $3->column); */

        checkIdDeclaration((yyval.t_node));

        verifyOperands((yyval.t_node));

    }
#line 3248 "./src/syntax.tab.c"
    break;

  case 41: /* expression: simpleExpression  */
#line 671 "./src/syntax.y"
                       {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3256 "./src/syntax.tab.c"
    break;

  case 42: /* simpleExpression: logicBinExpression  */
#line 682 "./src/syntax.y"
                       {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3264 "./src/syntax.tab.c"
    break;

  case 43: /* logicBinExpression: logicBinExpression LOGIC_OP logicUnExpression  */
#line 693 "./src/syntax.y"
                                                  {
        (yyval.t_node) = createNode("Logic Binary Expression", "logicBin");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

        addNodeType((yyval.t_node), "int");

        addNodePosition((yyval.t_node), (yyval.t_node)->child[1]->line, (yyval.t_node)->child[1]->column);

        verifyOperands((yyval.t_node));

        addNodeValue((yyval.t_node), (yyvsp[-1].t_token).text);

    }
#line 3286 "./src/syntax.tab.c"
    break;

  case 44: /* logicBinExpression: logicUnExpression  */
#line 710 "./src/syntax.y"
                        {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3294 "./src/syntax.tab.c"
    break;

  case 45: /* logicUnExpression: EXCLA_OP logicUnExpression  */
#line 716 "./src/syntax.y"
                               {
        (yyval.t_node) = createNode("Exclamation Expression", "exclaExp");

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[0].t_node);

        /* addNodeType($$, "int"); */
        addNodeTypeChildren((yyval.t_node));

        addNodePosition((yyval.t_node), (yyval.t_node)->child[0]->line, (yyval.t_node)->child[0]->column);

        verifyOperands((yyval.t_node));

    }
#line 3314 "./src/syntax.tab.c"
    break;

  case 46: /* logicUnExpression: binExpression  */
#line 731 "./src/syntax.y"
                    {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3322 "./src/syntax.tab.c"
    break;

  case 47: /* binExpression: binExpression BINARY_OP sumExpression  */
#line 741 "./src/syntax.y"
                                          {
        (yyval.t_node) = createNode("Binary Expression", "binExp");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

        addNodeType((yyval.t_node), "int");

        addNodePosition((yyval.t_node), (yyval.t_node)->child[1]->line, (yyval.t_node)->child[1]->column);

        verifyOperands((yyval.t_node));

        addNodeValue((yyval.t_node), (yyvsp[-1].t_token).text);

    }
#line 3344 "./src/syntax.tab.c"
    break;

  case 48: /* binExpression: sumExpression  */
#line 758 "./src/syntax.y"
                    {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3352 "./src/syntax.tab.c"
    break;

  case 49: /* sumExpression: sumExpression sumOP mulExpression  */
#line 764 "./src/syntax.y"
                                      {
        (yyval.t_node) = createNode("Sum Expression", "sumExp");

        addChild((yyval.t_node), 3);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[-1].t_node);
        (yyval.t_node)->child[2] = (yyvsp[0].t_node);

        addNodeTypeChildren((yyval.t_node));

        addNodePosition((yyval.t_node), (yyval.t_node)->child[2]->line, (yyval.t_node)->child[2]->column);

        verifyOperands((yyval.t_node));
    }
#line 3372 "./src/syntax.tab.c"
    break;

  case 50: /* sumExpression: mulExpression  */
#line 779 "./src/syntax.y"
                    {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3380 "./src/syntax.tab.c"
    break;

  case 51: /* mulExpression: mulExpression mulOP listExpression  */
#line 785 "./src/syntax.y"
                                       {
        (yyval.t_node) = createNode("Multiplication Expression", "mulExp");

        addChild((yyval.t_node), 3);

        addChild((yyval.t_node), 3);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[-1].t_node);
        (yyval.t_node)->child[2] = (yyvsp[0].t_node);

        addNodeTypeChildren((yyval.t_node));

        addNodePosition((yyval.t_node), (yyval.t_node)->child[2]->line, (yyval.t_node)->child[2]->column);

        verifyOperands((yyval.t_node));
    }
#line 3402 "./src/syntax.tab.c"
    break;

  case 52: /* mulExpression: listExpression  */
#line 805 "./src/syntax.y"
                     {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3410 "./src/syntax.tab.c"
    break;

  case 53: /* sumOP: PLUS_OP  */
#line 811 "./src/syntax.y"
            {
        (yyval.t_node) = createNode("+ Operator", "plusOp");
    }
#line 3418 "./src/syntax.tab.c"
    break;

  case 54: /* sumOP: MINUS_OP  */
#line 814 "./src/syntax.y"
               {
        (yyval.t_node) = createNode("- Operator", "minusOp");
    }
#line 3426 "./src/syntax.tab.c"
    break;

  case 55: /* mulOP: MUL_OP  */
#line 820 "./src/syntax.y"
           {
        (yyval.t_node) = createNode("* Operator", "mulOp");
    }
#line 3434 "./src/syntax.tab.c"
    break;

  case 56: /* mulOP: DIV_OP  */
#line 823 "./src/syntax.y"
             {
        (yyval.t_node) = createNode("/ Operator", "divOp");
    }
#line 3442 "./src/syntax.tab.c"
    break;

  case 57: /* factor: ID  */
#line 829 "./src/syntax.y"
       {
        char* temp;

        temp = (char*) malloc(strlen((yyvsp[0].t_token).text) + strlen("ID:  ") + 3);

        strcpy(temp, "ID:  ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_YELLOW);

        (yyval.t_node) = createNode(temp, "id");

        freeScopeToken((yyvsp[0].t_token).scope);
        free(temp);

        addNodeTypeId((yyval.t_node), (yyvsp[0].t_token).text);
        addNodePosition((yyval.t_node), (yyvsp[0].t_token).line, (yyvsp[0].t_token).column);
        addNodeId((yyval.t_node), (yyvsp[0].t_token).text);

        checkIdDeclaration((yyval.t_node));
    }
#line 3468 "./src/syntax.tab.c"
    break;

  case 58: /* factor: constant  */
#line 850 "./src/syntax.y"
               {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3476 "./src/syntax.tab.c"
    break;

  case 59: /* factor: DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 853 "./src/syntax.y"
                                                     {
        (yyval.t_node) = (yyvsp[-1].t_node);
    }
#line 3484 "./src/syntax.tab.c"
    break;

  case 60: /* factor: functionCall  */
#line 859 "./src/syntax.y"
                   {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3492 "./src/syntax.tab.c"
    break;

  case 61: /* constant: INT  */
#line 868 "./src/syntax.y"
        {
        char* temp;

        temp = (char*) malloc(strlen("Constant Integer: ") + strlen((yyvsp[0].t_token).text) + 1);
        strcpy(temp, "Constant Integer: ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_YELLOW);

        (yyval.t_node) = createNode(temp, "constInt");

        free(temp);

        addNodeType((yyval.t_node), "int");
        addNodePosition((yyval.t_node), (yyvsp[0].t_token).line, (yyvsp[0].t_token).column);
        addNodeValue((yyval.t_node), (yyvsp[0].t_token).text);
    }
#line 3514 "./src/syntax.tab.c"
    break;

  case 62: /* constant: MINUS_OP INT  */
#line 885 "./src/syntax.y"
                   {
        char* temp;

        temp = (char*) malloc(strlen("Constant Negative Integer: ") + strlen((yyvsp[0].t_token).text) + 1);
        strcpy(temp, "Constant Negative Integer: ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_YELLOW);

        (yyval.t_node) = createNode(temp, "constNegInt");

        free(temp);

        addNodeType((yyval.t_node), "int");
        addNodePosition((yyval.t_node), (yyvsp[0].t_token).line, (yyvsp[0].t_token).column);
        addNodeValue((yyval.t_node), (yyvsp[0].t_token).text);
    }
#line 3536 "./src/syntax.tab.c"
    break;

  case 63: /* constant: FLOAT  */
#line 902 "./src/syntax.y"
            {
        char* temp;

        temp = (char*) malloc(strlen("Constant Float: ") + strlen((yyvsp[0].t_token).text) + 1);
        strcpy(temp, "Constant Float: ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_YELLOW);

        (yyval.t_node) = createNode(temp, "constFloat");

        free(temp);

        addNodeType((yyval.t_node), "float");
        addNodePosition((yyval.t_node), (yyvsp[0].t_token).line, (yyvsp[0].t_token).column);
        addNodeValue((yyval.t_node), (yyvsp[0].t_token).text);
    }
#line 3558 "./src/syntax.tab.c"
    break;

  case 64: /* constant: MINUS_OP FLOAT  */
#line 919 "./src/syntax.y"
                     {
        char* temp;

        temp = (char*) malloc(strlen("Constant Negative Float: ") + strlen((yyvsp[0].t_token).text) + 1);
        strcpy(temp, "Constant Negative Float: ");
        strcat(temp, (yyvsp[0].t_token).text);

        temp = add_color(temp, COLOR_YELLOW);

        (yyval.t_node) = createNode(temp, "constNegFloat");

        free(temp);

        addNodeType((yyval.t_node), "float");
        addNodePosition((yyval.t_node), (yyvsp[0].t_token).line, (yyvsp[0].t_token).column);
        addNodeValue((yyval.t_node), (yyvsp[0].t_token).text);
    }
#line 3580 "./src/syntax.tab.c"
    break;

  case 65: /* constant: NULL_CONST  */
#line 936 "./src/syntax.y"
                 {
        char* temp;

        temp = malloc(strlen("Constant NULL") + 1);
        strcpy(temp, "Constant NULL");

        temp = add_color(temp, COLOR_YELLOW);

        (yyval.t_node) = createNode(temp, "constNull");

        free(temp);

        addNodeType((yyval.t_node), "nil");
        addNodePosition((yyval.t_node), (yyvsp[0].t_token).line, (yyvsp[0].t_token).column);
        addNodeValue((yyval.t_node), (yyvsp[0].t_token).text);
    }
#line 3601 "./src/syntax.tab.c"
    break;

  case 66: /* functionCall: ID DELIM_PARENT_L parametersPass DELIM_PARENT_R  */
#line 955 "./src/syntax.y"
                                                    {
        char* temp;

        temp = (char*) malloc(strlen("Function Call - ID: ") + strlen((yyvsp[-3].t_token).text) + 1);
        strcpy(temp, "Function Call - ID: ");
        strcat(temp, (yyvsp[-3].t_token).text);

        (yyval.t_node) = createNode(temp, "funcCall");

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);
        freeScopeToken((yyvsp[-3].t_token).scope);
        free(temp);

        addNodeTypeId((yyval.t_node), (yyvsp[-3].t_token).text);
        addFunctionName((yyval.t_node), (yyvsp[-3].t_token).text);
        addNodePosition((yyval.t_node), (yyvsp[-3].t_token).line, (yyvsp[-3].t_token).column);

        checkFunctionCall((yyval.t_node));
    }
#line 3627 "./src/syntax.tab.c"
    break;

  case 67: /* parametersPass: parametersPass DELIM_COMMA simpleExpression  */
#line 979 "./src/syntax.y"
                                                {
        (yyval.t_node) = createNode("Parameters Passing", "paramPass");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);
    }
#line 3640 "./src/syntax.tab.c"
    break;

  case 68: /* parametersPass: simpleExpression  */
#line 987 "./src/syntax.y"
                       {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3648 "./src/syntax.tab.c"
    break;

  case 69: /* parametersPass: %empty  */
#line 990 "./src/syntax.y"
      {
        (yyval.t_node) = createEmptyNode();
    }
#line 3656 "./src/syntax.tab.c"
    break;

  case 70: /* writeOp: write  */
#line 996 "./src/syntax.y"
          {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3664 "./src/syntax.tab.c"
    break;

  case 71: /* writeOp: writeln  */
#line 999 "./src/syntax.y"
              {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3672 "./src/syntax.tab.c"
    break;

  case 72: /* write: OUTPUT_KEY DELIM_PARENT_L STRING DELIM_PARENT_R  */
#line 1005 "./src/syntax.y"
                                                    {
        (yyval.t_node) = createNode(COLOR_BLUE "Output String" COLOR_RESET, "writeString");
        addNodeValue((yyval.t_node), (yyvsp[-1].t_token).text);
    }
#line 3681 "./src/syntax.tab.c"
    break;

  case 73: /* write: OUTPUT_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 1009 "./src/syntax.y"
                                                                {
        (yyval.t_node) = createNode(COLOR_BLUE "Output Expression" COLOR_RESET, "writeExp");

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);

        verifyOperands((yyval.t_node));
    }
#line 3695 "./src/syntax.tab.c"
    break;

  case 74: /* writeln: OUTPUTLN_KEY DELIM_PARENT_L STRING DELIM_PARENT_R  */
#line 1021 "./src/syntax.y"
                                                      {
        (yyval.t_node) = createNode(COLOR_BLUE "OutputLn String" COLOR_RESET, "writelnString");
        addNodeValue((yyval.t_node), (yyvsp[-1].t_token).text);
    }
#line 3704 "./src/syntax.tab.c"
    break;

  case 75: /* writeln: OUTPUTLN_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R  */
#line 1025 "./src/syntax.y"
                                                                  {
        (yyval.t_node) = createNode(COLOR_BLUE "OutputLn Expression" COLOR_RESET, "writelnExp");

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[-1].t_node);

        verifyOperands((yyval.t_node));
    }
#line 3718 "./src/syntax.tab.c"
    break;

  case 76: /* readOp: INPUT_KEY DELIM_PARENT_L ID DELIM_PARENT_R  */
#line 1037 "./src/syntax.y"
                                               {
        char* temp;

        temp = (char*) malloc(strlen((yyvsp[-1].t_token).text) + strlen("Read - Input ID: ") + 3);

        strcpy(temp, "Read - Input ID: ");
        strcat(temp, (yyvsp[-1].t_token).text);

        temp = add_color(temp, COLOR_BLUE);

        (yyval.t_node) = createNode(temp, "readOp");

        addNodeId((yyval.t_node), (yyvsp[-1].t_token).text);
        addNodePosition((yyval.t_node), (yyvsp[-1].t_token).line, (yyvsp[-1].t_token).column);

        verifyOperands((yyval.t_node));

        freeScopeToken((yyvsp[-1].t_token).scope);
        free(temp);
    }
#line 3743 "./src/syntax.tab.c"
    break;

  case 77: /* expressionStatement: expression DELIM_SEMICOLLON  */
#line 1060 "./src/syntax.y"
                                {
        (yyval.t_node) = (yyvsp[-1].t_node);
    }
#line 3751 "./src/syntax.tab.c"
    break;

  case 78: /* listExpression: listAssign  */
#line 1097 "./src/syntax.y"
               {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3759 "./src/syntax.tab.c"
    break;

  case 79: /* listAssign: listMap ASSIGN_LISTOP listAssign  */
#line 1103 "./src/syntax.y"
                                      {
        char* temp;

        /* temp = (char*) malloc(strlen($1.text) + strlen($3.text) + strlen($5.text) + strlen("List Assignment - ID1: ") + strlen(" - ID2: ") + strlen(" - ID3: ") + 3); */
        /* temp = (char*) malloc(strlen($1.text) + strlen($3.text) + strlen($5.text) + strlen("List Assignment - IDs: ") + 6); */

        temp = malloc(strlen("List Assignment") + 3);

        /* strcpy(temp, "List Assignment - ID1: ");
        strcat(temp, $1.text);
        strcat(temp, " - ID2: ");
        strcat(temp, $3.text);
        strcat(temp, " - ID3: ");
        strcat(temp, $5.text); */

        /* strcpy(temp, "List Assignment - IDs: ");
        strcat(temp, $1.text);
        strcat(temp, ", ");
        strcat(temp, $3.text);
        strcat(temp, ", ");
        strcat(temp, $5.text); */

        strcpy(temp, "List Assignment");

        temp = add_color(temp, COLOR_CYAN);

        (yyval.t_node) = createNode(temp, "listAssign");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

        addNodeTypeChildren((yyval.t_node));

        addNodePosition((yyval.t_node), (yyval.t_node)->child[1]->line, (yyval.t_node)->child[1]->column);

        /* freeScopeToken($1.scope);
        freeScopeToken($3.scope);
        freeScopeToken($5.scope); */
        free(temp);
    }
#line 3806 "./src/syntax.tab.c"
    break;

  case 80: /* listAssign: listMap  */
#line 1145 "./src/syntax.y"
             {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3814 "./src/syntax.tab.c"
    break;

  case 81: /* listHeader: HEADER_LISTOP listHeader  */
#line 1152 "./src/syntax.y"
                             {
        char* temp;

        temp = (char*) malloc(strlen("List Header") + 3);

        strcpy(temp, "List Header");
        /* strcpy(temp, "List Header - ID: "); */
        /* strcat(temp, $2.text); */

        temp = add_color(temp, COLOR_CYAN);

        (yyval.t_node) = createNode(temp, "listHeader");

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[0].t_node);

        addNodeTypeChildren((yyval.t_node));

        addNodePosition((yyval.t_node), (yyval.t_node)->child[0]->line, (yyval.t_node)->child[0]->column);

        verifyOperands((yyval.t_node));
        /* freeScopeToken($2.scope); */
        free(temp);
    }
#line 3844 "./src/syntax.tab.c"
    break;

  case 82: /* listHeader: listTailDestructor  */
#line 1180 "./src/syntax.y"
                         {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3852 "./src/syntax.tab.c"
    break;

  case 83: /* listTailDestructor: TAILDES_LISTOP listTailDestructor  */
#line 1199 "./src/syntax.y"
                                      {
        char* temp;

        /* temp = (char*) malloc(strlen($2.text) + strlen("List Tail Destructor - ID: ") + 3); */
        temp = malloc(strlen("List Tail Destructor") + 3);

        /* strcpy(temp, "List Tail Destructor - ID: ");
        strcat(temp, $2.text); */
        strcpy(temp, "List Tail Destructor");

        temp = add_color(temp, COLOR_CYAN);

        (yyval.t_node) = createNode(temp, "listTailDest");

        addChild((yyval.t_node), 1);

        (yyval.t_node)->child[0] = (yyvsp[0].t_node);

        addNodeTypeChildren((yyval.t_node));

        addNodePosition((yyval.t_node), (yyval.t_node)->child[0]->line, (yyval.t_node)->child[0]->column);

        verifyOperands((yyval.t_node));

        /* freeScopeToken($2.scope); */
        free(temp);
    }
#line 3884 "./src/syntax.tab.c"
    break;

  case 84: /* listTailDestructor: factor  */
#line 1226 "./src/syntax.y"
             {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3892 "./src/syntax.tab.c"
    break;

  case 85: /* listMap: listMap MAP_LISTOP listFilter  */
#line 1232 "./src/syntax.y"
                                  {
        char* temp;

        /* temp = (char*) malloc(strlen($1.text) + strlen($3.text) + strlen($5.text) + strlen("List Map - IDs: ") + 6); */
        temp = malloc(strlen("List Map") + 3);

        /* strcpy(temp, "List Map - IDs: "); */
        /* strcat(temp, $1.text);
        strcat(temp, ", ");
        strcat(temp, $3.text);
        strcat(temp, ", ");
        strcat(temp, $5.text); */

        strcpy(temp, "List Map");

        temp = add_color(temp, COLOR_CYAN);

        (yyval.t_node) = createNode(temp, "listMap");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

        addNodeTypeChildren((yyval.t_node));

        addNodePosition((yyval.t_node), (yyval.t_node)->child[1]->line, (yyval.t_node)->child[1]->column);

        verifyOperands((yyval.t_node));

        /* freeScopeToken($1.scope);
        freeScopeToken($3.scope);
        freeScopeToken($5.scope); */
        free(temp);
    }
#line 3932 "./src/syntax.tab.c"
    break;

  case 86: /* listMap: listFilter  */
#line 1267 "./src/syntax.y"
                 {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3940 "./src/syntax.tab.c"
    break;

  case 87: /* listFilter: listFilter FILTER_LISTOP listHeader  */
#line 1273 "./src/syntax.y"
                                        {
        char* temp;

        /* temp = (char*) malloc(strlen($1.text) + strlen($3.text) + strlen($5.text) + strlen("List Filter - IDs: ") + 6); */
        temp = malloc(strlen("List Filter") + 3);

        /* strcpy(temp, "List Filter - IDs: "); */
        /* strcat(temp, $1.text);
        strcat(temp, ", ");
        strcat(temp, $3.text);
        strcat(temp, ", ");
        strcat(temp, $5.text); */

        strcpy(temp, "List Filter");

        temp = add_color(temp, COLOR_CYAN);

        (yyval.t_node) = createNode(temp, "listFilter");

        addChild((yyval.t_node), 2);

        (yyval.t_node)->child[0] = (yyvsp[-2].t_node);
        (yyval.t_node)->child[1] = (yyvsp[0].t_node);

        addNodeTypeChildren((yyval.t_node));

        addNodePosition((yyval.t_node), (yyval.t_node)->child[1]->line, (yyval.t_node)->child[1]->column);

        verifyOperands((yyval.t_node));

        /* freeScopeToken($1.scope);
        freeScopeToken($3.scope);
        freeScopeToken($5.scope); */
        free(temp);
    }
#line 3980 "./src/syntax.tab.c"
    break;

  case 88: /* listFilter: listHeader  */
#line 1308 "./src/syntax.y"
                 {
        (yyval.t_node) = (yyvsp[0].t_node);
    }
#line 3988 "./src/syntax.tab.c"
    break;


#line 3992 "./src/syntax.tab.c"

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

#line 1319 "./src/syntax.y"

/* Additional C code */

void yyerror(const char* s){
    printf(COLOR_RED "Syntax error:" COLOR_RESET " %s\nLine: %d - Column: %d\n", s, line, column);
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
        setFileName(argv[1]);

        if(filep != NULL){
            /* print_start(); */

            yyin = filep;
            /* yylex(); */
            yyparse();
            fclose(yyin);

            semanticAnalysis();

            printf("\nAnalyzer completed. Errors: \n" COLOR_YELLOW "--%d lexical;" COLOR_RESET COLOR_CYAN " \n--%d syntatic; " COLOR_RESET COLOR_GREEN "\n--%d semantic." COLOR_RESET "\n\n\n", lexicalError, syntaticError, semanticErrorsTotal);

            /* printTable(); */
            printTable2();
            printTree();

            if(lexicalError == 0 && syntaticError == 0 && semanticErrorsTotal == 0){
                codeGeneration();
            }

            /* printParams(); */


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
