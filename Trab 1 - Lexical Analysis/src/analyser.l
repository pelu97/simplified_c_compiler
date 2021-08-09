%option noinput nounput
%option noyywrap
%{
/* definitions of manifest constants
LT, LE, EQ, NE, GT, GE,
IF, THEN, ELSE, ID, NUMBER, RELOP */
#include <stdio.h>
#include <stdlib.h>

// Macros para cores
#define COLOR_RESET   "\x1B[0m"
#define COLOR_RED     "\x1B[31m"
#define COLOR_GREEN   "\x1B[32m"
#define COLOR_YELLOW  "\x1B[33m"
#define COLOR_BLUE    "\x1B[34m"
#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_CYAN    "\x1B[36m"
#define COLOR_WHITE   "\x1B[37m"

// Variáveis para mapeamento de posição e erros
int error = 0;
int line = 1;
int column = 1;

// Funções utilizadas para formatação, impressão e mapeamento
void print_separator();
void print_separator_big();
void print_line(int line_number);
void print_column(int column_number);
void print_linebreak();
void print_tokentype(char* text);
void print_token();
void print_error();
void print_block(char* tokentype);
void color_set(char* color);
void color_reset();
void column_count();
void line_count();
void print_start();
void print_end();



%}
/* Definições */

/* Base */
DIGIT              [0-9]
INT                {DIGIT}+
FLOAT              {DIGIT}+[.]{DIGIT}+

/* Identificador */
ID                 [a-zA-Z_][a-z0-9A-Z]*

/* Tipos */
TYPE               int|float|list
STRING             {DELIM_DQUOTE}(\\.|[^{DELIM_DQUOTE}\\])*{DELIM_DQUOTE}

NULL               nil

/* Operadores */
ARITHMETIC_OP      \+|\-|\/|\*

LOGIC_OP           \|\||&&

BINARY_OP          <|<=|>|>=|==|!=

ASSIGN_OP          [=]

EXCLA_OP           [!]

/* Controle de fluxo */
FLOW_KEY           if|else|for|return

/* Entrada e saída */
INPUT_KEY          read
OUTPUT_KEY         write|writeln

/* Operadores de lista */
LIST_OP            <<|>>|\?|%|:

/* Delimitadores */
DELIM_PARENT       [()]
DELIM_BRACKET      [[]]
DELIM_CUR_BRACKET  [{}]
DELIM_COMMA        [,]
DELIM_SEMICOLLON   [;]
DELIM_SQUOTE       [']
DELIM_DQUOTE       ["]

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
    print_block("Single Line Comment");
    column_count();
}

{MULTI_COMMENT} {
    print_block("Multiple Line Comment");
    column_count();
}

{INT} {
    print_block("Integer");
    column_count();
}

{FLOAT} {
    print_block("Float");
    column_count();
}

{TYPE} {
    print_block("Type");
    column_count();
}

{STRING} {
    print_block("String");
    column_count();
}

{NULL} {
    print_block("Null");
    column_count();
}

{ARITHMETIC_OP} {
    print_block("Arithmetic Operation");
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

{FLOW_KEY} {
    print_block("Flow Control Keyword");
    column_count();
}

{INPUT_KEY} {
    print_block("Input Keyword");
    column_count();
}

{OUTPUT_KEY} {
    print_block("Output Keyword");
    column_count();
}

{ASSIGN_OP} {
    print_block("Assignment Operator");
    column_count();
}

{EXCLA_OP} {
    print_block("Exclamation Point Operator");
    column_count();
}

{LIST_OP} {
    print_block("List Operator");
    column_count();
}

{DELIM_PARENT} {
    print_block("Parenthesis Delimiter");
    column_count();
}

{DELIM_BRACKET} {
    print_block("Bracket Delimiter");
    column_count();
}

{DELIM_CUR_BRACKET} {
    print_block("Curly Bracket Delimiter");
    column_count();
}

{DELIM_COMMA} {
    print_block("Comma Delimiter");
    column_count();
}

{DELIM_SEMICOLLON} {
    print_block("Semicollon Delimiter");
    column_count();
}

{DELIM_SQUOTE} {
    print_block("Single Quote Delimiter");
    column_count();
}

{DELIM_DQUOTE} {
    print_block("Double Quote Delimiter");
    column_count();
}


{ID} {
    print_block("Identifier");
    column_count();
}

. {
    print_error();
    column_count();
    error = error + 1;
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




/* ------------------------ Funções de formatação da saída ------------------------ */

/* Limpa a definição de cor de volta para o padrão */
void color_reset(){
    printf(COLOR_RESET);
}

/* Define uma cor nova - macros definidas no topo do código */
void color_set(char* color){
    printf(color);
}

/* Imprime uma linha separadora */
void print_separator(){
    printf("-----------------------------------------");
}

/* Imprime uma linha separadora grande */
void print_separator_big(){
    printf("-------------------------------------------------------");
}

/* Imprime o posicionamento na linha */
void print_line(int line_number){
    printf("Line: ");
    color_set(COLOR_MAGENTA);
    printf("%d", line_number);
    color_reset();
}

/* Imprime o posicionamento na coluna */
void print_column(int column_number){
    printf("Column: ");
    color_set(COLOR_MAGENTA);
    printf("%d", column_number);
    color_reset();
}

/* Imprime uma posição completa (linha e coluna) */
void print_position(){
    print_line(line);
    printf("    -    ");
    print_column(column);
}

/* Imprime uma quebra de linha - separado em uma função apenas para ficar mais prático para montar a formatação do bloco completo */
void print_linebreak(){
    printf("\n");
}

/* Imprime o tipo do token lido */
void print_tokentype(char* text){
    printf("Token type: ");
    color_set(COLOR_BLUE);
    printf("%s", text);
    color_reset();
}

/* Imprime o token lido */
void print_token(){
    printf("Token read: ");
    color_set(COLOR_GREEN);
    printf("%s", yytext);
    color_reset();
}

/* Imprime um bloco completo de um erro léxico */
void print_error(){
    print_linebreak();

    color_set(COLOR_RED);
    print_separator();
    color_reset();

    print_linebreak();

    print_position();


    print_linebreak();

    color_set(COLOR_RED);
    printf("ERROR: Undefined token");
    color_reset();

    print_linebreak();

    print_token();

    print_linebreak();

    color_set(COLOR_RED);
    print_separator();
    color_reset();

    print_linebreak();
}

/* Imprime um bloco completo de um token */
void print_block(char* tokentype){
    print_linebreak();

    print_separator();

    print_linebreak();

    print_position();

    print_linebreak();

    print_tokentype(tokentype);

    print_linebreak();

    print_token();

    print_linebreak();

    print_separator();

    print_linebreak();
}

/* Imprime um cabeçalho de inicialização do analisador */
void print_start(){
    color_set(COLOR_YELLOW);
    print_linebreak();
    print_separator_big();
    print_linebreak();

    printf("---------------Starting lexical analyser---------------");

    print_linebreak();
    print_separator_big();
    print_linebreak();
    color_reset();
}

/* Imprime um rodapé de finalização do analisador */
void print_end(){
    color_set(COLOR_YELLOW);
    print_linebreak();
    print_separator_big();
    print_linebreak();

    printf("---Lexical analyser completed with ");

    if(error > 0){
        color_set(COLOR_RED);
    }
    else{
        color_set(COLOR_GREEN);
    }

    printf("%02d ", error);

    color_set(COLOR_YELLOW);

    printf("lexical errors---");

    print_linebreak();
    print_separator_big();
    print_linebreak();
    color_reset();

}
/* ------------------------ Fim das funções de formatação ------------------------ */

int main(int argc, char **argv){
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
}
