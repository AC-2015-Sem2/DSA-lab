#include <stdlib.h>
typedef struct st_node node;
struct st_node
{
    int data;
    node* next;
};

node* createNode(int data);
