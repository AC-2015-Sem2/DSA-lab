#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef struct Node{
    char *data;
    struct Node *left, *right;
}NodeQ, NodeT;
NodeQ *firstInQueue, *lastInQueue;
int isItNumber(char *data){
    char *temp = (char*) malloc(sizeof(char)*100);
    strcpy(temp, data);
    if(atoi(temp) != 0 || data == "0") return 1;
    return 0;
}
void enQueue(char *data){
    NodeQ* newNode = (NodeQ*) malloc(sizeof(NodeQ));
    char *temp = (char*) malloc(sizeof(char) * 100);
    strcpy(temp, data);
    newNode->data = temp;
    newNode->right = NULL;
    newNode->left = NULL;
    if(firstInQueue == NULL) firstInQueue = lastInQueue = newNode;
    else{
        lastInQueue->right = newNode;
        lastInQueue = newNode;
    }
}
void deQueue(){
    firstInQueue = firstInQueue->right;
}
void createQueue(FILE *inputFile){
    char word[100];
    while(fscanf(inputFile, "%s", word) != EOF) enQueue(word);
}
NodeT* createNode(char *data){
    NodeT *p = (NodeT*) malloc(sizeof(NodeT));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
NodeT* createBinTree(){
    char *data = (char*) malloc(sizeof(char) * 100);
    strcpy(data, firstInQueue->data);
    NodeT* p=createNode(data);
    deQueue();
    if(atoi(data) != 0 || strcmp(data, "0") == 0) return p;
    else{
        p->left = createBinTree();
        p->right = createBinTree();
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
int main(){
FILE *inputFile = fopen("input.txt", "r");
createQueue(inputFile);
NodeT* root = createBinTree();
prettyPrint(root, 0);
return 0;
}
