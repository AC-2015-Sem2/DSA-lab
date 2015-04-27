#include "stack.h"

void push(int code)
{
    if(stack==NULL)
    {
        stack=createNode(code);
    }
    else
    {
        NodeT *auxNode=createNode(code);
        auxNode->next=stack;
        stack=auxNode;
    }
}

void pop()
{
    if(stack!=NULL)
    {
        NodeT *aux;
        aux=stack;
        stack=stack->next;
        free(aux);
    }
}

NodeT *peekStack()
{
    return stack;
}

int isEmptyStack()
{
    return (stack==NULL);
}
