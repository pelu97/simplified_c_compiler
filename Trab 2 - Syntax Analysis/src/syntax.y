%define lr.type canonical-lr
%define parse.error verbose
%{
/* C declarations */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/base.h"
#include "../lib/symbol_table.h"
#include "../lib/scope.h"
#include "../lib/tree.h"

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
        t_scope* scope;
    } t_token;

    struct Node* t_node;
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

%right THEN_PREC ELSE_KEY

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
%type <t_node> parameterSimple
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
    declarationList {
        $$ = $1;
        /* printf("Declaration list - initialize tree\n"); */
        initializeTree($$);
    }
;

declarationList:
    declarationList declaration {
        $$ = createNode("Declaration List Declaration");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $2;

    }
    | declaration {
        $$ = $1;
    }
    | declarationList statement {
        $$ = createNode("Declaration List Statement");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $2;
    }
    | statement {
        $$ = $1;
    }
;

declaration:
    varDeclaration {
        $$ = $1;
    }
    | funcDeclaration {
        $$ = $1;
    }
;

varDeclaration:
    TYPE ID DELIM_SEMICOLLON {
        char* temp;
        /* printf("%s %s %s\n", $1.text, $2.text, $3.text); */
        createSymbol($2.text, $1.text, $2.line, $2.column, $2.scope->scopeValue, $2.scope->parentScope, 1);

        /* printf("variable declaration\n"); */

        temp = (char*) malloc(strlen($2.text) + strlen("Variable Declaration - ID: "));

        /* printf("allocated memory\n"); */
        strcpy(temp, "Variable Declaration - ID: ");
        /* printf("copied first string\n"); */
        strcat(temp, $2.text);
        /* printf("concatenated second string\n"); */
        $$ = createNode(temp);
        /* initializeTree($$); */
    }
    | TYPE LIST_TYPE ID DELIM_SEMICOLLON {
        char* temp;
        char* temp2;

        temp = (char*) malloc(strlen($1.text) + strlen($2.text) + 3);
        strcpy(temp, $1.text);
        strcat(temp, " ");
        strcat(temp, $2.text);
        /* printf("%s %s %s %s - %s\n", $1.text, $2.text, $3.text, $4.text, temp); */
        createSymbol($3.text, temp, $3.line, $3.column, $3.scope->scopeValue, $3.scope->parentScope, 1);


        temp2 = (char*) malloc(strlen($3.text) + strlen("Variable Declaration - List ID: "));

        strcpy(temp2, "Variable Declaration - List ID: ");
        strcat(temp2, $3.text);
        $$ = createNode(temp2);
    }
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
    TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R bodyStatement {
        char* temp;
        /* printf("%s %s %s %s - escopo %d %d\n", $1.text, $2.text, $3.text, $5.text, $2.scope->scopeValue, $2.scope->parentScope); */
        createSymbol($2.text, $1.text, $2.line, $2.column, $2.scope->scopeValue, $2.scope->parentScope, 0);

        temp = (char*) malloc(strlen($2.text) + strlen("Function Declaration - ID: "));

        strcpy(temp, "Function Declaration - ID: ");
        strcat(temp, $2.text);
        $$ = createNode(temp);

        addChild($$, 2);

        $$->child[0] = $4;
        $$->child[1] = $6;

    }
    | TYPE LIST_TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R bodyStatement {
        char* temp;
        char* temp2;

        temp = (char*) malloc(sizeof($1.text) + sizeof($2.text) + 3);
        strcpy(temp, $1.text);
        strcat(temp, " ");
        strcat(temp, $2.text);
        /* printf("%s %s %s %s %s - %s - escopo %d %d\n", $1.text, $2.text, $3.text, $4.text, $6.text, temp, $3.scope->scopeValue, $3.scope->parentScope); */
        createSymbol($3.text, temp, $3.line, $3.column, $3.scope->scopeValue, $3.scope->parentScope, 0);

        temp2 = (char*) malloc(strlen($3.text) + strlen("Function Declaration - List ID: "));

        strcpy(temp2, "Function Declaration - List ID: ");
        strcat(temp2, $3.text);
        $$ = createNode(temp2);

        addChild($$, 2);

        $$->child[0] = $5;
        $$->child[1] = $7;
    }
;

parameters:
    parameterList {
        $$ = $1;
    }
    | {
        $$ = createEmptyNode();
    }
;

parameterList:
    parameterList DELIM_COMMA parameterSimple {
        $$ = createNode("Parameters list");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $3;
    }
    | parameterSimple {
        $$ = $1;
    }

;

parameterSimple:
    TYPE ID {
        char* temp;

        createSymbol($2.text, $1.text, $2.line, $2.column, $2.scope->scopeValue, $2.scope->parentScope, 1);

        temp = (char*) malloc(strlen($2.text) + strlen("Parameter declaration - ID: "));

        strcpy(temp, "Parameter declaration - ID: ");
        strcat(temp, $2.text);
        $$ = createNode(temp);

    }
    | TYPE LIST_TYPE ID{
        char* temp;
        char* temp2;

        temp = (char*) malloc(strlen($1.text) + strlen($2.text) + 3);
        strcpy(temp, $1.text);
        strcat(temp, " ");
        strcat(temp, $2.text);

        createSymbol($3.text, temp, $3.line, $3.column, $3.scope->scopeValue, $3.scope->parentScope, 1);

        temp2 = (char*) malloc(strlen($2.text) + strlen("Parameter declaration - ID: "));

        strcpy(temp2, "List parameter declaration - ID: ");
        strcat(temp2, $2.text);
        $$ = createNode(temp2);

    }
;

statement:
    bodyStatement {
        $$ = $1;
    }
    | ifStatement {
        $$ = $1;
    }
    | loopStatement {
        $$ = $1;
    }
    | returnStatement {
        $$ = $1;
    }
    | listStatement DELIM_SEMICOLLON {
        $$ = $1;
    }
    | writeOp DELIM_SEMICOLLON {
        $$ = $1;
    }
    | readOp DELIM_SEMICOLLON {
        $$ = $1;
    }
    | expressionStatement {
        $$ = $1;
    }
    | error {
        $$ = createNode("ERROR");
    }
;

bodyStatement:
    DELIM_CUR_BRACKET_L statementList DELIM_CUR_BRACKET_R {
        $$ = $2;
    }
;

/* body:
    statementList {}
; */

localDeclaration:
    localDeclaration varDeclaration {
        $$ = createNode("Local declaration");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $2;
    }
    | {
        $$ = createEmptyNode();
    }
;

statementList:
    statementList localDeclaration statement {
        $$ = createNode("Statement List");

        addChild($$, 3);

        $$->child[0] = $1;
        $$->child[1] = $2;
        $$->child[2] = $3;

    }
    | {
        $$ = createEmptyNode();
    }
;

ifStatement:
    IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R statement %prec THEN_PREC {
        $$ = createNode("If statement");

        addChild($$, 2);

        $$->child[0] = $3;
        $$->child[1] = $5;
    }
    | IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R statement ELSE_KEY statement {
        $$ = createNode("If-else statement");

        addChild($$, 3);

        $$->child[0] = $3;
        $$->child[1] = $5;
        $$->child[2] = $7;

    }
;

loopStatement:
    FOR_KEY DELIM_PARENT_L expression DELIM_SEMICOLLON simpleExpression DELIM_SEMICOLLON expression DELIM_PARENT_R statement {
        $$ = createNode("For statement");

        addChild($$, 4);

        $$->child[0] = $3;
        $$->child[1] = $5;
        $$->child[2] = $7;
        $$->child[3] = $9;
    }
;

returnStatement:
    RETURN_KEY expression DELIM_SEMICOLLON {
        $$ = createNode("Return statement");

        addChild($$, 1);

        $$->child[0] = $2;
    }
;

expression:
    ID ASSIGN_OP expression {
        $$ = createNode("Assign operation");

        addChild($$, 1);

        $$->child[0] = $3;

    }
    | simpleExpression {
        $$ = $1;
    }
;

/* simpleExpression:
    binExpression {printf("%d\n", $1);}
    | logicBinExpression {printf("%d\n", $1);}
; */

simpleExpression:
    logicBinExpression {
        $$ = $1;
    }
;

/* logicExpression:
    simpleExpression LOGIC_OP simpleExpression {printf("%d %d %d\n", $1, $2, $3);}
    | EXCLA_OP simpleExpression {printf("%d %d\n", $1, $2);}
; */

logicBinExpression:
    logicBinExpression LOGIC_OP logicUnExpression {
        $$ = createNode("Logic Binary expression");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $3;
    }
    | logicUnExpression {
        $$ = $1;
    }
;

logicUnExpression:
    EXCLA_OP logicUnExpression {
        $$ = createNode("Exclamation expression");

        addChild($$, 1);

        $$->child[0] = $2;
    }
    | binExpression {
        $$ = $1;
    }
;

/* logicBinExpression:
    logicBinExpression LOGIC_OP logicBinExpression {printf("%d %d %d\n", $1, $2, $3);}
    | EXCLA_OP simpleExpression {printf("%d %d\n", $1, $2);} */

binExpression:
    binExpression BINARY_OP sumExpression {
        $$ = createNode("Binary expression");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $3;
    }
    | sumExpression {
        $$ = $1;
    }
;

sumExpression:
    sumExpression sumOP mulExpression {
        $$ = createNode("Sum expression");

        addChild($$, 3);

        $$->child[0] = $1;
        $$->child[1] = $2;
        $$->child[2] = $3;


    }
    | mulExpression {
        $$ = $1;
    }
;

mulExpression:
    mulExpression mulOP factor {
        $$ = createNode("Multiplication expression");

        addChild($$, 3);

        addChild($$, 3);

        $$->child[0] = $1;
        $$->child[1] = $2;
        $$->child[2] = $3;
    }
    | factor {
        $$ = $1;
    }
;

sumOP:
    PLUS_OP {
        $$ = createNode("+ Operator");
    }
    | MINUS_OP {
        $$ = createNode("- Operator");
    }
;

mulOP:
    MUL_OP {
        $$ = createNode("* Operator");
    }
    | DIV_OP {
        $$ = createNode("/ Operator");
    }
;

factor:
    ID {
        char* temp;

        temp = (char*) malloc(strlen($1.text) + strlen("Id: ") + 3);

        strcpy(temp, "Id: ");
        strcat(temp, $1.text);

        $$ = createNode(temp);
    }
    | constant {
        $$ = $1;
    }
    | DELIM_PARENT_L simpleExpression DELIM_PARENT_R {
        $$ = $2;
    }
    | functionCall {
        $$ = $1;
    }
    | listExpression {
        $$ = $1;
    }
;

constant:
    INT {
        char* temp;

        temp = (char*) malloc(strlen("Integer: ") + strlen($1.text));
        strcpy(temp, "Integer: ");
        strcat(temp, $1.text);

        $$ = createNode(temp);
    }
    | MINUS_OP INT {
        char* temp;

        temp = (char*) malloc(strlen("Negative Integer: ") + strlen($1.text));
        strcpy(temp, "Negative Integer: ");
        strcat(temp, $1.text);

        $$ = createNode(temp);
    }
    | FLOAT {
        char* temp;

        temp = (char*) malloc(strlen("Float: ") + strlen($1.text));
        strcpy(temp, "Float: ");
        strcat(temp, $1.text);

        $$ = createNode(temp);
    }
    | MINUS_OP FLOAT {
        char* temp;

        temp = (char*) malloc(strlen("Negative Float: ") + strlen($1.text));
        strcpy(temp, "Negative Float: ");
        strcat(temp, $1.text);

        $$ = createNode(temp);
    }
    | NULL_CONST {
        $$ = createNode("Null");
    }
;

functionCall:
    ID DELIM_PARENT_L parametersPass DELIM_PARENT_R {
        $$ = createNode("Function call");

        addChild($$, 1);

        $$->child[0] = $3;
    }
;

parametersPass:
    parametersPass DELIM_COMMA simpleExpression {
        $$ = createNode("Parameters pass");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $3;
    }
    | simpleExpression {
        $$ = $1;
    }
    | {
        $$ = createEmptyNode();
    }
;

writeOp:
    write {
        $$ = $1;
    }
    | writeln {
        $$ = $1;
    }
;

write:
    OUTPUT_KEY DELIM_PARENT_L STRING DELIM_PARENT_R {
        $$ = createNode("Output string");
    }
    | OUTPUT_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R {
        $$ = createNode("Output expression");

        addChild($$, 1);

        $$->child[0] = $3;
    }
;

writeln:
    OUTPUTLN_KEY DELIM_PARENT_L STRING DELIM_PARENT_R {
        $$ = createNode("OutputLn string");
    }
    | OUTPUTLN_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R {
        $$ = createNode("OutputLn expression");

        addChild($$, 1);

        $$->child[0] = $3;
    }
;

readOp:
    INPUT_KEY DELIM_PARENT_L ID DELIM_PARENT_R {
        char* temp;

        temp = (char*) malloc(strlen($3.text) + strlen("Read Id: ") + 3);

        strcpy(temp, "Read Id: ");
        strcat(temp, $3.text);

        $$ = createNode(temp);
    }
;

expressionStatement:
    expression DELIM_SEMICOLLON {
        $$ = $1;
    }
;

listStatement:
    listAssign {
        $$ = $1;
    }
    | listMap {
        $$ = $1;
    }
    | listFilter {
        $$ = $1;
    }
;

listExpression:
    listHeader {
        $$ = $1;
    }
    /* | listTail {printf("%d\n", $1);} */
    | listTailDestructor {
        $$ = $1;
    }
;

listAssign:
    ID ASSIGN_OP ID ASSIGN_LISTOP ID {
        $$ = createNode("List assign");
    }
;

listHeader:
    HEADER_LISTOP ID {
        $$ = createNode("List header");
    }
;

/* listTail:
    EXCLA_OP ID {printf("%d %d\n", $1, $2);}
; */

listTailDestructor:
    TAILDES_LISTOP ID {
        $$ = createNode("List tail destructor");
    }
;

listMap:
    ID ASSIGN_OP ID MAP_LISTOP ID {
        $$ = createNode("List map");
    }
;

listFilter:
    ID ASSIGN_OP ID FILTER_LISTOP ID {
        $$ = createNode("List filter");
    }
;


%%
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
