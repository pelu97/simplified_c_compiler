/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SRC_SYNTAX_TAB_H_INCLUDED
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
    LIST_TYPE = 262,               /* LIST_TYPE  */
    STRING = 263,                  /* STRING  */
    NULL_CONST = 264,              /* NULL_CONST  */
    PLUS_OP = 265,                 /* PLUS_OP  */
    MINUS_OP = 266,                /* MINUS_OP  */
    DIV_OP = 267,                  /* DIV_OP  */
    MUL_OP = 268,                  /* MUL_OP  */
    LOGIC_OP = 269,                /* LOGIC_OP  */
    BINARY_OP = 270,               /* BINARY_OP  */
    ASSIGN_OP = 271,               /* ASSIGN_OP  */
    EXCLA_OP = 272,                /* EXCLA_OP  */
    IF_KEY = 273,                  /* IF_KEY  */
    ELSE_KEY = 274,                /* ELSE_KEY  */
    FOR_KEY = 275,                 /* FOR_KEY  */
    RETURN_KEY = 276,              /* RETURN_KEY  */
    INPUT_KEY = 277,               /* INPUT_KEY  */
    OUTPUT_KEY = 278,              /* OUTPUT_KEY  */
    OUTPUTLN_KEY = 279,            /* OUTPUTLN_KEY  */
    ASSIGN_LISTOP = 280,           /* ASSIGN_LISTOP  */
    HEADER_LISTOP = 281,           /* HEADER_LISTOP  */
    TAILDES_LISTOP = 282,          /* TAILDES_LISTOP  */
    MAP_LISTOP = 283,              /* MAP_LISTOP  */
    FILTER_LISTOP = 284,           /* FILTER_LISTOP  */
    DELIM_PARENT_L = 285,          /* DELIM_PARENT_L  */
    DELIM_PARENT_R = 286,          /* DELIM_PARENT_R  */
    DELIM_BRACKET_L = 287,         /* DELIM_BRACKET_L  */
    DELIM_BRACKET_R = 288,         /* DELIM_BRACKET_R  */
    DELIM_CUR_BRACKET_L = 289,     /* DELIM_CUR_BRACKET_L  */
    DELIM_CUR_BRACKET_R = 290,     /* DELIM_CUR_BRACKET_R  */
    DELIM_COMMA = 291,             /* DELIM_COMMA  */
    DELIM_SEMICOLLON = 292,        /* DELIM_SEMICOLLON  */
    DELIM_SQUOTE = 293,            /* DELIM_SQUOTE  */
    DELIM_DQUOTE = 294,            /* DELIM_DQUOTE  */
    SINGLE_COMMENT = 295,          /* SINGLE_COMMENT  */
    MULTI_COMMENT = 296,           /* MULTI_COMMENT  */
    FORMAT_BLANKSPACE = 297,       /* FORMAT_BLANKSPACE  */
    FORMAT_NEWLINE = 298,          /* FORMAT_NEWLINE  */
    FORMAT_TAB = 299               /* FORMAT_TAB  */
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
#define LIST_TYPE 262
#define STRING 263
#define NULL_CONST 264
#define PLUS_OP 265
#define MINUS_OP 266
#define DIV_OP 267
#define MUL_OP 268
#define LOGIC_OP 269
#define BINARY_OP 270
#define ASSIGN_OP 271
#define EXCLA_OP 272
#define IF_KEY 273
#define ELSE_KEY 274
#define FOR_KEY 275
#define RETURN_KEY 276
#define INPUT_KEY 277
#define OUTPUT_KEY 278
#define OUTPUTLN_KEY 279
#define ASSIGN_LISTOP 280
#define HEADER_LISTOP 281
#define TAILDES_LISTOP 282
#define MAP_LISTOP 283
#define FILTER_LISTOP 284
#define DELIM_PARENT_L 285
#define DELIM_PARENT_R 286
#define DELIM_BRACKET_L 287
#define DELIM_BRACKET_R 288
#define DELIM_CUR_BRACKET_L 289
#define DELIM_CUR_BRACKET_R 290
#define DELIM_COMMA 291
#define DELIM_SEMICOLLON 292
#define DELIM_SQUOTE 293
#define DELIM_DQUOTE 294
#define SINGLE_COMMENT 295
#define MULTI_COMMENT 296
#define FORMAT_BLANKSPACE 297
#define FORMAT_NEWLINE 298
#define FORMAT_TAB 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "./src/syntax.y"

    struct Tokens{
        char text[150];
        int line;
        int column;
    } t_token;

    struct Nodes{
        int temp;
    } t_node;

#line 167 "./src/syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_SYNTAX_TAB_H_INCLUDED  */
