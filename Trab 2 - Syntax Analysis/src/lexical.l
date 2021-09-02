%option noinput nounput
%option noyywrap
%{
/* definitions of manifest constants
LT, LE, EQ, NE, GT, GE,
IF, THEN, ELSE, ID, NUMBER, RELOP */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "scope.h"

#include "syntax.tab.h"

// Macros para cores
// #define COLOR_RESET   "\x1B[0m"
// #define COLOR_RED     "\x1B[31m"
// #define COLOR_GREEN   "\x1B[32m"
// #define COLOR_YELLOW  "\x1B[33m"
// #define COLOR_BLUE    "\x1B[34m"
// #define COLOR_MAGENTA "\x1B[35m"
// #define COLOR_CYAN    "\x1B[36m"
// #define COLOR_WHITE   "\x1B[37m"

// // Variáveis para mapeamento de posição e erros
// int error = 0;
// int line = 1;
// int column = 1;

// Funções utilizadas para formatação, impressão e mapeamento
// void print_separator();
// void print_separator_big();
// void print_line(int line_number);
// void print_column(int column_number);
// void print_linebreak();
// void print_tokentype(char* text);
// void print_token();
// void print_error();
// void print_block(char* tokentype);
// void color_set(char* color);
// void color_reset();
void column_count();
void line_count();
// void print_start();
// void print_end();



%}
/* Definições */

/* Base */
DIGIT              [0-9]
INT                {DIGIT}+
FLOAT              {DIGIT}+[.]{DIGIT}+

/* Identificador */
ID                 [a-zA-Z_][a-z0-9A-Z_]*

/* Tipos */
/* TYPE               int|float|list */
TYPE               int|float
/* INT_TYPE           int */
/* FLOAT_TYPE         float */
LIST_TYPE          list
STRING             \"(\\.|[^"\\])*\"

NULL_CONST         nil

/* Operadores */
/* ARITHMETIC_OP      \+|\-|\/|\* */
PLUS_OP            \+
MINUS_OP           \-
DIV_OP             \/
MUL_OP             \*

LOGIC_OP           \|\||&&
/* OR_OP              \|\| */
/* AND_OP             && */

BINARY_OP          <|<=|>|>=|==|!=
/* LT_OP              < */
/* LE_OP              <= */
/* GT_OP              > */
/* GE_OP              >= */
/* EQ_OP              == */
/* NE_OP              != */

ASSIGN_OP          [=]

EXCLA_OP           [!]

/* Controle de fluxo */
/* FLOW_KEY           if|else|for|return */
IF_KEY             if
ELSE_KEY           else
FOR_KEY            for
RETURN_KEY         return

/* Entrada e saída */
INPUT_KEY          read
OUTPUT_KEY         write
OUTPUTLN_KEY       writeln

/* Operadores de lista */
/* LIST_OP            <<|>>|\?|%|: */
ASSIGN_LISTOP      :
HEADER_LISTOP      \?
TAILDES_LISTOP     %
MAP_LISTOP         >>
FILTER_LISTOP      <<

/* Delimitadores */
/* DELIM_PARENT       [()] */
/* DELIM_BRACKET      [[]] */
/* DELIM_CUR_BRACKET  [{}] */
DELIM_PARENT_L      \(
DELIM_PARENT_R      \)
DELIM_BRACKET_L     \[
DELIM_BRACKET_R     \]
DELIM_CUR_BRACKET_L \{
DELIM_CUR_BRACKET_R \}
DELIM_COMMA         [,]
DELIM_SEMICOLLON    [;]
DELIM_SQUOTE        [']
DELIM_DQUOTE        ["]

/* Comentários */
SINGLE_COMMENT     \/\/[^\n]*
MULTI_COMMENT      \/\*[^(\*\/)]*\*\/

/* Tags de formatação */
FORMAT_BLANKSPACE  [ ]
FORMAT_NEWLINE     \n
FORMAT_TAB         \t



%%

{FORMAT_BLANKSPACE} {
    column_count();
}

{FORMAT_TAB} {
    column_count();
}

{FORMAT_NEWLINE} {
    line_count();
}

{SINGLE_COMMENT} {
    /* print_block("Single Line Comment"); */
    /* column_count(); */
}

{MULTI_COMMENT} {
    /* print_block("Multiple Line Comment"); */
    /* column_count(); */
}

{INT} {
    /* print_block("Integer"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return INT;
}

{FLOAT} {
    /* print_block("Float"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return FLOAT;
}

{TYPE} {
    /* print_block("Type"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return TYPE;
}

{LIST_TYPE} {
    /* print_block("List Type"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return LIST_TYPE;
}

{STRING} {
    /* print_block("String"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return STRING;
}

{NULL_CONST} {
    /* print_block("Null"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return NULL_CONST;
}

{PLUS_OP} {
    /* print_block("Plus Operation"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return PLUS_OP;
}

{MINUS_OP} {
    /* print_block("Minus Operation"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return MINUS_OP;
}

{DIV_OP} {
    /* print_block("Div Operation"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return DIV_OP;
}

{MUL_OP} {
    /* print_block("Mul Operation"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return MUL_OP;
}

{LOGIC_OP} {
    /* print_block("Logic Operation"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return LOGIC_OP;
}

{BINARY_OP} {
    /* print_block("Binary Operation"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return BINARY_OP;
}

{IF_KEY} {
    /* print_block("If Keyword"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return IF_KEY;
}

{ELSE_KEY} {
    /* print_block("Else Keyword"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return ELSE_KEY;
}

{FOR_KEY} {
    /* print_block("For Keyword"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return FOR_KEY;
}

{RETURN_KEY} {
    /* print_block("Return Keyword"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return RETURN_KEY;
}

{INPUT_KEY} {
    /* print_block("Input Keyword"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return INPUT_KEY;
}

{OUTPUT_KEY} {
    /* print_block("Output Keyword"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return OUTPUT_KEY;
}

{OUTPUTLN_KEY} {
    /* print_block("Output with line break Keyword"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return OUTPUTLN_KEY;
}

{ASSIGN_OP} {
    /* print_block("Assignment Operator"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return ASSIGN_OP;
}

{EXCLA_OP} {
    /* print_block("Exclamation Point Operator"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return EXCLA_OP;
}

{ASSIGN_LISTOP} {
    /* print_block("Assignment List Operator"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return ASSIGN_LISTOP;
}

{HEADER_LISTOP} {
    /* print_block("Header List Operator"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return HEADER_LISTOP;
}

{TAILDES_LISTOP} {
    /* print_block("Tail Destructor List Operator"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return TAILDES_LISTOP;
}

{MAP_LISTOP} {
    /* print_block("Map List Operator"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return MAP_LISTOP;
}

{FILTER_LISTOP} {
    /* print_block("Filter List Operator"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return FILTER_LISTOP;
}

{DELIM_PARENT_L} {
    /* print_block("Parenthesis Delimiter"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return DELIM_PARENT_L;
}

{DELIM_PARENT_R} {
    /* print_block("Parenthesis Delimiter"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return DELIM_PARENT_R;
}

{DELIM_BRACKET_L} {
    /* print_block("Bracket Delimiter"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return DELIM_BRACKET_L;
}

{DELIM_BRACKET_R} {
    /* print_block("Bracket Delimiter"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return DELIM_BRACKET_R;
}

{DELIM_CUR_BRACKET_L} {
    int parentScope;
    /* print_block("Curly Bracket Delimiter"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;

    /* Scope - o valor do último escopo nunca é reduzido para não repetir em um escopo diferente*/
    parentScope = checkScope();
    lastScopeValue++;
    pushScope(lastScopeValue, parentScope);
    yylval.t_token.scope = getScope();

    /* printf("Abrindo novo escopo: %d pai %d\n", lastScopeValue, parentScope); */
    /* printf("Aberto novo escopo: %d pai %d\n", getScope()->scopeValue, getScope()->parentScope); */

    return DELIM_CUR_BRACKET_L;
}

{DELIM_CUR_BRACKET_R} {
    /* int value; */
    /* print_block("Curly Bracket Delimiter"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;

    /* Scope - o valor do último escopo nunca é reduzido para não repetir em um escopo diferente*/
    /* value = checkScope(); */
    popScope();
    /* yylval.t_token.scopeValue = value; */

    return DELIM_CUR_BRACKET_R;
}

{DELIM_COMMA} {
    /* print_block("Comma Delimiter"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return DELIM_COMMA;
}

{DELIM_SEMICOLLON} {
    /* print_block("Semicollon Delimiter"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return DELIM_SEMICOLLON;
}

{DELIM_SQUOTE} {
    /* print_block("Single Quote Delimiter"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return DELIM_SQUOTE;
}

{DELIM_DQUOTE} {
    /* print_block("Double Quote Delimiter"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;
    return DELIM_DQUOTE;
}


{ID} {
    /* int value; */
    t_scope* scope;
    /* print_block("Identifier"); */
    column_count();
    strcpy(yylval.t_token.text, yytext);
    yylval.t_token.line = line;
    yylval.t_token.column = column;

    /* Scope */
    /* value = checkScope(); */
    scope = getScope();
    yylval.t_token.scope = scope;

    return ID;
}

. {
    print_error(yytext);
    column_count();
    lexicalError = lexicalError + 1;
}

%%
/*
removed rules

{INTER_OP} {
    print_block("Interrogation Point Operator");
    column_count();
}


{PERCENT_OP} {
    print_block("Percentage Operator");
    column_count();
}

{COLON_OP} {
    print_block("Colon Operator");
    column_count();
}

{FORMAT_CODES} {
    print_block("Formatting Code");
    column_count();
}

{DELIM_SCOMMENT} {
    print_block("Single Line Comment Delimiter");
    column_count();
}

{DELIM_MCOMMENT} {
    print_block("Multi Line Comment Delimiter");
    column_count();
}

{TYPE} {
    print_block("Type");
    column_count();
}


{INT_TYPE} {
    print_block("Int Type");
    column_count();
}

{FLOAT_TYPE} {
    print_block("Float Type");
    column_count();
}

{LIST_TYPE} {
    print_block("List Type");
    column_count();
}

{ARITHMETIC_OP} {
    print_block("Arithmetic Operation");
    column_count();
}


{OR_OP} {
    print_block("Or Operation");
    column_count();
}

{AND_OP} {
    print_block("And Operation");
    column_count();
}

{LOGIC_OP} {
    print_block("Logic Operation");
    column_count();
}

{BINARY_OP} {
    print_block("Binary Operation");
    column_count();
}

{LT_OP} {
    print_block("Less than Operation");
    column_count();
}

{LE_OP} {
    print_block("Less or equal Operation");
    column_count();
}

{GT_OP} {
    print_block("Greater than Operation");
    column_count();
}

{GE_OP} {
    print_block("Greater or equal Operation");
    column_count();
}

{EQ_OP} {
    print_block("Equal Operation");
    column_count();
}

{NE_OP} {
    print_block("Not equal Operation");
    column_count();
}

{FLOW_KEY} {
    print_block("Flow Control Keyword");
    column_count();
}

{LIST_OP} {
    print_block("List Operator");
    column_count();
}


{ASSIGN_LISTOP} {
    print_block("Assignment List Operator");
    column_count();
}

{HEADER_LISTOP} {
    print_block("Header List Operator");
    column_count();
}

{TAILDES_LISTOP} {
    print_block("Tail Destructor List Operator");
    column_count();
}

{MAP_LISTOP} {
    print_block("Map List Operator");
    column_count();
}

{FILTER_LISTOP} {
    print_block("Filter List Operator");
    column_count();
}

{DELIM_PARENT} {
    print_block("Parenthesis Delimiter");
    column_count();
    return DELIM_PARENT;
}

{DELIM_BRACKET} {
    print_block("Bracket Delimiter");
    column_count();
    return DELIM_BRACKET;
}

{DELIM_CUR_BRACKET} {
    print_block("Curly Bracket Delimiter");
    column_count();
    return DELIM_CUR_BRACKET;
}


*/


/* ------------------------ Funções para calcular o mapeamento ------------------------ */

/* Mantém o mapeamento das colunas*/
void column_count(){
    column = column + yyleng;
}

/* Mantém o mapeamento das linhas */
void line_count(){
    line = line + 1;
    column = 1;
}

/* ------------------------ Fim das funções de mapeamento ------------------------ */






/* int main(int argc, char **argv){
    FILE *filep;

    if(argc >= 2) {
        filep = fopen(argv[1], "r");

        if(filep != NULL){
            print_start();

            yyin = filep;
            yylex();
            fclose(yyin);

            print_end();
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
} */
