#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
} node;
struct node* createNode(int data);
int findHeight(struct node *root);
int maxi(int a, int b);
struct node *rightRotate(struct node *root);
struct node *leftRotate(struct node *nod);
int getBalance(struct node *root);
struct node* insertNode(struct node* node, int data);
void prettyPrint(struct node *root,int nivel);
struct node* deleteNode(struct node* root, int data);
struct node * miniNod(struct node* node);
#endif // FUNCTIONS_H_INCLUDED
