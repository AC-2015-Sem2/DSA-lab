# include <stdlib.h>
# include <stdio.h>
# include <string.h>

FILE *input, *output;

typedef struct nod
{
    struct nod *left, *right;
    char *data;
}NODET;

NODET *root;

typedef struct nod1
{
    struct nod1 *next, *prev;
    char *data;
}NODEL;

NODET* createNODE(char *d)
{
    NODET *p;
    p=(NODET*)malloc(sizeof(NODET));
    p->data=d;
    p->left=NULL;
    p->right=NULL;
    return p;
}

NODET* createBinTree()
{
    NODET *p;
    char *data=(char*)malloc(sizeof(char)*10);
    fscanf(input,"%s",data);
    if(strcmp(data,"*")==0)
        return NULL;
    else
    {
        p=createNODE(data);
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}

NODEL *getListFromTree(NODET *root)
{
    NODEL *head;
    head=NULL;
    create(&head,root);
    return head;

}

void create(NODEL **head,NODET *root)
{
    if(root==NULL)
            AL(head,"*");
    else
        {
        AL(head, root->data);
        create(head,root->left);
        create(head,root->right);
        }
}

void AL(NODEL **head, char *data)
{
    if (*head == NULL)
    {
        *head = (NODEL*)malloc(sizeof(NODEL));
        (*head)->data = data;
        (*head)->next = NULL;
    }
    else
    {
        NODEL *newnode, *p;
        p = *head;
        while (p->next != NULL)
            p = p->next;
        newnode=(NODEL*)malloc(sizeof(NODEL));
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = p;
        p->next = newnode;

    }
}

void traverseList(NODEL *head)
{
    while(head!=NULL)
    {
        fprintf(output,"%s ",head->data);
        head=head->next;
    }
    fprintf(output,"\n");
}

NODET* getTreeFromList(NODEL **head)
{NODET *x;
    if(strcmp((*head)->data, "*") == 0)
    {
        *head=(*head)->next;
        return NULL;
    }
    else
    {
        x=createNODE((*head)->data);
        *head=(*head)->next;
        x->left=getTreeFromList(head);
        x->right=getTreeFromList(head);
        return x;
    }
}
void prettyPrint(NODET *root,int recLevel)
{
    if(root==NULL)
    {
        recLevel--;
        return;
    }
    recLevel++;
    prettyPrint(root->right,recLevel);
    int i=0;
    for(i=0; i<recLevel-1; i++)
        fprintf(output,"  ");

    fprintf(output,"%s", root->data);
    fprintf(output,"\n");
    prettyPrint(root->left,recLevel);
}

int main()
{
 input=fopen("input.dat", "r");
 output=fopen("output.dat", "w");
 NODET *root=createBinTree();
 NODEL *firstFromList=getListFromTree(root);
 traverseList(firstFromList);
 root=getTreeFromList(&firstFromList);
 prettyPrint(root,0);
 return 0;
}
