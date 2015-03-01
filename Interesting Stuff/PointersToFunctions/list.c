#include "list.h"

void addFirst(void * data)
{
    node * newNode = createNode(data);
    if(listObj->head == NULL)
    {
        listObj->head = newNode;
        listObj->tail = listObj->head;
    }
    else
    {
        newNode->next = listObj->head;
        listObj->head = newNode;
    }
    listObj->length++;
}

void printListV1(){
    node * aux = listObj->head;
    printf("Printing function: V1!\n");
    printf("List length=%d\n",listObj->length);
    while(aux != NULL){
        printf("%d ", (int)aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void printListV2(){
    node * aux = listObj->head;
    printf("Printing function: V2!\n");
    printf("List length=%d\n",listObj->length);
    while(aux != NULL){
        printf("%d ", (int)aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void initList(){
    listObj = (listT*)malloc(sizeof(listT));
    listObj->head = NULL;
    listObj->addFirst = &addFirst;
    listObj->length = 0;
}

void setPrintFunctionToV1(){
    listObj->printList = &printListV1;
}

void setPrintFunctionToV2(){
    listObj->printList = &printListV2;
}

node * createNode(void * data)
{

    node * newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = data;

    return newNode;

}
