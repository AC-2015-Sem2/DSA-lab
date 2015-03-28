#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct node
{
    struct node*left;
    struct node*right;
    char data[3];
} NodeT;
typedef struct NodeL
{
    char c[3];
    struct NodeL* next;
    struct NodeL* prev;
} NodeL;
NodeL*head=NULL;
NodeL*tail=NULL;
FILE *tr;
void AddNodeLast(NodeT* root,char s[3])
{
    NodeL *p;
    p=(NodeL *)malloc(sizeof(NodeL));
    if ( head == NULL )
    {
        head=tail = p;
        strcpy(p->c,s);
        p->next = p->prev = NULL;
    }
    else
    {
        p->next = NULL;
        p->prev =tail;
        strcpy(p->c,s);
        tail->next = p;
        tail = p;
    }
}
NodeT*createNode(char s[3])
{
    NodeT*p=(NodeT*)malloc(sizeof(NodeT));
    strcpy(p->data,s);
    p->left=p->right=NULL;
    return p;
}
NodeT *createBinTree()
{
    char *content;
    NodeT *p;

    content = (char *)malloc(sizeof(char)*3);
    scanf("%s", content);
    if (strcmp(content, "*")== 0)
        return NULL;
    else
    {
        p=createNode(content);
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return (p);
}

void treetolist(NodeT*root)
{
    if(root!=NULL)
    {
        AddNodeLast(root,root->data);
        treetolist(root->left);
        treetolist(root->right);
    }
    else AddNodeLast(root,"*");
}
void PrintList()
{
    NodeL *p;

    p = (NodeL *)malloc(sizeof(NodeL));
    p=head;
    while (p != NULL )
    {
        fprintf(tr,"%s ", p->c);
        p=p->next;
    }
    fprintf(tr,"\n");
}

NodeT *growTreeFromList()
{

    NodeT*p=NULL;
    if(head!=NULL)
    {
        if(strcmp(head->c,"*")!=0)
        {
            p=createNode(head->c);
            head=head->next;
            p->left=growTreeFromList();
            p->right=growTreeFromList();
        }
        else
        {
            head=head->next;
        }
    }
    return p;
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
        fprintf(tr,"     ");
    }
    fprintf(tr,"%s",root->data);
    fprintf(tr,"\n");
    prettyPrint(root->left,recLevel);
}
int main()
{
    tr=fopen("garden.txt","w");
    NodeT*q=createBinTree();
    fprintf(tr,"Initial tree: \n\n");
    prettyPrint(q,0);
    fprintf(tr,"\n\n");
    treetolist(q);
    fprintf(tr,"The List: \n\n");
    PrintList();
    fprintf(tr,"\n\n");
    NodeT*r=(NodeT*)malloc(sizeof(NodeT));
    r=growTreeFromList();
    fprintf(tr,"Final tree: \n\n");
    prettyPrint(r,0);
    return 0;
}
