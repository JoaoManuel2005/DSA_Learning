#include "single_linked_list.h"
#include "single_linked_node.h"

void singly_linked_list::initialize() {
    std::vector<node> list;
    this->tail = nullptr;
    this->header = nullptr;
}

void singly_linked_list::push(int value) {
    node temp = node(value);
    this->tail.setNext(&temp);
    this->tail = this->tail.getNext();
}

void singly_linked_list::head_push(int value) {
    node temp = node(value, this->header);
    this->header = &temp;
}

void singly_linked_list::remove() {
    current = this->header;
    if (header.getValue() == value) {
        header = header.getNext();
    }
    found = false;
    while (!found && current != nullptr) {
        if (current.getNext().getValue() == value) {
            current.setNext(current.getNext().getNext());
            found = true;
        }
        else {
            current = current.getNext();
        }
    }
}

void singly_linked_list::insert(int value, int position) {
    if (this->tail==nullptr && this->header==nullptr) {
        node temp = node(value);
        this->header = &temp;
        this->tail = &temp;
    }
    else {
        current = this->header;
        int i = 0
        while (i < position - 1) {
            current = current.getNext();
            i++;
        }
        node temp = node(value, current.getNext());
        current.setNext(&temp);
    }
}
