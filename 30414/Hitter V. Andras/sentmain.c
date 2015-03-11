#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;

} node;


int main()
{
    FILE *g;
    g=fopen("output.dat","w");

    FILE *f;
    f=fopen("input.dat","r");
    if (f==NULL)
    {
        perror("ERROR");
        return(-1);
    }

    int nrsent;
    fscanf(f,"%d",&nrsent);
    int sent[nrsent], sentinels[nrsent+1], x, i, totsent=1, j=0, nrcountry;;

    for(i=0; i<nrsent; i++)
    {
        fscanf(f,"%d ",&x);
        sent[i]=x;
        sentinels[i]=x;
        totsent=totsent+sentinels[i];
    }
    sentinels[i]=1;

    fscanf(f,"%d",&nrcountry);

    int power[nrcountry], p=0;
    char names[nrcountry][10];

    node* head[nrcountry];
    node* tail[nrcountry];
    for(i=0; i<nrcountry; i++)
    {
        head[i]=NULL;
        tail[i]=head[i];
    }

    for(i=0; i<nrcountry; i++)
    {
        fscanf(f,"%s",names[i]);
        while(fscanf(f," %d",&x)>0)
        {
        if ((head[i]==NULL)&&(tail[i]==NULL))
        {
            head[i]=(node*)malloc(sizeof(node*));
            tail[i]=(node*)malloc(sizeof(node*));
            head[i]->data=x;
            head[i]->next=NULL;
        }
        else if((head[i]==tail[i])&&(head[i]!=NULL))
             {
                node*aux=(node*)malloc(sizeof(node*));
                aux->data=head[i]->data;
                aux->next=tail[i];
                tail[i]->data=x;
                tail[i]->next=NULL;
                head[i]=aux;
             }
             else
             {
                node*pow=(node*)malloc(sizeof(node*));
                pow->data=x;
                pow->next=NULL;
                tail[i]->next=pow;
                tail[i]=pow;
             }
             tail[i]->next=NULL;

            power[i]=power[i]+x;
        }
        p=p+power[i];
    }
    fclose(f);
    if (p<totsent) fprintf(g,"The tyrant survived!\n");
    else fprintf(g,"The tyrant was defeated!\n");

    while (sentinels[nrsent]!=0)

return 0;
}
