#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "double_linked_node.hpp"

template <typename T>
class doubly_linked_list {
    public:
        doubly_linked_list();
        void push(T value);
        void head_push(T value);
        void remove(T value);
        void insert(T value, int position);
        void print_list();
        doubly_linked_node<T>* get_header_node();
        T get_header_value();
        int get_length();
        bool is_empty();
    private:
        doubly_linked_node<T>* header;
        doubly_linked_node<T>* tail;
        std::vector<doubly_linked_node<T>> list;
        int length;
};

#include "double_linked_list.tpp"

#endif // DOUBLE_LINKED_LIST_H