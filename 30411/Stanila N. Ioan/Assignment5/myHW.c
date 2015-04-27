#include "myHW.h"

List* createListFromMatrix() {
    List* l = NULL;
    for (int i = 0; i < nrOfVerteces; i++)
        addElement(&l);
    List* aul = l; //create iterator
    int i = 0;
    do {
        for (int j = 0; j < nrOfVerteces; j++)
            if (adjMatrix[i][j] != 0)
                addContentForElement(&aul, j);
        aul = aul->next;
        i++;
    } while (i < nrOfVerteces);
    return l;
}

int** createMatrixFromList(List* l) {
    int** a = (int**)malloc(nrOfVerteces*sizeof(int*));
    int i = 0;
    while (l != NULL) {
        *(a + i) = (int*)malloc(nrOfVerteces*sizeof(int));
        for (int j = 0; j < nrOfVerteces; j++)
            a[i][j] = 0;
        NodeT* n = l->content;
        while (n != NULL) {
            a[i][n->content] = 1;
            n = n->next;
        }
        i++;
        l = l->next;
    }
    return a;
}

int LISTgetNumberOfNeighborsOfVertex(int v)
{
    List* l = adjList;
    int n = 0;
    int i = 0;
    while (v + 1 != i) {
        if (v == i) {
            NodeT* nod = l->content;
            while (nod != NULL) {
                n++;
                nod = nod->next;
            }
        }
        l = l->next;
        i++;
    }
    return n;
}

int * LISTgetAllNeighborsOfVertex(int v)
{
    int n = LISTgetNumberOfNeighborsOfVertex(v);
    int* neighbors = (int*)malloc((n + 1)*sizeof(int));
    int k = 0;
    int i = 0;
    List* l = adjList;
    while (v + 1 != i) {
        if (v == i) {
            NodeT* nod = l->content;
            while (nod != NULL) {
                neighbors[k] = nod->content;
                k++;
                nod = nod->next;
            }
        }
        l = l->next;
        i++;
    }
    return neighbors;
}