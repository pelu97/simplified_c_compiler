#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/tree.h"
#include "../lib/base.h"




t_node* TreeRoot = NULL;
int nodesBuilt;

t_node* createNode(char* name){
    t_node* node;

    #ifdef DEBUG
    printf("Node creation - memory needed for %s: %d\n", name, strlen(name));
    #endif

    node = (t_node*) malloc(sizeof(t_node));

    node->name = (char*) malloc(strlen(name) + 1);
    node->empty = 0;

    #ifdef DEBUG
    printf("Node creation - allocated memory\n");
    #endif

    strcpy(node->name, name);

    #ifdef DEBUG
    printf("Node creation - copied name\n");
    #endif

    node->child = NULL;

    return node;
}

t_node* createEmptyNode(){
    t_node* node;

    #ifdef DEBUG
    printf("Node creation - empty node\n");
    #endif

    node = (t_node*) malloc(sizeof(t_node));

    node->name = (char*) malloc(3);
    node->empty = 1;

    #ifdef DEBUG
    printf("Node creation - allocated memory\n");
    #endif

    strcpy(node->name, " ");

    #ifdef DEBUG
    printf("Node creation - copied name\n");
    #endif

    node->child = NULL;

    return node;
}

void initializeTree(t_node* node){

    TreeRoot = node;

    #ifdef DEBUG
    printf("Tree initialized\n");
    #endif
}

void addChild(t_node* node, int n){
    t_node** temp;
    t_node** temp_old;

    temp = (t_node**) realloc(node->child, (sizeof(t_node*) * (n + 1)));

    if(temp != NULL){
        temp_old = node->child;
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

    #ifdef DEBUG
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

    #ifdef DEBUG
    printf("%d nodes in tree\n", nodesBuilt);
    #endif

}

void printBranch(t_node* node, int level){
    int i;

    #ifdef DEBUG
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
            #ifdef DEBUG
            printf("Printing children of node %s\n", node->name);
            #endif
            for(i=0; node->child[i] != NULL; i++){
                #ifdef DEBUG
                printf("Printing child %d of node %s\n", i, node->name);
                #endif
                printBranch(node->child[i], level+1);
            }
        }
    }
}

void printBranch2(t_node* node, int level, char* prevNode){
    int i;

    #ifdef DEBUG
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
            #ifdef DEBUG
            printf("Printing children of node %s\n", node->name);
            #endif
            for(i=0; node->child[i] != NULL; i++){
                #ifdef DEBUG
                printf("Printing child %d of node %s\n", i, node->name);
                #endif
                printBranch2(node->child[i], level+1, node->name);
            }
        }
    }
}

void printBranch3(t_node* node, int level, char* prevNode){
    int i, aux;

    #ifdef DEBUG
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
                aux = 7;
                // printf("FORMATTED NODE\n");
            }
            else{
                aux = -2;
            }
            printf("%s%*s│\n", node->name, (110 - (level*4) - strlen(node->name) + aux), " ");
        }
        else{
            level--;
        }

        if(node->child != NULL){
            #ifdef DEBUG
            printf("Printing children of node %s\n", node->name);
            #endif
            for(i=0; node->child[i] != NULL; i++){
                #ifdef DEBUG
                printf("Printing child %d of node %s\n", i, node->name);
                #endif
                printBranch3(node->child[i], level+1, node->name);
            }
        }
    }
}

void freeTree(){
    int i;

    i = freeBranch(TreeRoot);

    #ifdef DEBUG
    printf("Freed %d nodes from tree\n", i);
    #endif
}

int freeBranch(t_node* node){
    int i, freed;

    freed = 0;

    #ifdef DEBUG
    printf("Freeing branch %s\n", node->name);
    #endif


    if(node->child != NULL){
        #ifdef DEBUG
        printf("Freeing children of node %s\n", node->name);
        #endif
        for(i=0; node->child[i] != NULL; i++){
            freed = freed + freeBranch(node->child[i]);
        }
    }
    if(node->name != NULL){
        free(node->name);   //libera memória alocada para o nome
    }

    if(node->child != NULL){
        free(node->child);  //libera memória alocada para o vetor de filhos
    }

    if(node != NULL){
        free(node);     //libera memória alocada para o nó
    }

    return freed + 1;
}
