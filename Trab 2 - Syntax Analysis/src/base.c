#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COLOR_RESET   "\x1B[0m"
#define COLOR_RED     "\x1B[31m"
#define COLOR_GREEN   "\x1B[32m"
#define COLOR_YELLOW  "\x1B[33m"
#define COLOR_BLUE    "\x1B[34m"
#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_CYAN    "\x1B[36m"
#define COLOR_WHITE   "\x1B[37m"


int lexicalError;
int syntaticError;
int line;
int column;



/* ------------------------ Funções de formatação da saída do léxico ------------------------ */

/* Limpa a definição de cor de volta para o padrão */
void color_reset(){
    printf(COLOR_RESET);
}

/* Define uma cor nova - macros definidas no topo do código */
void color_set(char* color){
    printf("%s", color);
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
void print_token(char* text){
    printf("Token read: ");
    color_set(COLOR_GREEN);
    printf("%s", text);
    color_reset();
}

/* Imprime um bloco completo de um erro léxico */
void print_error(char* token_text){
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

    print_token(token_text);

    print_linebreak();

    color_set(COLOR_RED);
    print_separator();
    color_reset();

    print_linebreak();
}

/* Imprime um bloco completo de um token */
void print_block(char* tokentype, char* token_text){
    print_linebreak();

    print_separator();

    print_linebreak();

    print_position();

    print_linebreak();

    print_tokentype(tokentype);

    print_linebreak();

    print_token(token_text);

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

    if(lexicalError > 0){
        color_set(COLOR_RED);
    }
    else{
        color_set(COLOR_GREEN);
    }

    printf("%02d ", lexicalError);

    color_set(COLOR_YELLOW);

    printf("lexical errors---");

    print_linebreak();
    print_separator_big();
    print_linebreak();
    color_reset();

}
/* ------------------------ Fim das funções de formatação do léxico ------------------------ */


/*------------------------- Formatação ----------------------------------*/
char* add_color(char* string, char* color){
    char* temp;
    char* temp2;

    temp = (char*) malloc(strlen(string) + strlen(color) + strlen(COLOR_RESET) + 3);

    if(temp != NULL){
        strcpy(temp, color);
        strcat(temp, string);
        strcat(temp, COLOR_RESET);

        temp2 = string;
        string = temp;
        free(temp2);

        #ifdef DEBUG
        printf("ADDED COLOR TO: %s\n", string);
        #endif

        return string;
    }
    else{
        printf("Fatal error when allocatin memory to add color formatting\n");
    }


}


void test_colors(){
    // #define COLOR_RESET   "\x1B[0m"
    // #define COLOR_RED     "\x1B[31m"
    // #define COLOR_GREEN   "\x1B[32m"
    // #define COLOR_YELLOW  "\x1B[33m"
    // #define COLOR_BLUE    "\x1B[34m"
    // #define COLOR_MAGENTA "\x1B[35m"
    // #define COLOR_CYAN    "\x1B[36m"
    // #define COLOR_WHITE   "\x1B[37m"

    printf("------------- TESTE DE CORES ---------------\n");

    printf("%s teste RED %s\n", COLOR_RED, COLOR_RESET);
    printf("%s teste GREEN %s\n", COLOR_GREEN, COLOR_RESET);
    printf("%s teste YELLOW %s\n", COLOR_YELLOW, COLOR_RESET);
    printf("%s teste BLUE %s\n", COLOR_BLUE, COLOR_RESET);
    printf("%s teste MAGENTA %s\n", COLOR_MAGENTA, COLOR_RESET);
    printf("%s teste CYAN %s\n", COLOR_CYAN, COLOR_RESET);
    printf("%s teste WHYTE %s\n", COLOR_WHITE, COLOR_RESET);

    printf("------------- FIM TESTE DE CORES ---------------\n");
}
