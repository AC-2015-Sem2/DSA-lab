#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

NodeT ** adjArray;
int n;
NodeT** constructAdjList(FILE * f,int * n);
int longestPath(int v, int u);
