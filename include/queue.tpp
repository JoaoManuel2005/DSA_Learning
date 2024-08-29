#ifndef QUEUE_TPP
#define QUEUE_TPP

#include <iostream>
#include "queue.hpp"

template <typename T>
Queue<T>::Queue() : q() {
    std::cout << "Queue initialized" << std::endl;
}

template <typename T>
void Queue<T>::enqueue(T value) {
    q.push(value);
    std::cout << "Enqueued item: " << value << std::endl;
}

template <typename T>
T Queue<T>::dequeue() {
    T result = q.get_header();
    q.remove(result);
    //std::cout << result << std::endl;
    std::cout << "Dequeued item: " << result << std::endl;
    return result;
}

template <typename T>
int Queue<T>::get_length() const {
    return q.get_length();
}

template <typename T>
bool Queue<T>::is_empty() const {
    return q.is_empty();
}


#endif // QUEUE_TPP