#include <stdlib.h>

// Definições referentes à tabela de símbolos


typedef struct Symbols {
    int line;
    int column;
    char *name;
    struct Symbols *next;
} t_symbol;


extern t_symbol *SymbolTable;
extern t_symbol *lastSymbol;


void createSymbol(char* symbolName, int line, int column);

t_symbol* getSymbol(char* symbolName);

void printTable();

// void insertSymbol();
