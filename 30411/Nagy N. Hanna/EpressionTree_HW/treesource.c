#include "binaryTree.h"

nodeT *createBinTree(FILE *f)
{
    char *data=(char*)malloc(sizeof(char)*20);
    fscanf(f,"%s ",data);
    if(strstr("*+/-",data) == NULL)
    {

        nodeT *p=(nodeT*)malloc(sizeof(nodeT));
        p->data=data;
        p->left=NULL;
        p->right=NULL;

    }
    else
    {
        nodeT *p=(nodeT*)malloc(sizeof(nodeT));
        p->data=data;
        p->left=createBinTree(f);
        p->right=createBinTree(f);
        return p;
    }
}




void prettyPrint(FILE *pf,nodeT *root,int level)
{
    if(root==NULL)
    {
        level--; //! reached leaf, must decrement recurence level
        return;
    }
    level++; //! otherwise increment it
    prettyPrint(pf,root->right,level); //! keep going right in the tree
    int j=0;

    //! print spaces for the appropriate recurence level
    for(j=0; j<level-1; j++)
    {
        fprintf(pf,"     ");
    }
    //! then print value
    //printElement(root);
    fprintf (pf,"%s " ,root->data );
    //! print  a new line
    fprintf(pf,"\n");

    prettyPrint(pf,root->left,level); //! keep going left in the tree

}
