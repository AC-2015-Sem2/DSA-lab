#include "trees.h"

void ft_AL(char *a)
{
    if (tail == NULL)
    {
        head = (NodeL*)malloc(sizeof(NodeL));
        tail = head;
        strcpy(head->data,a);
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        NodeL *aux;

        aux = (NodeL*)malloc(sizeof(NodeL));
        strcpy(aux->data,a);
        aux->next = NULL;
        aux->prev = tail;
        tail->next = aux;
        tail = aux;
    }
}

NodeT *createNode(char *a)
{
    NodeT *nod;

    nod = (NodeT*)malloc(sizeof(NodeT));
    nod->left = NULL;
    nod->right = NULL;
    strcpy(nod->data,a);
    return nod;
}

NodeT *createBinTree()
{
    NodeT *p;
    char *data = (char*)malloc(sizeof(char) * 100);

    scanf ("%s", data);
    if (!strcmp(data, "*"))
        return NULL;
    else
    {
        p = createNode(data);
        p->left = createBinTree();
        p->right = createBinTree();
    }
    return p;
}

NodeL *getListFromTree(NodeT *root)
{
    if (root != NULL)
    {
        ft_AL(root->data);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    else
        ft_AL("*");
    return head;
}

NodeT *getTreeFromList(NodeL **aux)
{
    NodeT   *p;
    char    *data = (*aux)->data;
    *aux = (*aux)->next;

    if (!strcmp(data, "*"))
        return NULL;
    else
    {
        p = createNode(data);
        p->left = getTreeFromList(aux);
        p->right = getTreeFromList(aux);
    }
    return p;
}

void traverseList(NodeL *aux)
{
    while (aux != NULL)
    {
        printf ("%s ", aux->data);
        aux = aux->next;
    }
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
