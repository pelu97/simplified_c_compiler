#include <stdlib.h>
#include <stdio.h>
#include "../lib/symbol_table.h"



int main(){
    t_symbol* symbol = NULL;
    int i;

    createSymbol("Simbolo 1", "type", 1, 1, 0, -1, 0);

    createSymbol("Simbolo 2", "type", 1, 1, 2, 1, 1);

    createSymbol("Simbolo 3", "type", 1, 1, 2, 1, 1);

    createSymbol("Simbolo 4", "type", 1, 1, 2, 1, 0);

    createSymbol("Simbolo escopo pai", "type", 1, 1, 1, 0, 0);

    createSymbol("Simbolo 6", "type", 1, 1, 0, -1, 0);

    symbol = getSymbol("Simbolo 2");
    printf("%d - %d\n", sizeof(parameterHolder), parameterHolderMax);

    addParam(symbol);
    addParam(symbol);
    addParam(symbol);
    addParam(symbol);
    printf("%d - %d\n", sizeof(parameterHolder), parameterHolderMax);

    symbol = getSymbol("Simbolo 3");

    addParam(symbol);

    symbol = getSymbol("Simbolo 1");

    printf("%d - %d\n", sizeof(parameterHolder), parameterHolderMax);

    installParam(symbol);


    printTable();

    printTable2();


    for(symbol= SymbolTable; symbol != NULL; symbol = symbol->next){
        // printf("|%28.28s|", "123456789012345678901234567890123456789012345678901234567890");
        printf("|%-28.28s|", symbol->name);
        printf("%-14s|", symbol->type);
        printf("%-5d - %-5d|", symbol->scopeValue, symbol->parentScope);
        printf("%-14d|", symbol->line);
        printf("%-14d|", symbol->column);
        printf("Parameters: ");
        for(i=0; i < symbol->paramNumber; i++){
            printf("%s,", symbol->parameters[i]->name);
        }
        printf("\n");

        // printf("Symbol read from table: %s\n", pointer->name);
    }


    printf("Looking for symbol test_get\n");

    symbol = getSymbol("test_get");

    printf("Search ended\n");



    if(symbol != NULL){
        printf("Found %s\n", symbol->name);
    }
    else{
        printf("Not found\n");
    }




    return 0;
}
