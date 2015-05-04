#include "node.h"

void push(node** head, int data)
{
    node* NewNode = createNode(data);
    if(*head == NULL)
    {
        *head = NewNode;
    }
    else
    {
        NewNode->next = *head;
        *head = NewNode;
    }
}

void pop(node** head)
{
    if(*head != NULL)
    {
        node* del = *head;
        *head = (*head)->next;
        del->data = 0;
        del->next = NULL;
        free(del);
    }
}
