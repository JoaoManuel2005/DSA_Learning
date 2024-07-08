#include "linked_lists/single_linked_node.h"
#include <stdexcept>

node::node(int value, node* next_pointer) {
    this->value = value;
    this->next_pointer = next_pointer;
}
 
int node::getValue() const {
    return value;
}

node* node::getNext() const {
    return next_pointer;
}

void node::setNext(node* next) {
    next_pointer = next;
}
