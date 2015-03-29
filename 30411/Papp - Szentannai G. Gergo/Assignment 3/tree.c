#include "tree.h"


void AL( NodeL** head, NodeL** tail,  char *x)  // Almost the same as in SLL assignment
{
    if ((*head==NULL)&&(*tail==NULL))
    {
        *head=*tail=(NodeL*)malloc(sizeof(NodeL*));
        (*head)->str=x;
        (*head)->next=NULL;
    }
    else if((*tail==*head)&&(*tail!=NULL))
    {
        NodeL*aux=(NodeL*)malloc(sizeof(NodeL*));
        aux->str=(*head)->str;
        aux->next=*tail;
        (*tail)->str=x;
        (*tail)->next=NULL;
        (*head)=aux;

    }
    else
    {
        NodeL*p=(NodeL*)malloc(sizeof(NodeL*));
        p->str=x;
        p->next=NULL;
        (*tail)->next=p;
        (*tail)=p;
    }
    (*tail)->next=NULL;
}

void DF(NodeL** head)  // Delete First
{

        NodeL*p=(NodeL*)malloc(sizeof(NodeL*));
        p=(*head);
        *head=(*head)->next;
        free(p);
}

void PRINT_ALL(NodeL* head)  // As in SLL assignment
{
    NodeL* aux=(NodeL*)malloc(sizeof(NodeT*));
    aux=head;

    while(aux!=NULL)
    {
        printf("%s ",aux->str);
        aux=aux->next;
    }
    printf("\n");
}



void preorder(NodeT * root, NodeL** head, NodeL** tail)
{
    if (root == NULL)
        AL(head, tail,"*");  // mark children with '*'
    else if ( root != NULL )
    {
        AL(head, tail, root->str);  // Add nodes
        preorder( root->left, head, tail) ;
        preorder( root->right, head, tail) ;
    }
}

void printStringElement(NodeT * node)
{
    printf ( "%s " ,(char*) node->str );
}

NodeT *  createBinTree(FILE* in)  // Read from input.txt
{
    NodeT *p;
    char *content = (char*)malloc(sizeof(char)*MAX_SIZE_OF_CONTENT);

    fscanf(in, "%s " ,content );
    if ( strcmp(content,"*")==0 )
        return NULL;
    else
    {
        char * cont = content;
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->str = cont;
        p->left = createBinTree(in) ;
        p->right = createBinTree(in) ;
    }
    return p;
}


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
    printStringElement(root);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}


NodeL * getListFromTree(NodeT* root)
{
    NodeL **head=(NodeL**)malloc(sizeof(NodeL**));
    NodeL **tail=(NodeL**)malloc(sizeof(NodeL**));
    *head=*tail=NULL;


    // I used the preorder function, but inorder and postorder would also do it (it would give different structure/same result)
    preorder(root, head, tail);   // Reads the list and uses the Add Last function to generate list

    return *head;
}


void printList(NodeL *list)
{
    PRINT_ALL(list);
}


NodeT * getTreeFromList(NodeL** list)
{
    NodeT *p;
    char *content = (char*)malloc(sizeof(char)*MAX_SIZE_OF_CONTENT);

    strcpy(content,(*list)->str);
    DF(list);

    if ( strcmp(content,"*")==0 )
        return NULL;
    else
    {
        char * cont = content;
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->str = cont;
        p->left = getTreeFromList(list);
        p->right = getTreeFromList(list) ;
    }

    return p;
}
