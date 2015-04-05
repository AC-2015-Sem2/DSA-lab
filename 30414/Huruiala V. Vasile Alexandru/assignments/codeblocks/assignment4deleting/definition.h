#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define INPUT_FILE1 "input1.dat"
#define INPUT_FILE2 "input2.dat"
#define OUTPUT_FILE "output.dat"
#define MAX_NR_LENGTH 10

typedef struct st_BTree BTree;
struct st_BTree
{
    BTree* left;
    BTree* right;
    //Max depth of subtrees
    int Lweight;
    int Rweight;

    void* data;
};
