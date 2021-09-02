#include <stdlib.h>

// Definições referentes à tabela de símbolos


typedef struct Symbols {
    int line;
    int column;
    char *name;
    char *type;
    struct Symbols *next;
    int scopeValue;
    int parentScope;
    int varFunc;
} t_symbol;


extern t_symbol *SymbolTable;
extern t_symbol *lastSymbol;


void createSymbol(char* symbolName, char* type, int line, int column, int scopeValue, int parentScope, int varFunc);

t_symbol* getSymbol(char* symbolName);

void printTable();

void printTable2();

t_symbol* printChildren(t_symbol* fixedSymbol, int level);

// void insertSymbol();
