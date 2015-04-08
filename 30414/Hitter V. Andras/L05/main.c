#include"header.h"

int main()
{
    FILE *f=fopen("input.txt","r");
    if(!f)
    {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    NodeT *root=NULL;
    int n,i,x;
    printf("\nEnter no.of elements :");
    scanf("%d",&n);
    printf("\n Enter tree data :");
    root=NULL;
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    prettyPrint(root,0);

    printf("\nEnter no.of elements :");
    scanf("%d",&n);
    printf("\n Enter data for deletion:");
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        root=deletion(root,x);
    }
    prettyPrint(root,0);
    return 0;
}
