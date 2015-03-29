#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lis{
    char *character;
    struct lis *next;
}nodeL;

typedef struct sent {
    int nrElem;
    nodeL *last, *first;
}sentinel;

static sentinel *s;

typedef struct tree{
    char *data;
    struct tree *left, *right;
}nodeT;

nodeT *createNode(char *x){
    nodeT *p=(nodeT*)malloc(sizeof(nodeT));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

nodeT *createTree(){
    char *x=(char*)malloc(sizeof(char)*3);
    scanf("%s", x);
    nodeT *p=createNode(x);
    if(strcmp(x,"*")!=0){
        printf("left child of parent %s : ",x);
        p->left=createTree();
        printf("right child of parent %s : ",x);
        p->right=createTree();
    }
    return p;
}

nodeT *createTreeRoot(){
    printf("root=");
    nodeT *p=createTree();
    return p;
}

void TREE(nodeT * root, int level){
    //int i;
    if (root!=NULL){
        /*for(i=0;i<=level;i++){
            printf(" ");
        }*/
        printf("%s ",root->data);
        TREE(root->left,level+1);
        TREE(root->right,level+1);
    }
}

nodeL *createEmptyList(){
    nodeL *head=(nodeL*)malloc(sizeof(nodeL));
    head=NULL;
    if(head!=NULL){
        printf("error: cannot create list");
        return -1;
    }
    else
        return head;
}

nodeL *addNode(char *x,nodeL *head){
    nodeL *p=(nodeL*)malloc(sizeof(nodeL));
    sentinel *s=(sentinel*)malloc(sizeof(sentinel));
    if(head==NULL){
        strcpy(p->character,x);
        head=p;
        p->next=NULL;
        head->next=NULL;
        s->first=head;
        s->last=head;
        s->nrElem=s->nrElem+1;
    }
    else {
        strcpy(p->character,x);
        p->next=NULL;
        free(s->last);
        s->last=p;
        s->nrElem=s->nrElem+1;
    }
    return p;
}

nodeL *createList(nodeT *t, nodeL* head){
    nodeL *p;
    if(t!=NULL){
        p=addNode(t->data,head);
        p->next=createList(t->left,head);
        p->next=createList(t->right,head);
    }
    else
        p=addNode("*",head);
    return p;
}

nodeL *createListFromTree(nodeT *root){
    nodeL *head=createEmptyList();
    nodeL *p=createList(root,head);
    return p;
}

void LIST(nodeL *l){
    while(l!=NULL){
        printf("%s ",l->character);
        l=l->next;
    }
}

nodeT *createTreeList(char *x){
    nodeT *p=(nodeT*)malloc(sizeof(nodeT));
    strcpy(p->data,x);
    p->left=NULL;
    p->right=NULL;
    return p;
}

nodeT *createTreeFromList(nodeL *p){
    nodeT *root;
    root=createTreeList(p->character);
    if(strcmp(p->character,"*")!=0){
        root->left=createTreeFromList(p->next);
        root->right=createTreeFromList(p->next);
    }
    return root;
}

int main()

{
    nodeT *t=createTreeRoot();
    nodeL *l=createListFromTree(t);
    free(t);
    l=s->first;
    LIST(l);// prints the list
    printf("\n");
    t=createTreeFromList(l);
    TREE(t,0);//the tree
    return 0;
}
