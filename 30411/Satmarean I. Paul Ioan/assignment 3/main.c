#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tree node
typedef struct node{
    struct node * left;
    struct node * right;
    int data;
}NodeT;


//list node
typedef struct NodeL{
    struct NodeL * prev;
    struct NodeL * next;
    int code;
    char leaf;
}NodeL;

//creates a tree node
NodeT * createNode(int x)
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));
    p->data=x;
    p->left=p->right=NULL;
    return p;
}

//prints value of a tree element
void printElement(NodeT * node)
{
    printf("%d ",node->data);
}

//creates a binary tree recursively
NodeT * createBinTree()
{
    char* content=(char*)malloc(sizeof(char)*20);

    NodeT*p;

    scanf("%s",content);

    if(strcmp(content,"*")==0)
        return NULL;
    else{
        p=createNode(atoi(content));
        p->left=createBinTree();
        p->right=createBinTree();
    }

    return p;
}
NodeL * aux;

//makes a binary tree based on a aux var
//for the record i hate globals but couldnt figure out how to
//do it without them so if you know please give me a hint
NodeT * maketree()
{
    NodeT*p=NULL;

    if(aux!=NULL)
    {

        p=createNode(aux->code);
        if(aux->leaf=='*')
        {
        /* if(aux->next!=NULL)
            {
                aux=aux->next;
        }*/
        return p;

        }else
        {

            if(aux->next!=NULL)
            {
                aux=aux->next;
                p->left=maketree();
            }
            if(aux->next!=NULL)
            {
                aux=aux->next;
                p->right=maketree();
            }
        }
    }
    return p;
}

NodeT * getTreeFromList(NodeL * list)
{
    if(list!=NULL)
    {
        aux=NULL;
        aux=list;

        NodeT * root;
        root= maketree();

        return root;
    }
    return NULL;
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

NodeL * makeListNode(int x)
{
    NodeL * p=(NodeL*)malloc(sizeof(NodeL));
    p->code=x;
    p->next=p->prev=NULL;
    p->leaf='n';
    return p;
}

NodeL * head;
NodeL * last;

void createlist(NodeT * current)
{
    NodeL * p = makeListNode(current->data);
   p->prev=last;
   if(current->left==NULL&&current->right==NULL)
        p->leaf='*';
    if(last!=NULL) {
            last->next=p;
            head=p;
    }
    last=p;
    if(current->left!=NULL)
        createlist(current->left);
    if(current->right!=NULL)
        createlist(current->right);
    return;
}

NodeL * getListFromTree(NodeT *root)
{
    if(root!=NULL){
    head=NULL;
    last=NULL;

    last=makeListNode(root->data);

    NodeL * head= last;

    if(root->left!=NULL)
        createlist(root->left);
    if(root->right!=NULL)
        createlist(root->right);

    return head;
    }
    return NULL;
}

void printList(NodeL * a)
{
    NodeL* aux;
    aux=a;
    while(aux!=NULL)
    {
         if(aux->leaf=='*')
            printf("*");
        printf("%d ",aux->code);
        aux=aux->next;
    }
    printf("\n");
}

int main()
{

    NodeT * root = createBinTree();
    NodeL * list1= getListFromTree(root);
    printList(list1);
    root = getTreeFromList(list1);
    prettyPrint(root,0);
    return 0;
}


