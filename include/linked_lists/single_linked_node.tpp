#include "single_linked_node.hpp"
#include <stdexcept>

/**
 * Constructor for node 
 * @param value - value held in node
 * @param next_pointer - pointer to memory address of next node in linked list
*/
template <typename T>
node<T>::node(T value, node<T>* next_pointer) : value(value), next_pointer(next_pointer) {
    // this->value = value;
    // this->next_pointer = next_pointer;
}

/**
 * Getter for node
 * @return value - returns value held in node
*/
template <typename T>
T node<T>::getValue() const {
    return value;
}

/**
 * Getter for node
 * @return next_pointer - returns pointer to memory address of next node in linked list
*/
template <typename T>
node<T>* node<T>::getNext() const {
    return next_pointer;
}

/**
 * Setter for node
 * @param next - pointer to memory address of next node in linked list
*/
template <typename T>
void node<T>::setNext(node<T>* next) {
    next_pointer = next;
}
