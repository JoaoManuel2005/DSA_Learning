#ifndef SINGLE_LINKED_H
#define SINGLE_LINKED_H

#include <vector>
#include "single_linked_node.h"

template <typename T>
class singly_linked_list {
    public:
        singly_linked_list();
        void initialize();
        void push(T value);
        void head_push(T value);
        void remove(T value);
        void insert(T value, int position);
        void print_list();
        T get_header();
        int get_length() const;
        bool is_empty() const;
    private:
        node<T>* header;
        node<T>* tail;
        std::vector<node<T>> list;
        int length;
};

#include "single_linked_list.tpp"

#endif // SINGLE_LINKED_H