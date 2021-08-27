%define lr.type canonical-lr
%{
/* C declarations */
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
%}
/* Yacc/Bison declarations */

%token INT
%token FLOAT

%token ID

%token TYPE
%token STRING

%token NULL

%token ARITHMETIC_OP
%token LOGIC_OP
%token BINARY_OP
%token ASSIGN_OP
%token EXCLA_OP

%token FLOW_KEY

%token INPUT_KEY
%token OUTPUT_KEY

%token LIST_OP

%token DELIM_PARENT
%token DELIM_BRACKET
%token DELIM_CUR_BRACKET
%token DELIM_COMMA
%token DELIM_SEMICOLLON
%token DELIM_SQUOTE
%token DELIM_DQUOTE

%token SINGLE_COMMENT
%token MULTI_COMMENT

%token FORMAT_BLANKSPACE
%token FORMAT_NEWLINE
%token FORMAT_TAB


%%
/* Grammar rules */
program:
    declarationList { printf('%d', $1); }
;

declarationList:
    declarationList declaration {printf('%d %d', $1, $2);}
    | declaration {printf('%d', $1);}
;

declaration:
    varDeclaration {printf('%d', $1);}
    | funcDeclaration {printf('%d', $1);}
;

varDeclaration:
    TYPE varDeclList {printf('%d %d', $1, $2);}
;

varDeclList:
    varDeclList varDeclId {printf('%d %d', $1, $2);}
    | varDeclId {printf('%d', $1);}
;

varDeclId :
    ID {printf('%d', $1);}
;

funcDeclaration:
    TYPE ID '(' parameters ')' statement {printf('%d %d %d %d %d %d', $1, $2, $3, $4, $5, $6);}
;

parameters:
    parameterList {printf('%d', $1);}
    | {}
;

parameterList:
    parameterList ',' TYPE ID {printf('%d %d %d', $1, $2, $3);}
    | TYPE ID {printf('%d %d', $1, $2);}
;

statement:
    bodyStatement {printf('%d', $1);}
    | ifStatement {printf('%d', $1);}
    | loopStatement {printf('%d', $1);}
    | listStatement {printf('%d', $1);}
;

bodyStatement:
    '{' localDeclaration statementList '}' {printf('%d %d %d %d', $1, $2, $3, $4);}
;

localDeclaration:
    localDeclaration varDeclaration {printf('%d %d', $1, $2);}
    | {}
;

statementList:
    statementList statementList {printf('%d %d', $1, $2);}
    | {}
;

ifStatement:
    IF_KEYWORD '(' simpleExpression ')' bodyStatement {printf('%d %d %d %d %d', $1, $2, $3, $4, $5);}
    | IF_KEYWORD '(' simpleExpression ')' bodyStatement ELSE_KEYWORD bodyStatement {printf('%d %d %d %d %d %d %d', $1, $2, $3, $4, $5, $6, $7);}
;

loopStatement:
    FOR_KEYWORD '(' expression ';' simpleExpression ';' expression ')' bodyStatement {printf('%d %d %d %d %d %d %d %d %d', $1, $2, $3, $4, $5, $6, $7, $8, $9);}
;

returnStatement:
    RETURN_KEYWORD expression {printf('%d %d', $1, $2);}
;

expression:
    ID ASSIGN_OP expression {printf('%d %d %d', $1, $2, $3);}
    | simpleExpression {printf('%d', $1);}
;

simpleExpression:
    binExpression {printf('%d', $1);}
    | logicExpression {printf('%d', $1);}
;

logicExpression:
    simpleExpression LOGIC_OP simpleExpression {printf('%d %d %d', $1, $2, $3);}
    | EXCLA_OP simpleExpression {printf('%d %d', $1, $2);}
;

binExpression:
    sumExpression BINARY_OP sumExpression {printf('%d %d %d', $1, $2, $3);}
    | sumExpression {printf('%d', $1);}
;

sumExpression:
    sumExpression sumOP mulExpression {printf('%d %d %d', $1, $2, $3);}
    | mulExpression {printf('%d', $1);}
;

mulExpression:
    mulExpression mulOP factor {printf('%d %d %d', $1, $2, $3);}
    | factor {printf('%d', $1);}
;

sumOP:
    '+' {printf('%d', $1);}
    | '-' {printf('%d', $1);}
;

mulOP:
    '*' {printf('%d', $1);}
    | '/' {printf('%d', $1);}
;

factor:
    ID {printf('%d', $1);}
    | functionCall {printf('%d', $1);}
    | '(' simpleExpression ')' {printf('%d %d %d', $1, $2, $3);}
;

functionCall:
    ID '(' parameters ')' {printf('%d %d %d %d', $1, $2, $3, $4);}
;

writeOp:
    write {printf('%d', $1);}
    | writeln {printf('%d', $1);}
;

write:
    'write(' STRING ')' {printf('%d %d %d', $1, $2, $3);}
    | 'write(' simpleExpression ')' {printf('%d %d %d', $1, $2, $3);}
;

writeln:
    'writeln(' STRING ')' {printf('%d %d %d', $1, $2, $3);}
    | 'writeln(' simpleExpression ')' {printf('%d %d %d', $1, $2, $3);}
;

read:
    'read(' ID ')' {printf('%d %d %d', $1, $2, $3);}
;

listStatement:
    listAssign {printf('%d', $1);}
    | listHeader {printf('%d', $1);}
    | listTail {printf('%d', $1);}
    | listTailDestructor {printf('%d', $1);}
    | listMap {printf('%d', $1);}
    | listFilter {printf('%d', $1);}
;

listAssign:
    ID ASSIGN_OP ID ':' ID {printf('%d %d %d %d %d', $1, $2, $3, $4, $5);}
;

listHeader:
    '?' ID {printf('%d %d', $1, $2);}
;

listTail:
    '!' ID {printf('%d %d', $1, $2);}
;

listTailDestructor:
    '%' ID {printf('%d %d', $1, $2);}
;

listMap:
    ID ASSIGN_OP ID '>>' ID {printf('%d %d %d %d %d', $1, $2, $3, $4, $5);}
;

listFilter:
    ID ASSIGN_OP ID '<<' ID {printf('%d %d %d %d %d', $1, $2, $3, $4, $5);}
;


%%
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
