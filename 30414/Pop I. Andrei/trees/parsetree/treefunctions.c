# include "parsetree.h"

void enqueue(char *data)
{
    NodeQ *myNode=(NodeQ*) malloc(sizeof(NodeQ));
    char *aux=(char*) malloc (sizeof(char) * (strlen(data)+1));
    strcpy(aux, data);
    myNode->elem=aux;

    if(first==NULL)
    {
        first=last=myNode;
        myNode->next=NULL;

    }
    else
    {
        myNode->next=NULL;
        last->next=myNode;
        last=myNode;
    }
}

void dequeue()
{
    NodeQ *myNode=first;

    first=first->next;
    free(myNode);
}

void createQ(FILE *in)
{
    char *p, line[100], s[]=" \n";
    fgets(line, 100, in);

    p=strtok(line, s);

    while(p!=NULL)
    {
        enqueue(p);
        p=strtok(NULL, s);
    }
}

void printQ()
{
    NodeQ *myNode=first;

    while(myNode!=NULL)
    {
        printf("%s ", myNode->elem);
        myNode=myNode->next;
    }

}

NodeT *createNodeT(char *data)
{
    NodeT *p=(NodeT*) malloc (sizeof(NodeT));
    p->left=NULL;
    p->right=NULL;
    p->data=data;

    return p;
}


NodeT *createTree()
{
    char *aux=first->elem;
    NodeT *p = createNodeT(aux);
    dequeue(first);

    if(strstr("+-*/" , aux) == 0)
    {
        return p;
    }
    else
    {
        p->left=createTree();
        p->right=createTree();
    }
    return p;
}

void preorder(NodeT *root)
{
    if(root != NULL)
    {
        printf("%s ", root->data);
        preorder(root->left);
        preorder(root->right);
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
        printf("  ");
    }

    //! then print value
    printf("%s", root->data);

    //! print a new line
    printf("\n");
    prettyPrint(root->left,recLevel); //! keep going left in the tree
}

