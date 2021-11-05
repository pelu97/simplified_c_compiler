#include <stdlib.h>

// Definições referentes à tabela de símbolos

#ifndef SYMBOLTYPE
#define SYMBOLTYPE
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
    // codegen
    char* typeBase;
    int listTemporary;
    int paramTemporary;
} t_symbol;
#endif


extern t_symbol *SymbolTable;
extern t_symbol *lastSymbol;
extern t_symbol **parameterHolder;
extern int parameterHolderMax;


t_symbol* createSymbol(char* symbolName, char* type, int line, int column, int scopeValue, int parentScope, int varFunc, char* typeBase);

t_symbol* getSymbol(char* symbolName);

t_symbol* getSymbolFilter(char* symbolName, int scope, int varFunc);

t_symbol* getSymbolWithScope(char* symbolName, int scope);

t_symbol* getSymbolValidScope(char* symbolName);

t_symbol* getSymbolValidScopeVar(char* symbolName);

t_symbol* getSymbolValidScopeFunc(char* symbolName);

// adds parameter to temporary holder
void addParam(t_symbol* parameter);

// moves all parameters on temporary holder to the function
void installParam(t_symbol* function);

void addSymbolListTemporary(t_symbol* symbol, int listTemporary);

void addSymbolParamTemporary(t_symbol* symbol, int paramTemporary);

void printTable();

void printTable2();

t_symbol* printChildren(t_symbol* fixedSymbol, int level);

void printParams();

void freeTable();

// void insertSymbol();
