#include "graph.h"
typedef struct adjListNode {
int node;
struct adjListNode* next;
struct adjListNeighbor* neighbor;} adjListNodeT;

typedef struct adjListNeighbor{
int node,weight;
struct adjListNeighbor* next;} adjListNeighborT;

void readFromAdjMatrix(FILE * f);
void printAdjMatrix();
void listToMatrix();
void matrixToList();
int getNumberOfNeighborsOfVertex(int v);
int * getAllNeighborsOfVertex(int v);

adjListNodeT* firstNode;
