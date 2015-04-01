#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodT{char *data; struct nodT *left, *right;}NodeT;
typedef struct nodL{char *data; struct nodL *prev, *next;}NodeL;
NodeL *tail;
FILE *pf_in;

NodeT *CreateBinTree()
{
    NodeT *NewNODE=(NodeT*)malloc(sizeof(NodeT));
    char *data=(char*)malloc(20);
    fscanf(pf_in, "%s ", data);
    if (strcmp(data,"*")==0)
    {
        return NULL;
    }
    else
    {
        NewNODE->data=data;
        NewNODE->left=CreateBinTree();
        NewNODE->right=CreateBinTree();
    }
    return NewNODE;
}

NodeL *GetListFromTree(NodeT *root)
{
     NodeL *NewNODE=(NodeL*)malloc(sizeof(NodeL));
     if(root==NULL)
     {
         NewNODE->data=(char*)malloc(1);
         strcpy(NewNODE->data,"*");
     }
     else
     {
         NewNODE->data=(char*)malloc(20);
         strcpy(NewNODE->data, root->data);
     }
     NewNODE->next=NULL;
     NewNODE->prev=tail;
     if(tail!=NULL)
     {
         tail->next=NewNODE;
     }
     tail=NewNODE;
     if(root!=NULL)
     {
         GetListFromTree(root->left);
         GetListFromTree(root->right);
     }
     return NewNODE;
}
NodeT *GetTreeFromList(NodeL **head)
{
    NodeT *NewNODE=(NodeT*)malloc(sizeof(NodeT));
    if(strcmp((*head)->data, "*")==0)
    {
           *head=(*head)->next;
            return NULL;
    }
    else
    {
        NewNODE->data=(*head)->data;
        *head=(*head)->next;
        free((*head)->prev);
        NewNODE->left=GetTreeFromList(head);
        NewNODE->right=GetTreeFromList(head);
    }
    return NewNODE;
}
void TraverseList(NodeL *head)
{
    while (head!=NULL)
    {
        printf("%s ", head->data);
        head=head->next;
    }
    printf("\n");

}
void PrettyPrint(NodeT *root, int nr)
{
    int i;
    if(root==NULL)
    {
        return;
    }
    PrettyPrint(root->right, nr+3);
    for(i=0; i<nr; i++)
    {
        printf(" ");
    }
    printf("%s \n", root->data);
    PrettyPrint(root->left, nr+3);
}
int main()
{
    pf_in=fopen("input.txt", "r");
    NodeT *root=CreateBinTree(pf_in);
    NodeL *FirstFromList=GetListFromTree(root);
    printf("List: ");
    TraverseList(FirstFromList);
    root=GetTreeFromList(&FirstFromList);
    printf("\n");
    printf("Tree: \n");
    PrettyPrint(root, 0);
    return 0;
}
