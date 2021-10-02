#include "../lib/base.h"
#include "../lib/tree.h"



typedef struct semanticErrors{
    char* type;
    char* message;
    int line;
    int column;
} t_semerror;


extern t_semerror** semanticErrors;
extern int semanticErrorsTotal;

void addError(char* type, char* message, int line, int column);

void printErrors();

// check existence of main function
int checkMain();

// void functionPass(t_symbol* functionPointer);

void checkFunctions();

void checkFunctionCall(t_node* node);

int getFunctionCallParameters(t_node* node, int index, char*** types);

char** addTempType(char** types, char* type, int index);

void checkIdDeclaration(char* id);

void semanticAnalysis();
