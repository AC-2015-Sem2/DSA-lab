#ifndef SINGLELIST_HPP
#define SINGLELIST_HPP

#include "Node.hpp"
#include <fstream>
using std::ofstream;

class SingleList {
public:
    SingleList();
    ~SingleList();

    // getters
    int length();
    Node* getLast();

    // ops
    void addFirst(int newVal);
    void addLast(int newVal);

    void delFirst();
    void delLast();
    void delAll();
    void del(int val);

    void printAll(ofstream* out);
    void printFirst(ofstream* out, int n);
    void printLast(ofstream* out, int n);

private:
    Node* mFirst;
    int mElCount;
};

#endif // SINGLELIST_HPP
