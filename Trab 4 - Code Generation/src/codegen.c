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

- declaração de variável - FEITO
- declaração de função - FEITO
- if - FEITO
- if else - FEITO
- for - FEITO
- return - FEITO
- atribuição - FEITO
- expressões lógicas - FEITO
- expressões relacionais - FEITO
- expressões aritméticas - FEITO
- expressões de lista
- constantes?
- chamada de função - FEITO
- passagem de parâmetro - FEITO
- recebimento de parâmetro - FEITO
- write e writeln - FEITO
-- corrigir -  as instruções print e println parecem aceitar apenas um caractere por vez. Talvez seja necessário colocar a string na tabela de símbolos ou
    criar uma linha de print para cada caractere (mais simples). - FEITO
- read - FEITO
- conversões de tipo - FEITO PARA TIPOS BÁSICOS

- necessário adicionar um return padrão em toda função. O mais correto seria adicionar o nó na árvore, mas se for mais fácil pode só procurar um jeito de adicionar um return
no final do código já gerado de uma função;
*/


char* FileName = NULL;
int lastContextId = -1;
int labelCounter = -1;

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
    t_node* tempNode = NULL;
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

            // se definida essa flag, é gerado um código simples de write e writeln, apenas para facilitar visualização
            // ao invés de imprimir caractere a caractere no arquivo final, que é o correto aceito pelo tac, imprime a string completa de uma vez
            // isso não é aceito pelo tac mas ajuda a visualizar outras coisas no codigo final
            #ifndef DEBUG_CODEGEN_SIMPLE_WRITE
            for(i=1; i<(strlen(node->value)-1); i++){
                sprintf(tempCode, "print '%c'", node->value[i]);
                createCode(tempCode);
            }
            #endif

            #ifdef DEBUG_CODEGEN_SIMPLE_WRITE
            sprintf(tempCode, "print %s", node->value);
            createCode(tempCode);
            #endif
        }
        // writeln string
        else if(strcmp(node->sigla, "writelnString") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is writeln string\n");
            #endif

            // se definida essa flag, é gerado um código simples de write e writeln, apenas para facilitar visualização
            // ao invés de imprimir caractere a caractere no arquivo final, que é o correto aceito pelo tac, imprime a string completa de uma vez
            // isso não é aceito pelo tac mas ajuda a visualizar outras coisas no codigo final
            #ifndef DEBUG_CODEGEN_SIMPLE_WRITE
            for(i=1; i<(strlen(node->value)-1); i++){
                sprintf(tempCode, "print '%c'", node->value[i]);
                createCode(tempCode);
            }
            sprintf(tempCode, "println");
            createCode(tempCode);
            #endif

            #ifdef DEBUG_CODEGEN_SIMPLE_WRITE
            sprintf(tempCode, "println %s", node->value);
            createCode(tempCode);
            #endif
        }
        // write exp
        if(strcmp(node->sigla, "writeExp") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is write expression\n");
            #endif

            setOperand(node->child[0], tempOperand1);

            sprintf(tempCode, "print %s", tempOperand1);

            createCode(tempCode);
        }
        // writeln exp
        else if(strcmp(node->sigla, "writelnExp") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is writeln expression\n");
            #endif

            setOperand(node->child[0], tempOperand1);

            sprintf(tempCode, "println %s", tempOperand1);

            createCode(tempCode);
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
            printf("generateCode - Node is type cast - %s\n", node->sigla);
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
            // placeholder
            else{
                sprintf(tempCode, "inttofl %s", tempOperands);
            }

            addNodeTemporary(node, tempInt);
            createCode(tempCode);
        }
        // declaração de função e parâmetros recebidos pela pilha
        else if((strcmp(node->sigla, "funcDec") == 0) || (strcmp(node->sigla, "funcDecList") == 0)){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is function declaration\n");
            #endif

            sprintf(tempCode, "%s:", node->symbol->name);
            createCode(tempCode);

            pushContext();

            // recebe os parâmetros que serão passados pela pilha
            for(i=0; i<node->symbol->paramNumber; i++){
                // percorre cada parâmetro já armazenado na tabela de símbolos
                // os parâmetros foram empilhados bottom up, do final para o início, então é necessário receber-los do início para o final, desempilhando
                sprintf(tempCode, "pop %s_%d", node->symbol->parameters[i]->name, node->symbol->parameters[i]->scopeValue);
                createCode(tempCode);
            }

        }
        // chamada de função e parâmetros passados pela pilha
        else if(strcmp(node->sigla, "funcCall") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is function call\n");
            #endif

            // gera o código dos parâmetros sendo passados
            for(tempNode = node->child[0]; tempNode != NULL; tempNode = tempNode->child[0]){
                if((tempNode->child != NULL) && (strcmp(tempNode->sigla, "paramPass") == 0)){
                    // é 1 ou mais parâmetros
                    if(tempNode->child[0]->child != NULL){
                        // existe uma subárvore no child 0 com mais parâmetros, child 1 é um parâmetro
                        setOperand(tempNode->child[1], tempOperand1);
                        sprintf(tempCode, "param %s", tempOperand1);
                        createCode(tempCode);
                        // for já move o ponteiro do tempNode, só é preciso não sair do loop
                    }
                    else{
                        // últimos parâmetros, final da "recursão" transformada em loop
                        setOperand(tempNode->child[1], tempOperand1);
                        sprintf(tempCode, "param %s", tempOperand1);
                        createCode(tempCode);

                        setOperand(tempNode->child[0], tempOperand1);
                        sprintf(tempCode, "param %s", tempOperand1);
                        createCode(tempCode);
                        break;
                    }
                }
                else{
                    // apenas 1 ou nenhum parâmetro
                    if(tempNode->empty == 0){
                        // só possui 1 parâmetro, deve analisar o nó inicial da execução
                        setOperand(tempNode, tempOperand1);
                        sprintf(tempCode, "param %s", tempOperand1);
                        createCode(tempCode);
                    }
                    // se o nó for vazio, não existem parâmetros, nada precisa ser feito
                    // sai do loop
                    break;
                }
            }

            // gera código para a chamada da função
            sprintf(tempCode, "call %s", node->symbol->name);
            createCode(tempCode);

            // gera código para receber o retorno da função
            tempInt = getNewTemporary();
            sprintf(tempCode, "pop $%d", tempInt);
            addNodeTemporary(node, tempInt);
            createCode(tempCode);

        }
        // return
        else if(strcmp(node->sigla, "return") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is return\n");
            #endif

            setOperand(node->child[0], tempOperand1);
            sprintf(tempCode, "return %s", tempOperand1);
            createCode(tempCode);


        }
        // if
        else if(strcmp(node->sigla, "if") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is if\n");
            #endif

            // branch quando for falso. Quando for verdadeiro é só continuar a execução
            tempInt = getNewLabelId();
            sprintf(tempOperand1, "if_label_%d", tempInt);

            setOperand(node->child[0], tempOperand2);

            sprintf(tempCode, "brz %s, %s", tempOperand1, tempOperand2);

            createCode(tempCode);

            addNodeLabel(node->child[1], tempOperand1);

        }
        // if else
        else if(strcmp(node->sigla, "ifelse") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is if else\n");
            #endif

            // branch quando for falso. Quando for verdadeiro é só continuar a execução
            tempInt = getNewLabelId();
            sprintf(tempOperand1, "if_label_%d", tempInt);

            setOperand(node->child[0], tempOperand2);

            sprintf(tempCode, "brz %s, %s", tempOperand1, tempOperand2);

            createCode(tempCode);

            // label para o final do if, ou começo do else
            addNodeLabel(node->child[1], tempOperand1);

            tempInt = getNewLabelId();
            sprintf(tempOperand1, "if_label_%d", tempInt);

            // label para final do else, ou final de todo o if else
            addNodeLabel(node->child[2], tempOperand1);
            addNodeLabelJump(node->child[1], tempOperand1);

        }
        // for
        else if(strcmp(node->sigla, "for") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is for\n");
            #endif


            tempInt = getNewLabelId();
            sprintf(tempOperand1, "for_label_%d", tempInt);

            // label para início do for, após a atribuição inicial que já foi gerada
            sprintf(tempCode, "%s:", tempOperand1);
            createCode(tempCode);

            addNodeLabelJumpTrue(node->child[1], tempOperand1);

        }
        // fim do seletor de nós



        // se tiver uma labelJump, adiciona uma instrução de jump incondicional no final do código gerado
        if(node->labelJump != NULL){
            sprintf(tempCode, "jump %s", node->labelJump);
            createCode(tempCode);
        }

        // se tiver uma labelJumpTrue, adiciona uma instrução de jump condicional (branch se último temporário é diferente de zero) no final do código gerado
        if(node->labelJumpTrue != NULL){
            sprintf(tempCode, "brnz %s, $%d", node->labelJumpTrue, getLastTemporary());
            createCode(tempCode);
        }

        // se tiver uma label, adiciona no final do código gerado
        if(node->label != NULL){
            sprintf(tempCode, "%s:", node->label);
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
    int i, pregen, pregen_child[10];

    for(i=0; i<10; i++){
        pregen_child[i] = 0;
    }

    #ifdef DEBUG_CODEGEN
    printf("assembleCode - Assembling code for node %s\n", node->name);
    #endif

    if(node == TreeRoot){
        createCode(".code");
    }

    if(node != NULL){
        pregen = 0;
        // casos onde o nó precisa ser gerado antes dos filhos
        if(
            (strcmp(node->sigla, "funcDec") == 0) || (strcmp(node->sigla, "funcDecList") == 0) || (strcmp(node->sigla, "if") == 0) ||
            (strcmp(node->sigla, "ifelse") == 0) || (strcmp(node->sigla, "for") == 0)
        ){
            // caso onde o filho 1 precisa ser gerado antes do nó, que precisa ser gerado antes dos outros filhos
            // if, ifelse, for
            if((strcmp(node->sigla, "if") == 0) || (strcmp(node->sigla, "ifelse") == 0) || (strcmp(node->sigla, "for") == 0)){
                assembleCode(node->child[0]);
                pregen_child[0] = 1;
            }

            generateCode(node);
            pregen = 1;

            // casos específiocos do for - tratamento dos filhos possui uma ordem específica a ser seguida
            // nó do for já foi gerado, então as labels e labelJumps já foram atribuídas aos filhos
            if((strcmp(node->sigla, "for") == 0)){
                // gera o código do corpo do for - atribuição e label inicial já foram geradas
                assembleCode(node->child[3]);
                pregen_child[3] = 1;

                // gera o código da incrementação do for - corpo já foi gerado
                assembleCode(node->child[2]);
                pregen_child[2] = 1;

                // gera o código da verificação do for - incrementação já foi gerada. As labels e labelJumps já foram tratadas pelo nó pai e estão armazenadas no filho
                assembleCode(node->child[1]);
                pregen_child[1] = 1;
            }
        }


        if(node->child != NULL){
            for(i=0; node->child[i]!= NULL; i++){
                if(pregen_child[i] == 0){
                    assembleCode(node->child[i]);
                }
                else{
                    pregen_child[i] = 0;
                }
            }
        }

        if(pregen == 0){
            generateCode(node);
        }
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


int getNewLabelId(){
    // incrementa e depois retorna o valor
    return ++labelCounter;
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
