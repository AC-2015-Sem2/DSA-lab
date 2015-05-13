# include "header.h"

typedef struct e
{
    int source, dest;
    struct e *next;
}edgeT;

edgeT *firstEdge, *lastEdge;

void removeEdge(int);
void addAnEdge(int, int);
edgeT *createEdge(int, int);
void printEdges();
int getNrOfEdges();
int hasOther

