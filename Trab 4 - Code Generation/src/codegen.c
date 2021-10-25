#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/semantic.h"
#include "../lib/tree.h"
#include "../lib/symbol_table.h"
#include "../lib/codegen.h"


/*
NOTES:

Operações para gerar código:

- declaração de variável
- declaração de função
- if
- if else
- for
- return
- atribuição - FEITO
- expressões lógicas - FEITO
- expressões relacionais - FEITO
- expressões aritméticas - FEITO
- expressões de lista
- constantes?
- chamada de função
- passagem de parâmetro
- write e writeln - FEITO
-- corrigir -  as intstruções print e println parecem aceitar apenas um caractere por vez. Talvez seja necessário colocar a string na tabela de símbolos ou
    criar uma linha de print para cada caractere (mais simples).
- read - FEITO
- conversões de tipo
*/


char* FileName = NULL;
int lastContextId = -1;

t_code* CodeList = NULL;
t_code* lastCode = NULL;
t_context* TopContext = NULL;

t_code* createCode(char* code){
    t_code* newCode;

    #ifdef DEBUG_CODEGEN
    printf("createCode - Creating code %s\n", code);
    #endif


    newCode = malloc(sizeof(t_code));

    newCode->code = malloc(strlen(code) + 1);
    strcpy(newCode->code, code);


    if(lastCode != NULL){
        lastCode->next = newCode;
        newCode->prev = lastCode;
    }

    if(CodeList == NULL){
        CodeList = newCode;
        newCode->prev = NULL;
    }

    newCode->next = NULL;
    lastCode = newCode;

    #ifdef DEBUG_CODEGEN
    printf("createCode - Created code %s\n", newCode->code);
    #endif

    return newCode;
}



void generateCode(t_node* node){
    char tempCode[300];
    char tempOperands[120];
    char tempOperand1[50];
    char tempOperand2[50];
    int tempInt, i, tempInt2;
    // t_symbol* tempSymbol = NULL;

    if(node != NULL){

        #ifdef DEBUG_CODEGEN
        printf("generateCode - Generating code for node %s - %s\n", node->name, node->sigla);
        #endif

        // write string
        if(strcmp(node->sigla, "writeString") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is write string\n");
            #endif

            for(i=1; i<(strlen(node->value)-1); i++){
                sprintf(tempCode, "print '%c'", node->value[i]);
                createCode(tempCode);
            }

            // sprintf(tempCode, "print %s", node->value);
            // createCode(tempCode);
        }
        // writeln string
        else if(strcmp(node->sigla, "writelnString") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is writeln string\n");
            #endif

            for(i=1; i<(strlen(node->value)-1); i++){
                sprintf(tempCode, "print '%c'", node->value[i]);
                createCode(tempCode);
            }
            sprintf(tempCode, "println");
            createCode(tempCode);

            // sprintf(tempCode, "println %s", node->value);
            // createCode(tempCode);
        }
        // read
        else if(strcmp(node->sigla, "readOp") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is read\n");
            #endif


            if(node->symbol != NULL){
                if(strcmp(node->symbol->typeBase, "float") == 0){
                    sprintf(tempCode, "scanf %s_%d", node->symbol->name, node->symbol->scopeValue);
                }
                else {
                    sprintf(tempCode, "scani %s_%d", node->symbol->name, node->symbol->scopeValue);
                }
                createCode(tempCode);
            }

            // sprintf(temp, "println %s", node->string);
        }
        // atribuição
        else if(strcmp(node->sigla, "assignOp") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is assignOp\n");
            #endif

            if(strncmp(node->child[0]->sigla, "const", 5) == 0){
                // se a subexpressão à direita da atribuição for uma constante
                // sprintf(tempOperand2, "%s", node->child[0]->value);

                setOperandConstant(node->child[0], tempOperand2);
            }
            else{
                tempInt = getLastTemporary();
                sprintf(tempOperand2, "$%d", tempInt);
            }

            sprintf(tempCode, "mov %s_%d, %s", node->id, node->symbol->scopeValue, tempOperand2);

            createCode(tempCode);
        }
        // soma ou subtração
        else if(strcmp(node->sigla, "sumExp") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is sumExp - children %s %s %s\n", node->child[0]->name, node->child[1]->name, node->child[2]->name);
            #endif

            // if((node->child[0]->assignedTemporary <= -2)){
            //     // subexpressão à esquerda não possui um temporário, ou seja, deve ser um elemento único (constante, por exemplo)
            //     if(strcmp(node->child[0]->sigla, "id") == 0){
            //         // subexpressão da esquerda é um id
            //         sprintf(tempOperand1, "%s_%d", node->child[0]->id, node->child[0]->symbol->scopeValue);
            //     }
            //     else if(strncmp(node->child[0]->sigla, "const", 5) == 0){
            //         // subexpressão da esquerda é uma constante
            //         setOperandConstant(node->child[0], tempOperand1);
            //     }
            // }
            // else{
            //     // subexpressão à esquerda possui temporário, ou seja, é uma subxpressão já calculada
            //     sprintf(tempOperand1, "$%d", node->child[0]->assignedTemporary);
            // }
            //
            // if((node->child[2]->assignedTemporary <= -2)){
            //     // subexpressão à direita não possui um temporário, ou seja, deve ser um elemento único (constante, por exemplo)
            //     if(strcmp(node->child[2]->sigla, "id") == 0){
            //         // subexpressão da direita é um id
            //         sprintf(tempOperand2, "%s_%d", node->child[2]->id, node->child[2]->symbol->scopeValue);
            //     }
            //     else if(strncmp(node->child[2]->sigla, "const", 5) == 0){
            //         // subexpressão da direita é uma constante
            //         setOperandConstant(node->child[2], tempOperand2);
            //     }
            // }
            // else{
            //     // subexpressão à direita possui temporário, ou seja, é uma subxpressão já calculada
            //     sprintf(tempOperand2, "$%d", node->child[2]->assignedTemporary);
            // }

            // if((node->child[0]->assignedTemporary <= -2) && (node->child[2]->assignedTemporary <= -2)){
            //     // duas subexpressões não possuem temporários, ou seja, devem ser elementos únicos (constantes, por exemplo)
            //
            //     #ifdef DEBUG_CODEGEN
            //     printf("generateCode - sumExp node - no temporaries\n");
            //     #endif
            //
            //     if(strcmp(node->child[0]->sigla, "id") == 0){
            //         // subexpressão da esquerda é um id
            //         sprintf(tempOperand1, "%s_%d", node->child[0]->id, node->child[0]->symbol->scopeValue);
            //     }
            //     else if(strncmp(node->child[0]->sigla, "const", 5) == 0){
            //         // subexpressão da esquerda é uma constante
            //         // if(strncmp(node->child[0]->sigla, "constNeg", 8) == 0){
            //         //     // negativa
            //         //     sprintf(tempOperand1, "-%s", node->child[0]->value);
            //         // }
            //         // else{
            //         //     // positiva
            //         //     sprintf(tempOperand1, "%s", node->child[0]->value);
            //         // }
            //
            //         setOperandConstant(node->child[0], tempOperand1);
            //     }
            //
            //     if(strcmp(node->child[2]->sigla, "id") == 0){
            //         // subexpressão da direita é um id
            //         sprintf(tempOperand2, "%s_%d", node->child[2]->id, node->child[2]->symbol->scopeValue);
            //     }
            //     else if(strncmp(node->child[2]->sigla, "const", 5) == 0){
            //         // subexpressão da direita é uma constante
            //         // if(strncmp(node->child[2]->sigla, "constNeg", 8) == 0){
            //         //     // negativa
            //         //     sprintf(tempOperand2, "-%s", node->child[2]->value);
            //         // }
            //         // else{
            //         //     // positiva
            //         //     sprintf(tempOperand2, "%s", node->child[2]->value);
            //         // }
            //
            //         setOperandConstant(node->child[2], tempOperand2);
            //     }
            // }
            // else if((node->child[0]->assignedTemporary <= -2) && (node->child[2]->assignedTemporary > -2)){
            //     // subexpressão da direita possui um temporário, ou seja, é uma subexpressão e já teve seu código gerado, temporário é usado aqui
            //
            //     #ifdef DEBUG_CODEGEN
            //     printf("generateCode - sumExp node - right has temporary\n");
            //     #endif
            //
            //     if(strcmp(node->child[0]->sigla, "id") == 0){
            //         // subexpressão da esquerda é um id
            //         sprintf(tempOperand1, "%s_%d", node->child[0]->id, node->child[0]->symbol->scopeValue);
            //     }
            //     else if(strncmp(node->child[0]->sigla, "const", 5) == 0){
            //         // subexpressão da esquerda é uma constante
            //         // if(strncmp(node->child[0]->sigla, "constNeg", 8) == 0){
            //         //     // negativa
            //         //     sprintf(tempOperand1, "-%s", node->child[0]->value);
            //         // }
            //         // else{
            //         //     // positiva
            //         //     sprintf(tempOperand1, "%s", node->child[0]->value);
            //         // }
            //         setOperandConstant(node->child[0], tempOperand1);
            //     }
            //
            //     sprintf(tempOperand2, "$%d", node->child[2]->assignedTemporary);
            // }
            // else if((node->child[0]->assignedTemporary > -2) && (node->child[2]->assignedTemporary <= -2)){
            //     // subexpressão da esquerda possui um temporário, ou seja, é uma subexpressão e já teve seu código gerado, temporário é usado aqui
            //
            //     #ifdef DEBUG_CODEGEN
            //     printf("generateCode - sumExp node - left has temporary\n");
            //     #endif
            //
            //     if(strcmp(node->child[2]->sigla, "id") == 0){
            //         // subexpressão da direita é um id
            //         sprintf(tempOperand2, "%s_%d", node->child[2]->id, node->child[2]->symbol->scopeValue);
            //     }
            //     else if(strncmp(node->child[2]->sigla, "const", 5) == 0){
            //         // subexpressão da direita é uma constante
            //         // if(strncmp(node->child[2]->sigla, "constNeg", 8) == 0){
            //         //     // negativa
            //         //     sprintf(tempOperand2, "-%s", node->child[2]->value);
            //         // }
            //         // else{
            //         //     // positiva
            //         //     sprintf(tempOperand2, "%s", node->child[2]->value);
            //         // }
            //         setOperandConstant(node->child[2], tempOperand2);
            //     }
            //
            //     sprintf(tempOperand1, "$%d", node->child[0]->assignedTemporary);
            // }
            // else{
            //     // as duas subexpressões possuem temporários e já tiveram seu código gerado, devemos usar os temporários aqui
            //
            //     #ifdef DEBUG_CODEGEN
            //     printf("generateCode - sumExp node - both have temporaries\n");
            //     #endif
            //
            //     sprintf(tempOperand1, "$%d", node->child[0]->assignedTemporary);
            //     sprintf(tempOperand2, "$%d", node->child[2]->assignedTemporary);
            // }

            setOperand(node->child[0], tempOperand1);
            setOperand(node->child[2], tempOperand2);

            tempInt = getNewTemporary();

            sprintf(tempOperands, "$%d, %s, %s", tempInt, tempOperand1, tempOperand2);

            addNodeTemporary(node, tempInt);

            if(strcmp(node->child[1]->sigla, "plusOp") == 0){
                sprintf(tempCode, "add %s", tempOperands);
            }
            else if(strcmp(node->child[1]->sigla, "minusOp") == 0){
                sprintf(tempCode, "sub %s", tempOperands);
            }

            createCode(tempCode);

        }
        // multiplicação ou divisão
        else if(strcmp(node->sigla, "mulExp") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is mulExp - children %s %s %s\n", node->child[0]->name, node->child[1]->name, node->child[2]->name);
            #endif

            // if((node->child[0]->assignedTemporary <= -2)){
            //     // subexpressão à esquerda não possui um temporário, ou seja, deve ser um elemento único (constante, por exemplo)
            //     if(strcmp(node->child[0]->sigla, "id") == 0){
            //         // subexpressão da esquerda é um id
            //         sprintf(tempOperand1, "%s_%d", node->child[0]->id, node->child[0]->symbol->scopeValue);
            //     }
            //     else if(strncmp(node->child[0]->sigla, "const", 5) == 0){
            //         // subexpressão da esquerda é uma constante
            //         setOperandConstant(node->child[0], tempOperand1);
            //     }
            // }
            // else{
            //     // subexpressão à esquerda possui temporário, ou seja, é uma subxpressão já calculada
            //     sprintf(tempOperand1, "$%d", node->child[0]->assignedTemporary);
            // }
            //
            // if((node->child[2]->assignedTemporary <= -2)){
            //     // subexpressão à direita não possui um temporário, ou seja, deve ser um elemento único (constante, por exemplo)
            //     if(strcmp(node->child[2]->sigla, "id") == 0){
            //         // subexpressão da direita é um id
            //         sprintf(tempOperand2, "%s_%d", node->child[2]->id, node->child[2]->symbol->scopeValue);
            //     }
            //     else if(strncmp(node->child[2]->sigla, "const", 5) == 0){
            //         // subexpressão da direita é uma constante
            //         setOperandConstant(node->child[2], tempOperand2);
            //     }
            // }
            // else{
            //     // subexpressão à direita possui temporário, ou seja, é uma subxpressão já calculada
            //     sprintf(tempOperand2, "$%d", node->child[2]->assignedTemporary);
            // }

            setOperand(node->child[0], tempOperand1);
            setOperand(node->child[2], tempOperand2);

            tempInt = getNewTemporary();

            sprintf(tempOperands, "$%d, %s, %s", tempInt, tempOperand1, tempOperand2);

            addNodeTemporary(node, tempInt);

            if(strcmp(node->child[1]->sigla, "mulOp") == 0){
                sprintf(tempCode, "mul %s", tempOperands);
            }
            else if(strcmp(node->child[1]->sigla, "divOp") == 0){
                sprintf(tempCode, "div %s", tempOperands);
            }

            createCode(tempCode);

        }
        // lógica binária
        else if(strcmp(node->sigla, "logicBin") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is logicBin\n");
            #endif

            // if((node->child[0]->assignedTemporary <= -2)){
            //     // subexpressão à esquerda não possui um temporário, ou seja, deve ser um elemento único (constante, por exemplo)
            //     if(strcmp(node->child[0]->sigla, "id") == 0){
            //         // subexpressão da esquerda é um id
            //         sprintf(tempOperand1, "%s_%d", node->child[0]->id, node->child[0]->symbol->scopeValue);
            //     }
            //     else if(strncmp(node->child[0]->sigla, "const", 5) == 0){
            //         // subexpressão da esquerda é uma constante
            //         setOperandConstant(node->child[0], tempOperand1);
            //     }
            // }
            // else{
            //     // subexpressão à esquerda possui temporário, ou seja, é uma subxpressão já calculada
            //     sprintf(tempOperand1, "$%d", node->child[0]->assignedTemporary);
            // }
            //
            // if((node->child[1]->assignedTemporary <= -2)){
            //     // subexpressão à direita não possui um temporário, ou seja, deve ser um elemento único (constante, por exemplo)
            //     if(strcmp(node->child[1]->sigla, "id") == 0){
            //         // subexpressão da direita é um id
            //         sprintf(tempOperand2, "%s_%d", node->child[1]->id, node->child[1]->symbol->scopeValue);
            //     }
            //     else if(strncmp(node->child[1]->sigla, "const", 5) == 0){
            //         // subexpressão da direita é uma constante
            //         setOperandConstant(node->child[1], tempOperand2);
            //     }
            // }
            // else{
            //     // subexpressão à direita possui temporário, ou seja, é uma subxpressão já calculada
            //     sprintf(tempOperand2, "$%d", node->child[1]->assignedTemporary);
            // }

            setOperand(node->child[0], tempOperand1);
            setOperand(node->child[1], tempOperand2);

            tempInt = getNewTemporary();
            sprintf(tempOperands, "$%d, %s, %s", tempInt, tempOperand1, tempOperand2);

            addNodeTemporary(node, tempInt);

            if(strcmp(node->value, "&&") == 0){
                // and
                sprintf(tempCode, "and %s", tempOperands);
            }
            else if(strcmp(node->value, "||") == 0){
                // or
                sprintf(tempCode, "or %s", tempOperands);
            }

            // sprintf(tempCode, "%s %s", node->logicOperator, tempOperands);

            createCode(tempCode);
        }
        // lógica unária
        else if(strcmp(node->sigla, "exclaExp") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is exclaExp - unary logic\n");
            #endif

            setOperand(node->child[0], tempOperand1);

            tempInt = getNewTemporary();
            sprintf(tempOperands, "$%d, %s", tempInt, tempOperand1);

            addNodeTemporary(node, tempInt);

            sprintf(tempCode, "not %s", tempOperands);

            createCode(tempCode);
        }
        // relacionais
        else if(strcmp(node->sigla, "binExp") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is binExp - relational expression\n");
            #endif

            setOperand(node->child[0], tempOperand1);
            setOperand(node->child[1], tempOperand2);

            tempInt = getNewTemporary();
            // sprintf(tempOperands, "$%d, %s", tempInt, tempOperand1, tempOperand2);

            // <|<=|>|>=|==|!=
            if(strcmp(node->value, "<") == 0){
                // menor - slt
                sprintf(tempCode, "slt $%d, %s, %s", tempInt, tempOperand1, tempOperand2);
            }
            else if(strcmp(node->value, "<=") == 0){
                // menor igual - sleq
                sprintf(tempCode, "sleq $%d, %s, %s", tempInt, tempOperand1, tempOperand2);
            }
            else if(strcmp(node->value, ">") == 0){
                // maior - slt inverted
                sprintf(tempCode, "slt $%d, %s, %s", tempInt, tempOperand2, tempOperand1);
            }
            else if(strcmp(node->value, ">=") == 0){
                // maior igual - sleq inverted
                sprintf(tempCode, "sleq $%d, %s, %s", tempInt, tempOperand2, tempOperand1);
            }
            else if(strcmp(node->value, "==") == 0){
                // igual - seq
                sprintf(tempCode, "seq $%d, %s, %s", tempInt, tempOperand1, tempOperand2);
            }
            else if(strcmp(node->value, "!=") == 0){
                // diferente - not seq
                sprintf(tempCode, "seq $%d, %s, %s", tempInt, tempOperand1, tempOperand2);
                createCode(tempCode);
                tempInt2 = tempInt;
                tempInt = getNewTemporary();
                sprintf(tempCode, "not $%d, $%d", tempInt, tempInt2);
            }

            addNodeTemporary(node, tempInt);
            createCode(tempCode);
        }
        // conversão de tipo
        else if(strncmp(node->sigla, "Cast", 4) == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is binExp - relational expression\n");
            #endif

            tempInt = getNewTemporary();

            setOperand(node->child[0], tempOperand1);

            sprintf(tempOperands, "$%d, %s", tempInt, tempOperand1);
            // int to float
            if(strcmp(node->sigla, "CastIntToFloat") == 0){
                sprintf(tempCode, "inttofl %s", tempOperands);
            }
            // float to int
            else if(strcmp(node->sigla, "CastFloatToInt") == 0){
                sprintf(tempCode, "fltoint %s", tempOperands);
            }

            addNodeTemporary(node, tempInt);
            createCode(tempCode);
        }
    }
}


void setOperand(t_node* node, char* operand){
    if(node->assignedTemporary <= -2){
        // subexpressão não possui um temporário, ou seja, deve ser um elemento único (constante, por exemplo)
        if(strcmp(node->sigla, "id") == 0){
            // subexpressão é um id
            sprintf(operand, "%s_%d", node->symbol->name, node->symbol->scopeValue);
        }
        else if(strncmp(node->sigla, "const", 5) == 0){
            // subexpressão é uma constante
            setOperandConstant(node, operand);
        }
    }
    else{
        // subexpressão possui temporário, ou seja, é uma subxpressão já calculada
        sprintf(operand, "$%d", node->assignedTemporary);
    }

}


void setOperandConstant(t_node* node, char* operand){
    if(strncmp(node->sigla, "constNeg", 8) == 0){
        // negativa
        sprintf(operand, "-%s", node->value);
    }
    else{
        // positiva ou constante null
        sprintf(operand, "%s", node->value);
    }
}


void assembleCode(t_node* node){
    int i;

    #ifdef DEBUG_CODEGEN
    printf("assembleCode - Assembling code for node %s\n", node->name);
    #endif

    if(node == TreeRoot){
        createCode(".code");
    }

    if(node != NULL){

        if(node->child != NULL){
            for(i=0; node->child[i]!= NULL; i++){
                assembleCode(node->child[i]);
            }
        }
        generateCode(node);
    }
}


void setFileName(char* filename){
    int i;

    #ifdef DEBUG_CODEGEN
    printf("setFileName - Filename received: %s\n", filename);
    #endif

    FileName = malloc(strlen(filename) + 1);

    strcpy(FileName, filename);

    // strcpy(FileName, "\0");

    for(i = strlen(FileName) - 1; i>=0; i--){
        if(FileName[i] == '.'){
            FileName[i] = '\0';
            break;
        }
    }



    #ifdef DEBUG_CODEGEN
    printf("setFileName - Filename saved: %s - index: %d\n", FileName, i);
    #endif

}


t_context* pushContext(){
    t_context* context;

    context = malloc(sizeof(t_context));

    lastContextId++;
    context->contextId = lastContextId;

    context->lastTemporary = -1;

    context->next = NULL;

    if(TopContext != NULL){
        context->next = TopContext;
    }

    TopContext = context;

    return context;
}


void popContext(){
    t_context* context;

    if(TopContext != NULL){
        context = TopContext;
        TopContext = TopContext->next;

        free(context);
    }
}


t_context* getContext(){
    t_context* context;

    context = TopContext;

    return context;
}


int getNewTemporary(){
    t_context* context;

    context = getContext();

    context->lastTemporary++;

    return context->lastTemporary;
}


int getLastTemporary(){
    t_context* context;

    context = getContext();

    return context->lastTemporary;
}


void printCode(){
    t_code* pointer;

    printf("Imprimindo código gerado: \n");

    for(pointer = CodeList; pointer != NULL; pointer = pointer->next){
        printf("%s\n", pointer->code);
    }

    printf("Fim do código gerado\n");
}


void assembleTable(){
    t_symbol* symbol;
    char temp[80];

    createCode(".table");

    for(symbol = SymbolTable; symbol != NULL; symbol = symbol->next){
        // strcpy(temp, symbol->typeBase);
        // strcat(temp, " ");
        // strcat(temp, symbol->name);
        // strcat(temp, "_");
        // strcat(temp, symbol->scopeValue);

        if(symbol->varFunc == 1){
            sprintf(temp, "%s %s_%d", symbol->typeBase, symbol->name, symbol->scopeValue);

            createCode(temp);
        }
    }
}


void writeFile(){
    FILE* fp;
    char* tempFileName;
    t_code* codePointer;

    tempFileName = malloc(strlen(FileName) + 6);
    strcpy(tempFileName, FileName);
    strcat(tempFileName, ".tac");

    fp = fopen(tempFileName, "w");

    if(fp != NULL){

        for(codePointer = CodeList; codePointer != NULL; codePointer = codePointer->next){
            fprintf(fp, "%s\n", codePointer->code);
        }

        fclose(fp);
        printf("Compiler completed, written to file: %s\n", tempFileName);
    }
    else{
        printf("Fatal error when opening file to save generated code\n");
    }
}


void codeGeneration(){

    #ifdef DEBUG_CODEGEN
    printf("codeGeneration - Starting code generation process\n");
    #endif

    // inicializa geração
    // percorre árvore gerando o código e armazenando em uma estrutura
    //  armazenar em uma estrutura é mais rápido e permite fazer o backpatching
    // grava no arquivo - se debug ativado, printa na tela também

    assembleTable();

    pushContext();

    assembleCode(TreeRoot);

    #ifdef DEBUG_CODEGEN
    printCode();
    #endif

    writeFile();

}
