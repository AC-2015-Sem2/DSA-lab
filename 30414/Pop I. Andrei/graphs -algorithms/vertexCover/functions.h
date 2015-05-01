# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

int ** adjMatrix;
int nrOfVerteces;

typedef struct e
{
    int source, dest;
}edgeT;

void vertexCover();


#endif // FUNCTIONS_H_INCLUDED
