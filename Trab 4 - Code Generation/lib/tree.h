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
} t_node;
#endif

#define CAST_INT_FLOAT 1

#define CAST_FLOAT_INT 2

#define CAST_NIL_INTLIST 3

#define CAST_NIL_FLOATLIST 4


extern t_node* TreeRoot;
extern char *lastFuncDeclared;


t_node* createNode(char* name, char* sigla);

void overrideNode(t_node* node, char* name);

t_node* createEmptyNode();

void addNodeType(t_node* node, char* type);

void addNodeTypeChildren(t_node* node);

void addNodeTypeId(t_node* node, char* id);

void addTypeCastNode(t_node* node, int child, int castType);

void addFunctionName(t_node* node, char* function);

void updateLastFunc(char* name);

void addNodePosition(t_node* node, int line, int column);

void addNodeId(t_node* node, char* id);

void initializeTree(t_node* node);

void addChild(t_node* node, int n);

void printTree();

void printBranch(t_node* node, int level);

void printBranch2(t_node* node, int level, char* prevNode);

void printBranch3(t_node* node, int level, char* prevNode);

void freeTree();

int freeBranch();
