#ifndef SINGLE_LINKED_NODE_H
#define SINGLE_LINKED_NODE_H

class node {
    public:
        node(int value, node* next_pointer=nullptr);
        int getValue();
        node* getNext();
        void setNext(node* next_pointer);
    private:
        int value;
        node* next_pointer;
};

#endif // SINGLE_LINKED_NODE_H