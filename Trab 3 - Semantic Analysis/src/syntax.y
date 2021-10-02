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
#include "../lib/semantic.h"

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
-check function parameters: quantity and types on every use;
-check operators arguments types;

--Scope:
-check if variables used (identifiers) have been declared inside the scope or in any parent scope;

--Main
-detect existence of main function;
--Checando, mas poderia registrar a linha do registro;
--Poderia estender parte da checagem para todas as funções - verificar e informar caso ocorram redefinições de funções


---Notes:
-Function parameters: preciso armazenar quantos parâmetros e os tipos deles no registro de funções na tabela de símbolos, para que seja possível
verificar se as chamadas à função estão corretas;
Talvez uma lista de um struct próprio para isso; ou talvez um vetor de strings e uma variável para armazenar a quantidade, onde cada string é o tipo
Parâmetros estão sendo armazenados - vetor de símbolos, é possível acessar o que quiser
*/

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

    /* t_token_t t_token; */

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
        $$ = createNode("Declaration List - Declaration");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $2;

    }
    | declaration {
        $$ = $1;
    }
    | declarationList statement {
        $$ = createNode("Declaration List - Statement");

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

        temp = (char*) malloc(strlen($2.text) + strlen("Variable Declaration - ID: ") + 1);

        /* printf("allocated memory\n"); */
        strcpy(temp, "Variable Declaration - ID: ");
        /* printf("copied first string\n"); */
        strcat(temp, $2.text);
        /* printf("concatenated second string\n"); */

        temp = add_color(temp, COLOR_GREEN);

        $$ = createNode(temp);
        /* initializeTree($$); */

        freeScopeToken($2.scope);
        free(temp);

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


        temp2 = (char*) malloc(strlen($3.text) + strlen("Variable Declaration - List Type ID: ") + 1);

        strcpy(temp2, "Variable Declaration - List Type ID: ");
        strcat(temp2, $3.text);

        temp2 = add_color(temp2, COLOR_GREEN);

        $$ = createNode(temp2);

        freeScopeToken($3.scope);
        free(temp);
        free(temp2);

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
        t_symbol* symbol;
        /* printf("%s %s %s %s - escopo %d %d\n", $1.text, $2.text, $3.text, $5.text, $2.scope->scopeValue, $2.scope->parentScope); */
        symbol = createSymbol($2.text, $1.text, $2.line, $2.column, $2.scope->scopeValue, $2.scope->parentScope, 0);

        temp = (char*) malloc(strlen($2.text) + strlen("Function Declaration - ID: ") + 1);

        strcpy(temp, "Function Declaration - ID: ");
        strcat(temp, $2.text);

        temp = add_color(temp, COLOR_GREEN);

        $$ = createNode(temp);

        addChild($$, 2);

        $$->child[0] = $4;
        $$->child[1] = $6;

        freeScopeToken($2.scope);
        free(temp);

        /* printf("function declaration test\n"); */

        installParam(symbol);

    }
    | TYPE LIST_TYPE ID DELIM_PARENT_L parameters DELIM_PARENT_R bodyStatement {
        char* temp;
        char* temp2;
        t_symbol* symbol;

        temp = (char*) malloc(sizeof($1.text) + sizeof($2.text) + 3);
        strcpy(temp, $1.text);
        strcat(temp, " ");
        strcat(temp, $2.text);
        /* printf("%s %s %s %s %s - %s - escopo %d %d\n", $1.text, $2.text, $3.text, $4.text, $6.text, temp, $3.scope->scopeValue, $3.scope->parentScope); */
        symbol = createSymbol($3.text, temp, $3.line, $3.column, $3.scope->scopeValue, $3.scope->parentScope, 0);

        temp2 = (char*) malloc(strlen($3.text) + strlen("Function Declaration - List Type ID: ") + 1);

        strcpy(temp2, "Function Declaration - List Type ID: ");
        strcat(temp2, $3.text);

        temp2 = add_color(temp2, COLOR_GREEN);

        $$ = createNode(temp2);

        addChild($$, 2);

        $$->child[0] = $5;
        $$->child[1] = $7;

        freeScopeToken($3.scope);
        free(temp);
        free(temp2);

        installParam(symbol);
    }
;

parameters:
    parameterList {
        /* printf("parameters of function declaration test\n"); */
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
        t_symbol* symbol;

        symbol = createSymbol($2.text, $1.text, $2.line, $2.column, lastScopeValue+1, $2.scope->scopeValue, 1);
        /* $2.scope->scopeValue lastScopeValue+1 $2.scope->parentScope*/
        temp = (char*) malloc(strlen($2.text) + strlen("Parameter Declaration - ID: ") + 3);

        strcpy(temp, "Parameter Declaration - ID: ");
        strcat(temp, $2.text);

        temp = add_color(temp, COLOR_GREEN);

        $$ = createNode(temp);

        freeScopeToken($2.scope);
        free(temp);


        addParam(symbol);

    }
    | TYPE LIST_TYPE ID{
        char* temp;
        char* temp2;
        t_symbol* symbol;

        temp = (char*) malloc(strlen($1.text) + strlen($2.text) + 3);
        strcpy(temp, $1.text);
        strcat(temp, " ");
        strcat(temp, $2.text);

        symbol = createSymbol($3.text, temp, $3.line, $3.column, lastScopeValue+1, $3.scope->scopeValue, 1);
        /* $3.scope->scopeValue lastScopeValue+1 $3.scope->parentScope*/
        temp2 = (char*) malloc(strlen($3.text) + strlen("Parameter Declaration - List Type ID: ") + 3);

        strcpy(temp2, "Parameter Declaration - List Type ID: ");
        strcat(temp2, $3.text);

        temp2 = add_color(temp2, COLOR_GREEN);

        $$ = createNode(temp2);

        freeScopeToken($3.scope);
        free(temp);
        free(temp2);

        addParam(symbol);

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
        $$ = createNode(COLOR_RED "SYNTAX ERROR" COLOR_RESET);
    }
;

bodyStatement:
    DELIM_CUR_BRACKET_L statementList DELIM_CUR_BRACKET_R {
        $$ = $2;
        freeScopeToken($1.scope);
    }
;

/* body:
    statementList {}
; */

localDeclaration:
    localDeclaration varDeclaration {
        $$ = createNode("Local Declaration");

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
        $$ = createNode(COLOR_BLUE "If Statement" COLOR_RESET);

        addChild($$, 2);

        $$->child[0] = $3;
        $$->child[1] = $5;
    }
    | IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R statement ELSE_KEY statement {
        $$ = createNode(COLOR_BLUE "If-Else Statement" COLOR_RESET);

        addChild($$, 3);

        $$->child[0] = $3;
        $$->child[1] = $5;
        $$->child[2] = $7;

    }
;

loopStatement:
    FOR_KEY DELIM_PARENT_L expression DELIM_SEMICOLLON simpleExpression DELIM_SEMICOLLON expression DELIM_PARENT_R statement {
        $$ = createNode(COLOR_BLUE "For Statement" COLOR_RESET);

        addChild($$, 4);

        $$->child[0] = $3;
        $$->child[1] = $5;
        $$->child[2] = $7;
        $$->child[3] = $9;
    }
;

returnStatement:
    RETURN_KEY expression DELIM_SEMICOLLON {
        $$ = createNode(COLOR_BLUE "Return Statement" COLOR_RESET);

        addChild($$, 1);

        $$->child[0] = $2;
    }
;

expression:
    ID ASSIGN_OP expression {
        $$ = createNode("Assign Operation");

        addChild($$, 1);

        $$->child[0] = $3;
        freeScopeToken($1.scope);

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
        $$ = createNode("Logic Binary Expression");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $3;

        addNodeType($$, "logic");

    }
    | logicUnExpression {
        $$ = $1;
    }
;

logicUnExpression:
    EXCLA_OP logicUnExpression {
        $$ = createNode("Exclamation Expression");

        addChild($$, 1);

        $$->child[0] = $2;

        addNodeType($$, "logic");

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
        $$ = createNode("Binary Expression");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $3;

        addNodeType($$, "binary");

    }
    | sumExpression {
        $$ = $1;
    }
;

sumExpression:
    sumExpression sumOP mulExpression {
        $$ = createNode("Sum Expression");

        addChild($$, 3);

        $$->child[0] = $1;
        $$->child[1] = $2;
        $$->child[2] = $3;

        addNodeTypeChildren($$);
    }
    | mulExpression {
        $$ = $1;
    }
;

mulExpression:
    mulExpression mulOP factor {
        $$ = createNode("Multiplication Expression");

        addChild($$, 3);

        addChild($$, 3);

        $$->child[0] = $1;
        $$->child[1] = $2;
        $$->child[2] = $3;

        addNodeTypeChildren($$);
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

        temp = (char*) malloc(strlen($1.text) + strlen("ID:  ") + 3);

        strcpy(temp, "ID:  ");
        strcat(temp, $1.text);

        temp = add_color(temp, COLOR_YELLOW);

        $$ = createNode(temp);

        freeScopeToken($1.scope);
        free(temp);

        addNodeTypeId($$, $1.text);
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

        temp = (char*) malloc(strlen("Constant Integer: ") + strlen($1.text) + 1);
        strcpy(temp, "Constant Integer: ");
        strcat(temp, $1.text);

        temp = add_color(temp, COLOR_YELLOW);

        $$ = createNode(temp);

        free(temp);

        addNodeType($$, "int");
    }
    | MINUS_OP INT {
        char* temp;

        temp = (char*) malloc(strlen("Constant Negative Integer: ") + strlen($2.text) + 1);
        strcpy(temp, "Constant Negative Integer: ");
        strcat(temp, $2.text);

        temp = add_color(temp, COLOR_YELLOW);

        $$ = createNode(temp);

        free(temp);

        addNodeType($$, "int");
    }
    | FLOAT {
        char* temp;

        temp = (char*) malloc(strlen("Constant Float: ") + strlen($1.text) + 1);
        strcpy(temp, "Constant Float: ");
        strcat(temp, $1.text);

        temp = add_color(temp, COLOR_YELLOW);

        $$ = createNode(temp);

        free(temp);

        addNodeType($$, "float");
    }
    | MINUS_OP FLOAT {
        char* temp;

        temp = (char*) malloc(strlen("Constant Negative Float: ") + strlen($2.text) + 1);
        strcpy(temp, "Constant Negative Float: ");
        strcat(temp, $2.text);

        temp = add_color(temp, COLOR_YELLOW);

        $$ = createNode(temp);

        free(temp);

        addNodeType($$, "float");
    }
    | NULL_CONST {
        char* temp;

        temp = malloc(strlen("Constant NULL") + 1);
        strcpy(temp, "Constant NULL");

        temp = add_color(temp, COLOR_YELLOW);

        $$ = createNode(temp);

        free(temp);

        addNodeType($$, "null");
    }
;

functionCall:
    ID DELIM_PARENT_L parametersPass DELIM_PARENT_R {
        char* temp;

        temp = (char*) malloc(strlen("Function Call - ID: ") + strlen($1.text) + 1);
        strcpy(temp, "Function Call - ID: ");
        strcat(temp, $1.text);

        $$ = createNode(temp);

        addChild($$, 1);

        $$->child[0] = $3;
        freeScopeToken($1.scope);
        free(temp);

        addFunctionName($$, $1.text);

        checkFunctionCall($$);
    }
;

parametersPass:
    parametersPass DELIM_COMMA simpleExpression {
        $$ = createNode("Parameters Passing");

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
        $$ = createNode(COLOR_BLUE "Output String" COLOR_RESET);
    }
    | OUTPUT_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R {
        $$ = createNode(COLOR_BLUE "Output Expression" COLOR_RESET);

        addChild($$, 1);

        $$->child[0] = $3;
    }
;

writeln:
    OUTPUTLN_KEY DELIM_PARENT_L STRING DELIM_PARENT_R {
        $$ = createNode(COLOR_BLUE "OutputLn String" COLOR_RESET);
    }
    | OUTPUTLN_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R {
        $$ = createNode(COLOR_BLUE "OutputLn Expression" COLOR_RESET);

        addChild($$, 1);

        $$->child[0] = $3;
    }
;

readOp:
    INPUT_KEY DELIM_PARENT_L ID DELIM_PARENT_R {
        char* temp;

        temp = (char*) malloc(strlen($3.text) + strlen("Read - Input ID: ") + 3);

        strcpy(temp, "Read - Input ID: ");
        strcat(temp, $3.text);

        temp = add_color(temp, COLOR_BLUE);

        $$ = createNode(temp);

        freeScopeToken($3.scope);
        free(temp);
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
        char* temp;

        /* temp = (char*) malloc(strlen($1.text) + strlen($3.text) + strlen($5.text) + strlen("List Assignment - ID1: ") + strlen(" - ID2: ") + strlen(" - ID3: ") + 3); */
        temp = (char*) malloc(strlen($1.text) + strlen($3.text) + strlen($5.text) + strlen("List Assignment - IDs: ") + 6);

        /* strcpy(temp, "List Assignment - ID1: ");
        strcat(temp, $1.text);
        strcat(temp, " - ID2: ");
        strcat(temp, $3.text);
        strcat(temp, " - ID3: ");
        strcat(temp, $5.text); */

        strcpy(temp, "List Assignment - IDs: ");
        strcat(temp, $1.text);
        strcat(temp, ", ");
        strcat(temp, $3.text);
        strcat(temp, ", ");
        strcat(temp, $5.text);

        temp = add_color(temp, COLOR_CYAN);

        $$ = createNode(temp);

        freeScopeToken($1.scope);
        freeScopeToken($3.scope);
        freeScopeToken($5.scope);
        free(temp);
    }
;

listHeader:
    HEADER_LISTOP ID {
        char* temp;

        temp = (char*) malloc(strlen($2.text) + strlen("List Header - ID: ") + 3);

        strcpy(temp, "List Header - ID: ");
        strcat(temp, $2.text);

        temp = add_color(temp, COLOR_CYAN);

        $$ = createNode(temp);

        freeScopeToken($2.scope);
        free(temp);
    }
;

/* listTail:
    EXCLA_OP ID {printf("%d %d\n", $1, $2);}
; */

listTailDestructor:
    TAILDES_LISTOP ID {
        char* temp;

        temp = (char*) malloc(strlen($2.text) + strlen("List Tail Destructor - ID: ") + 3);

        strcpy(temp, "List Tail Destructor - ID: ");
        strcat(temp, $2.text);

        temp = add_color(temp, COLOR_CYAN);

        $$ = createNode(temp);

        freeScopeToken($2.scope);
        free(temp);
    }
;

listMap:
    ID ASSIGN_OP ID MAP_LISTOP ID {
        char* temp;

        temp = (char*) malloc(strlen($1.text) + strlen($3.text) + strlen($5.text) + strlen("List Map - IDs: ") + 6);

        strcpy(temp, "List Map - IDs: ");
        strcat(temp, $1.text);
        strcat(temp, ", ");
        strcat(temp, $3.text);
        strcat(temp, ", ");
        strcat(temp, $5.text);

        temp = add_color(temp, COLOR_CYAN);

        $$ = createNode(temp);

        freeScopeToken($1.scope);
        freeScopeToken($3.scope);
        freeScopeToken($5.scope);
        free(temp);
    }
;

listFilter:
    ID ASSIGN_OP ID FILTER_LISTOP ID {
        char* temp;

        temp = (char*) malloc(strlen($1.text) + strlen($3.text) + strlen($5.text) + strlen("List Filter - IDs: ") + 6);

        strcpy(temp, "List Filter - IDs: ");
        strcat(temp, $1.text);
        strcat(temp, ", ");
        strcat(temp, $3.text);
        strcat(temp, ", ");
        strcat(temp, $5.text);

        temp = add_color(temp, COLOR_CYAN);

        $$ = createNode(temp);

        freeScopeToken($1.scope);
        freeScopeToken($3.scope);
        freeScopeToken($5.scope);
        free(temp);
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

            printParams();

            semanticAnalysis();

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
