#include "treeAndList.h"

NodeT *createNode(void *content)
{
    NodeT *node = (NodeT*)malloc(sizeof(NodeT));
    node->content = content;
    node->left = NULL;
    node->right = NULL;
    return node;
}

NodeL *createListNode(void *content)
{
    NodeL *newNode = (NodeL*)malloc(sizeof(NodeL));
    newNode->content = content;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//! exactly like in the lab session
NodeT *createBinTree()
{
    NodeT *p;
    char *content = (char*)malloc(sizeof(char)*MAX_SIZE_OF_CONTENT);

    scanf( "%s" ,content );
    if ( strcmp(content,"*")==0 ) //the element which was before was a leaf, it's gonna end up there
    {
        return NULL;
    }
    else
    {
        void * cont = getContent(content);
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->content = cont;
        p->left = createBinTree();
        p->right = createBinTree();
    }
    return p;
}

NodeL* getListFromTree(NodeT *node)
{
    createDoublyLinked(node);
    return head;
}

void createDoublyLinked(NodeT *node)
{
    if (node != NULL)
    {
        addLast(node->content);
        if (node->left == NULL)
            addLast((void *)"*"); //! I add the stars as well, so It'll be easier to reconstruct the tree
        if (node->right == NULL)
            addLast((void *)"*");
        createDoublyLinked(node->left);
        createDoublyLinked(node->right);
    }
}
//! I used a global variable copyroot in order to move the pointer to the next value
//! after processing it..

NodeT * getTreeFromList()
{
    NodeT *p;
    char *content = (char *) copyhead->content;
    if (strcmp(content,"*")==0) //the element which was before was a leaf, it's gonna end up there
    {
        copyhead = copyhead->next;
        return NULL;
    }
    else
    {
        void * cont = getContent(content);
        p = (NodeT *) malloc(sizeof(NodeT));
        p->content = cont;
        copyhead = copyhead->next;
        p->left = getTreeFromList();
        p->right = getTreeFromList();
    }
    return p;
}

void traverse(NodeL *aux)
{
    aux = head;
    while(aux)
    {
        printf ("%s " ,(char*) aux->content);
        aux = aux->next;
    }
}

void addLast(void *content)
{
    NodeL * newNode = createListNode(content);
    if(head == NULL)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        newNode->next =  NULL;
        tail->next = newNode;
        tail= newNode;
    }
}

void printStringElement(NodeT * node)
{
    printf ("%s " ,(char*) node->content);
}

void * getStringContent(char * content)
{
    return content;
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
    printElement(root);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}
