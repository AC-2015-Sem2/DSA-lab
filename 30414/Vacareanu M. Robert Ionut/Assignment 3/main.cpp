#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct Node{
    char *data;
    struct Node *left, *right;
}NodeT, NodeL;
NodeL *head, *tail;

NodeT* createNode(char *data){
    NodeT *p = (NodeT*) malloc(sizeof(NodeT));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
NodeT* createBinTree(){
    NodeT *p;
    char *data = (char*) malloc(sizeof(char) * 100);
    scanf("%s", data);
    if(strcmp(data, "*") == 0) return NULL;
    else{
        p = createNode(data);
        p->left = createBinTree();
        p->right = createBinTree();
    }
    return p;
}
void addLast(char *data){
    if (head == NULL){
        head = (NodeL*) malloc(sizeof(NodeL));
        head->data = data;
        head->right = NULL;
        head->left = NULL;
        tail = head;
    }
    else{
        NodeL* newNodeL = (NodeL*) malloc(sizeof(NodeL));
        newNodeL->data = data;
        newNodeL->right = NULL;
        tail->right = newNodeL;
        tail = newNodeL;
    }
}
NodeL* getListFromTree(NodeT *root){
    if(root == NULL) addLast("*");
    else{
        addLast(root->data);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    return head;
}
void traverseList(NodeL *firstFromList){
    while(firstFromList!=NULL){
        printf("%s ", firstFromList->data);
        firstFromList = firstFromList->right;
    }
    printf("\n");
}
NodeT* getTreeFromList(NodeL *headOfList){
    head = headOfList;
    NodeT* p = (NodeT*) malloc(sizeof(NodeT));
    char *data = headOfList->data;
    if(headOfList == NULL) printf("\nThe list is empty, no tree to display");
    if(strcmp(data, "*") == 0){
        head = head->right;
        return NULL;
    }
    else{
        head=head->right;
        p=createNode(data);
        p->left=getTreeFromList(head);
        p->right=getTreeFromList(head);
    }
    return p;
}
void prettyPrint(NodeT *root, int recLevel){

    if(root == NULL){
        recLevel--;
        return;
    }
    recLevel++;
    prettyPrint(root->right, recLevel);
    int j=0;

    for(j=0; j<recLevel-1; j++) printf("     ");

    printf("%s", root->data);
    printf("\n");
    prettyPrint(root->left, recLevel);
}
int main()
{
    NodeT* root = createBinTree();
    NodeL* firstFromList = getListFromTree(root);
    printf("\n\nThe list from the tree is: \n");
    traverseList(head);
    printf("\nThe tree from the list is: \n");
    root=getTreeFromList(firstFromList);
    prettyPrint(root, 0);
    return 0;
}
