#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct node
{
    struct node*left;
    struct node*right;
    char data[10];
} NodeT;
typedef struct NodeL
{
    char c[10];
    struct NodeL* next;
    struct NodeL* prev;
} NodeL;
NodeL*head=NULL;
NodeL*tail=NULL;
FILE *in,*out;
void AddNodeLast(char s[10])
{
    NodeL *p;
    p=(NodeL *)malloc(sizeof(NodeL));
    if ( head == NULL )
    {
        head=tail = p;
        strcpy(p->c,s);
        p->next = p->prev = NULL;
    }
    else
    {
        p->next = NULL;
        p->prev =tail;
        strcpy(p->c,s);
        tail->next = p;
        tail = p;
    }
}
NodeT*createNode(char s[10])
{
    NodeT*p=(NodeT*)malloc(sizeof(NodeT));
    strcpy(p->data,s);
    p->left=p->right=NULL;
    return p;
}
NodeT *growTreeFromList()
{

    NodeT*p=NULL;
    if(head!=NULL)
    {
        if(strcmp(head->c,"#")!=0)
        {
            p=createNode(head->c);
            head=head->next;
            p->left=growTreeFromList();
            p->right=growTreeFromList();
        }
        else
        {
            head=head->next;
        }
    }
    return p;
}

void prettyPrint(NodeT *root,int recLevel)
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
        fprintf(out,"      ");
    }
    fprintf(out,"%s",root->data);
    fprintf(out,"\n");
    prettyPrint(root->left,recLevel);
}
int main()
{
    in=fopen("math.txt","r");
    out=fopen("exptree.txt","w");
    char*pf,input[40];
    fgets(input,40,in);
    pf=strtok(input," ");
    while(pf)
    {
        AddNodeLast(pf);
        if(strcmp(pf,"-")&&strcmp(pf,"+")&&strcmp(pf,"/")&&strcmp(pf,"*"))
            //if the elemnt is a number than it's a leaf
           {
               AddNodeLast("#");
               AddNodeLast("#");
           }
        pf= strtok(NULL, " ");
    }
    NodeT*r=(NodeT*)malloc(sizeof(NodeT));
    r=growTreeFromList();
    prettyPrint(r,0);
    return 0;
}
