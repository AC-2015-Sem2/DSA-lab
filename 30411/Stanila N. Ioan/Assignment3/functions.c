#include "functions.h"

void LTinorder(BinTree* t, LIST** l) {
    if (t == NULL) {
        add_last(l, '*');
    } else {
        add_last(l, t->val);
        LTinorder(t->left, l);
        LTinorder(t->right, l);
    }
}

LIST* getListFromTree(BinTree* t) {
    LIST* l = NULL;
    LTinorder(t, &l);
    return l;
}

BinTree* TLinorder(LIST** l) {
    BinTree* t = NULL;
    if ((*l)->val == '*') {
        del_first(l);
        return NULL;
    } else {
        t = btCreateNode((*l)->val);
        del_first(l);
        t->left = TLinorder(l);
        t->right = TLinorder(l);
    }
    return t;
}

BinTree* getTreeFromList(LIST* l) {
    BinTree* t = TLinorder(&l);
    return t;
}