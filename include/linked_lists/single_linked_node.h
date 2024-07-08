#ifndef SINGLE_LINKED_NODE_H
#define SINGLE_LINKED_NODE_H

class node {
    public:
        node(int value, node* next_pointer=nullptr);
        virtual int getValue() const;
        virtual node* getNext() const;
        virtual void setNext(node* next);
    protected:
        int value;
        node* next_pointer;
};

#endif // SINGLE_LINKED_NODE_H