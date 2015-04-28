#ifndef ADJLIST_H_INCLUDED
#define ADJLIST_H_INCLUDED
typedef struct edge
{
    int vertexIndex;
    struct edge *edgePointer;
}edge;

typedef struct vertex
{
    int vertexKey;
    struct edge *edgePointer;
}vertex;
int  adjMatrix[20][20];
int n;
int nrOfVerteces;
vertex graph[10];
int vertexCount;
int b[20][20];
void readFromAdjMatrix(FILE * f);
void InsertVertex(int vertexKey);
void insertEdge(int vertex1, int vertex2);
void insertAllVert();
void insertAllEdges();
void fromAdjMatrixToAdjList();
void fromAdjListToAdjMatrix();
void printGraph();
void printmatrix();
void printAdjMatrix();


#endif // ADJLIST_H_INCLUDED
