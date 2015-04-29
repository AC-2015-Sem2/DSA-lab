
int ** adjMatrix;
void printAdjMatrix();
void readFromAdjMatrix(FILE * f);
int getNumberOfNeighborsOfVertexFromMatrix(int v);
int * getAllNeighborsOfVertexFromMatrix(int v);

void bfsMatrix(int searchNode);
void dfsMatrix(int searchNode);
