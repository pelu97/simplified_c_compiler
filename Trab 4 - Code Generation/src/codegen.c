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
- expressões de lista:
    - construtor - FEITO
    - destrutor
    - tail
    - header - FEITO
    - map
    - filter
- constantes?
- chamada de função - FEITO
- passagem de parâmetro - FEITO
- recebimento de parâmetro - FEITO
- write e writeln - FEITO
-- corrigir -  as instruções print e println parecem aceitar apenas um caractere por vez. Talvez seja necessário colocar a string na tabela de símbolos ou
    criar uma linha de print para cada caractere (mais simples). - FEITO
- read - FEITO
- conversões de tipo - FEITO

- necessário adicionar um return padrão em toda função. O mais correto seria adicionar o nó na árvore, mas se for mais fácil pode só procurar um jeito de adicionar um return
no final do código já gerado de uma função; - FEITO
- verificar se há alguma diferença em informar o número da parâmetros na chamada call ou não - talvez seja melhor só já adicionar o número de parâmetros
na instrução de call. - FEITO
- remover o return da função main, não é necessário. - FEITO
- atualizar a forma como parâmetros são recebidos em uma função, verificar o uso de # - NÃO É NECESSÁRIO, DESEMPILHAR FUNCIONA CORRETAMENTE
- corrigidos problemas sintáticos ao usar expressões de lista dentro de outras expressões e problema semântico ao comparar lista com NIL; - FEITO
- corrigido localização de erro quando um nó de cast era uilizado; - FEITO
- problema na passagem de parâmetros, não funciona em recursões. É necessário utilizar o # ou receber em temporários. - FEITO
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
    int tempInt, i, tempInt2, tempInt3, tempInt4, tempInt5, tempInt6, tempInt7;
    t_node* tempNode = NULL;
    // t_symbol* tempSymbol = NULL;

    // as variáveis possuem nomes de temporários, sem nomes mnemônicos, pois são utilizadas para várias coisas diferentes
    // em cada situação diferente (nó diferente ou if diferente), as variáveis temporárias são utilizadas de alguma forma diferente com significados diferentes
    // nos casos onde muitos temporários forem utilizados, haverão comentários explicando o que cada um está representando naquela situação

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

            // if(strncmp(node->child[0]->sigla, "const", 5) == 0){
            //     // se a subexpressão à direita da atribuição for uma constante
            //     // sprintf(tempOperand2, "%s", node->child[0]->value);
            //
            //     setOperandConstant(node->child[0], tempOperand2);
            // }
            // else{
            //     tempInt = getLastTemporary();
            //     sprintf(tempOperand2, "$%d", tempInt);
            // }



            // // se a variável for do tipo lista
            // if((strcmp(node->symbol->type, "int list") == 0) || (strcmp(node->symbol->type, "float list") == 0)){
            //     //  verifica se essa variável já possui um temporário que armazena a sua lista
            //     // if(node->symbol->listTemporary > -1){
            //     //     tempInt = node->symbol->listTemporary;
            //     // }
            //     // // não possui um temporário ainda, cria um
            //     // else{
            //     //     tempInt = getNewTemporary();
            //     //     addSymbolListTemporary(node->symbol, tempInt);
            //     // }
            //
            //     // cria o código movendo para o temporário
            //     sprintf(tempCode, "mov $%d, %s", tempInt, tempOperand2);
            //     createCode(tempCode);
            //
            // }
            // // se não for do tipo lista
            // else{
            //     sprintf(tempCode, "mov %s_%d, %s", node->id, node->symbol->scopeValue, tempOperand2);
            //     createCode(tempCode);
            // }

            setOperand(node, tempOperand1);
            setOperand(node->child[0], tempOperand2);

            sprintf(tempCode, "mov %s, %s", tempOperand1, tempOperand2);
            createCode(tempCode);


        }
        // soma ou subtração
        else if(strcmp(node->sigla, "sumExp") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is sumExp - children %s %s %s\n", node->child[0]->name, node->child[1]->name, node->child[2]->name);
            #endif


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
                // sprintf(tempCode, "inttofl %s", tempOperands);
                sprintf(tempCode, "mov %s", tempOperands);
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

            tempInt = node->symbol->paramNumber-1;
            // recebe os parâmetros que serão passados pela pilha
            for(i=0; i<node->symbol->paramNumber; i++){
                // percorre cada parâmetro já armazenado na tabela de símbolos
                // os parâmetros foram empilhados bottom up, do final para o início, então é necessário receber-los do início para o final, desempilhando

                // sprintf(tempCode, "pop %s_%d", node->symbol->parameters[i]->name, node->symbol->parameters[i]->scopeValue);
                // createCode(tempCode);

                // não é necessário desempilhar os parâmetros, mas é necessário definir qual o número de cada um para que sejam acessados com #
                // os parâmetros foram empilhados do final para o início, então o #0 é o último parâmetro da declaração, os números são definidos de forma decrescente
                addSymbolParamTemporary(node->symbol->parameters[i], tempInt);
                tempInt--;

            }


        }
        // chamada de função e parâmetros passados pela pilha
        else if(strcmp(node->sigla, "funcCall") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is function call\n");
            #endif

            tempInt = 0;
            // gera o código dos parâmetros sendo passados
            for(tempNode = node->child[0]; tempNode != NULL; tempNode = tempNode->child[0]){
                if((tempNode->child != NULL) && (strcmp(tempNode->sigla, "paramPass") == 0)){
                    // é 1 ou mais parâmetros
                    if(tempNode->child[0]->child != NULL){
                        // existe uma subárvore no child 0 com mais parâmetros, child 1 é um parâmetro
                        setOperand(tempNode->child[1], tempOperand1);
                        sprintf(tempCode, "param %s", tempOperand1);
                        createCode(tempCode);
                        tempInt++;
                        // for já move o ponteiro do tempNode, só é preciso não sair do loop
                    }
                    else{
                        // últimos parâmetros, final da "recursão" transformada em loop
                        setOperand(tempNode->child[1], tempOperand1);
                        sprintf(tempCode, "param %s", tempOperand1);
                        createCode(tempCode);
                        tempInt++;

                        setOperand(tempNode->child[0], tempOperand1);
                        sprintf(tempCode, "param %s", tempOperand1);
                        createCode(tempCode);
                        tempInt++;
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
                        tempInt++;
                    }
                    // se o nó for vazio, não existem parâmetros, nada precisa ser feito
                    // sai do loop
                    break;
                }
            }

            // gera código para a chamada da função
            // tempInt guarda o número de parâmetros que foram passados pela pilha
            sprintf(tempCode, "call %s, %d", node->symbol->name, tempInt);
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
            printf("generateCode - Node is return - function: %s\n", node->functionName);
            #endif

            // a main não deve ter return
            if(strcmp(node->functionName, "main") != 0){
                setOperand(node->child[0], tempOperand1);
                sprintf(tempCode, "return %s", tempOperand1);
                createCode(tempCode);

            }
            else{
                sprintf(tempCode, "println");
                createCode(tempCode);
            }

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
        // list header
        else if(strcmp(node->sigla, "listHeader") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is list header\n");
            #endif

            tempInt = getNewTemporary();

            setOperand(node->child[0], tempOperand1);

            sprintf(tempCode, "mov $%d, %s[0]", tempInt, tempOperand1);

            createCode(tempCode);

            addNodeTemporary(node, tempInt);
        }
        // list tail
        else if(strcmp(node->sigla, "listTail") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is list tail\n");
            #endif

            // setOperand(node->child[0], tempOperand1);
            // setOperandSize(node->child[0], tempOperand2);
            //
            // sprintf(tempCode, "%s[%s-1]", tempOperand1, tempOperand2);
            //
            // createCode(tempCode);
        }
        // construtor de lista
        else if(strcmp(node->sigla, "listAssign") == 0){
            #ifdef DEBUG_CODEGEN
            printf("generateCode - Node is list assign - constructor\n");
            #endif

            // nó da direita, que é uma lista, ainda não possui temporário
            // significa que ainda não foi gerada uma lista dinâmica para essa lista
            if(node->child[1]->sizeTemporary <= -1){
                tempInt = getNewTemporary();
                tempInt2 = getNewTemporary();

                setOperandSize(node->child[1], tempOperand1);

                // move o tamanho da lista para o temporário - em teoria, nesse caso é para sempre ser 0
                sprintf(tempCode, "mov $%d, %s", tempInt2, tempOperand1);
                createCode(tempCode);

                // incrementa o tamanho da lista
                sprintf(tempCode, "add $%d, $%d, 1", tempInt2, tempInt2);
                createCode(tempCode);

                // aloca memória dinamicamente para a lista (lista = tempInt, tamanho = tempInt2)
                sprintf(tempCode, "mema $%d, $%d", tempInt, tempInt2);
                createCode(tempCode);


            }
            // nó da direita, que é uma lista, já possui temporário
            // isso quer dizer que já existe uma lista dinâmica alocada para essa lista
            // deve alocar uma nova com o novo tamanho, transferir todo o conteúdo da anterior e desalocar a anterior
            else{

                // incrementa o tamanho da lista anterior
                setOperandSize(node->child[1], tempOperand1);
                // temporário novo para o tamanho novo
                tempInt2 = getNewTemporary();

                sprintf(tempCode, "add $%d, %s, 1", tempInt2, tempOperand1);
                createCode(tempCode);

                // aloca uma nova lista com o novo tamanho
                tempInt = getNewTemporary();

                sprintf(tempCode, "mema $%d, $%d", tempInt, tempInt2);
                createCode(tempCode);

                // monta o loop para trasnferir os elementos da lista antiga para a lista nova

                // tempInt3 = índice da lista antiga
                tempInt3 = getNewTemporary();
                // tempInt4 = flag para determinar se é necessário continuar o loop ou não
                tempInt4 = getNewTemporary();
                // tempInt5 = id da label gerada para o loop
                tempInt5 = getNewLabelId();
                // tempInt6 = temporário para mover os valores entre listas, pois é impossível mover diretamente
                // a instrução mov $0[$1], $2[$1] tem 4 operandos e não é suportada
                tempInt6 = getNewTemporary();
                // tempInt7 = índice da lista nova - não é possível usar o índice tempInt3 pois o índice da lista nova deve ser um elemento para a frente
                // após copiar a lista antiga, a posição 0 deve ser vazia para receber o novo elemento que está sendo inserido
                tempInt7 = getNewTemporary();

                // inicializa o índice da lista antiga
                sprintf(tempCode, "mov $%d, 0", tempInt3);
                createCode(tempCode);

                // inicializa o índice da lista nova
                sprintf(tempCode, "mov $%d, 1", tempInt7);
                createCode(tempCode);

                // gera o label do loop
                sprintf(tempCode, "list_loop_%d:", tempInt5);
                createCode(tempCode);

                // move o item da lista antiga para o temporário
                sprintf(tempCode, "mov $%d, $%d[$%d]", tempInt6, node->child[1]->assignedTemporary, tempInt3);
                createCode(tempCode);

                // move o item do temporário para a nova lista
                sprintf(tempCode, "mov $%d[$%d], $%d", tempInt, tempInt7, tempInt6);
                createCode(tempCode);

                // incrementa o índice da lista antiga
                sprintf(tempCode, "add $%d, $%d, 1", tempInt3, tempInt3);
                createCode(tempCode);

                // incrementa o índice da lista nova
                sprintf(tempCode, "add $%d, $%d, 1", tempInt7, tempInt7);
                createCode(tempCode);

                // verifica se deve parar o loop ou continuar - se o índice já passou do tamanho da lista antiga
                sprintf(tempCode, "slt $%d, $%d, $%d", tempInt4, tempInt3, node->child[1]->sizeTemporary);
                createCode(tempCode);

                // jump para continuar o loop
                sprintf(tempCode, "brnz list_loop_%d, $%d", tempInt5, tempInt4);
                createCode(tempCode);

                // libera a memória alocada para a lista antiga

                // finalizou o loop, pode atribuir o valor para a lista nova

            }


            // insere o valor novo na lista

            // decrementa de volta o tamanho da lista para acessar a última posição
            // sprintf(tempCode, "sub $%d, $%d, 1", tempInt2, tempInt2);
            // createCode(tempCode);

            // pega o valor que deve ser inserido dentro da lista
            setOperand(node->child[0], tempOperand2);

            // coloca o valor dentro da lista na última posição
            // sprintf(tempCode, "mov $%d[$%d], %s", tempInt, tempInt2, tempOperand2);
            // createCode(tempCode);

            // coloca o valor dentro da lista na primeira posição
            sprintf(tempCode, "mov $%d[0], %s", tempInt, tempOperand2);
            createCode(tempCode);

            // incrementa novamente o tamanho da lista que foi decrementado para acessar a última posição
            // sprintf(tempCode, "add $%d, $%d, 1", tempInt2, tempInt2);
            // createCode(tempCode);

            // adiciona os temporários da lista e do tamanho no nó
            addNodeTemporary(node, tempInt);
            addNodeSizeTemporary(node, tempInt2);



        }
        // map
        // else if(strcmp(node->sigla, "listMap") == 0){
        //     #ifdef DEBUG_CODEGEN
        //     printf("generateCode - Node is list map\n");
        //     #endif
        //
        //
        //
        // }
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
    int tempInt;

    if(node->assignedTemporary <= -2){
        // subexpressão não possui um temporário, ou seja, deve ser um elemento único (constante, por exemplo)
        if((strcmp(node->sigla, "id") == 0) || (strcmp(node->sigla, "assignOp") == 0)){
            // subexpressão é um id ou é uma atribuição (contém um símbolo)
            if(node->symbol->paramTemporary > -1){
                // o símbolo é um parâmetro sendo recebido, utilizar #
                sprintf(operand, "#%d", node->symbol->paramTemporary);
            }
            else{
                if((strcmp(node->symbol->type, "int list") == 0) || (strcmp(node->symbol->type, "float list") == 0)){
                    //  é um id do tipo lista, precisa verificar se já há um temporário que armazena essa lista
                    if(node->symbol->listTemporary > -1){
                        sprintf(operand, "$%d", node->symbol->listTemporary);
                    }
                    // não possui um temporário ainda, cria um
                    else{
                        tempInt = getNewTemporary();
                        addSymbolListTemporary(node->symbol, tempInt);
                        sprintf(operand, "$%d", node->symbol->listTemporary);
                    }

                }
                // não é uma lista
                else{
                    sprintf(operand, "%s_%d", node->symbol->name, node->symbol->scopeValue);
                }
            }
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


void setOperandSize(t_node* node, char* operand){
    if(node->sizeTemporary <= -2){
        // subexpressão não possui um tamanho temporário
        if(strcmp(node->sigla, "id") == 0){
            // subexpressão é um id
            sprintf(operand, "%s_size_%d", node->symbol->name, node->symbol->scopeValue);
        }
        // não possui temporário e não é id, coloca um tamanho inicial 0
        else{
            sprintf(operand, "0");
        }
        // else if(strncmp(node->sigla, "const", 5) == 0){
        //     // subexpressão é uma constante
        //     setOperandConstant(node, operand);
        // }
    }
    else{
        // subexpressão possui tamanho temporário, ou seja, é uma subxpressão já calculada
        sprintf(operand, "$%d", node->sizeTemporary);
    }

}


void setOperandConstant(t_node* node, char* operand){
    if(strncmp(node->sigla, "constNeg", 8) == 0){
        // negativa
        sprintf(operand, "-%s", node->value);
    }
    else if(strcmp(node->sigla, "constNull") == 0){
        // constante null
        sprintf(operand, "0");
    }
    else{
        // positiva
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

            // se for uma lista, cria uma símbolo para o tamanho da lista também
            if((strcmp(symbol->type, "int list") == 0) || (strcmp(symbol->type, "float list") == 0)){
                sprintf(temp, "int %s_size_%d = 0", symbol->name, symbol->scopeValue);
                createCode(temp);
            }

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

    free(tempFileName);

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

    if(FileName != NULL){
        free(FileName);
    }

    freeContext();
    freeCode();

}

void freeContext(){
    t_context* context;
    t_context* temp = NULL;

    context = TopContext;

    while(context != NULL){
        temp = context;
        context = context->next;
        if(temp != NULL){
            free(temp);
        }
    }
}

void freeCode(){
    t_code* codepointer;
    t_code* temp = NULL;

    codepointer = CodeList;

    while(codepointer != NULL){
        temp = codepointer;
        codepointer = codepointer->next;
        if(temp->code != NULL){
            free(temp->code);
        }
        if(temp != NULL){
            free(temp);
        }
    }


}
