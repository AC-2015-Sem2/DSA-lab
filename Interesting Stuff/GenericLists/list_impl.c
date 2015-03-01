#include "list_h.h"

void addFirst(void * data)
{
    node * newNode = createNode(data);
    if(head == NULL)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

}

void printList(){

    node * aux = head;
    while(aux != NULL){
        printBasedOnType(aux->data);
        aux=aux->next;
    }

}
// TODO: change only this function in your program based on
// what you want to print
//      -> in our case, it's a simple integer
// could you in any way check what type the data parameter is?
//      -> if yes, how?
//      -> if no, why not?
void printBasedOnType(void * data){
    printf("%d ", (int)data);
}

node * createNode(void * data)
{

    node * newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = data;

    return newNode;

}
