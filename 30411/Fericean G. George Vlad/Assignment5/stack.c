#include "stack.h"

void push(int content)
{
    NodeT * newH = createNode(content);
    newH->next = stack;
    stack = newH;
}

void pop()
{
    if(stack!=NULL){
        stack=stack->next;
    }
}

NodeT * peekStack()
{
    return stack;
}

int isEmptyStack(){
    return stack == NULL;
}
void printStack()
{
    NodeT * aux=stack;
    while(aux!=NULL)
    {
        printf("%d ",aux->data );
        aux=aux->next;
    }
    printf("\n");
}
