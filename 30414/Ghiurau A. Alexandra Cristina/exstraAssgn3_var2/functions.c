#include "functions.h"

void printStringElement(NodeT * node, FILE *fileOutput)
{
    fprintf (fileOutput,"%s " ,(char*) node->content);
}

void * getStringContent(char * content)
{
    return content;
}

NodeT *createNode(void *content)
{
    NodeT *node = (NodeT*)malloc(sizeof(NodeT));
    node->content = content;
    node->left = NULL;
    node->right = NULL;
    return node;
}

NodeT *createBinTree(FILE *file)
{
    NodeT *p;

    char *content = (char*)malloc(sizeof(char)*MAX_SIZE_OF_CONTENT);

    if(fscanf(file, "%s", content)== -1) //conditia de oprire
    {
        return NULL;
    }
    else
    if ((strcmp(content,"+")!=0) && (strcmp(content,"-")!=0) && (strcmp(content,"*")!=0) && (strcmp(content,"/")!=0))
    {
        return p = createNode(content);
    }
    else
    {
        void * cont = getContent(content);
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->content = cont;
        p->left = createBinTree(file);
        p->right = createBinTree(file);
    }
    return p;
}

void prettyPrint(NodeT *root,int recLevel, FILE *fileOutput) //! root, index, length, reccurence level
{
    if(root==NULL)
    {
        recLevel--; //! reached leaf, must decrement recurence level
        return;
    }
    recLevel++; //! otherwise increment it
    prettyPrint(root->right,recLevel,fileOutput); //! keep going right in the tree
    int j=0;

    //! print spaces for the appropriate recurence level
    for(j=0; j<recLevel-1; j++)
    {
        fprintf(fileOutput,"     ");
    }
    //! then print value
    printElement(root, fileOutput);

    //! print  a new line
    fprintf(fileOutput,"\n");

    prettyPrint(root->left,recLevel,fileOutput); //! keep going left in the tree
}
