#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeT{
    char *data;
    struct nodeT *left;
    struct nodeT *right;
}node;

FILE* f;

node* allocNode()
{
    return (node*)malloc(sizeof(node));
}

node* createNode(char *data)
{
    node* newNode = allocNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* createTree()
{

    node* p;

    char* tempData = (char*)malloc(sizeof(char)*10);
    fscanf(f, "%s", tempData);

    p = createNode(tempData);

    if(strlen(tempData) == 1 && (tempData[0]=='+' || tempData[0]=='-' || tempData[0]=='*' || tempData[0]=='/'))
    {
        p->left = createTree();
        p->right = createTree();
    }

    return p;
}

void prettyPrint(node *root,int recLevel)
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
        printf("    ");
    }

    printf("%s", root->data);

    printf("\n");
    printf("\n");

    prettyPrint(root->left,recLevel);
}

int main()
{
    f = fopen("input.dat", "r");
    node* root = createTree();
    fclose(f);
    prettyPrint(root, 0);
    return 0;
}
