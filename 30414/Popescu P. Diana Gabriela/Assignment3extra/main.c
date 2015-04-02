#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod1
{
    char* data;
    struct nod1* next;
} NodeQ;

typedef struct nod2
{
    char* data;
    struct nod2 *left, *right;
} NodeT;
/*
void enqueue(NodeQ** head, char* data)
{
    static NodeQ* tail=NULL;
    if((*head)==NULL)
    {
        (*head)=(NodeQ*)malloc(sizeof(char)*100);
        (*head)->next=NULL;
        (*head)->data=data;
        tail=(*head);
    }
    else
    {
        NodeQ* nnew=(NodeQ*)malloc(sizeof(char)*100);//! alloc memory for string!!!!
        nnew->data=data;
        nnew->next=NULL;
        tail->next=nnew;
        tail=nnew;
    }
}
*/
void enqueue(NodeQ** head, char* data)
{
    NodeQ* nnew=(NodeQ*)malloc(sizeof(NodeQ));
    nnew->data=(char*)malloc(sizeof(char)*100);
    nnew->data=data;
    nnew->next=NULL;
    if((*head)==NULL)
        (*head)=nnew;
    else
        {
            NodeQ* tail=*head;
            while(tail->next!=NULL)
                tail=tail->next;
            tail->next=nnew;
        }
}

void dequeue(NodeQ** head)
{
    if ((*head)!=NULL)
    {
        NodeQ* t=(*head)->next;
        free(*head);
        (*head)=t;
    }
}

NodeT* createNodeT(char* data)
{
    NodeT* nnew=(NodeT*)malloc(sizeof(char)*100);
    nnew->data=data;
    nnew->left=NULL;
    nnew->right=NULL;
    return nnew;
}

/*
void printList(NodeQ* head)
{
    while (head != NULL)
    {
        printf("%s ", head->data);
        head =head->next;
    }
    printf("\n");
}
*/

void prettyPrintTree(NodeT *root,int recLevel) //! root, index, length, reccurence level
{
    if(root==NULL)
    {
        recLevel--; //! reached leaf, must decrement recurence level
        return;
    }
    recLevel++; //! otherwise increment it
    prettyPrintTree(root->right,recLevel); //! keep going right in the tree
    int j=0;

    //! print spaces for the appropriate recurence level
    for(j=0; j<recLevel-1; j++)
    {
        printf("     ");
    }
    //! then print value
    printf("%s", root->data);

    //! print  a new line
    printf("\n");

    prettyPrintTree(root->left,recLevel); //! keep going left in the tree
}

NodeT* TreeFromQueue(NodeQ** head)
{
    NodeT* p;
    if(!(strcmp((*head)->data,"*")==0 || strcmp((*head)->data,"-")==0 || strcmp((*head)->data,"+")==0 || strcmp((*head)->data,"/")==0))
    {
        p=createNodeT((*head)->data);
        dequeue(head);
        return p;
    }
    else
    {
        p=createNodeT((*head)->data);
        dequeue(head);
        p->left=TreeFromQueue(head);
        p->right=TreeFromQueue(head);
    }
    return p;
}

int main()
{
    NodeQ* head=NULL;
    NodeT* root=NULL;
    FILE* f=fopen("input.txt", "r");
    if(f==0)
        printf("err");
    char* s=(char*)malloc(sizeof(char)*100);

    fscanf(f, "%[^\n]s", s);
    printf("%s\n", s);

    //create queue:
    char* token=strtok(s, " ");
    while(token!=NULL)
    {
        enqueue(&head, token);
        token=strtok(NULL, " ");
    }

    root=TreeFromQueue(&head);
    prettyPrintTree(root, 0);
    return 0;
}
