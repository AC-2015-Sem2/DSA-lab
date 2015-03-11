#include "SingleList.hpp"
#include <iostream>

SingleList::SingleList()
    : mFirst(0), mElCount(0) {}

SingleList::~SingleList() {
    while (mFirst != 0) {
        delFirst();
    }
}

// getters
int SingleList::length() {
    return mElCount;
}

Node* SingleList::getLast() {
    Node* k = mFirst;
    while (!k->isLast()) {
        k = k->next();
    }

    return k;
}

void SingleList::addFirst(int newVal) {
    if (mFirst == 0) {
        mFirst = new Node(newVal);
    } else {
        Node* temp = mFirst;
        mFirst = new Node(newVal);
        mFirst->linkTo(temp);
    }

    ++ mElCount;
}

void SingleList::addLast(int newVal) {
    if (mFirst == 0) {
        addFirst(newVal);
    } else {
        Node* last = this->getLast();
        last->extend(newVal);
    }

    ++ mElCount;
}

// set the pointers to zero
void SingleList::delFirst() {

    // if list is non-empty
    if (mFirst != 0) {
        if (mFirst->isLast()) {
            delete mFirst;
            mFirst = 0;
        } else {
            Node* temp = mFirst;
            mFirst = mFirst->next();
            delete temp;
        }

        -- mElCount;
    }
}

void SingleList::delLast() {

    // if list is non-empty
    if (mFirst != 0) {
        if (mFirst->isLast()) {
            // if list is non-empty
            delete mFirst;
            mFirst = 0;
        } else {
            Node* k = mFirst;
            Node* prev = mFirst;

            k = k->next();
            while (!k->isLast()) {
                prev = k;
                k = k->next();
            }
            delete k;
            prev->linkTo(0); // set as last;
        }

        -- mElCount;
    }
}

void SingleList::delAll() {
    while(mFirst != 0) {
        delFirst();
    }
}

void SingleList::del(int val) {
    if (mFirst == 0) {
        return;
    }
    Node *k = mFirst, *prev = mFirst;

    // when k == 0, doesn't check the 2nd condition
    while (k != 0 && k->data() != val) {
        prev = k;
        k = k->next();
    }
    // if val is in the list
    if (k != 0) {
        // if first element
        if (prev == k) {
            delFirst();
        } else {
            prev->linkTo(k->next());
            delete k;
            -- mElCount;
        }
    }
}

void SingleList::printAll(ofstream* out) {
    if (mFirst == 0) {
        *out << "Empty\n";
    } else {
        Node* k = mFirst;

        while (k != 0) {
            *out << k->data() << " ";
            k = k->next();
        }
        *out << "\n";
    }
}

void SingleList::printFirst(ofstream* out, int n) {
    if (n >= mElCount) {
        printAll(out);
    } else {
        Node* k = mFirst;
        for (int i = 0; i < n; i++) {
            *out << k->data() << " ";
            k = k->next();
        }
        *out << "\n";
    }
}

void SingleList::printLast(ofstream* out, int n) {
    if (n >= mElCount) {
        printAll(out);
    } else {
        Node* k = mFirst;
        int i;

        for (i = 0; i < mElCount - n; i++) {
            k = k->next();
        }

        for (i = 0; i < n; i++) {
            *out << k->data() << " ";
            k = k->next();
        }
        *out << "\n";
    }
}
