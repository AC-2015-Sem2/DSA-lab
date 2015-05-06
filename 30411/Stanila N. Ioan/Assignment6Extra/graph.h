#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <stdio.h>

#include "edge.h"

struct graph {
    int** a;
    int n;
};

struct graph* getGraph(FILE* f);
void printMatrixOfGraph(struct graph);

struct edge* getAllEdgesFromGraph(struct graph g);
int getNumberOfEdgesOfGraph(struct graph g);

void vertexCover(struct graph g);

#endif // GRAPH_H_INCLUDED
