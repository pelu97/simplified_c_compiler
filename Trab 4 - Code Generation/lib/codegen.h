

typedef struct Code{
    char* code;
    struct Code* next;
    struct Code* prev;
} t_code;

typedef struct Context{
    int contextId;
    int lastTemporary;
    struct Context *next;
} t_context;

extern char* FileName;
extern int lastContextId;
extern int labelCounter;

extern t_code* CodeList;
extern t_code* lastCode;
extern t_context* TopContext;


t_code* createCode(char* code);

void generateCode(t_node* node);

void setOperand(t_node* node, char* operand);

void setOperandSize(t_node* node, char* operand);

void setOperandConstant(t_node* node, char* operand);

void assembleCode(t_node* node);

void setFileName(char* filename);

t_context* pushContext();

void popContext();

t_context* getContext();

int getNewTemporary();

int getLastTemporary();

int getNewLabelId();

void printCode();

void assembleTable();

void writeFile();

void codeGeneration();
