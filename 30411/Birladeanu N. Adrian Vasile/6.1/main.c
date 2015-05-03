#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"
//Daca moare da-i build&run inca o data(din 10 incercari una trebuie sa mearga). Kruskal are un bug care face ca
//uneori sa nu mearga cum trebuie si nu mi-am dat seama care e problema. SI NU E O GLUMA.
int main()
{
    FILE * f1 = fopen("matrix.txt","r");
    readFromAdjMatrix(f1);
    printAdjMatrix();
    //bfs(0);
    //dfs(0);
    //dfsRecurs(0);
    printf("\n");
    kruskal();
    printf("\n");
    prim(0);
    printf("\n");
    bellmanFord();
    printf("\n");
    return 0;
}
