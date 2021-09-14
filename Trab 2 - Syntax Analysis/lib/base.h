#include <stdio.h>

#define COLOR_RESET   "\x1B[0m"
#define COLOR_RED     "\x1B[31m"
#define COLOR_GREEN   "\x1B[32m"
#define COLOR_YELLOW  "\x1B[33m"
#define COLOR_BLUE    "\x1B[34m"
#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_CYAN    "\x1B[36m"
#define COLOR_WHITE   "\x1B[37m"

// #define DEBUG 1

extern int lexicalError;
extern int syntaticError;
extern int line;
extern int column;




/* ------------------------ Funções de formatação da saída ------------------------ */

/* Limpa a definição de cor de volta para o padrão */
void color_reset();

/* Define uma cor nova - macros definidas no topo do código */
void color_set(char* color);

/* Imprime uma linha separadora */
void print_separator();

/* Imprime uma linha separadora grande */
void print_separator_big();

/* Imprime o posicionamento na linha */
void print_line(int line_number);

/* Imprime o posicionamento na coluna */
void print_column(int column_number);

/* Imprime uma posição completa (linha e coluna) */
void print_position();

/* Imprime uma quebra de linha - separado em uma função apenas para ficar mais prático para montar a formatação do bloco completo */
void print_linebreak();

/* Imprime o tipo do token lido */
void print_tokentype(char* text);

/* Imprime o token lido */
void print_token(char* text);

/* Imprime um bloco completo de um erro léxico */
void print_error(char* token_text);

/* Imprime um bloco completo de um token */
void print_block(char* tokentype, char* token_text);

/* Imprime um cabeçalho de inicialização do analisador */
void print_start();

/* Imprime um rodapé de finalização do analisador */
void print_end();
/* ------------------------ Fim das funções de formatação ------------------------ */
