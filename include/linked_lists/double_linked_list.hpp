#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "double_linked_node.hpp"

template <typename T>
class doubly_linked_list {
    private:
        doubly_linked_node<T>* header;
        doubly_linked_node<T>* tail;
        std::vector<doubly_linked_node<T>> list;
        int length;
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

        class iterator {
            private:
                doubly_linked_node<T>* current;
                doubly_linked_node<T>*dummy_node;
            public:
                using value_type = T;
                using difference_type = std::ptrdiff_t;
                using pointer = T*;
                using reference = T&;
                using iterator_category = std::bidirectional_iterator_tag;

                // constructor for iterator
                iterator(doubly_linked_node<T>* header_ptr, doubly_linked_node<T>* ptr) : current(header_ptr), dummy_node(ptr) {}
                // Dereference operator to access value of node iterator is pointing to
                T operator*() const {return current->getValue();}

                // Pointer operator to return a pointer to the value of the node
                pointer operator->() const {return &(current->getValue());}

                //Pre-incrememnt to move to the next node
                iterator& operator++() {
                    current = current->getNext();
                    return *this;
                }

                //Pre-decrememnt to move to the previous node
                iterator& operator--() {
                    if (current == nullptr) {
                        current = dummy_node->getPrev();
                    }
                    else {
                        current = current->getPrev();
                    }
                    return *this;
                }
                // Equality check
                bool operator==(const iterator& other) const {return current == other.current; }

                // Inequality check
                bool operator!=(const iterator& other) const {return current != other.current; }
        };
        iterator begin() { return iterator(header, nullptr); }
        iterator end() { 
            doubly_linked_node<T>* node = new doubly_linked_node<T>(header->getValue(), tail, nullptr);
            //doubly_linked_node<T>* ptr = &node;
            return iterator(nullptr, node); 
        }
};

#include "double_linked_list.tpp"

#endif // DOUBLE_LINKED_LIST_H