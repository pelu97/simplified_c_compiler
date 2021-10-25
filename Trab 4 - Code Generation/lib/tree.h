#include "../lib/symbol_table.h"

#ifndef NODETYPE
#define NODETYPE
typedef struct Node{
    char* name;
    char* sigla;
    int empty;
    struct Node** child;
    char* type;
    char* functionName;
    int line;
    int column;
    char* id;
    char* value;
    t_symbol* symbol;
    int assignedTemporary;
    // char* logicOperator;
} t_node;
#endif

#define CAST_INT_FLOAT 1

#define CAST_FLOAT_INT 2

#define CAST_NIL_INTLIST 3

#define CAST_NIL_FLOATLIST 4


extern t_node* TreeRoot;
extern char *lastFuncDeclared;


t_node* createNode(char* name, char* sigla);

void overrideNode(t_node* node, char* name, char* sigla);

t_node* createEmptyNode();

void addNodeType(t_node* node, char* type);

void addNodeTypeChildren(t_node* node);

void addNodeTypeId(t_node* node, char* id);

void addTypeCastNode(t_node* node, int child, int castType);

void addFunctionName(t_node* node, char* function);

void updateLastFunc(char* name);

void addNodePosition(t_node* node, int line, int column);

void addNodeId(t_node* node, char* id);

void addNodeSymbol(t_node* node, t_symbol* symbol);

void addNodeValue(t_node* node, char* value);

// void addNodeOperator(t_node* node, char* logicOperator);

void addNodeTemporary(t_node* node, int temporary);

void initializeTree(t_node* node);

void addChild(t_node* node, int n);

void printTree();

void printBranch(t_node* node, int level);

void printBranch2(t_node* node, int level, char* prevNode);

void printBranch3(t_node* node, int level, char* prevNode);

void freeTree();

int freeBranch();
