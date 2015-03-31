#include <stdio.h>
#include <stdlib.h>
#include <strings.h> // strcmp, strcpy, atof
#include <ctype.h> // isdigit

typedef struct  node
{
    char        data[20];
    struct node *left;
    struct node *right;
}               NodeT;
NodeT *radacina;


NodeT *createNode(char *a)
{
    NodeT *nod;

    nod = (NodeT*)malloc(sizeof(NodeT));
    nod->left = NULL;
    nod->right = NULL;
    strcpy(nod->data,a);
    return nod;
}

NodeT *createBinTree(FILE *in)
{
    NodeT   *p;
    char    *data = (char*)malloc(sizeof(char) * 20);

    fscanf(in, "%s", data);
    if (isdigit(data[0]) || isdigit(data[1]))
    {
        p = createNode(data);
        p->left = NULL;
        p->right = NULL;
    }
    else
    {
        p = createNode(data);
        p->left = createBinTree(in);
        p->right = createBinTree(in);
    }
    return p;
}

float compute(NodeT *n)
{
    if (!strcmp("+",n->data))
        return (compute(n->left) + compute(n->right));
    else if (!strcmp("-",n->data))
        return (compute(n->left) - compute(n->right));
    else if (!strcmp("*",n->data))
        return (compute(n->left) * compute(n->right));
    else if (!strcmp("/",n->data))
        return (compute(n->left) / compute(n->right));
    else
        return (atof(n->data));
}

int main()
{
    FILE    *in;

    in = fopen ("input.dat", "r");
    radacina = createBinTree(in);
    printf ("%f", compute(radacina));
    return 0;
}
