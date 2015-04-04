#ifndef AVLD_H_INCLUDED
#define AVLD_H_INCLUDED
typedef struct node
{
    float id;
    struct node *left,*right;
    int fact;//fact reprezinta factorul de echilibru si poate lua val -1,0,1 si e = cu hstanga-hdreapta
}NodeT;
NodeT* s_rot(NodeT *p);
NodeT* d_rot(NodeT *p);
void prettyPrint(NodeT *p,int recLevel);
void preorder(NodeT *p);
void inorder(NodeT *p);
void postorder(NodeT *p);
void drum(NodeT* p,int *maxi,int lung);
void calcul_factor_echilibru(NodeT *p);
NodeT* s_rot_right(NodeT *p);
NodeT* s_rot_left(NodeT *p);
NodeT* d_rot_right(NodeT *p);
NodeT* d_rot_left(NodeT *p);
NodeT* echilibrare(NodeT *p);
NodeT* creare(NodeT *p, float key);
NodeT* stergere(NodeT *p, float key);




#endif // AVLD_H_INCLUDED
