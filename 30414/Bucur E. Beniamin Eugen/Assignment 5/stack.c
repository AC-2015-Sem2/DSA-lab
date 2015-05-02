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

int peekStack()
{
    return stack->content;
}

int isEmptyStack(){
    return stack == NULL;
}

//! auxiliary
void printStack()
{
    NodeT * aux=stack;
    while(aux!=NULL)
    {
        printf("%d ",aux->content );
        aux=aux->next;
    }
    printf("\n");
}
