#include <stdio.h>
#include <stdlib.h>

#define MAX 10; // Max length of country names

typedef struct node
{
    int code;
    struct node* next;

    /*
    If there are no elements, then (head==tail==NULL).
    If there is only one element, then (head==tail!=NULL).
    */

} NodeT;


int main()
{
    // Clearing output.dat
    FILE *f;
    f=fopen("output.dat","w");
    FILE *pf;

    // Opening input.dat
    pf=fopen("input.dat","r");
    if (pf==NULL)
    {
        perror("Cannot open file");
        return(-1);
    }

    // Reading number of sentinels
    int n_s;
    fscanf(pf,"%d",&n_s);

    // Reading value of sentinels
    int sentinels[n_s+1];
    int sen[n_s];
    int q;
    int i;
    int tot_s=1; // total strength of sentinels (1 for the tyrant)
    for(i=0; i<n_s; i++)
    {
        fscanf(pf,"%d ",&q);
        sen[i]=sentinels[i]=q;
        tot_s=tot_s+sentinels[i];
    }
    sentinels[i]=1;

    // Reading number of countries
    int n_c;
    fscanf(pf,"%d",&n_c);

    // Reading names of countries and creating list for each country (only heads and tails are stored in arrays)
    NodeT* head[n_c];
    NodeT* tail[n_c];
    for(i=0; i<n_c; i++)
    {
        head[i]=tail[i]=NULL; // initializing heads & tails as NULL pointers
    }
    char names[n_c][10]; // array for storing country names
    int total_power[n_c]; // array for storing strength for each country
    int tot_p=0;
    for(i=0; i<n_c; i++)
    {
        fscanf(pf,"%s",names[i]); // reading name of country i
        total_power[i]=0;  // initializing total strength value
        while(fscanf(pf," %d",&q)>0)

        {
            // AL (Adding wave to list for country i):
            if ((head[i]==NULL)&&(tail[i]==NULL)) // 0 elements
            {
                head[i]=tail[i]=(NodeT*)malloc(sizeof(NodeT*));
                head[i]->code=q;
                head[i]->next=NULL;
            }
            else if((tail[i]==head[i])&&(tail[i]!=NULL)) // 1 elements
            {
                NodeT*aux=(NodeT*)malloc(sizeof(NodeT*));
                aux->code=head[i]->code;
                aux->next=tail[i];
                tail[i]->code=q;
                tail[i]->next=NULL;
                head[i]=aux;
            }
            else // more elements
            {
                NodeT*p=(NodeT*)malloc(sizeof(NodeT*));
                p->code=q;
                p->next=NULL;
                tail[i]->next=p;
                tail[i]=p;
            }
            tail[i]->next=NULL;


            total_power[i]=total_power[i]+q; // computing total strength
        }
        tot_p=tot_p+total_power[i];
    }
    fclose(pf);
    if (tot_p<tot_s)
        fprintf(f,"The tyrant survived!\n");
    else
        fprintf(f,"The tyrant was defeated!\n");

    int j=0; // index for nr. of sentinel
    while (sentinels[n_s]!=0)//||()
    {
        for(i=0; i<n_c; i++)
        {
            if (head[i]!=NULL)
            {
                sentinels[j]=sentinels[j]-head[i]->code;
                if (sentinels[j]<0) // if a sentinel is destroyed...
                {
                    sentinels[j+1]=sentinels[j+1]+sentinels[j];
                    sentinels[j]=0;
                    j++;
                }
                // DF:
                {
                    if ((head[i]==NULL)||(head[i]==tail[i]))
                    {
                        head[i]=tail[i]=NULL;
                    }
                    else
                    {
                        NodeT*p=(NodeT*)malloc(sizeof(NodeT*));
                        p=head[i];
                        head[i]=head[i]->next;
                        free(p);
                    }
                }

            }
            if (sentinels[n_s]<1) goto label;
        }
    }
label:
    fprintf(f,"The last hit was done by: %s\n",names[i]);
    int min=999999999;
    int max=-1;
    int mx,mn;
    for (i=0;i<n_c;i++)
    {
        if (min>total_power[i])
           {
                min=total_power[i];
                mn=i;
           }

        if (max<total_power[i])
        {
            max=total_power[i];
            mx=i;
        }
    }
    fprintf(f,"The strongest country was: %s\n", names[mx]);
    fprintf(f,"The weakest country was: %s\n", names[mn]);
    if (total_power[mx]<tot_s)
    {
        fprintf(f,"No country could have defeated the tyrant.\n ");
        for (q=0;q<n_s;q++)
        {
            if (total_power[mx]>sen[q])
            {
                total_power[mx]=total_power[mx]-sen[q];
                sen[q]=0;
            }
            else break;
        }
        fprintf(f,"%s could have defeated the first %d sentinels,\n and would have chipped off %d life points from sentinel %d.",names[mx],q,total_power[mx],q+1);
    }
    else
        fprintf(f,"%s could have defeated the tyrant.\n ", names[mx]);

    fclose(f);
    return 0;
}
