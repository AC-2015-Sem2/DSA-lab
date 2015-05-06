typedef struct st_edge edge;
struct st_edge
{
    int source;
    int destination;
    int weight;
};
void initRand();
int getRand(int min, int max);
int noOfEdges(int** adjMat, int size);
int** getCopyOfAdjecencyMatrix(int** adjMat, int size);
edge extractMinEdge(int** adjMat, int size);
int adjMatIsEmpty(int** adjMat, int size);
edge extractEdgeAndCutAllIncidentEdges(int** adjMat, int size, int arbNumber);
