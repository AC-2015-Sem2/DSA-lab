#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct nodeBT{
    int data;
    int ht;
    struct nodeBT *left, *right;
}node;

void prettyPrint(node *root,int recLevel);

node *createNode(int x){
    node *p=(node*)malloc(sizeof(node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

node *createBinaryTree(){
    char *content=(char*)malloc(sizeof(char)*3);
    scanf("%s",content);
    node *p=createNode(atoi(content));
    if(strcmp(content,"*")==0)
        return NULL;
    else {
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

node *createAVL(node *root){
    if(isAVL(root->right)!=1)
        {
        root->right=createAVL(root->right);
        if (BF(root)==-2)
            {
            if (BF(root->right)==-1){
                root=RR(root);
                return root;
            }
            else
            if (BF(root->right)==1){
                root=RL(root);
                return root;
            }
            }
        else
        if(isAVL(root->right)==1 && isAVL(root)!=1)//the possibility that the subtree is AVL, yet the tree is not
            {
            root=rotateleft(root);//rotate left because the value of the root is the smallest
            root->left=createAVL(root->left);//make sure the subtree is AVL
            return root;
            }
        }
    if(isAVL(root->left)!=1)
        {
            root->left=createAVL(root->left);
            if (BF(root)==2)
            {
            if (BF(root->left)==1){
                root=LL(root);
                return root;
            }
            else{
                root=LR(root);
                return root;
            }
            }
        }
        else
        if(isAVL(root->left)==1)//the possibility that the subtree is AVL, yet the tree is not
        {
            root=rotateright(root);//rotate the tree right because the value of the root is the greatest
            root->right=createAVL(root->right);//make sure the subtree is AVL
            return root;
        }
    return root;
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
    node *root=createBinaryTree();
    while(isBST(root,INT_MIN,INT_MAX)==0){
        if (isBST(root,INT_MIN,INT_MAX)==0)
            printf("The tree is not a Binary Search Tree ! \n input again : \n");
        printf("root : ");
        node *root=createBinaryTree();
        prettyPrint(root,0);
    }
    prettyPrint(root,0);
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
        if (isAVL(root)!=1){
                printf("The tree is not an AVL tree\n");
                printf("Do you want to create the corresponding AVL tree? ? (yes-1, no-0) : ");
                scanf("%d",&x);
                if(x==1) {
                    printf("The corresponding AVL tree is : \n" );
                    root=createAVL(root);
                }
            }
        prettyPrint(root,0);
        printf("Do you want to delete another node? (1=yes, 0=no) \n");
        scanf("%d", &y);
    }
    return 0;
}
