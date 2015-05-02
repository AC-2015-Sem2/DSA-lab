#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "T_t_DLL_Def.h"
#include "listFunctions.h"

NodeL* addLast(NodeL** tail, char* data){
    NodeL* node = (NodeL*)malloc(sizeof(NodeL));
    node->data = (char*)malloc(strlen(data));
    strcpy(node->data, data);
    if (*tail!=NULL){
    (*tail)->next = node;
    }
    node->prev = *tail;
    *tail = node;
    return node;
}

char* delFirst(NodeL** head){
    char* toRet = (char*)malloc(strlen((*head)->data));
    toRet = (*head)->data;
    *head = (*head)->next;
    return toRet;
}

void traverseList(NodeL* head)
{
    while (head!=NULL)
    {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}
