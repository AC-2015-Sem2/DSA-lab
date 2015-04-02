#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>

/* ************************************************************************************************** */

typedef struct node
{
    struct node* left;
    struct node* right;
    int data;
} NodeT;

/* ************************************************************************************************** */

NodeT * troot;
NodeT * head;
NodeT * tail;

/* ************************************************************************************************** */

NodeT* createnode(int data)
{
    NodeT* p=(NodeT*)malloc(sizeof(NodeT));
    p->data=data;
    p->left=p->right=NULL;
    return p;
}

/* ************************************************************************************************** */

void addlast(int data)
{
        if(head!=NULL)
    {
        if(tail!=NULL)
        {
             NodeT * p=(NodeT*)malloc(sizeof(NodeT));
             p->data=data;
             p->left=tail;
             p->right=NULL;
             tail->right=p;
             tail=p;

    }
        else
        {
            NodeT * p=(NodeT*)malloc(sizeof(NodeT));
            p->data=data;
            p->right=NULL;
            p->left=head;
            tail=p;
            head->right=tail;
        }
    }
    else
    {
        NodeT * p=(NodeT*)malloc(sizeof(NodeT));
        p=createnode(data);
        head=p;
    }
}

/* ************************************************************************************************** */

NodeT* createStaticTree()
{
    troot=createnode(1);
    troot->left=createnode(2);
    troot->right=createnode(5);
    troot->left->left=createnode(6);
    troot->left->right=createnode(7);
    troot->right->left=createnode(9);

    return troot;
}

/* ************************************************************************************************** */

NodeT * createbinarytree()
{
    NodeT* p;
    char *content=(char*)malloc(sizeof(20));
    scanf("%s",content);
    if(strcmp(content,"*")==0)
        return NULL;
    else
    {
        p=createnode(atoi(content));
        p->left=createbinarytree();
        p->right=createbinarytree();
    }
    return p;
}

/* ************************************************************************************************** */

NodeT * getlistfromtree(NodeT *troot)
{
    if (troot != NULL)
    {
        addlast(troot->data);
        getlistfromtree(troot->left);
        getlistfromtree(troot->right);
    }
    else
    {
        addlast(0);
    }
    return head;
}

/* ************************************************************************************************** */

void traverselist(NodeT* head, NodeT* troot)
{

    if (head->data==0) troot=NULL;
    else
    {
        troot=createnode(head->data);
        traverselist(head->right,troot->left);
        traverselist(head->right,troot->right);
    }
}

/* ************************************************************************************************** */

void prettyprint(NodeT *troot)
{
    if (troot != NULL)
    {
        printf("%d ",troot->data);
        prettyprint(troot->left);
        prettyprint(troot->right);
    }
}

/* ************************************************************************************************** */

void listprint(NodeT * head)
{
    if (head != NULL)
    {
        if(head->data != 0)
        {printf("%d ",head->data);
        listprint(head->right);
        }
        else
        {
           printf("* ");
        listprint(head->right);
        }
    }
}

/* ************************************************************************************************** */

void printElement(NodeT * node)
{
    printf ( "%d " ,(int) node->data );
}

/* ************************************************************************************************** */

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

/* ************************************************************************************************** */
/* ************************************************************************************************** */
int main()
{
    NodeT * troot=createbinarytree();
    //troot=createStaticTree();
    head=getlistfromtree(troot);
    traverselist(head,troot);
    printf("\n     *************************************     \n");
    prettyPrint(troot,0);
    printf("\n     *************************************     \n");
    listprint(head);

    return 0;
}

