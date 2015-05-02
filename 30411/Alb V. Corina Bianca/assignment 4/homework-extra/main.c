#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct nodeBT{
    int data;
    int ht;
    struct nodeBT *left, *right;
}node;

static node *rootAVL=NULL;
void prettyPrint(node *root,int recLevel);

node *createNode(int x){
    node *p=(node*)malloc(sizeof(node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

node * rotateright(node *x)
{
               node *y;
               y=x->left;
               x->left=y->right;
               y->right=x;
               x->ht=height(x);
               y->ht=height(y);
               return(y);
}
node * rotateleft(node *x)
{
               node *y;
               y=x->right;
               x->right=y->left;
               y->left=x;
               x->ht=height(x);
               y->ht=height(y);
               return(y);
}
node * RR(node *T)
{
               T=rotateleft(T);
               return(T);
}
node * LL(node *T)
{
               T=rotateright(T);
               return(T);
}
node * LR(node *T)
{
               T->left=rotateleft(T->left);
               T=rotateright(T);
               return(T);
}
node * RL(node *T)
{
               T->right=rotateright(T->right);
               T=rotateleft(T);
               return(T);
}
int BF(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    if(T->left==NULL)
        lh=0;
        else{
            T->left->ht=height(T->left);
            lh=1+T->left->ht;
        }
    if(T->right==NULL)
        rh=0;
        else{
            T->right->ht=height(T->right);
            rh=1+T->right->ht;
        }
    return(lh-rh);
}


node *insertNode(node *root, int cont){
    if(root==NULL){
        return createNode(cont);
    }
    else
    if(cont>root->data) {
        root->right=insertNode(root->right,cont);
        if(BF(root)==-2){
            if(cont>root->right->data)
                root=RR(root);
                else
                    root=RL(root);
        }
    }
    else
    if(cont<root->data) {
        root->left=insertNode(root->left,cont);
        if(BF(root)==2){
            if(cont < root->left->data)
                root=LL(root);
                else
                  root=LR(root);
        }
    }
    /*else{
        if(cont==root->data) printf("the node %d already exists in the tree",cont);
        return root;
    }*/
    root->ht=height(root);
    return(root);
}

node *createBinaryTree(){
    char *content=(char*)malloc(sizeof(char)*3);
    scanf("%s",content);
    node *p=createNode(atoi(content));
    if(strcmp(content,"*")==0)
        return NULL;
    else {
        rootAVL=insertNode(rootAVL,atoi(content));
        printf("left child of %d parent : ",atoi(content));
        p->left=createBinaryTree();
        printf("right child of %d parent : ",atoi(content));
        p->right=createBinaryTree();
    }
    return p;
}

int height(node *T)
{
               int lh,rh;
               if(T==NULL)
                              return(0);
               if(T->left==NULL)
                              lh=0;
               else
                              lh=1+T->left->ht;
               if(T->right==NULL)
                              rh=0;
               else
                              rh=1+T->right->ht;
               if(lh>rh)
                              return(lh);
               return(rh);
}

node * Delete(node *T,int x){
    node *p;
    if(T==NULL)
        return NULL;
    else
        if(x > T->data){                // insert in right subtree
            T->right=Delete(T->right,x);
            if(BF(T)==2){//rebalance
                if(BF(T->left)>=0)
                    T=LL(T);
                    else
                        T=LR(T);
            }
        }
    else
        if(x<T->data){ //insert in left subtree
            T->left=Delete(T->left,x);
            if(BF(T)==-2){//Rebalance
                if(BF(T->right)<=0)
                    T=RR(T);
                    else
                        T=RL(T);
                    }
        }
    else{//data to be deleted is found
        if(T->right !=NULL){  //delete its inordersuccesor
            p=T->right;
            while(p->left != NULL)
                p=p->left;
            T->data=p->data;
            T->right=Delete(T->right,p->data);
            if(BF(T)==2){//Rebalance
                if(BF(T->left)>=0)
                    T=LL(T);
                    else
                        T=LR(T);
            }
        }
    else
        return(T->left);
                        }
    T->ht=height(T);
    return(T);
}

int isBST(node *root, int min, int max){
    if (root==NULL) return 1;
    if(root->data<min || root->data>max)
        return 0;
    else return (isBST(root->right, root->data, max) && isBST(root->left, min,root->data));
}

int maximum(int a, int b){
    return (a>=b) ? a : b;
}

int height_rec(node *root){
    if (root==NULL) return 0;
    return (1+maximum(height_rec(root->left),height_rec(root->right)));
}

int isAVL(node *root){//is balanced
    int lh,rh;
    if (root==NULL) return 1;
    rh=height_rec(root->left);
    lh=height_rec(root->right);
    if((isAVL(root->left)) && (isAVL(root->right)) && (abs(rh-lh)<=1)) return 1;
    return 0;
}

void prettyPrint(node *root,int recLevel) //! root, index, length, reccurence level
{
    if(root==NULL)
    {
        recLevel--; //! reached leaf, must decrement recurence level
        return;
    }
    recLevel++; //! otherwise increment it
    prettyPrint(root->right,recLevel); //! keep going right in the tree
    int j=0;

    //! print spaces for the appropriate recurence level
    for(j=0; j<recLevel-1; j++)
    {
        printf("     ");
    }
    //! then print value
    printf("%d", root->data);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}

int main(){
    printf("root : ");
    node *root=NULL;
    root=createBinaryTree();
    while(isBST(root,INT_MIN,INT_MAX)==0){
        if (isBST(root,INT_MIN,INT_MAX)==0)
            printf("The tree is not a Binary Search Tree ! \n input again : \n");
        printf("root : ");
        node *root=createBinaryTree();
        prettyPrint(root,0);
    }
    printf("the binary search tree is : \n");
    prettyPrint(root,0);
    printf("the corresponding AVL tree is : ");
    prettyPrint(rootAVL,0);
    printf("Give the node you want to delete : \n");
    int y=1;
    while(y==1){
        int x;
        scanf("%d",&x);
        if(root==NULL) {
            printf("There is no node in the tree");
            return 0;
        }
        root=Delete(root,x);
        prettyPrint(root,0);
        printf("Do you want to delete another node? (1=yes, 0=no) \n");
        scanf("%d", &y);
    }
    return 0;
}
