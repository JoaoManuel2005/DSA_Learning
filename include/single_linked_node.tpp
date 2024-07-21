#include "linked_lists/single_linked_node.h"
#include <stdexcept>

template <typename T>
node<T>::node(T value, node<T>* next_pointer) {
    this->value = value;
    this->next_pointer = next_pointer;
}

template <typename T>
T node<T>::getValue() const {
    return value;
}

template <typename T>
node<T>* node<T>::getNext() const {
    return next_pointer;
}

template <typename T>
void node<T>::setNext(node<T>* next) {
    next_pointer = next;
}
