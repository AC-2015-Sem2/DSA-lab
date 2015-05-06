#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "queue.h"
#include "edge.h"

#define UNVISITED 0
#define VISITED 1
#define MAX 9999
#define UNDEFINED -1

int ** adjMatrix;
int nrOfVerteces;
