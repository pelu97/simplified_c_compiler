





typedef struct Node{
    char* name;
    int empty;
    struct Node** child;
} t_node;


extern t_node* TreeRoot;


t_node* createNode(char* name);

t_node* createEmptyNode();

void initializeTree(t_node* node);

void addChild(t_node* node, int n);

void printTree();

void printBranch(t_node* node, int level);
