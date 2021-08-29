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
    STRING = 262,                  /* STRING  */
    NULL_CONST = 263,              /* NULL_CONST  */
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
    ASSIGN_LISTOP = 279,           /* ASSIGN_LISTOP  */
    HEADER_LISTOP = 280,           /* HEADER_LISTOP  */
    TAILDES_LISTOP = 281,          /* TAILDES_LISTOP  */
    MAP_LISTOP = 282,              /* MAP_LISTOP  */
    FILTER_LISTOP = 283,           /* FILTER_LISTOP  */
    DELIM_PARENT = 284,            /* DELIM_PARENT  */
    DELIM_BRACKET = 285,           /* DELIM_BRACKET  */
    DELIM_CUR_BRACKET = 286,       /* DELIM_CUR_BRACKET  */
    DELIM_COMMA = 287,             /* DELIM_COMMA  */
    DELIM_SEMICOLLON = 288,        /* DELIM_SEMICOLLON  */
    DELIM_SQUOTE = 289,            /* DELIM_SQUOTE  */
    DELIM_DQUOTE = 290,            /* DELIM_DQUOTE  */
    SINGLE_COMMENT = 291,          /* SINGLE_COMMENT  */
    MULTI_COMMENT = 292,           /* MULTI_COMMENT  */
    FORMAT_BLANKSPACE = 293,       /* FORMAT_BLANKSPACE  */
    FORMAT_NEWLINE = 294,          /* FORMAT_NEWLINE  */
    FORMAT_TAB = 295,              /* FORMAT_TAB  */
    IF_KEYWORD = 296,              /* IF_KEYWORD  */
    ELSE_KEYWORD = 297,            /* ELSE_KEYWORD  */
    FOR_KEYWORD = 298,             /* FOR_KEYWORD  */
    RETURN_KEYWORD = 299,          /* RETURN_KEYWORD  */
    WRITE_KEYWORD = 300,           /* WRITE_KEYWORD  */
    WRITELN_KEYWORD = 301,         /* WRITELN_KEYWORD  */
    READ_KEYWORD = 302             /* READ_KEYWORD  */
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
#define NULL_CONST 263
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
#define ASSIGN_LISTOP 279
#define HEADER_LISTOP 280
#define TAILDES_LISTOP 281
#define MAP_LISTOP 282
#define FILTER_LISTOP 283
#define DELIM_PARENT 284
#define DELIM_BRACKET 285
#define DELIM_CUR_BRACKET 286
#define DELIM_COMMA 287
#define DELIM_SEMICOLLON 288
#define DELIM_SQUOTE 289
#define DELIM_DQUOTE 290
#define SINGLE_COMMENT 291
#define MULTI_COMMENT 292
#define FORMAT_BLANKSPACE 293
#define FORMAT_NEWLINE 294
#define FORMAT_TAB 295
#define IF_KEYWORD 296
#define ELSE_KEYWORD 297
#define FOR_KEYWORD 298
#define RETURN_KEYWORD 299
#define WRITE_KEYWORD 300
#define WRITELN_KEYWORD 301
#define READ_KEYWORD 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_SYNTAX_TAB_H_INCLUDED  */
