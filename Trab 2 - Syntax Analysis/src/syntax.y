%define lr.type canonical-lr
%define parse.error verbose
%{
/* C declarations */
#include <stdio.h>
#include <stdlib.h>
#include "format.h"

extern int yylex();
extern int yylex_destroy();
extern int yyparse();
extern void yyerror(const char* s);
extern FILE* yyin;

%}
/* Yacc/Bison declarations */

/* Base */
%token INT
%token FLOAT

/* Identificador */
%token ID

/* Tipos */
%token TYPE
/* %token INT_TYPE */
/* %token FLOAT_TYPE */
%token LIST_TYPE
%token STRING

%token NULL_CONST

/* Operadores */
/* %token ARITHMETIC_OP */
%token PLUS_OP
%token MINUS_OP
%token DIV_OP
%token MUL_OP

%token LOGIC_OP
/* %token OR_OP
%token AND_OP */

%token BINARY_OP
/* %token LT_OP
%token LE_OP
%token GT_OP
%token GE_OP
%token EQ_OP
%token NE_OP */

%token ASSIGN_OP

%token EXCLA_OP

/* Controle de fluxo */
/* %token FLOW_KEY */
%token IF_KEY
%token ELSE_KEY
%token FOR_KEY
%token RETURN_KEY

/* Entrada e saída */
%token INPUT_KEY
%token OUTPUT_KEY
%token OUTPUTLN_KEY

/* Operadores de lista */
/* %token LIST_OP */
%token ASSIGN_LISTOP
%token HEADER_LISTOP
%token TAILDES_LISTOP
%token MAP_LISTOP
%token FILTER_LISTOP

/* %token DELIM_PARENT */
%token DELIM_PARENT_L
%token DELIM_PARENT_R
/* %token DELIM_BRACKET */
%token DELIM_BRACKET_L
%token DELIM_BRACKET_R
/* %token DELIM_CUR_BRACKET */
%token DELIM_CUR_BRACKET_L
%token DELIM_CUR_BRACKET_R
%token DELIM_COMMA
%token DELIM_SEMICOLLON
%token DELIM_SQUOTE
%token DELIM_DQUOTE

%token SINGLE_COMMENT
%token MULTI_COMMENT

%token FORMAT_BLANKSPACE
%token FORMAT_NEWLINE
%token FORMAT_TAB


/* %token '<<'
%token '>>' */

%%
/* Grammar rules */
program:
    declarationList { printf("%d\n", $1); }
;

declarationList:
    declarationList declaration {printf("%d %d\n", $1, $2);}
    | declaration {printf("%d\n", $1);}
;

declaration:
    varDeclaration {printf("%d\n", $1);}
    | funcDeclaration {printf("%d\n", $1);}
;

varDeclaration:
    TYPE varDeclList DELIM_SEMICOLLON {printf("%d %d %d\n", $1, $2, $3);}
    | TYPE LIST_TYPE varDeclList DELIM_SEMICOLLON {printf("%d %d %d %d\n", $1, $2, $3, $4);}
;

varDeclList:
    varDeclList DELIM_COMMA varDeclId {printf("%d %d\n", $1, $2);}
    | varDeclId {printf("%d\n", $1);}
;

varDeclId :
    ID {printf("%d\n", $1);}
;

funcDeclaration:
    TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R statement {printf("%d %d %d %d %d %d\n", $1, $2, $3, $4, $5, $6);}
;

parameters:
    parameterList {printf("%d\n", $1);}
    | {}
;

parameterList:
    parameterList DELIM_COMMA TYPE ID {printf("%d %d %d\n", $1, $2, $3);}
    | TYPE ID {printf("%d %d\n", $1, $2);}
;

statement:
    bodyStatement {printf("%d\n", $1);}
    | ifStatement {printf("%d\n", $1);}
    | loopStatement {printf("%d\n", $1);}
    | returnStatement {printf("%d\n", $1);}
    | listStatement DELIM_SEMICOLLON {printf("%d\n", $1);}
    | writeOp DELIM_SEMICOLLON {printf("%d\n", $1);}
    | readOp DELIM_SEMICOLLON {printf("%d\n", $1);}
    | expressionStatement {printf("%d\n", $1);}
;

bodyStatement:
    DELIM_CUR_BRACKET_L localDeclaration statementList DELIM_CUR_BRACKET_R {printf("%d %d %d %d\n", $1, $2, $3, $4);}
;

localDeclaration:
    localDeclaration varDeclaration {printf("%d %d\n", $1, $2);}
    | {}
;

statementList:
    statement statementList {printf("%d %d\n", $1, $2);}
    | {}
;

ifStatement:
    IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R bodyStatement {printf("%d %d %d %d %d\n", $1, $2, $3, $4, $5);}
    | IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R bodyStatement ELSE_KEY bodyStatement {printf("%d %d %d %d %d %d %d\n", $1, $2, $3, $4, $5, $6, $7);}
;

loopStatement:
    FOR_KEY DELIM_PARENT_L expression DELIM_SEMICOLLON simpleExpression DELIM_SEMICOLLON expression DELIM_PARENT_R bodyStatement {printf("%d %d %d %d %d %d %d %d %d\n", $1, $2, $3, $4, $5, $6, $7, $8, $9);}
;

returnStatement:
    RETURN_KEY expression DELIM_SEMICOLLON {printf("%d %d\n", $1, $2);}
;

expression:
    ID ASSIGN_OP expression {printf("%d %d %d\n", $1, $2, $3);}
    | simpleExpression {printf("%d\n", $1);}
;

/* simpleExpression:
    binExpression {printf("%d\n", $1);}
    | logicBinExpression {printf("%d\n", $1);}
; */

simpleExpression:
    logicBinExpression {printf("%d\n", $1);}
;

/* logicExpression:
    simpleExpression LOGIC_OP simpleExpression {printf("%d %d %d\n", $1, $2, $3);}
    | EXCLA_OP simpleExpression {printf("%d %d\n", $1, $2);}
; */

logicBinExpression:
    logicBinExpression LOGIC_OP logicUnExpression {printf("%d %d %d\n", $1, $2, $3);}
    | logicUnExpression {printf("%d\n", $1);}
;

logicUnExpression:
    EXCLA_OP logicUnExpression {printf("%d %d\n", $1, $2);}
    | binExpression {printf("%d\n", $1);}
;

/* logicBinExpression:
    logicBinExpression LOGIC_OP logicBinExpression {printf("%d %d %d\n", $1, $2, $3);}
    | EXCLA_OP simpleExpression {printf("%d %d\n", $1, $2);} */

binExpression:
    binExpression BINARY_OP sumExpression {printf("%d %d %d\n", $1, $2, $3);}
    | sumExpression {printf("%d\n", $1);}
;

sumExpression:
    sumExpression sumOP mulExpression {printf("%d %d %d\n", $1, $2, $3);}
    | mulExpression {printf("%d\n", $1);}
;

mulExpression:
    mulExpression mulOP factor {printf("%d %d %d\n", $1, $2, $3);}
    | factor {printf("%d\n", $1);}
;

sumOP:
    PLUS_OP {printf("%d\n", $1);}
    | MINUS_OP {printf("%d\n", $1);}
;

mulOP:
    MUL_OP {printf("%d\n", $1);}
    | DIV_OP {printf("%d\n", $1);}
;

factor:
    ID {printf("%d\n", $1);}
    | constant {printf("%d\n", $1);}
    | DELIM_PARENT_L simpleExpression DELIM_PARENT_R {printf("%d %d %d\n", $1, $2, $3);}
    | functionCall {printf("%d\n", $1);}
    | listExpression {printf("%d\n", $1);}
;

constant:
    INT {printf("%d\n", $1);}
    | FLOAT {printf("%d\n", $1);}
;

functionCall:
    ID DELIM_PARENT_L parametersPass DELIM_PARENT_R {printf("%d %d %d %d\n", $1, $2, $3, $4);}
;

parametersPass:
    parametersPass DELIM_COMMA simpleExpression {printf("%d %d %d\n", $1, $2, $3);}
    | simpleExpression {printf("%d\n", $1);}
    | {}
;

writeOp:
    write {printf("%d\n", $1);}
    | writeln {printf("%d\n", $1);}
;

write:
    OUTPUT_KEY DELIM_PARENT_L STRING DELIM_PARENT_R {printf("%d %d %d\n", $1, $2, $3);}
    | OUTPUT_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R {printf("%d %d %d\n", $1, $2, $3);}
;

writeln:
    OUTPUTLN_KEY DELIM_PARENT_L STRING DELIM_PARENT_R {printf("%d %d %d\n", $1, $2, $3);}
    | OUTPUTLN_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R {printf("%d %d %d\n", $1, $2, $3);}
;

readOp:
    INPUT_KEY DELIM_PARENT_L ID DELIM_PARENT_R {printf("%d %d %d\n", $1, $2, $3);}
;

expressionStatement:
    expression DELIM_SEMICOLLON {printf("%d\n", $1);}
;

listStatement:
    listAssign {printf("%d\n", $1);}
    | listMap {printf("%d\n", $1);}
    | listFilter {printf("%d\n", $1);}
;

listExpression:
    listHeader {printf("%d\n", $1);}
    /* | listTail {printf("%d\n", $1);} */
    | listTailDestructor {printf("%d\n", $1);}
;

listAssign:
    ID ASSIGN_OP ID ASSIGN_LISTOP ID {printf("%d %d %d %d %d\n", $1, $2, $3, $4, $5);}
;

listHeader:
    HEADER_LISTOP ID {printf("%d %d\n", $1, $2);}
;

/* listTail:
    EXCLA_OP ID {printf("%d %d\n", $1, $2);}
; */

listTailDestructor:
    TAILDES_LISTOP ID {printf("%d %d\n", $1, $2);}
;

listMap:
    ID ASSIGN_OP ID MAP_LISTOP ID {printf("%d %d %d %d %d\n", $1, $2, $3, $4, $5);}
;

listFilter:
    ID ASSIGN_OP ID FILTER_LISTOP ID {printf("%d %d %d %d %d\n", $1, $2, $3, $4, $5);}
;


%%
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
