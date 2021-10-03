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
    int varFunc;    //1 = var; 0 = func
    //semantic
    int paramNumber;
    struct Symbols **parameters;
} t_symbol;


extern t_symbol *SymbolTable;
extern t_symbol *lastSymbol;
extern t_symbol **parameterHolder;
extern int parameterHolderMax;


t_symbol* createSymbol(char* symbolName, char* type, int line, int column, int scopeValue, int parentScope, int varFunc);

t_symbol* getSymbol(char* symbolName);

// adds parameter to temporary holder
void addParam(t_symbol* parameter);

// moves all parameters on temporary holder to the function
void installParam(t_symbol* function);

void printTable();

void printTable2();

t_symbol* printChildren(t_symbol* fixedSymbol, int level);

void printParams();

void freeTable();

// void insertSymbol();
