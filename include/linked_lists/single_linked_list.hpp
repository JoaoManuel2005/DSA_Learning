#ifndef SINGLE_LINKED_H
#define SINGLE_LINKED_H

#include <vector>
#include "single_linked_node.hpp"

template <typename T>
class singly_linked_list {

    private:
        node<T>* header;
        node<T>* tail;
        std::vector<node<T>> list;
        int length;

    public:
        singly_linked_list();
        void push(T value);
        void head_push(T value);
        void remove(T value);
        void insert(T value, int position);
        void print_list();
        node<T>* get_header_node();
        T get_header_value();
        int get_length() const;
        bool is_empty() const;

        class iterator {
            private:
                // Current node iterator is pointing to 
                node<T>* current;

            public:
                // typedefs to define iterator traits
                using value_type = T;
                using difference_type = std::ptrdiff_t;
                using pointer = T*;
                using reference = T&;
                using iterator_category = std::forward_iterator_tag;

                // constructor for iterator
                iterator(node<T>* ptr) : current(ptr) {}

                // Dereference operator to access value of node iterator is pointing to
                T operator*() const {return current->getValue();}

                // Pointer operator to return a pointer to the value of the node
                pointer operator->() const {return &(current->getValue());}

                //Pre-incrememnt to move to the next node
                iterator& operator++() {
                    current = current->getNext();
                    return *this;
                }
                // Equality check
                bool operator==(const iterator& other) const {return current == other.current; }

                // Inequality check
                bool operator!=(const iterator& other) const {return current != other.current; }
        };
        iterator begin() { return iterator(header); }
        iterator end() { return iterator(nullptr); }
};

#include "single_linked_list.tpp"

#endif // SINGLE_LINKED_H

