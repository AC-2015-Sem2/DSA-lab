#include "Create.h"
NodeT *createBinTree(FILE *f)
{
    NodeT *p;
    char *content=(char *)malloc(sizeof(char)*MAX_CONTENT);
    fscanf(f,"%s",content);
    if(strcmp(content,"*")==0)
    {
        return NULL;
    }
    else
    {
        p=(NodeT *)malloc(sizeof(NodeT));
        if(p==NULL)
        {
            perror("Not enough memory!\n");
            exit(1);
        }
        p->key=atoi(content);
        p->left=createBinTree(f);
        p->right=createBinTree(f);
    }
    return p;
}
