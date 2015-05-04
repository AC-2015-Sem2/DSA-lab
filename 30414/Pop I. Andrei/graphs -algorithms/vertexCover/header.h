# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct e
{
    int source, dest;
    struct e *next;
}edgeT;

int ** adjMatrix;
int nrOfVerteces;

void vertexCover();
void readFromAdjMatrix(FILE *);
void getTheEdges(int **);

edgeT *firstEdge, *lastEdge;

void removeEdges(int);
void addAnEdge(int, int);
edgeT *createEdge(int, int);
void printEdges();
int getNrOfEdges();
int hasOtherAdjacentEdges(int);

