struct AdjListNode* newAdjListNode(int dest);
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
int** getMatrix(FILE * f,int n);
int** createAdjMatFromList(struct Graph *graph, int n);
void printMatrix (int** adjMatrix,int n);
