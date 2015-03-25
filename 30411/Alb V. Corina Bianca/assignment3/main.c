#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodetree{
    int date;
    struct nodetree *left, *right;
}nodeT;

typedef struct nodelist{
    char *character;
    struct nodelist *next;
}nodeL;

nodeT *createNode(int x){
    nodeT *p;
    p=(nodeT*)malloc(sizeof(nodeT));
    p->date=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

nodeT *createBinaryTree(){
    char* content=(char*)malloc(sizeof(char)*20);
    scanf("%s",content);
    nodeT *p=createNode(atoi(content));
    if (strcmp(content,"*")==0)
        return NULL;
    else{
        p->left=createBinaryTree();
        p->right=createBinaryTree();
    }
    return p;
}

nodeL *getListFromTree(nodeT *root){
    nodeL *p=(nodeL*)malloc(sizeof(nodeL));
    if(root == NULL)
        p->character="*";
    else{
        p->character=(char*)root->date;
        free(root);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    return p;
}

int *printList(nodeL *first){
    if(first!=NULL){
    printf("%s ",first->character);
    printList(first->next);
    }
    return 0;
}

nodeT *createTreeNode(char *c){
    nodeT* p=(nodeT*)malloc(sizeof(nodeT));
    if(strcmp(c,"*")!=0){
        p->date=atoi(c);
        p->left=NULL;
        p->right=NULL;
    }
    return p;
}

nodeT *getTree(nodeL *first){
    nodeT *p=createTreeNode(first->character);
    if(strcmp(first->character,"*")==0)
        return NULL;
    else {
        p->left=getTree(first->next);
        p->right=getTree(first->next);
    }
    return p;
}

void prettyPrint(nodeT *root,int level){
    int i;
    if(root!=NULL){
        for(i=0;i<=level; i++)
            printf(" ");
        printf("%d ",root->date);
        prettyPrint(root->left,level+1);
        prettyPrint(root->right,level+1);
    }
}

int main()
{
    nodeT *root=createBinaryTree();
    nodeL *first=getListFromTree(root);
    printList(first);
    root=getTree(first);
    prettyPrint(root,0);
    return 0;
}
