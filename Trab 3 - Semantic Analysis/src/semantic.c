#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/semantic.h"
#include "../lib/base.h"
#include "../lib/symbol_table.h"
#include "../lib/scope.h"


t_semerror** semanticErrors = NULL;
int semanticErrorsTotal = 0;

void addError(char* type, char* message, char* error_text, int line, int column){
    t_semerror* error;

    semanticErrorsTotal++;

    semanticErrors = realloc(semanticErrors, (sizeof(t_semerror*) * semanticErrorsTotal));

    #ifdef DEBUG_SEMANTIC
    printf("Adding error with type %s and message %s\n", type, message);
    #endif

    error = malloc(sizeof(t_semerror));

    error->type = malloc(strlen(type) + 1);
    strcpy(error->type, type);

    error->message = malloc(strlen(message) + 1);
    strcpy(error->message, message);

    error->error_text = malloc(strlen(error_text) + 1);
    strcpy(error->error_text, error_text);

    error->line = line;
    error->column = column;

    semanticErrors[semanticErrorsTotal-1] = error;
}

void printErrors(){
    int i;

    #ifdef DEBUG_SEMANTIC
    printf("Printing %d semantic errors\n", semanticErrorsTotal);
    #endif

    for(i=0; i<semanticErrorsTotal; i++){
        printf("%s - line: %d, column: %d\n", semanticErrors[i]->message, semanticErrors[i]->line, semanticErrors[i]->column);
    }
}

int checkMain(){
    t_symbol* pointer;
    int found = 0;
    char temp[500];
    int line, column;

    for(pointer = SymbolTable; pointer != NULL; pointer = pointer->next){
        if((strcmp(pointer->name, "main") == 0) && (pointer->varFunc == 0)){
            found++;

            if(found == 1){
                line = pointer->line;
                column = pointer->column;
            }

            if(found > 1){
                sprintf(temp, "Redefinition of function main. Previous definition on line %d, column %d.", line, column);

                // strcpy(temp, "Redefinition of function main. Previous definition on line ");
                // strcat(temp, line);
                // strcat(temp, ", column ");
                // strcat(temp, column);

                addError("mainRedef", temp, "", pointer->line, pointer->column);
            }
        }

        #ifdef DEBUG_SEMANTIC
        printf("Comparing %s with main - varFunc=%d\n", pointer->name, pointer->varFunc);
        #endif
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
                        addError("funcRedef", temp, "test", -1, -1);

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
    // char** types = NULL;
    t_typeTemp** types = NULL;
    t_symbol* funcDeclaration;
    char temp[500];

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

    // printf("Parâmetros no nó: %s\n", node->name);
    for(i=0; i<paramNumber; i++){
        #ifdef DEBUG_SEMANTIC
        printf("Function call check - Printing type %d - length: %d\n", i, strlen(types[i]->type));
        printf("%s\n", types[i]->type);
        #endif
        NULL;
    }

    funcDeclaration = getSymbol(node->functionName);

    if(funcDeclaration != NULL){
        j = paramNumber-1;
        correct = 1;

        if(paramNumber == funcDeclaration->paramNumber){
            for(i=0; i<paramNumber; i++){
                #ifdef DEBUG_SEMANTIC
                printf("Function call check - Comparing types %s - %s\n", types[j]->type, funcDeclaration->parameters[i]->type);
                #endif

                if(strcmp(types[j]->type, funcDeclaration->parameters[i]->type) != 0){
                    correct = 0;
                    // printf("Wrong parameter type (%s - %s) in call to function %s\n", types[j]->type, funcDeclaration->parameters[i]->type, funcDeclaration->name);

                    strcpy(temp, "Wrong parameter type in call to function ");
                    strcat(temp, funcDeclaration->name);
                    strcat(temp, ". Expected ");
                    strcat(temp, funcDeclaration->parameters[i]->type);
                    strcat(temp, " - got ");
                    strcat(temp, types[j]->type);
                    addError("paramType", temp, "", types[j]->line, types[j]->column);
                }
                j--;
            }
        }
        else{
            // different number of parameters
            // printf("Wrong number of parameters in call to function %s\n", funcDeclaration->name);
            strcpy(temp, "Wrong number of parameters in call to function ");
            strcat(temp, funcDeclaration->name);
            addError("paramNumber", temp, "", node->line, node->column);
        }


    }
    else{
        // printf("Error when looking for function declaration - function '%s' not declared in symbol table\n", node->functionName);
        NULL;
    }

}

int getFunctionCallParameters(t_node* node, int index, t_typeTemp*** types){
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

            *types = addTempType(*types, node->child[1]->type, index, node->child[1]->line, node->child[1]->column);
            index++;
            index = getFunctionCallParameters(node->child[0], index, types);
        }
        else{
            // armazena o tipo do child 0 em algum lugar
            // final da recursão - último parâmetro
            #ifdef DEBUG_SEMANTIC
            printf("Function call check - Node only has expression childs - no recursion\n");
            #endif

            *types = addTempType(*types, node->child[1]->type, index, node->child[1]->line, node->child[1]->column);
            index++;
            *types = addTempType(*types, node->child[0]->type, index, node->child[0]->line, node->child[0]->column);
            index++;
        }
    }
    else{
        #ifdef DEBUG_SEMANTIC
        printf("Function call check - Node has no childs, check if it's an empty node\n");
        #endif

        if(node->empty == 0){
            // caso de só existir um parâmetro. O nó passado no início da execução não tem filhos e já é o nó que deve ser analisado
            *types = addTempType(*types, node->type, index, node->line, node->column);
            index++;
        }
        // caso o nó não tenha filhos e seja vazio, não há nada a fazer. É o nó criado quando a chamada de função não possuía parâmetros
    }

    return index;
}

t_typeTemp** addTempType(t_typeTemp** types, char* type, int index, int line, int column){
    t_typeTemp** temp;

    #ifdef DEBUG_SEMANTIC
    printf("Function call check - Adding temporary type: %s\n", type);
    #endif

    // temp = realloc(types, (size + strlen(type) + 1));
    temp = realloc(types, (sizeof(t_typeTemp*) * (index+2)));
    // index + 2 compensa pela posição do índice que começa em 0 (+1) e pelo fato de estar adicionado mais um elemento (+1)
    // então index+2 representa o número de elementos atuais +1 que será adicionado agora


    if(temp != NULL){
        types = temp;

        #ifdef DEBUG_SEMANTIC
        printf("Function call check - Allocated memory for temporary array of types: %d bytes\n", (sizeof(t_typeTemp*) * (index+2)));
        #endif

        index++;
        // types[index] = malloc(strlen(type) + 1);
        // types[index] = malloc((strlen(type) + 1) + (sizeof(int) * 2));
        types[index] = malloc(sizeof(t_typeTemp));
        types[index]->type = malloc(strlen(type) + 1);

        #ifdef DEBUG_SEMANTIC
        printf("Function call check - Allocated memory for temporary type: %s - index: %d - bytes: %d, bytes for type: %d\n", type, index, (sizeof(t_typeTemp)), (strlen(type) + 1));
        #endif

        strcpy(types[index]->type, type);
        types[index]->line = line;
        types[index]->column = column;
        // size = size + strlen(type) + 1;

        #ifdef DEBUG_SEMANTIC
        printf("Function call check - Copied temporary type: %s - index: %d\n", type, index);
        #endif
    }
    else{
        printf("Error when allocating memory for temporary type array in function call checking\n");
    }

    #ifdef DEBUG_SEMANTIC
    printf("Function call check - Added temporary type: %s\n", types[index]->type);
    #endif

    return types;
}


void checkIdDeclaration(t_node* node){
    t_symbol* pointer;
    int found = 0;
    char temp[300];

    for(pointer = SymbolTable; pointer != NULL; pointer = pointer->next){
        if(strcmp(node->id, pointer->name) == 0){
            // achou o símbolo na tabela
            // não procura o símbolo no escopo mais próximo (que é o que seria usado)
            // procura apenas se existe um símbolo com esse nome em um escopo válido
            // (escopo atual ou algum escopo pai, ou seja, algum escopo atualmente na pilha)
            if(findInScopeStack(pointer->scopeValue) == 1){
                found++;
                break;
            }
        }
    }

    if(found == 0){
        // printf("Uso de uma variável ou função não declarada - %s\n", node->id);

        strcpy(temp, "Variable or function ");
        strcat(temp, node->id);
        strcat(temp, " undeclared in this scope.");

        addError("undeclaredId", temp, "", node->line, node->column);
    }
    else{
        // else para testes, no final só é preciso imprimir quando ocorrer erro
        // printf("Uso de uma variável ou função declarada corretamente - %s\n", node->id);
        NULL;
    }
}


void semanticAnalysis(){
    int mainFunction;

    mainFunction = checkMain();

    // if(mainFunction == 0){
    //     printf("Não foi encontrada uma definição para a main\n");
    // }
    // else if(mainFunction == 1){
    //     printf("Foi encontrada uma definição correta para a main\n");
    // }
    // else if(mainFunction > 1){
    //     printf("Foram encontradas múltiplas definições para a main\n");
    // }
    // else{
    //     printf("Erro ao procurar a definição para a main\n");
    // }

    // checkFunctions();


    // printf("%d\n", semanticErrorsTotal);
    printErrors();

}
