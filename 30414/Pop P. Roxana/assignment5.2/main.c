#include "graph.h"

int main()
{
    FILE * f=fopen("adjList.dat","r");
    if (f==NULL) perror("Couldn't open input file\n");
    adjArray=constructAdjList(f,&n);
    int u=3,v=5;
    printf("\nThe longest path between %d and %d is %d\n",u,v,longestPath(u,v));
    return 0;
}
