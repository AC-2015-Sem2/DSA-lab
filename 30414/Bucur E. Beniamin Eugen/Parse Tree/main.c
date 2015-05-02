#include <stdio.h>
#include <stdlib.h>
#include <strings.h> // strcmp, strcpy, atof
#include <ctype.h> // isdigit
#include <conio.h> // getch

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

void prettyPrint(NodeT *root,int recLevel) //! root, index, length, reccurence level
{
    if(root==NULL)
    {
        recLevel--; //! reached leaf, must decrement recurence level
        return;
    }
    recLevel++; //! otherwise increment it
    prettyPrint(root->right,recLevel); //! keep going right in the tree
    int j=0;

    //! print spaces for the appropriate recurence level
    for(j=0; j<recLevel-1; j++)
    {
        printf("     ");
    }
    //! then print value
    printf("%s", root->data);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}

int main()
{
    FILE    *in;

    in = fopen ("input.dat", "r");
    radacina = createBinTree(in);
    prettyPrint(radacina, 0);
    printf ("\nThe value of the expression is %f", compute(radacina));
    getch();
    return 0;
}
