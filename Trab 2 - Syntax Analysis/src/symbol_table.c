#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"
#include "base.h"


t_symbol *SymbolTable = NULL;
t_symbol *lastSymbol = NULL;

void createSymbol(char* symbolName, int line, int column){
    t_symbol *symbol;

    symbol = (t_symbol*) malloc(sizeof(t_symbol));
    symbol->name = (char*) malloc(sizeof(symbolName) + 1);

    strcpy(symbol->name, symbolName);

    symbol->next = NULL;

    symbol->line = line;
    symbol->column = column;

    // lastSymbol->next = symbol;

    // lastSymbol = symbol;

    if(SymbolTable == NULL) {
        SymbolTable = symbol;
        // printf("First symbol inserted\n");
    }

    if(lastSymbol == NULL){
        lastSymbol = symbol;
    }
    else{
        lastSymbol->next = symbol;

        lastSymbol = symbol;
    }


    // printf("Symbol inserted: %s\n", symbol->name);
}

t_symbol* getSymbol(char* symbolName){
    t_symbol* pointer;
    t_symbol* found = NULL;

    for(pointer = SymbolTable; pointer != NULL && found == NULL; pointer = pointer->next){
        // printf("Comparing %s with %s\n", symbolName, pointer->name);
        if(strcmp(pointer->name, symbolName) == 0){
            found = pointer;
            // printf("Symbol found - ending search\n");
        }
    }

    return found;
}

void printTable(){
    t_symbol *pointer;

    printf("-------Printing table------\n");

    // printf("%s\n", SymbolTable->name);
    for(pointer = SymbolTable; pointer != NULL; pointer = pointer->next){
        printf("Symbol read from table: %s\n", pointer->name);
    }

    printf("-------End table------\n");
}