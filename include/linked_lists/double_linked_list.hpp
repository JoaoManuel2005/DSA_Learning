#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <linked_lists/single_linked_list.hpp>
#include <linked_lists/double_linked_node.hpp>

class doubly_linked_list : public singly_linked_list {
    public:
        doubly_linked_list();
        void initialize();
        void push(int value);
        void head_push(int value);
        void remove(int value);
        void insert(int value, int position);
        void print_list();
    private:
        doubly_linked_node* header;
        doubly_linked_node* tail;
};

#endif // DOUBLE_LINKED_LIST_H