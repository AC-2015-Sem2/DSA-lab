#include "tree.h"

/************ Function that creates a node in a tree **********************************************/
nodeT * createNodeT(char * data)
{
    nodeT * p =(nodeT*)malloc(sizeof(nodeT));
    p->data=(char*)malloc(10*sizeof(char));
    strcpy(p->data,data);
    p->left=NULL;
    p->right=NULL;

    return p;
}
/************ Function that creates a binary tree *************************************************/
nodeT * createBinTree()
{
 nodeT* p;
    char*data=(char*)malloc(sizeof(char)*100);
    if (fscanf(f,"%s",data)==-1)
    {
        return NULL;
    }
    else
    {
    if ((strcmp(data,"*")!=0)&&(strcmp(data,"/")!=0)&&(strcmp(data,"+")!=0)&&(strcmp(data,"-")!=0))
    {
        p=createNodeT(data);
    }
    else
    {
        p=createNodeT(data);
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
    }
}

/*********** Pretty print ****************************************************************************/
void prettyPrint(nodeT *root,int recLevel)
{
    if(root==NULL)
    {
        recLevel--;
        return;
    }
    recLevel++;
    prettyPrint(root->right,recLevel);
    int j=0;
    for(j=0; j<recLevel-1; j++)
    {
        fprintf(g,"     ");
    }
    fprintf(g,"%s ",root->data);
    fprintf(g,"\n");

    prettyPrint(root->left,recLevel);
}

