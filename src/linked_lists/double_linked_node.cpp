#include "linked_lists/double_linked_node.h"
#include <stdexcept>

doubly_linked_node::doubly_linked_node(int value, doubly_linked_node* prev_pointer, doubly_linked_node* next_pointer)
    : node(value, next_pointer), prev_pointer(prev_pointer) {};
    // this->value = value;
    // this->prev_pointer = prev_pointer;
    // this->next_pointer = next_pointer;

doubly_linked_node* doubly_linked_node::getPrev() const {
    return prev_pointer;
}

doubly_linked_node* doubly_linked_node::getNext() const {
    return static_cast<doubly_linked_node*>(next_pointer);
}

void doubly_linked_node::setPrev(doubly_linked_node* prev) {
    prev_pointer = prev;
}

void doubly_linked_node::setNext(doubly_linked_node* next) {
    next_pointer = next;
}

void doubly_linked_node::setNext(node* next) {
    next_pointer = static_cast<doubly_linked_node*>(next);
}

