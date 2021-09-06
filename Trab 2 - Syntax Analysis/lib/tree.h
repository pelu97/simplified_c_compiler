





typedef struct Node{
    char* name;
    struct Node** child;
} t_node;


extern t_node* TreeRoot;


t_node* createNode(char* name);

void addChild(t_node* node, int n);

void printTree();

void printBranch();
