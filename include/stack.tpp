#include "stack.hpp"
#include <stdexcept>

/**
 * Constructor for stack
*/
template<typename T>
Stack<T>::Stack() {}

/**
 * Destructor for stack 
 * First invalidates refernces, pointers and iterators to contained elements
 * Then destructs vector forming stack
*/
template<typename T>
Stack<T>::~Stack() {
    stack.clear();
    stack.~vector();
}

/**
 * Pushes new object to the end of the stack
 * @param x - object to be pushed to stack 
*/
template<typename T>
void Stack<T>::push(T x) {
    stack.push_back(x);
}

/**
 * Pops latest object to have been added to stack 
*/
template<typename T>
T Stack<T>::pop() {
    if (stack.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    int last = stack.back();
    stack.pop_back();
    return last;
}

/**
 * Similar to pop but we only look at the last value and don't actually pop it from the stack
*/
template<typename T>
T Stack<T>::seek() {
    if (stack.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return stack.back();
}