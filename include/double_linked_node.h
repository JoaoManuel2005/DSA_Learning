#ifndef DOUBLE_LINKED_NODE_H
#define DOUBLE_LINKED_NODE_H

#include <single_linked_node.h>

class doubly_linked_node : public node {
    public:
        doubly_linked_node(int value, doubly_linked_node* prev_pointer=nullptr, doubly_linked_node* next_pointer=nullptr);
        doubly_linked_node* getPrev() const;
        doubly_linked_node* getNext() const override;
        void setPrev(doubly_linked_node* prev);
        void setNext(node* next) override;
        void setNext(doubly_linked_node* next);
    private:
        doubly_linked_node* prev_pointer;


};

#endif // DOUBLE_LINKED_LIST_H