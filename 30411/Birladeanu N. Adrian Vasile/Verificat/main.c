#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fin;
char s[70];
int n; // numarul noduri ale listei

typedef struct treenode
{
    char code;
    struct treenode *left;
    struct treenode *right;
} NodeT;

typedef struct listnode
{
    char code;
    struct listnode *next;
} NodeL;
NodeL *tail, aux2;

NodeT* create_tree_node(char c)
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->code=c;
    p->left=p->right=NULL;
    return p;
}

NodeT* createBinTree()
{
    char c;
    sscanf(s, "%c", &c);
    if(c=='*')
    {
        if(strlen(s)>1)strcpy(s, s+2);
        return NULL;
    }
    else
    {
        NodeT *p=create_tree_node(c);
        if(strlen(s)>1)strcpy(s, s+2);
        p->left=createBinTree();
        p->right=createBinTree();
        return p;
    }
}

void preorder (NodeT *root)
{
    if(root!=NULL)
    {
        printf("%c ", root->code);
        preorder(root->left);
        preorder(root->right);
    }
}

void add_to_list (NodeT *nod)
{
    if(tail==NULL)
    {
        tail=(NodeL*)malloc(sizeof(NodeL));
        tail->code=nod->code;
        tail->next=NULL;
    }
    else
    {
        NodeL *p=(NodeL*)malloc(sizeof(NodeL));
        if(nod!=NULL) p->code=nod->code;
        else p->code='*';
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
}

NodeL* getListfromTree(NodeT* root)
{
    add_to_list(root);
    NodeL *p=tail;
    if(root!=NULL)
    {
        getListfromTree(root->left);
        getListfromTree(root->right);
    }
    return p;
}

NodeT* getTreefromList(NodeL *first) //voi modifica sirul s si voi crea un nou arbore cu createBinTree
{
    strcpy(s, "");
    NodeL *aux=first;
    while(aux!=NULL)
    {
        char s2[3];
        s2[0]=aux->code;
        s2[1]=' ';
        s2[2]='\0';
        strcat(s, s2);
        aux=aux->next;
    }
    NodeT *p=createBinTree();
    return p;
}


void traverseList(NodeL *first)
{
    NodeL *aux=first;
    while(aux!=NULL)
    {
        printf("%c ", aux->code);
        aux=aux->next;
    }
    printf("\n");
}

void printElement(NodeT * node)
{
    printf ( "%c " , node->code);
}

void prettyPrint(NodeT *root,int recLevel)
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
        printf(" ");
    }

    printElement(root);

    printf("\n");
    prettyPrint(root->left,recLevel);
}


int main()
{
    int i, a;
    for(i=0; i<=strlen(s); i++)if(s[i]==' ')a++;
    n=strlen(s)-a;
    fin=fopen("input.txt", "r");
    fgets(s, 70, fin);
    NodeT *root=createBinTree();
    NodeL *head=getListfromTree(root);
    traverseList(head);
    root=getTreefromList(head);
    prettyPrint(root, 0);
    return 0;
}
