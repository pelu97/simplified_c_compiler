#include <stdlib.h>
#include <stdio.h>
#include "../lib/base.h"
#include "../lib/scope.h"


t_scope* ScopeStack = NULL;
t_scope* topScope = NULL;

int lastScopeValue = -1;


void pushScope(int value, int parentScope){
    t_scope* scope;

    scope = (t_scope*) malloc(sizeof(t_scope));

    scope->next = topScope;
    scope->scopeValue = value;
    scope->parentScope = parentScope;

    topScope = scope;


    if(ScopeStack == NULL){
        ScopeStack = scope;
    }

}

// ainda não limpa da memória, é necessário tratar isso futuramente
// retorna -1 caso a pilha esteja vazia
int popScope(){
    int value;
    t_scope* temp;


    if(topScope != NULL){
        value = topScope->scopeValue;
        temp = topScope;
        topScope = topScope->next;

        free(temp);
    }
    else{
        value = -1;
    }

    return value;

}

int checkScope(){
    int value;

    if(topScope != NULL){
        value = topScope->scopeValue;
    }
    else{
        value = -1;
    }

    return value;
}

t_scope* getScope(){
    t_scope* scope;

    scope = (t_scope*) malloc(sizeof(t_scope));

    if(topScope != NULL){
        scope->scopeValue = topScope->scopeValue;
        scope->parentScope = topScope->parentScope;
    }
    else{
        scope->scopeValue = -1;
        scope->parentScope = -1;
    }

    return scope;
}

void freeScopeToken(t_scope* scope){
    if(scope != NULL){
        free(scope);
    }
}

void freeScope(){
    t_scope* scope;
    t_scope* temp;

    scope = topScope;

    while(scope != NULL){
        temp = scope;
        scope = scope->next;

        free(temp);
    }
}
