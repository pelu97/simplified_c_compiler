#include <stdlib.h>


typedef struct Scope {
    int scopeValue;
    int parentScope;
    struct Scope* next;
} t_scope;


extern t_scope* ScopeStack;
extern t_scope* topScope;
extern int lastScopeValue;

void pushScope(int value, int parentScope);

int popScope();

int checkScope();

t_scope* getScope();

void freeScopeToken(t_scope* scope);

void freeScope();
