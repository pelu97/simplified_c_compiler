%define lr.type canonical-lr
%define parse.error verbose
%{
/* C declarations */
#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "symbol_table.h"

extern int yylex();
extern int yylex_destroy();
extern int yyparse();
extern void yyerror(const char* s);
extern FILE* yyin;

//yynerrs //global variable counting errors

%}
/* Yacc/Bison declarations */

//Mudando o formato do token retornado pelo lexico
%union{
    struct Tokens{
        char text[150];
        int line;
        int column;
    } t_token;

    struct Nodes{
        int temp;
    } t_node;
}

/* %left PLUS_OP MINUS_OP
%left MUL_OP DIV_OP
%left LOGIC_OP
%left BINARY_OP
%right EXCLA_OP */


/* Base */
%token <t_token> INT
%token <t_token> FLOAT

/* Identificador */
%token <t_token> ID

/* Tipos */
%token <t_token> TYPE
/* %token INT_TYPE */
/* %token FLOAT_TYPE */
%token <t_token> LIST_TYPE
%token <t_token> STRING

%token <t_token> NULL_CONST

/* Operadores */
/* %token ARITHMETIC_OP */
%left <t_token> PLUS_OP
%left <t_token> MINUS_OP
%left <t_token> DIV_OP
%left <t_token> MUL_OP

%left <t_token> LOGIC_OP
/* %token OR_OP
%token AND_OP */

%left <t_token> BINARY_OP
/* %token LT_OP
%token LE_OP
%token GT_OP
%token GE_OP
%token EQ_OP
%token NE_OP */

%token <t_token> ASSIGN_OP

%right <t_token> EXCLA_OP

/* Controle de fluxo */
/* %token FLOW_KEY */
%token <t_token> IF_KEY
%token <t_token> ELSE_KEY
%token <t_token> FOR_KEY
%token <t_token> RETURN_KEY

/* Entrada e saída */
%token <t_token> INPUT_KEY
%token <t_token> OUTPUT_KEY
%token <t_token> OUTPUTLN_KEY

/* Operadores de lista */
/* %token LIST_OP */
%token <t_token> ASSIGN_LISTOP
%token <t_token> HEADER_LISTOP
%token <t_token> TAILDES_LISTOP
%token <t_token> MAP_LISTOP
%token <t_token> FILTER_LISTOP

/* %token DELIM_PARENT */
%token <t_token> DELIM_PARENT_L
%token <t_token> DELIM_PARENT_R
/* %token DELIM_BRACKET */
%token <t_token> DELIM_BRACKET_L
%token <t_token> DELIM_BRACKET_R
/* %token DELIM_CUR_BRACKET */
%token <t_token> DELIM_CUR_BRACKET_L
%token <t_token> DELIM_CUR_BRACKET_R
%token <t_token> DELIM_COMMA
%token <t_token> DELIM_SEMICOLLON
%token <t_token> DELIM_SQUOTE
%token <t_token> DELIM_DQUOTE

%token <t_token> SINGLE_COMMENT
%token <t_token> MULTI_COMMENT

%token <t_token> FORMAT_BLANKSPACE
%token <t_token> FORMAT_NEWLINE
%token <t_token> FORMAT_TAB

%type <t_node> program
%type <t_node> declarationList
%type <t_node> declaration
%type <t_node> varDeclaration
%type <t_node> funcDeclaration
%type <t_node> parameters
%type <t_node> parameterList
%type <t_node> statement
%type <t_node> bodyStatement
%type <t_node> localDeclaration
%type <t_node> statementList
%type <t_node> ifStatement
%type <t_node> loopStatement
%type <t_node> returnStatement
%type <t_node> expression
%type <t_node> simpleExpression
%type <t_node> logicBinExpression
%type <t_node> logicUnExpression
%type <t_node> binExpression
%type <t_node> sumExpression
%type <t_node> mulExpression
%type <t_node> sumOP
%type <t_node> mulOP
%type <t_node> factor
%type <t_node> constant
%type <t_node> functionCall
%type <t_node> parametersPass
%type <t_node> writeOp
%type <t_node> write
%type <t_node> writeln
%type <t_node> readOp
%type <t_node> expressionStatement
%type <t_node> listStatement
%type <t_node> listExpression
%type <t_node> listAssign
%type <t_node> listHeader
%type <t_node> listTailDestructor
%type <t_node> listMap
%type <t_node> listFilter

/* %token '<<'
%token '>>' */

%%
/* Grammar rules */
/* \{printf[^\}]*\} */
program:
    declarationList {}
;

declarationList:
    declarationList declaration {}
    | declaration {}
;

declaration:
    varDeclaration {}
    | funcDeclaration {}
;

varDeclaration:
    TYPE ID DELIM_SEMICOLLON {
        printf("%s %s %s\n", $1.text, $2.text, $3.text);
    }
    | TYPE LIST_TYPE ID DELIM_SEMICOLLON {}
;

/* varDeclaration:
    TYPE varDeclList DELIM_SEMICOLLON {printf("%d %d %d\n", $1, $2, $3);}
    | TYPE LIST_TYPE varDeclList DELIM_SEMICOLLON {printf("%d %d %d %d\n", $1, $2, $3, $4);}
; */

/* varDeclList:
    varDeclList DELIM_COMMA varDeclId {printf("%d %d\n", $1, $2);}
    | varDeclId {printf("%d\n", $1);}
; */

/* varDeclId :
    ID {printf("%d\n", $1);}
; */

funcDeclaration:
    TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R statement {}
;

parameters:
    parameterList {}
    | {}
;

parameterList:
    parameterList DELIM_COMMA TYPE ID {}
    | parameterList DELIM_COMMA TYPE LIST_TYPE ID {}
    | TYPE ID {}
    | TYPE LIST_TYPE ID {}
;

statement:
    bodyStatement {}
    | ifStatement {}
    | loopStatement {}
    | returnStatement {}
    | listStatement DELIM_SEMICOLLON {}
    | writeOp DELIM_SEMICOLLON {}
    | readOp DELIM_SEMICOLLON {}
    | expressionStatement {}
;

bodyStatement:
    DELIM_CUR_BRACKET_L localDeclaration statementList DELIM_CUR_BRACKET_R {}
;

localDeclaration:
    localDeclaration varDeclaration {}
    | {}
;

statementList:
    statement statementList {}
    | {}
;

ifStatement:
    IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R bodyStatement {}
    | IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R bodyStatement ELSE_KEY bodyStatement {}
;

loopStatement:
    FOR_KEY DELIM_PARENT_L expression DELIM_SEMICOLLON simpleExpression DELIM_SEMICOLLON expression DELIM_PARENT_R bodyStatement {}
;

returnStatement:
    RETURN_KEY expression DELIM_SEMICOLLON {}
;

expression:
    ID ASSIGN_OP expression {}
    | simpleExpression {}
;

/* simpleExpression:
    binExpression {printf("%d\n", $1);}
    | logicBinExpression {printf("%d\n", $1);}
; */

simpleExpression:
    logicBinExpression {}
;

/* logicExpression:
    simpleExpression LOGIC_OP simpleExpression {printf("%d %d %d\n", $1, $2, $3);}
    | EXCLA_OP simpleExpression {printf("%d %d\n", $1, $2);}
; */

logicBinExpression:
    logicBinExpression LOGIC_OP logicUnExpression {}
    | logicUnExpression {}
;

logicUnExpression:
    EXCLA_OP logicUnExpression {}
    | binExpression {}
;

/* logicBinExpression:
    logicBinExpression LOGIC_OP logicBinExpression {printf("%d %d %d\n", $1, $2, $3);}
    | EXCLA_OP simpleExpression {printf("%d %d\n", $1, $2);} */

binExpression:
    binExpression BINARY_OP sumExpression {}
    | sumExpression {}
;

sumExpression:
    sumExpression sumOP mulExpression {}
    | mulExpression {}
;

mulExpression:
    mulExpression mulOP factor {}
    | factor {}
;

sumOP:
    PLUS_OP {}
    | MINUS_OP {}
;

mulOP:
    MUL_OP {}
    | DIV_OP {}
;

factor:
    ID {}
    | constant {}
    | DELIM_PARENT_L simpleExpression DELIM_PARENT_R {}
    | functionCall {}
    | listExpression {}
;

constant:
    INT {}
    | FLOAT {}
;

functionCall:
    ID DELIM_PARENT_L parametersPass DELIM_PARENT_R {}
;

parametersPass:
    parametersPass DELIM_COMMA simpleExpression {}
    | simpleExpression {}
    | {}
;

writeOp:
    write {}
    | writeln {}
;

write:
    OUTPUT_KEY DELIM_PARENT_L STRING DELIM_PARENT_R {}
    | OUTPUT_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R {}
;

writeln:
    OUTPUTLN_KEY DELIM_PARENT_L STRING DELIM_PARENT_R {}
    | OUTPUTLN_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R {}
;

readOp:
    INPUT_KEY DELIM_PARENT_L ID DELIM_PARENT_R {}
;

expressionStatement:
    expression DELIM_SEMICOLLON {}
;

listStatement:
    listAssign {}
    | listMap {}
    | listFilter {}
;

listExpression:
    listHeader {}
    /* | listTail {printf("%d\n", $1);} */
    | listTailDestructor {}
;

listAssign:
    ID ASSIGN_OP ID ASSIGN_LISTOP ID {}
;

listHeader:
    HEADER_LISTOP ID {}
;

/* listTail:
    EXCLA_OP ID {printf("%d %d\n", $1, $2);}
; */

listTailDestructor:
    TAILDES_LISTOP ID {}
;

listMap:
    ID ASSIGN_OP ID MAP_LISTOP ID {}
;

listFilter:
    ID ASSIGN_OP ID FILTER_LISTOP ID {}
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

    /* createSymbol("Teste");
    printTable(); */


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