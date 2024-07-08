#include "linked_lists/single_linked_list.h"
#include "linked_lists/single_linked_node.h"
#include <iostream>

singly_linked_list::singly_linked_list() : header(nullptr), tail(nullptr) {}

void singly_linked_list::initialize() {
    std::vector<node> list;
    this->tail = nullptr;
    this->header = nullptr;
}

void singly_linked_list::push(int value) {
    if (this->tail==nullptr && this->header==nullptr) {
        node* temp = new node(value);
        this->header = temp;
        this->tail = temp;
    }
    else {
        node* temp = new node(value);
        this->tail->setNext(temp);
        this->tail = this->tail->getNext();
    }
}

void singly_linked_list::head_push(int value) {
    node* temp = new node(value, this->header);
    this->header = temp;
}

void singly_linked_list::remove(int value) {
    node* current = this->header;
    if (header->getValue() == value) {
        header = header->getNext();
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
}

void singly_linked_list::insert(int value, int position) {
    if (this->tail==nullptr && this->header==nullptr) {
        node* temp = new node(value);
        this->header = temp;
        this->tail = temp;
    }
    else if (position == 0) {
        head_push(value);
    }
    else {
        node* current = this->header;
        int i = 0;
        while (i < position - 1) {
            current = current->getNext();
            i++;
            if (current == nullptr) {
                push(value);
                return;
            }
        }
        node* temp = new node(value, current->getNext());
        current->setNext(temp);
    }
}

void singly_linked_list::print_list() {
    node* current = this->header; 
    while (current != nullptr) {
        std::cout << current->getValue() << std::endl;
        current = current->getNext();
    }
}

int singly_linked_list::get_header() {
    return header->getValue();
}