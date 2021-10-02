#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/semantic.h"
#include "../lib/base.h"
#include "../lib/symbol_table.h"


t_semerror** semanticErrors = NULL;
int semanticErrorsTotal = 0;

void addError(char* type, char* message, int line, int column){
    t_semerror* error;

    semanticErrorsTotal++;

    semanticErrors = realloc(semanticErrors, (sizeof(t_semerror*) * semanticErrorsTotal));

    printf("Adding error with type %s and message %s\n", type, message);

    error = malloc(sizeof(t_semerror));

    error->type = malloc(strlen(type) + 1);
    strcpy(error->type, type);

    error->message = malloc(strlen(message) + 1);
    strcpy(error->message, message);

    error->line = line;
    error->column = column;
}

void printErrors(){
    int i;

    for(i=0; i<semanticErrorsTotal; i++){
        printf("%s\n", semanticErrors[i]->message);
    }
}

int checkMain(){
    t_symbol* pointer;
    int found = 0;

    for(pointer = SymbolTable; pointer != NULL; pointer = pointer->next){
        if((strcmp(pointer->name, "main") == 0) && (pointer->varFunc == 0)){
            found++;
        }
        printf("Comparing %s with main - varFunc=%d\n", pointer->name, pointer->varFunc);
    }

    return found;
}



void checkFunctions(){
    t_symbol* pointer;
    t_symbol* pointerTemp;
    int* functionChecked;
    int i, functionNumber, j;
    char* temp;

    // allocate and initialize an array to mark function definitions that have already been checked
    functionChecked = NULL;
    functionNumber = 0;
    for(pointer = SymbolTable; pointer != NULL; pointer = pointer->next){
        if(pointer->varFunc == 0){
            functionNumber++;
        }
    }

    functionChecked = malloc((sizeof(int) * (functionNumber)));

    i = 0;
    j = 0;
    for(pointer = SymbolTable; pointer != NULL; pointer = pointer->next){
        if(pointer->varFunc == 0){
            for(pointerTemp = SymbolTable; pointerTemp != NULL; pointerTemp = pointerTemp->next){
                if(strcmp(pointer->name, pointerTemp->name) == 0){
                    if((pointer != pointerTemp) && (functionChecked[j] == 0)){
                        // redefinicao de uma funcao
                        temp = malloc(strlen("Redefinition of function ") + strlen(pointer->name) + strlen(". Previous definition on position: "));
                        strcpy(temp, "Redefinition of function ");
                        strcat(temp, pointer->name);
                        strcat(temp, ". Previous definition on position: ");
                        addError("funcRedef", temp, -1, -1);

                        functionChecked[j] = 1;
                        free(temp);
                    }
                    j++;
                }
            }
            functionChecked[i] = 1;
            i++;
        }
    }
}


void checkFunctionCall(t_node* node){
    int i, paramNumber, j, correct;
    char** types = NULL;
    t_symbol* funcDeclaration;

    // check children of node for types
    // store types in temporary array of strings
    // find function declaration in symbol table
    // compare types and number of arguments stored in temporary array with the symbol table declaration of the function
    // profit

    #ifdef DEBUG_SEMANTIC
    printf("Function call check - Checking function call...\n");
    #endif

    // soma 1 no número de parâmetros para compensar que o retorno da função é o último índice
    paramNumber = getFunctionCallParameters(node->child[0], -1, &types) + 1;

    #ifdef DEBUG_SEMANTIC
    printf("Function call check - Got %d parameters used in function call - size of types pointer: %d\n", paramNumber, sizeof(types));
    #endif

    // printBranch(node, 0);

    printf("Parâmetros no nó: %s\n", node->name);
    for(i=0; i<paramNumber; i++){
        #ifdef DEBUG_SEMANTIC
        printf("Function call check - Printing type %d - length: %d\n", i, strlen(types[i]));
        #endif
        printf("%s\n", types[i]);
    }

    funcDeclaration = getSymbol(node->functionName);

    if(funcDeclaration != NULL){
        j = paramNumber-1;
        correct = 1;

        if(paramNumber == funcDeclaration->paramNumber){
            for(i=0; i<paramNumber; i++){
                #ifdef DEBUG_SEMANTIC
                printf("Function call check - Comparing types %s - %s\n", types[j], funcDeclaration->parameters[i]->type);
                #endif

                if(strcmp(types[j], funcDeclaration->parameters[i]->type) != 0){
                    correct = 0;
                    printf("Wrong parameter type (%s - %s) in call to function %s\n", types[j], funcDeclaration->parameters[i]->type, funcDeclaration->name);
                }
                j--;
            }
        }
        else{
            // different number of parameters
            printf("Wrong number of parameters in call to function %s\n", funcDeclaration->name);
        }


    }
    else{
        printf("Error when looking for function declaration - function '%s' not declared in symbol table\n", node->functionName);
    }

}

int getFunctionCallParameters(t_node* node, int index, char*** types){
    // int size = 0;
    // child 0 é nó para o próximo parâmetro - se não houver child 1, child 0 é o último tipo
    // child 1 é o parâmetro atual

    #ifdef DEBUG_SEMANTIC
    printf("Function call check - Getting parameters from function call - index: %d, node: %s\n", index, node->name);
    #endif


    // if(node->child != NULL){
    //     if(node->child[0]->child != NULL){
    //         // armazena o tipo do child 1 em algum lugar
    //         // chama a recursão no child 0 que é o nó para o próximo tipo
    //         #ifdef DEBUG_SEMANTIC
    //         printf("Function call check - Node still has more than one child - recursion\n");
    //         #endif
    //
    //         addTempType(types, node->child[1]->type, index);
    //         index++;
    //         getFunctionCallParameters(node->child[0], index, types);
    //     }
    //     else{
    //         // armazena o tipo do child 0 em algum lugar
    //         // final da recursão - último parâmetro
    //         #ifdef DEBUG_SEMANTIC
    //         printf("Function call check - Node only has one child - no recursion\n");
    //         #endif
    //
    //         addTempType(types, node->child[0]->type, index);
    //         index++;
    //     }
    // }

    if(node->child != NULL){
        if(node->child[0]->child != NULL){
            // armazena o tipo do child 1 em algum lugar
            // chama a recursão no child 0 que é o nó para o próximo tipo
            #ifdef DEBUG_SEMANTIC
            printf("Function call check - Node still has more than one paramater child - recursion\n");
            #endif

            *types = addTempType(*types, node->child[1]->type, index);
            index++;
            index = getFunctionCallParameters(node->child[0], index, types);
        }
        else{
            // armazena o tipo do child 0 em algum lugar
            // final da recursão - último parâmetro
            #ifdef DEBUG_SEMANTIC
            printf("Function call check - Node only has expression childs - no recursion\n");
            #endif

            *types = addTempType(*types, node->child[1]->type, index);
            index++;
            *types = addTempType(*types, node->child[0]->type, index);
            index++;
        }
    }
    else{
        #ifdef DEBUG_SEMANTIC
        printf("Function call check - Node has no childs, check if it's an empty node\n");
        #endif

        if(node->empty == 0){
            // caso de só existir um parâmetro. O nó passado no início da execução não tem filhos e já é o nó que deve ser analisado
            *types = addTempType(*types, node->type, index);
            index++;
        }
        // caso o nó não tenha filhos e seja vazio, não há nada a fazer. É o nó criado quando a chamada de função não possuía parâmetros
    }

    return index;
}

char** addTempType(char** types, char* type, int index){
    char** temp;

    #ifdef DEBUG_SEMANTIC
    printf("Function call check - Adding temporary type: %s\n", type);
    #endif

    // temp = realloc(types, (size + strlen(type) + 1));
    temp = realloc(types, (sizeof(char*) * (index+2)));
    // index + 2 compensa pela posição do índice que começa em 0 (+1) e pelo fato de estar adicionado mais um elemento (+1)
    // então index+2 representa o número de elementos atuais +1 que será adicionado agora


    if(temp != NULL){
        types = temp;

        #ifdef DEBUG_SEMANTIC
        printf("Function call check - Allocated memory for temporary array of types: %d bytes\n", (sizeof(char*) * (index+1)));
        #endif

        index++;
        types[index] = malloc(strlen(type) + 1);

        #ifdef DEBUG_SEMANTIC
        printf("Function call check - Allocated memory for temporary type: %s - index: %d - bytes: %d\n", type, index, (strlen(type) + 1));
        #endif

        strcpy(types[index], type);

        // size = size + strlen(type) + 1;

        #ifdef DEBUG_SEMANTIC
        printf("Function call check - Copied temporary type: %s - index: %d\n", type, index);
        #endif
    }
    else{
        printf("Error when allocating memory for temporary type array in function call checking\n");
    }

    #ifdef DEBUG_SEMANTIC
    printf("Function call check - Added temporary type: %s\n", types[index]);
    #endif

    return types;
}


void semanticAnalysis(){
    int mainFunction;

    mainFunction = checkMain();

    if(mainFunction == 0){
        printf("Não foi encontrada uma definição para a main\n");
    }
    else if(mainFunction == 1){
        printf("Foi encontrada uma definição correta para a main\n");
    }
    else if(mainFunction > 1){
        printf("Foram encontradas múltiplas definições para a main\n");
    }
    else{
        printf("Erro ao procurar a definição para a main\n");
    }

    // checkFunctions();


    // printf("%d\n", semanticErrorsTotal);
    // printErrors();

}
