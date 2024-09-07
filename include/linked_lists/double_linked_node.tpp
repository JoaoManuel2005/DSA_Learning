#include "linked_lists/double_linked_node.hpp"
#include <stdexcept>

/**
 * Constructor for node 
 * @param value - value held in node
 * @param prev_pointer - pointer to memory address of previous node in linked list
 * @param next_pointer - pointer to memory address of next node in linked list
*/
template <typename T>
doubly_linked_node<T>::doubly_linked_node(T value, doubly_linked_node<T>* prev_pointer, doubly_linked_node<T>* next_pointer)
    : value(value), prev_pointer(prev_pointer), next_pointer(next_pointer) {};

/**
 * Getter for node's value
 * @return value - returns value held in node
*/
template <typename T>
T doubly_linked_node<T>::getValue() {
    return value;
}

/**
 * Getter for node's prev pointer
 * @return prev_pointer - returns pointer to memory address of previous node in linked list
*/
template <typename T>
doubly_linked_node<T>* doubly_linked_node<T>::getPrev() {
    return prev_pointer;
}

/**
 * Getter for node's next pointer
 * @return next_pointer - returns pointer to memory address of next node in linked list
*/
template <typename T>
doubly_linked_node<T>* doubly_linked_node<T>::getNext() {
    return next_pointer;
}

/**
 * Setter for node's prev pointer
 * @param prev - pointer to memory address of previous node in linked list
*/
template <typename T>
void doubly_linked_node<T>::setPrev(doubly_linked_node<T>* prev) {
    prev_pointer = prev;
}

/**
 * Setter for node's next pointer
 * @param next - pointer to memory address of next node in linked list
*/
template <typename T>
void doubly_linked_node<T>::setNext(doubly_linked_node<T>* next) {
    next_pointer = next;
}
