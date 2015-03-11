#include "Node.hpp"

Node::Node()
    : mData(0), mNext(0) {}

Node::Node(int newData)
    : mData(newData), mNext(0) {}

Node::Node(int newData, Node* newNext)
    : mData(newData), mNext(newNext) {}

Node::~Node() {
    // don't delete the next
    // use delete from SingleList
}

// getters
int Node::data() {
    return mData;
}

Node* Node::next() {
    return mNext;
}

bool Node::isLast() {
    if (mNext == 0) {
        return true;
    } else {
        return false;
    }
}

// setters
void Node::data(int newData) {
    mData = newData;
}

void Node::linkTo(Node* newNext) {
    mNext = newNext;
}

void Node::extend(int newData) {
    mNext = new Node(newData);
}
