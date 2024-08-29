#include "linked_lists/single_linked_list.hpp"
#include "linked_lists/single_linked_node.hpp"
#include <iostream>

template <typename T>
singly_linked_list<T>::singly_linked_list() : header(nullptr), tail(nullptr), length(0) {
    std::cout << "SingleLinkedList initialized" << std::endl;
}

template <typename T>
void singly_linked_list<T>::initialize() {
    std::vector<node<T>> list;
    this->tail = nullptr;
    this->header = nullptr;
}

template <typename T>
void singly_linked_list<T>::push(T value) {
    if (this->tail==nullptr && this->header==nullptr) {
        node<T>* temp = new node<T>(value);
        this->header = temp;
        this->tail = temp;
    }
    else {
        node<T>* temp = new node<T>(value);
        this->tail->setNext(temp);
        this->tail = this->tail->getNext();
    }
    length++;
}

template <typename T>
void singly_linked_list<T>::head_push(T value) {
    node<T>* temp = new node<T>(value, this->header);
    this->header = temp;
    length++;
}

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
        }
        else {
            current = current->getNext();
        }
    }
    length--;
}

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

template <typename T>
T singly_linked_list<T>::get_header() {
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