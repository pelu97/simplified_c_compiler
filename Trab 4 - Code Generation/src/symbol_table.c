#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/symbol_table.h"
#include "../lib/base.h"
#include "../lib/scope.h"

// ainda não limpa a tabela da memória, ainda é necessário tratar isso
t_symbol *SymbolTable = NULL;
t_symbol *lastSymbol = NULL;
t_symbol **parameterHolder = NULL;
int parameterHolderMax = 0;

t_symbol* createSymbol(char* symbolName, char* type, int line, int column, int scopeValue, int parentScope, int varFunc, char* typeBase){
    t_symbol *symbol;

    symbol = (t_symbol*) malloc(sizeof(t_symbol));
    symbol->name = (char*) malloc(strlen(symbolName) + 1);
    symbol->type = (char*) malloc(strlen(type) + 1);
    symbol->typeBase = (char*) malloc(strlen(typeBase) + 1);

    strcpy(symbol->name, symbolName);
    strcpy(symbol->type, type);
    strcpy(symbol->typeBase, typeBase);

    symbol->next = NULL;

    symbol->line = line;
    symbol->column = column;

    symbol->scopeValue = scopeValue;
    symbol->parentScope = parentScope;
    symbol->varFunc = varFunc;
    symbol->paramNumber = 0;
    symbol->parameters = NULL;

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

    return symbol;


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


t_symbol* getSymbolFilter(char* symbolName, int scope, int varFunc){
    t_symbol* pointer;
    t_symbol* found = NULL;

    for(pointer = SymbolTable; pointer != NULL && found == NULL; pointer = pointer->next){
        // printf("Comparing %s with %s\n", symbolName, pointer->name);
        if((strcmp(pointer->name, symbolName) == 0) && (pointer->scopeValue == scope) && ( (varFunc == -1) || ((varFunc != -1) && (pointer->varFunc == varFunc)) ) ){
            found = pointer;
            // printf("Symbol found - ending search\n");
        }
    }

    return found;
}


t_symbol* getSymbolWithScope(char* symbolName, int scope){
    t_symbol* pointer;
    t_symbol* found = NULL;

    for(pointer = SymbolTable; pointer != NULL && found == NULL; pointer = pointer->next){
        // printf("Comparing %s with %s\n", symbolName, pointer->name);
        if((strcmp(pointer->name, symbolName) == 0) && (pointer->scopeValue == scope)){
            found = pointer;
            // printf("Symbol found - ending search\n");
        }
    }

    return found;
}


t_symbol* getSymbolValidScope(char* symbolName){
    // t_symbol* pointer;
    t_symbol* symbol = NULL;
    t_scope* scopePointer = NULL;

    for(scopePointer = topScope; scopePointer != NULL; scopePointer = scopePointer->next){
        symbol = getSymbolFilter(symbolName, scopePointer->scopeValue, -1);

        if(symbol != NULL){
            break;
        }
    }

    return symbol;
}


t_symbol* getSymbolValidScopeVar(char* symbolName){
    // t_symbol* pointer;
    t_symbol* symbol = NULL;
    t_scope* scopePointer = NULL;

    for(scopePointer = topScope; scopePointer != NULL; scopePointer = scopePointer->next){
        symbol = getSymbolFilter(symbolName, scopePointer->scopeValue, 1);

        if(symbol != NULL){
            break;
        }
    }

    // for(pointer = SymbolTable; pointer != NULL && found == NULL; pointer = pointer->next){
    //     // printf("Comparing %s with %s\n", symbolName, pointer->name);
    //     if((strcmp(pointer->name, symbolName) == 0) && (pointer->scopeValue == scope) && (pointer->varFunc == 1)){
    //         found = pointer;
    //         // printf("Symbol found - ending search\n");
    //     }
    // }

    return symbol;
}


t_symbol* getSymbolValidScopeFunc(char* symbolName){
    // t_symbol* pointer;
    t_symbol* symbol = NULL;
    t_scope* scopePointer = NULL;

    for(scopePointer = topScope; scopePointer != NULL; scopePointer = scopePointer->next){
        symbol = getSymbolFilter(symbolName, scopePointer->scopeValue, 0);

        if(symbol != NULL){
            break;
        }
    }

    return symbol;
}


void addParam(t_symbol* parameter){
    t_symbol** temp;

    temp = realloc(parameterHolder, (sizeof(t_symbol*) * (parameterHolderMax + 1)));


    if(temp != NULL){
        parameterHolder = temp;

        parameterHolder[parameterHolderMax] = parameter;
        parameterHolderMax++;
    }
    else{
        printf("Fatal error on memory allocation for parameter holder\n");
    }

    // temp = (t_node**) realloc(node->child, (sizeof(t_node*) * (n + 1)));
}


void installParam(t_symbol* function){

    function->parameters = parameterHolder;
    function->paramNumber = parameterHolderMax;

    parameterHolder = NULL;
    parameterHolderMax = 0;
}



void printTable(){
    t_symbol *pointer;

    printf("|-------------------------------------SYMBOL TABLE--------------------------------------|\n");
    printf("|_______________________________________________________________________________________|\n");
    printf("|------------NAME------------|-----TYPE-----|----SCOPE----|-----LINE-----|----COLUMN----|\n");
    // printf("%s\n", SymbolTable->name);
    for(pointer = SymbolTable; pointer != NULL; pointer = pointer->next){
        // printf("|%28.28s|", "123456789012345678901234567890123456789012345678901234567890");
        printf("|%-28.28s|", pointer->name);
        printf("%-14s|", pointer->type);
        printf("%-5d - %-5d|", pointer->scopeValue, pointer->parentScope);
        printf("%-14d|", pointer->line);
        printf("%-14d|\n", pointer->column);
        // printf("Symbol read from table: %s\n", pointer->name);
    }

    printf("|_______________________________________________________________________________________|\n");
    printf("|---------------------------------------END TABLE---------------------------------------|\n");
}




void printTable2(){
    t_symbol *pointer;
    int currentScope = 0;

    printf("┌────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│---------------------------------------SYMBOL TABLE-----------------------------------------│\n");
    // printf("|____________________________________________________________________________________________|\n");
    printf("│------------NAME------------|-----TYPE-----|--SCOPE--|----LINE----|---COLUMN---|--" COLOR_VAR "VAR" COLOR_RESET "/" COLOR_FUNC "FUNC" COLOR_RESET "--│\n");
    // printf("%s\n", SymbolTable->name);
    for(pointer = SymbolTable; pointer != NULL; pointer = pointer->next){
        // printf("|%28.28s|", "123456789012345678901234567890123456789012345678901234567890");
        if(pointer->scopeValue > currentScope){
            pointer = printChildren(pointer, 1);
        }
        else{
            // printf("|%-28.28s|", pointer->name);
            // printf("%-14s|", pointer->type);
            // printf("%-9d|", pointer->scopeValue);
            // // printf("%-16d|", pointer->parentScope);
            // printf("%-12d|", pointer->line);
            // printf("%-12d|", pointer->column);
            if(pointer->varFunc == 1){
                printf(COLOR_VAR "│" "%-28.28s"  "│", pointer->name);
                printf("%-14s│", pointer->type);
                printf("%-9d│", pointer->scopeValue);
                // printf("%-16d│", pointer->parentScope);
                printf("%-12d│", pointer->line);
                printf("%-12d│", pointer->column);
                printf("%-12s│\n" COLOR_RESET, "var");
            }
            else{
                printf(COLOR_FUNC"│" "%-28.28s""│", pointer->name);
                printf("%-14s│", pointer->type);
                printf("%-9d│", pointer->scopeValue);
                // printf("%-16d│", pointer->parentScope);
                printf("%-12d│", pointer->line);
                printf("%-12d│", pointer->column);
                printf("%-12s│\n" COLOR_RESET, "func");
            }
            // printf("Symbol read from table: %s\n", pointer->name);
        }
        currentScope = pointer->scopeValue;
    }

    // printf("|____________________________________________________________________________________________|\n");
    printf("│-----------------------------------------END TABLE------------------------------------------│\n");
    printf("└────────────────────────────────────────────────────────────────────────────────────────────┘\n\n\n");
}

t_symbol* printChildren(t_symbol* fixedSymbol, int level){
    t_symbol* pointer;
    t_symbol* parentPointer;
    int flag = 0;
    int found = 0;

    // printf("printing children of %d\n", fixedSymbol->scopeValue);

    parentPointer = fixedSymbol;
    while((parentPointer != NULL) && (parentPointer->scopeValue >= fixedSymbol->parentScope) && (found == 0)){
        if((parentPointer->scopeValue == fixedSymbol->parentScope)){
            found = 1;
        }
        else{
            parentPointer = parentPointer->next;
            // printf("parent not found yet, getting next symbol %d\n", parentPointer);

            // if(parentPointer == NULL){
            //     found = -1;
            //     // printf("Table ended before finding parent\n");
            // }
        }
    }



    // parent scope found in table
    if(found == 1){
        // printf("parent found: %d - %d\n", found, parentPointer->scopeValue);

        if(parentPointer->varFunc == 1){
            printf(COLOR_VAR);
        }
        else{
            printf(COLOR_FUNC);
        }
        if(level > 1){
            printf("│%*s%-*.*s│", ((level-1)*2), " ", (28-((level-1)*2)), (28-((level-1)*2)), parentPointer->name);
        }
        else{
            printf("│%-*.*s│", (28-((level-1)*2)), (28-((level-1)*2)), parentPointer->name);
        }
        printf("%-14s│", parentPointer->type);
        printf("%-9d│", parentPointer->scopeValue);
        // printf("%-16d│", parentPointer->parentScope);
        printf("%-12d│", parentPointer->line);
        printf("%-12d│", parentPointer->column);
        if(parentPointer->varFunc == 1){
            printf("%-12s│\n", "var");
        }
        else{
            printf("%-12s│\n", "func");
        }
        printf(COLOR_RESET);
    }
    else if(fixedSymbol->parentScope > -1){
        if(level > 1){
            printf("│%*s%-*.*s│", ((level-1)*2), " ", (28-((level-1)*2)), (28-((level-1)*2)), "--New scope without ID--");
        }
        else{
            printf("│%-*.*s│", (28-((level-1)*2)), (28-((level-1)*2)), "--New scope without ID--");
        }
        printf("%-14s│", " ");
        printf("%-9d│", -1);
        // printf("%-16d│", -1);
        printf("%-12d│", -1);
        printf("%-12d│", -1);
        printf("%-12s│\n", " ");
        // if(pointer->varFunc == 1){
        //     printf("%-12s│\n", "var");
        // }
        // else{
        //     printf("%-12s│\n", "func");
        // }

    }

    // printf("parent printed if found\n");

    pointer = fixedSymbol;
    while(flag == 0){
        if((pointer->scopeValue != fixedSymbol->scopeValue) && (pointer->scopeValue > fixedSymbol->parentScope)){
            pointer = printChildren(pointer, level+1);
            flag = 1;
        }
        else if(pointer->scopeValue <= fixedSymbol->parentScope){
            flag = 1;
        }
        else{
            // printf("printing the children\n");
            if(pointer->varFunc == 1){
                printf(COLOR_VAR);
            }
            else{
                printf(COLOR_FUNC);
            }

            printf("│%*s%-*.*s│", level*2, " ", (28-(level*2)), (28-(level*2)), pointer->name);
            printf("%-14s│", pointer->type);
            printf("%-9d│", pointer->scopeValue);
            // printf("%-16d│", pointer->parentScope);
            printf("%-12d│", pointer->line);
            printf("%-12d│", pointer->column);
            if(pointer->varFunc == 1){
                printf("%-12s│\n", "var");
            }
            else{
                printf("%-12s│\n", "func");
            }
            printf(COLOR_RESET);

            if(pointer->next != NULL){
                pointer = pointer->next;
            }
            else{
                flag = 1;
            }
        }

    }

    return pointer;
}


void printParams(){
    t_symbol* pointer;
    int i;

    for(pointer = SymbolTable; pointer != NULL; pointer = pointer->next){
        // printf("|%28.28s|", "123456789012345678901234567890123456789012345678901234567890");
        printf("|%-28.28s|", pointer->name);
        printf("Parameters (%d): ", pointer->paramNumber);

        for(i = 0; i < pointer->paramNumber; i++){
            printf(" %s ", pointer->parameters[i]->name);
        }
        printf("\n");
        // printf("Symbol read from table: %s\n", pointer->name);
    }
}

void freeTable(){
    t_symbol* pointer;
    t_symbol* temp;
    int i;

    pointer = SymbolTable;
    i=0;

    while(pointer != NULL){
        temp = pointer;      //aponta para o atual
        pointer = pointer->next;    //pega o próximo

        #ifdef DEBUG
        printf("Freeing pointer to symbol: %s\n", temp->name);
        #endif

        if(temp->name != NULL){
            free(temp->type);   //libera a memória alocada para o tipo
        }

        if(temp->name != NULL){
            free(temp->name);   //libera a memória alocada para o nome
        }

        if(temp->parameters != NULL){
            free(temp->parameters); //libera a memória alocada para os parâmetros
        }

        free(temp);      //libera o atual

        i++;
    }

    #ifdef DEBUG
    printf("%d symbols freed\n", i);
    #endif

}
