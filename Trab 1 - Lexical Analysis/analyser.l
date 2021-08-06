%option noinput nounput
%option noyywrap
%{
/* definitions of manifest constants
LT, LE, EQ, NE, GT, GE,
IF, THEN, ELSE, ID, NUMBER, RELOP */
#include <stdio.h>
#include <stdlib.h>

int line = 1;
int column = 1;
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
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: INT\n");
    printf("Token read: %s\n", yytext);
}

{FLOAT} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: FLOAT\n");
    printf("Token read: %s\n", yytext);
}


{LIST} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: LIST\n");
    printf("Token read: %s\n", yytext);
}

{TYPE} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: TYPE\n");
    printf("Token read: %s\n", yytext);
}

{NULL} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: NULL\n");
    printf("Token read: %s\n", yytext);
}

{ARITHMETIC_OP} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: ARITHMETIC_OP\n");
    printf("Token read: %s\n", yytext);
}


{LOGIC_OP} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: LOGIC_OP\n");
    printf("Token read: %s\n", yytext);
}

{BINARY_OP} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: BINARY_OP\n");
    printf("Token read: %s\n", yytext);
}

{FLOW_KEY} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: FLOW_KEY\n");
    printf("Token read: %s\n", yytext);
}

{INPUT_KEY} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: INPUT_KEY\n");
    printf("Token read: %s\n", yytext);
}

{OUTPUT_KEY} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: OUTPUT_KEY\n");
    printf("Token read: %s\n", yytext);
}

{ASSIGN_OP} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: ASSIGN_OP\n");
    printf("Token read: %s\n", yytext);
}

{INTER_OP} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: INTER_OP\n");
    printf("Token read: %s\n", yytext);
}

{EXCLA_OP} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: EXCLA_OP\n");
    printf("Token read: %s\n", yytext);
}

{DELIM_PARENT} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: DELIM_PARENT\n");
    printf("Token read: %s\n", yytext);
}

{DELIM_BRACKET} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: DELIM_BRACKET\n");
    printf("Token read: %s\n", yytext);
}

{DELIM_CUR_BRACKET} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: DELIM_CUR_BRACKET\n");
    printf("Token read: %s\n", yytext);
}

{DELIM_COMMA} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: DELIM_COMMA\n");
    printf("Token read: %s\n", yytext);
}

{DELIM_SEMICOLLON} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: DELIM_SEMICOLLON\n");
    printf("Token read: %s\n", yytext);
}

{DELIM_SQUOTE} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: DELIM_SQUOTE\n");
    printf("Token read: %s\n", yytext);
}

{DELIM_DQUOTE} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: DELIM_DQUOTE\n");
    printf("Token read: %s\n", yytext);
}



{ID} {
    printf("Line: %d - Column: %d\n", line, column);
    printf("Token type: ID\n");
    printf("Token read: %s\n", yytext);
}

%%

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
