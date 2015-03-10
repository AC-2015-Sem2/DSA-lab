#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int dmg;
    struct node* next;
} node;
typedef struct node2
{
    int power;
    char name[20];
    struct node2* next;
    struct node* wave;
    struct node* army;
} node2;
int main()
{
    node *pp,*p,*sentinel;
    node2 *qq,*q,*country,*sc,*wc,*ks;
    int o,k,ko,wipe=0,hp,wave,sentpow=0,oneshot=0,n,m,i,x;
    char s[100],s2[100];
    FILE *f,*g;
    f=fopen("input.dat","r");
    g=fopen("output.dat","a");
    fscanf(f,"%d",&n);
    sentinel=(node*)malloc(sizeof(node));
    fscanf(f,"%d",&sentinel->dmg);
    sentpow=sentinel->dmg;
    sentinel->next=NULL;
    pp=sentinel;
    for (i=1; i<n; i++)
    {
        p=(node*) malloc (sizeof(node));
        fscanf(f,"%d",&p->dmg);
        pp->next=p;
        p->next=NULL;
        pp=p;
        sentpow=sentpow+p->dmg;
    }
    fscanf(f,"%d",&m);
    country=(node2*)malloc(sizeof(node2));
    fscanf(f,"%s",&country->name);
    country->next=NULL;
    p=(node*)malloc(sizeof(node));
    country->army=p;
    fscanf(f,"%d",&p->dmg);
    country->power=p->dmg;
    country->wave=country->army;
    p->next=NULL;
    pp=p;
    for (k=0; k<100; k++) s[k]='a';
    fgets(s,100,f);
    for (k=0; k<strlen(s); k++) s[k]=s[k+1];
    while ((s[0]>='0') && (s[0]<='9'))
    {
        p=(node*)malloc(sizeof(node));
        sscanf(s,"%d",&x);
        sprintf(s2,"%d",x);
        o=strlen(s);
        for (k=0; k<o; k++) s[k]=s[k+strlen(s2)+1];
        s[o]='\n';
        p->dmg=x;
        country->power=country->power+p->dmg;
        pp->next=p;
        p->next=NULL;
        pp=p;
    }
    qq=country;
    sc=country;
    wc=sc;
    oneshot=country->power;
    for (i=1; i<m; i++)
    {
        q=(node2*)malloc(sizeof(node2));
        fscanf(f,"%s",q->name);
        q->next=NULL;
        qq->next=q;
        p=(node*)malloc(sizeof(node));
        qq=q;
        q->army=p;
        q->wave=q->army;
        pp=p;
        fscanf(f,"%d",&p->dmg);
        q->power=p->dmg;
        p->next=NULL;
        for (k=0; k<100; k++) s[k]='a';
        fgets(s,100,f);
        for (k=0; k<strlen(s); k++) s[k]=s[k+1];
        while ((s[0]>='0') && (s[0]<='9'))
        {
            p=(node*)malloc(sizeof(node));
            sscanf(s,"%d",&x);
            o=strlen(s);
            sprintf(s2,"%d",x);
            for (k=0; k<o; k++) s[k]=s[k+strlen(s2)+1];
            s[o]='\n';
            p->dmg=x;
            q->power=q->power+p->dmg;
            pp->next=p;
            p->next=NULL;
            pp=p;
        }
        if (q->power>sc->power) sc=q;
        oneshot=oneshot+q->power;
        if (q->power<wc->power) wc=q;
    }
    if (oneshot>sentpow) fprintf(g,"Kim Jong Nu Has Fallen!!!\n");
    else fprintf(g,"Wipe!\n");
    hp=sentpow;
    while ((hp>=0) && (!wipe))
    {
        q=country;
        ko=0;

        while (q!=NULL)
        {   if (q->wave!=NULL){
            p=q->wave;
            hp=hp-p->dmg;
            if (hp<0) ks=q;}
            q->wave=p->next;
            if (q->wave==NULL) ko++;
            q=q->next;
        }
        if (ko==m) wipe=1;
    }
    if (!wipe) fprintf(g,"KS:%s\n",ks->name);
    fprintf(g,"OP:%s\n",sc->name);
    fprintf(g,"NOOB:%s\n",wc->name);
    if (sc->power>sentpow)
    {
        fprintf(g,"The following countries could defeat the sentinel alone:");
        q=country;
        while (q!=NULL)
        {
            if (q->power>sentpow) fprintf(g,"%s ",q->name);
            q=q->next;
        }
    }
    else
    {
        fprintf(g,"No country could have defeated the sentinel alone.\n");
        hp=sc->power;
        i=0;
        p=sentinel;
        while (hp-p->dmg>=0)
        {
            i++;
            hp=hp-p->dmg;
            p=p->next;
        }
        fprintf(g,"%s alone could defeat %d sentinel(s) and deal additional %d damage to sentinel nr. %i.",sc->name,i,hp,i+1);
    }
    fclose(f);
    fclose(g);
    return 0;
}
