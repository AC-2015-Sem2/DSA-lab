#include "functions.h"

#include <stdlib.h>
#include <string.h>

FILE* openFile(char* s) {
    FILE* f = fopen(s, "r");
    if (f == NULL) {
        perror(s);
        exit(1);
    }
    return f;
}

Queue* createQueue(FILE* f) {
    Queue* q = NULL;
    char line[101]; //= (char*)malloc(LINE_SIZE*sizeof(char));
    fscanf(f, " %[^\n]s ", line);
    char* tline = strtok(line, " ");
    while (tline != NULL) {
        enqueue(&q, tline);
        tline = strtok(NULL, " ");
    }
    //free(line);
    return q;
}

Tree* buildBinaryTree(Queue** q) {
    Tree* t = NULL;
    if (strcmp((*q)->val, "+") && strcmp((*q)->val, "-") && strcmp((*q)->val, "*") && strcmp((*q)->val, "/")) {
            t = createNode((*q)->val);
            dequeue(q);
            return t;
    } else {
            t = createNode((*q)->val);
            dequeue(q);
            t->left = buildBinaryTree(q);
            t->right = buildBinaryTree(q);
    }
    return t;
}