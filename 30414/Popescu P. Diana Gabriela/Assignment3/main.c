#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod1
{
    int data;
    struct nod1 *left, *right;
} NodeT;

typedef struct nod2
{
    char* data;
    struct nod2 *next, *prev;
} NodeL;

NodeL* findLast(NodeL* head)
{
    while(head->next!=NULL)
        head=head->next;
    return head;
}

void addLastL(NodeL** head, char* data)
{
    if((*head)==NULL)
    {
        (*head)=(NodeL*)malloc(sizeof(NodeL));
        (*head)->data=data;
        (*head)->next=NULL;
        (*head)->prev=NULL;
    }
    else
    {
        NodeL* nnew=(NodeL*)malloc(sizeof(NodeL));
        nnew->data=data;
        nnew->next=NULL;
        NodeL* tail=findLast(*head);
        nnew->prev=tail;
        tail->next=nnew;
    }
}
/*void addLastL(NodeL** head, char* data)
{
    static NodeL* tail=NULL;
    if((*head)==NULL)
    {
        (*head)=(NodeL*)malloc(sizeof(NodeL));
        (*head)->data=data;
        (*head)->next=NULL;
        (*head)->prev=NULL;
        tail=(*head);
    }
    else
    {
        NodeL* nnew=(NodeL*)malloc(sizeof(NodeL));
        nnew->data=data;
        nnew->next=NULL;
        nnew->prev=tail;
        tail->next=nnew;
        tail=nnew;
    }
}
*/
NodeT* createNodeT(int data)
{
    NodeT* nnew=(NodeT*)malloc(sizeof(NodeT));
    nnew->data=data;
    nnew->left=NULL;
    nnew->right=NULL;
    return nnew;
}

NodeT* createBinaryTree(FILE* f)
{
    NodeT* p;
    char* data=(char*)malloc(sizeof(char)*100);
    fscanf(f, "%s", data);
    if(strcmp(data, "*")==0)
        return NULL;
    else
    {
        p=createNodeT(atoi(data));
        p->left=createBinaryTree(f);
        p->right=createBinaryTree(f);
    }
    return p;
}
//print functions:
void prettyPrint(NodeT *root,int recLevel) //! root, index, length, reccurence level
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

void printList(NodeL* head)
{
    while(head!=NULL)
        {
            printf("%s ", head->data);
            head=head->next;
        }
    printf("\n");
}
/*void printList(NodeL* head)
{
    NodeL* t = head;
    while (t != NULL)
    {
        printf("%s ", t->data);
        t = t->next;
    }
    printf("\n");
}
*/
//List/Tree functions:
/*
NodeL* ListFromTree(NodeT* root)//all elem of the list will have char type data //algorithm very similar to preorderPrint or createBinaryTree
{
    static NodeL* head=NULL;//for the first and only initialization
    if(root==NULL)
        {
            addLastL(&head, "*");
            return NULL;// it could be also "return head"--it does not matter at this level
        }
    else
    {
        char* str=(char*)malloc(sizeof(char)*100);
        itoa(root->data, str, 10);
        addLastL(&head, str);// here head is first created and then it's never changed
        ListFromTree(root->left);
        ListFromTree(root->right);
    }
    return head;
}

NodeT* TreeFromList(NodeL* head)
{
    static int ok=0;
    static NodeL* hhead;// i could not just initialize hhead with head, because it said that the initialization value is not CONSTANT
    if(ok==0)//so i thought of trying this:
        {
            hhead=head;
            ok=1;
        }
    else
        hhead=hhead->next;
    NodeT* p;
    if(strcmp(hhead->data, "*")==0)
        return NULL;
    else
    {
        p=createNodeT(atoi(hhead->data));
        p->left=TreeFromList(hhead);
        p->right=TreeFromList(hhead);
    }
    return p;
}
*/
void ListTree(NodeT* root, NodeL** head)
{
    if(root==NULL)
        {
            addLastL(head, "*");
        }
    else
    {
        char* str=(char*)malloc(sizeof(char)*100);
        itoa(root->data, str, 10);
        addLastL(head, str);
        ListTree(root->left, head);
        ListTree(root->right, head);
    }
}

NodeL* ListFromTree(NodeT* root)
{
    NodeL* head=NULL;
    ListTree(root, &head);
    return head;
}

void deleteFirst(NodeL** head)
{
    if (*head != NULL)
    {
        NodeL* t = (*head)->next;
        free(*head);
        *head = t;
    }
}

NodeT* TreeFromList(NodeL** head)
{
    NodeT* p;
    if(strcmp((*head)->data, "*")==0)
        {
            deleteFirst(head);
            return NULL;
        }
    else
    {
        p=createNodeT(atoi((*head)->data));
        deleteFirst(head);
        p->left=TreeFromList(head);
        p->right=TreeFromList(head);
    }
    return p;
}
int main()
{
    FILE* f=fopen("input.txt", "r");
    if(f==0)
        printf("err");
    NodeT *root=createBinaryTree(f);
    printf("Initial tree:\n");
    prettyPrint(root, 0);

    printf("\nList:\n");

    NodeL *head=ListFromTree(root);
    printList(head);

    printf("\nFinal tree:\n");

    root=TreeFromList(&head);
    prettyPrint(root, 0);

    fclose(f);
    return 0;
}
