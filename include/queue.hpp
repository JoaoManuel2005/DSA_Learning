#ifndef QUEUE_H
#define QUEUE_H

#include "linked_lists/single_linked_list.hpp"

template <typename T>
class Queue {
    public: 
        Queue();
        void enqueue(T value);
        T dequeue();
        int get_length() const;
        bool is_empty() const;
    private:
        singly_linked_list<T> q;

};

#include "queue.tpp"

#endif // QUEUE_H