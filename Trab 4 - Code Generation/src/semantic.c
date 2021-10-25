#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/semantic.h"
#include "../lib/base.h"
#include "../lib/symbol_table.h"
#include "../lib/scope.h"
#include "../lib/tree.h"


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
        printf(COLOR_RED "Semantic error:" COLOR_RESET " %s\nLine: %d - Column: %d\n", semanticErrors[i]->message, semanticErrors[i]->line, semanticErrors[i]->column);
    }
}

void freeErrors(){
    int i;

    for(i=0; i<semanticErrorsTotal; i++){
        if(semanticErrors[i]->type != NULL){
            free(semanticErrors[i]->type);
        }
        if(semanticErrors[i]->message != NULL){
            free(semanticErrors[i]->message);
        }
        if(semanticErrors[i]->error_text != NULL){
            free(semanticErrors[i]->error_text);
        }

        free(semanticErrors[i]);
    }

    free(semanticErrors);
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

    if(found == 0){
        addError("mainNotFound", "Main function has not been defined", "", -1, -1);
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
    int i, paramNumber, j, correct, typeConvert;
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
    paramNumber = getFunctionCallParameters(node->child[0], -1, &types, node, 0) + 1;

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

    // funcDeclaration = getSymbol(node->functionName);

    funcDeclaration = getSymbolValidScopeFunc(node->functionName);

    if(funcDeclaration != NULL){
        j = paramNumber-1;
        correct = 1;

        #ifdef DEBUG_SEMANTIC
        printf("Function call check - Comparing paramNumber - passed %d (%s), expected %d (%s)\n", paramNumber, node->functionName, funcDeclaration->paramNumber, funcDeclaration->name);
        #endif


        if(paramNumber == funcDeclaration->paramNumber){
            for(i=0; i<paramNumber; i++){
                #ifdef DEBUG_SEMANTIC
                printf("Function call check - Comparing types %s - %s\n", types[j]->type, funcDeclaration->parameters[i]->type);
                #endif

                if(strcmp(types[j]->type, funcDeclaration->parameters[i]->type) != 0){
                    correct = 0;
                    // printf("Wrong parameter type (%s - %s) in call to function %s\n", types[j]->type, funcDeclaration->parameters[i]->type, funcDeclaration->name);

                    typeConvert = checkConversion(types[j]->type, funcDeclaration->parameters[i]->type);

                    if(typeConvert > 0){
                        // pode converter
                        addTypeCastNode(types[j]->fatherNode, types[j]->childIndex, typeConvert);
                    }
                    else{
                        strcpy(temp, "Wrong parameter type in call to function ");
                        strcat(temp, funcDeclaration->name);
                        strcat(temp, ". Expected ");
                        strcat(temp, funcDeclaration->parameters[i]->type);
                        strcat(temp, " - got ");
                        strcat(temp, types[j]->type);
                        addError("paramType", temp, "", types[j]->line, types[j]->column);
                    }

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
        addError("funcNotDeclared", "Identifier used is not a function or was not declared in this scope", "", node->line, node->column);
    }

    // libera a memória usada para o vetor temporário
    for(i=0; i<paramNumber; i++){
        if(types[i] != NULL){
            if(types[i]->type != NULL){
                free(types[i]->type);
            }
            free(types[i]);
        }
    }
    if(types != NULL){
        free(types);
    }

}

int getFunctionCallParameters(t_node* node, int index, t_typeTemp*** types, t_node* fatherNode, int childIndex){
    // int size = 0;
    // child 0 é nó para o próximo parâmetro - se não houver child 1, child 0 é o último tipo
    // child 1 é o parâmetro atual

    #ifdef DEBUG_SEMANTIC
    printf("getFunctionCallParameters - Getting parameters from function call - index: %d, node: %s\n", index, node->name);
    #endif


    // if(node->child != NULL){
    //     if(node->child[0]->child != NULL){
    //         // armazena o tipo do child 1 em algum lugar
    //         // chama a recursão no child 0 que é o nó para o próximo tipo
    //         #ifdef DEBUG_SEMANTIC
    //         printf("getFunctionCallParameters - Node still has more than one child - recursion\n");
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
    //         printf("getFunctionCallParameters - Node only has one child - no recursion\n");
    //         #endif
    //
    //         addTempType(types, node->child[0]->type, index);
    //         index++;
    //     }
    // }

    // if(node->child != NULL){
    //     if(node->child[0]->child != NULL){
    //         // armazena o tipo do child 1 em algum lugar
    //         // chama a recursão no child 0 que é o nó para o próximo tipo
    //         #ifdef DEBUG_SEMANTIC
    //         printf("getFunctionCallParameters - Node still has more than one paramater child - recursion\n");
    //         #endif
    //
    //         *types = addTempType(*types, node->child[1]->type, index, node->child[1]->line, node->child[1]->column);
    //         index++;
    //         index = getFunctionCallParameters(node->child[0], index, types);
    //     }
    //     else{
    //         // armazena o tipo do child 0 em algum lugar
    //         // final da recursão - último parâmetro
    //         #ifdef DEBUG_SEMANTIC
    //         printf("getFunctionCallParameters - Node only has expression childs - no recursion\n");
    //         #endif
    //
    //
    //         *types = addTempType(*types, node->child[1]->type, index, node->child[1]->line, node->child[1]->column);
    //         index++;
    //         *types = addTempType(*types, node->child[0]->type, index, node->child[0]->line, node->child[0]->column);
    //         index++;
    //     }
    // }
    // else{
    //     #ifdef DEBUG_SEMANTIC
    //     printf("getFunctionCallParameters - Node has no childs, check if it's an empty node\n");
    //     #endif
    //
    //     if(node->empty == 0){
    //         // caso de só existir um parâmetro. O nó passado no início da execução não tem filhos e já é o nó que deve ser analisado
    //         *types = addTempType(*types, node->type, index, node->line, node->column);
    //         index++;
    //     }
    //     // caso o nó não tenha filhos e seja vazio, não há nada a fazer. É o nó criado quando a chamada de função não possuía parâmetros
    // }

    if((node->child != NULL) && (strcmp(node->sigla, "paramPass") == 0)){
        if(node->child[0]->child != NULL){
            // armazena o tipo do child 1 em algum lugar
            // chama a recursão no child 0 que é o nó para o próximo tipo
            #ifdef DEBUG_SEMANTIC
            printf("getFunctionCallParameters - Node still has more than one paramater child - recursion\n");
            #endif

            *types = addTempType(*types, node->child[1]->type, index, node->child[1]->line, node->child[1]->column, node, 1);
            index++;
            index = getFunctionCallParameters(node->child[0], index, types, node, 0);
        }
        else{
            // armazena o tipo do child 0 em algum lugar
            // final da recursão - último parâmetro
            #ifdef DEBUG_SEMANTIC
            printf("getFunctionCallParameters - Node only has expression childs - no recursion\n");
            #endif


            *types = addTempType(*types, node->child[1]->type, index, node->child[1]->line, node->child[1]->column, node, 1);
            index++;
            *types = addTempType(*types, node->child[0]->type, index, node->child[0]->line, node->child[0]->column, node, 0);
            index++;
        }
    }
    else{
        #ifdef DEBUG_SEMANTIC
        printf("getFunctionCallParameters - Node has no childs, check if it's an empty node\n");
        #endif

        if(node->empty == 0){
            // caso de só existir um parâmetro. O nó passado no início da execução não tem filhos e já é o nó que deve ser analisado
            *types = addTempType(*types, node->type, index, node->line, node->column, fatherNode, childIndex);
            index++;
        }
        // caso o nó não tenha filhos e seja vazio, não há nada a fazer. É o nó criado quando a chamada de função não possuía parâmetros
    }

    return index;
}

t_typeTemp** addTempType(t_typeTemp** types, char* type, int index, int line, int column, t_node* fatherNode, int childIndex){
    t_typeTemp** temp;

    #ifdef DEBUG_SEMANTIC
    printf("addTempType - Adding temporary type: %s\n", type);
    #endif

    // temp = realloc(types, (size + strlen(type) + 1));
    temp = realloc(types, (sizeof(t_typeTemp*) * (index+2)));
    // index + 2 compensa pela posição do índice que começa em 0 (+1) e pelo fato de estar adicionado mais um elemento (+1)
    // então index+2 representa o número de elementos atuais +1 que será adicionado agora


    if(temp != NULL){
        types = temp;

        #ifdef DEBUG_SEMANTIC
        printf("addTempType - Allocated memory for temporary array of types: %d bytes\n", (sizeof(t_typeTemp*) * (index+2)));
        #endif

        index++;
        // types[index] = malloc(strlen(type) + 1);
        // types[index] = malloc((strlen(type) + 1) + (sizeof(int) * 2));
        types[index] = malloc(sizeof(t_typeTemp));
        types[index]->type = malloc(strlen(type) + 1);

        #ifdef DEBUG_SEMANTIC
        printf("addTempType - Allocated memory for temporary type: %s - index: %d - bytes: %d, bytes for type: %d\n", type, index, (sizeof(t_typeTemp)), (strlen(type) + 1));
        #endif

        if(type != NULL){
            strcpy(types[index]->type, type);
        }
        else{
            strcpy(types[index]->type, "NULL");
        }
        types[index]->line = line;
        types[index]->column = column;
        // size = size + strlen(type) + 1;
        types[index]->fatherNode = fatherNode;
        types[index]->childIndex = childIndex;

        #ifdef DEBUG_SEMANTIC
        printf("addTempType - Copied temporary type: %s - index: %d\n", type, index);
        #endif
    }
    else{
        printf("Error when allocating memory for temporary type array in function call checking\n");
    }

    #ifdef DEBUG_SEMANTIC
    printf("addTempType - Added temporary type: %s - fatherNode name: %s - childIndex: %d\n", types[index]->type, types[index]->fatherNode->name, types[index]->childIndex);
    #endif

    return types;
}


void checkIdDeclaration(t_node* node){
    t_symbol* symbol;
    int found = 0;
    char temp[300];

    // for(pointer = SymbolTable; pointer != NULL; pointer = pointer->next){
    //     if(strcmp(node->id, pointer->name) == 0){
    //         // achou o símbolo na tabela
    //         // não procura o símbolo no escopo mais próximo (que é o que seria usado)
    //         // procura apenas se existe um símbolo com esse nome em um escopo válido
    //         // (escopo atual ou algum escopo pai, ou seja, algum escopo atualmente na pilha)
    //         if(findInScopeStack(pointer->scopeValue) == 1){
    //             found++;
    //             break;
    //         }
    //     }
    // }

    // printf("______Verificando ID\n");

    symbol = getSymbolValidScope(node->id);

    if(symbol == NULL){
        // printf("Uso de uma variável ou função não declarada - %s\n", node->id);

        strcpy(temp, "Variable or function ");
        strcat(temp, node->id);
        strcat(temp, " undeclared in this scope.");

        addError("undeclaredId", temp, "", node->line, node->column);
    }
    // else{
    //     // else para testes, no final só é preciso imprimir quando ocorrer erro
    //     // printf("Uso de uma variável ou função declarada corretamente - %s\n", node->id);
    //     NULL;
    // }
}


int checkConversion(char* type1, char* type2){
    int result;
    // tipo 1 é a base, tipo 2 é para qual está sendo checado se ele pode ser convertido

    if(strcmp(type1, type2) == 0){
        // dois tipos iguais, não deveria checar se é possível converter pois não é preciso converter
        result = -1;
    }
    else if((strcmp(type1, "int") == 0) && (strcmp(type2, "float") == 0)){
        // tipo1 é int e tipo2 é float, pode converter
        // conversão int para float
        result = CAST_INT_FLOAT;
    }
    else if((strcmp(type1, "float") == 0) && (strcmp(type2, "int") == 0)){
        result = CAST_FLOAT_INT;
    }
    else{
        result = 0;
    }

    return result;
}


void addOperandError(int line, int column){
    addError("operandType", "Invalid operand type", "", line, column);
}


int verifyListFunction(t_node* node){
    t_symbol* symbol = NULL;
    int result = 1;

    if(node->id != NULL){
        symbol = getSymbolValidScopeFunc(node->id);
    }

    if(symbol != NULL){
        // a função existe
        if(symbol->paramNumber == 1){
            // a função só possui um parâmetro (unária)
            if((strcmp(symbol->parameters[0]->type, "int") == 0) || (strcmp(symbol->parameters[0]->type, "float") == 0)){
                // o parâmetro é do tipo int ou float, como deve ser
                // atribuindo valor 2 para o retorno quando for int e 3 quando for float - utilizado para inserir nós de conversão de tipo caso necessário
                if(strcmp(symbol->parameters[0]->type, "int") == 0){
                    result = 2;
                }
                else{
                    result = 3;
                }
            }
            else{
                result = 0;
                addError("operandType", "Invalid operand - Function must have a parameter with type int or float", "", node->line, node->column);
            }

            if((strcmp(symbol->type, "int") == 0) || (strcmp(symbol->type, "float") == 0)){
                // a função possui um retorno int ou float (unário), como deve ser
                NULL;
            }
            else{
                if(result < 2){
                    result = 0;
                }
                addError("operandType", "Invalid operand - Function must have type int or float", "", node->line, node->column);
            }
        }
        else{
            result = 0;
            addError("operandType", "Invalid operand - Expecting unary function, got function with multiple or zero parameters", "", node->line, node->column);
        }
    }
    else{
        result = 0;
        addError("operandType", "Invalid operand - Function not declared in this scope or not a function", "", node->line, node->column);
    }

    return result;
}


void verifyOperands(t_node* node){
    int aux;
    t_symbol* tempSymbol;
    // verifica os tipos dos operandos
    // adição e multiplicação - FEITO
    // exclamação - FEITO
    // map e filter - FEITO
    // header - FEITO
    // tail destructor - FEITO
    // relacionais (binárias) - FEITO
    // lógicas - FEITO
    // atribuição (assignment) - FEITO

    // operações de adição ou multiplicação
    if((strcmp(node->sigla, "sumExp") == 0) || (strcmp(node->sigla, "mulExp") == 0)){
        if((strcmp(node->child[0]->type, "int") != 0) && (strcmp(node->child[0]->type, "float") != 0)){
            // em uma adição ou multiplicação, o operando esquerdo precisa ser int ou float, nenhum outro é aceito
            // se for outro tipo (list por exemplo) gera um erro
            if((strcmp(node->child[0]->type, "Error") != 0)){
                // addError("operandType", "Tipo de operando inválido", "", node->child[0]->line, node->child[0]->column);
                // addOperandError(node->child[0]->line, node->child[0]->column);
                addError("operandType", "Invalid operand - Expecting operand of type int or float", "", node->child[0]->line, node->child[0]->column);
            }
            addNodeType(node, "Error");
        }
        if((strcmp(node->child[2]->type, "int") != 0) && (strcmp(node->child[2]->type, "float") != 0)){
            // em uma adição ou multiplicação, o operando direito precisa ser int ou float, nenhum outro é aceito
            // se for outro tipo (list por exemplo) gera um erro
            if((strcmp(node->child[2]->type, "Error") != 0)){
                // addError("operandType", "Tipo de operando inválido", "", node->child[2]->line, node->child[2]->column);
                // addOperandError(node->child[2]->line, node->child[2]->column);
                addError("operandType", "Invalid operand - Expecting operand of type int or float", "", node->child[2]->line, node->child[2]->column);
            }
            addNodeType(node, "Error");
        }
    }

    // exclamação - pode ser operação de lista ou operação lógica - é decidido aqui qual é o tipo
    if(strcmp(node->sigla, "exclaExp") == 0){
        // operação de lista
        if((strcmp(node->child[0]->type, "int list") == 0) || (strcmp(node->child[0]->type, "float list") == 0)){
            overrideNode(node, COLOR_CYAN "List Tail" COLOR_RESET, "listTail");
        }
        else if((strcmp(node->child[0]->type, "nil") == 0)){
            // operação de lista mas em uma constante null - comportamento indefinido - erro
            // addOperandError(node->child[0]->line, node->child[0]->column);
            overrideNode(node, COLOR_CYAN "List Tail" COLOR_RESET, "listTail");
            addNodeType(node, "Error");
            addError("operandType", "Invalid operand - Expecting operand of type list (int list or float list)", "", node->child[0]->line, node->child[0]->column);
        }
        // operação lógica - só pode ser aplicada em inteiro ou deveria poder receber float também? (e ser convertido para inteiro)
        else if((strcmp(node->child[0]->type, "int") == 0)){
            NULL;
        }
        // erro, operando incorreto para o operador de exclamação
        else{
            // addError("operandType", "Tipo de operando inválido", "", node->child[0]->line, node->child[0]->column);
            // addOperandError(node->child[0]->line, node->child[0]->column);
            addError("operandType", "Invalid operand - Expecting operand of type int", "", node->child[0]->line, node->child[0]->column);
        }
    }

    // list header
    if(strcmp(node->sigla, "listHeader") == 0){
        if((strcmp(node->child[0]->type, "int list") == 0) || (strcmp(node->child[0]->type, "float list") == 0)){
            // operando é int list ou float list
            NULL;
        }
        else{
            // addError("operandType", "Tipo de operando inválido", "", node->child[0]->line, node->child[0]->column);
            // addOperandError(node->child[0]->line, node->child[0]->column);
            addError("operandType", "Invalid operand - Expecting operand of type list (int list or float list)", "", node->child[0]->line, node->child[0]->column);
            addNodeType(node, "Error");
        }
    }

    // tail destructor
    if(strcmp(node->sigla, "listTailDest") == 0){
        if((strcmp(node->child[0]->type, "int list") == 0) || strcmp(node->child[0]->type, "float list") == 0){
            // operando é int list ou float list
            NULL;
        }
        else{
            // addOperandError(node->child[0]->line, node->child[0]->column);
            addError("operandType", "Invalid operand - Expecting operand of type list (int list or float list)", "", node->child[0]->line, node->child[0]->column);
            addNodeType(node, "Error");
        }
    }

    // map e filter
    if((strcmp(node->sigla, "listMap") == 0) || (strcmp(node->sigla, "listFilter") == 0)){

        aux = verifyListFunction(node->child[0]);

        if((strcmp(node->child[1]->type, "int list") == 0) || (strcmp(node->child[1]->type, "float list") == 0) || (strcmp(node->child[1]->type, "nil") == 0)){
            // segundo parâmetro está correto
            if((aux == 2) && (strcmp(node->child[1]->type, "float list") == 0)){
                // parâmetro é do tipo float list e a função esperava int, precisa inserir nó de conversão floatToInt
                addTypeCastNode(node, 1, CAST_FLOAT_INT);
            }
            else if((aux == 3) && (strcmp(node->child[1]->type, "int list") == 0)){
                // parâmetro é do tipo int list e a função esperava float, precisa inserir nó de conversão intToFloat
                addTypeCastNode(node, 1, CAST_INT_FLOAT);
            }
            else if((strcmp(node->child[1]->type, "nil") == 0)){
                // segundo parâmetro é do tipo nil - lista vazia
                if(aux == 2){
                    // esperava o tipo int
                    addTypeCastNode(node, 1, CAST_NIL_INTLIST);
                }
                else if(aux == 3){
                    // esperava o tipo float
                    addTypeCastNode(node, 1, CAST_NIL_FLOATLIST);
                }

                if((strcmp(node->sigla, "listFilter") == 0)){
                    addNodeType(node, node->child[1]->type);
                }
            }

        }
        else{
            addError("operandType", "Invalid operand - Expecting operand of type list (int list or float list)", "", node->child[1]->line, node->child[1]->column);
        }
    }

    // lógicas - binárias (lógica unária já foi tratada acima - exclaExp)
    if(strcmp(node->sigla, "logicBin") == 0){
        if((strcmp(node->child[0]->type, "int") == 0) && (strcmp(node->child[1]->type, "int") == 0)){
            // dois argumentos precisam ser inteiros -  a não ser que seja permitido ter um float e ele ser convertido para inteiro
            NULL;
        }
        else{
            // addError("operandType", "Tipo de operando inválido", "", node->child[0]->line, node->child[0]->column);
            // addOperandError(node->child[0]->line, node->child[0]->column);
            if((strcmp(node->child[0]->type, "int") != 0)){
                addError("operandType", "Invalid operand - Expecting operand of type int", "", node->child[0]->line, node->child[0]->column);
            }
            if((strcmp(node->child[1]->type, "int") != 0)){
                addError("operandType", "Invalid operand - Expecting operand of type int", "", node->child[1]->line, node->child[1]->column);
            }
            // addNodeType(node, "Error");
        }
    }

    // relacionais (ou binárias)
    if(strcmp(node->sigla, "binExp") == 0){
        if(
            ((strcmp(node->child[0]->type, "int") == 0) || (strcmp(node->child[0]->type, "float") == 0)) &&
            ((strcmp(node->child[1]->type, "int") == 0) || (strcmp(node->child[1]->type, "float") == 0))
        ){
            // argumentos podem ser inteiros ou floats - é preciso converter caso sejam diferentes? provável, para que possam ser comparados
            if((strcmp(node->child[0]->type, "int") == 0) && (strcmp(node->child[1]->type, "float") == 0)){
                // lado esquerdo é int e direito é float, converter esquerdo de int para float
                addTypeCastNode(node, 0, CAST_INT_FLOAT);
            }
            else if((strcmp(node->child[0]->type, "float") == 0) && (strcmp(node->child[1]->type, "int") == 0)){
                // lado esquerdo é float e direito é int, converter direito de int para float
                addTypeCastNode(node, 1, CAST_INT_FLOAT);
            }
        }
        else{
            // addError("operandType", "Tipo de operando inválido", "", node->child[0]->line, node->child[0]->column);
            // addOperandError(node->child[0]->line, node->child[0]->column);
            addError("operandType", "Invalid operand - Expecting operands of type int or float", "", node->child[0]->line, node->child[0]->column);
            // addNodeType(node, "Error");
        }
    }

    // atribuição - assignment
    if(strcmp(node->sigla, "assignOp") == 0){
        tempSymbol = getSymbolValidScopeVar(node->id);

        if(tempSymbol != NULL){
            addNodeSymbol(node, tempSymbol);

            if((strcmp(tempSymbol->type, "int") == 0) || (strcmp(tempSymbol->type, "float") == 0)){
                // lado esquerdo é um tipo simples
                // pode haver conversão do lado direito
                if((strcmp(node->child[0]->type, "int") == 0) || (strcmp(node->child[0]->type, "float") == 0)){
                    // lado direito é um tipo simples. Só precisa verificar se precisa de conversão. Se não precisar, tudo certo, não existem erros
                    if((strcmp(tempSymbol->type, "int") == 0) && (strcmp(node->child[0]->type, "float") == 0)){
                        // conversão de float para int do lado direito
                        addTypeCastNode(node, 0, CAST_FLOAT_INT);
                    }
                    else if((strcmp(tempSymbol->type, "float") == 0) && (strcmp(node->child[0]->type, "int") == 0)){
                        // conversão de int para float do lado direito
                        addTypeCastNode(node, 0, CAST_INT_FLOAT);
                    }
                }
                else if((strcmp(node->child[0]->type, "Error") != 0)){
                    // erro, se lado esquerdo é um tipo simples, lado direito também precisa ser
                    // addOperandError(node->child[0]->line, node->child[0]->column);
                    addError("operandType", "Invalid operand - Expecting operand of type int or float", "", node->child[0]->line, node->child[0]->column);
                }
            }
            else{
                // lado esquerdo não é um tipo simples - verificar a semântica de atribuição de lista aqui
                if((strcmp(node->child[0]->type, "int list") == 0) || (strcmp(node->child[0]->type, "float list") == 0)){
                    // lado direito é uma lista - correto
                    NULL;
                }
                else if(strcmp(node->child[0]->type, "nil") == 0){
                    // lado direito é a constante null - correto, trocar o tipo do null para o tipo da lista do elemento esquerdo
                    // addNodeType(node->child[0], tempSymbol->type);
                    if((strcmp(tempSymbol->type, "int list") == 0)){
                        addTypeCastNode(node, 0, CAST_NIL_INTLIST);
                    }
                    else if((strcmp(tempSymbol->type, "float list") == 0)){
                        addTypeCastNode(node, 0, CAST_NIL_FLOATLIST);
                    }
                }
                else{
                    // esperava uma lista do lado direito mas obteve outro tipo - provavelmente um tipo simples pois foi o único que restou
                    // addOperandError(node->child[0]->line, node->child[0]->column);
                    addError("operandType", "Invalid operand - Expecting operand of type list (int list or float list)", "", node->child[0]->line, node->child[0]->column);
                }
            }
        }
        else{
            // símbolo é nulo, não foi declarado ou não é uma variável.
            // addOperandError(node->line, node->column);
            addError("operandType", "Invalid operand - Variable was not declared in this scope or is not a variable", "", node->line, node->column);
            // verificação de erro já ocorrendo por meio da checkIdDeclaration - decidir onde será mantido
        }
    }

    // write ou writeln com expressão
    if((strcmp(node->sigla, "writeExp") == 0) || (strcmp(node->sigla, "writelnExp") == 0)) {
        // tipo precisa ser  um tipo básico
        if((strcmp(node->child[0]->type, "int") == 0) || (strcmp(node->child[0]->type, "float") == 0)){
            // expressão passada é de um tipo básico
            NULL;
        }
        else{
            // não foi passado um tipo básico
            // addOperandError(node->child[0]->line, node->child[0]->column);
            addError("operandType", "Invalid operand - Expecting operand of type int or float", "", node->child[0]->line, node->child[0]->column);
        }
    }


    // read
    if(strcmp(node->sigla, "readOp") == 0){
        tempSymbol = getSymbolValidScopeVar(node->id);

        if(tempSymbol != NULL){
            addNodeSymbol(node, tempSymbol);

            if((strcmp(tempSymbol->type, "int") == 0) || (strcmp(tempSymbol->type, "float") == 0)){
                // variável é de um tipo simples
                NULL;
            }
            else{
                // variável não é de tipo simples, erro
                // addOperandError(node->line, node->column);
                addError("operandType", "Invalid operand - Expecting operand of type int or float", "", node->line, node->column);
            }
        }
        else{
            // variável não encontrada em um escopo válido
            // addOperandError(node->line, node->column);
            addError("operandType", "Invalid operand - Variable was not declared in this scope or is not a variable", "", node->line, node->column);
        }
    }

    // return
    if(strcmp(node->sigla, "return") == 0){
        tempSymbol = getSymbolValidScopeFunc(node->functionName);

        #ifdef DEBUG_SEMANTIC
        printf("verifyOperands - Checking return - symbol type: %s, child type: %s\n", tempSymbol->type, node->child[0]->type);
        #endif

        if(tempSymbol != NULL){
            // encontrou a função - em teoria é para sempre entrar aqui, pois o sintático está preenchendo essa parte corretamente
            if(strcmp(tempSymbol->type, node->child[0]->type) == 0){
                // tipo de retorno e da expressão do return são iguais - nada precisa ser feito, nenhum erro
                NULL;
            }
            else if((strcmp(tempSymbol->type, "int") == 0) && (strcmp(node->child[0]->type, "float") == 0)){
                // converter a expressão no return de float para int
                addTypeCastNode(node, 0, CAST_FLOAT_INT);
            }
            else if((strcmp(tempSymbol->type, "float") == 0) && (strcmp(node->child[0]->type, "int") == 0)){
                // converter a expressão no return de int para float
                addTypeCastNode(node, 0, CAST_INT_FLOAT);
            }
            else{
                // erro
                // tipos incompatíveis entre o retorno da função e o operando do return, sem possibilidade de conversão
                // addOperandError(node->child[0]->line, node->child[0]->column);
                addError("operandType", "Invalid operand - Type mismatch between returned value and function return type", "", node->child[0]->line, node->child[0]->column);
            }
        }
        else{
            // printf("Erro ao pegar a função a qual o return está associado - provavelmente erro no sintático\n");
            // função não encontrada, provavelmente erro no sintático. Um return deveria estar dentro de uma função que deveria ter sido encontrada aqui
            NULL;
        }
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
    freeErrors();

}
