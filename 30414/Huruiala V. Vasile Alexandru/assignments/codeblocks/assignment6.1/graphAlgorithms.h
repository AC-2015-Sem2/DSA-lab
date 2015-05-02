#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct st_edge edge;
struct st_edge
{
    int source;
    int destination;
    int weight;
};

void kruskal(int** adjMat, int size);
void bellman_ford(int** adjMat, int size, int startingNode);
