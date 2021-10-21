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
/* %type <t_node> listStatement */
%type <t_node> listExpression
%type <t_node> listAssign
%type <t_node> listHeader
/* %type <t_node> listTail */
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
        $$ = createNode("Declaration List - Declaration", "decListDec");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $2;

    }
    | declaration {
        $$ = $1;
    }
    | declarationList statement {
        $$ = createNode("Declaration List - Statement", "decListState");

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

        $$ = createNode(temp, "varDec");
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

        $$ = createNode(temp2, "varDecList");

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
    TYPE ID {
        /* printf("%s %s %s %s - escopo %d %d\n", $1.text, $2.text, $3.text, $5.text, $2.scope->scopeValue, $2.scope->parentScope); */
        createSymbol($2.text, $1.text, $2.line, $2.column, $2.scope->scopeValue, $2.scope->parentScope, 0);
        updateLastFunc($2.text);
    } DELIM_PARENT_L parameters DELIM_PARENT_R {
        t_symbol* symbol;

        /* symbol = getSymbol($2.text); */
        symbol = getSymbolValidScopeFunc($2.text);
        installParam(symbol);
    }
    bodyStatement {
        char* temp;

        temp = (char*) malloc(strlen($2.text) + strlen("Function Declaration - ID: ") + 1);

        strcpy(temp, "Function Declaration - ID: ");
        strcat(temp, $2.text);

        temp = add_color(temp, COLOR_GREEN);

        $$ = createNode(temp, "funcDec");

        addChild($$, 2);

        $$->child[0] = $5;
        $$->child[1] = $8;

        freeScopeToken($2.scope);
        free(temp);

        /* printf("function declaration test\n"); */

    }
    | TYPE LIST_TYPE ID {
        char* temp;

        temp = (char*) malloc(sizeof($1.text) + sizeof($2.text) + 3);
        strcpy(temp, $1.text);
        strcat(temp, " ");
        strcat(temp, $2.text);
        createSymbol($3.text, temp, $3.line, $3.column, $3.scope->scopeValue, $3.scope->parentScope, 0);
        updateLastFunc($3.text);

        free(temp);
    }
    DELIM_PARENT_L parameters DELIM_PARENT_R {
        t_symbol* symbol;

        symbol = getSymbolValidScopeFunc($3.text);

        installParam(symbol);
    }
    bodyStatement {
        char* temp2;

        temp2 = (char*) malloc(strlen($3.text) + strlen("Function Declaration - List Type ID: ") + 1);

        strcpy(temp2, "Function Declaration - List Type ID: ");
        strcat(temp2, $3.text);

        temp2 = add_color(temp2, COLOR_GREEN);

        $$ = createNode(temp2, "funcDecList");

        addChild($$, 2);

        $$->child[0] = $6;
        $$->child[1] = $9;

        freeScopeToken($3.scope);
        free(temp2);
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
        $$ = createNode("Parameters list", "paramList");

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

        $$ = createNode(temp, "paramSimple");

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

        $$ = createNode(temp2, "paramSimpleList");

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
    /* | listStatement DELIM_SEMICOLLON {
        $$ = $1;
    } */
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
        $$ = createNode(COLOR_RED "SYNTAX ERROR" COLOR_RESET, "error");
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
        $$ = createNode("Local Declaration", "localDec");

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
        $$ = createNode("Statement List", "stateList");

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
        $$ = createNode(COLOR_BLUE "If Statement" COLOR_RESET, "if");

        addChild($$, 2);

        $$->child[0] = $3;
        $$->child[1] = $5;
    }
    | IF_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R statement ELSE_KEY statement {
        $$ = createNode(COLOR_BLUE "If-Else Statement" COLOR_RESET, "ifelse");

        addChild($$, 3);

        $$->child[0] = $3;
        $$->child[1] = $5;
        $$->child[2] = $7;

    }
;

loopStatement:
    FOR_KEY DELIM_PARENT_L expression DELIM_SEMICOLLON simpleExpression DELIM_SEMICOLLON expression DELIM_PARENT_R statement {
        $$ = createNode(COLOR_BLUE "For Statement" COLOR_RESET, "for");

        addChild($$, 4);

        $$->child[0] = $3;
        $$->child[1] = $5;
        $$->child[2] = $7;
        $$->child[3] = $9;
    }
;

returnStatement:
    RETURN_KEY expression DELIM_SEMICOLLON {
        $$ = createNode(COLOR_BLUE "Return Statement" COLOR_RESET, "return");

        addChild($$, 1);

        addFunctionName($$, lastFuncDeclared);

        $$->child[0] = $2;

        verifyOperands($$);
    }
;

expression:
    ID ASSIGN_OP expression {
        $$ = createNode("Assign Operation", "assignOp");

        addChild($$, 1);

        $$->child[0] = $3;
        freeScopeToken($1.scope);

        addNodePosition($$, $1.line, $1.column);
        addNodeId($$, $1.text);

        /* addNodePosition($3, $3->line, $3->column); */

        checkIdDeclaration($$);

        verifyOperands($$);

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
        $$ = createNode("Logic Binary Expression", "logicBin");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $3;

        addNodeType($$, "int");

        addNodePosition($$, $$->child[1]->line, $$->child[1]->column);

        verifyOperands($$);

    }
    | logicUnExpression {
        $$ = $1;
    }
;

logicUnExpression:
    EXCLA_OP logicUnExpression {
        $$ = createNode("Exclamation Expression", "exclaExp");

        addChild($$, 1);

        $$->child[0] = $2;

        /* addNodeType($$, "int"); */
        addNodeTypeChildren($$);

        addNodePosition($$, $$->child[0]->line, $$->child[0]->column);

        verifyOperands($$);

    }
    | binExpression {
        $$ = $1;
    }
;

/* logicBinExpression:
    logicBinExpression LOGIC_OP logicBinExpression {printf("%d %d %d\n", $1, $2, $3);}
    | EXCLA_OP simpleExpression {printf("%d %d\n", $1, $2);} */

binExpression:
    binExpression BINARY_OP listExpression {
        $$ = createNode("Binary Expression", "binExp");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $3;

        addNodeType($$, "int");

        addNodePosition($$, $$->child[1]->line, $$->child[1]->column);

        verifyOperands($$);

    }
    | listExpression {
        $$ = $1;
    }
;

sumExpression:
    sumExpression sumOP mulExpression {
        $$ = createNode("Sum Expression", "sumExp");

        addChild($$, 3);

        $$->child[0] = $1;
        $$->child[1] = $2;
        $$->child[2] = $3;

        addNodeTypeChildren($$);

        addNodePosition($$, $$->child[2]->line, $$->child[2]->column);

        verifyOperands($$);
    }
    | mulExpression {
        $$ = $1;
    }
;

mulExpression:
    mulExpression mulOP factor {
        $$ = createNode("Multiplication Expression", "mulExp");

        addChild($$, 3);

        addChild($$, 3);

        $$->child[0] = $1;
        $$->child[1] = $2;
        $$->child[2] = $3;

        addNodeTypeChildren($$);

        addNodePosition($$, $$->child[2]->line, $$->child[2]->column);

        verifyOperands($$);
    }
    | factor {
        $$ = $1;
    }
;

sumOP:
    PLUS_OP {
        $$ = createNode("+ Operator", "plusOp");
    }
    | MINUS_OP {
        $$ = createNode("- Operator", "minusOp");
    }
;

mulOP:
    MUL_OP {
        $$ = createNode("* Operator", "mulOp");
    }
    | DIV_OP {
        $$ = createNode("/ Operator", "divOp");
    }
;

factor:
    ID {
        char* temp;

        temp = (char*) malloc(strlen($1.text) + strlen("ID:  ") + 3);

        strcpy(temp, "ID:  ");
        strcat(temp, $1.text);

        temp = add_color(temp, COLOR_YELLOW);

        $$ = createNode(temp, "id");

        freeScopeToken($1.scope);
        free(temp);

        addNodeTypeId($$, $1.text);
        addNodePosition($$, $1.line, $1.column);
        addNodeId($$, $1.text);

        checkIdDeclaration($$);
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
    /* | listExpression {
        $$ = $1;
    } */
;

constant:
    INT {
        char* temp;

        temp = (char*) malloc(strlen("Constant Integer: ") + strlen($1.text) + 1);
        strcpy(temp, "Constant Integer: ");
        strcat(temp, $1.text);

        temp = add_color(temp, COLOR_YELLOW);

        $$ = createNode(temp, "constInt");

        free(temp);

        addNodeType($$, "int");
        addNodePosition($$, $1.line, $1.column);
    }
    | MINUS_OP INT {
        char* temp;

        temp = (char*) malloc(strlen("Constant Negative Integer: ") + strlen($2.text) + 1);
        strcpy(temp, "Constant Negative Integer: ");
        strcat(temp, $2.text);

        temp = add_color(temp, COLOR_YELLOW);

        $$ = createNode(temp, "constNegInt");

        free(temp);

        addNodeType($$, "int");
        addNodePosition($$, $2.line, $2.column);
    }
    | FLOAT {
        char* temp;

        temp = (char*) malloc(strlen("Constant Float: ") + strlen($1.text) + 1);
        strcpy(temp, "Constant Float: ");
        strcat(temp, $1.text);

        temp = add_color(temp, COLOR_YELLOW);

        $$ = createNode(temp, "constFloat");

        free(temp);

        addNodeType($$, "float");
        addNodePosition($$, $1.line, $1.column);
    }
    | MINUS_OP FLOAT {
        char* temp;

        temp = (char*) malloc(strlen("Constant Negative Float: ") + strlen($2.text) + 1);
        strcpy(temp, "Constant Negative Float: ");
        strcat(temp, $2.text);

        temp = add_color(temp, COLOR_YELLOW);

        $$ = createNode(temp, "constNegFloat");

        free(temp);

        addNodeType($$, "float");
        addNodePosition($$, $2.line, $2.column);
    }
    | NULL_CONST {
        char* temp;

        temp = malloc(strlen("Constant NULL") + 1);
        strcpy(temp, "Constant NULL");

        temp = add_color(temp, COLOR_YELLOW);

        $$ = createNode(temp, "constNull");

        free(temp);

        addNodeType($$, "nil");
        addNodePosition($$, $1.line, $1.column);
    }
;

functionCall:
    ID DELIM_PARENT_L parametersPass DELIM_PARENT_R {
        char* temp;

        temp = (char*) malloc(strlen("Function Call - ID: ") + strlen($1.text) + 1);
        strcpy(temp, "Function Call - ID: ");
        strcat(temp, $1.text);

        $$ = createNode(temp, "funcCall");

        addChild($$, 1);

        $$->child[0] = $3;
        freeScopeToken($1.scope);
        free(temp);

        addNodeTypeId($$, $1.text);
        addFunctionName($$, $1.text);
        addNodePosition($$, $1.line, $1.column);

        checkFunctionCall($$);
    }
;

parametersPass:
    parametersPass DELIM_COMMA simpleExpression {
        $$ = createNode("Parameters Passing", "paramPass");

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
        $$ = createNode(COLOR_BLUE "Output String" COLOR_RESET, "writeString");
    }
    | OUTPUT_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R {
        $$ = createNode(COLOR_BLUE "Output Expression" COLOR_RESET, "writeExp");

        addChild($$, 1);

        $$->child[0] = $3;

        verifyOperands($$);
    }
;

writeln:
    OUTPUTLN_KEY DELIM_PARENT_L STRING DELIM_PARENT_R {
        $$ = createNode(COLOR_BLUE "OutputLn String" COLOR_RESET, "writelnString");
    }
    | OUTPUTLN_KEY DELIM_PARENT_L simpleExpression DELIM_PARENT_R {
        $$ = createNode(COLOR_BLUE "OutputLn Expression" COLOR_RESET, "writelnExp");

        addChild($$, 1);

        $$->child[0] = $3;

        verifyOperands($$);
    }
;

readOp:
    INPUT_KEY DELIM_PARENT_L ID DELIM_PARENT_R {
        char* temp;

        temp = (char*) malloc(strlen($3.text) + strlen("Read - Input ID: ") + 3);

        strcpy(temp, "Read - Input ID: ");
        strcat(temp, $3.text);

        temp = add_color(temp, COLOR_BLUE);

        $$ = createNode(temp, "readOp");

        addNodeId($$, $3.text);
        addNodePosition($$, $3.line, $3.column);

        verifyOperands($$);

        freeScopeToken($3.scope);
        free(temp);
    }
;

expressionStatement:
    expression DELIM_SEMICOLLON {
        $$ = $1;
    }
;

/* listStatement:
    listAssign {
        $$ = $1;
    }
    | listMap {
        $$ = $1;
    }
    | listFilter {
        $$ = $1;
    }
; */

listExpression:
    /* listHeader {
        $$ = $1;
    } */
    /* | listTail {printf("%d\n", $1);} */
    /* | listTailDestructor {
        $$ = $1;
    }
    | listAssign {
        $$ = $1;
    }
    | listMap {
        $$ = $1;
    }
    | listFilter {
        $$ = $1;
    }
    | sumExpression {
        $$ = $1;
    } */
    listAssign {
        $$ = $1;
    }
;

listAssign:
    listAssign ASSIGN_LISTOP listHeader {
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

        $$ = createNode(temp, "listAssign");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $3;

        addNodeTypeChildren($$);

        addNodePosition($$, $$->child[1]->line, $$->child[1]->column);

        /* freeScopeToken($1.scope);
        freeScopeToken($3.scope);
        freeScopeToken($5.scope); */
        free(temp);
    }
    | listHeader {
        $$ = $1;
    }
;


listHeader:
    HEADER_LISTOP listHeader {
        char* temp;

        temp = (char*) malloc(strlen("List Header") + 3);

        strcpy(temp, "List Header");
        /* strcpy(temp, "List Header - ID: "); */
        /* strcat(temp, $2.text); */

        temp = add_color(temp, COLOR_CYAN);

        $$ = createNode(temp, "listHeader");

        addChild($$, 1);

        $$->child[0] = $2;

        addNodeTypeChildren($$);

        addNodePosition($$, $$->child[0]->line, $$->child[0]->column);

        verifyOperands($$);
        /* freeScopeToken($2.scope); */
        free(temp);
    }
    /* | listTail {
        $$ = $1;
    } */
    | listTailDestructor {
        $$ = $1;
    }
;

/* listTail:
    EXCLA_OP ID {printf("%d %d\n", $1, $2);}
; */

/* listTail:
    EXCLA_OP listTail {
        $$ = $1;
    }
    | listTailDestructor {
        $$ = $1;
    }
; */

listTailDestructor:
    TAILDES_LISTOP listTailDestructor {
        char* temp;

        /* temp = (char*) malloc(strlen($2.text) + strlen("List Tail Destructor - ID: ") + 3); */
        temp = malloc(strlen("List Tail Destructor") + 3);

        /* strcpy(temp, "List Tail Destructor - ID: ");
        strcat(temp, $2.text); */
        strcpy(temp, "List Tail Destructor");

        temp = add_color(temp, COLOR_CYAN);

        $$ = createNode(temp, "listTailDest");

        addChild($$, 1);

        $$->child[0] = $2;

        addNodeTypeChildren($$);

        addNodePosition($$, $$->child[0]->line, $$->child[0]->column);

        verifyOperands($$);

        /* freeScopeToken($2.scope); */
        free(temp);
    }
    | listMap {
        $$ = $1;
    }
;

listMap:
    listMap MAP_LISTOP listFilter {
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

        $$ = createNode(temp, "listMap");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $3;

        addNodeTypeChildren($$);

        addNodePosition($$, $$->child[1]->line, $$->child[1]->column);

        verifyOperands($$);

        /* freeScopeToken($1.scope);
        freeScopeToken($3.scope);
        freeScopeToken($5.scope); */
        free(temp);
    }
    | listFilter {
        $$ = $1;
    }
;

listFilter:
    listFilter FILTER_LISTOP sumExpression {
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

        $$ = createNode(temp, "listFilter");

        addChild($$, 2);

        $$->child[0] = $1;
        $$->child[1] = $3;

        addNodeTypeChildren($$);

        addNodePosition($$, $$->child[1]->line, $$->child[1]->column);

        verifyOperands($$);

        /* freeScopeToken($1.scope);
        freeScopeToken($3.scope);
        freeScopeToken($5.scope); */
        free(temp);
    }
    | sumExpression {
        $$ = $1;
    }
;




%%
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
