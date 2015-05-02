#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    struct node* left;
    struct node* right;
    int data;
} NodeT;
typedef struct nodel
{
    struct nodel* next;
    int data;
} NodeL;
NodeL* head;
NodeL* tail;
NodeT* createNode(int data)
{
    NodeT* root=(NodeT*)malloc(sizeof(NodeT));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}
void printElement(NodeT*  root)
{
    printf("%d",root->data);
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
NodeT* createBinTree()
{
    NodeT* p;
    char* data =(char*)malloc(sizeof(char)*100);
    scanf("%s",data);
    if(strcmp(data,"*")==0)
    {
        return NULL;
    }
    else
    {
        p=createNode(atoi(data));
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}
NodeT* createeBinTree()
{
    NodeT* p;
    char* data =(char*)malloc(sizeof(char)*100);
    scanf("%s",data);
    if(strcmp(data,"*")==0)
    {
        return NULL;
    }
    else
    {
        p=createNode(atoi(data));
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}
void addlast(int data)
{
    NodeL* p=(NodeL*)malloc(sizeof(NodeL));
    p->data=data;
    if(head==NULL)
    {
        head=p;
        tail=p;
        p->next=NULL;
    }
    else if(tail!=NULL)
    {
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
}
NodeL* getListFromTree(NodeT* root)
{
    if(root!=NULL)
    {
        addlast(root->data);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    else
        addlast('*');
    return head;
}
NodeT *getTreeFromList()
{
    NodeT *p;
    int data;
    data=head->data;
    head=head->next;
    if (data=='*')
    {
        return NULL;
        //printf("amajunsaici ");
    }
    else
    {
        p=createNode(data);
        p->left=getTreeFromList( );
        p->right=getTreeFromList();
    }
    return p;
}
int main()
{
    int i;
    i=0;
    NodeT* root=createBinTree();
    head=getListFromTree(root);
    root=getTreeFromList();
    prettyPrint(root,i);
    return 0;
}
