#include "stack.h"
#include <stdexcept>

void Stack::initialize() {
    stack.clear();
}

void Stack::push(int x) {
    stack.push_back(x);
}

int Stack::pop() {
    if (stack.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    int last = stack.back();
    stack.pop_back();
    return last;
}

int Stack::seek() {
    if (stack.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return stack.back();
}