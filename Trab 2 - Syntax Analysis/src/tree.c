#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/tree.h"





t_node* TreeRoot = NULL;


t_node* createNode(char* name){
    t_node* node;

    node = (t_node*) malloc(sizeof(t_node));

    node->name = (char*) malloc(sizeof(name) + 1);

    strcpy(node->name, name);

    node->child = NULL;

    return node;
}

void addChild(t_node* node, int n){
    t_node** temp;

    temp = (t_node**) realloc(node->child, (sizeof(t_node*) * n));

    if(temp != NULL){
        node->child = temp;
    }
    else{
        printf("Fatal error on memory allocation for child nodes\n");
    }
}



void printTree(){
    t_node* node;
    int i;

    // node = TreeRoot;

    printBranch(TreeRoot);

}

void printBranch(t_node* node){
    int i;

    printf("%s\n", node->name);

    if(node->child != NULL){
        for(i=0; node->child[i] != NULL; i++){
            printBranch(node->child[i]);
        }
    }
}
