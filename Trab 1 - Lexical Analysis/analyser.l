%{
/* definitions of manifest constants
LT, LE, EQ, NE, GT, GE,
IF, THEN, ELSE, ID, NUMBER, RELOP */
#include <stdio.h>
%}
/* regular definitions */

letter             [A-Za-z]
digit              [0-9]

int                {digit}+
float              {digit}+[\.]{digit}+
list               "list"

negative           [/-]

type               int|float|list

null               NIL


arithmetic_op      "+" | "-" | "*" | "/"
logic_op           "!" | "||" | "&&"
binary_op          "<" | "<=" | ">" | ">=" | "==" | "!="

flow_key           if|else|for|return
input_key          read
output_key         write|writeln



assign             "="

%%



%%
