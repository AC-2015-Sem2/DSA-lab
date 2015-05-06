#include "graph.h"

#include <stdlib.h>

struct graph* getGraph(FILE* f) {
    struct graph g;
    fscanf(f, "%d", &(g.n));
    g.a = (int**)malloc(g.n*sizeof(int*));
    for (int i = 0; i < g.n; i++) {
        *(g.a + i) = (int*)malloc(g.n*sizeof(int));
        for (int j = 0; j < g.n; j++)
            fscanf(f, "%d", &g.a[i][j]);
    }
    struct graph* gp = (struct graph*)malloc(sizeof(struct graph));
    *gp = g;
    return gp;
}

void printMatrixOfGraph(struct graph g) {
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++)
            printf("%d ", g.a[i][j]);
        printf("\n");
    }
    printf("\n");
}

struct edge* getAllEdgesFromGraph(struct graph g) {
    int ne = getNumberOfEdgesOfGraph(g);
    struct edge* ve = (struct edge*)malloc(ne*sizeof(struct edge));
    int k = 0;
    for (int i = 0; i < g.n - 1; i++)
        for (int j = i + 1; j < g.n; j++)
            if (g.a[i][j] > 0) {
                ve[k].u = i;
                ve[k].v = j;
                k++;
            }
    return ve;
}

int getNumberOfEdgesOfGraph(struct graph g) {
    int n = 0;
    for (int i = 0; i < g.n - 1; i++)
        for (int j = i + 1; j < g.n; j++)
            if (g.a[i][j] > 0)
                n++;
    return n;
}

int inVector(int* v, int n, int x) {
    for (int i = 0; i < n; i++)
        if (v[i] == x)
            return 1;
    return 0;
}

int* findDegreeOfVerteces(struct graph g) {
    int* deg = (int*)malloc(g.n*sizeof(int));
    for (int i = 0; i < g.n; i++) {
        int it = 0;
        for (int j = 0; j < g.n; j++) {
            if (g.a[i][j] > 0)
                it++;
        }
        deg[i] = it;
    }
    return deg;
}

int maxVertex(int* deg, int n) {
    int max = 0;
    int x;
    for (int i = 0; i < n; i++) {
        if (deg[i] > max) {
            x = i;
            max = deg[i];
        }
    }
    return x;
}

struct edge* orderEdges(int* deg, struct edge* e, int en, int n) {
    struct edge* ev = (struct edge*)malloc(en*sizeof(struct edge));
    int k = 0;
    for (int i = 0; i < n; i++) {
        int x = maxVertex(deg, n);
        for (int j = 0; j < en; j++) {
            if (e[j].u == x) {
                ev[k] = e[j];
                e[j].u = -1;
                e[j].v = -1;
                k++;
            } else if (e[j].v == x) {
                ev[k].u = e[j].v;
                ev[k].v = e[j].u;
                e[j].u = -1;
                e[j].v = -1;
                k++;
            }
        }
        deg[x] = -1;
    }
    return ev;
}

void vertexCover(struct graph g) {
    int en = getNumberOfEdgesOfGraph(g);
    struct edge* ev = getAllEdgesFromGraph(g);
    int* deg = findDegreeOfVerteces(g);
    ev = orderEdges(deg, ev, en, g.n);
    int nrOfVerteces = 0;
    int vertexVector[nrOfVerteces];
    int complete = 0;
    int i = 0;
    while(!complete && i < en) {
        if (!inVector(vertexVector, nrOfVerteces, ev[i].u)) {
            vertexVector[nrOfVerteces] = ev[i].u;
            nrOfVerteces++;
        }
        if (g.n == nrOfVerteces)
            complete = 1;
        i++;
    }
    for (int i = 0; i < nrOfVerteces; i++)
        printf("%d ", vertexVector[i]);
}