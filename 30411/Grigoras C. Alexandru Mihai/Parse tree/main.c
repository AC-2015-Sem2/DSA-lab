#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char  content[100];
    struct node *left, *right;
} NodeT;
typedef struct nodel
{
    char x[100];
    struct nodel *next;
}NodeL;
NodeL *Qhead,*Qtail;
void enqueue(char x[100])
{
    if (Qhead==NULL)
    {
        Qhead=(NodeL*)malloc(sizeof(NodeL));
        strcpy(Qhead->x,x);
        Qhead->next=NULL;
        Qtail=Qhead;
    }
    else
    {

        NodeL *p=(NodeL*)malloc(sizeof(NodeL));
        strcpy(p->x,x);
        p->next=NULL;
        Qtail->next=p;
        Qtail=p;
    }
}
void dequeue()
{
    if (Qhead!=NULL)
    {
        NodeL *p=Qhead->next;
        free(Qhead);
        Qhead=p;
    }

}
NodeT *createNode(char content[100])
{
    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    strcpy(newNode->content , content);
    newNode->left = NULL;
    newNode->right= NULL;
    return newNode;
}
NodeT *createBinTREE()
{

    NodeT *p;
    char content[100];
    strcpy(content,Qhead->x);
    dequeue();
    if ((strcmp(content,"*")==0 || strcmp(content,"+")==0 || strcmp(content,"-")==0 || strcmp(content,"/")==0))
    {
         p=createNode(content);
         p->left=createBinTREE();
         p->right=createBinTREE();
    }
    else
    {
        p=createNode(content);
        p->left=NULL;
        p->right=NULL;
    }
    return p;
}
void listread(FILE *pf)
{
    //char *p=(char*)malloc(sizeof(char)*100);
    char p[100];
    while (fscanf(pf,"%s",p)==1)
    {
        enqueue(p);
    }
}
void printElement(NodeT *root)
{
    printf("%s ",root->content);
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
int main()
{
    FILE *pf=fopen("date.in","r");
    listread(pf);
    NodeT *root=createBinTREE();
    prettyPrint(root,0);
    return 0;
}
