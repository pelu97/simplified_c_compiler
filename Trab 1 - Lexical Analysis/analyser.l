%option noinput nounput
%option noyywrap
%{
/* definitions of manifest constants
LT, LE, EQ, NE, GT, GE,
IF, THEN, ELSE, ID, NUMBER, RELOP */
#include <stdio.h>
#include <stdlib.h>

#define COLOR_RESET   "\x1B[0m"
#define COLOR_RED     "\x1B[31m"
#define COLOR_GREEN   "\x1B[32m"
#define COLOR_YELLOW  "\x1B[33m"
#define COLOR_BLUE    "\x1B[34m"
#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_CYAN    "\x1B[36m"
#define COLOR_WHITE   "\x1B[37m"

int line = 1;
int column = 1;

void print_separator();
void print_line(int line_number);
void print_column(int column_number);
void print_linebreak();
void print_tokentype(char* text);
void print_token();
void print_error();
void print_block(char* tokentype);
void color_set(char* color);
void color_reset();



%}
/* regular definitions */

DIGIT              [0-9]
INT                {DIGIT}+
FLOAT              {DIGIT}+[.]{DIGIT}+

ID                 [a-zA-Z_][a-z0-9A-Z]*

LIST               list

TYPE               int|float

NULL               nil

ARITHMETIC_OP      \+|\-|\/|\*

LOGIC_OP           \|\||&&

BINARY_OP          <|<=|>|>=|==|!=

FLOW_KEY           if|else|for|return

INPUT_KEY          read
OUTPUT_KEY         write|writeln

ASSIGN_OP          [=]
INTER_OP           [?]
EXCLA_OP           [!]

DELIM_PARENT       [()]
DELIM_BRACKET      [[]]
DELIM_CUR_BRACKET  [{}]
DELIM_COMMA        [,]
DELIM_SEMICOLLON   [;]
DELIM_SQUOTE       [']
DELIM_DQUOTE       ["]

FORMAT_BLANKSPACE  [ ]
FORMAT_NEWLINE     \n
FORMAT_TAB         \t

%%

{FORMAT_BLANKSPACE} {
    column = column + yyleng;
}

{FORMAT_TAB} {
    column = column + yyleng;
}

{FORMAT_NEWLINE} {
    column = 1;
    line = line + 1;
}

{INT} {
    print_block("Integer");
}

{FLOAT} {
    print_block("Float");
}

{LIST} {
    print_block("List");
}

{TYPE} {
    print_block("Type");
}

{NULL} {
    print_block("Null");
}

{ARITHMETIC_OP} {
    print_block("Arithmetic Operation");
}

{LOGIC_OP} {
    print_block("Logic Operation");
}

{BINARY_OP} {
    print_block("Binary Operation");
}

{FLOW_KEY} {
    print_block("Flow Control Keyword");
}

{INPUT_KEY} {
    print_block("Input Keyword");
}

{OUTPUT_KEY} {
    print_block("Output Keyword");
}

{ASSIGN_OP} {
    print_block("Assignment Operator");
}

{INTER_OP} {
    print_block("Interrogation Point Operator");
}

{EXCLA_OP} {
    print_block("Exclamation Point Operator");
}

{DELIM_PARENT} {
    print_block("Parenthesis Delimiter");
}

{DELIM_BRACKET} {
    print_block("Bracket Delimiter");
}

{DELIM_CUR_BRACKET} {
    print_block("Curly Bracket Delimiter");
}

{DELIM_COMMA} {
    print_block("Comma Delimiter");
}

{DELIM_SEMICOLLON} {
    print_block("Semicollon Delimiter");
}

{DELIM_SQUOTE} {
    print_block("Single Quote Delimiter");
}

{DELIM_DQUOTE} {
    print_block("Double Quote Delimiter");
}

{ID} {
    print_block("Identifier");
}

. {
    print_error();
}

%%

void color_reset(){
    printf(COLOR_RESET);
}

void color_set(char* color){
    printf(color);
}

void print_separator(){
    printf("-----------------------------------------");
}

void print_line(int line_number){
    printf("Line: ");
    color_set(COLOR_MAGENTA);
    printf("%d", line_number);
    color_reset();
}

void print_column(int column_number){
    printf("Column: ");
    color_set(COLOR_MAGENTA);
    printf("%d", column_number);
    color_reset();
}

void print_position(){
    print_line(line);
    printf(" - ");
    print_column(column);
}

void print_linebreak(){
    printf("\n");
}

void print_tokentype(char* text){
    printf("Token type: ");
    color_set(COLOR_BLUE);
    printf("%s", text);
    color_reset();
}

void print_token(){
    printf("Token read: ");
    color_set(COLOR_GREEN);
    printf("%s", yytext);
    color_reset();
}

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

int main(int argc, char **argv){
    FILE *filep;

    if(argc >= 2) {
        filep = fopen(argv[1], "r");

        if(filep != NULL){
            yyin = filep;
            yylex();
        }
        else{
            printf("Erro ao abrir o arquivo.\n");
        }
    }
    else{
        printf("Nenhum arquivo foi passado.\n");
    }


    return 0;
}
