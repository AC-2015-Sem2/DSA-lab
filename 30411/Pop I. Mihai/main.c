#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *left, *right;
}NodeT;

typedef struct nodel{
    int data;
    struct nodel *next;
}NodeL;

NodeL *headL,*tailL;

NodeT *createNode(int data)
{
    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

NodeT* createBinTree(){
    NodeT* newNode;
    char* data = (char*)malloc(sizeof(char));
    scanf("%s ",data);
    if(strcmp(data,"*")==0)
        return NULL;
    else{
        newNode = createNode(atoi(data));
        newNode -> left = createBinTree();
        newNode -> right = createBinTree();
    }
    return newNode;
}

void addLast(int data){
    NodeL* newNode = (NodeL*)malloc(sizeof(NodeL));
    newNode -> data = data;
    if(headL == NULL){
        headL = newNode;
        tailL = newNode;
        newNode -> next = NULL;
    }
    else if(tailL != NULL){
        newNode -> next = NULL;
        tailL -> next = newNode;
        tailL = newNode;
    }
}

void getListFromTree(NodeT* root){
    if(root != NULL){
        addLast(root -> data);
        getListFromTree(root -> left);
        getListFromTree(root -> right);
    }
    else{
        addLast(0);
    }
}

void printList(){
    NodeL *newNode = headL;
    while(newNode != NULL){
        printf("%d ",newNode -> data);
        newNode = newNode -> next;
    }
    printf("\n");
}

NodeT* getTreeFromList(){
    NodeT *newNode;
    int code;
    code = headL -> data;
    headL = headL -> next;
    if( code == 0)
        return NULL;
    else{
        newNode = createNode(code);
        newNode -> left = getTreeFromList();
        newNode -> right = getTreeFromList();
    }
    return newNode;
}

void printElement(NodeT* root){
    printf("%d ",root -> data);
}


void prettyPrint(NodeT *root,int recLevel) //! root, index, length, recurrence level
{
    if(root==NULL)
    {
        recLevel--; //! reached leaf, must decrement recurrence level
        return;
    }
    recLevel++; //! otherwise increment it
    prettyPrint(root->right,recLevel); //! keep going right in the tree
    int j=0;

    //! print spaces for the appropriate recurrence level
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
    NodeT *root = createBinTree();
    getListFromTree(root);
    printList();
    root = getTreeFromList();
    prettyPrint(root,0);
    return 0;
}
