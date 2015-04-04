#include <stdio.h>
#include <stdlib.h>
#include "AVLD.h"
void prettyPrint(NodeT *root,int recLevel)
{
    if(root==NULL)
    {
        recLevel--;
        return;
    }
    recLevel++;
    prettyPrint(root->right,recLevel);
    int j=0;
    for(j=0; j<recLevel-1; j++)
    {
        printf("           ");
    }
    printf("%.0f",root->id);
    printf("\n");
    prettyPrint(root->left,recLevel);
}
void preorder(NodeT *p)
{
    if(p!=0)
    {
        printf("%.0f ",p->id);
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(NodeT *p)
{
    if(p!=0)
    {
        inorder(p->left);
        printf("%.0f ",p->id);
        inorder(p->right);
    }
}
void postorder(NodeT *p)
{
    if(p!=0)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%.0f ",p->id);
    }
}
void drum(NodeT* p,int *maxi,int lung)
{
    if (p!=NULL)
    {
        drum(p->left,&*maxi,lung+1);
        if ((p->left==NULL)&&(p->right==NULL)&&(*maxi<lung))
            *maxi=lung;
        drum(p->right,&*maxi,lung+1);
    }
}

void calcul_factor_echilibru(NodeT *p)
{
    int hightLeft=1,hightRight=1;
    if(p->left!=NULL)//daca subarborele stang al nodului repsectiv nu ii gol alculaez innaltimea
        drum(p->left,&hightLeft,1);
    else
        hightLeft=0;//daca  subarborele stang e gol nodul are inaltimea
    if(p->right!=NULL)
        drum(p->right,&hightRight,1);//daca subarborele drept mai are noduri ii calculez inaltimea
    else
        hightRight=0;//daca subarborele drept iigol de la ecest nod in jos insemna ca are inaltimea 0
    p->fact=hightRight-hightLeft;//calculez factorul de echilibrare

}

NodeT* s_rot_right(NodeT *p)
{
    NodeT *q;
    q=p->left;
    p->left=q->right;
    q->right=p;
    calcul_factor_echilibru(p);
    calcul_factor_echilibru(q);
    p=q;
    return p;
}

NodeT* s_rot_left(NodeT *p)
{
    NodeT *q;
    q=p->right;
    p->right=q->left;
    q->left=p;
    calcul_factor_echilibru(p);
    calcul_factor_echilibru(q);
    p=q;
    return p;
}

NodeT* d_rot_right(NodeT *p)
{
    p->left=s_rot_left(p);
    p=s_rot_right(p);
    return p;
}
NodeT* d_rot_left(NodeT *p)
{
    p->right=s_rot_right(p);
    p=s_rot_left(p);
    return p;
}
NodeT* echilibrare(NodeT *p)
{
    NodeT *w;
    calcul_factor_echilibru(p);//se calculeaza factorul de echilibru a nodului curent p
    //printf("\nfactorul de echilibru pt %.0f ii %d\n",p->id,p->fact);
    if(p->fact==-2) // daca p nod este critic
    {
        w=p->left; // atunci w este copilul stanga al lui p
        calcul_factor_echilibru(w);
        if (w->fact==1)// si daca acesta are factorul de echilibru 1
            p = d_rot_right(p);// atunci se face dubla rotatie dreapta

        else//altfel se face o simpla rotatie dreapta
            p = s_rot_right(p);


    }
    else if(p->fact==2) //daca p nod este critic
    {
        w=p->right;//w este copilul dreapta al nodului curent p
        if (w->fact==-1)// si acesta are factorul de ech -1
            p = d_rot_left(p);//se face o dubla rotatie stanga

        else//altfel se face o simpla rotatie stanga
            p = s_rot_left(p);


    }
    return p;
}

NodeT* creare(NodeT *p, float key)
{
    if (p==NULL)  // daca nodul curent este NULL atunci
    {
        p=(NodeT*)malloc(sizeof(NodeT)); //se aloca spatiu pentru el in zona heap
        p->id=key; //informatia devine key
        p->fact=0; // factorul de echilibru este 0 - nodul este echilibrat
        p->right=NULL;// nodul se insereaza ca nod frunza
        p->left=NULL; //deci referintele catre copii sai sunt NULL
        return p;
    }
    else
    {
        if (key<p->id) //daca cheia care se doreste inserata este mai mica ca valoare decat informatia din nodul curent
            p->left = creare(p->left,key);// atunci se insereaza in subarborele stang al nodului curent
        else if (key>p->id) //altfel daca cheia care se va insera e mai mare decat informatia din nodul curent
            p ->right = creare(p->right,key); // atunci se va insera in subarborele drept
    }
    p=echilibrare(p);
    return p;
}

NodeT* stergere(NodeT *p,float key)
{
    NodeT *q=0,*r=0,*w=0;
    if (p!=NULL)// daca nodul curent este diferit de NULL
    {
        if (key<p->id) //cheia este < decat inf din nod=>se cauta cheia in subarborele stang al nodului curent
            p->left = stergere(p->left,key);
        else if (key>p->id) // daca cheia este mai mare se cauta in subarborele drept
            p->right = stergere(p->right,key);
        else
        {
            q=p;
            if (q->right==NULL) // daca copilul drept al lui q eate NULL
                p=q->left;// atunci p devine q->stanga
            else if (q->left==NULL) //altfel daca copilul stang al lui q este NULL
                p=q->right;// p devine q->dreapta
            else
            {
                w=q->left;//altfel w este copilul stanga al lui q
                r=q;// r devine q
                if (w->right!=NULL)// daca copilul drept al lui w nu este NULL
                {
                    while (w->right!=NULL)
                    {
                        r=w;
                        w=w->right;
                    }
                    p->id=w->id;
                    q=w;
                    r->right=w->left;
                    r=p->left;
                    w=w->left;
                    if (r!=NULL)
                        while ((r!=w)&&(r!=NULL))
                        {
                            r = echilibrare(r);
                            r=r->right;
                        }
                }
                else
                {
                    p->id=w->id;
                    p->left=w->left;
                    q=w;
                }
            }
            // se sterge q
            free(q);
        }
    }
    if (p!=NULL)

        p = echilibrare(p);// se echilibreaza p daca nu este NULL
    return p;
}
