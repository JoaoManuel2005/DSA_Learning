#include "linked_lists/single_linked_list.hpp"
#include "linked_lists/single_linked_node.hpp"
#include <iostream>

/**
 * Constructor for single linked list
 * Initialises header and tail both to be null pointers
 * Initalises list length to be 0
**/
template <typename T>
singly_linked_list<T>::singly_linked_list() : header(nullptr), tail(nullptr), length(0) {
    std::cout << "SingleLinkedList initialized" << std::endl;
}

/**
 * Function to push new node to linked list
 * Makes the new node the new tail of the list
 * @param value - values stored in new node
*/
template <typename T>
void singly_linked_list<T>::push(T value) {
    node<T>* temp = new node<T>(value);
    if (this->tail==nullptr && this->header==nullptr) {
        this->header = temp;
        this->tail = temp;
    }
    else {
        this->tail->setNext(temp);
        this->tail = this->tail->getNext();
    }
    length++;
}

/**
 * Pushes new node to list but at head
 * @param value - value that is stored in the node we want to add to list
 * Creates new node whos next pointer is the current list header
 * Makes lists new header this new node
*/
template <typename T>
void singly_linked_list<T>::head_push(T value) {
    node<T>* temp = new node<T>(value, this->header);
    this->header = temp;
    length++;
}

/**
 * Removes node from linked list 
 * @param value - value that is stored in the node we want to remove from list
 * Iterates through list to find desired node to remove
 * When we find it, we set the previous nodes next pointer to the next of the desired node,
 * effectively removing it as a link
*/
template <typename T>
void singly_linked_list<T>::remove(T value) {
    if (header == nullptr) {
        return;
    }
    node<T>* current = this->header;
    if (header->getValue() == value) {
        header = header->getNext();
        if (header == nullptr) {
            tail = nullptr;
        }
        length--;
        return;
    }
    bool found = false;
    while (!found && current != nullptr) {
        if (current->getNext() != nullptr && current->getNext()->getValue() == value) {
            current->setNext(current->getNext()->getNext());
            found = true;
            length--;
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
 * We set the previous nodes next as the new node
 * We set the new nodes, next_pointer to point to the previous nodes next
 * 
*/
template <typename T>
void singly_linked_list<T>::insert(T value, int position) {
    if (this->tail==nullptr && this->header==nullptr) {
        node<T>* temp = new node<T>(value);
        this->header = temp;
        this->tail = temp;
    }
    else if (position == 0) {
        head_push(value);
    }
    else {
        node<T>* current = this->header;
        int i = 0;
        while (i < position - 1) {
            current = current->getNext();
            i++;
            if (current == nullptr) {
                push(value);
                return;
            }
        }
        node<T>* temp = new node<T>(value, current->getNext());
        current->setNext(temp);
    }
    length++;
    std::cout << "Appended item: " << value << ", new length: " << length << std::endl;
}

template <typename T>
void singly_linked_list<T>::print_list() {
    node<T>* current = this->header; 
    while (current != nullptr) {
        std::cout << current->getValue() << std::endl;
        current = current->getNext();
    }
}

/**
 * Getter for header node
*/
template <typename T>
node<T>* singly_linked_list<T>::get_header_node() {
    return header;
}

/**
 * Getter for header value, not header node
*/
template <typename T>
T singly_linked_list<T>::get_header_value() {
    return header->getValue();
}

template <typename T>
int singly_linked_list<T>::get_length() const {
    // int length = 0;
    // node<T>* current = this->header; 
    // while (current != nullptr) {
    //     length += 1;
    //     current = current->getNext();
    // }
    return length;
}

template <typename T>
bool singly_linked_list<T>::is_empty() const {
    // if (header == nullptr) {
    //     return true;
    // }
    // return false;
    if (length==0) {
        return true;
    }
    else {
        return false;
    }
}