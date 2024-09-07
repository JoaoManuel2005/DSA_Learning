#ifndef QUEUE_TPP
#define QUEUE_TPP

#include <iostream>
#include "queue.hpp"

template <typename T>
Queue<T>::Queue() : q() {
    std::cout << "Queue initialized" << std::endl;
}

/**
 * Pushes new value to the underlying linked list that forms the queue
 * @param value - value stored in node that we want to add to linked list
*/
template <typename T>
void Queue<T>::enqueue(T value) {
    q.push(value);
    //std::cout << "Enqueued item: " << value << std::endl;
}

/**
 * Removes header node from underlying linked list that forms the queue
 * First it gets the header value than uses that as the value to search for to remove in linked lists remove function
 * @return value stored in lists header node that was removed
*/
template <typename T>
T Queue<T>::dequeue() {
    T result = q.get_header_value();
    q.remove(result);
    //std::cout << result << std::endl;
    //std::cout << "Dequeued item: " << result << std::endl;
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