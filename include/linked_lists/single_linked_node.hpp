#ifndef SINGLE_LINKED_NODE_H
#define SINGLE_LINKED_NODE_H

template <typename T>
class node {
    public:
        node(T value, node* next_pointer=nullptr);
        virtual T getValue() const;
        virtual node* getNext() const;
        virtual void setNext(node* next);
    protected:
        T value;
        node* next_pointer;
};

#include "single_linked_node.tpp"

#endif // SINGLE_LINKED_NODE_H