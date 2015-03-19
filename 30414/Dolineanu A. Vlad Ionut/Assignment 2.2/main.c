#include <stdio.h>
#include <stdlib.h>
#include "queueFunctions.h"
#include "listFunctions.h"

int main()
{
    FILE* f = fopen("input.dat", "r");
    FILE* g = fopen("output.dat", "w");

    initList();
    initQueue();

    int aux;
    while(fscanf(f, "%d", &aux) > 0)
        addToList(aux);

    char *auxName = (char*)malloc(sizeof(char));
    int auxMoney, auxTime;

    while(fscanf(f, "%s", auxName) > 0)
    {
        fscanf(f, "%d", &auxMoney);
        fscanf(f, "%d", &auxTime);
        enqueue(auxName, auxMoney, auxTime);
    }

    lNode* templNode = alloclNode();
    templNode = list->head;

    while(templNode != NULL)
    {
        int currentTime = templNode->data;
        Node* tempNode = allocNode();
        tempNode = peek();
        int totalMoney = 0;
        do
        {
            if(currentTime >= tempNode->y)
            {
                currentTime -= tempNode->y;
                totalMoney += tempNode->x;
                if(tempNode->next != NULL)
                    tempNode = tempNode->next;
                else
                    currentTime = -1;
            }
            else
                currentTime = -1;
        }while(currentTime>0);

        fprintf(g, "%d\n", totalMoney);
        templNode = templNode->next;
    }

    fclose(f);
    fclose(g);
    return 0;
}
