#include <stdlib.h>
#include <stdio.h>
#include "symbol_table.h"



int main(){
    t_symbol* symbol = NULL;

    createSymbol("Simbolo 1", 1, 1);

    createSymbol("Simbolo 3", 3, 3);

    createSymbol("test_get", 4, 7);

    createSymbol("Simbolo 8", 12, 34);

    printTable();

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
