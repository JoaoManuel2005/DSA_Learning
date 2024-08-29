#ifndef STACK_H
#define STACK_H

#include <vector>

class Stack {
    public:
        void initialize();
        void push(int x);
        int pop();
        int seek();
    private:
        std::vector<int> stack;
};

#endif // STACK_H