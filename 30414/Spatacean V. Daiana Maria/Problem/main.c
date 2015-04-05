#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char key;
    struct node*left,*right;
} Node;

Node*constructie()
{
    Node*p;
    char c;


    //printf("\nnume nod");
    scanf("%c",&c);
    if (c=='*') return 0;
    else
    {
        p=(Node*)malloc(sizeof(Node));
        p->key=c;
        p->left=constructie();
        p->right=constructie();
    }
    return p;
}

void preorder(Node*p,int nivel)
{
    int i;
    if(p!=0)
    {
        for(i=0; i<=nivel; i++)
            printf("  ");
        printf("%c\n",p->key);
        preorder(p->left,nivel+1);
        preorder(p->right,nivel+1);
    }
}


void inorder(Node*p,int nivel)
{
    int i;
    if(p!=0)
    {


        inorder(p->left,nivel+1);
        for(i=0; i<=nivel; i++)
            printf("  ");
        printf("%c\n",p->key);
        inorder(p->right,nivel+1);
    }
}

void postorder(Node*p,int nivel)
{
    int i;
    if(p!=0)
    {


        postorder(p->left,nivel+1);
        postorder(p->right,nivel+1);
        for(i=0; i<=nivel; i++)
            printf("  ");
        printf("%c\n",p->key);
    }
}



int main()
{

    //FILE*f=fopen("data.txt","r");
    //FILE*g=fopen("out.txt","w");
    Node*rad=constructie();
    printf("\npreordine\n");
    preorder(rad,0);
    printf("\ninordine\n");
    inorder(rad,0);
    printf("\npostorder\n");
    postorder(rad,0);
    //fclose(f);
    //fclose(g);

    return 0;
}
