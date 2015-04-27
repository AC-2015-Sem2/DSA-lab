#include "stack.h"

void push(int content)
{
    nodeT * newH = create(content);
    newH->next = stack;
    stack = newH;
}

void pop()
{
    if(stack!=NULL){
        stack=stack->next;
    }
}

nodeT * peekStack()
{
    return stack;
}

int isEmptyStack(){
    return stack == NULL;
}

//! auxiliary
void printStack()
{
    nodeT * aux=stack;
    while(aux!=NULL)
    {
        printf("%d ",aux->code );
        aux=aux->next;
    }
    printf("\n");
}
