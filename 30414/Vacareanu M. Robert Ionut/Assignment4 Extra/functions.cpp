#include "header.h"

NodeT* createNode(int data){
    NodeT* newNode = (NodeT*) malloc(sizeof(NodeT));
    newNode->data = data;
    newNode->weight = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int CalculateWeight(struct Node* root){
    NodeT* p = root;
    int leftWeight = 0, rightWeight = 0;
    if(root == NULL) return 0;
    else{
        leftWeight = CalculateWeight(root->left) + 1;
        rightWeight = CalculateWeight(root->right) + 1;
        p->weight = leftWeight - rightWeight;
    }
    return (leftWeight>rightWeight)? leftWeight:rightWeight;
}
void prettyPrint(struct Node* root, int recLevel){
    if(root == NULL){
        recLevel--;
        return;
    }
    recLevel++;
    prettyPrint(root->right, recLevel);
    int j = 0;
    for(j=0; j<recLevel; j++) printf("     ");
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
NodeT* balanceTree(struct Node* root){
    CalculateWeight(root);
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
    if(root == NULL){
        root = createNode(data);
    }
    else{
        if(data < root->data) root->left = insertNodeUtil(root->left, data);
        else root->right = insertNodeUtil(root->right, data);
    }
    return balanceTree(root);
}
NodeT* insertNode(struct Node* root, int data){
    root = insertNodeUtil(root, data);
    CalculateWeight(root);
//    root = balanceTree(root);
    return root;
}
NodeT* minValueNode(struct Node* root){
    NodeT* currentNode = root;
    while(currentNode->left != NULL) currentNode = currentNode->left;
    return currentNode;
}
NodeT* deleteNode(struct Node *root, int data){
    if(root == NULL) return root;
//     Search for the key
    if(data < root->data) root->left = deleteNode(root->left, data);
    else if(data > root->data) root->right = deleteNode(root->right, data);
//     Once found, delete it
    else{
        // One child or no child
        if ((root->left == NULL) || (root->right == NULL)){
            NodeT* tempNode;
            if(root->left == NULL && root->right != NULL) tempNode = root->right;
            else tempNode = root->left;
            if(tempNode == NULL){
                tempNode = root;
                root = NULL;
            }
            else *root = *tempNode;
            free(tempNode);
        }
    // Two children
        else{
            NodeT* tempNode = minValueNode(root->right);
            root->data = tempNode->data;
            root->right = deleteNode(root->right, tempNode->data);
        }
    }
    return balanceTree(root);
}
