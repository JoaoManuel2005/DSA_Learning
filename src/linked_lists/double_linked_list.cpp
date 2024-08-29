#include "linked_lists/double_linked_list.hpp"
#include "linked_lists/double_linked_node.hpp"
#include <iostream>

doubly_linked_list::doubly_linked_list() : singly_linked_list(), tail(nullptr) {}

void doubly_linked_list::push(int value) {
    if (this->tail==nullptr && this->header==nullptr) {
        doubly_linked_node* temp = new doubly_linked_node(value);
        this->header = temp;
        this->tail = temp;
    }
    else {
        doubly_linked_node* temp = new doubly_linked_node(value);
        this->tail->setNext(temp);
        temp->setPrev(tail);
        this->tail = this->tail->getNext();
    }
}

void doubly_linked_list::head_push(int value) {
    doubly_linked_node* temp = new doubly_linked_node(value, this->header);
    static_cast<doubly_linked_node*>(header)->setPrev(temp);
    this->header = temp;
}

void doubly_linked_list::remove(int value) {
    if (header == nullptr) return;

    doubly_linked_node* current = this->header;
    if (header->getValue() == value) {
        header = header->getNext();
        header->setPrev(nullptr);
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

void doubly_linked_list::insert(int value, int position) {
    if (this->tail==nullptr && this->header==nullptr) {
        doubly_linked_node* temp = new doubly_linked_node(value);
        this->header = temp;
        this->tail = temp;
    }
    else if (position == 0) {
        head_push(value);
    }
    else {
        doubly_linked_node* current = static_cast<doubly_linked_node*>(header);
        int i = 0;
        while (i < position - 1) {
            current = static_cast<doubly_linked_node*>(current->getNext());
            i++;
            if (current == nullptr) {
                push(value);
                return;
            }
        }
        doubly_linked_node* temp = new doubly_linked_node(value, current, current->getNext());
        current->setNext(temp);
    }
}

void doubly_linked_list::print_list() {
    node* current = this->header; 
    while (current != nullptr) {
        std::cout << current->getValue() << std::endl;
        current = current->getNext();
    }
}
