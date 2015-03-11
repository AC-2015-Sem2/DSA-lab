#ifndef NODE_HPP
#define NODE_HPP

class Node {
public:
    Node();
    Node(int newData);
    Node(int newData, Node* newNext);
    ~Node();

    // getters
    int data();
    Node* next();
    bool isLast();

    // setters
    void data(int newData);
    void linkTo(Node* newNext);
    void extend(int newData);
    // creates a new node in extension
    // of this node

private:
    int mData;
    Node* mNext;
};

#endif // NODE_HPP
