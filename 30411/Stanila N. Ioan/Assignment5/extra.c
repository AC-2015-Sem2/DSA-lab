#include "extra.h"

void longestPath(int a, int b) {
    int** paths = allocateMatrixAndInitialise(a);
    int* nrPath = (int*)malloc(sizeof(int));
    *nrPath = 0;
    longestPathUtil(a, b, a, &paths, nrPath, 0);
    findMaxPath(paths);
}

void longestPathUtil(int a, int b, int c, int*** paths, int* nrPath, int level) {
    List* l = gotoVertex(c);
    if (c == b) {
        (*paths)[*nrPath][0] = level;
        *paths = addVertexToList(*paths, *nrPath, c);
    } else {
        while (l->content != NULL) {
            if (!alreadyThere(*paths, *nrPath, l->content->content)) {
                *paths = addVertexToList(*paths, *nrPath, l->content->content);
                longestPathUtil(a, b, l->content->content, paths, nrPath, level + 1);
                l->content = l->content->next;
            }
        }
    }

}

int** allocateMatrixAndInitialise(int val) {
    int** a = (int**)malloc((N + 1)*sizeof(int*));
    for (int i = 0; i < N - 1; i++)
        *(a + i) = (int*)malloc((N + 1)*sizeof(int));
    for (int i = 0; i < N + 1; i++)
        for (int j = 0; j < N - 1; j++)
            a[i][j] = -1;
    return a;
}

List* gotoVertex(int v) {
    List* l = adjList;
    int n = 0;
    while (n != v) {
        n++;
        l = l->next;
    }
    return l;
}

int** addVertexToList(int** a, int nrPath, int c) {
    for (int j = 1; j < N - 1; j++) {
        if (a[nrPath][j] == -1)
            a[nrPath][j] = c;
            break;
    }
    return a;
}

int alreadyThere(int** a, int nrPath, int c) {
    int exists;
    for (int i = 0; i < nrPath; i++) {
        exists = 1;
        for (int j = 1; j < N + 1 && a[nrPath][j - 1] != c; j++)
            if (a[nrPath][j] != a[i][j])
                exists = 0;
        if (exists == 1)
            break;
    }
    return exists;
}

void findMaxPath(int** a) {
    int max = -1, aux;
    for (int i = 0; i < N - 1; i++)
        if (max < a[i][0]) {
            max = a[i][0];
            aux = i;
        }
    for (int i = 0; i < max + 1; i++)
        printf("%d ", a[aux][i]);
}