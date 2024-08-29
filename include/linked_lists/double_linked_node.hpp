#ifndef DOUBLE_LINKED_NODE_H
#define DOUBLE_LINKED_NODE_H

#include <linked_lists/single_linked_node.hpp>

class doubly_linked_node : public node {
    public:
        doubly_linked_node(int value, doubly_linked_node* prev_pointer=nullptr, doubly_linked_node* next_pointer=nullptr);
        doubly_linked_node* getPrev() const;
        doubly_linked_node* getNext() const override;
        void setPrev(doubly_linked_node* prev);
        void setNext(doubly_linked_node* next);
        void setNext(node* next) override;
    private:
        doubly_linked_node* prev_pointer;


};

#endif // DOUBLE_LINKED_LIST_H