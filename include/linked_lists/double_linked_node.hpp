#ifndef DOUBLE_LINKED_NODE_H
#define DOUBLE_LINKED_NODE_H

#include <linked_lists/single_linked_node.hpp>

template <typename T>
class doubly_linked_node {
    public:
        doubly_linked_node(T value, doubly_linked_node* prev_pointer=nullptr, doubly_linked_node* next_pointer=nullptr);
        T getValue();
        doubly_linked_node* getPrev();
        doubly_linked_node* getNext();
        void setPrev(doubly_linked_node* prev);
        void setNext(doubly_linked_node* next);

    private:
        T value;
        doubly_linked_node* next_pointer;
        doubly_linked_node* prev_pointer;

};

#include "double_linked_node.tpp"

#endif // DOUBLE_LINKED_LIST_H