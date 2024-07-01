#include "single_linked_node.h"
#include <stdexcept>

node::node(int value, node* next_pointer) {
    this->value = value;
    this->next_pointer = next_pointer;
}
 

int node::getValue() {
    return this->value;
}

node* node::getNext() {
    return this->next_pointer;
}

void node::setNext(node* next_pointer) {
    this->next_pointer = next_pointer;
}
