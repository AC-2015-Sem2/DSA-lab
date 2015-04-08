#include "header.h"

NodeT* createNode(int data){
    NodeT* newNode = (NodeT*) malloc(sizeof(NodeT));
    newNode->data = data;
    newNode->weight = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
NodeT* createBinTree(){
    NodeT* root;
    char *data = (char*) malloc(sizeof(char)*100);
    scanf("%s", data);
    if(strcmp(data, "*") == NULL) return NULL;
    else{
        root = createNode(atoi(data));
        root->left = createBinTree();
        root->right = createBinTree();
    }
    return root;
}
int calculateWeight(struct Node* root){
    NodeT* p = root;
    int leftWeight=0, rightWeight=0;
    if(root == NULL){
        return 0;
    }
    else{
        leftWeight = calculateWeight(root->left) + 1;
        rightWeight = calculateWeight(root->right) + 1;
        p->weight = leftWeight-rightWeight;
    }
    return (leftWeight>rightWeight)? leftWeight:rightWeight;
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

    printf("%d", root->data);
    printf("\n");
    prettyPrint(root->left, recLevel);
}
NodeT* rotateRight(struct Node* root){
    NodeT* pivot = NULL;
    pivot = root->left;
    root->left = pivot->right;
    pivot->right = root;
    root = pivot;
    return root;
}
NodeT* rotateLeft(struct Node* root){
    NodeT* pivot = NULL;
    pivot = root->right;
    root->right = pivot->left;
    pivot->left = root;
    root = pivot;
    return root;
}
void preOrder(NodeT* root){
    if(root != NULL){
        printf("%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
NodeT* balanceTree(struct Node* root){
    calculateWeight(root);
    if(root == NULL) return 0;
    if(root != NULL){
            if(root->weight > 1){
                if(root->left->weight <= -1){
                    root->left=rotateLeft(root->left);
                    root = rotateRight(root);
                    return root;
                }
                else{
                    root = rotateRight(root);
                    return root;
                }
            }
            else if(root->weight < -1){
                if(root->right->weight >= 1){
                    root->right=rotateRight(root->right);
                    root = rotateLeft(root);
                    return root;
            }
                else{
                    root = rotateLeft(root);
                    return root;
            }
        }
        else return root;
    }
    return root;
}
NodeT* insertNodeUtil(struct Node* root, int data){
    if (root == NULL){
        root = createNode(data);
    }
    else{
        if(data < root->data) root->left=insertNodeUtil(root->left, data);
        else root->right=insertNodeUtil(root->right, data);
    }
    return balanceTree(root);
}
NodeT* insertNode(struct Node* root, int data){
    root = insertNodeUtil(root, data);
    calculateWeight(root);
//    root = balanceTree(root);
    return root;
}
