#include "double_linked_list.hpp"
#include "double_linked_node.hpp"
#include <iostream>

/**
 * Constructor for double linked list
 * Initialises header and tail both to be null pointers
 * Initalises list length to be 0
**/
template <typename T>
doubly_linked_list<T>::doubly_linked_list() : header(nullptr), tail(nullptr), length(0) {}

/**
 * Function to push new node to linked list
 * Creates new node
 * Set's current tails next pointer to new node. Sets new nodes prev pointer to current tail
 * Set's tail to be new node, effectively pushing it to end of list
 * @param value - values stored in new node
*/
template <typename T>
void doubly_linked_list<T>::push(T value) {
    if (this->tail==nullptr && this->header==nullptr) {
        doubly_linked_node<T>* temp = new doubly_linked_node<T>(value);
        this->header = temp;
        this->tail = temp;
    }
    else {
        doubly_linked_node<T>* temp = new doubly_linked_node<T>(value);
        this->tail->setNext(temp);
        temp->setPrev(tail);
        this->tail = this->tail->getNext();
    }
}

/**
 * Pushes new node to list but at head
 * @param value - value that is stored in the node we want to add to list
 * @brief Creates new node whos next pointer is the current list header
 * Sets current lists header prev pointer to be the new node
 * Makes lists new header this new node, effectively pushing new node at head of list
*/
template <typename T>
void doubly_linked_list<T>::head_push(T value) {
    doubly_linked_node<T>* temp = new doubly_linked_node<T>(value, nullptr, this->header);
    header->setPrev(temp);
    this->header = temp;
}

/**
 * Removes node from linked list 
 * @param value - value that is stored in the node we want to remove from list
 * Iterates through list to find desired node to remove
 * When we find it, we set the previous nodes next pointer to the next of the desired node,
 * then we set the next of the desired nodes' prev pointer to be the previous of the desired node
 * effectively removing it as a link
*/
template <typename T>
void doubly_linked_list<T>::remove(T value) {
    if (header == nullptr) return;

    doubly_linked_node<T>* current = this->header;
    if (header->getValue() == value) {
        header = header->getNext();
        header->setPrev(nullptr);
        return;
    }
    bool found = false;
    while (!found && current != nullptr) {
        if (current->getNext() != nullptr && current->getNext()->getValue() == value) {
            current->setNext(current->getNext()->getNext());
            current->getNext()->setPrev(current);
            found = true;
        }
        else {
            current = current->getNext();
        }
    }
}

/**
 * Pushes new node to list but at a specific position that we specify
 * @param value - value stored in the node we want to add
 * @param position - numbered position we want to add new node in list
 * We iterate through list until the node position before we want to add
 * We create a new node whos prev pointer is the node we iterated until
 * and whose next pointer is the next node of the node we iterated until
 * effectively adding the node at the position we wanted
*/
template <typename T>
void doubly_linked_list<T>::insert(T value, int position) {
    if (this->tail==nullptr && this->header==nullptr) {
        doubly_linked_node<T>* temp = new doubly_linked_node<T>(value);
        this->header = temp;
        this->tail = temp;
    }
    else if (position == 0) {
        head_push(value);
    }
    else {
        doubly_linked_node<T>* current = header;
        int i = 0;
        while (i < position - 1) {
            current = current->getNext();
            i++;
            if (current == nullptr) {
                push(value);
                return;
            }
        }
        doubly_linked_node<T>* temp = new doubly_linked_node<T>(value, current, current->getNext());
        current->setNext(temp);
    }
}

template <typename T>
void doubly_linked_list<T>::print_list() {
    doubly_linked_node<T>* current = this->header; 
    while (current != nullptr) {
        std::cout << current->getValue() << std::endl;
        current = current->getNext();
    }
}

template <typename T>
doubly_linked_node<T>* doubly_linked_list<T>::get_header_node() {
    return header;
}

template <typename T>
T doubly_linked_list<T>::get_header_value() {
    return header->getValue();
}

template <typename T>
int doubly_linked_list<T>::get_length() {
    return length;
}

template <typename T>
bool doubly_linked_list<T>::is_empty() {
    if (length==0) {
        return true;
    }
    else {
        return false;
    }
}
