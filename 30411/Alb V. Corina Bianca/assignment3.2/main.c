#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *data;
    struct node *left, *right;
}nodeT;

typedef struct Queue{
    char *ch;
    struct Queue *prev, *next;
}Q;

typedef struct Sentinel{
    char *ch;
    Q *first, *last;
}senti;

Q *createList(char *str){
    Q* p=(Q*)malloc(sizeof(Q));
    senti *sent=(senti*)malloc(sizeof(senti));
    p->ch=(char*)malloc(sizeof(char)*7);
    p->ch=strtok(str," ");
    sent->ch=(char*)malloc(sizeof(char)*7);
    sent->last=p;
    sent->first=p;
    p->next=NULL;
    p->prev=NULL;
    while(p!=NULL){
        p=p->next=NULL;
        p=(Q*)malloc(sizeof(Q));
        p->ch=(char*)malloc(sizeof(char)*7);
        p->ch=strtok(NULL," ");
        p->prev=sent->last;
        sent->last=p;
    }
    return p;
}

nodeT *createNode(char *x){
     nodeT *p=(nodeT*)malloc(sizeof(nodeT));
     p->data=(char*)malloc(sizeof(char)*7);
     p->data=x;
     p->left=NULL;
     p->right=NULL;
     return p;
}

nodeT *createBinaryTree(Q* L){
    nodeT *p=createNode(L->ch);
    if (strcmp(L->prev->ch,"*-+/")==0){
        p->left=NULL;
        p->right=NULL;
    }
    else if(strcmp(L->ch,"*-+/")!=0){
            p->left=createBinaryTree(L->next);
            p->right=createBinaryTree(L->next);
        }
    return p;
}

void output(nodeT *root,int level){//outputs the tree in preorder
    int i;
    if(root!=NULL){
        for(i=0;i<=level;i++)
            printf(" ");
        printf("%2.2s\n",root->data);
        output(root->left,level+1);
        output(root->right,level+1);
    }
}

int main(){
    FILE *f;
    char *str;
    str=(char*)malloc(sizeof(char)*100);
    f=fopen("data.txt","r");
    fgets(str,100,f);
    fclose(f);
    Q *L=createList(str);
    nodeT *root=createBinaryTree(L);
    output(root,0);
    return 0;
}
