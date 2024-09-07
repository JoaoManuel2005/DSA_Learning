#ifndef STACK_H
#define STACK_H

#include <vector>

template<typename T>
class Stack {
    public:
        Stack();
        ~Stack();
        void initialize();
        void push(T x);
        T pop();
        T seek();
    private:
        std::vector<T> stack;
};

#include "stack.tpp"

#endif // STACK_H