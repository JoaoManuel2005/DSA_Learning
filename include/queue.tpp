#ifndef QUEUE_TPP
#define QUEUE_TPP

#include <iostream>
#include "queue.h"

template <typename T>
Queue<T>::Queue() : q() {}

template <typename T>
void Queue<T>::enqueue(T value) {
    q.push(value);
}

template <typename T>
T Queue<T>::dequeue() {
    T result = q.get_header();
    q.remove(result);
    //std::cout << result << std::endl;
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