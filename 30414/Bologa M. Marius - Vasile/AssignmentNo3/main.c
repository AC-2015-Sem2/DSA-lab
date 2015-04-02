#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE*fin;

typedef struct node
{
    char* data;
    struct node *left, *right;
} NodeT;

typedef struct lista
{
    char* data;
    struct lista *next, *prev;
} ListaT;
ListaT *headT,*tailT;

NodeT *createTreeNode(char* data)
{
    NodeT* curr = (NodeT*)malloc(sizeof(NodeT));
    curr -> data = data;
    curr -> left = NULL;
    curr -> right = NULL;
    return curr;
}

ListaT* createListNode(char *data)
{
    ListaT *curr =(ListaT*)malloc(sizeof(ListaT));
    curr->data = data;
    curr->next = NULL;
    curr->prev = NULL;
    return curr;
}

NodeT* createBinTree()
{

    char* data =(char*)malloc(sizeof(char));
    fscanf(fin, "%s", data);
    if(strcmp(data,"*")==0)
        return NULL;
    else
    {
        NodeT* curr=createTreeNode(data);
        curr -> left = createBinTree();
        curr -> right = createBinTree();
        return curr;
    }

}
void addLast(char *data)
{
    if(headT==NULL)
    {
        ListaT* head=createListNode(data);
        head->prev=NULL;
        head->next=NULL;
        headT=head;
        tailT=headT;
    }
    else
    {
        ListaT *curr=createListNode(data);
        tailT->next=curr;
        curr->prev=tailT;
        curr->next=NULL;
        tailT=curr;
    }
}

ListaT* getListFromTree(NodeT* root)
{
    if(root != NULL)
    {
        addLast(root->data);
        getListFromTree(root -> left);
        getListFromTree(root -> right);
    }
    else
    {
        addLast("*");
    }
    return headT;
}
void printList()
{
    ListaT *curr = headT;
    while(curr != NULL)
    {
        printf("%s ",curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}

NodeT *getTreeFromList(ListaT **headT)
{
    if(strcmp((*headT)->data,"*")!=0)
    {
        NodeT *curr=createTreeNode((*headT)->data);
        *headT=(*headT)->next;
        free((*headT)->prev);
        curr->left= getTreeFromList(headT);
        curr->right= getTreeFromList(headT);
        return curr;
    }
    else
    {
        *headT=(*headT)->next;
        return NULL;
    }
}
void prettyPrint(NodeT *root,int nivel)
{
    if(root==NULL)
    {
        nivel--;
        return;
    }
    nivel++;
    prettyPrint(root->right,nivel);
    int i=0;
    for(i=0; i<nivel-1; i++)
    {
        printf("     ");
    }
    printf("%s ",root -> data);
    printf("\n");
    prettyPrint(root->left,nivel);
}
int main()
{

    fin=fopen("input.txt","r");
    if (fin==NULL)
    {
        printf("Error in opening the file.");
        exit(1);
    }
    NodeT *root = createBinTree();
    getListFromTree(root);
    printList();
    root = getTreeFromList(&headT);
    prettyPrint(root,0);
    return 0;
}
