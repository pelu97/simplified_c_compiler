#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/tree.h"
#include "../lib/base.h"




t_node* TreeRoot = NULL;


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

    node->name = (char*) malloc(1);
    node->empty = 1;

    #ifdef DEBUG
    printf("Node creation - allocated memory\n");
    #endif

    strcpy(node->name, "");

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

    temp = (t_node**) realloc(node->child, (sizeof(t_node*) * (n + 1)));

    if(temp != NULL){
        node->child = temp;

        // aloca um filho a mais e seta ele para nulo, para saber quando acabaram os filhos
        node->child[n] = NULL;
    }
    else{
        printf("Fatal error on memory allocation for child nodes\n");
    }
}



void printTree(){

    #ifdef DEBUG
    printf("Printing tree\n");
    #endif

    printBranch(TreeRoot, 0);

}

void printBranch(t_node* node, int level){
    int i;

    #ifdef DEBUG
    printf("Printing branch %s- level %d\n", node->name, level);
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
