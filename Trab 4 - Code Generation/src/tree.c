#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/tree.h"
#include "../lib/base.h"
#include "../lib/symbol_table.h"
#include "../lib/scope.h"
#include "../lib/semantic.h"



t_node* TreeRoot = NULL;
int nodesBuilt;
char* lastFuncDeclared = NULL;

t_node* createNode(char* name, char* sigla){
    t_node* node;

    #ifdef DEBUG_TREE
    printf("Node creation - memory needed for %s: %d\n", name, strlen(name));
    #endif

    node = (t_node*) malloc(sizeof(t_node));

    node->name = (char*) malloc(strlen(name) + 1);
    node->sigla = (char*) malloc(strlen(sigla) + 1);
    node->empty = 0;
    node->type = NULL;
    node->functionName = NULL;
    node->line = -1;
    node->column = -1;
    node->id = NULL;
    node->value = NULL;
    node->symbol = NULL;
    node->assignedTemporary = -2;
    node->label = NULL;
    node->labelJump = NULL;

    #ifdef DEBUG_TREE
    printf("Node creation - allocated memory\n");
    #endif

    strcpy(node->name, name);
    strcpy(node->sigla, sigla);

    #ifdef DEBUG_TREE
    printf("Node creation - copied name\n");
    #endif

    node->child = NULL;

    return node;
}


void overrideNode(t_node* node, char* name, char* sigla){
    char* temp;
    char *tempsigla;

    #ifdef DEBUG_TREE
    printf("overrideNode - overriding node\n");
    #endif

    temp = malloc(strlen(name) + 1);
    tempsigla = malloc(strlen(sigla) + 1);

    #ifdef DEBUG_TREE
    printf("overrideNode - allocated memory\n");
    #endif

    if(temp != NULL && tempsigla != NULL){
        strcpy(temp, name);
        strcpy(tempsigla, sigla);
        free(node->name);
        free(node->sigla);
        node->name = temp;
        node->sigla = tempsigla;
        #ifdef DEBUG_TREE
        printf("overrideNode - replaced name and sigla\n");
        #endif
    }
    else{
        printf("Fatal error when reallocating memory for node override\n");
    }
}


t_node* createEmptyNode(){
    t_node* node;

    #ifdef DEBUG_TREE
    printf("Node creation - empty node\n");
    #endif

    node = (t_node*) malloc(sizeof(t_node));

    node->name = (char*) malloc(3);
    node->sigla = malloc(strlen("empty") + 1);
    node->empty = 1;
    node->type = NULL;
    node->functionName = NULL;
    node->line = -1;
    node->column = -1;
    node->id = NULL;

    #ifdef DEBUG_TREE
    printf("Node creation - allocated memory\n");
    #endif

    strcpy(node->name, " ");
    strcpy(node->sigla, "empty");

    #ifdef DEBUG_TREE
    printf("Node creation - copied name\n");
    #endif

    node->child = NULL;

    return node;
}


void addNodeType(t_node* node, char* type){
    node->type = malloc(strlen(type) + 1);
    strcpy(node->type, type);
}


void addNodeTypeChildren(t_node* node){
    int childNumber=0;
    char tempType[15];

    #ifdef DEBUG_TREE
    printf("addNodeTypeChildren - Adding type to node %s\n", node->name);
    #endif

    while(node->child[childNumber] != NULL){
        childNumber++;
    }

    strcpy(tempType, "temp");

    #ifdef DEBUG_TREE
    printf("addNodeTypeChildren - Has %d children\n", childNumber);
    #endif

    // if(childNumber == 3){
    //
    //     #ifdef DEBUG_TREE
    //     printf("addNodeTypeChildren - 3 children - Child left: %s / type: %s - child right: %s / type: %s\n", node->child[0]->name, node->child[0]->type, node->child[2]->name, node->child[2]->type);
    //     #endif
    //
    //     if(node->child[0]->type == NULL){
    //         if(strcmp(node->child[0]->sigla, "id") == 0){
    //             addNodeTypeId(node->child[0], node->child[0]->id);
    //         }
    //     }
    //
    //     if(node->child[2]->type == NULL){
    //         if(strcmp(node->child[2]->sigla, "id") == 0){
    //             addNodeTypeId(node->child[2], node->child[2]->id);
    //         }
    //     }
    //
    //     if( (strcmp(node->child[0]->type, "int") == 0) && (strcmp(node->child[2]->type, "int") == 0) ){
    //         // dois lados da expressão são inteiros
    //         strcpy(tempType, "int");
    //     }
    //     else if((strcmp(node->child[0]->type, "float") == 0) || (strcmp(node->child[2]->type, "float") == 0)){
    //         // um dos lados da expressão é float
    //         strcpy(tempType, "float");
    //     }
    // }


    if(childNumber == 3){
        // 3 filhos são nós de adição ou multiplicação. Em teoria, apenas esses.
        #ifdef DEBUG_TREE
        printf("addNodeTypeChildren - 3 children - Child left: %s / type: %s - child right: %s / type: %s\n", node->child[0]->name, node->child[0]->type, node->child[2]->name, node->child[2]->type);
        #endif

        if(node->child[0]->type == NULL){
            if(strcmp(node->child[0]->sigla, "id") == 0){
                addNodeTypeId(node->child[0], node->child[0]->id);
            }
            // else{
            //     addNodeType(node->child[0], "tempType");
            // }
        }

        if(node->child[2]->type == NULL){
            if(strcmp(node->child[2]->sigla, "id") == 0){
                addNodeTypeId(node->child[2], node->child[2]->id);
            }
            // else{
            //     addNodeType(node->child[2], "tempType");
            // }
        }

        if( (strcmp(node->child[0]->type, "int") == 0) && (strcmp(node->child[2]->type, "int") == 0) ){
            // dois lados da expressão são inteiros
            strcpy(tempType, "int");
        }
        else if((strcmp(node->child[0]->type, "float") == 0) && (strcmp(node->child[2]->type, "int") == 0)){
            // lado esquerdo da expressão é float e o direito é inteiro
            strcpy(tempType, "float");
            addTypeCastNode(node, 2, CAST_INT_FLOAT);
        }
        else if((strcmp(node->child[0]->type, "int") == 0) && (strcmp(node->child[2]->type, "float") == 0)){
            // lado direito da expressão é float e o esquerdo é inteiro
            strcpy(tempType, "float");
            addTypeCastNode(node, 0, CAST_INT_FLOAT);
        }
        else if((strcmp(node->child[0]->type, "float") == 0) && (strcmp(node->child[2]->type, "float") == 0)){
            // os dois lados da expressão são float
            strcpy(tempType, "float");
        }
        // else {
        //     if((strcmp(node->child[0]->type, "int") != 0) && (strcmp(node->child[0]->type, "float") != 0)){
        //         // em uma adição ou multiplicação, o operando esquerdo precisa ser int ou float, nenhum outro é aceito
        //         // se for outro tipo (list por exemplo) gera um erro
        //         if((strcmp(node->child[0]->type, "Error") != 0)){
        //             addError("operandType", "Tipo de operando inválido", "", node->child[0]->line, node->child[0]->column);
        //         }
        //         strcpy(tempType, "Error");
        //     }
        //     if((strcmp(node->child[2]->type, "int") != 0) && (strcmp(node->child[2]->type, "float") != 0)){
        //         // em uma adição ou multiplicação, o operando direito precisa ser int ou float, nenhum outro é aceito
        //         // se for outro tipo (list por exemplo) gera um erro
        //         if((strcmp(node->child[2]->type, "Error") != 0)){
        //             addError("operandType", "Tipo de operando inválido", "", node->child[2]->line, node->child[2]->column);
        //         }
        //         strcpy(tempType, "Error");
        //     }
        // }

    }
    else if(childNumber == 1){
        #ifdef DEBUG_TREE
        printf("addNodeTypeChildren - 1 children - Child: %s / type: %s \n", node->child[0]->name, node->child[0]->type);
        #endif

        if(strcmp(node->sigla, "listHeader") == 0){
            if(strcmp(node->child[0]->type, "int list") == 0){
                strcpy(tempType, "int");
            }
            else if(strcmp(node->child[0]->type, "float list") == 0){
                strcpy(tempType, "float");
            }
        }
        else if((strcmp(node->sigla, "listTailDest") == 0)){
            if(strcmp(node->child[0]->type, "int list") == 0){
                strcpy(tempType, "int list");
            }
            else if(strcmp(node->child[0]->type, "float list") == 0){
                strcpy(tempType, "float list");
            }
        }
        else if((strcmp(node->sigla, "exclaExp") == 0)){
            if(strcmp(node->child[0]->type, "int list") == 0){
                strcpy(tempType, "int list");
            }
            else if(strcmp(node->child[0]->type, "float list") == 0){
                strcpy(tempType, "float list");
            }
            else{
                strcpy(tempType, "int");
            }
        }

        // if((strcmp(node->child[0]->type, "int") == 0) || (strcmp(node->child[0]->type, "int list") == 0)){
        //     strcpy(tempType, "int");
        // }
        // else if((strcmp(node->child[0]->type, "float") == 0) || (strcmp(node->child[0]->type, "float list") == 0)){
        //     strcpy(tempType, "float");
        // }
    }
    else if(childNumber == 2){
        #ifdef DEBUG_TREE
        printf("addNodeTypeChildren - 2 children - Child left: %s / type: %s - child right: %s / type: %s\n", node->child[0]->name, node->child[0]->type, node->child[1]->name, node->child[1]->type);
        #endif

        if(strcmp(node->sigla, "listFilter") == 0){
            strcpy(tempType, node->child[1]->type);
        }
        else if(strcmp(node->sigla, "listMap") == 0){
            strcpy(tempType, node->child[0]->type);
            strcat(tempType, " list");
        }
        else if(strcmp(node->sigla, "listAssign") == 0){
            // addNodeTypeListAssign(node);

            #ifdef DEBUG_TREE
            printf("addNodeTypeChildren - checking list assign type - child 1: %s - child 2: %s\n", node->child[0]->type, node->child[1]->type);
            #endif

            if(strcmp(node->child[1]->type, "nil") == 0){
                if((strcmp(node->child[0]->type, "int") == 0)){
                    // addNodeType(node, "int list");
                    strcpy(tempType, "int list");
                    addTypeCastNode(node, 1, CAST_NIL_INTLIST);
                }
                else if((strcmp(node->child[0]->type, "float") == 0)){
                    // addNodeType(node, "float list");
                    strcpy(tempType, "float list");
                    addTypeCastNode(node, 1, CAST_NIL_FLOATLIST);
                }
                else{
                    // addNodeType(node, "Error");
                    strcpy(tempType, "Error");
                }
            }
            else{
                if((strcmp(node->child[0]->type, "float") == 0) && ((strcmp(node->child[1]->type, "int") == 0) || (strcmp(node->child[1]->type, "int list") == 0))){
                    addTypeCastNode(node, 0, CAST_FLOAT_INT);
                    strcpy(tempType, node->child[1]->type);
                }
                else if((strcmp(node->child[0]->type, "int") == 0) && ((strcmp(node->child[1]->type, "float") == 0) || (strcmp(node->child[1]->type, "float list") == 0))){
                    addTypeCastNode(node, 0, CAST_INT_FLOAT);
                    strcpy(tempType, node->child[1]->type);
                }
                else if(
                    ((strcmp(node->child[0]->type, "int") == 0) && ((strcmp(node->child[1]->type, "int") == 0) || (strcmp(node->child[1]->type, "int list") == 0)))
                    || ((strcmp(node->child[0]->type, "float") == 0) && ((strcmp(node->child[1]->type, "float") == 0) || (strcmp(node->child[1]->type, "float list") == 0)))
                ){
                    strcpy(tempType, node->child[1]->type);
                }
                else{
                    strcpy(tempType, "Error");
                }

                // addNodeType(node, node->child[1]->type);
                // strcpy(tempType, node->child[1]->type);
            }

            addNodePosition(node, node->child[1]->line, node->child[1]->column);

            // else if((strcmp(node->child[0]->type, "int") == 0) && ((strcmp(node->child[1]->type, "int") == 0) || (strcmp(node->child[1]->type, "int list") == 0))){
            //     // parâmetro esquerdo é int e direito é int ou int list
            //     // if(strcmp(node->child[1]->type, "int list") == 0){
            //     //     // parâmetro direito é int list
            //     //     addNodeType(node, "int list");
            //     // }
            //     // else{
            //     //     // parâmetro direito é int
            //     //
            //     // }
            //     addNodeType(node, node->child[1]->type);
            // }
            // else if((strcmp(node->child[0]->type, "float") == 0) && ((strcmp(node->child[1]->type, "int") == 0) || (strcmp(node->child[1]->type, "int list") == 0))){
            //
            // }
        }

    }

    // node->type = malloc(strlen(tempType) + 1);
    // strcpy(node->type, tempType);

    #ifdef DEBUG_TREE
    printf("addNodeTypeChildren - Type added: %s\n", tempType);
    #endif

    addNodeType(node, tempType);
}


void addNodeTypeId(t_node* node, char* id){
    t_symbol* symbol = NULL;
    // t_scope* scopePointer = NULL;
    // int found = 0;

    // symbol = getSymbol(id);
    //
    // if(symbol != NULL){
    //     addNodeType(node, symbol->type);
    // }
    // else{
    //     printf("Error when adding type from id to node - probably undeclared id\n");
    // }


    // roda a pilha de escopo. Quanto mais no topo da pilha, mais próximo é o escopo e maior a prioridade
    // for(scopePointer = topScope; scopePointer != NULL; scopePointer = scopePointer->next){
    //     symbol = getSymbolWithScope(id, scopePointer->scopeValue);
    //
    //     if(symbol != NULL){
    //         found = 1;
    //         break;
    //     }
    // }

    symbol = getSymbolValidScope(id);

    // symbol = getSymbol(id);

    if(symbol != NULL){
        addNodeType(node, symbol->type);
        addNodeSymbol(node, symbol);
    }
    else{
        // printf("Error when adding type from id to node - probably undeclared id\n");
        addNodeType(node, "null");
    }
}


void addTypeCastNode(t_node* node, int child, int castType){
    char tempName[400];
    char tempSigla[200];
    char tempType[50];
    t_node* newNode;
    // 1 - int to float
    // 2 - float to int
    // 3 - nil to int list
    // 4 - nil to float list

    if(castType == CAST_INT_FLOAT){
        strcpy(tempName, COLOR_B_YELLOW "Type Cast - Int to float" COLOR_RESET);
        strcpy(tempSigla, "CastIntToFloat");
        strcpy(tempType, "float");
    }
    else if(castType == CAST_FLOAT_INT){
        strcpy(tempName, COLOR_B_YELLOW "Type Cast - Float to int" COLOR_RESET);
        strcpy(tempSigla, "CastFloatToInt");
        strcpy(tempType, "int");
    }
    else if(castType == CAST_NIL_INTLIST){
        strcpy(tempName, COLOR_B_YELLOW "Type Cast - Nil to int list" COLOR_RESET);
        strcpy(tempSigla, "CastNilToIntList");
        strcpy(tempType, "int list");
    }
    else if(castType == CAST_NIL_FLOATLIST){
        strcpy(tempName, COLOR_B_YELLOW "Type Cast - Nil to float list" COLOR_RESET);
        strcpy(tempSigla, "CastNilToFloatList");
        strcpy(tempType, "float list");
    }
    else{
        printf("Undefined type cast\n");
    }

    newNode = createNode(tempName, tempSigla);

    addNodeType(newNode, tempType);

    addChild(newNode, 1);
    newNode->child[0] = node->child[child];

    node->child[child] = newNode;

}


void addFunctionName(t_node* node, char* function){
    node->functionName = malloc(strlen(function) + 1);
    strcpy(node->functionName, function);
}

void updateLastFunc(char* name){
    if(lastFuncDeclared != NULL){
        free(lastFuncDeclared);
    }
    lastFuncDeclared = malloc(strlen(name) + 1);
    strcpy(lastFuncDeclared, name);
}


void addNodePosition(t_node* node, int line, int column){
    node->line = line;
    node->column = column;
}


void addNodeId(t_node* node, char* id){
    node->id = malloc(strlen(id) + 1);
    strcpy(node->id, id);
}


void addNodeSymbol(t_node* node, t_symbol* symbol){
    node->symbol = symbol;
}


void addNodeValue(t_node* node, char* value){
    node->value = malloc(strlen(value) + 1);
    strcpy(node->value, value);
}


// void addNodeOperator(t_node* node, char* logicOperator){
//     node->operator = malloc(strlen(logicOperator) + 1);
//     strcpy(node->logicOperator, logicOperator);
// }


void addNodeTemporary(t_node* node, int temporary){
    node->assignedTemporary = temporary;
}

void addNodeLabel(t_node* node, char* label){
    node->label = malloc(strlen(label) + 1);
    strcpy(node->label, label);
}

void addNodeLabelJump(t_node* node, char* labelJump){
    node->labelJump = malloc(strlen(labelJump) + 1);
    strcpy(node->labelJump, labelJump);
}

void addNodeLabelJumpTrue(t_node* node, char* labelJumpTrue){
    node->labelJumpTrue = malloc(strlen(labelJumpTrue) + 1);
    strcpy(node->labelJumpTrue, labelJumpTrue);
}


void initializeTree(t_node* node){

    TreeRoot = node;

    #ifdef DEBUG_TREE
    printf("Tree initialized\n");
    #endif
}

void addChild(t_node* node, int n){
    t_node** temp;
    // t_node** temp_old;

    temp = (t_node**) realloc(node->child, (sizeof(t_node*) * (n + 1)));

    if(temp != NULL){
        // temp_old = node->child;
        node->child = temp;

        // aloca um filho a mais e seta ele para nulo, para saber quando acabaram os filhos
        node->child[n] = NULL;

        // limpa antiga área de memória
        // if(temp != NULL){
        //     free(temp_old);
        // }
    }
    else{
        printf("Fatal error on memory allocation for child nodes\n");
    }
}



void printTree(){

    #ifdef DEBUG_TREE
    printf("Printing tree\n");
    nodesBuilt = 0;
    #endif

    printf(                 "┌────────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf(                 "│------------------------------------------------SYNTAX TREE-------------------------------------------------│\n");
    printf(                 "│                                                                                                            │\n");
    printf(                 "│        ┌───────────────────────────────────────────┐                                                       │\n");
    printf(                 "│        │-------------------Codes-------------------│                                                       │\n");
    printf("│" COLOR_GREEN  "        │-█ Declarations-                           │                                                       " COLOR_RESET "│\n" );
    printf("│" COLOR_YELLOW "        │-█ Constants and IDs-                      │                                                       " COLOR_RESET"│\n");
    printf("│" COLOR_BLUE   "        │-█ Flow Control and Input/Output Keywords- │                                                       " COLOR_RESET"│\n");
    printf("│" COLOR_CYAN   "        │-█ List Operations-                        │                                                       " COLOR_RESET"│\n");
    printf("│" COLOR_RED    "        │-█ Syntax Errors-                          │                                                       " COLOR_RESET"│\n");
    printf(                 "│        │-█ Others-                                 │                                                       │\n");
    printf(                 "│        └───────────────────────────────────────────┘                                                       │\n");
    printf(                 "│                                                                                                            │\n");

    // █
    // ╚
    // │

    // printBranch(TreeRoot, 0);
    // printBranch2(TreeRoot, 0, "start");
    printBranch3(TreeRoot, 0, "start");

    printf("│--------------------------------------------------END TREE--------------------------------------------------│\n");
    printf("└────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");

    #ifdef DEBUG_TREE
    printf("%d nodes in tree\n", nodesBuilt);
    #endif

}

void printBranch(t_node* node, int level){
    int i;

    #ifdef DEBUG_TREE
    printf("Printing branch %s- level %d\n", node->name, level);
    nodesBuilt++;
    #endif

    // não vazio
    if(node->empty == 0){
        if(level > 0){
            printf("%*s", level*2, " ");
        }
        printf("%s\n", node->name);

        if(node->child != NULL){
            #ifdef DEBUG_TREE
            printf("Printing children of node %s\n", node->name);
            #endif
            for(i=0; node->child[i] != NULL; i++){
                #ifdef DEBUG_TREE
                printf("Printing child %d of node %s\n", i, node->name);
                #endif
                printBranch(node->child[i], level+1);
            }
        }
    }
}

void printBranch2(t_node* node, int level, char* prevNode){
    int i;

    #ifdef DEBUG_TREE
    printf("Printing branch %s- level %d\n", node->name, level);
    nodesBuilt++;
    #endif

    // não vazio
    if(node->empty == 0){
        if(strcmp(node->name, prevNode) != 0){
            if(level > 0){
                printf("%*s", level*4, " ");
            }
            printf("%s\n", node->name);
        }
        else{
            level--;
        }

        if(node->child != NULL){
            #ifdef DEBUG_TREE
            printf("Printing children of node %s\n", node->name);
            #endif
            for(i=0; node->child[i] != NULL; i++){
                #ifdef DEBUG_TREE
                printf("Printing child %d of node %s\n", i, node->name);
                #endif
                printBranch2(node->child[i], level+1, node->name);
            }
        }
    }
}

void printBranch3(t_node* node, int level, char* prevNode){
    int i, aux, typeLen;

    #ifdef DEBUG_TREE
    printf("Printing branch %s- level %d\n", node->name, level);
    nodesBuilt++;
    #endif

    // não vazio
    if(node->empty == 0){
        if(strcmp(node->name, prevNode) != 0){
            if(level > 0){
                printf("│%*s", level*4, " ");
            }
            else{
                printf("│");
            }
            if(strncmp(node->name, "\x1B[", 2) == 0){
                if(
                    (strcmp(node->sigla, "CastIntToFloat") == 0) ||
                    (strcmp(node->sigla, "CastFloatToInt") == 0) ||
                    (strcmp(node->sigla, "CastNilToIntList") == 0) ||
                    (strcmp(node->sigla, "CastNilToFloatList") == 0)
                ){
                    aux = 9;
                }
                else{
                    aux = 7;
                }
                // printf("FORMATTED NODE\n");
            }
            else{
                aux = -2;
            }
            // printf("%s%*s│\n", node->name, (110 - (level*4) - strlen(node->name) + aux), " ");
            if(node->type != NULL){
                typeLen = strlen(node->type);
            }
            else{
                typeLen = 6;
            }
            printf("%s - %s%*s│\n", node->name, node->type, ((int)(110 - (level*4) - strlen(node->name) - (typeLen + 3)  + aux)), " ");
        }
        else{
            level--;
        }

        if(node->child != NULL){
            #ifdef DEBUG_TREE
            printf("Printing children of node %s\n", node->name);
            #endif
            for(i=0; node->child[i] != NULL; i++){
                #ifdef DEBUG_TREE
                printf("Printing child %d of node %s\n", i, node->name);
                #endif
                printBranch3(node->child[i], level+1, node->name);
            }
        }
    }
}

void freeTree(){
    #ifdef DEBUG_TREE
    int i;
    #endif

    #ifdef DEBUG_TREE
    i = freeBranch(TreeRoot);
    #endif

    #ifndef DEBUG_TREE
    freeBranch(TreeRoot);
    #endif

    if(lastFuncDeclared != NULL){
        free(lastFuncDeclared);
    }

    #ifdef DEBUG_TREE
    printf("Freed %d nodes from tree\n", i);
    #endif
}

int freeBranch(t_node* node){
    int i, freed;

    freed = 0;

    #ifdef DEBUG_TREE
    printf("Freeing branch %s\n", node->name);
    #endif


    if(node->child != NULL){
        #ifdef DEBUG_TREE
        printf("Freeing children of node %s\n", node->name);
        #endif
        for(i=0; node->child[i] != NULL; i++){
            freed = freed + freeBranch(node->child[i]);
        }
    }
    if(node->name != NULL){
        free(node->name);   //libera memória alocada para o nome
    }

    if(node->sigla != NULL){
        free(node->sigla);  //libera memória alocada para a sigla
    }

    if(node->child != NULL){
        free(node->child);  //libera memória alocada para o vetor de filhos
    }

    if(node->type != NULL){
        free(node->type);   //libera memória alocada para o tipo
    }

    if(node->functionName != NULL){
        free(node->functionName);   //libera memória alocada para o nome da função
    }

    if(node->id != NULL){
        free(node->id);   //libera memória alocada para o id
    }


    if(node != NULL){
        free(node);     //libera memória alocada para o nó
    }

    return freed + 1;
}
