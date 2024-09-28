#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "linked_lists/double_linked_list.hpp"

template <typename T>
class Deque {
    private:
        doubly_linked_list<T> list;
    public:
        Deque();
        void push_back(T value);
        void push_front(T value);
        T pop_back();
        T pop_front();
        T back();
        T front();
        int get_length();
        bool is_empty();
};

#include "deque.tpp"

#endif // DEQUE_HPP