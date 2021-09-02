#include <stdlib.h>
#include <stdio.h>
#include "scope.h"



int main(){
    int value;
    t_scope* scope;

    int i;

    for(i=0; i<5; i++){
        printf("Inserindo escopo: %d %d\n", i, i-1);
        pushScope(i, i-1);
    }

    printf("Pilha de escopo preenchida - removendo\n");


    printf("Checando escopo: %d\n", checkScope());

    value = i;

    while(value != 0) {
        scope = getScope();
        value = popScope();
        printf("Escopo removido: %d %d\n", scope->scopeValue, scope->parentScope);
    }

    return 0;
}
