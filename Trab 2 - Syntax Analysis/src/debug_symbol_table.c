#include <stdlib.h>
#include <stdio.h>
#include "symbol_table.h"



int main(){
    t_symbol* symbol = NULL;

    createSymbol("Simbolo 1", "type", 1, 1, 0, -1);

    createSymbol("Simbolo 2", "type", 1, 1, 2, 1);

    createSymbol("Simbolo 3", "type", 1, 1, 2, 1);

    createSymbol("Simbolo 4", "type", 1, 1, 2, 1);

    createSymbol("Simbolo escopo pai", "type", 1, 1, 1, 0);

    createSymbol("Simbolo 6", "type", 1, 1, 0, -1);


    printTable();

    printTable2();

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
