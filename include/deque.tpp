#include "deque.hpp"

template<typename T>
Deque<T>::Deque() : list() {}

template<typename T>
void Deque<T>::push_back(T value) {
    list.push(value);
}

template<typename T>
void Deque<T>::push_front(T value) {
    list.head_push(value);
}

template<typename T>
T Deque<T>::pop_back() {
    auto it = list.end();
    --it;
    it->getPrev()->setNext(nullptr);
    T value = *it;
    return value;
}

template<typename T>
T Deque<T>::pop_front() {
    T value = list.get_header_value();
    list.remove(value);
    return value;
}

template<typename T>
T Deque<T>::back() {
    auto it = list.end();
    --it;
    T value = *it;
    return value;
}

template<typename T>
T Deque<T>::front() {
    return list.get_header_value();
}

template<typename T>
int Deque<T>::get_length() {
    return list.get_length();
}

template<typename T>
bool Deque<T>::is_empty() {
    return list.is_empty();
}

