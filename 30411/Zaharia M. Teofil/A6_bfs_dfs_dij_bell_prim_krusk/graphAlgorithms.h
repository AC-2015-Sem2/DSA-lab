#include "graph.h"

void prim(int startNode);
void kruskal();
void dijkstra(int startNode);

void bellman(int startNode);
int hasNegativeEdgeCycles(int* distance);
void reconstructPaths(int startNode, int* parent, int* distance);
