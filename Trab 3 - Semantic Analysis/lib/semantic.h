#include "../lib/base.h"
#include "../lib/tree.h"



typedef struct semanticErrors{
    char* type;
    char* message;
    char* error_text;
    int line;
    int column;
} t_semerror;

typedef struct typesTemporary{
    char* type;
    int line;
    int column;
} t_typeTemp;


extern t_semerror** semanticErrors;
extern int semanticErrorsTotal;

void addError(char* type, char* message, char* error_text, int line, int column);

void printErrors();

// check existence of main function
int checkMain();

// void functionPass(t_symbol* functionPointer);

void checkFunctions();

void checkFunctionCall(t_node* node);

// int getFunctionCallParameters(t_node* node, int index, char*** types);

int getFunctionCallParameters(t_node* node, int index, t_typeTemp*** types);

// char** addTempType(char** types, char* type, int index);

t_typeTemp** addTempType(t_typeTemp** types, char* type, int index, int line, int position);

// void checkIdDeclaration(char* id);

void checkIdDeclaration(t_node* node);

void semanticAnalysis();
