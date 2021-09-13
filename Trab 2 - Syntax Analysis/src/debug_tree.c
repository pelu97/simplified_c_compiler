#include <stdio.h>
#include "../lib/tree.h"


int main(){
    t_node* nodes[5];
    int i, j;

    for(i=0; i<5; i++){
        nodes[i] = NULL;
    }

    nodes[0] = createNode("Node 1");

    initializeTree(nodes[0]);

    nodes[1] = createNode("Node 2");
    nodes[2] = createNode("Node 3");


    addChild(nodes[0], 1);

    addChild(nodes[1], 1);

    nodes[0]->child[0] = nodes[1];

    nodes[1]->child[0] = nodes[2];



    for(i=0; nodes[i]!=NULL; i++){
        printf("Nó %d: %s\n", i, nodes[i]->name);

        if(nodes[i]->child != NULL){
            for(j=0; nodes[i]->child[j]!=NULL; j++){
                printf("Filho %d: %s\n", i, nodes[i]->child[j]->name);
            }
        }
    }

    // printBranch(nodes[0], 0);

    printTree();






    return 0;
}
